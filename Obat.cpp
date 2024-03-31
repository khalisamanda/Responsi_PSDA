#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct Obat {
    string nama;
    string deskripsi;
    string penerbit;
    string kadaluarsa;
    string kegunaan;
};

vector<Obat> dataObat;

void tambahObat() {
    Obat obat;
    cout << "Nama Obat      : ";
    cin >> obat.nama;
    cout << "Deskripsi Obat : ";
    cin.ignore();
    getline(std::cin, obat.deskripsi);
    cout << "Pabrik         : ";
    cin >> obat.penerbit;
    cout << "Berlaku Hingga : ";
    cin >> obat.kadaluarsa;
    cout << "Kegunaan       : ";
    cin.ignore();
    getline(std::cin, obat.kegunaan);
    dataObat.push_back(obat);
    cout << "Obat berhasil ditambahkan.\n";
}

void cariObat(const string& kataKunci) {
    string kataKunciLower = kataKunci;
    transform(kataKunciLower.begin(), kataKunciLower.end(), kataKunciLower.begin(), ::tolower);

    for (const auto& obat : dataObat) {
        string namaObatLower = obat.nama;
        transform(namaObatLower.begin(), namaObatLower.end(), namaObatLower.begin(), ::tolower);
        
        string deskripsiObatLower = obat.deskripsi;
        transform(deskripsiObatLower.begin(), deskripsiObatLower.end(), deskripsiObatLower.begin(), ::tolower);
        
        if (namaObatLower.find(kataKunciLower) != string::npos || deskripsiObatLower.find(kataKunciLower) != string::npos) {
            cout << "Nama Obat      : " << obat.nama << endl;
            cout << "Deskripsi Obat : " << obat.deskripsi << endl;
            cout << "Pabrik         : " << obat.penerbit << endl;
            cout << "Berlaku Hingga : " << obat.kadaluarsa << endl;
            cout << "Kegunaan       : " << obat.kegunaan << endl;
        }
    }
}

void lihatObat() {
    cout << "Daftar Obat:\n";
    cout << "\n";
    for (const auto& obat : dataObat) {
        cout <<  obat.nama << endl;
    }
}

int main() {
    // Menambahkan daftar obat yang telah disediakan
    Obat parasetamol {"Parasetamol", "Merupakan obat untuk meredakan demam dan nyeri ringan hingga sedang seperti sakit kepala, sakit gigi, atau nyeri menstruasi.", "PT Parasetamol", "01/01/2025", "Meredakan demam dan nyeri\n"};
    Obat amoksisilin {"Amoksisilin", "Adalah antibiotik yang digunakan untuk mengobati infeksi bakteri, seperti infeksi saluran pernapasan, infeksi saluran kemih, dan infeksi kulit.", "PT Amoksisilin", "01/01/2025", "Mengobati infeksi bakteri\n"};
    Obat omeprazol {"Omeprazol", "Mengurangi produksi asam lambung dan digunakan untuk mengobati penyakit refluks gastroesofageal (GERD), tukak lambung, dan sindrom Zollinger-Ellison.", "PT Omeprazol", "01/01/2025", "Mengurangi produksi asam lambung\n"};
    Obat ibuprofen {"Ibuprofen", "Meredakan nyeri dan peradangan, serta menurunkan demam.", "PT Ibuprofen", "01/01/2025", "Meredakan nyeri dan peradangan\n"};
    Obat metformin {"Metformin", "Digunakan untuk mengontrol kadar gula darah pada penderita diabetes tipe 2 dengan meningkatkan sensitivitas tubuh terhadap insulin.", "PT Metformin", "01/01/2025", "Mengontrol kadar gula darah\n"};
    Obat atorvastatin {"Atorvastatin", "Mengurangi kadar kolesterol total, LDL (kolesterol jahat), dan trigliserida dalam darah, serta meningkatkan kadar HDL (kolesterol baik).", "PT Atorvastatin", "01/01/2025", "Mengurangi kadar kolesterol\n"};
    Obat cetirizine {"Cetirizine", "Obat antihistamin yang digunakan untuk meredakan gejala alergi seperti bersin-bersin, hidung tersumbat, gatal-gatal, dan mata berair.", "PT Cetirizine", "01/01/2025", "Meredakan gejala alergi\n"};
    Obat salbutamol {"Salbutamol", "Bronkodilator yang digunakan untuk meredakan gejala asma, bronkitis, dan penyakit paru obstruktif kronis (PPOK) dengan melebarkan saluran udara.", "PT Salbutamol", "01/01/2025", "Meredakan gejala asma\n"};
    Obat loratadin {"Loratadin", "Obat antihistamin yang digunakan untuk meredakan gejala alergi seperti bersin-bersin, hidung tersumbat, gatal-gatal, dan mata berair.", "PT Loratadin", "01/01/2025", "Meredakan gejala alergi\n"};
    Obat aspirin {"Aspirin", "Meredakan nyeri ringan hingga sedang, menurunkan demam, dan mengurangi pembekuan darah.", "PT Aspirin", "01/01/2025", "Meredakan nyeri dan menurunkan demam\n"};
    
    dataObat.push_back(parasetamol);
    dataObat.push_back(amoksisilin);
    dataObat.push_back(omeprazol);
    dataObat.push_back(ibuprofen);
    dataObat.push_back(metformin);
    dataObat.push_back(atorvastatin);
    dataObat.push_back(cetirizine);
    dataObat.push_back(salbutamol);
    dataObat.push_back(loratadin);
    dataObat.push_back(aspirin);

    bool exit = false;
    while (!exit) {
        cout << "\n WELCOME TO DATABASE APOTEK MANDA ";
        cout << "\n";
        cout << "\nMenu:\n";
        cout << "\n";
        cout << "\n1. Tambah Obat\n";
        cout << "2. Cari Obat\n";
        cout << "3. Lihat Obat\n";
        cout << "4. Keluar\n";
        
        cout << "\n";
        cout << "\nPilih menu: ";
        int menu;
        std::cin >> menu;
        switch (menu) {
            case 1:
                tambahObat();
                break;
            case 2: {
                cin.ignore();
                cout << "Masukkan kata kunci: ";
                string kataKunci;
                getline(std::cin, kataKunci);
                cariObat(kataKunci);
                break;
            }
            case 3:
                lihatObat();
                break;
            case 4:
                exit = true;
                cout << "Terima kasih!\n";
                break;
            default:
                cout << "Menu tidak valid!\n";
        }
    }
    return 0;
}
