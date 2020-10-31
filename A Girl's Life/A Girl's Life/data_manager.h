#pragma once
#include <vector>
#include "player.h"
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

class Quiz
{
public:
	char question[128];
	char answer[128];
	char choice1[128];
	char choice2[128];

	void setQuizInfo(char* question, char* answer, char* choice1, char* choice2)
	{
		strcpy_s<128>(this->question, question);
		strcpy_s<128>(this->answer, answer);
 		strcpy_s<128>(this->choice1, choice1);
		strcpy_s<128>(this->choice2, choice2);
	}

	~Quiz()
	{
		delete[] question;
		delete[] answer;
		delete[] choice1;
		delete[] choice2;
	}
};

class Quizs
{
public:
	Quiz* quiz;
	char subject[128];

	Quizs(const char* subject)
	{
		strcpy_s<128>(this->subject, subject);
	}

	~Quizs()
	{
		delete quiz;
		delete[] subject;
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
	void LoadQuizData(Quizs* quizs);


	vector<PlayerInfo*> playerInfos;
	int dataCount = 0;
};