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

void dummy(adrArmada& Larmada);