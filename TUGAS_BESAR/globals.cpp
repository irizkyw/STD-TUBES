#include "globals.h"

void mahasiswa() {
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
void category(int& select, bool& stat) {
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
void menu_armada() {
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

void addArmada(adrArmada& armada) {
	adrArmada alloc;
	int total, done; int i = 1; bool dup = false;
	gotoxy(0, menu.size() + 5);
	std::cout << "Masukan Jumlah Data : ";
	std::cin >> total;
	if (total >= 1) {
		for (i = 1; i <= total;) {
			system("cls");
			menu_armada();
			gotoxy(1, 12 + i);
			if (dup) std::cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << std::endl;
			else std::cout << "================ MASUKAN DATA KE-" << i << " ================" << std::endl;
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
	}
	else puts("Total yang kamu masukan kurang dari 1");
}
void deleteById(adrArmada& armada) {
	Armada data; int pause = 0;
	showAllArmada(armada, false, false);
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
void findAndShow(adrArmada Larmada) {
	adrArmada current, search;
	adrCargo child;
	Armada data;
	int select_find = 0;
	std::cout << " [1]Search info Kode; [2]Search nama; [3]Search info range jadwal; [4] Search info tujuan;" << std::endl;
	std::cout << "Search dengan: ";
	std::cin >> select_find;
	switch (select_find) {
	case 1:
		showAllArmada(Larmada, false, false);
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
				std::cout << std::endl;
				std::cout << "==================== EndSearch ====================" << std::endl;
			}
			else std::cout << data.id << " Tidak ditemukan!!" << std::endl;
		}
		break;
	case 2:
		showAllArmada(Larmada, false, false);
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
		showAllArmada(Larmada, false, false);
		if (Larmada != NULL) {
			std::cout << " Search Start Jadwal[tgl bln thn] : ";
			int start_tgl, start_bln, start_thn, end_tgl, end_bln, end_thn;
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
		showAllArmada(Larmada, false, false);
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
void menu_cargo() {
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
void addCargo(adrCargo& cargo, adrArmada armada) {
	adrCargo child;
	adrArmada searchAramda; Armada dataA;
	int total, done; bool dup = false;
	gotoxy(0, 10);
	showAllArmada(armada, false, false);
	std::cout << " * kode -1 Untuk Kembali\n";
	std::cout << "Masukan Kode Armada : ";
	std::cin >> dataA.id;
	if (dataA.id == "-1")return;

	searchAramda = findArmadaByID(armada, dataA); //nyari parrent
	if (searchAramda != NULL) {
		std::cout << "Masukan Jumlah Data : ";
		std::cin >> total;
		if (total == -1) return;
		if (total >= 1) {
			for (int i = 1; i <= total;) {
				if (dup) std::cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << std::endl;
				else std::cout << "================ MASUKAN DATA KE-" << i << " ================" << std::endl;
				Cargo newdata;

				std::cout << "Kode Barang : ";
				std::cin >> newdata.id_barang;
				if (newdata.id_barang == "-1") return;
				std::cout << "Nama Barang : ";
				std::cin >> newdata.nama_barang;
				std::cout << "Volume Barang : ";
				std::cin >> newdata.volume_barang;

				if (findChildByID(searchAramda->cargo, newdata) == NULL) { // idnya ada yang sama atau tidak.

					if (searchAramda->info.capacity + newdata.volume_barang >= searchAramda->info.max_capacity)
						std::cout << "Volume barang melebihi kapasitas!!" << std::endl;
					else {
						insertLastChild(searchAramda->cargo, allocCargo(newdata));
						searchAramda->info.capacity += newdata.volume_barang;
						dup = false;
						++i;
					}
				}
				else dup = true;

			}
		}
		else puts("Total yang kamu masukan kurang dari 1");

	}
	else puts("Armada tidak di temukan");
}
void deleteByIdChild(adrArmada& armada) {
	Cargo newdata; int pause = 0;
	adrArmada current;
	if (armada != NULL) {
		current = armada;
		std::cout << "================== Search Cargo ==================" << std::endl << std::endl;
		while (current != NULL) {
			std::cout << " > Kode Armada : " << current->info.id << " [" << current->info.capacity << " / " << current->info.max_capacity << "]KG" << std::endl;
			if (current->cargo == NULL)
				std::cout << "\tList barang kosong !!" << std::endl;
			showAllCargo(current->cargo);
			current = current->next;
		}
		std::cout << "==================== EndSearch ====================" << std::endl;

		std::cout << " * -1 Untuk Kembali\n";
		std::cout << "\nHapus data dengan Kode :";
		std::cin >> newdata.id_barang;
		if (newdata.id_barang == "-1") return;

		adrCargo del = NULL; adrCargo searchCargo = NULL;
		current = armada;
		while (current != NULL) {
			searchCargo = findChildByID(current->cargo, newdata);
			if (searchCargo != NULL) {
				deleteAfterChild(current->cargo, searchCargo, del);
				if (del != NULL) {
					current->info.capacity -= del->info.volume_barang;
					std::cout << "Data Berhasil di hapus dengan kode barang " << del->info.id_barang << std::endl;
				}
			}
			current = current->next;
		}
		if (del == NULL) {
			std::cout << "Data tidak ditemukan dengan ID : " << newdata.id_barang << std::endl;
		}
	}
}

void findAndShowChild(adrCargo Lcargo, adrArmada Larmada) {
	adrArmada current, show_list;
	adrCargo list_barang, searchCargo, show_child;
	Cargo newdata;
	int select_find = 0;
	std::cout << " [1]Search info Kode; [2]Search nama;" << std::endl;
	std::cout << "Search dengan: ";
	std::cin >> select_find;

	switch (select_find) {
	case 1:
		if (Larmada != NULL) {
			std::cout << "=================== List Cargo! ===================" << std::endl << std::endl;
			show_list = Larmada;
			while (show_list != NULL) {
				show_child = show_list->cargo;
				std::cout << " > Kode Armada : " << show_list->info.id << " [" << show_list->info.capacity << " / "
					<< show_list->info.max_capacity << "]KG" << std::endl;
				while (show_child != NULL) {
					std::cout << "\tKode Barang : " << show_child->info.id_barang << std::endl;
					show_child = show_child->next;
				}
				show_list = show_list->next;
			}
			std::cout << "==================== End List! ====================" << std::endl;

			std::cout << " Search Kode : ";
			std::cin >> newdata.id_barang;

			current = Larmada;
			std::cout << "================== Search Cargo ==================" << std::endl << std::endl;
			while (current != NULL) {
				list_barang = current->cargo;
				if (list_barang != NULL) {
					searchCargo = findChildByID(list_barang, newdata);
					if (searchCargo != NULL) {
						std::cout << "\tKode Armada\t: " << current->info.id << std::endl;
						std::cout << "\tKode Barang\t: " << searchCargo->info.id_barang << std::endl;
						std::cout << "\tNama Barang\t: " << searchCargo->info.nama_barang << std::endl;
						std::cout << "\tBerat Barang\t: " << searchCargo->info.volume_barang << std::endl << std::endl;
					}
					else std::cout << newdata.id_barang << " Tidak ditemukan!!" << std::endl;
				}
				current = current->next;
			}
			std::cout << "==================== EndSearch ====================" << std::endl;

		}
		break;
	case 2:
		if (Larmada != NULL) {
			std::cout << "=================== List Cargo! ===================" << std::endl << std::endl;
			show_list = Larmada;
			while (show_list != NULL) {
				show_child = show_list->cargo;
				std::cout << " > Kode Armada : " << show_list->info.id << " [" << show_list->info.capacity << " / "
					<< show_list->info.max_capacity << "]KG" << std::endl;
				while (show_child != NULL) {
					std::cout << "\tNama Armada : " << show_child->info.nama_barang << std::endl;
					show_child = show_child->next;
				}
				show_list = show_list->next;
			}
			std::cout << "==================== End List! ====================" << std::endl;


			current = Larmada;
			std::cout << " Search Nama Barang : ";
			std::cin >> newdata.nama_barang;

			std::cout << "================== Search Cargo ==================" << std::endl << std::endl;
			while (current != NULL) {
				list_barang = current->cargo;
				std::cout << "\tKode Armada\t: " << current->info.id << std::endl;
				if (list_barang != NULL) {
					while (list_barang != NULL) {
						if (list_barang->info.nama_barang == newdata.nama_barang) {
							std::cout << "\tKode Barang\t: " << list_barang->info.id_barang << std::endl;
							std::cout << "\tNama Barang\t: " << list_barang->info.nama_barang << std::endl;
							std::cout << "\tBerat Barang\t: " << list_barang->info.volume_barang << std::endl << std::endl;
						}
						list_barang = list_barang->next;
					}
				}
				else std::cout << newdata.id_barang << "\tTidak ditemukan!!" << std::endl << std::endl;
				current = current->next;
			}
			std::cout << "==================== EndSearch ====================" << std::endl;
		}
		break;
	}
}

void dummy(adrArmada& Larmada) {
	Armada data;
	data.id = "A001"; data.nama_armada = "BINEKA"; data.jenis_armada = "Truck"; data.asal = "Jakarta"; data.tujuan = "Bandung"; data.tanggal = 1; data.bulan = 1; data.tahun = 2020; data.jadwal = "01/01/2020"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
	data.id = "A002"; data.nama_armada = "Armada2"; data.jenis_armada = "Truck"; data.asal = "Jakarta"; data.tujuan = "Bandung"; data.tanggal = 2; data.bulan = 1; data.tahun = 2020; data.jadwal = "02/01/2020"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
	data.id = "A003"; data.nama_armada = "Armada3"; data.jenis_armada = "Truck"; data.asal = "Jakarta"; data.tujuan = "Bandung"; data.tanggal = 3; data.bulan = 1; data.tahun = 2020; data.jadwal = "03/01/2020"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
}
