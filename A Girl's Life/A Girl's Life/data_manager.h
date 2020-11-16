#pragma once
#include <vector>
#include <map>
#include "player.h"
#include "school_quiz_science.h"
#include "school_quiz_korean.h"
using namespace std;

class PlayerInfo
{
public:
	char name[128];
	int days;
	char id[128];

	PlayerInfo(char* name, int days, char* id)
	{
		strcpy_s<128>(this->name, name);
		strcpy_s<128>(this->id, id);
		this->days = days;
	}

};


class DataManager
{
public:
	void LoadPlayersData();
	void UpdatePlayersData();
	PlayerInfo* AddPlayer(char* name);
	Player LoadPlayerData(PlayerInfo* playerInfo);
	void CreateNewPlayerData(PlayerInfo* playerInfo);
	void LoadKoreanQuizData(KoreanQuizs* quizs);
	void LoadScienceQuizData(ScienceQuizs* quizs);

	
	vector<PlayerInfo*> playerInfos;
	int dataCount = 0;
};