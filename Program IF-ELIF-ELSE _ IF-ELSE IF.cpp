#include <iostream>
using namespace std;

int main()
{
    int nilai = 85;
    if (nilai >= 90) {
        cout << "Grade A";
    }
    else if (nilai >= 80) {
        cout << "Grade B";
    }
    else if (nilai >= 70) {
        cout << "Grade C";
    }
    else {
        cout << "Grade D";
    }

    return 0;
}
