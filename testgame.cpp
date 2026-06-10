#include <iostream>
#include <windows.h>
#include <conio.h>  // _kbhit(), _getch()
#include <wchar.h>
#include <locale.h>
#include <random>
#include <time.h>
#include "functions.h"


using namespace std;

int main()

{

    srand(time(NULL));
    /*
    cout << "아무 키나 누르면 즉시 반응합니다. (q: 종료)\n";

    while (true) {
        // 키가 눌렸는지 확인
        if (_kbhit()) {
            int ch = _getch(); // 입력된 키를 즉시 읽음 (Enter 불필요)            
            cout << "입력된 키: " << ch << "\n";

            // 특정 키(q) 입력 시 종료
            if (ch == 'q' || ch == 'Q') {
                cout << "프로그램 종료\n";
                break;
            }
        }
        // 다른 작업 가능 (비동기 입력 처리)
    }

    
    
    // 로케일 설정 (유니코드 출력 가능하게)
    
    printf("\n\n\n\n\n");
    
    
    setlocale(LC_ALL, "");



    const int CardMapSize = 9;
    wchar_t CardMap[CardMapSize][CardMapSize] = { 
    {L'┌',L'─',L'─',L'─',L'─',L'─',L'─',L'─',L'┐'},
    {L'│',L' ',L'■',L'■',L'■',L'■',L'■',L' ',L'│'},
    {L'│',L' ',L'■',L'■',L'■',L'■',L'■',L' ',L'│'}, 
    {L'│',L' ',L'■',L'■',L'■',L'■',L'■',L' ',L'│'}, 
    {L'└',L'─',L'─',L'─',L'─',L'─',L'─',L'─',L'┘'} };


    for (int e = 0; e < CardMapSize; e++)
    {
        for (int f = 0; f < CardMapSize; f++)
        {
            wprintf(L"%lc", CardMap[e][f]);
        }

        printf("\n");
    }

    
    */
    
    // MainMenu();

    std::string word = "";

    Menu_1_GenerateWords(word);


}