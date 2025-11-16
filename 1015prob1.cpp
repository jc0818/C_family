#include <iostream>
#include <math.h>
using namespace std;
class Calculator {
public:
    // 한 개의 정수를 받아 제곱을 계산함
    int calculate(int a) {
        return pow(a, 2);
    }
    // 두 개의 정수를 받아 합을 계산함
    int calculate(int a, int b) {
        return a + b;
    }
    // 두 개의 실수를 받아 합을 계산함
    double calculate(double a, double b) {
        return a + b;
    }
    // 실수와 정수를 받아 합을 계산함
    double calculate(double a, int b) {
        return a + b;
    }
    // 정수와 실수를 받아 합을 계산함
    double calculate(int a, double b) {
        return a + b;
    }
    // 세 개의 정수를 받아 평균을 계산함
    double calculate(int a, int b, int c) {
        int sum = a + b + c;
        return (double)sum / 3.0;
    }
};
int main() {
    Calculator myCal;
    cout << myCal.calculate(2) << endl;      // 2의 제곱 계산
    cout << myCal.calculate(2, 3) << endl;   // 정수 2개 합
    cout << myCal.calculate(2.1, 3.8) << endl; // 실수 2개 합
    cout << myCal.calculate(2.1, 3) << endl;   // 실수+정수 합
    cout << myCal.calculate(2, 3.8) << endl;   // 정수+실수 합
    cout << myCal.calculate(3, 5, 9) << endl;  // 정수 3개 평균
    return 0;
}

