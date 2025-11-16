#include <iostream>   // 표준 입출력 사용
#include <string>     // 문자열(string) 관련 기능 사용
using namespace std;

int main()
{
	string sentence;      // 원본 문자열
	string changestr;     // 바꿀 단어
	string setStr;        // 대체할 단어
	int pos = 0;          // 검색 시작 위치 인덱스

	cout << "원본 문자열을 입력하세요: ";
	getline(cin, sentence);   // 공백 포함 문장 입력받기

	cout << "바꿀 이름을 입력하세요: ";
	getline(cin, changestr);  // 찾을 단어 입력받기

	cout << "바뀔 이름을 입력하세요: ";
	getline(cin, setStr);     // 대체 단어 입력받기

	while ((pos = sentence.find(changestr, pos)) != string::npos)  // 찾을 단어가 존재하는 동안 반복
	{
		sentence.replace(pos, changestr.length(), setStr);         // 해당 부분을 새 단어로 교체
		pos += setStr.length();                                    // 다음 검색 위치로 이동
	}

	cout << "바뀐 문자열: " << sentence << endl;   // 교체 완료된 문자열 출력
	return 0;                                      // 프로그램 종료
}
