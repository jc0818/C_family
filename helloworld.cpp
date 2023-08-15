#include <iostream>

using namespace std;
int main() 
{
    int n;
    cin >> n;
     int a = 0, b = n - 1;
        int c = 3 * n - 3, d = 4 * n - 4;

        for (int i = 1; i < 2 * n; ++i) {
            if (i == 1 || i == (2 * n) - 1) {
                for (int j = a; j <= b; j++) {
                    cout<<"*";
                }
                for (int j = b + 1; j < c; j++) {
                   cout<<" ";
                }
                for (int j = c; j <= d; j++) {
                    cout<<"*";                }
            } else {
                for (int j = 0; j < a; j++) {
                    cout<<" ";

                }
                cout<<"*"; // a

                for (int j = a + 1; j < b; j++) {
                    cout<<" ";

                }
                cout<<"*";
                for (int j = b + 1; j < c; j++) {
                    cout<<" ";                }

                if (b != c) {
                    cout<<"*"; // c
                }
                for (int j = c + 1; j < d; j++) {
                    cout<<" ";

                }
                cout<<"*";
            }
           cout<<"\n";
            if (i < n) {
                a++;
                b++;
                c--;
                d--;
            } else {
                a--;
                b--;
                c++;
                d++;
            }
        }
    return 0;
    }

