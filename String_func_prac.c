#include <stdio.h>
#include <string.h>
#define MAX 16

void getInfo(char *name, char* birth, char* id)
{
	printf("생년월일 >> ");
	gets(birth);
	printf("이름 >> ");
	gets(name);
	
	strcpy(id,name);
	strcat(id,birth);
}

void comp(const char* id1, const char* id2)
{
	if(strcmp(id1, id2) < 0)
	{
		printf("비교 결과 사용자1이 앞에 위치합니다.\n");
	}else if(strcmp(id1, id2) > 0)
	{
		printf("비교 결과 사용자2가 앞에 위치합니다.\n");
	}else
	{
		printf("두 아이디는 똑같음.\n");
	}
}

int main()
{
	char name1[MAX], birth1[MAX], id1[MAX * 2];
	char name2[MAX], birth2[MAX], id2[MAX * 2];	
	
	printf("사용자1 \n");
	getInfo(name1,birth1,id1);
	printf("사용자1의 아이디는 %s입니다.\n",id1);
	printf("사용자2 \n");
	getInfo(name2,birth2,id2);
	printf("사용자2의 아이디는 %s입니다.\n\n",id2);
	
	
	comp(id1,id2);
	
	return 0;
}
