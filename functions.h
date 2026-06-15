#pragma once
#include <iostream>
#include <atomic>

void MainMenu();

void Menu_1();
void Menu_1_MainLayout();
void Menu_1_InputLayout();
void Menu_2();
void Menu_2_WordLayout();
void Menu_2_InputLayout();
void Menu_3();
void Menu_4();
void Menu_4_ReceiveScore();


void Environment();
void TitleName(std::string InString);
void InGame1TitleName(std::string InString, int InStage, int InScore);
void InGame2TitleName(std::string InString, int InStage, int InHealth, int InScore);
std::string StringResizer(std::string InString);
void GenerateWords();

struct Words1
{		
	std::string Game1WordTable[9][3] = {};
};

struct Words2
{
	std::string Name2;
};

struct PlayerInfo1 // 자원캐기용 정보 구조체
{
	int CurrentStage = 1;	
	int CurrentScore = 0;
	int PlayerCount = 0;
	int ComputerCount = 0;
};

struct PlayerInfo2 // 산성비용 정보 구조체
{
	int CurrentStage = 1;
	int CurrentHealth = 10;
	int CurrentScore = 0;
};

void ComputerInput(Words1* InGame1Word, PlayerInfo1* MyPlayerInfo, std::atomic<int>* flag);