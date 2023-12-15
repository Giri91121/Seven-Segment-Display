#include <iostream>
#include <vector>


using namespace std;

// Fungsi untuk mengubah bilangan biner ke decimal
int binaryToDecimal(int n) // int n digunakan untuk menyimpan input biner
{ 
	int num = n;  // variabel n dimasukkan ke variabel num
	int dec_value = 0;  // dec_value akan menyimpan hasil konversi
	int base = 1; // sebagai pangkat dari bilangan biner

	int temp = num; // menginisialisasikan  temp sama dengan num

	while (temp) {  // akan melakukan loop selama temp tidak bernilai 0
		int last_digit = temp % 10; // mengambil digit terakhir dari bilangan biner
		temp = temp / 10;  // mengurangi bilangan biner untuk setiap iterasi
		dec_value += last_digit * base;  // menambahkan nilai desimal dengan digit terakhir yang dikalikan dengan pangkat dari 2
		base = base * 2; // meningkatkan pangkat 2 untuk setiap iterasi agar sesuai dengan posisi digit biner yang diambil
	} 

	return dec_value;  // mengembalikan nilai desimal yang dihasilkan dari konversi bilangan biner
} 

// Fungsi untuk menampilkan boolean tabel dan seven segment display
void display_Segment(vector<bool>& segments) {
    // Untuk menampilkan boolean tabel
    cout << "=============================\n";
    cout << "| A | B | C | D | E | F | G |\n";
    cout << "=============================\n";
    cout << "| " << (segments[0] ? "1" : "0") << " | " << (segments[1] ? "1" : "0") << " | " << (segments[2] ? "1" : "0") << " | " << (segments[3] ? "1" : "0") << " | " << (segments[4] ? "1" : "0") << " | " << (segments[5] ? "1" : "0") << " | " << (segments[6] ? "1" : "0") << " |" << endl;
    cout << "=============================\n";

    // Untuk menampilkan boolean seven segment display
    cout << " " << (segments[0] ? "__" : "  ") << endl;
    cout << (segments[5] ? "|" : " ") << (segments[6] ? "__" : "  ") << (segments[1] ? "|" : " ") << endl;
    cout << (segments[4] ? "|" : " ") << (segments[3] ? "__" : "  ") << (segments[2] ? "|" : " ") << endl;
    cout << endl;
}

// Fungsi untuk mengatur seven segmen sesuai dengan angka yang diinginkan(0-9)
void Segment_Number(vector<bool>& segments, int number) {
    // Mengatur segmen untuk angka tertentu
    switch(number) {
        case 0:
            segments = {true, true, true, true, true, true, false};
            break;
        case 1:
            segments = {false, true, true, false, false, false, false};
            break;
        case 2:
            segments = {true, true, false, true, true, false, true};
            break;
        case 3:
            segments = {true, true, true, true, false, false, true};
            break;
        case 4:
            segments = {false, true, true, false, false, true, true};
            break;
        case 5:
            segments = {true, false, true, true, false, true, true};
            break;
        case 6:
            segments = {true, false, true, true, true, true, true};
            break;
        case 7:
            segments = {true, true, true, false, false, false, false};
            break;
        case 8:
            segments = {true, true, true, true, true, true, true};
            break;
        case 9:
            segments = {true, true, true, true, false, true, true};
            break;
        default:
            break;
    }
}

int main() {
    vector<bool> segments(7, false); // Inisialisasi dengan 7 segmen, awalnya semuanya mati
    int number;

    cout << "\nMasukkan angka biner atau decimal (0-9): ";
    cin >> number;

    number = binaryToDecimal(number); // Mengatur bilangan biner sama dengan bilangan decimal

    // Mengatur jika input number lebih dari angka 9, maka angka tidak valid dan harus melakukan penginputan ulang 
    while(number >= 10 || number < 0){
        cout << "\nAngka tidak valid!\nMasukkan angka lain (0-9) : ";
        cin >> number;
    }

    Segment_Number(segments, number); // Mengatur segmen sesuai angka yang dimasukkan
    display_Segment(segments); // Menampilkan tabel dan seven segment display

    return 0;
}