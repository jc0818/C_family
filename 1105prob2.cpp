#include <iostream>
#include <string>

using namespace std;

// 전자기기 기본 클래스
class ElectronicDevice {
public:
    string Ebrand;          // 브랜드명
    string Emodel;          // 모델명
    int battery;            // 배터리 잔량

    void printInfo()        // 기기 정보 출력
    {
        cout << "브랜드: " + Ebrand + ", ";
        cout << "모델: " + Emodel + ", ";
        cout << "현재 배터리 용량: " << battery << "%" << endl;
    }
};

class Phone : public virtual ElectronicDevice {   // 전화 기능 클래스
public:
    string phoneNumber;     // 전화번호

    void call()             // 전화 기능
    {
        string setCall;
        cout << "전화할 번호를 입력하세요: ";
        cin.ignore();
        getline(cin, setCall);
        cout << "전화 거는 중: " + setCall + " >> " + phoneNumber << endl;
    }
};

class Camera : public virtual ElectronicDevice {  // 카메라 기능 클래스
public:
    int cameraMP;           // 카메라 화소

    void takeAPhoto()       // 사진 촬영
    {
        cout << "사진 찍는 중. 화소 : " << cameraMP << " MP" << endl;
        cout << "사진 촬영 완료." << endl;
    }
};

class SmartPhone : public Phone, public Camera {  // 스마트폰 클래스
public:
    SmartPhone(string brand, string model, int charge, string phoneNum, int cp)
    {
        Ebrand = brand;     // 브랜드 설정
        Emodel = model;     // 모델 설정
        battery = charge;   // 배터리 잔량 설정
        phoneNumber = phoneNum; // 전화번호 설정
        cameraMP = cp;      // 카메라 화소 설정
    }

    void run()              // 스마트폰 메뉴 실행
    {
        cout << "===========================" << endl;
        int check = NULL;
        while (true)
        {
            cout << "1. 정보 확인 2. 전화 걸기 3. 사진 찍기 4. 인터넷 접속 0. 종료" << endl;
            cout << "스마트폰 기능 선택: ";
            cin >> check;

            if (check == 1)
                printInfo();            // 정보 출력
            else if (check == 2)
                call();                 // 전화 기능
            else if (check == 3)
                takeAPhoto();           // 사진 기능
            else if (check == 4)
                internetOn();           // 인터넷 접속
            else if (check == 0)
            {
                cout << "프로그램을 종료합니다." << endl;
                break;                  // 종료
            }
            else
                cout << "잘못된 입력입니다. 다시 시도하세요." << endl;

            cout << "===========================" << endl;
        }
    }

    void internetOn()        // 인터넷 접속 기능
    {
        cout << "인터넷 접속 완료, " + Ebrand + " " + Emodel << endl;
    }
};

int main()
{
    SmartPhone myPhone("Samsung", "S25", 95, "010-1234-5678", 12); // 스마트폰 생성
    myPhone.run();        // 스마트폰 기능 실행

    return 0;
}
