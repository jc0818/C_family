#include <stdio.h>
void prnStr(int a[10])
{
    printf("-----------------------------\n");
    printf("1  2  3  4  5  6  7  8  9  10\n");
    printf("-----------------------------\n");
     for(int i = 0; i < 10; ++i){
                printf("%d  ", a[i]);
    }
}
int main()
{
    int a[10] = {0,};
    int check;
    char YaN;
    
    while(1)
    {
    YaN='\0';
    printf("좌석을 예약 하시겠습니까? Y/N : ");
    scanf(" %c", &YaN);
    
    if(YaN == 'n' || YaN == 'N')
    {
        printf("ㅃO\n");
        break;
    }
    
    if(YaN == 'y' || YaN == 'Y'){
           
            prnStr(a);
            //input
            printf("\n몇번 자리 예약 : ");
            scanf("%d",&check);
            check-=1;
            if(a[check] == 0)
            {
                a[check]++;
                printf("예약 되었습니다.\n");
            }else
            {
                printf("이미 예약된 자리임. \n");
            }
        }
    YaN='\0';
    
    }
    return 0;
}

