#include <iostream>
#include <thread>
#include <conio.h>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <random>
#include <atomic>
#include <chrono>
#include <mutex>
#include <windows.h>
#include "functions.h"

std::atomic<bool> GameRunning(true);
std::mutex Gamemutex;


void MainMenu()
{      
    Environment();
    TitleName("타자연습 게임 v0.1");
    
    int ChooseMenu = 0;

    printf("\n");
    printf("[메뉴 선택]");
    printf("\n\n\n");
    printf("1. 자원캐기\n\n2. 산성비\n\n3. 도움말\n\n4. 점수\n\n5. 종료\n\n\n\n");
    printf("입력 : ");

    ChooseMenu = _getch();

    if (ChooseMenu == '1')
    {
        printf("1번을 선택했습니다.");
        Menu_1();
    }
    else if (ChooseMenu == '2')
    {
        printf("2번을 선택했습니다.");
        Menu_2();
    }
    else if (ChooseMenu == '3')
    {
        printf("3번을 선택했습니다.");
        Menu_3();
    }
    else if (ChooseMenu == '4')
    {
        printf("4번을 선택했습니다.");
        Menu_4();
    }
    else if (ChooseMenu == '5')
    {
        printf("5번을 선택했습니다.");
        return;
    }
    else
    {
        printf("잘못된 입력입니다. 다시 입력해주세요.");
        _getch();
        MainMenu();
    }


}



void Menu_1()
{
    
    Environment();
    
    PlayerInfo1 MyPlayerInfo{};
    InGame1TitleName("자원캐기",MyPlayerInfo.CurrentStage,MyPlayerInfo.CurrentScore);
        

    printf("\n\n\n\n\n\n\n\n                                       아무 키나 누르면 시작합니다.");
    _getch();
    ;            
    
    Menu_1_MainLayout();    
    
}

void Menu_1_MainLayout()
{
    system("cls");

    PlayerInfo1 MyPlayerInfo{};
    InGame1TitleName("자원캐기", MyPlayerInfo.CurrentStage, MyPlayerInfo.CurrentScore);         
  
    std::thread T1(Menu_1_InputLayout);
    T1.join();


}


void Menu_1_InputLayout()
{    
    

    int flag = 0; // 단어 제거 횟수 카운트. 홀수 개로 설정하면 무승부는 절대 발생하지 않음

    PlayerInfo1 MyPlayerInfo;
    Words1 InGame1Word;

    srand(time(NULL));


    

    // 외부 파일 읽기

    std::vector<std::string> words;

    std::ifstream file("words.txt");
    std::string line;

    if (file.is_open())
    {
        std::getline(file, line);

        std::stringstream ss(line);
        std::string word;

        while (std::getline(ss, word, ','))
        {
            words.push_back(word);
        }
    }

    std::thread ComputerThread(ComputerInput, &InGame1Word, &MyPlayerInfo, &flag);

    StageStart:  

    // 단어배열 초기화

    for (int e = 0; e < 9; e++)
    {
        for (int f = 0; f < 3; f++)
        {
            std::string& InArray = words[rand() % words.size()];
            InGame1Word.Game1WordTable[e][f] = InArray;
        }

    }


    
    while (flag < 27)
    {   
        system("cls");
        InGame1TitleName("자원캐기", MyPlayerInfo.CurrentStage, MyPlayerInfo.CurrentScore);

        for (int e = 0; e < 9; e++)
        {
            for (int f = 0; f < 3; f++)
            {
                printf("%-15s ", InGame1Word.Game1WordTable[e][f].c_str());
            }
            printf("\n");
        }

        printf("\n\n\n\n\n\n\n\n내가 입력한 단어의 개수 : %d\n컴퓨터가 입력한 단어의 개수 : %d\n", MyPlayerInfo.PlayerCount, MyPlayerInfo.ComputerCount);

        const int Border = 105; // 구분선 길이
        for (int i = 0; i < Border; i++)
        {
            printf("─");
        }
        printf("\n\n입력 : ");
        std::string InputString;
        std::getline(std::cin, InputString);
        system("cls");

        std::lock_guard<std::mutex> lock(Gamemutex);

        for (int e = 0; e < 9; e++)
        {
            for (int f = 0; f < 3; f++)
            {

               if (InGame1Word.Game1WordTable[e][f] == InputString)
               {
                   InGame1Word.Game1WordTable[e][f] = "";
                   MyPlayerInfo.CurrentScore += 10;
                   MyPlayerInfo.PlayerCount++;
                   flag++;
                   
               }
            }

        }
        

    }

    if (ComputerThread.joinable())
{
    ComputerThread.join();
}

        // 단어 모두 제거된 후

        if (MyPlayerInfo.PlayerCount > MyPlayerInfo.ComputerCount) // 플레이어가 컴퓨터보다 더 많이 제거했으면
        {
            printf("\n승리! 다음 단계로 진행합니다.");            
            MyPlayerInfo.CurrentStage++;
            _getch();

            // 현재 스테이지 정보는 초기화                  
                       
            MyPlayerInfo.PlayerCount = 0;
            MyPlayerInfo.ComputerCount = 0;
            flag = 0;
            goto StageStart;

        }
        else if (MyPlayerInfo.PlayerCount < MyPlayerInfo.ComputerCount) // 컴퓨터가 더 많이 제거했으면
        {
            printf("\n 패배했습니다.");
            
        }

        
        
        InGame1TitleName("자원캐기", MyPlayerInfo.CurrentStage, MyPlayerInfo.CurrentScore);          
        
    




}

void ComputerInput(Words1* InGame1Word, PlayerInfo1* MyPlayerInfo, int* flag)
{
    while (*flag < 27)
    {
        std::this_thread::sleep_for(std::chrono::seconds(2));

        std::lock_guard<std::mutex> lock(Gamemutex);

        std::vector<std::pair<int, int>> AvailableWords;

        for (int e = 0; e < 9; e++)
        {
            for (int f = 0; f < 3; f++)
            {
                if (!InGame1Word->Game1WordTable[e][f].empty())
                {
                    AvailableWords.push_back({ e, f });
                }
            }
        }

        if (!AvailableWords.empty())
        {
            int index = rand() % AvailableWords.size();

            int row = AvailableWords[index].first;
            int col = AvailableWords[index].second;

            InGame1Word->Game1WordTable[row][col] = "";

            MyPlayerInfo->ComputerCount++;
            (*flag)++;
           
        }
    }
}


void Menu_2()
{
    Environment();
    TitleName("산성비");
    
    bool Result = false;
    std::string PlayerName = "";
    int Stages = 0;
    int FinalScore = 0;
    
    
    std::thread T1(Menu_2_WordLayout);
    T1.join();
    
    
}
void Menu_2_WordLayout()
{

}
void Menu_2_InputLayout()
{
  
}


void Menu_3()
{
    Environment();
    TitleName("도움말");

    printf("\n\n");

    printf("[산성비]\n");
    printf("\n\n위에서 떨어지는 단어들을 밑에 닿기 전에 입력해야 합니다.");
    printf("\n\n밑으로 닿기 전까지 제거하지 못하면 라이프가 감소합니다. 라이프는 스테이지 클리어 시 마다 일정량 회복됩니다.");


    printf("\n\n\n\n");

    printf("[자원 캐기]\n");
    printf("\n\n시작시 일정한 수의 단어가 주어집니다.");
    printf("\n\n컴퓨터와 경쟁해 더 많은 단어를 입력한 쪽이 승리합니다.");
    printf("\n\n단어를 입력하면 사라지며 다른 쪽에서 다시 입력할 수 없습니다.");

    printf("\n\n\n\n\n");
    printf("\n아무 키나 눌러 메인 메뉴로 돌아갑니다.");
    _getch();
    MainMenu();

}


void Menu_4()
{    
    Environment();
    TitleName("점수 보기");

    printf("          이름　　　　　스테이지　　　　　점수　 　  모드");

    const int HighScoreMaxCount = 10;
    const int AlignInfo = 4;
    
    
    std::string Name[HighScoreMaxCount][AlignInfo] = {
    {"AAA","10","9999","산성비"},
    {"BBB","9","8888","자원캐기"},
    {"CCC","8","7777","산성비"},
    {"DDD","7","6666","자원캐기"},
    {"EEE","6","5555","산성비"},
    {"FFF","5","4444","자원캐기"},
    {"GGG","4","3333","산성비"},
    {"HHH","3","2222","자원캐기"},
    {"III","2","1111","산성비"},
    {"JJJ","1","1","자원캐기"},
    }; // default fixed data

    
    printf("\n\n\n");

    for (int e = 0; e < HighScoreMaxCount; e++)
    {
        for (int f = 0; f < AlignInfo; f++)
        {
            printf("%15s", Name[e][f].c_str());
        }
        printf("\n");
    }
 
    
    printf("\n\n\n\n\n");
    printf("\n아무 키나 눌러 메인 메뉴로 돌아갑니다.");
    _getch();
    MainMenu();
    // 1. 게임 종료후 임시 저장공간 1에 이름과 점수가 있다

    // 2. 임시 저장공간 2가 있는데 여기엔 아무것도 없다

    // 3. 가장 위의(점수가 높은) 줄부터 임시 저장공간에 들어있는 점수와 비교한다

    // 4. 내 점수가 더 높으면 임시 저장공간 2에 해당 순위의 점수와 이름값을 저장한다

    // 5. 임시 저장공간 1에 있는 점수와 이름값을 해당 순위에 넣는다

    // 6. 임시 저장공간 2에 있는 값을 임시 저장공간 1로 넣는다

    // 7. 작업했던 순위의 밑순위로 내려가 3~6을 반복한다(제일 밑부분까지)


    

}
void Menu_4_ReceiveScore()
{
}


void GenerateWords()
{
    /* Method 1

    const std::string WordsContainer = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890";

    std::string CombineWord = "";   
    
    int Wordslength = 0;
    
    

    while (true)
    {
        CombineWord = "";
        Wordslength = (rand() % 10) + 2; // 2~ 11까지
        for (int i = 0; i < Wordslength; i++)
        {
            CombineWord += static_cast<char>(WordsContainer[rand() % WordsContainer.size()]);
        }

        printf("%s\n", CombineWord.c_str());
        Sleep(20);
    }
    */

    // Method 2


}

void Environment()
{
    system("cls");
    system("color 70");
}

void TitleName(std::string InString) // 위에 내용을 표시한다.
{

    // ------------------------- 제목
    const int Border =105; // 구분선 길이
    for (int i = 0; i < Border; i++)
    {
        printf("─");
    }

    printf("\n%s\n", InString.c_str());

    for (int i = 0; i < Border; i++)
    {
        printf("─");
    }

    printf("\n\n");
}
void InGame1TitleName(std::string InString,int InStage, int InScore) // 산성비용 제목
{           
    const int Border = 105; // 구분선 길이
    for (int i = 0; i < Border; i++)
    {
        printf("─");
    }

    printf("\n%s　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　스테이지 : %d　　　　점수 : %d　\n", InString.c_str(), InStage,InScore);

    for (int i = 0; i < Border; i++)
    {
        printf("─");
    }

    printf("\n\n");
}
void InGame2TitleName(std::string InString,int InStage, int InHealth, int InScore) // 자원캐기용 제목
{    
    const int Border = 105; // 구분선 길이
    for (int i = 0; i < Border; i++)
    {
        printf("─");
    }

    printf("\n%s　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　스테이지 : %d　　　　　점수 : %d\n", InString.c_str(),InStage,InScore);

    for (int i = 0; i < Border; i++)
    {
        printf("─");
    }

    printf("\n\n");
}

std::string StringResizer(std::string InString)
{
    
    std::string ResizeText = InString;

    while (ResizeText.size() / 3 != 5)
    {
        if (ResizeText.size() / 3 < 5)
        {
            ResizeText += "　";
        }
        else if (ResizeText.size() / 3 > 5)
        {
            ResizeText = ResizeText.substr(0, 15);
        }
    }
    
    return ResizeText;
}
