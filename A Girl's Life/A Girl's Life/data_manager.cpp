#define _CRT_SECURE_NO_WARNINGS
#include "data_manager.h"
#include "global.h"
#include<sstream>
#include<string>

void DataManager::LoadPlayersData()
{
	playerInfos.clear();
	FILE* fp = nullptr;

	fopen_s(&fp, "data/Player_Info.dat", "rt");

	if (fp != nullptr)
	{
		fscanf_s(fp, "%d", &dataCount);
		for (int i = 0; i < dataCount; ++i)
		{
			PlayerInfo* playerInfo;
			char name[128]; int days = 0; char id[128];
			fscanf_s(fp, "%s %d %s", name, 128, &days, id, 128);
			playerInfo = new PlayerInfo(name, days, id);
			playerInfos.push_back(playerInfo);
		}

		fclose(fp);
	}

}

void DataManager::UpdatePlayersData()
{
	dataCount = playerInfos.size();

	FILE* fp = nullptr;
	fopen_s(&fp, "data/Player_Info.dat", "wt");
	if (fp != nullptr)
	{
		fprintf(fp, "%d\n", playerInfos.size());
		for (int i = 0; i < playerInfos.size(); ++i)
		{
			fprintf(fp, "%s\t%d\t%s\n", playerInfos[i]->name, playerInfos[i]->days, playerInfos[i]->id);
		}

		fclose(fp);
	}
}

PlayerInfo* DataManager::AddPlayer(char* name)
{
	char cID[128] = "0001";
	if (playerInfos.size() > 0) 
	{
		int iID = atoi(playerInfos[playerInfos.size() - 1]->id) + 1;
		sprintf(cID, "%04d", iID);
	}
	
	PlayerInfo* playerInfo = new PlayerInfo(name, 1, cID);
	playerInfos.push_back(playerInfo); 
	

	UpdatePlayersData();
	CreateNewPlayerData(playerInfo);

	return playerInfo;
}

Player DataManager::LoadPlayerData(PlayerInfo* playerInfo)
{
	Player player;

	FILE* fp = nullptr;

	char fileName[128] = "data/";
	char fileType[] = ".dat";
	strcat(fileName, playerInfo->id);
	strcat(fileName, "_");
	strcat(fileName, playerInfo->name);
	strcat(fileName, fileType);
	


	fopen_s(&fp, fileName, "rt");

	if (fp != nullptr)
	{
		
		PlayerInfo* playerInfo;
		//char name[128]; char id[128];

		fscanf_s(fp, "%s", player.name, 128);
		fscanf_s(fp, "%s", player.ID, 128);
		fscanf_s(fp, "%d", &player.days);
		fscanf_s(fp, "%d", &player.stress);
		fscanf_s(fp, "%d", &player.energy);
		fscanf_s(fp, "%d", &player.money);
		fscanf_s(fp, "%d", &player.koreanScore);
		fscanf_s(fp, "%d", &player.mathScore);
		fscanf_s(fp, "%d", &player.englishScore);
		fscanf_s(fp, "%d", &player.scienceScore);
		fscanf_s(fp, "%d", &player.societyScore);
		fscanf_s(fp, "%d", &player.PTScore);
		fscanf_s(fp, "%d", &player.technologyScore);
		fscanf_s(fp, "%d", &player.historyScore);

			
			
		//strcpy_s<128>(player.name, name);
		//strcpy_s<128>(player.ID, id);
		

		fclose(fp);
	}
	

	return player;
}

void DataManager::CreateNewPlayerData(PlayerInfo* playerInfo)
{
	FILE* fp = nullptr;

	char fileName[128] = "data/";
	char fileType[] = ".dat";
	strcat(fileName, playerInfo->id);
	strcat(fileName, "_");
	strcat(fileName, playerInfo->name);
	strcat(fileName, fileType);

	fopen_s(&fp, fileName, "wt");
	if (fp != nullptr)
	{
		fprintf(fp, "%s\n", playerInfo->name);
		fprintf(fp, "%s\n", playerInfo->id);
		fprintf(fp, "%d\n", playerInfo->days);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		fprintf(fp, "%d\n", 0);
		

		fclose(fp);
	}
}

void DataManager::LoadKoreanQuizData(KoreanQuizs* quizs)
{
	FILE* fp = nullptr;

	char fileName[128] = "data/school_quiz/korean.dat";


	fopen_s(&fp, fileName, "rt");

	if (fp != nullptr)
	{


		char lines[100][255];
		int len = 0;
		while (!feof(fp))
		{
			fgets(lines[len], sizeof(lines[len]), fp);
			len++;
		}

		//kQuizs->quiz = new KoreanQuiz[len];


		for (int i = 0; i < len; i++)
		{

			KoreanQuiz* quiz = new KoreanQuiz();
			char ch[4][128] = { {'\0'} };
			for (int j = 0, k = 0, l = 0; k < 4; j++)
			{
				if (lines[i][j] == '/')
				{
					k++;
					l = 0;
					continue;
				}

				if (lines[i][j] == NULL || lines[i][j] == '\0' || lines[i][j] == '\n')
				{
					break;
				}
				ch[k][l] = lines[i][j];
				l++;
			}
			
			
			quiz->setQuizInfo(ch[0], ch[3], ch[1], ch[2]);
			quizs->quizs.push_back(quiz);
			
		}
			

		fclose(fp);
	}
	

}



void DataManager::LoadScienceQuizData(ScienceQuizs* quizs) 
{
	FILE* fp = nullptr;

	char fileName[128] = "data/school_quiz/science.dat";


	fopen_s(&fp, fileName, "rt");

	if (fp != nullptr)
	{

		char lines[20][255];
		int len = 0;
		while (!feof(fp))
		{
			fgets(lines[len], sizeof(lines[len]), fp);
			len++;
		}

		//scQuiz[0] = new ScienceQuiz[len - 1];

		for (int i = 1; i < len; i++)
		{
			ScienceQuiz* quiz = new ScienceQuiz();
			for (int j = 0; ; j ++)
			{
				quiz->qustion.push_back(lines[i][j]);
				//scQuizs->quiz[i-1].qustion.push_back(lines[i][j]);
				if (lines[i][j + 1] == '\n' || lines[i][j + 1] == NULL || lines[i][j + 1] == '\0') {
					quizs->quizs.push_back(quiz);
					break;
				}

			}
		}

		fclose(fp);
	}
}

