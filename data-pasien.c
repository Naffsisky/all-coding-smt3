#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;

struct pasien{
  int no_pasien;
  char nama[50];
  char nik[20];
  char alamat[50];
  char riwayat[50];
};

int main(){
struct pasien identitas1 = {1, "Naffsvn", "21081010278", "Penjaringan Sari 2", "Gerd"};
struct pasien identitas2 = {};
struct pasien identitas3 = {};
struct pasien identitas4 = {};
struct pasien identitas5 = {};

struct pasien identitas[] = {identitas1, identitas2, identitas3, identitas4, identitas5};
for (i=0; i<5; i++){
    printf("NO PASIEN\t: %d\n", identitas[i].no_pasien);
    printf("NAMA\t\t: %s\n", identitas[i].nama);
    printf("NIK\t\t: %s\n", identitas[i].nik);
    printf("ALAMAT\t\t: %s\n", identitas[i].alamat);
    printf("RIWAYAT KELUHAN\t: %s\n\n", identitas[i].riwayat);
  }
}

/*

Mulai
Mendeklarasikan i sebagai integer
Membuat struct pasien berisi :
no_pasien dengan tipe integer
nama dengan tipe char dan array 50
nik dengan tipe char dan array 20
alamat dengan tipe char dan array 50
riwayat dengan tipe char dan array 50
Membuat program inti
Membuat data struct dari pasien dengan nama identitas1, identitas2, dst.
Membuat pengumpulan data menggunakan array dengan nama identitas
Membuat perulangan for dengan syarat i = 0, jika i < 5, dan i++
Menampilkan isi data yang telah di masukan
Selesai
*/
