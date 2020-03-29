#pragma once

#include "PlayerStatBox.h"

struct Game_t {
	
private:
	enum EStatus { Presentation, Resolution };
	enum EResult { Winner_p1, Winner_p2, Tie};

	EResult result;
	EStatus status = EStatus::Presentation;

	PlayerStatsBox_t* p1;
	PlayerStatsBox_t* p2;

public:
	Game_t(PlayerStatsBox_t* player1, PlayerStatsBox_t* player2);
	~Game_t();
	void draw();
	void drawWinner();
	void Play();
	EResult Winner();

};