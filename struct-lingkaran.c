#include <stdio.h>

struct lingkaran {
int jari_jari;
float luas;
float keliling;
};

int main(){
struct lingkaran circle[2];
float pi = 3.14;

// LINGKARAN A
// Multiply data tinggal ganti angka
printf("LINGKARAN A\n\n");
circle[0].jari_jari = 3;
circle[0].luas = pi * circle[0].jari_jari * circle[0].jari_jari;
circle[0].keliling = 2 * pi * circle[0].jari_jari;

printf("jari-jari lingkaran A : %d\n", circle[0].jari_jari);
printf("luas lingkaran A : %f\n", circle[0].luas);
printf("keliling lingkaran A : %f\n", circle[0].keliling);
}
