#include "globals.h"

adrCargo allocCargo(Cargo data) {
	adrCargo alloc = new element_cargo;
	alloc->info = data;
	alloc->next = NULL;
	return alloc;
}
void insertFirstChild(adrCargo& Lcargo, adrCargo data_baru) {
	if (Lcargo == NULL)
		Lcargo = data_baru;
	else {
		data_baru->next = Lcargo;
		Lcargo = data_baru;
	}
}
void insertAfterChild(adrCargo& Lcargo, adrCargo Prec, adrCargo data_baru) {
	adrCargo current;
	if (Lcargo == NULL) insertFirstChild(Lcargo, data_baru);
	else {
		current = Lcargo;
		while (current != Prec) current = current->next;
		data_baru->next = current->next;
		current->next = data_baru;
	}
}
void insertLastChild(adrCargo& Lcargo, adrCargo data_baru) {
	adrCargo current;
	if (Lcargo == NULL)
		Lcargo = data_baru;
	else {
		current = Lcargo;
		while (current->next != NULL) current = current->next;
		current->next = data_baru;
	}
}
void deleteFirstChild(adrCargo& Lcargo, adrCargo& P) {
	if (Lcargo != NULL) {
		P = Lcargo;
		Lcargo = Lcargo->next;
		P->next = NULL;
	}
	else std::cout << "[ERROR] List Cargo Kosong!!" << std::endl;
}
void deleteLastChild(adrCargo& Lcargo, adrCargo& del) {
	adrCargo current;
	if (Lcargo != NULL) {
		if (Lcargo->next == NULL) deleteFirstChild(Lcargo, del);
		else {
			current = Lcargo;
			while (current->next->next != NULL) current = current->next;
			del = current->next;
			current->next = NULL;
		}
	}
	else std::cout << "[ERROR] List Cargo Kosong!!" << std::endl;
}
void deleteAfterChild(adrCargo& Lcargo, adrCargo Prec, adrCargo& del) {
	adrCargo current;
	if (Lcargo != NULL) {
		if (Prec->next == NULL) deleteLastChild(Lcargo, del);
		else if (Prec == Lcargo) deleteFirstChild(Lcargo,del);
		else {
			current = Lcargo;
			while (current != Prec) current = current->next;
			del = current->next;
			current->next = del->next;
			del->next = NULL;
		}
	}
	else std::cout << "[ERROR] List Cargo Kosong!!" << std::endl;
}
adrCargo findChildByID(adrCargo Lcargo, Cargo search) {
	adrCargo current;
	if (Lcargo != NULL) {
		current = Lcargo;
		while (current != NULL && current->info.id_barang != search.id_barang) current = current->next;
		return current;
	}
	else return NULL;
}