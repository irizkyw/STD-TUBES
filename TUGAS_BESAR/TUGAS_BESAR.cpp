// TUGAS_BESAR.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "globals.h"

using namespace std;



int main()
{
	adrArmada armada;
	init(armada);
	int kategori = -1; int menu = -1; bool stat = false; int pause;
	mahasiswa();
	if (cin.get())system("cls");

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
				break;
			case 4:
				showAllArmada(armada);
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
			menu_armada();
			switch (menu) {
			case 1:
				break;
			case 2:
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

