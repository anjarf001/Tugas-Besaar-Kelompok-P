#include "../header/penyedia.h"
void insertLastPenyedia(ListPenyedia &L, adrPenyedia P) {
    if (isEmptyPenyedia(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;       // P menunjuk balik ke elemen terakhir lama
        L.last->next = P;       // elemen terakhir lama menunjuk ke P
        L.last = P;             // P resmi menjadi elemen terakhir
    }
}

void insertAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia P) {
    if (isEmptyPenyedia(L) || Prec == NULL) {
        return;                 // list kosong
    }
    if (Prec == L.last) {
        insertLastPenyedia(L, P);
    } else {
        P->next = Prec->next;       // P menunjuk ke elemen setelah Prec
        P->prev = Prec;          // P menunjuk balik ke Prec
        Prec->next->prev = P;       // elemen setelah Prec menunjuk balik ke P
        Prec->next = P;          // Prec menunjuk maju ke P
    }
}

void deleteLastPenyedia(ListPenyedia &L, adrPenyedia &P) {
    P = NULL;
    if (isEmptyPenyedia(L)) {
        return;
    }
    P = L.last;
    if (L.first == L.last) {            // hanya satu elemen
        L.first = NULL;
        L.last = NULL;
    } else {
        L.last = P->prev;               // elemen sebelum terakhir jadi last
        L.last->next = NULL;            // last tidak punya elemen sesudahnya
        P->prev = NULL;                 // putus P dari list
    }
}

void deleteAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia &P) {
    P = NULL;
    if (isEmptyPenyedia(L) || Prec == NULL || Prec->next == NULL) {
        return;                         // tidak ada yang bisa dihapus
    }
    if (Prec->next == L.last) {
        deleteLastPenyedia(L, P);
    } else {
        P = Prec->next;                 // P = elemen yang akan dilepas
        Prec->next = P->next;           // Prec langsung menyambung ke elemen setelah P
        P->next->prev = Prec;           // elemen setelah P menyambung balik ke Prec
        P->next = NULL;                 // putus P dari list
        P->prev = NULL;
    }
}