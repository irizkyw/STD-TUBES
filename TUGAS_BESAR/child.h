typedef struct element_cargo* adrCargo;

struct Cargo{
	std::string id_barang, nama_barang;
	float volume_barang;
};

struct element_cargo {
	Cargo info;
	adrCargo next;
};

adrCargo allocCargo(Cargo data);
void insertFirstChild(adrCargo& Larmada, adrCargo data_baru);
void insertAfterChild(adrCargo& Larmada, adrCargo Prec, adrCargo P);
void insertLastChild(adrCargo& Larmada, adrCargo P);
void deleteFirstChild(adrCargo& Larmada, adrCargo& P);
void deleteLastChild(adrCargo& Larmada, adrCargo& del);
void deleteAfterChild(adrCargo& Larmada, adrCargo Prec, adrCargo& P);

adrCargo findChildByID(adrCargo Larmada, Cargo search);
