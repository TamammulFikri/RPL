#include <iostream>
using namespace std;

int main()
{
    int pilihan = 2;
    switch (pilihan) {
        case 1:
            cout << "Menu 1";
            break;
        case 2:
            cout << "Menu 2";
            break;
        default:
            cout << "Pilihan tidak ada";
    }
}
