#include <iostream>
#include <thread>
#include <conio.h>
#include <iomanip>
#include <string>
#include <random>
#include <windows.h>
#include "functions.h"


void MainMenu()
{      
    Environment();
    TitleName("타자연습 게임 v0.1");
    
    int ChooseMenu = 0;

    printf("[메뉴 선택]");
    printf("\n\n\n");
    printf("1. 산성비\n\n2. 자원캐기\n\n3. 도움말\n\n4. 점수\n\n5. 종료\n\n\n\n");
    printf("입력 : ");

    ChooseMenu = _getch();

    if (ChooseMenu == '1')
    {
        Menu_1();
    }
    else if (ChooseMenu == '2')
    {
        Menu_2();
    }
    else if (ChooseMenu == '3')
    {
        printf("\n3번을 선택했습니다.");
        Menu_3();
    }
    else if (ChooseMenu == '4')
    {
        Menu_4();
    }
    else if (ChooseMenu == '5')
    {
        return;
    }
    else
    {
        printf("잘못된 입력입니다. 다시 입력해주세요.");
        _getch();
        MainMenu();
    }


}


void Menu_1() // 메뉴 1 하위구조 호출용
{
    Environment();
    TitleName("산성비");
    Menu_1_MainLayout();  

}

void Menu_1_MainLayout()
{

    std::thread T1(Menu_1_WordLayout); // 별도의 영역으로 관리
    T1.join();

    for (int i = 0; i < 205; i++)
    {
        printf("─");
    }
    std::thread T2(Menu_1_Inputword); // 별도의 영역으로 관리
    T2.join();
}

void Menu_1_WordLayout()
{
    const int Height = 42;
    const int Width = 60;
    int BoardBorder = Width - 44;

    std::string WordField[Height][Width] = { ".", };

    // 가로 0에서 17까지의 영역은 낙하구간
    // 가로 18에서 59까지의 영역은 정보구간
    for (int e = 0; e < Height; e++)
    {
        for (int f = 0; f < BoardBorder; f++)
        {
            WordField[e][f] = "　　　　　"; // 낙하부 빈글자
        }
        for (int f = BoardBorder; f < Width; f++) // 정보창부 빈글자
        {
            WordField[e][f] = " ";
        }
    }  
    
    // 정보창 경계선

    for (int i = BoardBorder+1; i < Width; i++)
    {
        WordField[0][i] = "─";
        WordField[Height - 1][i] = "─";
    }
    for (int i = 1; i < Height - 1; i++)
    {
        WordField[i][BoardBorder] = "│";
        WordField[i][Width-1] = "│";
    }
    WordField[0][BoardBorder] = "┌";
    WordField[0][Width-1] = "┐";
    WordField[Height-1][BoardBorder] = "└";
    WordField[Height-1][Width - 1] = "┘";

    // 출력부분

     

        for (int e = 0; e < Height; e++)
        {
            for (int f = 0; f < BoardBorder; f++)
            {
                printf("%6s", WordField[e][f].c_str());
            }
            for (int f = BoardBorder; f < Width; f++)
            {
                printf("%s", WordField[e][f].c_str());
            }

            printf("\n");
        }

    
    

    


}

void Menu_1_Inputword()
{
    
    while (true)
    {   
        printf("\n입력 : ");
        std::string InputString = "";

        std::cin >> std::noskipws;
        std::cin >> InputString;
        std::cin.clear();
        std::cin.ignore(10000);

       
    }
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



void Menu_2()
{
    Environment();
    TitleName("자원 캐기");
    
    bool Result = false;
    std::string PlayerName = "";
    int Stages = 0;
    int FinalScore = 0;
    
    
    std::thread T1(Menu_2_WordLayout);
    T1.join();
    
    
}

void Menu_2_WordLayout()
{
    const int Height = 5;
    const int Width = 5;
    std::string WordTable[Height][Width] = { "", };

    for (int e = 0; e < Height; e++)
    {
        for (int f = 0; f < Width; f++)
        {
            WordTable[e][f] = char(rand() % 20+50);
        }
    }

    for (int e = 0; e < Height; e++)
    {
        for (int f = 0; f < Width; f++)
        {
            printf("[%s]", WordTable[e][f].c_str());
        }
        printf("\n");
    }
}

void Menu_2_StatusLayout()
{
    std::string StatusScreen[10][50] = {"",};

    for (int e = 0; e < 10; e++)
    {
        for (int f = 0; f < 50; f++)
        {
            StatusScreen[e][f] = " ";
        }

    }
    for (int e = 0; e < 50; e++)
    {
        StatusScreen[0][e] = "─";
        StatusScreen[9][e] = "─";
    }
    for (int f = 0; f < 10; f++)
    {
        StatusScreen[f][0] = "│";
        StatusScreen[f][49] = "│";
    }

    StatusScreen[0][0] = "┌";
    StatusScreen[0][49] = "┐";
    StatusScreen[9][0] = "└";
    StatusScreen[9][49] = "┘";

    for (int e = 0; e < 10; e++)
    {
        for (int f = 0; f < 50; f++)
        {
            printf("%s", StatusScreen[e][f].c_str());
        }
        printf("\n");
    }
}



void Menu_3()
{
    Environment();
    TitleName("도움말");

    printf("\n\n\n");

    printf("[산성비]\n");
    printf("\n\n위에서 떨어지는 단어들을 밑에 닿기 전에 입력해야 합니다.");
    printf("\n\n밑으로 닿기 전까지 제거하지 못하면 라이프가 감소합니다. 라이프는 스테이지 클리어 시 마다 일정량 회복됩니다.");


    printf("\n\n\n\n\n\n");

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

    const int HighScoreMaxCount = 10;

    // 1. 게임 종료후 임시 저장공간 1에 이름과 점수가 있다

    // 2. 임시 저장공간 2가 있는데 여기엔 아무것도 없다

    // 3. 가장 위의(점수가 높은) 줄부터 임시 저장공간에 들어있는 점수와 비교한다

    // 4. 내 점수가 더 높으면 임시 저장공간 2에 해당 순위의 점수와 이름값을 저장한다

    // 5. 임시 저장공간 1에 있는 점수와 이름값을 해당 순위에 넣는다

    // 6. 임시 저장공간 2에 있는 값을 임시 저장공간 1로 넣는다

    // 7. 작업했던 순위의 밑순위로 내려가 3~6을 반복한다(제일 밑부분까지)
    
    
    int HighScoreStages[HighScoreMaxCount] = { 10,9,8,7,6,5,4,3,2,1 };
    std::string Name[HighScoreMaxCount] = { "AAA","BBB","CCC","DDD","EEE","FFF","GGG","HHH","III","JJJ" };    

    
    printf("\n\n\n");

    for (int i = HighScoreMaxCount-1; i > 0; i--)
    {
        printf("\n%s   %d", Name[i].c_str(), HighScoreStages[i]);
    }
    
    printf("\n\n\n\n\n");
    printf("\n아무 키나 눌러 메인 메뉴로 돌아갑니다.");
    _getch();
    MainMenu();



    

}

void Environment()
{
    system("cls");
    system("color 70");
}

void TitleName(std::string InString) // 위에 내용을 표시한다.
{

    // ------------------------- 제목
    const int Border = 205;
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
