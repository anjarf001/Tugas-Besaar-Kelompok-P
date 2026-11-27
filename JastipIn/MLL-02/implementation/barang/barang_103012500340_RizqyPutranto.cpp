#include "../header/barang.h"
bool isEmptyBarang(ListBarang L) {
    return L.first == NULL;
}

void createListBarang(ListBarang &L) {
    L.first = NULL;
}

adrBarang createElmBarang(infotypeBarang x) {
    adrBarang P = new elmBarang;
    P->info = x;
    P->next = NULL;
    return P;
}

void dealokasiBarang(adrBarang &P) {
    delete P;
    P = NULL;
}

void insertFirstBarang(ListBarang &L, adrBarang P) {
    P->next = L.first;
    L.first = P;
}

void deleteFirstBarang(ListBarang &L, adrBarang &P) {
    P = NULL;
    if (isEmptyBarang(L)) {
        return;
    }
    P = L.first;
    L.first = P->next;                  // first geser ke elemen kedua
    P->next = NULL;                     // putus P dari list
}

void printBarang(ListBarang L) {
    if (isEmptyBarang(L)) {
        cout << "Data barang kosong." << endl;
        return;
    }
    adrBarang P = L.first;
    int i = 1;
    while (P != NULL ) {
        cout << i << ". ID: " << P->info.id
             << " | Nama: " << P->info.namaBarang
             << " | Kategori: " << P->info.kategori << endl;
        P = P->next;
        i++;
    }
}
adrBarang findBarang(ListBarang L, string id) {
    adrBarang P = L.first;
    while (P != NULL) {
        if (P->info.id == id) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void hapusSemuaBarang(ListBarang &L) {
    adrBarang P;
    while (!isEmptyBarang(L)) {
        deleteFirstBarang(L, P);
        dealokasiBarang(P);
    }
}
