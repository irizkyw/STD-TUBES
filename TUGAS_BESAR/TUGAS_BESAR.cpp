// TUGAS_BESAR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "globals.h"

using namespace std;

int main()
{
	adrArmada armada;
	adrCargo cargo;
	Armada max_data, min_data;
	int min, max;
	init(armada);
	initCargo(cargo);
	int kategori = -1; int menu = -1; bool stat = false; int pause;
	mahasiswa();
	if (cin.get())system("cls");
	cin.clear();

	dummy(armada);
	while (kategori != 0 || menu != 0) {
		if(menu == 9 || stat == false) category(kategori,stat);
		if (kategori == 0) return 0;
		if (kategori == 1 && stat == true) {
			menu_armada();
			std::cout << "Select Menu : ";
			std::cin >> menu;
			switch (menu) {
			case 1:
				addArmada(armada);
				puts("\n\nPenambahan Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 2:
				deleteById(armada);
				cin >> pause;
				puts("\n\nHapus Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				break;
			case 3:
				showAllArmada(armada,true,true);
				puts("\n\Show Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 4:
				findAndShow(armada);
				puts("\n\nCari Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 5:
				max = countMaximumChild(armada, max_data);
				min = countMinimumChild(armada, min_data);
				if (max != INT_MIN && min != INT_MAX) {
					cout << "Data paling banyak adalah " << max << " barang, Dengan Kode Armada " << max_data.id << endl;
					cout << "Data paling sedikit adalah " << min << " barang, Dengan Kode Armada " << min_data.id << endl;
				}else cout << "Tidak ada barang" << endl;
				puts("\n\nCari Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 6:
				printTotalParentChild(armada);
				puts("\n\nCari Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 9:
				stat = false;
				break;
			case 0:
				exit;
				break;
			default:
				cout << "Menu tidak tersedia" << endl;
				break;
			}
		}
		if (kategori == 2 && stat == true) {
			menu_cargo();
			std::cout << "Select Menu : ";
			std::cin >> menu;
			switch (menu) {
			case 1:
				addCargo(cargo,armada);
				puts("\n\nPenambahan Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 2:
				deleteByIdChild(armada);
				cin >> pause;
				puts("\n\nHapus Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				break;
			case 3:
				findAndShowChild(cargo, armada);
				puts("\n\nCari Data Selesai [Press 0 - 9] Untuk kembali ke menu");
				cin >> pause;
				break;
			case 9:
				stat = false;
				break;
			case 0:
				exit;
				break;
			default:
				cout << "Menu tidak tersedia" << endl;
				break;
			}
		}
	}
}