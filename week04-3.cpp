// week04-3.cpp
#include "week04-3.h"

//Book 클래스 구현 
Book::Book(string t, string a, int s) { //생성자
    title = t;
    author = a;
    serial = s;
}

string Book::getTitle() const { //제목 반환
    return title;
}

string Book::getAuthor() const { //저자 반환
    return author;
}

int Book::getSerial() const { // 일련번호 반환
    return serial;
}

//Libary 클래스 구현
Library::Library() { // 초기화 
    count = 0;
    for (int i = 0; i < 3; i++) {
        shelf[i] = nullptr;
    }
}

Library::~Library() { //메모리 해제
    for (int i = 0; i < 3; i++) {
        if (shelf[i] != nullptr) {
            delete shelf[i];
        }
    }
}

void Library::addBook() { //최대 3권 저장 가능
    if (count >= 3) {
        cout << "서고가 가득 찼습니다." << endl;
        return;
    }

    string t, a;
    int s;

    cout << "추가하려는 책의 정보를 입력하세요." << endl;
    cout << "제목: ";
    cin.ignore();
    getline(cin, t);
    cout << "저자: ";
    getline(cin, a);
    cout << "일련번호: ";
    cin >> s;

    shelf[count] = new Book(t, a, s); //책 추가
    count++;

    cout << "책이 추가되었습니다." << endl;
}

//제목으로 책 찾기
void Library::searchByTitle() { //
    if (count == 0) {//책 없으면 
        cout << "저장된 책이 없습니다." << endl;
        return;
    }

    string t;
    cout << "찾으려는 책의 제목을 입력하세요: ";
    cin.ignore();
    getline(cin, t);
    // 찾으면 출력
    for (int i = 0; i < count; i++) {
        if (shelf[i]->getTitle() == t) {
            cout << "일련번호는 " << shelf[i]->getSerial() << "입니다." << endl;
            return;
        }
    }
    // 없으면 메시지
    cout << "검색하신 책을 찾을 수 없습니다." << endl;

}

void Library::printAll() { // 전채 출력 
    if (count == 0) {
        cout << "저장된 책이 없습니다." << endl;
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "<" << i + 1 << ">" << endl;
        cout << "제목: " << shelf[i]->getTitle() << endl;
        cout << "저자: " << shelf[i]->getAuthor() << endl;
        cout << "일련번호: " << shelf[i]->getSerial() << endl;
    }
}

void Library::run() {
    cout << "도서관 운영을 시작합니다." << endl;
    while (true) {// 메뉴
        cout << "#########################################" << endl;
        cout << "1: 책 정보 추가  2: 책의 일련번호 검색  3: 전체 책 정보 출력  0: 프로그램 종료" << endl;
        cout << "작업을 선택하세요: ";
        int cmd;
        cin >> cmd;
        cout << endl;
        if (cmd == 1) { // 1이면 책 추가
            addBook();
        }
        else if (cmd == 2) { // 2면 책 이름으로 검색
            searchByTitle();
        }
        else if (cmd == 3) { // 책 전체 출력 
            printAll();
        }
        else if (cmd == 0) { // 종료
            cout << "#########################################\n" << "도서관 운영을 종료합니다." << endl;
            break;
        }
        else { //예외 처리 
            cout << "잘못된 입력입니다." << endl;
        }
    }
}
