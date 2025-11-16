#include <iostream>   // 표준 입출력 사용
#include <string>     // 문자열(string) 사용을 위한 라이브러리
using namespace std;

int main()
{
	string sentence;              // 입력받은 문장을 저장할 변수 선언

	getline(cin, sentence);       // 공백 포함 문장 입력받기

	for (int i = sentence.size(); i >= 0; i--)  // 문자열 끝에서부터 0까지 반복
	{
		cout << sentence[i];      // 각 문자를 역순으로 출력
	}
	cout << endl;                 // 줄바꿈 출력
	return 0;                     // 프로그램 종료
}
