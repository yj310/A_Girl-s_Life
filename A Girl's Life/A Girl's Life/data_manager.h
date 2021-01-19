#pragma once
#include <vector>
#include <map>
#include "player.h"
#include "school_quiz_science.h"
#include "school_quiz_korean.h"
#include "school_quiz_pt.h"
using namespace std;

class PlayerInfo
{
public:
	char name[128];
	int days;
	int character;
	char id[128];

	PlayerInfo(char* name, int days, int character, char* id)
	{
		strcpy_s<128>(this->name, name);
		strcpy_s<128>(this->id, id);
		this->days = days;
		this->character = character;
	}

};


class DataManager
{
public:
	void LoadPlayersData();
	void UpdatePlayersData();
	PlayerInfo* AddPlayer(char* name, int character);
	Player LoadPlayerData(PlayerInfo* playerInfo);
	void SavePlayerData();
	void CreateNewPlayerData(PlayerInfo* playerInfo);
	void LoadKoreanQuizData(KoreanQuizs* quizs);
	void LoadHistoryQuizData(KoreanQuizs* quizs);
	void LoadScienceQuizData(ScienceQuizs* quizs);
	void LoadEnglishQuizData(KoreanQuizs* quizs);
	void LoadPTQuizData(PTQuizs* quizs);

	
	vector<PlayerInfo*> playerInfos;
	int dataCount = 0;
};