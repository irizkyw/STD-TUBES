#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
#include <sstream>
#include "parent.h"

static std::vector<std::string> menu = {
		{"Tambah Armada"}, {"Hapus Armada By Kode"}, {"Tampilkan semua Armada dan list barang dari cargo"}, {"Cari Aramada dan tampilkan list barang dari cargo"}, {"Tampilkan Armada dengan barang paling banyak & paling sedikit"}
};
static void color(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

static void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void mahasiswa();
void category(int& select, bool& stat);

// Armada
void menu_armada();
void addArmada(adrArmada& armada);
void deleteById(adrArmada& armada);
void findAndShow(adrArmada Larmada);

// Cargo , Mahen
void menu_cargo();
void addCargo(adrCargo& cargo, adrArmada armada);
void deleteByIdChild(adrArmada& armada);
void findAndShowChild(adrCargo Lcargo, adrArmada Larmada);

<<<<<<< HEAD
void dummy(adrArmada& Larmada);
=======
	gotoxy(1, 1);
	puts("=================== PILIH MENU! ===================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 2 + i);
		std::cout << i + 1 << "> " << menu[i];
	}
	gotoxy(3, 7);
	std::cout << 9 << "> " << "Kembali Ke Kategori";
	gotoxy(3, 8);
	std::cout << 0 << "> " << "Exit";
	gotoxy(1, 9);
	puts("====================================================");
}
static void addCargo(adrCargo& cargo, adrArmada armada) {
	adrCargo child;
	adrArmada searchAramda; Armada dataA;
	int total, done; int i = 1; bool dup = false;
	gotoxy(0, 10);
	showAllArmada(armada, false, false);

	std::cout << "Masukan Kode Armada : ";
	std::cin >> dataA.id;

	searchAramda = findArmadaByID(armada, dataA); //nyari parrent
	if (searchAramda != NULL) {
		std::cout << "Masukan Jumlah Data : ";
		std::cin >> total;

		if (total >= 1) {
			for (i = 1; i <= total;) {
				if (dup) std::cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << std::endl;
				else std::cout << "================ MASUKAN DATA KE-" << i << " ================" << std::endl;
				Cargo newdata;

				std::cout << "Kode Barang : ";
				std::cin >> newdata.id_barang;
				std::cout << "Nama Barang : ";
				std::cin >> newdata.nama_barang;
				std::cout << "Volume Barang : ";
				std::cin >> newdata.volume_barang;

				if (findChildByID(searchAramda->cargo, newdata) == NULL) { // idnya ada yang sama atau tidak.
					insertLastChild(searchAramda->cargo, allocCargo(newdata));
					searchAramda->info.capacity += newdata.volume_barang;
					dup = false;
					++i;
				}else dup = true;
				
			}
		}
		else puts("Total yang kamu masukan kurang dari 1");

	}else puts("Armada tidak di temukan");
}
static void deleteByIdChild(adrArmada armada,adrCargo& cargo) {
	adrArmada current, curr;
	Cargo data;
	int pause = 0;
	current = armada;
	curr = armada;
	if (armada != NULL) {
		while (current != NULL) {
			std::cout << " >\tKode Armada\t: " << current->info.id << std::endl;
			std::cout << " \tNama Armada\t: " << current->info.nama_armada << std::endl;
			std::cout << " \tJenis Armada\t: " << current->info.jenis_armada << std::endl;
			std::cout << " \tArmada Asal\t: " << current->info.asal << std::endl;
			std::cout << " \tArmada Tujuan\t: " << current->info.tujuan << std::endl;
			std::cout << " \tJadwal Berangkat: " << current->info.jadwal << std::endl;
			std::cout << " \tWaktu Berangkat\t: " << current->info.waktu << std::endl << std::endl;
			std::cout << " \tKapasitas\t: " << current->info.capacity << " / " << current->info.max_capacity << " KG" << std::endl;
			std::cout << " *\tList Barang dari Cargo :" << std::endl;
			showAllCargo(current->cargo);
			current = current->next;
		}
		while (curr != NULL) {
			curr->cargo;
			if (curr->cargo != NULL) {
				std::cout << "\nHapus Data dengan Kode : ";
				std::cin >> data.id_barang;
				adrCargo temp, del;
				temp = findChildByID(curr->cargo, data);
				if (temp != NULL) {
					deleteAfterChild(curr->cargo, temp, del);
					if (del != NULL) {
						std::cout << "Data Berhasil dihapus dengan ID : " << del->info.id_barang << std::endl;
					}
				}
				else std::cout << "Data tidak ditemukan dengan ID : " << data.id_barang << std::endl;
			}
			curr = curr->next;
		}
	}
}
static void findAndShowChild(adrCargo Lcargo, adrArmada Larmada) {
	adrArmada current;
	adrCargo list_barang, searchCargo;
	Cargo newdata;
	int select_find = 0;
	std::cout << " [1]Search info Kode; [2]Search nama;" << std::endl;
	std::cout << "Search dengan: ";
	std::cin >> select_find;
	switch (select_find) {
	case 1:
		showAllArmada(Larmada, false,true);
		if (Larmada != NULL) {
			current = Larmada;
			std::cout << " Search Kode : ";
			std::cin >> newdata.id_barang;
			while (current != NULL) {
				list_barang = current->cargo;
				if (list_barang != NULL) {
					searchCargo = findChildByID(Lcargo, newdata);
					if (searchCargo != NULL) {
						std::cout << "================== Search Cargo ==================" << std::endl << std::endl;
						std::cout << "\tKode Barang\t: " << searchCargo->info.id_barang << std::endl;
						std::cout << "\tNama Barang\t: " << searchCargo->info.nama_barang << std::endl;
						std::cout << "\tBerat Barang\t: " << searchCargo->info.volume_barang << std::endl;
						std::cout << "==================== EndSearch ====================" << std::endl;
					}
					else std::cout << newdata.id_barang << " Tidak ditemukan!!" << std::endl;
				}
				current = current->next;
			}
		}
		break;
	case 2:
		showAllArmada(Larmada, false,true);
		if (Larmada != NULL) {
			current = Larmada;
			std::cout << " Search Nama Barang : ";
			std::cin >> newdata.nama_barang;
			while (current != NULL) {
				list_barang = current->cargo;
				while (list_barang != NULL) {
					searchCargo = findChildByID(Lcargo, newdata);
					if (list_barang->info.nama_barang == newdata.nama_barang) {
						std::cout << "================== Search Cargo ==================" << std::endl << std::endl;
						std::cout << "\tKode Barang\t: " << searchCargo->info.id_barang << std::endl;
						std::cout << "\tNama Barang\t: " << searchCargo->info.nama_barang << std::endl;
						std::cout << "\tBerat Barang\t: " << searchCargo->info.volume_barang << std::endl;
						std::cout << "==================== EndSearch ====================" << std::endl;
					}
					else {
						std::cout << newdata.id_barang << " Tidak ditemukan!!" << std::endl;
					}
					list_barang = list_barang->next;
				}
				current = current->next;
			}
		}
		break;
	}
}

static void dummy(adrArmada& Larmada) {
	Armada data;
	data.id = "A001"; data.nama_armada = "Armada1"; data.jenis_armada = "Truck"; data.asal = "Jakarta"; data.tujuan = "Bandung"; data.tanggal = 1; data.bulan = 1; data.tahun = 2020; data.jadwal = "01/01/2020"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
	data.id = "A002"; data.nama_armada = "Armada2"; data.jenis_armada = "Truck"; data.asal = "Jakarta"; data.tujuan = "Bandung"; data.tanggal = 2; data.bulan = 1; data.tahun = 2020; data.jadwal = "02/01/2020"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
	data.id = "A003"; data.nama_armada = "Armada3"; data.jenis_armada = "Truck"; data.asal = "Jakarta"; data.tujuan = "Bandung"; data.tanggal = 3; data.bulan = 1; data.tahun = 2020; data.jadwal = "03/01/2020"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
}
>>>>>>> 89dfd5ab2d3f4ab4bf378521324ce8ac0dcd5d98
