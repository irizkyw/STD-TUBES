#include "globals.h"

using namespace std;

void init(adrArmada& start) {
	start = NULL;
}
adrArmada allocArmada(Armada data) {
	adrArmada alloc = new element_armada;
	alloc->info = data;
	alloc->next = NULL;
	alloc->cargo = NULL;
	return alloc;
}
void insertFirst(adrArmada& Larmada, adrArmada data_baru) {
	if (Larmada == NULL)
		Larmada = data_baru;
	else {
		data_baru->next = Larmada;
		Larmada = data_baru;
	}
}
void insertAfter(adrArmada& Larmada, adrArmada Prec, adrArmada data_baru) {
	adrArmada current;
	if (Larmada == NULL) insertFirst(Larmada, data_baru);
	else {
		current = Larmada;
		while (current != Prec) current = current->next;
		data_baru->next = current->next;
		current->next = data_baru;
	}
}
void insertLast(adrArmada& Larmada, adrArmada data_baru) {
	adrArmada current;
	if (Larmada == 0)
		insertFirst(Larmada, data_baru);
	else {
		current = Larmada;
		while (current->next != NULL) current = current->next;
		current->next = data_baru;
	}
}
void deleteFirst(adrArmada& Larmada, adrArmada& P) {
	if (Larmada != NULL) {
		P = Larmada;
		Larmada = Larmada->next;
		P->next = NULL;
	}
	else std::cout << "[ERROR] List Armada Kosong!!" << std::endl;
}
void deleteLast(adrArmada& Larmada, adrArmada& del) {
	adrArmada current;
	if (Larmada != NULL) {
		if (Larmada->next == NULL) deleteFirst(Larmada, del);
		else {
			current = Larmada;
			while (current->next->next != NULL) current = current->next;
			del = current->next;
			current->next = NULL;
		}
	} else std::cout << "[ERROR] List Armada Kosong!!" << std::endl;
}
void deleteAfter(adrArmada& Larmada, adrArmada Prec, adrArmada& del) {
	adrArmada current;
	if (Larmada != NULL) {
		if (Prec->next == NULL) deleteLast(Larmada, del);
		else if (Prec == Larmada) deleteFirst(Larmada, del);
		else {
			current = Larmada;
			while (current != Prec) current = current->next;
			del = current->next;
			current->next = del->next;
			del->next = NULL;
			del->cargo = NULL; 
		}
	}
	else std::cout << "[ERROR] List Armada Kosong!!" << std::endl;
}
adrArmada findArmadaByID(adrArmada Larmada, Armada search) {
	adrArmada current;
	if (Larmada != NULL) {
		current = Larmada;
		while (current != NULL && current->info.id != search.id) current = current->next;
		return current;
	}
	else return NULL;
}
void countAllChild(adrArmada Larmada) {
	int total, temp; adrArmada current; adrCargo child;
	total = 0;
	if (Larmada != NULL) {
		current = Larmada;
		while (current != NULL) {
			child = current->cargo;
			temp = 0;
			while (child != NULL) {
				temp++;
				child = child->next;
			}
			current = current->next;
		}
	}
	else std::cout << "[ERROR] List Armada Kosong!!" << std::endl;
}
int countMinimumChild(adrArmada Larmada, Armada& data_armada) {
	int total = 0; int temp; adrArmada current; adrCargo child;
	if (Larmada != NULL) {
		current = Larmada;
		while (current != NULL) {
			child = current->cargo;
			temp = 0;
			while (child != NULL) {
				temp++;
				child = child->next;
			}
			if (temp > total) {
				data_armada = current->info;
				temp = total;
			}
			current = current->next;
		}
		return total;
	}
	else return -1;
}
int countMaximumChild(adrArmada Larmada, Armada& data_armada) {
	int total = 0; int temp; adrArmada current; adrCargo child;
	if (Larmada != NULL) {
		current = Larmada;
		while (current != NULL) {
			child = current->cargo;
			temp = 0;
			while (child != NULL) {
				temp++;
				child = child->next;
			}
			if (temp > total) {
				data_armada = current->info;
				temp = total;
			}
			current = current->next;
		}
		return total;
	}
	else return -1;
}
void showAllArmada(adrArmada Larmada,bool showAll) {
	adrArmada current; int i = 0;
	system("cls");
	if (Larmada == NULL) cout << "Armada Kosong" << endl;
	else {
		current = Larmada;
		gotoxy(1, 0);
		cout << "=================== List Armada ===================" << endl << endl;
		while (current != NULL) {
			cout << " >\tKode Armada\t: " << current->info.id << endl;
			cout << " \tNama Armada\t: " << current->info.nama_armada << endl;
			if (showAll) cout << " \tJenis Armada\t: " << current->info.jenis_armada << endl;
			if (showAll) cout << " \tArmada Asal\t: " << current->info.asal << endl;
			if (showAll == false) cout << " \tArmada Tujuan\t: " << current->info.tujuan << endl;
			if (showAll == false) cout << " \tJadwal Berangkat: " << current->info.jadwal << endl;
			if (showAll) cout << " \tWaktu Berangkat\t: " << current->info.waktu << endl << endl;
			if (showAll) cout << " \tMax Kapasitas\t: " << current->info.max_capacity << " KG" << endl;
			if (showAll) cout << " \tTotal Kapasitas\t: " << current->info.capacity << " KG" << endl << endl;
			if (showAll == false) cout << endl;
			current = current->next;
			i++;
		}
		cout << "==================== End List! ====================" << endl;
	}
}