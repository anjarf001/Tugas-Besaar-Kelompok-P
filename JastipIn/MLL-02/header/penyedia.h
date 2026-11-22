#ifndef PENYEDIA_H_INCLUDED
#define PENYEDIA_H_INCLUDED
#include "krs.h"
#include <string>
#include <iostream>

using namespace std;

struct infotypePenyedia
{
    string id;
    string nama;
    string kota;
};

typedef  struct elmPenyedia *adrPenyedia;   // variabel alias untuk pointer

// kerangka dari elemen list
struct elmPenyedia
{
    inoftypePenyedia info; //isi data penyedia
    adrPenyedia next; // pointer ke elemen berikutnya
    adrPenyedia prev; // pointer ke elemen sebelumnya
};

// kerangka dari list
struct ListPenyedia
{
    adrPenyedia first;
    adrPenyedia last;
};


void createListPenyedia(ListPenyedia &L);
/* I.S. sembarang
   F.S. terbentuk list kosong: first dan last bernilai NULL */

bool isEmptyPenyedia(ListPenyedia L);
/* I.S. terdefinisi list LMK
   F.S. mengembalikan true jika list kosong dan false jika list tidak kosong */

adrPenyedia createElmPenyedia(inoftypePenyedia x);
/* I.S. terdefinisi info x
   F.S. mengembalikan alamat elemen baru yang sudah dialokasi
        dengan info berisi x, next dan prev bernilai NULL */

void dealokasiPenyedia(adrPenyedia &P);
/* I.S. terdefinisi elemen list P yang sudah tidak dipakai
   F.S. memori elemen P dikembalikan ke sistem dan P bernilai NULL */


   // insert
void insertFirstPenyedia(ListPenyedia &L, adrPenyedia P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. elemen list P menjadi elemen pertama list,
        jika list sebelumnya kosong maka P juga menjadi elemen terakhir */

void insertLastPenyedia(ListPenyedia &L, adrPenyedia P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. elemen list P menjadi elemen terakhir list,
        jika list sebelumnya kosong maka P juga menjadi elemen pertama */

void insertAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia P);
/* I.S. terdefinisi list LMK yang mungkin kosong, elemen list P dan elemen list prec
   F.S. elemen list P berada tepat setelah prec,
        jika prec adalah elemen terakhir maka P menjadi elemen terakhir,
        jika list kosong atau prec NULL maka list tidak berubah */


   // delete
void deleteFirstPenyedia(ListPenyedia &L, adrPenyedia &P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list setelahnya akan menjadi
        elemen list pertama atau tidak ada elemen list pertama */
   
void deleteLastPenyedia(ListPenyedia &L, adrPenyedia &P);
/* I.S. terdefinisi list LMK yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemen list terakhir atau tidak ada elemen list terakhir */

void deleteAfterPenyedia(ListPenyedia &L, adrPenyedia Prec, adrPenyedia &P);
/* I.S. terdefinisi list LMK yang mungkin kosong, elemen list P dan elemen list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah P akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */

   // tampil
void printPenyedia(ListPenyedia L);
/* I.S. terdefinisi list LMK yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list,
        jika list kosong menampilkan pesan data penyedia kosong */
      
   // pencarian
adrPenyedia findPenyedia(ListPenyedia L, string id);
/* I.S. list dan id penyedia terdefinisi
   F.S. mengembalikan alamat elemen yang cocok atau NULL jika tidak ditemukan */
   
#endif // MAHASISWA_H_INCLUDED
