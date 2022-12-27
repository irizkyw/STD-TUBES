#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <conio.h>
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

static void mahasiswa() {
	system("cls");
	std::vector<std::string> mahasiswa = {
		{"Ichwan Rizky Wahyudin - 1301213434"}, {"Wahyu Nata Mahendra - 1301213101"}
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

// Armada
static void menu_armada() {
	system("cls");
	gotoxy(1, 1);
	puts("=================== PILIH MENU! ===================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 2 + i);
		std::cout << i + 1 << "> " << menu[i];
	}
	gotoxy(3, menu.size() + 2);
	std::cout << 9 << "> " << "Kembali Ke Kategori";
	gotoxy(3, menu.size() + 3);
	std::cout << 0 << "> " << "Exit";
	gotoxy(1, menu.size() + 4);
	puts("====================================================");
}
static void addArmada(adrArmada &armada) {
	adrArmada alloc;
	int total, done; int i = 1; bool dup = false;
	gotoxy(0, menu.size() + 5); 
	std::cout << "Masukan Jumlah Data : ";
	std::cin >> total;
	if (total >= 1) {
		for (i = 1; i <= total;) {
			system("cls");
			menu_armada();
			gotoxy(1, 12+i);
			if (dup) std::cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << std::endl;
			else std::cout << "================ MASUKAN DATA KE-" << i <<" ================" << std::endl;
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
			std::cout << "Jadwal Berangkat[tgl bulan tahun] : ";
			std::cin >> data.tanggal; std::cin >> data.bulan; std::cin >> data.tahun;
			data.jadwal = std::to_string(data.tanggal) + "/" + std::to_string(data.bulan) + "/" + std::to_string(data.tahun);
			std::cout << "Waktu Berangkat : ";
			std::cin >> data.waktu;
			std::cout << "Kapasitas Maksimal(KG) : ";
			std::cin >> data.max_capacity;
			data.capacity = 0;
			if (findArmadaByID(armada, data) == NULL) { //datanya udah ada ato belum
				++i;
				insertLast(armada, allocArmada(data));
				dup = false;
			}
			else {
				dup = true;
			}
		}
	} else puts("Total yang kamu masukan kurang dari 1");
}
static void deleteById(adrArmada& armada) {
	Armada data; int pause = 0;
	showAllArmada(armada,false,false);
	if (armada != NULL) {
		std::cout << "\nHapus data dengan Kode :";
		std::cin >> data.id;
		adrArmada del, searchArmada;
		searchArmada = findArmadaByID(armada, data);
		if (searchArmada != NULL) {
			deleteAfter(armada, searchArmada, del);
			if (del != NULL) std::cout << "Data Berhasil di hapus dengan ID : " << del->info.id << std::endl;
		}
		else std::cout << "Data tidak ditemukan dengan ID : " << data.id << std::endl;
	}
}
static void findAndShow(adrArmada Larmada) {
	adrArmada current,search;
	adrCargo child;
	Armada data;
	int select_find = 0;
	std::cout << " [1]Search info Kode; [2]Search nama; [3]Search info range jadwal; [4] Search info tujuan;" << std::endl;
	std::cout << "Search dengan: ";
	std::cin >> select_find;
	switch (select_find) {
	case 1:
		showAllArmada(Larmada,false,false);
		if (Larmada != NULL) {
			std::cout << " Search Kode : ";
			std::cin >> data.id;
			search = findArmadaByID(Larmada, data);
			if (search != NULL) {
				std::cout << "================== Search Armada ==================" << std::endl << std::endl;
				std::cout << " >\tKode Armada\t: " << search->info.id << std::endl;
				std::cout << " \tNama Armada\t: " << search->info.nama_armada << std::endl;
				std::cout << " \tJenis Armada\t: " << search->info.jenis_armada << std::endl;
				std::cout << " \tArmada Asal\t: " << search->info.asal << std::endl;
				std::cout << " \tArmada Tujuan\t: " << search->info.tujuan << std::endl;
				std::cout << " \tJadwal Berangkat: " << search->info.jadwal << std::endl;
				std::cout << " \tWaktu Berangkat\t: " << search->info.waktu << std::endl << std::endl;
				std::cout << " \tKapasitas\t: " << search->info.capacity << " / " << search->info.max_capacity << " KG" << std::endl;
				std::cout << " *\tList Barang dari Cargo :" << std::endl;
				showAllCargo(search->cargo);
				std::cout << std:: endl;
				std::cout << "==================== EndSearch ====================" << std::endl;
			}
			else std::cout << data.id << " Tidak ditemukan!!" << std::endl;
		}
		break;
	case 2:
		showAllArmada(Larmada,false,false);
		if (Larmada != NULL) {
			std::cout << " Search nama kendaraan : ";
			std::cin >> data.nama_armada;
			current = Larmada;
			std::cout << "================== Search Armada ==================" << std::endl << std::endl;
			while (current != NULL) {
				if (current->info.nama_armada == data.nama_armada) {
					std::cout << " >\tKode Armada\t: " << current->info.id << std::endl;
					std::cout << " \tNama Armada\t: " << current->info.nama_armada << std::endl;
					std::cout << " \tJenis Armada\t: " << current->info.jenis_armada << std::endl;
					std::cout << " \tArmada Asal\t: " << current->info.asal << std::endl;
					std::cout << " \tArmada Tujuan\t: " << current->info.tujuan << std::endl;
					std::cout << " \tJadwal Berangkat: " << current->info.jadwal << std::endl;
					std::cout << " \tWaktu Berangkat\t: " << current->info.waktu << std::endl << std::endl;
					std::cout << " \tKapasitas\t: " << current->info.capacity << " / " << current->info.max_capacity << " KG" << std::endl;
					showAllCargo(current->cargo);
				}
				current = current->next;
			}
			std::cout << "==================== EndSearch ====================" << std::endl;
		}
		break;
	case 3:
		showAllArmada(Larmada,false,false);
		if (Larmada != NULL) {
			std::cout << " Search Start Jadwal[tgl bln thn] : ";
			int start_tgl,start_bln, start_thn, end_tgl, end_bln, end_thn;
			std::cin >> start_tgl; std::cin >> start_bln; std::cin >> start_thn;
			std::cout << " Search End Jadwal[tgl bln thn] : ";
			std::cin >> end_tgl; std::cin >> end_bln; std::cin >> end_thn;
			current = Larmada;
			std::cout << "================== Search Armada ==================" << std::endl << std::endl;
			while (current != NULL) {
				if (current->info.tanggal >= start_tgl && current->info.tanggal <= end_tgl) {
					if (current->info.bulan >= start_bln && current->info.bulan <= end_bln) {
						if (current->info.tahun >= start_thn && current->info.tahun <= end_thn) {
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
						}
					}
				}
				current = current->next;
			}
		}
		break;
	case 4:
		showAllArmada(Larmada, false,false);
		if (Larmada != NULL) {
			std::cout << " Search Tujuan : ";
			std::cin >> data.tujuan;
			current = Larmada;
			std::cout << "================== Search Armada ==================" << std::endl << std::endl;
			while (current != NULL) {
				if (current->info.tujuan == data.tujuan) {
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
				}
				current = current->next;
			}
		}
		break;
	}
}

// Cargo , Mahen
static void menu_cargo() {
	system("cls");
	std::vector<std::string> menu = {
		{"Tambah Cargo"}, {"Hapus Cargo By Kode"}, {"Cari Cargo dan Tampilkan Spesifikasi Barangnya"}
	};

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
static void deleteByIdChild(adrCargo& cargo) {
	Cargo newdata; int pause = 0;
	std::cout << "\nHapus data dengan Kode :";
	std::cin >> newdata.id_barang;
	adrCargo del, searchCargo;
	searchCargo = findChildByID(cargo, newdata);
	if (searchCargo != NULL) {
		deleteAfterChild(cargo, searchCargo, del);
		if (del != NULL) {
			std::cout << "Data Berhasil dihapus dengan ID : " << del->info.id_barang << std::endl;
		}
	}
	else {
		std::cout << "Data tidak ditemukan dengan ID : " << newdata.id_barang << std::endl;
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