#include <iostream>   // 표준 입출력 사용
#include <string>     // 문자열 사용
using namespace std;
int main()
{
    string sentence;    // 입력받은 수식 저장
    string numText;     // 숫자를 임시로 저장
    int i = 0;          // 인덱스 변수
    int sum = 0;        // 누적 합 저장
    char sign = '+';    // 현재 계산에 적용될 부호 저장 (초기값은 +)
    cout << "수식을 입력하세요 (예: 12+34-5+67): ";
    cin >> sentence;    // 공백 없는 문자열 입력
    while (true)
    {
        if (i == sentence.size())  // 문자열 끝에 도달했을 때
        {
            if (!numText.empty())  // 마지막 숫자 처리
            {
                if (sign == '+')
                    sum += stoi(numText);  // 더하기 수행
                else if (sign == '-')
                    sum -= stoi(numText);  // 빼기 수행
            }
            break;  // 반복 종료
        }
        if (sentence[i] >= '0' && sentence[i] <= '9')  // 숫자인 경우
        {
            numText += sentence[i];  // 숫자를 이어붙임
        }
        else  // 부호(+ 또는 -)를 만난 경우
        {
            if (sign == '+')
                sum += stoi(numText);  // 이전 숫자를 더함
            else if (sign == '-')
                sum -= stoi(numText);  // 이전 숫자를 뺌
            sign = sentence[i];  // 새로운 부호 저장
            numText = "";        // 숫자 문자열 초기화
        }
        i++;  // 다음 문자로 이동
    }
    cout << "계산 결과: " << sum;  // 최종 결과 출력
    return 0;                       // 프로그램 종료
}
