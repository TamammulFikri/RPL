#include <iostream>
using namespace std;

int main() {
    int kehadiran;
    cout << "Masukkan nilai kehadiran (%): ";
    cin >> kehadiran;

    if (kehadiran >= 75) {
        cout << "Boleh ikut ujian\n";
    } else {
        cout << "Tidak boleh ikut ujian (kehadiran kurang dari 75)\n";
    }

    return 0;
}
