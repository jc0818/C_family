#include <iostream>
#include <string>
using namespace std;

// 학생 정보를 저장하는 클래스
class Student {
public:
    string name;                     // 이름
    double score[6] = { 0,0,0,0,0,0 }; // 6개의 과제 점수

    void printInfo();                 // 학생 정보 출력
    double avg_score(double score[6]); // 평균 점수 계산
    bool check(double score[6]);       // 불합격 여부 확인
    void init(string a);               // 이름 및 점수 입력 함수

    // 기본 생성자 (기본값으로 초기화)
    Student() {
        name = "김동국";
        score[0] = 100; score[1] = 99; score[2] = 98;
        score[3] = 97;  score[4] = 96; score[5] = 95;
    }

    // 소멸자 (출력 종료 알림)
    ~Student() {
        cout << name << " 출력 끝." << endl;
    }
};

// 이름과 점수 입력
void Student::init(string a) {
    name = a;
    cout << "과제 점수 6개 입력: ";
    cin >> score[0] >> score[1] >> score[2] >> score[3] >> score[4] >> score[5];
}

// 10점 미만이 있으면 불합격(true)
bool Student::check(double score[6]) {
    for (int i = 0; i < 6; ++i) {
        if (score[i] < 10) return true;
    }
    return false;
}

// 평균 점수 계산
double Student::avg_score(double score[6]) {
    double temp = 0.0;
    for (int i = 0; i < 6; ++i) temp += score[i];
    return temp / 6.0;
}

// 학생 정보 출력
void Student::printInfo() {
    cout << "이름: " << name << endl;
    cout << "과제 성적: ";
    for (int i = 0; i < 6; i++) cout << score[i] << " ";

    cout << "\n과제 점수 평균: " << avg_score(score);
    if (check(score)) cout << "(불합격)" << endl;
    else cout << "(합격)" << endl;
    cout << endl;
}

// 강의(학생 집합)를 관리하는 클래스
class Lecture {
public:
    Student* students;  // 동적 학생 배열
    int size;           // 학생 수

    void setStudentsInfo();  // 학생 정보 입력
    void printBestStudent(); // 최고 점수 학생 출력

    // 생성자: 학생 수만큼 배열 동적할당
    Lecture(int num) {
        size = num;
        students = new Student[num];
    }

    // 소멸자: 메모리 해제
    ~Lecture() {
        delete[] students;
    }
};

// 학생 정보 입력
void Lecture::setStudentsInfo() {
    for (int i = 0; i < size; i++) {
        string name;
        cout << "이름 입력: ";
        cin >> name;
        students[i].init(name);  // 이름과 점수 입력
    }
}

// 최고 점수 학생 출력
void Lecture::printBestStudent() {
    if (size == 0) return;
    int bestIdx = 0;
    double bestAvg = students[0].avg_score(students[0].score);

    for (int i = 1; i < size; i++) {
        double curAvg = students[i].avg_score(students[i].score);
        if (curAvg > bestAvg) {
            bestAvg = curAvg;
            bestIdx = i;
        }
    }

    cout << "최고 점수 학생 정보:" << endl;
    students[bestIdx].printInfo();
}

// 프로그램 실행 시작점
int main() {
    int num;
    cout << "학생 수 입력: ";
    cin >> num;

    Lecture lecture(num);      // Lecture 객체 생성
    lecture.setStudentsInfo(); // 학생 정보 입력
    lecture.printBestStudent();// 최고 점수 학생 출력

    return 0; // 프로그램 종료
}
