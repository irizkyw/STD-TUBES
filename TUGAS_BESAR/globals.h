#include <iostream>
#include <Windows.h>
#include <vector>
#include <conio.h>
#include "parent.h"

static void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

static void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

static void mahasiswa() {
	system("cls");
	std::vector<std::string> mahasiswa = {
		{"Ichwan Rizky Wahyudin - 1301213434"}, {"Wahyu Nata Mahendra - 1301213434"}
	};

	gotoxy(30, 10);
	puts("===================================================");
	gotoxy(45, 8);
	puts("TUGAS BESAR STRUKTUR DATA");
	for (int i = 0; i < mahasiswa.size(); ++i) {
		gotoxy(38, 12 + i);
		std::cout << i + 1 << "> " << mahasiswa[i];
	}
	gotoxy(30, 15);
	puts("===================================================");
	gotoxy(45, 23);
	puts("PRESS ENTER UNTUK MASUK");
}

static void category(int &select, bool &stat) {
	system("cls");
	std::vector<std::string> menu = {
		{"Kelola Armada"}, {"Kelola Cargo"},
	};

	gotoxy(1, 1);
	puts("================= PILIH KATEGORI! =================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 2 + i);
		std::cout << i + 1 << "> " << menu[i];
	}
		gotoxy(3, 4);
	std::cout << 9 << "> " << "Kembali Ke Kategori";
		gotoxy(3, 5);
	std::cout << 0 << "> " << "Exit";
		gotoxy(1, 6);
	puts("====================================================");
	std::cout << "Select Menu : ";
	std::cin >> select;
	if (select == 1 || select == 2) stat = true;
}

static void menu_armada() {
	system("cls");
	std::vector<std::string> menu = {
		{"Tambah Armada"}, {"Hapus Armada"},
		{"Hapus Armada By Kode"}, {"Tampilkan Armada dengan list barang"}
	};

	gotoxy(1, 1);
	puts("=================== PILIH MENU! ===================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 2 + i);
		std::cout << i + 1 << "> " << menu[i];
	}
	gotoxy(3, 5);
	std::cout << 9 << "> " << "Kembali Ke Kategori";
	gotoxy(3, 6);
	std::cout << 0 << "> " << "Exit";
	gotoxy(1, 7);
	puts("====================================================");
}

static void addArmada(adrArmada &armada) {
	adrArmada alloc;
	int total, done; int i = 1; bool dup = false;
	gotoxy(0, 9); 
	std::cout << "Masukan Jumlah Data : ";
	std::cin >> total;
	if (total >= 1) {
		for (i = 1; i <= total; ++i) {
			system("cls");
			menu_armada();
			gotoxy(1, 11+i);
			if (dup) {
				std::cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << std::endl;
			}
			else
				std::cout << "================ MASUKAN DATA KE-" << i <<" ================" << std::endl;
			Armada data;
			std::cout << "Kode Armada : ";
			std::cin >> data.id;
			std::cout << "Nama Armada : ";
			std::cin >> data.nama_armada;
			std::cout << "Jenis Armada : ";
			std::cin >> data.jenis_armada;
			std::cout << "Armada Asal: ";
			std::cin >> data.asal;
			std::cout << "Armada Tujuan : ";
			std::cin >> data.tujuan;
			std::cout << "Tanggal Berangkat : ";
			std::cin >> data.tanggal;
			std::cout << "Waktu Berangkat : ";
			std::cin >> data.waktu;
			std::cout << "Kapasitas Maksimal(KG) : ";
			std::cin >> data.max_capacity;
			data.capacity = 0;
			if (findArmadaByID(armada, data) == NULL)
				insertLast(armada, allocArmada(data));
			else {
				total++;
				dup = true;
			}
		}
	} else puts("Total yang kamu masukan kurang dari 1");
}

static void deleteById(adrArmada& armada) {
	Armada data;
	showAllArmada(armada);
	if (armada != NULL) {
		std::cout << "\nHapus data dengan Kode :";
		std::cin >> data.id;
		adrArmada del;
		adrArmada searchArmada;
		searchArmada = findArmadaByID(armada, data);
		if (searchArmada != NULL) {
			deleteAfter(armada, searchArmada, del);
			if (del != NULL) std::cout << "Data Berhasil di hapus dengan ID : " << del->info.id << std::endl;
		}
		else std::cout << "Data tidak ditemukan dengan ID : " << data.id << std::endl;
	}
}