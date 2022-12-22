#include "Score.h"

Ekko::Score::Score()
{
}

void Ekko::Score::addScore()
{
	score++;
}

int Ekko::Score::getScore()
{
	return score;
}

void Ekko::Score::resetScore()
{
	score = 0;
}

void Ekko::Score::drawScore()
{
	increment = 0;
	std::string scoreStr = std::to_string(score);
	for (int i = 0; i <= scoreStr.length(); i++)
	{
		switch (scoreStr[i])
		{
		case '0':
			Ekko::Renderer::Draw(zero, xCoord + increment, 0, 0);
			break;
		case '1':
			Ekko::Renderer::Draw(one, xCoord + increment, 0, 0);
			break;
		case '2':
			Ekko::Renderer::Draw(two, xCoord + increment, 0, 0);
			break;
		case '3':
			Ekko::Renderer::Draw(three, xCoord + increment, 0, 0);
			break;
		case '4':
			Ekko::Renderer::Draw(four, xCoord + increment, 0, 0);
			break;
		case '5':
			Ekko::Renderer::Draw(five, xCoord + increment, 0, 0);
			break;
		case '6':
			Ekko::Renderer::Draw(six, xCoord + increment, 0, 0);
			break;
		case '7':
			Ekko::Renderer::Draw(seven, xCoord + increment, 0, 0);
			break;
		case '8':
			Ekko::Renderer::Draw(eight, xCoord + increment, 0, 0);
			break;
		case '9':
			Ekko::Renderer::Draw(nine, xCoord + increment, 0, 0);
			break;
		}
		increment += 40;
	}
}
