// week04-3.h
#ifndef WEEK04_3_H
#define WEEK04_3_H

#include <iostream>
#include <string>
using namespace std;

// 책 정보를 저장하는 클래스
class Book {
private:
    string title;  // 제목
    string author; // 저자
    int serial;    // 일련번호
public:
    Book(string t, string a, int s);  // 생성자
    string getTitle() const;           // 제목 반환
    string getAuthor() const;          // 저자 반환
    int getSerial() const;             // 일련번호 반환
};

// 도서관 클래스
class Library {
private:
    Book* shelf[3];  // 책 저장 배열 (최대 3권)
    int count;       // 현재 저장된 책 수
public:
    Library();       // 생성자
    ~Library();      // 소멸자
    void addBook();      // 책 추가
    void searchByTitle();// 제목으로 책 검색
    void printAll();     // 모든 책 정보 출력
    void run();          // 도서관 운영
};

#endif
