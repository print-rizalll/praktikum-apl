#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Spesifikasi {
    int    kapasitas_penumpang;
    string kelas_penerbangan;
};

struct Pesawat {
    int         id;
    string      kode_pesawat;
    string      nama_maskapai;
    string      model;
    string      status;
    string      tahun_produksi;
    Spesifikasi spek;
};

struct Pengguna {
    string nama;
    string password;
    bool   aktif;
};

void tampilBanner(Pengguna *pUser) {
    cout << "\n";
    cout << "  +=================================================+\n";
    cout << "  |    >>>  MANAJEMEN ARMADA PESAWAT  <<<           |\n";
    cout << "  |      Sistem Informasi Pengelolaan Pesawat       |\n";
    cout << "  +=================================================+\n";
    if (pUser != nullptr && (*pUser).aktif)
        cout << "  | Login sebagai : " << left << setw(33) << (*pUser).nama << "|\n"
            << "  +=================================================+\n";
    cout << "\n";
}

void tampilTabelPesawat(Pesawat daftarPesawat[], int jumlahPesawat) {
    cout << "\n+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    cout << "| " << left
        << setw(3)  << "ID"       << " | " << setw(8)  << "Kode"     << " | "
        << setw(18) << "Maskapai" << " | " << setw(16) << "Model"    << " | "
        << setw(12) << "Status"   << " | " << setw(6)  << "Tahun"    << " | "
        << setw(10) << "Kap."     << " | " << setw(24) << "Kelas"    << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    for (int i = 0; i < jumlahPesawat; i++)
        cout << "| " << left
            << setw(3)  << daftarPesawat[i].id                       << " | "
            << setw(8)  << daftarPesawat[i].kode_pesawat             << " | "
            << setw(18) << daftarPesawat[i].nama_maskapai            << " | "
            << setw(16) << daftarPesawat[i].model                    << " | "
            << setw(12) << daftarPesawat[i].status                   << " | "
            << setw(6)  << daftarPesawat[i].tahun_produksi           << " | "
            << setw(10) << daftarPesawat[i].spek.kapasitas_penumpang << " | "
            << setw(24) << daftarPesawat[i].spek.kelas_penerbangan   << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+"
        << string(18,'-') << "+" << string(14,'-') << "+" << string(8,'-') << "+"
        << string(12,'-') << "+" << string(26,'-') << "+\n";
    cout << "  Total: " << jumlahPesawat << " pesawat\n";
}

void tampilTabelPesawat(Pesawat daftarPesawat[], int jumlahPesawat, bool ringkas) {
    cout << "\n+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+" << string(18,'-') << "+" << string(14,'-') << "+\n";
    cout << "| " << left << setw(3) << "ID" << " | " << setw(8) << "Kode" << " | "
        << setw(18) << "Maskapai" << " | " << setw(16) << "Model" << " | " << setw(12) << "Status" << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+" << string(18,'-') << "+" << string(14,'-') << "+\n";
    for (int i = 0; i < jumlahPesawat; i++)
        cout << "| " << left << setw(3) << daftarPesawat[i].id << " | " << setw(8) << daftarPesawat[i].kode_pesawat
            << " | " << setw(18) << daftarPesawat[i].nama_maskapai << " | " << setw(16) << daftarPesawat[i].model
            << " | " << setw(12) << daftarPesawat[i].status << " |\n";
    cout << "+" << string(5,'-') << "+" << string(10,'-') << "+" << string(20,'-') << "+" << string(18,'-') << "+" << string(14,'-') << "+\n";
}

bool statusValid(string *status) {
    if (*status == "Aktif" || *status == "Perawatan" || *status == "Tidak Aktif")
        return true;
    return false;
}

int cariIndexPesawat(Pesawat daftarPesawat[], int jumlahPesawat, int &idCari) {
    for (int i = 0; i < jumlahPesawat; i++)
        if (daftarPesawat[i].id == idCari) return i;
    return -1;
}

int totalKapasitas(Pesawat daftarPesawat[], int index, int jumlahPesawat) {
    if (index >= jumlahPesawat) return 0;
    return daftarPesawat[index].spek.kapasitas_penumpang
        + totalKapasitas(daftarPesawat, index + 1, jumlahPesawat);
}

bool registerUser(Pengguna daftarUser[], int &jumlahUser, int MAX_USER) {
    if (jumlahUser >= MAX_USER) {
        cout << "\n  [!] Kapasitas user penuh!\n";
        return false;
    }
    string regNama, regPass;
    cout << "\n  +----------------------------------+\n";
    cout << "  |      REGISTER AKUN BARU         |\n";
    cout << "  +----------------------------------+\n";
    cout << "  Nama     : "; getline(cin, regNama);
    cout << "  Password : "; getline(cin, regPass);

    if (regNama.empty() || regPass.empty()) {
        cout << "\n  [!] Nama dan Password tidak boleh kosong!\n";
        return false;
    }
    for (int i = 0; i < jumlahUser; i++) {
        if (daftarUser[i].nama == regNama) {
            cout << "\n  [!] Username sudah terdaftar!\n";
            return false;
        }
    }
    daftarUser[jumlahUser++] = {regNama, regPass, true};
    cout << "\n  [OK] Registrasi berhasil! Silakan login.\n";
    return true;
}

Pengguna* loginUser(Pengguna daftarUser[], int &jumlahUser) {
    int  percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < 3 && !loginBerhasil) {
        string inputNama, inputPass;
        cout << "\n  +----------------------------------+\n";
        cout << "  |    LOGIN  (" << (percobaan+1) << " / 3)             |\n";
        cout << "  +----------------------------------+\n";
        cout << "  Username : "; getline(cin, inputNama);
        cout << "  Password : "; getline(cin, inputPass);

        for (int i = 0; i < jumlahUser; i++) {
            if (daftarUser[i].nama     == inputNama &&
                daftarUser[i].password == inputPass  &&
                daftarUser[i].aktif) {
                loginBerhasil = true;

                return &daftarUser[i];
            }
        }

        if (!loginBerhasil) {
            percobaan++;
            if (percobaan < 3)
                cout << "\n  [X] Salah! Sisa percobaan: " << (3 - percobaan) << "\n";
            else {
                cout << "\n  +===========================================+\n";
                cout << "  |  [!!] Login gagal 3x. Program berhenti.  |\n";
                cout << "  +===========================================+\n\n";
                exit(0);
            }
        }
    }
    return nullptr;
}

void tambahPesawat(Pesawat daftarPesawat[], int &jumlahPesawat, int &idCounter, int MAX_PESAWAT) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       TAMBAH DATA PESAWAT                |\n";
    cout << "  +------------------------------------------+\n";

    if (jumlahPesawat >= MAX_PESAWAT) { cout << "  [!] Data penuh!\n"; return; }

    Pesawat baru;
    baru.id = idCounter++;

    cout << "  Kode Pesawat                         : "; getline(cin, baru.kode_pesawat);
    cout << "  Nama Maskapai                        : "; getline(cin, baru.nama_maskapai);
    cout << "  Model Pesawat                        : "; getline(cin, baru.model);

    while (true) {
        cout << "  Status (Aktif/Perawatan/Tidak Aktif) : "; getline(cin, baru.status);
        string *pStatus = &baru.status;
        if (statusValid(pStatus)) break;
        else cout << "  [!] Status tidak valid! Pilihan: Aktif, Perawatan, Tidak Aktif\n";
    }

    cout << "  Tahun Produksi                       : "; getline(cin, baru.tahun_produksi);
    cout << "  Kapasitas Penumpang                  : "; cin >> baru.spek.kapasitas_penumpang; cin.ignore();
    cout << "  Kelas Penerbangan                    : "; getline(cin, baru.spek.kelas_penerbangan);

    daftarPesawat[jumlahPesawat++] = baru;
    cout << "\n  [OK] Pesawat ditambahkan! (ID: " << baru.id << ")\n";
    cout << "  Total kapasitas armada kini: "
        << totalKapasitas(daftarPesawat, 0, jumlahPesawat) << " penumpang\n";
}

void lihatPesawat(Pesawat daftarPesawat[], int jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       DAFTAR ARMADA PESAWAT              |\n";
    cout << "  +------------------------------------------+\n";
    if (jumlahPesawat == 0) { cout << "  [!] Belum ada data pesawat.\n"; return; }
    tampilTabelPesawat(daftarPesawat, jumlahPesawat);
    cout << "  Total kapasitas seluruh armada: "
        << totalKapasitas(daftarPesawat, 0, jumlahPesawat) << " penumpang\n";
}

void ubahPesawat(Pesawat daftarPesawat[], int jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       UBAH DATA PESAWAT                  |\n";
    cout << "  +------------------------------------------+\n";
    if (jumlahPesawat == 0) { cout << "  [!] Belum ada data pesawat.\n"; return; }

    tampilTabelPesawat(daftarPesawat, jumlahPesawat, true);

    int idCari;
    cout << "\n  ID yang akan diubah: "; cin >> idCari; cin.ignore();

    int idx = cariIndexPesawat(daftarPesawat, jumlahPesawat, idCari);
    if (idx == -1) { cout << "\n  [!] ID tidak ditemukan.\n"; return; }

    Pesawat *pPesawat = &daftarPesawat[idx];

    cout << "\n  Masukkan data baru (Enter = lewati):\n\n";
    string inp;

    cout << "  Kode Pesawat [" << pPesawat->kode_pesawat << "]: ";
    getline(cin, inp); if (!inp.empty()) pPesawat->kode_pesawat = inp;

    cout << "  Nama Maskapai [" << pPesawat->nama_maskapai << "]: ";
    getline(cin, inp); if (!inp.empty()) pPesawat->nama_maskapai = inp;

    cout << "  Model [" << pPesawat->model << "]: ";
    getline(cin, inp); if (!inp.empty()) pPesawat->model = inp;

    while (true) {
        cout << "  Status [" << pPesawat->status << "] (Aktif/Perawatan/Tidak Aktif, Enter=lewati): ";
        getline(cin, inp);
        if (inp.empty()) break;
        string *pStatus = &inp;
        if (statusValid(pStatus)) { pPesawat->status = inp; break; }
        else cout << "  [!] Status tidak valid! Pilihan: Aktif, Perawatan, Tidak Aktif\n";
    }

    cout << "  Tahun Produksi [" << pPesawat->tahun_produksi << "]: ";
    getline(cin, inp); if (!inp.empty()) pPesawat->tahun_produksi = inp;

    cout << "  Kapasitas Penumpang [" << pPesawat->spek.kapasitas_penumpang << "]: ";
    getline(cin, inp); if (!inp.empty()) pPesawat->spek.kapasitas_penumpang = stoi(inp);

    cout << "  Kelas Penerbangan [" << pPesawat->spek.kelas_penerbangan << "]: ";
    getline(cin, inp); if (!inp.empty()) pPesawat->spek.kelas_penerbangan = inp;

    cout << "\n  [OK] Data ID " << idCari << " berhasil diperbarui.\n";
}

void hapusPesawat(Pesawat daftarPesawat[], int &jumlahPesawat) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       HAPUS DATA PESAWAT                 |\n";
    cout << "  +------------------------------------------+\n";
    if (jumlahPesawat == 0) { cout << "  [!] Belum ada data pesawat.\n"; return; }

    tampilTabelPesawat(daftarPesawat, jumlahPesawat, true);

    int idCari;
    cout << "\n  ID yang akan dihapus: "; cin >> idCari; cin.ignore();

    int idx = cariIndexPesawat(daftarPesawat, jumlahPesawat, idCari);
    if (idx == -1) { cout << "\n  [!] ID tidak ditemukan.\n"; return; }

    Pesawat *pPesawat = &daftarPesawat[idx];
    cout << "\n  Akan dihapus: [" << pPesawat->kode_pesawat
        << "] " << pPesawat->nama_maskapai
        << " - "  << pPesawat->model << "\n";

    string kf;
    cout << "  Yakin hapus? (y/n): "; getline(cin, kf);
    if (kf == "y" || kf == "Y") {
        for (int i = idx; i < jumlahPesawat - 1; i++)
            daftarPesawat[i] = daftarPesawat[i + 1];
        jumlahPesawat--;
        cout << "\n  [OK] Data ID " << idCari << " berhasil dihapus.\n";
    } else {
        cout << "\n  [i] Penghapusan dibatalkan.\n";
    }
}

void lihatUser(Pengguna daftarUser[], int *jumlahUser) {
    cout << "\n  +------------------------------------------+\n";
    cout << "  |       DAFTAR PENGGUNA TERDAFTAR          |\n";
    cout << "  +------------------------------------------+\n";
    cout << "\n+" << string(5,'-') << "+" << string(25,'-') << "+" << string(20,'-') << "+\n";
    cout << "| " << left << setw(3) << "No" << " | " << setw(23) << "Nama" << " | " << setw(18) << "Password" << " |\n";
    cout << "+" << string(5,'-') << "+" << string(25,'-') << "+" << string(20,'-') << "+\n";
    for (int i = 0; i < *jumlahUser; i++)
        cout << "| " << left << setw(3) << (i+1) << " | " << setw(23) << daftarUser[i].nama
            << " | " << setw(18) << daftarUser[i].password << " |\n";
    cout << "+" << string(5,'-') << "+" << string(25,'-') << "+" << string(20,'-') << "+\n";
    cout << "  Total: " << *jumlahUser << " pengguna\n";
}

int main() {

    const int MAX_PESAWAT = 100;
    const int MAX_USER    = 50;

    Pesawat  daftarPesawat[MAX_PESAWAT];
    Pengguna daftarUser[MAX_USER];

    int jumlahPesawat = 0;
    int jumlahUser    = 0;
    int idCounter     = 1;

    daftarUser[0] = {"rizal", "071", true};
    jumlahUser = 1;

    daftarPesawat[0] = {idCounter++, "GA-001", "Garuda Indonesia", "Boeing 737-800",   "Aktif",       "2015", {162, "Ekonomi & Bisnis"}};
    daftarPesawat[1] = {idCounter++, "JT-045", "Lion Air",         "Boeing 737 MAX 8", "Aktif",       "2019", {210, "Ekonomi"}};
    daftarPesawat[2] = {idCounter++, "QZ-102", "AirAsia",          "Airbus A320neo",   "Perawatan",   "2018", {186, "Ekonomi"}};
    daftarPesawat[3] = {idCounter++, "SJ-088", "Sriwijaya Air",    "Boeing 737-500",   "Tidak Aktif", "2005", {120, "Ekonomi"}};
    daftarPesawat[4] = {idCounter++, "ID-201", "Batik Air",        "Airbus A330-300",  "Aktif",       "2020", {440, "Ekonomi & Bisnis & First"}};
    jumlahPesawat = 5;

    Pengguna *userLogin = nullptr;

    bool programBerjalan = true;

    while (programBerjalan) {

        userLogin = nullptr;

        bool sudahLogin = false;
        while (!sudahLogin) {
            Pengguna kosong = {"", "", false};
            tampilBanner(&kosong);

            cout << "  +-----------------------------+\n";
            cout << "  |        MENU AWAL            |\n";
            cout << "  |  1. Login                   |\n";
            cout << "  |  2. Register Akun Baru      |\n";
            cout << "  |  0. Keluar Program          |\n";
            cout << "  +-----------------------------+\n";
            cout << "  Pilihan: ";

            int pilihanAwal;
            cin >> pilihanAwal; cin.ignore();

            if (pilihanAwal == 1) {
                userLogin = loginUser(daftarUser, jumlahUser);
                if (userLogin != nullptr) {
                    cout << "\n  [OK] Login berhasil! Selamat datang, "
                        << userLogin->nama << "\n";
                    cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
                    sudahLogin = true;
                }
            } else if (pilihanAwal == 2) {
                registerUser(daftarUser, jumlahUser, MAX_USER);
                cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
            } else if (pilihanAwal == 0) {
                cout << "\n  Sampai jumpa!\n\n";
                return 0;
            } else {
                cout << "\n  [!] Pilihan tidak valid.\n";
                cout << "  Tekan Enter untuk melanjutkan..."; cin.get();
            }
        }

        bool jalan  = true;
        int  pilihan = 0;

        while (jalan) {
            tampilBanner(userLogin);

            cout << "  +------------------------------------------+\n";
            cout << "  |            MENU UTAMA                    |\n";
            cout << "  +------------------------------------------+\n";
            cout << "  |  1. Tambah Data Pesawat   (Create)       |\n";
            cout << "  |  2. Lihat Semua Pesawat   (Read)         |\n";
            cout << "  |  3. Ubah Data Pesawat     (Update)       |\n";
            cout << "  |  4. Hapus Data Pesawat    (Delete)       |\n";
            cout << "  |  5. Lihat Daftar User                    |\n";
            cout << "  |  0. Logout                               |\n";
            cout << "  +------------------------------------------+\n";
            cout << "  Pilihan: ";
            cin >> pilihan; cin.ignore();

            if      (pilihan == 1) { tambahPesawat(daftarPesawat, jumlahPesawat, idCounter, MAX_PESAWAT); }
            else if (pilihan == 2) { lihatPesawat(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 3) { ubahPesawat(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 4) { hapusPesawat(daftarPesawat, jumlahPesawat); }
            else if (pilihan == 5) { lihatUser(daftarUser, &jumlahUser); }  // Address-of &
            else if (pilihan == 0) {
                cout << "\n  [OK] Logout berhasil. Kembali ke menu login...\n";
                userLogin = nullptr;
                jalan = false;
            } else {
                cout << "\n  [!] Pilihan tidak valid.\n";
            }

            if (pilihan != 0) {
                cout << "  Tekan Enter untuk kembali..."; cin.get();
            }
        }
    }
    return 0;
}