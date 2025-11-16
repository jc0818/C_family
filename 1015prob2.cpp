#include <iostream>
#include <string>

using namespace std;

class User {
public:
    static int idn; // 다음 객체에 부여될 고유 아이디
    static int cnt; // 현재 존재하는 객체 수
    int id;         // 객체 고유 아이디
    string name;    // 사용자 이름

    void print();         // 객체 정보 출력
    static void printCnt(); // 현재 객체 수 출력

    User() {
        cout << "이름: ";
        getline(cin, name);
        id = idn++;  // 객체 생성 시 고유 아이디 부여
        cnt++;       // 객체 수 증가
        cout << "계정이 생성되었습니다." << endl;
    }

    ~User() {
        cout << "계정이 삭제되었습니다." << endl;
        cnt--;       // 객체 소멸 시 객체 수 감소
    }
};

// 객체 정보 출력
void User::print() {
    cout << name << "(" << id << ")" << endl;
}

// 현재 객체 수 출력
void User::printCnt() {
    cout << "\n현재 유저수: " << cnt << endl << endl;
}

// 정적 멤버 초기화
int User::idn = 1000;
int User::cnt = 0;

int main() {
    User* userArr = new User[3]; // 동적 배열로 User 객체 3개 생성
    for (int i = 0; i < 3; i++) {
        userArr[i].print();       // 각 객체 정보 출력
    }
    User::printCnt();             // 현재 객체 수 출력

    delete[] userArr;             // 객체 소멸 및 메모리 해제

    userArr = new User[2];        // User 객체 2개 생성
    for (int i = 0; i < 2; i++) {
        userArr[i].print();
    }
    User::printCnt();

    delete[] userArr;             // 객체 소멸 및 메모리 해제
    User::printCnt();             // 최종 객체 수 출력

    return 0;
}

