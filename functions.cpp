#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include "functions.h"

void MainMenu()
{
   system("cls");

   printf("┌────────────────────────────────────────────────────────────┐\n");
   printf("│                        테스트 제목                         │\n");
   printf("│                                                            │\n");
   printf("│                                                            │\n");
   printf("│                                                            │\n");
   printf("│                                                            │\n");
   printf("│  1. 게임 시작                                              │\n");
   printf("│                                                            │\n");
   printf("│  2. 플레이 방법                                            │\n");
   printf("│                                                            │\n");
   printf("│  3. 최고점수 보기                                          │\n");
   printf("│                                                            │\n");
   printf("│  4. 나가기                                                 │\n");
   printf("│                                                            │\n");
   printf("│                                                            │\n");
   printf("│                                                            │\n");
   printf("└────────────────────────────────────────────────────────────┘\n");

   printf("\n");    
    
   int MainInputKey = _getch();      

   while (MainInputKey < 1 || MainInputKey > 4)
   {
       if (MainInputKey == '1')
       {
           printf("\n 1번 출력 테스트");
       }
       else if (MainInputKey == '2')
       {
           printf("\n 2번 출력 테스트");
       }
       else if (MainInputKey == '3')
       {
           Menu_3();
       }
       else if (MainInputKey == '4')
       {
           Menu_4();
       }

       MainInputKey = _getch();

   }
}

void Menu_1()
{
}

void Menu_2()
{
}

void Menu_3()
{    
    system("cls");

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
    bool HighScoreDummyInput = false;

    printf("==================== High Scores ====================");
    printf("\n\n\n");

    for (int i = HighScoreMaxCount-1; i > 0; i--)
    {
        printf("\n%s   %d", Name[i].c_str(), HighScoreStages[i]);
    }
    
    
    printf("\n아무 키나 눌러 메인 메뉴로 돌아갑니다.");
    HighScoreDummyInput = _getch();
    MainMenu();





}

void Menu_4()
{
    exit;
}