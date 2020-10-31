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

void DataManager::LoadQuizData(Quizs* quizs)
{
	FILE* fp = nullptr;

	char fileName[128] = "data/school_quiz/";
	char fileType[] = ".dat";
	strcat(fileName, quizs->subject);
	strcat(fileName, fileType);



	fopen_s(&fp, fileName, "rt");

	if (fp != nullptr)
	{

		/*char line[256];

		fscanf_s(fp, "%s", line, 128);
		char* question = strtok(line, "/");
		char* choice1 = strtok(NULL, "/");
		char* choice2 = strtok(NULL, "/");
		char* answer = strtok(NULL, "/");

		quiz->setQuizInfo(question, answer, choice1, choice2);*/

		char lines[100][255];
		int i = 0;
		while (!feof(fp))
		{
			fgets(lines[i], sizeof(lines[i]), fp);
			i++;
		}

		quizs->quiz = new Quiz[i];

		for (int j = 0; j < i; j++)
		{

			string str(lines[j]);
			istringstream ss(str);
			string stringBuffer;
			

			char question[128];
			getline(ss, stringBuffer, '/');
			strcpy(question, stringBuffer.c_str());

			char choice1[128];
			getline(ss, stringBuffer, '/');
			strcpy(choice1, stringBuffer.c_str());

			char choice2[128];
			getline(ss, stringBuffer, '/');
			strcpy(choice2, stringBuffer.c_str());

			char answer[128];
			getline(ss, stringBuffer, '/');
			strcpy(answer, stringBuffer.c_str());
			
			
			quizs->quiz[i].setQuizInfo(question, answer, choice1, choice2);

			/*char* question = strtok(lines[j], "/");
			char* choice1 = strtok(NULL, "/");
			char* choice2 = strtok(NULL, "/");
			char* answer = strtok(NULL, "/");
			quizs->quiz[i].setQuizInfo(question, answer, choice1, choice2);*/
		}
			

		fclose(fp);
	}


}