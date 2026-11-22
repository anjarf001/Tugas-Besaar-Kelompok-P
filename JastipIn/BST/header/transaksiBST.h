#ifndef TRANSAKSIBST_H_INCLUDED
#define TRANSAKSIBST_H_INCLUDED
#include <string>
#include <iostream>

using namespace std;

struct infotypeTransaksi
{
    string namaPelanggan;
    string idPenyedia; //menghubungkan transaksi dengan parent(penyedia jastip)
    string idBarang; // menghubungkan transaksi dengam child(barang)
    int jumlahBarang;
    int hargaSatuan; //Key
    int totalHarga; // hasil dari jumlahBarang * hargaSatuan
    string statusBayar; // contoh: "Lunas" atau "Belum Lunas"
};

// pointer adrTransaksi: penunjuk alamat memori menuju suatu node di BST
typedef  struct nodeTransaksi *adrTransaksi;   

// kerangka dari elemen node
struct nodeTransaksi
{
    infotypeTransaksi info; //menyimpan data transaksi
    adrTransaksi left; // pointer ke anak kiri(hargsatuan lebih kecil)
    adrTransaksi right; // pointer ke anak kanan(hargsatuan lebih besar)
};

// wadah utama BST yang menyimpan alamat akar(root) 
struct TreeTransaksi
{
      adrTransaksi root;
};

//primitif
// inisialisasi tree baru dalam keadaan kosong (root = NULL)
void createTreeTransaksi(TreeTransaksi &T);
// Mengecek apakah tree masih kosong (mengembalikan true jika root == NULL)
bool isEmptyTreeTransaksi(TreeTransaksi T);
// Alokasi memori untuk membuat satu node transaksi baru beserta datanya (left & right = NULL)
adrTransaksi createNodeTransaksi(infotypeTransaksi x);
// menghapus memori node yang sudah tidak terpakai agar tidak terjadi memory leak
void dealokasiTransaksi(adrTransaksi &P);

//insert
void insertTransaksi(adrTransaksi &root, adrTransaksi P);


// search
// Mencari node transaksi berdasarkan key hargaSatuan (lebih cepat karena membagi ruang pencarian)
adrTransaksi findTransaksi(adrTransaksi root, int hargaSatuan);
// Mencari transaksi dengan hargaSatuan termurah (menelusuri cabang paling kiri)
adrTransaksi findMinTransaksi(adrTransaksi root);
// Mencari transaksi dengan hargaSatuan termahal (menelusuri cabang paling kanan)
adrTransaksi findMaxTransaksi(adrTransaksi root);


// delete
void deleteTransaksi(adrTransaksi &root, int hargaSatuan);

// traversal
// Menampilkan detail satu data transaksi agar tidak menulis cout berulang kali
void printInfoTransaksi(infotypeTransaksi x);
// Traversal Left -> Root -> Right: menampilkan transaksi TERURUT dari hargaSatuan termurah ke termahal
void inOrderTransaksi(adrTransaksi root);
// Traversal Root -> Left -> Right: menampilkan dari akar dulu, cocok untuk melihat struktur hirarki tree
void preOrderTransaksi(adrTransaksi root);
// Traversal Left -> Right -> Root: memproses anak terlebih dahulu sebelum parent
void postOrderTransaksi(adrTransaksi root);

// pendukung
// Menghitung total seluruh node transaksi di dalam BST (bisa dipakai untuk fungsional total transaksi aplikasi)
int countNodeTransaksi(adrTransaksi root);
// Menghitung tinggi/kedalaman maksimum BST untuk mengetahui keseimbangan tree
int heightTransaksi(adrTransaksi root);

#endif // NILAIBST_H_INCLUDED
