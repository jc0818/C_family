#include <stdio.h>
#include <Windows.h>
#include <time.h>



void a();//상점 
void b();//강화 
void c();//가챠  
void d();//종료 

int s, s_1, s_2, s_3;

int attack = 1;
int gold = 10000;
int hando = 0;
int hwai = 0;
int ga = 0;
int na = 0;
int da = 0;

int main()
{
    printf("어디로 이동하시겠습니까 ? \n\n");
    printf("1번 - 상점\n");
    printf("2번 - 강화소\n");
    printf("3번 - 카드 픽업\n");
    printf("4번 - 게임 종료\n ");
    printf("선택 : ");
    scanf("%d", &s);

    switch (s)
    {
    case 1:
        system("cls");
        a();
    case 2:
        system("cls");
        b();
    case 3:
        system("cls");
        c();
    case 4:
        system("cls");
        exit(0);
    default:
        printf("\n\n main 잘못된 선택입니다.");
        Sleep(1000);
        system("cls");
        main();
    }
    
}


void a()
{
    printf("1번 물약 ( 200 G ) 2번 무기 ( 500 G ) 3번 방어구 ( 400 G ) 4번 나가기\n\n");
    printf("현재 소지중인 골드 : %d G\n\n", gold);
    printf("선택 : ");
    scanf("%d", &s_1);

    switch (s_1)
    {
    case 1:
        if (gold >= 200)
        {
            printf("\n\n물약을 구매하셨습니다.\n");
            gold = gold - 200;
            printf("\n남은 골드 : %d", gold);
            Sleep(1000);
            system("cls");
            a();
        }
        else
        {
            printf("\n\n소지하신 골드가 부족합니다.");
            Sleep(1000);
            system("cls");
            a();
        }
    case 2:
        if (gold >= 500)
        {
            printf("\n\n무기를 구매하셨습니다.\n");
            gold = gold - 500;
            printf("\n남은 골드 : %d", gold);
            Sleep(1000);
            system("cls");
            a();
        }
        else
        {
            printf("\n\n소지하신 골드가 부족합니다.");
            Sleep(1000);
            system("cls");
            a();
        }
    case 3:
        if (gold >= 400)
        {
            printf("\n\n방어구를 구매하셨습니다.\n");
            gold = gold - 400;
            printf("\n남은 골드 : %d", gold);
            Sleep(1000);
            system("cls");
            a();
        }
        else
        {
            printf("\n\n소지하신 골드가 부족합니다.");
            Sleep(1000);
            system("cls");
            a();
        }
    case 4:
        printf("\n\n메인화면으로 돌아갑니다");
        Sleep(1000);
        system("cls");
        main();

    default:
        printf("\n\n잘못된 선택입니다.");
        Sleep(1000);
        system("cls");
        a();
    }
}


void b()
{
    int n;
    srand((int)time(NULL));

    printf("1번 공격력 강화 ( 200 G ) 2번 나가기\n\n");
    printf("현재 소지중인 골드 : %d G\n\n", gold);
    printf("현재 공격력 : %d \n\n", attack);
    printf("선택 : ");
    scanf("%d", &s_2);
    switch (s_2)
    {
    case 1:
        if (gold >= 200)
        {
            printf("\n\n공격력 강화를 진행합니다.\n\n");
            gold = gold - 200;
            printf("남은 골드 : %d\n\n", gold);
            n = rand() % 100;
            if (n < 50)
            {
                printf("\n강화에 성공하셨습니다 ! 공격력이 3 증가합니다.\n\n");
                attack = attack + 3;
                Sleep(1700);
                system("cls");
                b();
            }
            else
            {
                printf("\n강화에 실패하셨습니다..\n\n");
                Sleep(1700);
                system("cls");
                b();
            }
            Sleep(1000);
            system("cls");
            b();
        }
        else
        {
            printf("\n\n소지하신 골드가 부족합니다.\n\n");
            Sleep(1000);
            system("cls");
            b();
        }
    case 2:
        printf("\n\n메인화면으로 돌아갑니다\n\n");
        Sleep(1000);
        system("cls");
        main();
    default:
        printf("\n\n잘못된 선택입니다.\n\n");
        Sleep(1000);
        system("cls");
        b();

    }
}

void c()
{
    int n;
    
    srand((int)time(NULL));
    
    printf("(하루 최대 5번 )무료 카드 픽업 1연차 : ①번 \n 무료 카드 픽업 10연차 : ②번\n 메인으로 돌아가기 : ③번 \n\n  1연차 횟수 :   『%d』\n 카드픽업 횟수 : 『%d』 \n \n 일반 『%d』 레전드 『%d』 울트라 『%d』\n \n  ",hando,hwai,ga,na,da);
    
    printf("선택 : ");
    scanf("%d", &s_3);
   
    switch (s_3)
    {
        
    case 1:
        
        printf("\n\n무료카드 1연차 픽업을 진행합니다.\n\n");

        n = rand() % 100;
        if (hando >= 5)
        {
            printf("하루 최대 가챠를 하였습니다.");
            Sleep(2000);
            system("cls");
            main();
        }
        if (n < 80)
        {
            printf("\n\n   일반카드\"종말의화살\"  \n\n");
            hando = hando+1;
            hwai = hwai + 1;
            ga = ga + 1;
            Sleep(1500);
            system("cls");
            c();
           
        }
        else if ( n < 98)
        {
            printf("\n\n   레전드카드\"악마가 깃든 볼펜 \"  \n\n");
            hando = hando + 1;
            hwai = hwai + 1;
            na = na + 1;
            Sleep(1500);
            system("cls");
            c();
            
        }
        else if ( n <=100)
        {
            printf("\n\n   울트라레전드슈퍼원투쓰리포카드\"천사의 윙크  \"  \n\n");
            hando = hando + 1;
            hwai = hwai + 1;
            da = da + 1;
            Sleep(1500);
            system("cls");
            c();
           
        }
        if (hando >= 5)
        {
            hando = 5;
        }

    case 2:
        for (int i = 1; i <= 10; i++)
        {
            

            
            hwai = hwai + 1;

                printf("\n\n카드픽업 %d번.\n\n",i);

                n = rand() % 100;
                if (n < 80)//80프로
                {
                    printf("\n\n   일반카드\"종말의화살\"  \n\n");
                    ga = ga + 1;
                    Sleep(1000);
                    system("cls");
                    

                }
                else if ( n < 98)//18프로
                {
                    printf("\n\n   레전드카드\"악마가 깃든 볼펜 \"  \n\n");
                    na = na + 1;
                    Sleep(1000);
                    system("cls");
                    

                }
                else if ( n <= 100 )//2프로 
                {
                    printf("\n\n   울트라레전드슈퍼원투쓰리포카드\" 천사의 윙크  \"  \n\n");
                    da = da + 1;
                    Sleep(1000);
                    system("cls");
                    

                }
        }
        c();
        
    case 3:
        printf("\n 나가는 중.....");
        Sleep(1500);
        system("cls");
        main();
        break;
    default:
        printf("\n\n  잘못된 선택입니다.\n\n");
        Sleep(1000);
        system("cls");
        main();
    }
}

