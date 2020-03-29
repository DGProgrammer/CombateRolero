#include <cstdio>
#include <cstring>
#include "PlayerStatBox.h"
#include "rlutil.h"
#include <time.h> 
#include <math.h>

#define V printf("\xBA")
#define H printf("\xCD")
#define RT printf("\xBB")
#define RB printf("\xBC")
#define LT printf("\xC9")
#define LB printf("\xC8")

using namespace rlutil;

int value(int max, int min)
{
	return rand() % (max-min) + min;
}

const char* statNames[6] = {
	"FUE", "DES", "CON", "INT", "SAB", "CAR"
};

void PlayerStatsBox_t::drawStat(EStats statIndex, int value, int order)
{
	locate(m_x + 1, m_y + 2 + order);

	setColor(YELLOW);
	printf("%s: ", statNames[statIndex]);
	setColor(WHITE);
	printf("%d", value);

	totalPoints = totalPoints + value;

	resetColor();
}

void PlayerStatsBox_t::drawBox()
{
	int x = m_x, y = m_y;
	setColor(m_color);
	locate(x, y);
	LT;
	for (int i = 0; i < m_w; i++) H;
	RT;

	for (int i = 0; i < m_h; i++)
	{
		locate(x, ++y);
		V;
		for (int j = 0; j < m_w; j++)
			printf(" ");
		V;
	}

	locate(x, y);
	LB;
	for (int i = 0; i < m_w; i++) H;
	RB;
	/*LT;  H; H; RT;
	locate(x, y+1);
	LB;  H; H; RB;*/
}

PlayerStatsBox_t::PlayerStatsBox_t(int color,
	int x, int y, int w, int h)
	: m_x(x), m_y(y), m_w(w), m_h(h), m_color{ color }
{
}

void PlayerStatsBox_t::draw()
{
	drawBox();
	locate(m_x + 1, m_y + 1);
	strcpy(&m_name[0], m_names[value(4,0)]);
	printf("%s", &m_name);

	for (int i = 0; i < 6; i++)
	{
		drawStat((EStats)i, value(18,3), i);
	}
	printf("\n");
}

void PlayerStatsBox_t::draw(int x, int y)
{
	m_x = x;
	m_y = y;
	totalPoints = 0;
	draw();
}
