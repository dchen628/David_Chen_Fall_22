/*
	Include Pixel.h
	Inherit a class from GameApp. Override method OnUpdate in it.
	Feed the name of your class to LINK_START macro.
*/

#include "Pixel.h"

class PixelGame : public Ekko::GameApp
{
public:
	PixelGame()
	{
		/*Ekko::PixelWindow::GetWindow()->SetKeyPressedCallback(
			[this](const Ekko::KeyPressedEvent& event) {OnKeyPress(event); });
		Ekko::PixelWindow::GetWindow()->SetKeyReleasedCallback(
			[this](const Ekko::KeyReleasedEvent& event) {OnKeyRelease(event); });*/
	}

	void ForceUpdate() override
	{
		Ekko::Renderer::Draw(pic, 200, 200, 1);
		Ekko::Renderer::Draw(pic2, 100, 100, 1);
	}

private:
	//Ekko::Picture mBackground{ "Assets/Textures/testing.png" };
	Ekko::Picture pic{ "Assets/Textures/smile.png" };
	Ekko::Picture pic2{ "Assets/Textures/test.png" };

	/*enum class CharState {
		MOVE_LEFT,
		MOVE_RIGHT,
		MOVE_UP,
		MOVE_DOWN,
		STILL
	} m_State{ CharState::STILL };

	void OnKeyPress(const Ekko::KeyPressedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case PIXEL_KEY_LEFT:
			m_State = CharState::MOVE_LEFT;
			break;
		case PIXEL_KEY_RIGHT:
			m_State = CharState::MOVE_RIGHT;
			break;
		case PIXEL_KEY_UP:
			m_State = CharState::MOVE_UP;
			break;
		case PIXEL_KEY_DOWN:
			m_State = CharState::MOVE_DOWN;
			break;
		}
	}

	void OnKeyRelease(const Ekko::KeyReleasedEvent& event)
	{
		switch (event.GetKeyCode())
		{
		case PIXEL_KEY_LEFT:
			if (m_State == CharState::MOVE_LEFT)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_RIGHT:
			if(m_State == CharState::MOVE_RIGHT)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_UP:
			if(m_State == CharState::MOVE_UP)
				m_State = CharState::STILL;
			break;
		case PIXEL_KEY_DOWN:
			if(m_State == CharState::MOVE_DOWN)
				m_State = CharState::STILL;
			break;
		}
	}*/
};

LINK_START(PixelGame)