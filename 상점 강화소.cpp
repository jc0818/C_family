#include <stdio.h>
#include <Windows.h>
#include <time.h>



void a();//���� 
void b();//��ȭ 
void c();//��í  
void d();//���� 

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
    printf("���� �̵��Ͻðڽ��ϱ� ? \n\n");
    printf("1�� - ����\n");
    printf("2�� - ��ȭ��\n");
    printf("3�� - ī�� �Ⱦ�\n");
    printf("4�� - ���� ����\n ");
    printf("���� : ");
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
        printf("\n\n main �߸��� �����Դϴ�.");
        Sleep(1000);
        system("cls");
        main();
    }
    
}


void a()
{
    printf("1�� ���� ( 200 G ) 2�� ���� ( 500 G ) 3�� �� ( 400 G ) 4�� ������\n\n");
    printf("���� �������� ��� : %d G\n\n", gold);
    printf("���� : ");
    scanf("%d", &s_1);

    switch (s_1)
    {
    case 1:
        if (gold >= 200)
        {
            printf("\n\n������ �����ϼ̽��ϴ�.\n");
            gold = gold - 200;
            printf("\n���� ��� : %d", gold);
            Sleep(1000);
            system("cls");
            a();
        }
        else
        {
            printf("\n\n�����Ͻ� ��尡 �����մϴ�.");
            Sleep(1000);
            system("cls");
            a();
        }
    case 2:
        if (gold >= 500)
        {
            printf("\n\n���⸦ �����ϼ̽��ϴ�.\n");
            gold = gold - 500;
            printf("\n���� ��� : %d", gold);
            Sleep(1000);
            system("cls");
            a();
        }
        else
        {
            printf("\n\n�����Ͻ� ��尡 �����մϴ�.");
            Sleep(1000);
            system("cls");
            a();
        }
    case 3:
        if (gold >= 400)
        {
            printf("\n\n���� �����ϼ̽��ϴ�.\n");
            gold = gold - 400;
            printf("\n���� ��� : %d", gold);
            Sleep(1000);
            system("cls");
            a();
        }
        else
        {
            printf("\n\n�����Ͻ� ��尡 �����մϴ�.");
            Sleep(1000);
            system("cls");
            a();
        }
    case 4:
        printf("\n\n����ȭ������ ���ư��ϴ�");
        Sleep(1000);
        system("cls");
        main();

    default:
        printf("\n\n�߸��� �����Դϴ�.");
        Sleep(1000);
        system("cls");
        a();
    }
}


void b()
{
    int n;
    srand((int)time(NULL));

    printf("1�� ���ݷ� ��ȭ ( 200 G ) 2�� ������\n\n");
    printf("���� �������� ��� : %d G\n\n", gold);
    printf("���� ���ݷ� : %d \n\n", attack);
    printf("���� : ");
    scanf("%d", &s_2);
    switch (s_2)
    {
    case 1:
        if (gold >= 200)
        {
            printf("\n\n���ݷ� ��ȭ�� �����մϴ�.\n\n");
            gold = gold - 200;
            printf("���� ��� : %d\n\n", gold);
            n = rand() % 100;
            if (n < 50)
            {
                printf("\n��ȭ�� �����ϼ̽��ϴ� ! ���ݷ��� 3 �����մϴ�.\n\n");
                attack = attack + 3;
                Sleep(1700);
                system("cls");
                b();
            }
            else
            {
                printf("\n��ȭ�� �����ϼ̽��ϴ�..\n\n");
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
            printf("\n\n�����Ͻ� ��尡 �����մϴ�.\n\n");
            Sleep(1000);
            system("cls");
            b();
        }
    case 2:
        printf("\n\n����ȭ������ ���ư��ϴ�\n\n");
        Sleep(1000);
        system("cls");
        main();
    default:
        printf("\n\n�߸��� �����Դϴ�.\n\n");
        Sleep(1000);
        system("cls");
        b();

    }
}

void c()
{
    int n;
    
    srand((int)time(NULL));
    
    printf("(�Ϸ� �ִ� 5�� )���� ī�� �Ⱦ� 1���� : ��� \n ���� ī�� �Ⱦ� 10���� : ���\n �������� ���ư��� : ��� \n\n  1���� Ƚ�� :   ��%d��\n ī���Ⱦ� Ƚ�� : ��%d�� \n \n �Ϲ� ��%d�� ������ ��%d�� ��Ʈ�� ��%d��\n \n  ",hando,hwai,ga,na,da);
    
    printf("���� : ");
    scanf("%d", &s_3);
   
    switch (s_3)
    {
        
    case 1:
        
        printf("\n\n����ī�� 1���� �Ⱦ��� �����մϴ�.\n\n");

        n = rand() % 100;
        if (hando >= 5)
        {
            printf("�Ϸ� �ִ� ��í�� �Ͽ����ϴ�.");
            Sleep(2000);
            system("cls");
            main();
        }
        if (n < 80)
        {
            printf("\n\n   �Ϲ�ī��\"������ȭ��\"  \n\n");
            hando = hando+1;
            hwai = hwai + 1;
            ga = ga + 1;
            Sleep(1500);
            system("cls");
            c();
           
        }
        else if ( n < 98)
        {
            printf("\n\n   ������ī��\"�Ǹ��� ��� ���� \"  \n\n");
            hando = hando + 1;
            hwai = hwai + 1;
            na = na + 1;
            Sleep(1500);
            system("cls");
            c();
            
        }
        else if ( n <=100)
        {
            printf("\n\n   ��Ʈ�����彴�ۿ���������ī��\"õ���� ��ũ  \"  \n\n");
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

                printf("\n\nī���Ⱦ� %d��.\n\n",i);

                n = rand() % 100;
                if (n < 80)//80����
                {
                    printf("\n\n   �Ϲ�ī��\"������ȭ��\"  \n\n");
                    ga = ga + 1;
                    Sleep(1000);
                    system("cls");
                    

                }
                else if ( n < 98)//18����
                {
                    printf("\n\n   ������ī��\"�Ǹ��� ��� ���� \"  \n\n");
                    na = na + 1;
                    Sleep(1000);
                    system("cls");
                    

                }
                else if ( n <= 100 )//2���� 
                {
                    printf("\n\n   ��Ʈ�����彴�ۿ���������ī��\" õ���� ��ũ  \"  \n\n");
                    da = da + 1;
                    Sleep(1000);
                    system("cls");
                    

                }
        }
        c();
        
    case 3:
        printf("\n ������ ��.....");
        Sleep(1500);
        system("cls");
        main();
        break;
    default:
        printf("\n\n  �߸��� �����Դϴ�.\n\n");
        Sleep(1000);
        system("cls");
        main();
    }
}

