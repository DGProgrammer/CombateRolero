// Jue26.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include "PlayerStatBox.h"
#include "Game.h"
#include "rlutil.h"
#include <time.h> 

using namespace rlutil;

int main(int argc, char** argv)
{
	srand(time(NULL));

	PlayerStatsBox_t stats(1, 60, 10, 8, 8);
	PlayerStatsBox_t stats2(1, 60, 10, 8, 8);


	//PlayerStatsBox_t* p = new PlayerStatsBox_t(1, "Trazos", 60, 10, 8, 8);
	Game_t game(&stats, &stats2);
	int pulso = 1;
	do {
		if (pulso == 1)
		{
		game.Play();
		}
		pulso = getkey();
	} while (pulso != 0);
}