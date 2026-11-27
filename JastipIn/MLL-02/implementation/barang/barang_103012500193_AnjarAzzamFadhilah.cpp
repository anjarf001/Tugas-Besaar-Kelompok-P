#include "../../header/matakuliah.h"

void insertLastBarang(ListBarang &L, adrBarang P){
    if (isEmptyBarang(L)) {
        L.first = P;
    } else {
        adrBarang Q = L.first;
        while (Q->next != NULL) {       // telusuri sampai elemen terakhir
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteLastBarang(ListBarang &L, adrBarang &P){
    P = NULL;
    if (isEmptyBarang(L)) {
        return;
    }
    if (L.first->next == NULL) {
        deleteFirstBarang(L, P);
    } else {
        adrBarang Q = L.first;
        while (Q->next->next != NULL) {
            Q = Q->next;
        }
        P = Q->next;                    // P = elemen terakhir
        Q->next = NULL;                 // Q jadi elemen terakhir yang baru
    }
}

void insertAfterBarang(ListBarang &L, adrBarang Prec, adrBarang P){
    if (isEmptyBarang(L) || Prec == NULL) {
        return;                         // list kosong / Prec tidak valid, batalkan
    }
    P->next = Prec->next;
    Prec->next = P;
}

void deleteAfterBarang(ListBarang &L, adrBarang Prec, adrBarang &P){
    P = NULL;
    if (isEmptyBarang(L) || Prec == NULL || Prec->next == NULL) {
        return;                         // tidak ada yang bisa dihapus
    }
    P = Prec->next;
    Prec->next = P->next;
    P->next = NULL;
}