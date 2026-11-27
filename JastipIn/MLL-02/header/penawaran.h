#ifndef KRS_H_INCLUDED
#define KRS_H_INCLUDED
#include "penyedia.h"
#include "barang.h"
#include <string>
#include <iostream>

using namespace std;

struct infotypePenawaran {
    int harga;
    int stok;
    string status;   // "ready" , "habis" , "PO"
};

typedef struct elmPenawaran *adrPenawaran; //alias untuk pointer ke elemen penawaran

// kerangka dari elemen list
struct elmPenawaran {
    infotypePenawaran info;  
    adrPenawaran next;       
    adrPenawaran prev;       
    adrPenyedia penyedia;    // pointer ke PARENT (penyedia yang menawarkan)
    adrBarang barang;        // pointer ke CHILD  (barang yang ditawarkan)
};

// kerangka dari list
struct ListPenawaran {
    adrPenawaran first;
    adrPenawaran last;
};

// pengecekan apakah list kosong
bool isEmptyPenawaran(ListPenawaran L);
/* I.S. terdefinisi list
   F.S. mengembalikan true jika list kosong dan false jika list tidak kosong */

// pembuatan list kosong
void createListPenawaran(ListPenawaran &L);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
adrPenawaran createElmPenawaran(infotypePenawaran x, adrPenyedia P, adrBarang B);
/* I.S. terdefinisi info x, alamat penyedia P dan alamat barang B
   F.S. mengembalikan alamat elemen baru yang sudah dialokasi dengan info berisi x,
        penyedia menunjuk P, barang menunjuk B, next dan prev bernilai NULL */

void dealokasiPenawaran(adrPenawaran &P);
/* I.S. terdefinisi elemen list P yang sudah tidak dipakai
   F.S. memori elemen P dikembalikan ke sistem dan P bernilai NULL */

// pencarian sebuah elemen list
adrPenawaran findPenawaran(ListPenawaran L, adrPenyedia P, adrBarang B);
/* I.S. terdefinisi list, alamat penyedia P dan alamat barang B
   F.S. mengembalikan alamat elemen penawaran yang menghubungkan P dan B
        atau NULL jika tidak ditemukan */

// penambahan elemen *
void insertFirstPenawaran(ListPenawaran &L, adrPenawaran P);
/* I.S. terdefinisi list yang mungkin kosong dan elemen list P
   F.S. elemen list P menjadi elemen pertama list,
        jika list sebelumnya kosong maka P juga menjadi elemen terakhir */

void insertAfterPenawaran(ListPenawaran &L, adrPenawaran Prec, adrPenawaran P);
/* I.S. terdefinisi list yang mungkin kosong, elemen list P dan elemen list prec
   F.S. elemen list P berada tepat setelah prec,
        jika prec adalah elemen terakhir maka P menjadi elemen terakhir,
        jika list kosong atau prec NULL maka list tidak berubah */

void insertLastPenawaran(ListPenawaran &L, adrPenawaran P);
/* I.S. terdefinisi list yang mungkin kosong dan elemen list P
   F.S. elemen list P menjadi elemen terakhir list,
        jika list sebelumnya kosong maka P juga menjadi elemen pertama */

// penghapusan sebuah elemen
void deleteFirstPenawaran(ListPenawaran &L, adrPenawaran &P);
/* I.S. terdefinisi list yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list setelahnya akan menjadi
        elemen list pertama atau tidak ada elemen list pertama */

void deleteLastPenawaran(ListPenawaran &L, adrPenawaran &P);
/* I.S. terdefinisi list yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemen list terakhir atau tidak ada elemen list terakhir */

void deleteAfterPenawaran(ListPenawaran &L, adrPenawaran Prec, adrPenawaran &P);
/* I.S. terdefinisi list yang mungkin kosong, elemen list P dan elemen list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah P akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */

void deleteElmPenawaran(ListPenawaran &L, adrPenawaran Q, adrPenawaran &P);
/* I.S. terdefinisi list yang mungkin kosong dan elemen list Q yang ada di list
   F.S. P adalah alamat elemen Q yang sudah dilepas dari list
        P bernilai NULL jika list kosong atau Q NULL */

// tampil
void printPenawaran(ListPenawaran L);
/* I.S. terdefinisi list LMK yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua penawaran (penyedia, barang, harga,
        stok, status), jika list kosong menampilkan pesan data penawaran kosong */


//baru oprasi primitif saja belum ada tambahan!!!



#endif // KRS_H_INCLUDED
