#include <iostream>
using namespace std;
// 피라미드를 출력하는 함수
// a: 피라미드 문자 / b: 배경 문자 / c: 층수 / d: 상하 반전 여부
void printPyramid(char a, char b=' ', int c = 4, bool d=false) {
	char main = a;   // 피라미드를 구성할 문자
	char space = b;  // 배경 문자
	int size = c;    // 피라미드 층수
	bool reverse = d; // 상하 반전 여부
	// 상하 반전(true)
	if (reverse == true)
	{
		for (int i = size - 1; i >= 0; i--) // 층을 거꾸로 반복
		{
			for (int j = 0; j < size - i; j++) // 왼쪽 여백 출력
				cout << space;
			for (int k = 0; k < i * 2 + 1 ; k++) // 피라미드 본체 출력
				cout << main;
			for (int j = 0; j < size - i; j++) // 오른쪽 여백 출력
				cout << space;
			cout << endl; // 줄바꿈
		}
	}
	// 일반 피라미드(false
	else
	{
		for (int i = 0; i < size; i++) // 층을 위에서 아래로 반복
		{
			for (int j = 0; j < size - i; j++) // 왼쪽 여백 출력
				cout << space;
			for (int k = 0; k < i * 2 + 1; k++) // 피라미드 본체 출력
				cout << main;
			for (int j = 0; j < size - i; j++) // 오른쪽 여백 출력
				cout << space;
			cout << endl; // 줄바꿈
		}
	}
};
int main()
{
	printPyramid('*');               // 기본 피라미드
	printPyramid('1', '=');          // 배경 문자 '=' 사용
	printPyramid('^', '~', 7);       // 층수를 7로 설정
	printPyramid('V', '.', 5, true); // 역피라미드 출력
}

