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
void insertFirstChild(adrCargo& Lcargo, adrCargo data_baru);
void insertAfterChild(adrCargo& Lcargo, adrCargo Prec, adrCargo data_baru);
void insertLastChild(adrCargo& Lcargo, adrCargo data_baru);
void deleteFirstChild(adrCargo& Lcargo, adrCargo& P);
void deleteLastChild(adrCargo& Lcargo, adrCargo& del);
void deleteAfterChild(adrCargo& Lcargo, adrCargo Prec, adrCargo& del);

adrCargo findChildByID(adrCargo Lcargo, Cargo search);
