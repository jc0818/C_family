#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 81

void checkArr(char *arr)
{
	int point = 0;
	int contNum = 1;
	int size = strlen(arr);
	
	
	for(int i = 0; i < size; ++i)
	{
		if(*(arr+i) == 'O')
		{
			point += contNum;
			++contNum;
				
		}else
		{
			contNum = 1;	
		}	
	}
	
	printf("%d\n",point);
	
}

//포인터 문제 
int main()
{
	char *arr="";
	int num;
	
	scanf("%d", &num);
	getchar(); 
	for(int i = 0; i < num; i++)
	{
		arr = (char *)malloc(sizeof(char) * MAX); // 메모리 동적 할당

        fgets(arr, MAX, stdin);
        arr[strcspn(arr, "\n")] = '\0';  // 개행 문자 제거

        checkArr(arr);

        free(arr);  // 동적 메모리 해제
    }
	
	return 0;
}
