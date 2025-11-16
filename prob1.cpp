#include <iostream>
#include <string>
using namespace std;

class Shape {   // 도형의 공통 기반 클래스
protected:
    string name;                    // 도형 이름
public:
    Shape(string n = "") : name(n) {}  // 생성자
    virtual ~Shape() {}               // 가상 소멸자

    virtual double getArea() = 0;     // 면적 계산 (순수 가상)
    virtual void show() = 0;          // 정보 출력 (순수 가상)
};

class Circle : public Shape {         // 원 클래스
private:
    int radius;                       // 반지름
public:
    Circle(string n, int r) : Shape(n), radius(r) {}   // 생성자

    double getArea() { return 3.14 * radius * radius; }  // 면적

    void show() {                      // 출력 함수
        cout << "이름: " << name
            << ", 면적: " << getArea() << endl;
    }
};

class Rectangle : public Shape {      // 직사각형 클래스
private:
    int width;                        // 가로
    int height;                       // 세로
public:
    Rectangle(string n, int w, int h) : Shape(n), width(w), height(h) {} // 생성자

    double getArea() { return width * height; }  // 면적

    void show() {                      // 출력 함수
        cout << "이름: " << name
            << ", 면적: " << getArea() << endl;
    }
};

class Triangle : public Shape {       // 삼각형 클래스
private:
    double base;    // 밑변              
    double height;    // 높이                            
public:
    Triangle(string n, double b, double h) : Shape(n), base(b), height(h) {} // 생성자

    double getArea() { return base * height / 2.0; }  // 면적

    void show() {                      // 출력 함수
        cout << "이름: " << name
            << ", 면적: " << getArea() << endl;
    }
};

class Oval : public Shape { // 타원 클래스
private:
    int shortR;  // 단축
    int longR;   // 장축
public:
    Oval(string n, int a, int b) : Shape(n), shortR(a), longR(b) {} // 생성자

    double getArea() { return 3.14 * shortR * longR; }   // 면적

    void show() {                      // 출력 함수
        cout << "이름: " << name
            << ", 면적: " << getArea() << endl;
    }
};

int main() {

    Shape* shapes[4]; // Shape 포인터 배열 (업캐스팅용)

    shapes[0] = new Circle("피자", 30); // Circle 객체 생성
    shapes[1] = new Rectangle("교과서", 20, 25); // Rectangle 객체 생성
    shapes[2] = new Triangle("도로표지판", 30, 43.3); // Triangle 객체 생성
    shapes[3] = new Oval("계란", 5, 10); // Oval 객체 생성

    shapes[0]->show();
    shapes[1]->show();
    shapes[2]->show();
    shapes[3]->show();


    for (int i = 0; i < 4; i++) // 메모리 해제
        delete shapes[i];

    return 0; // 프로그램 종료

   
}
