#include <iostream>
using namespace std;

class Fraction {
public:
    int bunja;
    int bunmo;

    // 기본 생성자
    Fraction() {
        bunja = 0;
        bunmo = 1;  // 분모는 0이면 안 됨
    }

    // 분자, 분모 초기화 생성자
    Fraction(int a, int b) {
        bunja = a;
        bunmo = b;
        reduce();  // 생성할 때 자동으로 기약분수 처리
    }

    // 최대공약수(GCD) 계산 (유클리드 호제법)
    int gcd(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    // 기약분수로 만드는 함수
    void reduce() {
        int g = gcd(bunja, bunmo);
        bunja /= g;
        bunmo /= g;
        if (bunmo < 0) {  // 분모가 음수일 경우 부호 정리
            bunja = -bunja;
            bunmo = -bunmo;
        }
    }

    // 덧셈: f1 + f2
    Fraction add(const Fraction& other) {
        Fraction temp;
        temp.bunja = bunja * other.bunmo + other.bunja * bunmo;
        temp.bunmo = bunmo * other.bunmo;
        temp.reduce();
        return temp;
    }

    // 뺄셈: f1 - f2
    Fraction sub(const Fraction& other) {
        Fraction temp;
        temp.bunja = bunja * other.bunmo - other.bunja * bunmo;
        temp.bunmo = bunmo * other.bunmo;
        temp.reduce();
        return temp;
    }

    // 곱셈: f1 * f2
    Fraction mul(const Fraction& other) {
        Fraction temp;
        temp.bunja = bunja * other.bunja;
        temp.bunmo = bunmo * other.bunmo;
        temp.reduce();
        return temp;
    }

    // 나눗셈: f1 / f2
    Fraction div(const Fraction& other) {
        Fraction temp;
        temp.bunja = bunja * other.bunmo;
        temp.bunmo = bunmo * other.bunja;
        temp.reduce();
        return temp;
    }

    // 출력 함수
    void print() {
        cout << bunja << "/" << bunmo << endl;
    }


};

int main() {
    int a, b;
//입력 및 두 분수에 대한 객체 생성  
    cout << "분수 1 입력 (분자 분모): ";
    cin >> a >> b;
    Fraction f1(a, b);

    cout << "분수 2 입력 (분자 분모): ";
    cin >> a >> b;
    Fraction f2(a, b);

    cout << "\n분수 1: ";
    f1.print();
    cout << "분수 2: ";
    f2.print();
    cout << endl;
	
    // 연산 결과 출력
    Fraction addResult = f1.add(f2);
    Fraction subResult = f1.sub(f2);
    Fraction mulResult = f1.mul(f2);
    Fraction divResult = f1.div(f2);
	//출력  
    cout << "합: ";
    addResult.print();

    cout << "차: ";
    subResult.print();

    cout << "곱: ";
    mulResult.print();

    cout << "나눗셈: ";
    divResult.print();
    
    return 0; 
}
