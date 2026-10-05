#include <iostream>
#include <string>

using namespace std;

const int MAX_BARANG = 50;
string namaBarang[MAX_BARANG];
int harga[MAX_BARANG];
int stok[MAX_BARANG];
int terjual[MAX_BARANG];
int jumlahBarang = 0;

void inisialisasiDataAwal() {
    namaBarang[0] = "Nasi Goreng"; harga[0] = 15000; stok[0] = 20; terjual[0] = 0;
    namaBarang[1] = "Mie Goreng";  harga[1] = 12000; stok[1] = 15; terjual[1] = 0;
    namaBarang[2] = "Es Teh";      harga[2] = 5000;  stok[2] = 30; terjual[2] = 0;
    namaBarang[3] = "Air Mineral"; harga[3] = 4000;  stok[3] = 25; terjual[3] = 0;
    namaBarang[4] = "Roti Bakar";  harga[4] = 10000; stok[4] = 10; terjual[4] = 0;
    jumlahBarang = 5;
}

int main() {
    inisialisasiDataAwal();
    int pilihanMenu;

    do {
        cout << "====================================\n";
        cout << "     KANTIN SMK JAKARTA PUSAT 1     \n";
        cout << "               TAMAM                \n";
        cout << "====================================\n";
        cout << "1. Tambah Barang\n";
        cout << "2. Lihat Daftar Barang\n";
        cout << "3. Transaksi Penjualan\n";
        cout << "4. Lihat Laporan Penjualan\n";
        cout << "5. Cari Barang\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu : ";
        cin >> pilihanMenu;
        cout << "====================================\n";

        switch (pilihanMenu) {
            case 1: {
                if (jumlahBarang >= MAX_BARANG) {
                    cout << "Kapasitas barang sudah mencapai maksimum (50)!\n";
                    break;
                }

                string nama;
                int hrg, stk;

                cout << "Masukkan Nama Barang : ";
                cin.ignore();
                getline(cin, nama);

                if (nama == "") {
                    cout << "Nama barang tidak boleh kosong!\n";
                    break;
                }

                cout << "Masukkan Harga       : ";
                cin >> hrg;
                if (hrg <= 0) {
                    cout << "Harga tidak valid! Harga harus lebih dari 0.\n";
                    break;
                }

                cout << "Masukkan Stok        : ";
                cin >> stk;
                if (stk < 0) {
                    cout << "Stok tidak boleh kurang dari 0!\n";
                    break;
                }

                namaBarang[jumlahBarang] = nama;
                harga[jumlahBarang] = hrg;
                stok[jumlahBarang] = stk;
                terjual[jumlahBarang] = 0;
                jumlahBarang++;

                cout << "Barang berhasil ditambahkan.\n";
                break;
            }
            case 2: {
                if (jumlahBarang == 0) {
                    cout << "Data barang masih kosong.\n";
                } else {
                    cout << "NO | NAMA BARANG      | HARGA    | STOK | TERJUAL\n";
                    cout << "--------------------------------------------------\n";
                    for (int i = 0; i < jumlahBarang; i++) {
                        cout << i + 1 << "  | " << namaBarang[i];
                        for (int j = namaBarang[i].length(); j < 16; j++) cout << " ";
                        cout << "| Rp" << harga[i];
                        for (int j = std::to_string(harga[i]).length(); j < 7; j++) cout << " ";
                        cout << " | " << stok[i] << "   | " << terjual[i] << "\n";

                        if (stok[i] <= 5) {
                            cout << "     [PERINGATAN! Stok " << namaBarang[i] << " hampir habis. Sisa: " << stok[i] << "]\n";
                        }
                    }
                }
                break;
            }
            case 3: {
                if (jumlahBarang == 0) {
                    cout << "Belum ada barang di kantin untuk dijual.\n";
                    break;
                }

                string tambahLagi;
                int keranjangIndex[100];
                int keranjangQty[100];
                int jumlahTransaksi = 0;
                long totalBelanja = 0;

                do {
                    cout << "\nDaftar Barang:\n";
                    for (int i = 0; i < jumlahBarang; i++) {
                        cout << i + 1 << ". " << namaBarang[i] << " (Rp" << harga[i] << " | Stok: " << stok[i] << ")\n";
                    }

                    int nomorPilihan, jumlahBeli;
                    cout << "Masukkan nomor barang: ";
                    cin >> nomorPilihan;

                    if (nomorPilihan < 1 || nomorPilihan > jumlahBarang) {
                        cout << "Nomor barang tidak tersedia!\n";
                    } else {
                        int index = nomorPilihan - 1;
                        cout << "Barang      : " << namaBarang[index] << "\n";
                        cout << "Harga       : Rp" << harga[index] << "\n";
                        cout << "Jumlah beli : ";
                        cin >> jumlahBeli;

                        if (jumlahBeli <= 0) {
                            cout << "Jumlah pembelian tidak valid!\n";
                        } else if (jumlahBeli > stok[index]) {
                            cout << "Stok tidak mencukupi!\n";
                            cout << "Stok tersedia : " << stok[index] << "\n";
                        } else {
                            long subtotal = harga[index] * jumlahBeli;
                            cout << "Subtotal    : Rp" << subtotal << "\n";

                            keranjangIndex[jumlahTransaksi] = index;
                            keranjangQty[jumlahTransaksi] = jumlahBeli;
                            jumlahTransaksi++;

                            stok[index] = stok[index] - jumlahBeli;
                            terjual[index] = terjual[index] + jumlahBeli;

                            totalBelanja += subtotal;
                        }
                    }

                    cout << "Tambah barang lain? (Y/T): ";
                    cin >> tambahLagi;

                } while (tambahLagi == "Y" || tambahLagi == "y");

                if (jumlahTransaksi > 0) {
                    char statusMember;
                    double diskonPersen = 0;

                    // Cek Status Member
                    cout << "Apakah pembeli memiliki kartu member? (y/t): ";
                    cin >> statusMember;

                    if (statusMember == 'Y' || statusMember == 'y') {
                        diskonPersen = 0.10; // Diskon 10% khusus member
                    } else {
                        diskonPersen = 0;    // Non-member tidak dapat diskon
                    }

                    long jumlahDiskon = totalBelanja * diskonPersen;
                    long totalBayar = totalBelanja - jumlahDiskon;

                    // Cetak Struk Pembelian
                    cout << "\n========================================\n";
                    cout << "       KANTIN SMK JAKARTA PUSAT 1       \n";
                    cout << "                 TAMAM                  \n";
                    cout << "========================================\n";
                    cout << "Status Member : " << ((diskonPersen > 0) ? "Ya (Diskon 10%)" : "Tidak") << "\n";
                    cout << "----------------------------------------\n";
                    for (int i = 0; i < jumlahTransaksi; i++) {
                        int idx = keranjangIndex[i];
                        cout << namaBarang[idx] << "\n";
                        cout << keranjangQty[i] << " x Rp" << harga[idx] << "\t\tRp" << (harga[idx] * keranjangQty[i]) << "\n";
                    }
                    cout << "----------------------------------------\n";
                    cout << "Subtotal\t\tRp" << totalBelanja << "\n";
                    cout << "Diskon (" << (diskonPersen * 100) << "%)\t\tRp" << jumlahDiskon << "\n";
                    cout << "----------------------------------------\n";
                    cout << "TOTAL\t\t\tRp" << totalBayar << "\n";
                    cout << "========================================\n";
                    cout << "Terima kasih\n\n";
                }
                break;
            }
            case 4: {
                if (jumlahBarang == 0) {
                    cout << "Belum ada data laporan.\n";
                    break;
                }

                int totalUnitTerjual = 0;
                long totalPendapatan = 0;
                int maxTerjual = -1;
                int idxTerlaris = 0;
                int minStok = 99999;
                int idxStokMin = 0;

                for (int i = 0; i < jumlahBarang; i++) {
                    totalUnitTerjual += terjual[i];
                    totalPendapatan += (terjual[i] * harga[i]);

                    if (terjual[i] > maxTerjual) {
                        maxTerjual = terjual[i];
                        idxTerlaris = i;
                    }

                    if (stok[i] < minStok) {
                        minStok = stok[i];
                        idxStokMin = i;
                    }
                }

                cout << "========================================\n";
                cout << "           LAPORAN PENJUALAN            \n";
                cout << "========================================\n";
                cout << "Jumlah jenis barang : " << jumlahBarang << "\n";
                cout << "Total barang terjual: " << totalUnitTerjual << "\n";
                cout << "Total pendapatan    : Rp" << totalPendapatan << "\n\n";
                cout << "Barang terlaris:\n";
                cout << namaBarang[idxTerlaris] << " - " << terjual[idxTerlaris] << " pcs\n\n";
                cout << "Stok menipis:\n";
                cout << namaBarang[idxStokMin] << " - " << stok[idxStokMin] << " pcs\n";
                cout << "========================================\n";
                break;
            }
            case 5: {
                cin.ignore();
                string kataKunci;
                cout << "Masukkan nama barang yang dicari: ";
                getline(cin, kataKunci);

                bool ditemukan = false;
                for (int i = 0; i < jumlahBarang; i++) {
                    if (namaBarang[i] == kataKunci) {
                        cout << "\nBarang ditemukan!\n";
                        cout << "Nama    : " << namaBarang[i] << "\n";
                        cout << "Harga   : Rp" << harga[i] << "\n";
                        cout << "Stok    : " << stok[i] << "\n";
                        cout << "Terjual : " << terjual[i] << " pcs\n";
                        ditemukan = true;
                        break;
                    }
                }

                if (!ditemukan) {
                    cout << "Barang tidak ditemukan.\n";
                }
                break;
            }
            case 6:
                cout << "Keluar dari program. Terima kasih!\n";
                break;
            default:
                cout << "Pilihan menu tidak tersedia!\n";
                break;
        }
        cout << "\n";
    } while (pilihanMenu != 6);

    return 0;
}
