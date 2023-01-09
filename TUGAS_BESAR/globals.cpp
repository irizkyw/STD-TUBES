#include "globals.h"

using namespace std;

// Armada
void mahasiswa() {
	system("cls");
	vector<string> mahasiswa = {
		{"Ichwan Rizky Wahyudin - 1301213434"}, {"Wahyu Nata Mahendra - 1301213101"}
	};

	gotoxy(30, 10);
	puts("===================================================");
	gotoxy(45, 8);
	puts("TUGAS BESAR STRUKTUR DATA");
	for (int i = 0; i < mahasiswa.size(); ++i) {
		gotoxy(38, 12 + i);
		cout << i + 1 << "> " << mahasiswa[i];
	}
	gotoxy(30, 15);
	puts("===================================================");
	gotoxy(45, 23);
	puts("PRESS ENTER UNTUK MASUK");
}
void category(int& select, bool& stat) {
	system("cls");
	vector<string> menu = {
		{"Kelola Armada"}, {"Kelola Cargo"},
	};

	gotoxy(1, 1);
	puts("================= PILIH KATEGORI! =================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 2 + i);
		cout << i + 1 << "> " << menu[i];
	}
	gotoxy(3, 4);
	cout << 9 << "> " << "Kembali Ke Kategori";
	gotoxy(3, 5);
	cout << 0 << "> " << "Exit";
	gotoxy(1, 6);
	puts("====================================================");
	cout << "Select Menu : ";
	cin >> select;
	if (select == 1 || select == 2) stat = true;
}
void menu_armada() {
	system("cls");
	gotoxy(1, 1);
	puts("=================== PILIH MENU! ===================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 3 + i);
		cout << i + 1 << "> " << menu[i];
	}
	gotoxy(3, menu.size() + 4);
	cout << 9 << "> " << "Kembali Ke Kategori";
	gotoxy(3, menu.size() + 5);
	cout << 0 << "> " << "Exit";
	gotoxy(1, menu.size() + 6);
	puts("====================================================");
}
void addArmada(adrArmada& armada) {
	adrArmada alloc;
	int total, done; int i = 1; bool dup = false;
	gotoxy(0, menu.size() + 9);
	cout << "Masukan Jumlah Data : ";
	cin >> total;
	if (total >= 1) {
		for (i = 1; i <= total;) {
			system("cls");
			menu_armada();
			gotoxy(1, 12 + i);
			if (dup) cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << endl;
			else cout << "================ MASUKAN DATA KE-" << i << " ================" << endl;
			Armada data;
			cout << "Kode Armada : ";
			cin >> data.id;
			cout << "Nama Armada : ";
			cin >> data.nama_armada;
			cout << "Jenis Armada : ";
			cin >> data.jenis_armada;
			cout << "Armada Asal: ";
			cin >> data.asal;
			cout << "Armada Tujuan : ";
			cin >> data.tujuan;
			cout << "Jadwal Berangkat[tgl bulan tahun] : ";
			cin >> data.tanggal; cin >> data.bulan; cin >> data.tahun;
			data.jadwal = to_string(data.tanggal) + "/" + to_string(data.bulan) + "/" + to_string(data.tahun);
			cout << "Waktu Berangkat : ";
			cin >> data.waktu;
			cout << "Kapasitas Maksimal(KG) : ";
			cin >> data.max_capacity;
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
		cout << "\nHapus data dengan Kode :";
		cin >> data.id;
		adrArmada del, searchArmada;
		searchArmada = findArmadaByID(armada, data);
		if (searchArmada != NULL) {
			deleteAfter(armada, searchArmada, del);
			if (del != NULL) cout << "Data Berhasil di hapus dengan ID : " << del->info.id << endl;
		}
		else cout << "Data tidak ditemukan dengan ID : " << data.id << endl;
	}
}
void findAndShow(adrArmada Larmada) {
	adrArmada current, search;
	adrCargo child;
	Armada data;
	int select_find = 0;
	cout << " [1]Search info Kode; [2]Search nama; [3]Search info range jadwal; [4] Search info tujuan;" << endl;
	cout << "Search dengan: ";
	cin >> select_find;
	switch (select_find) {
	case 1:
		showAllArmada(Larmada, false, false);
		if (Larmada != NULL) {
			cout << " Search Kode : ";
			cin >> data.id;
			search = findArmadaByID(Larmada, data);
			if (search != NULL) {
				cout << "================== Search Armada ==================" << endl << endl;
				cout << " >\tKode Armada\t: " << search->info.id << endl;
				cout << " \tNama Armada\t: " << search->info.nama_armada << endl;
				cout << " \tJenis Armada\t: " << search->info.jenis_armada << endl;
				cout << " \tArmada Asal\t: " << search->info.asal << endl;
				cout << " \tArmada Tujuan\t: " << search->info.tujuan << endl;
				cout << " \tJadwal Berangkat: " << search->info.jadwal << endl;
				cout << " \tWaktu Berangkat\t: " << search->info.waktu << endl << endl;
				cout << " \tKapasitas\t: " << search->info.capacity << " / " << search->info.max_capacity << " KG" << endl;
				cout << " *\tList Barang dari Cargo :" << endl;
				showAllCargo(search->cargo);
				cout << endl;
				cout << "==================== EndSearch ====================" << endl;
			}
			else cout << data.id << " Tidak ditemukan!!" << endl;
		}
		break;
	case 2:
		showAllArmada(Larmada, false, false);
		if (Larmada != NULL) {
			cout << " Search nama kendaraan : ";
			cin >> data.nama_armada;
			current = Larmada;
			cout << "================== Search Armada ==================" << endl << endl;
			while (current != NULL) {
				if (current->info.nama_armada == data.nama_armada) {
					cout << " >\tKode Armada\t: " << current->info.id << endl;
					cout << " \tNama Armada\t: " << current->info.nama_armada << endl;
					cout << " \tJenis Armada\t: " << current->info.jenis_armada << endl;
					cout << " \tArmada Asal\t: " << current->info.asal << endl;
					cout << " \tArmada Tujuan\t: " << current->info.tujuan << endl;
					cout << " \tJadwal Berangkat: " << current->info.jadwal << endl;
					cout << " \tWaktu Berangkat\t: " << current->info.waktu << endl << endl;
					cout << " \tKapasitas\t: " << current->info.capacity << " / " << current->info.max_capacity << " KG" << endl;
					showAllCargo(current->cargo);
				}
				current = current->next;
			}
			cout << "==================== EndSearch ====================" << endl;
		}
		break;
	case 3:
		showAllArmada(Larmada, false, false);
		if (Larmada != NULL) {
			cout << " Search Start Jadwal[tgl bln thn] : ";
			int start_tgl, start_bln, start_thn, end_tgl, end_bln, end_thn;
			cin >> start_tgl; cin >> start_bln; cin >> start_thn;
			cout << " Search End Jadwal[tgl bln thn] : ";
			cin >> end_tgl; cin >> end_bln; cin >> end_thn;
			current = Larmada;
			cout << "================== Search Armada ==================" << endl << endl;
			while (current != NULL) {
				if (current->info.tanggal >= start_tgl && current->info.tanggal <= end_tgl) {
					if (current->info.bulan >= start_bln && current->info.bulan <= end_bln) {
						if (current->info.tahun >= start_thn && current->info.tahun <= end_thn) {
							cout << " >\tKode Armada\t: " << current->info.id << endl;
							cout << " \tNama Armada\t: " << current->info.nama_armada << endl;
							cout << " \tJenis Armada\t: " << current->info.jenis_armada << endl;
							cout << " \tArmada Asal\t: " << current->info.asal << endl;
							cout << " \tArmada Tujuan\t: " << current->info.tujuan << endl;
							cout << " \tJadwal Berangkat: " << current->info.jadwal << endl;
							cout << " \tWaktu Berangkat\t: " << current->info.waktu << endl << endl;
							cout << " \tKapasitas\t: " << current->info.capacity << " / " << current->info.max_capacity << " KG" << endl;
							cout << " *\tList Barang dari Cargo :" << endl;
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
			cout << " Search Tujuan : ";
			cin >> data.tujuan;
			current = Larmada;
			cout << "================== Search Armada ==================" << endl << endl;
			while (current != NULL) {
				if (current->info.tujuan == data.tujuan) {
					cout << " >\tKode Armada\t: " << current->info.id << endl;
					cout << " \tNama Armada\t: " << current->info.nama_armada << endl;
					cout << " \tJenis Armada\t: " << current->info.jenis_armada << endl;
					cout << " \tArmada Asal\t: " << current->info.asal << endl;
					cout << " \tArmada Tujuan\t: " << current->info.tujuan << endl;
					cout << " \tJadwal Berangkat: " << current->info.jadwal << endl;
					cout << " \tWaktu Berangkat\t: " << current->info.waktu << endl << endl;
					cout << " \tKapasitas\t: " << current->info.capacity << " / " << current->info.max_capacity << " KG" << endl;
					cout << " *\tList Barang dari Cargo :" << endl;
					showAllCargo(current->cargo);
				}
				current = current->next;
			}
		}
		break;
	}
}

// Cargo
void menu_cargo() {
	system("cls");
	vector<string> menu = {
		{"Tambah Cargo"}, {"Hapus Cargo By Kode"}, {"Cari Cargo dan Tampilkan Spesifikasi Barangnya"} , {"Ganti data barang"}
	};

	gotoxy(1, 1);
	puts("=================== PILIH MENU! ===================");
	for (int i = 0; i < menu.size(); ++i) {
		gotoxy(3, 2 + i);
		cout << i + 1 << "> " << menu[i];
	}
	gotoxy(3, 7);
	cout << 9 << "> " << "Kembali Ke Kategori";
	gotoxy(3, 8);
	cout << 0 << "> " << "Exit";
	gotoxy(1, 9);
	puts("====================================================");
}
void addCargo(adrCargo& cargo, adrArmada armada) {
	adrCargo child;
	adrArmada searchAramda; Armada dataA;
	int total, done; bool dup = false;
	gotoxy(0, 10);
	showAllArmada(armada, false, false);
	cout << " * kode -1 Untuk Kembali\n";
	cout << "Masukan Kode Armada : ";
	cin >> dataA.id;
	if (dataA.id == "-1")return;

	searchAramda = findArmadaByID(armada, dataA); //nyari parrent
	if (searchAramda != NULL) {
		cout << "Masukan Jumlah Data : ";
		cin >> total;
		if (total == -1) return;
		if (total >= 1) {
			for (int i = 1; i <= total;) {
				if (dup) cout << "================ KODE DUPLIKAT SILAHKAN INPUT ULANG ================" << endl;
				else cout << "================ MASUKAN DATA KE-" << i << " ================" << endl;
				Cargo newdata;

				cout << "Kode Barang : ";
				cin >> newdata.id_barang;
				if (newdata.id_barang == "-1") return;
				cout << "Nama Barang : ";
				cin >> newdata.nama_barang;
				cout << "Volume Barang : ";
				cin >> newdata.volume_barang;

				if (findChildByID(searchAramda->cargo, newdata) == NULL) { // idnya ada yang sama atau tidak.

					if (searchAramda->info.capacity + newdata.volume_barang >= searchAramda->info.max_capacity)
						cout << "Volume barang melebihi kapasitas!!" << endl;
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
	adrArmada current, Search_Armada;
	Armada id_armada;
	if (armada != NULL) {
		current = armada;
		cout << "================== Search Cargo ==================" << endl << endl;
		while (current != NULL) {
			cout << " > Kode Armada : " << current->info.id << " [" << current->info.capacity << " / " << current->info.max_capacity << "]KG" << endl;
			if (current->cargo == NULL)
				cout << "\tList barang kosong !!" << endl;
			showAllCargo(current->cargo);
			current = current->next;
		}
		cout << "==================== EndSearch ====================" << endl;

		cout << " * -1 Untuk Kembali\n";

		cout << "\nCari Armada dengan Kode : ";
		cin >> id_armada.id;
		if (id_armada.id == "-1") return;


		adrCargo del = NULL; adrCargo searchCargo = NULL;
		Search_Armada = findArmadaByID(armada, id_armada);
		if (Search_Armada != NULL) {

			cout << "\nHapus data dengan Kode : ";
			cin >> newdata.id_barang;
			if (newdata.id_barang == "-1") return;

			searchCargo = findChildByID(Search_Armada->cargo, newdata);
			cout << "Search Cargo : " << searchCargo->info.id_barang << endl;
			if (searchCargo != NULL) {
				deleteAfterChild(Search_Armada->cargo, searchCargo, del);
				if (del != NULL) {
					Search_Armada->info.capacity -= del->info.volume_barang;
					cout << "Data Berhasil di hapus dengan kode barang " << del->info.id_barang << endl;
				}
			}
			else cout << "Data tidak ditemukan dengan ID : " << newdata.id_barang << endl;
		}
		else cout << "Armada tidak ditemukan dengan ID : " << id_armada.id << endl;
	}
}
void findAndShowChild(adrCargo Lcargo, adrArmada Larmada) {
	adrArmada current, show_list;
	adrCargo list_barang, searchCargo, show_child;
	Cargo newdata;
	int select_find = 0;
	cout << " [1]Search info Kode; [2]Search nama;" << endl;
	cout << "Search dengan: ";
	cin >> select_find;

	switch (select_find) {
	case 1:
		if (Larmada != NULL) {
			cout << "=================== List Cargo! ===================" << endl << endl;
			show_list = Larmada;
			while (show_list != NULL) {
				show_child = show_list->cargo;
				cout << " > Kode Armada : " << show_list->info.id << " [" << show_list->info.capacity << " / "
					<< show_list->info.max_capacity << "]KG" << endl;
				while (show_child != NULL) {
					cout << "\tKode Barang : " << show_child->info.id_barang << endl;
					show_child = show_child->next;
				}
				show_list = show_list->next;
			}
			cout << "==================== End List! ====================" << endl;

			cout << " Search Kode : ";
			cin >> newdata.id_barang;

			current = Larmada;
			cout << "================== Search Cargo ==================" << endl << endl;
			while (current != NULL) {
				list_barang = current->cargo;
				if (list_barang != NULL) {
					searchCargo = findChildByID(list_barang, newdata);
					if (searchCargo != NULL) {
						cout << "\tKode Armada\t: " << current->info.id << endl;
						cout << "\tKode Barang\t: " << searchCargo->info.id_barang << endl;
						cout << "\tNama Barang\t: " << searchCargo->info.nama_barang << endl;
						cout << "\tBerat Barang\t: " << searchCargo->info.volume_barang << endl << endl;
					}
					else cout << newdata.id_barang << " Tidak ditemukan!!" << endl;
				}
				current = current->next;
			}
			cout << "==================== EndSearch ====================" << endl;

		}
		break;
	case 2:
		if (Larmada != NULL) {
			cout << "=================== List Cargo! ===================" << endl << endl;
			show_list = Larmada;
			while (show_list != NULL) {
				show_child = show_list->cargo;
				cout << " > Kode Armada : " << show_list->info.id << " [" << show_list->info.capacity << " / "
					<< show_list->info.max_capacity << "]KG" << endl;
				while (show_child != NULL) {
					cout << "\tNama Armada : " << show_child->info.nama_barang << endl;
					show_child = show_child->next;
				}
				show_list = show_list->next;
			}
			cout << "==================== End List! ====================" << endl;


			current = Larmada;
			cout << " Search Nama Barang : ";
			cin >> newdata.nama_barang;

			cout << "================== Hasil Cargo ==================" << endl << endl;
			while (current != NULL) {
				list_barang = current->cargo;
				if (list_barang != NULL) {
					while (list_barang != NULL) {
						if (list_barang->info.nama_barang == newdata.nama_barang) {
							cout << "\tKode Armada\t: " << current->info.id << endl;
							cout << "\t > Kode Barang\t: " << list_barang->info.id_barang << endl;
							cout << "\t   Nama Barang\t: " << list_barang->info.nama_barang << endl;
							cout << "\t   Berat Barang\t: " << list_barang->info.volume_barang << endl << endl;
						}
						list_barang = list_barang->next;
					}
				}
				current = current->next;
			}
			cout << "==================== EndSearch ====================" << endl;
		}
		else cout << "\tArmada Kosong!!" << endl << endl;
		break;
	}
}
void printTotalParentChild(adrArmada Larmada) {
	adrArmada current;
	adrCargo child;
	int totalParent = 0; int totalChild;

	if (Larmada != NULL) {
		current = Larmada;
		while (current != NULL) {
			child = current->cargo;
			totalChild = 0;
			while (child != NULL) {
				totalChild++;
				child = child->next;
			}
			cout << "\t>Armada " << current->info.id
				<< ": " << totalChild << " barang" << endl;
			totalParent++;
			current = current->next;
		}
		cout << "\n\t>Total Armada : " << totalParent << endl;
	}
}
void replaceChild(adrArmada Larmada,adrCargo Lcargo) {
	Armada armada;
	adrArmada current;
	
	Cargo cargo, n_cargo;
	char konfirmasi;
	if (Larmada != NULL) {
		current = Larmada;
		cout << "================== Search Cargo ==================" << endl << endl;
		while (current != NULL) {
			cout << " > Kode Armada : " << current->info.id << " [" << current->info.capacity << " / " << current->info.max_capacity << "]KG" << endl;
			if (current->cargo == NULL)
				cout << "\tList barang kosong !!" << endl;
			showAllCargo(current->cargo);
			current = current->next;
		}
		cout << "==================== EndSearch ====================" << endl;

		cout << "Cari Kode Armada : ";
		cin >> armada.id;
		
		adrArmada find_parent = findArmadaByID(Larmada, armada);
		if (find_parent != NULL) {
			cout << "Pilih kode barang yang ingin dirubah : ";
			cin >> cargo.id_barang;
			adrCargo find_child = findChildByID(find_parent->cargo, cargo);
			cout << find_child->info.id_barang << endl;
			if (find_child != NULL) {
				cout << "Masukan databaru untuk di ganti" << endl;
				cout << "Nama Barang : ";
				n_cargo.id_barang = find_child->info.id_barang; // id barang tidak berubah;
				cin >> n_cargo.nama_barang;
				cout << "Volume Barang : ";
				cin >> n_cargo.volume_barang;

				cout << "Apakah kode id barang " << find_child->info.id_barang << " di ganti? [Y/N] : ";
				cin >> konfirmasi;
				if (konfirmasi == 'Y') {
					find_parent->info.capacity -= find_child->info.volume_barang;
					find_child->info = n_cargo;
					find_parent->info.capacity += n_cargo.volume_barang;
				}
				else cout << "Data tidak berhasil di rubah" << endl;
			}
			else cout << "Kode barang tidak ada!!" << endl;

		}
		else cout << "Aramda tidak di temukan!!" << endl;

	}
}
void dummy(adrArmada& Larmada) {
	Armada data;
	data.id = "A001"; data.nama_armada = "CDE"; data.jenis_armada = "Truck"; data.asal = "Bandung"; data.tujuan = "Jakarta"; data.tanggal = 9; data.bulan = 1; data.tahun = 2023; data.jadwal = "09/01/2023"; data.waktu = "08:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
	
	data.id = "A002"; data.nama_armada = "GrandMax"; data.jenis_armada = "Truck"; data.asal = "Bandung"; data.tujuan = "Bali"; data.tanggal = 12; data.bulan = 1; data.tahun = 2023; data.jadwal = "12/01/2023"; data.waktu = "12:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
	
	data.id = "A003"; data.nama_armada = "Fuso"; data.jenis_armada = "Truck"; data.asal = "Bandung"; data.tujuan = "Bogor"; data.tanggal = 13; data.bulan = 1; data.tahun = 2023; data.jadwal = "13/01/2023"; data.waktu = "13:00"; data.max_capacity = 1000; data.capacity = 0;
	insertLast(Larmada, allocArmada(data));
}