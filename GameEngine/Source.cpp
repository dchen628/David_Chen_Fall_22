/*
	Include Pixel.h
	Inherit a class from GameApp. Override method OnUpdate in it.
	Feed the name of your class to LINK_START macro.
*/

#include "Pixel.h"
#include "Score.h"

class PixelGame : public Ekko::GameApp
{
public:
	PixelGame()
	{
		Ekko::PixelWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Ekko::KeyPressedEvent& event) {OnKeyPress(event); });
		Ekko::PixelWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Ekko::KeyReleasedEvent& event) {OnKeyRelease(event); });
	}

	void ForceUpdate() override
	{
		Ekko::Renderer::Draw(background, -200, 0, 0);
		Ekko::Renderer::Draw(player);
		Ekko::Renderer::Draw(bad);
		Ekko::Renderer::Draw(bullet);
		Ekko::Renderer::Draw(enemyBullet);
		score.drawScore();

		if (m_State == CharState::MOVE_LEFT)
			player.ChangeX(-10);
		if (m_State == CharState::MOVE_RIGHT)
			player.ChangeX(10);
		if (m_State == CharState::MOVE_UP)
			player.ChangeY(10);
		if (m_State == CharState::MOVE_DOWN)
			player.ChangeY(-10);

		if (m_State == CharState::FIRE && shot == false)
		{
			hit = false;
			bullet.SetCoord(player.GetX() + 43, player.GetY() + 100, 0);
			shot = true;
		}
		if (bullet.GetY() < 800 && shot == true)
		{
			bullet.ChangeY(15);
		}
		else if (bullet.GetY() >= 800)
		{
			shot = false;
		}



		if (enemyShotTimer == false)
		{
			alive = std::chrono::steady_clock::now();
			enemyShotTimer = true;
		}
		enemyFire = std::chrono::steady_clock::now();
		if (enemyFire - alive >= std::chrono::seconds(2) && timer == false && enemyShot == false)
		{
			enemyBullet.SetCoord(bad.GetX() + 48, bad.GetY(), 1);
			enemyShot = true;
		}
		if (enemyBullet.GetY() > -20 && enemyShot == true)
		{
			enemyBullet.ChangeY(-enemyBulletSpd);
		}
		else if (enemyBullet.GetY() <= -20 && enemyShot == true)
		{
			enemyShot = false;
			enemyShotTimer = false;
		}



		if (bad.GetX() >= 900)
		{
			side = true;
		}
		if (bad.GetX() <= 0)
			side = false;
		if (bad.GetX() < 900 && side == false)
		{
			bad.ChangeX(enemySpd);
		}
		if (side == true)
		{
			bad.ChangeX(-enemySpd);
		}
		if (counter == 5 && enemySpd < 20)
		{
			enemySpd++;
			counter = 0;
			enemyBulletSpd++;
		}



		if (enemyBullet.OverlapsWith(player) == true && enemyHit == false)
		{
			playerOld = std::chrono::steady_clock::now();
			enemyHit = true;
			score.resetScore();
			enemySpd = 5;
			enemyBulletSpd = 10;
			lastPlayerHitXCoord = player.GetX();
			lastPlayerHitYCoord = player.GetY();
		}
		if (enemyHit == true)
		{
			player.SetCoord(-200, -200, 0);
			playerExplosion.SetCoord(lastPlayerHitXCoord, lastPlayerHitYCoord, 0);
			Ekko::Renderer::Draw(playerExplosion);
		}
		auto playerDuration = std::chrono::steady_clock::now();
		if (playerDuration - playerOld >= std::chrono::seconds(3) && enemyHit == true)
		{
			playerExplosion.SetCoord(-200, -200, 0);
			enemyHit = false;
			player.SetCoord(450, 0, 0);
		}



		if (bullet.OverlapsWith(bad) == true && hit == false)
		{
			old = std::chrono::steady_clock::now();
			timer = true;
			hit = true;
			counter++;
			score.addScore();
			lastHitXCoord = bad.GetX();
		}
		if (timer == true)
		{
			bad.SetCoord(-200, -200, 0);
			explosion.SetCoord(lastHitXCoord, 720, 0);
			Ekko::Renderer::Draw(explosion);
		}
		auto duration = std::chrono::steady_clock::now();
		if (duration - old >= std::chrono::seconds(3) && timer == true)
		{
			explosion.SetCoord(-200, -200, 0);
			timer = false;
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dist(0, 900);
			int randomX = dist(gen);
			bad.SetCoord(randomX, 700, 1);
		}
	}

private:
	Ekko::Picture background{ "Assets/Textures/back.png" };
	Ekko::Unit player{ "Assets/Textures/plane.png", 450, 0, 0 };
	Ekko::Unit bullet{ "Assets/Textures/ball.png", -100, -100, 0 };
	Ekko::Unit enemyBullet{ "Assets/Textures/enemyball.png", -100, -100, 0 };
	bool shot = false;
	bool enemyShot = false;
	bool enemyShotTimer = false;
	bool enemyHit = false;

	Ekko::Unit bad{ "Assets/Textures/BadGuy1.png", 500, 700, 1 };
	bool side = false;
	int enemySpd = 5;
	int counter = 0;
	int enemyBulletSpd = 10;

	bool hit = false;
	Ekko::Score score{};

	Ekko::Unit explosion{ "Assets/Textures/boom.png", -200, -200, 0 };
	Ekko::Unit playerExplosion{ "Assets/Textures/boom.png", -200, -200, 0 };
	std::chrono::steady_clock::time_point old;
	std::chrono::steady_clock::time_point playerOld;
	std::chrono::steady_clock::time_point alive;
	std::chrono::steady_clock::time_point enemyFire;
	bool timer = false;
	int lastHitXCoord{ 0 };
	int lastPlayerHitXCoord{ 0 };
	int lastPlayerHitYCoord{ 0 };



	enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		STILL,
		FIRE
	} m_State{ CharState::STILL };

	void OnKeyPress(const Ekko::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case PIXEL_KEY_LEFT:
		case PIXEL_KEY_A:
			m_State = CharState::MOVE_LEFT;
			break;
		case PIXEL_KEY_RIGHT:
		case PIXEL_KEY_D:
			m_State = CharState::MOVE_RIGHT;
			break;
		case PIXEL_KEY_UP:
		case PIXEL_KEY_W:
			m_State = CharState::MOVE_UP;
			break;
		case PIXEL_KEY_DOWN:
		case PIXEL_KEY_S:
			m_State = CharState::MOVE_DOWN;
			break;
		case PIXEL_KEY_SPACE:
			m_State = CharState::FIRE;
			break;
		}
	}

	void OnKeyRelease(const Ekko::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case PIXEL_KEY_LEFT:
		case PIXEL_KEY_A:
			if (m_State == CharState::MOVE_LEFT)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_RIGHT:
		case PIXEL_KEY_D:
			if(m_State == CharState::MOVE_RIGHT)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_UP:
		case PIXEL_KEY_W:
			if(m_State == CharState::MOVE_UP)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_DOWN:
		case PIXEL_KEY_S:
			if(m_State == CharState::MOVE_DOWN)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_SPACE:
			if (m_State == CharState::FIRE)
				m_State = CharState::STILL;
			break;
		}
	}
};

LINK_START(PixelGame)