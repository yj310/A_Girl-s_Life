#pragma once
#include "player.h"

class GameSystem
{
public:
	GameSystem();
	Player* player;

	void classMemory();

	void deleteData()
	{
		player = nullptr;
	}

	/* setter */
	//void setPlayer(Player player) { this->player = new Player() }


};