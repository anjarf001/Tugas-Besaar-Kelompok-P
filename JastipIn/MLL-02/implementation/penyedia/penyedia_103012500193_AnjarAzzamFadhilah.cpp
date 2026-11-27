#include "../header/penyedia.h"

void createListPenyedia(ListPenyedia &L){
    L.first = NULL;
    L.last = NULL;
}

bool isEmptyPenyedia(ListPenyedia L){
    return L.first == NULL && L.last == NULL;
}

adrPenyedia createElmPenyedia(inoftypePenyedia x){
    adrPenyedia P = new elmPenyedia;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasiPenyedia(adrPenyedia &P){
    delete P;
    P = NULL;
}

void insertFirstPenyedia(ListPenyedia &L, adrPenyedia P){
    if (isEmptyPenyedia(L)) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;      // P menunjuk ke elemen pertama lama
        L.first->prev = P;      // elemen pertama lama menunjuk balik ke P
        L.first = P;            // P resmi menjadi elemen pertama
    }
}

void deleteFirstPenyedia(ListPenyedia &L, adrPenyedia &P){
    P = NULL;
    if (isEmptyPenyedia(L)) {
        return;
    }
    P = L.first;
    if (L.first == L.last) {            // hanya satu elemen
        L.first = NULL;
        L.last = NULL;
    } else {
        L.first = P->next;              // elemen kedua jadi first
        L.first->prev = NULL;           // first tidak punya elemen sebelumnya
        P->next = NULL;                 // putus P dari list
    }
    
}

void printPenyedia(ListPenyedia L){
    if (isEmptyPenyedia(L)) {
        cout << "Data penyedia kosong." << endl;
        return;
    }
    adrPenyedia P = L.first;
    int i = 1;
    while (P != NULL) {
        cout << i << ". ID: " << P->info.id
             << " | Nama: " << P->info.nama
             << " | Kota: " << P->info.kota << endl;
        P = P->next;
        i++;
    }
}

adrPenyedia findPenyedia(ListPenyedia L, string id){
    adrPenyedia P = L.first;
    while (P != NULL) {
        if (P->info.id == id) {
            return P;
        }
        P = P->next;                    // lanjut ke elemen berikutnya
    }
    return NULL;

}

void hapusSemuaPenyedia(ListPenyedia &L){
    adrPenyedia P;
    while (!isEmptyPenyedia(L)) {
        deleteFirstPenyedia(L, P);
        dealokasiPenyedia(P);
}