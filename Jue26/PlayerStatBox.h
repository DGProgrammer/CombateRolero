#pragma once

struct PlayerStatsBox_t {
	enum EStats{ FUE, DES, CON, INT, SAB, CAR};
	
	

	PlayerStatsBox_t(int color, int x,
		int y, int w, int h);
	void draw();
	void draw(int x, int y);
	int totalPoints = 0;
	int m_x, m_y, m_w, m_h, m_color;

private:
	void drawStat(EStats statIndex, int value, int order);
	void drawBox();
	char m_name[50];
	char m_names[4][50] = { "THOR", "HULK", "IRON MAN", "SUPERMAN" };
};