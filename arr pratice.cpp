#include <stdio.h>

int main()
{//좌우 뒤집기 
	int i,j;
	int arr[5][5]={
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25}
	};
	
	for(i=0;i<5;i++)
	{
		for(j=4;j>=0;j--)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}

/*
//상하 뒤집기
int main()
{
	int i,j;
	int arr[5][5]={
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25}
	};
	
	for(i=4;i>=0;i--)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	
}

//지그재그 
int main()
{
	int i,j;
	int temp=1;
	int arr[5][5]={
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25}
	};
	
	for(i=0;i<5;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<5;j++)
			arr[i][j] = temp++;
		}
		else {
		for(j=5-1;j>=0;j--)
		{
		arr[i][j]=temp++;
		}
	}
	
	}
	
	  for(i=0;i<5;i++){
        for(j=0;j<5;j++){
            printf("%2d ", arr[i][j]);
        }
        printf("\n"); 
    }
	
}

//좌우 지렁이 
int main()
{
	int i,j;
	int temp=1;
	int arr[5][5]={
	{1,2,3,4,5},
	{6,7,8,9,10},
	{11,12,13,14,15},
	{16,17,18,19,20},
	{21,22,23,24,25}
	};
	
	for(i=0;i<5;i++)
	{
		if(i%2==0)
		{
			for(j=0;j<5;j++)
			printf("%2d ",arr[i][j]);
		}
		else {
		for(j=4;j>=0;j--)
		{
		printf("%2d ",arr[i][j]);
		}
	}
	printf("\n");
	}
	
	
	
}
*/
