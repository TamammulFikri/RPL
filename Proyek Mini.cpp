#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main() {
    string nama[50];
    int durasi[50];
    bool selesai[50];

    int count = 5;

    nama[0] = "Mengerjakan Matematika";
    durasi[0] = 60;
    selesai[0] = false;

    nama[1] = "Membaca Buku";
    durasi[1] = 30;
    selesai[1] = true;

    nama[2] = "Mengerjakan Bahasa Indonesia";
    durasi[2] = 90;
    selesai[2] = false;

    nama[3] = "Belajar Pemrograman";
    durasi[3] = 120;
    selesai[3] = true;

    nama[4] = "Mengerjakan Tugas Produktif";
    durasi[4] = 100;
    selesai[4] = false;

    int pilihan;

    do {
        cout << "\n====================================\n";
        cout << "     PENJADWAL TUGAS HARIAN SISWA\n";
        cout << "====================================\n";
        cout << "1. Tambah Tugas\n";
        cout << "2. Lihat Semua Tugas\n";
        cout << "3. Cari Tugas Berdasarkan Durasi\n";
        cout << "4. Hapus Tugas\n";
        cout << "5. Laporan Ringkas\n";
        cout << "6. Keluar\n";
        cout << "====================================\n";

        while (true) {
            cout << "Pilih menu: ";

            if (cin >> pilihan && pilihan >= 1 && pilihan <= 6) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }

            cout << "Input tidak valid. Masukkan angka 1-6.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (pilihan) {
        case 1: {
            if (count >= 50) {
                cout << "\nTugas sudah mencapai batas maksimal 50.\n";
                break;
            }

            cout << "\n--- Tambah Tugas ---\n";

            do {
                cout << "Nama tugas: ";
                getline(cin, nama[count]);

                if (nama[count].empty()) {
                    cout << "Nama tugas tidak boleh kosong.\n";
                }
            } while (nama[count].empty());

            while (true) {
                cout << "Durasi (menit): ";

                if (cin >> durasi[count] && durasi[count] > 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Durasi harus berupa angka lebih dari 0.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            selesai[count] = false;
            count++;

            cout << "Tugas berhasil ditambahkan.\n";

            break;
        }

        case 2: {
            cout << "\n--- Semua Tugas ---\n";

            if (count == 0) {
                cout << "Belum ada tugas.\n";
                break;
            }

            for (int i = 0; i < count; i++) {
                cout << "\nTugas ke-" << i + 1 << endl;
                cout << "Nama   : " << nama[i] << endl;
                cout << "Durasi : " << durasi[i] << " menit" << endl;

                if (selesai[i]) {
                    cout << "Status : Selesai" << endl;
                }
                else {
                    cout << "Status : Belum selesai" << endl;
                }
            }

            break;
        }

        case 3: {
            int batasDurasi;
            bool ditemukan = false;

            cout << "\n--- Cari Tugas ---\n";

            while (true) {
                cout << "Tampilkan tugas dengan durasi >= ";

                if (cin >> batasDurasi && batasDurasi >= 0) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Input tidak valid. Masukkan angka.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            cout << "\nHasil pencarian:\n";

            for (int i = 0; i < count; i++) {
                if (durasi[i] >= batasDurasi) {
                    cout << i + 1 << ". "
                        << nama[i]
                        << " - "
                        << durasi[i]
                        << " menit";

                    if (selesai[i]) {
                        cout << " - Selesai";
                    }
                    else {
                        cout << " - Belum selesai";
                    }

                    cout << endl;
                    ditemukan = true;
                }
            }

            if (!ditemukan) {
                cout << "Tidak ada tugas dengan durasi tersebut.\n";
            }

            break;
        }

        case 4: {
            int nomor;

            cout << "\n--- Hapus Tugas ---\n";

            if (count == 0) {
                cout << "Tidak ada tugas yang dapat dihapus.\n";
                break;
            }

            for (int i = 0; i < count; i++) {
                cout << i + 1 << ". "
                    << nama[i]
                    << " - "
                    << durasi[i]
                    << " menit\n";
            }

            while (true) {
                cout << "Masukkan nomor tugas yang ingin dihapus: ";

                if (cin >> nomor && nomor >= 1 && nomor <= count) {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    break;
                }

                cout << "Nomor tugas tidak valid.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            nomor--;

            for (int i = nomor; i < count - 1; i++) {
                nama[i] = nama[i + 1];
                durasi[i] = durasi[i + 1];
                selesai[i] = selesai[i + 1];
            }

            count--;

            cout << "Tugas berhasil dihapus.\n";

            break;
        }

        case 5: {
            int totalDurasi = 0;
            int jumlahSelesai = 0;
            int jumlahBelum = 0;

            for (int i = 0; i < count; i++) {
                totalDurasi += durasi[i];

                if (selesai[i]) {
                    jumlahSelesai++;
                }
                else {
                    jumlahBelum++;
                }
            }

            cout << "\n--- LAPORAN RINGKAS ---\n";
            cout << "Total tugas    : " << count << endl;
            cout << "Total durasi   : " << totalDurasi << " menit" << endl;
            cout << "Jumlah selesai : " << jumlahSelesai << endl;
            cout << "Jumlah belum   : " << jumlahBelum << endl;

            if (totalDurasi > 300) {
                cout << "\nPERINGATAN!\n";
                cout << "Total durasi tugas lebih dari 300 menit.\n";
                cout << "Pertimbangkan untuk mengatur waktu istirahat.\n";
            }

            break;
        }

        case 6:
            cout << "\nProgram selesai. Terima kasih.\n";
            break;
        }

    } while (pilihan != 6);

    return 0;
}
