#include "Game.h"
#include "rlutil.h"

using namespace rlutil;

Game_t::Game_t(PlayerStatsBox_t * player1, PlayerStatsBox_t * player2)
	: p1(player1), p2(player2)
{
	saveDefaultColor();
}

Game_t::~Game_t()
{
	resetColor();
}
void Game_t::Play()
{
	switch (status)
	{
	case EStatus::Presentation:
		cls();
		draw();
		status = EStatus::Resolution;
		break;
	case EStatus::Resolution:
		drawWinner();
		status = EStatus::Presentation;
		break;
	default:
		break;
	}
}
Game_t::EResult Game_t::Winner()
{
	int result = p1->totalPoints - p2->totalPoints;
	if (result > 0)
	{
		return EResult::Winner_p1;
	}
	else if (result < 0)
	{
		return EResult::Winner_p2;
	}
	else
	{
		return EResult::Tie;
	}
}

void Game_t::draw()
{
	p1->draw(1, 5);
	p2->draw(20, 5);
}

void Game_t::drawWinner()
{
	setColor(RED);
	int init = p1->m_x + p1->m_w + 2;
	int final = p2->m_x;
	int y = p1->m_y + (p1->m_h / 2);
	locate(init, y);

	for (size_t i = 0; i < (final - init); i++)
	{
		printf("\x3D");
	}

	switch (result = Winner())
	{
	case EResult::Winner_p1:
		locate(final - 1, y);
		printf("\x3E");
		break;
	case EResult::Winner_p2:
		locate(init, y);
		printf("\x3C");
		break;
	case EResult::Tie:
		break;
	default:
		break;
	}
}
