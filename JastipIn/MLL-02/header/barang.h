#ifndef BARANG_H_INCLUDED
#define BARANG_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

struct infotypebarang {
   string id, namabarang, kategori;
};

typedef  struct elmBarang *adrBarang;   // variabel alias untuk pointer

// kerangka dari elemen list
struct elmBarang {
   infotypebarang info;
   adrBarang next;
};

// kerangka dari list
struct ListBarang {
   adrBarang first;
};

// pengecekan apakah list kosong
bool isEmptyBarang(ListBarang L);
/* I.S Mengembalikan true jika list L kosong
   F.S mengembalikan false jika sebaliknya */

// pembuatan list kosong
void createListBarang(ListBarang &L);
/* I.S. ~
   F.S. terbentuk list kosong */

// manajemen memori
adrBarang createElmBarang(infotypeBarang x);
/* I.S. Mengembalikan alamat elemen baru yang sudah dialokasi
   F.S. dengan info = x dan next = NULL */

void dealokasiBarang(adrBarang &P);
/* I.S. pointer P terdefinisi
   F.S. memori yang digunakan P dikembalikan ke sistem */

// penambahan elemen *
void insertFirstBarang(ListBarang &L, adrBarang P);
/* I.S. L terdefinisi list barang mungkin kosong dan elemen list P
   F.S. P menjadi elemen pertama list L, dan next(P) menunjuk elemen
        yang sebelumnya pertama (NULL jika L sebelumnya kosong)*/

void insertLastBarang(ListBarang &L, adrBarang P);
/* I.S. L terdefinisi list barang mungkin kosong dan elemen list P
   F.S. P menjadi elemen terakhir list L. Jika L sebelumnya kosong,
        maka P menjadi elemen pertama */

void insertAfterBarang(ListBarang &L, adrBarang Prec, adrBarang P);
/* I.S. L terdefinisi list barang mungkin kosong, elemen list P dan Prec adalah elemen di L atau NULL
   F.S. P berada tepat setelah Prec, dan next(P) menunjuk elemen
        yang sebelumnya berada setelah Prec.
        Jika L kosong atau Prec = NULL, tidak ada yang disisipkan dan L tidak berubah*/

// penghapusan sebuah elemen
void deleteFirstBarang(ListBarang &L, adrBarang &P);
/* I.S. terdefinisi list barang yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen pertama list
        yang akan dihapus dan elemen list selanjutnya akan menjadi
        elemenlist pertama atau tidak ada elemen list pertama*/

void deleteLastBarang(ListBarang &L, adrBarang &P);
/* I.S. terdefinisi list barang yang mungkin kosong dan elemen list P
   F.S. P adalah alamat dari alamat elemen terakhir list
        yang akan dihapus dan elemen list sebelumnya akan menjadi
        elemenlist terakhir atau tidak ada elemen list terakhir */

void deleteAfterBarang(ListBarang &L, adrBarang Prec, adrBarang &P);
/* I.S. terdefinisi list barang yang mungkin kosong, elemen list P dan elemen list prec
   F.S. P adalah alamat dari alamat elemen list setelah prec
        yang akan dihapus dan elemen list setelah p akan terhubung
        langsung dengan prec atau tidak ada elemen list setelahnya */

// tampil 
void printBarang(ListBarang L);
/* I.S. terdefinisi list  yang mungkin kosong
   F.S. jika list tidak kosong menampilkan semua info yang ada pada list
        jika list kosong menampilkan pesan data barang kosong*/

// pencarian sebuah elemen list
adrBarang findBarang(ListBarang L, string id);
/* I.S. list dan kode mata kuliah terdefinisi
   F.S. mengembalikan alamat elemen yang cocok atau NULL jika tidak ditemukan */

// menghapus semua elemen barang
void hapusSemuaBarang(ListBarang &L);
/* I.S. terdefinisi list LMK yang mungkin kosong
   F.S. semua elemen list dihapus dan memorinya dikembalikan, list menjadi kosong */

#endif // BARANG_H_INCLUDED
