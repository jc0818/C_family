#include <iostream>
#include <string>
using namespace std;

class Todo { // Todo의 추상 기반 클래스
protected:
    string doName; // 할 일 이름
public:
    Todo(string name = "") : doName(name) {} // 생성자
    virtual int getWeight() = 0; // 중요도 계산 (순수 가상)
    virtual void show() = 0; // 출력 함수 (순수 가상)

    string getName() { return doName; } // 이름 반환
};

class HouseChore : public Todo { // 집안일 클래스
private:
    int score; // 난이도/우선도
    int time; // 예상 소요시간
public:

    HouseChore(string n, int a, int b) : Todo(n), score(a), time(b) {} // 생성자

    void show() { // 정보 출력
        cout << "집안일: " << doName << ", 우선도: " << score
            << ", 예상시간: " << time << ", 중요도: " << getWeight() << endl;
    }

    int getWeight() { // 중요도 계산
        int w = score * 10 + time / 3;
        if (w > 100) w = 100;
        return w;
    }
};

class Study : public Todo { // 공부 클래스
private:
    int important = 50; // 기본 중요도
    int score; // 남은 페이지
    int time;  // 시험까지 남은 날
public:

    Study(string n, int a, int b) : Todo(n), score(a), time(b) {} // 생성자

    void show() { // 출력
        cout << "공부: " << doName << ", 남은 페이지: " << score
            << ", 시험까지 남은 날: " << time << ", 중요도: " << getWeight() << endl;
    }

    int getWeight() { // 중요도 계산
        int w = 50 + (score / 2) + (10 - time) * 5;
        if (w < 0) w = 0;
        if (w > 100) w = 100;
        return w;
    }
};

class Appointment : public Todo { // 약속 클래스
private:
    int score; // 약속까지 남은 시간
    int time;  // 중요도
public:

    Appointment(string n, int a, int b) : Todo(n), time(a), score(b) {} // 생성자

    void show() { // 출력
        cout << "약속: " << doName << ", 약속까지 남은 시간: " << score
            << ", 중요도: " << time << ", 중요도: " << getWeight() << endl;
    }

    int getWeight() { // 중요도 계산
        int w = score * 20 + (10 - time) * 5;
        if (w < 0) w = 0;
        if (w > 100) w = 100;
        return w;
    }
};

void sortTodos(Todo* todos[], int size) { // 중요도 기준 정렬 함수
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {

            int w1 = todos[j]->getWeight(); // 앞 요소 중요도
            int w2 = todos[j + 1]->getWeight(); // 다음 요소 중요도

            if (w1 < w2) { // 중요도 큰 순 정렬
                Todo* temp = todos[j];
                todos[j] = todos[j + 1];
                todos[j + 1] = temp;
            }
            else if (w1 == w2) { // 중요도 동일  이름 사전순 정렬
                if (todos[j]->getName() > todos[j + 1]->getName()) {
                    Todo* temp = todos[j];
                    todos[j] = todos[j + 1];
                    todos[j + 1] = temp;
                }
            }
        }
    }
}

int main() {
    Todo* todos[10]; // Todo 포인터 배열

    todos[0] = new HouseChore("청소", 3, 30);
    todos[1] = new Study("C++ 공부", 100, 5);
    todos[2] = new Appointment("의사 예약", 2, 4);
    todos[3] = new HouseChore("설거지", 2, 20);
    todos[4] = new Study("알고리즘 공부", 50, 3);
    todos[5] = new Appointment("친구 만나기", 1, 5);
    todos[6] = new HouseChore("빨래", 1, 15);
    todos[7] = new Study("자료구조 복습", 30, 4);
    todos[8] = new Appointment("회의 준비", 3, 6);
    todos[9] = new HouseChore("정리정돈", 2, 25);

    sortTodos(todos, 10); // 정렬 실행

    cout << "정렬된 할 일 목록:" << endl;

    for (int i = 0; i < 10; ++i)
        todos[i]->show(); // 출력

    for (int i = 0; i < 10; ++i)
        delete todos[i]; // 메모리 해제

    return 0; // 종료
}
