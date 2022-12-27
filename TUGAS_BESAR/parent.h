#include "child.h"

typedef struct element_armada* adrArmada;
struct Armada {
	std::string id, nama_armada, jenis_armada, asal, tujuan, jadwal, waktu;
	int tanggal, bulan, tahun;
	float capacity, max_capacity;
};

struct element_armada {
	Armada info;
	adrCargo cargo;
	adrArmada next;
};



void init(adrArmada& start);
adrArmada allocArmada(Armada data);
void insertFirst(adrArmada& Larmada, adrArmada data_baru);
void insertAfter(adrArmada& Larmada, adrArmada Prec, adrArmada P);
void insertLast(adrArmada& Larmada, adrArmada P);
void deleteFirst(adrArmada& Larmada, adrArmada& P);
void deleteLast(adrArmada& Larmada, adrArmada& del);
void deleteAfter(adrArmada& Larmada, adrArmada Prec, adrArmada& P);

adrArmada findArmadaByID(adrArmada Larmada, Armada search);
void countAllChild(adrArmada Larmada);
int countMinimumChild(adrArmada Larmada, Armada& data);
int countMaximumChild(adrArmada Larmada, Armada& data);

void showAllArmada(adrArmada Larmada, bool showAll, bool showChild);
void showAllCargo(adrCargo Lcargo);