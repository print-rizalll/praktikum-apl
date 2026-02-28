#include <iostream>
#include <string>
using namespace std;

int main() {
    string nama, password;
    int percobaan = 0;

    cout << "==============================" << endl;
    cout << "   PROGRAM KONVERSI PANJANG   " << endl;
    cout << "==============================" << endl;

    while (percobaan < 3) {
        cout << "\nMasukkan Nama     : ";
        cin >> nama;
        cout << "Masukkan Password : ";
        cin >> password;

        if (password == "071" && nama == "rizal") {
            cout << "\nLogin berhasil! Selamat datang, " << nama << "!" << endl;
            break;
        } else {
            percobaan++;
            cout << "Password salah! Percobaan ke-" << percobaan << " dari 3." << endl;

            if (percobaan == 3) {
                cout << "\nAnda sudah salah 3 kali. Program berhenti." << endl;
                return 0;
            }
        }
    }

    int pilihan;

    do {
        cout << "\n==============================" << endl;
        cout << "         MENU UTAMA           " << endl;
        cout << "==============================" << endl;
        cout << "1. Meter ke Kilometer & Centimeter" << endl;
        cout << "2. Kilometer ke Meter & Centimeter" << endl;
        cout << "3. Centimeter ke Meter & Kilometer" << endl;
        cout << "0. Keluar" << endl;
        cout << "==============================" << endl;
        cout << "Pilih menu : ";
        cin >> pilihan;

        if (pilihan == 1) {
            double meter;
            cout << "\nMasukkan nilai dalam Meter : ";
            cin >> meter;

            double kilometer= meter / 1000;
            double centimeter = meter * 100;

            cout << "\n--- HASIL KONVERSI ---" << endl;
            cout << meter << " Meter = " << kilometer<< " Kilometer" << endl;
            cout << meter << " Meter = " << centimeter << " Centimeter" << endl;

        } else if (pilihan == 2) {
            double kilometer;
            cout << "\nMasukkan nilai dalam Kilometer : ";
            cin >> kilometer;

            double meter = kilometer* 1000;
            double centimeter    = kilometer* 100000;

            cout << "\n--- HASIL KONVERSI ---" << endl;
            cout << kilometer<< " Kilometer = " << meter << " Meter" << endl;
            cout << kilometer<< " Kilometer = " << centimeter    << " Centimeter" << endl;

        } else if (pilihan == 3) {
            double centimeter;
            cout << "\nMasukkan nilai dalam Centimeter : ";
            cin >> centimeter;

            double meter = centimeter / 100;
            double kilometer   = centimeter / 100000;

            cout << "\n--- HASIL KONVERSI ---" << endl;
            cout << centimeter << " Centimeter = " << meter << " Meter" << endl;
            cout << centimeter << " Centimeter = " << kilometer   << " Kilometer" << endl;

        } else if (pilihan == 0) {
            cout << "\nTerima kasih, " << nama << "! Program selesai." << endl;

        } else {
            cout << "\nPilihan tidak valid! Silakan pilih 0-3." << endl;
        }

    } while (pilihan != 0);

    return 0;
}