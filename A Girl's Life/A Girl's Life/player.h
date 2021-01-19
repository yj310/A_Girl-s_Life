#pragma once
#include "item.h"
#include <vector>
using namespace std;

class Player
{
public:
	Player();
	Player(const Player& player)
	{
		strcpy_s<128>(this->name, player.name);
		strcpy_s<128>(this->ID, player.ID);
		this->days = player.days;
		this->time = player.time;
		this->stress = player.stress;
		this->energy = player.energy;
		this->money = player.money;
		this->character = player.character;

		this->koreanScore = player.koreanScore;
		this->mathScore = player.mathScore;
		this->englishScore = player.englishScore;
		this->scienceScore = player.scienceScore;
		this->societyScore = player.societyScore;
		this->PTScore = player.PTScore;
		this->technologyScore = player.technologyScore;
		this->historyScore = player.historyScore;

	}
	void Update();
	void Render();

	char name[128];	// 이름
	char ID[128];	// character ID
	int days;	// 일차
	int time;	// 시간
	int stress;	// 스트레스
	int energy;	// 체력
	int money;	// 용돈
	int character;	// 캐릭터

	vector<Item*> myItem;	// 소유한 아이템

	// 성적
	int koreanScore;		// 국어
	int	mathScore;			// 수학
	int englishScore;		// 영어
	int scienceScore;		// 과학
	int societyScore;		// 사회
	int PTScore;			// 체육
	int technologyScore;	// 기술
	int historyScore;		// 역사


	// adder
	void nexyDay() { days++; }	// 다음날로 이동
	void addTime(int time) { this->time += time; }
	void addStress(int stress)	{ this->stress += stress; }
	void addEnergy(int energy)	{ this->energy += energy; }
	void addMoney(int money)	{ this->money += money; }

	void addKoreanScore(int score)		{ this->koreanScore += score; }
	void addMathScore(int score)		{ this->mathScore += score; }
	void addEnglishScore(int score)		{ this->englishScore += score; }
	void addScienceScore(int score)		{ this->scienceScore += score; }
	void addSocietyScore(int score)		{ this->societyScore += score; }
	void addPTScore(int score)			{ this->PTScore += score; }
	void addTechnologyScore(int score)	{ this->technologyScore += score; }
	void addHistoryScore(int score)		{ this->historyScore += score; }

	// setter
	void setData(const char* name, int days, const char* ID) { strcpy_s<128>(this->name, name); strcpy_s<128>(this->ID, ID); this->days = days; }
	void setName(const char* name) { strcpy_s<128>(this->name, name); }
	void setID(const char* ID) { strcpy_s<128>(this->ID, ID); }

	void setDays(int days)		{ this->days = days; }
	void setTime(int time) { this->time = time; }
	void setStress(int stress)	{ this->stress = stress; }
	void setEnergy(int energy)	{ this->energy = energy; }
	void setMoney(int money)	{ this->money = money; }
	void setCharacter(int character) { this->character = character; }

	void setKoreanScore(int score)		{ this->koreanScore = score; }
	void setMathScore(int score)		{ this->mathScore = score; }
	void setEnglishScore(int score)		{ this->englishScore = score; }
	void setScienceScore(int score)		{ this->scienceScore = score; }
	void setSocietyScore(int score)		{ this->societyScore = score; }
	void setPTScore(int score)			{ this->PTScore = score; }
	void setTechnologyScore(int score)	{ this->technologyScore = score; }
	void setHistoryScore(int score)		{ this->historyScore = score; }

	// getter
	int getDays()	{ return this->days; }
	int getTime() { return this->time; }
	char* getName() { return this->name; }
	char* getID() { return this->ID; }

	int getStress() { return this->stress; }
	int getEnergy() { return this->energy; }
	int getMoney()	{ return this->money; }
	int getCharacter() { return this->character; }

	int getKoreanScore()	{ return this->koreanScore; }
	int getMathScore()		{ return this->mathScore; }
	int getEnglishScore()	{ return this->englishScore; }
	int getScienceScore()	{ return this->scienceScore; }
	int getSocietyScore()	{ return this->societyScore; }
	int getPTScore()		{ return this->PTScore; }
	int getTechnologyScore() { return this->technologyScore; }
	int getHistoryScore()	{ return this->historyScore; }


};
