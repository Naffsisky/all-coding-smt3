#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/* 
Andi memiliki akun bank dengan dengan saldo awal 500rb. Akun bank Andi dapat melakukan transfer dana, penarikan dana, dan deposit dana.
Simulasikan akun bank milik andi dengan menerapkan pointer dan fungsi.
*/

// Minimal saldo tersisa 25000

int i, z, pin, pilihan, deposit, total, tariktunai, nominaltf, koderek;
int saldo = 500000; 
int *ptr_saldo = &saldo;
char rektujuan[16];

void akun(){
    login:
    printf("Silahkan masukan kode pin anda : ");
    scanf("%d", &pin);
    if (pin == 123456){
        printf("Login SUKSES!\n");
        z = 0;
    }
    else{
        system("clear");
        printf("Login GAGAL!\n");
        z = 1;
    }
}
void menu(){
    system("clear");
    printf("********************************\n");
    printf("              MENU              \n");
    printf("1. Transfer\n");
    printf("2. Penarikan Tunai\n");
    printf("3. Deposit Tunai\n");
    printf("4. Cek Saldo\n");
    printf("5. EXIT\n");
    printf("********************************\n");
}
void transfer(){
    ulang:
    system("clear");
    printf("Kode Bank : \n");
    printf("BCA\t(427 XXXXXX)\t\tBNI\t(009 XXXXXX)\nBRI\t(002 XXXXXX)\t\tMandiri\t(422 XXXXXX)\n\n");
    printf("1. BCA\n");
    printf("2. BNI\n");
    printf("3. BRI\n");
    printf("4. Mandiri\n\n");
    printf("Masukan kode bank tujuan : ");
    scanf("%d", &koderek);
    if (koderek == 1){
        koderek = 427;
    }
    else if (koderek == 2){
        koderek = 9;
    }
    else if (koderek == 3){
        koderek = 2;
    }
    else if (koderek == 4){
        koderek = 422;
    }
    else{
        system("clear");
        printf("Kode bank tidak ditemukan!\n");
        sleep(3);
        goto ulang;
    }
    system("clear");
    fflush(stdin);
    printf("Maks nomor rekening 16 digit\n");
    printf("Masukan nomor rekening tujuan (Tanpa kode bank) : ");
    gets(rektujuan);
    while (strlen(rektujuan) <= 3 || strlen(rektujuan) > 16){
        system("clear");
        printf("Masukan nomor rekening dengan benar!\n");
        printf("Masukan nomor rekening tujuan : ");
        gets(rektujuan);
    }
    system("clear");
    printf("Masukan nominal yang akan di transfer : ");
    scanf("%d", &nominaltf);
    saldo = saldo - nominaltf;
    if (saldo >= 25000){
        system("clear");
        printf("\nTransfer dengan tujuan\n\n");
        if (koderek == 2 || koderek == 3 || koderek == 4){
            printf("Kode Bank \t\t: 00%d\n", koderek);
            printf("No Rekening \t\t: 00%d %s\n", koderek, rektujuan);
            

        }
        else{
            printf("Kode Bank \t\t: %d\n", koderek);
            printf("No Rekening \t\t: %d %s\n", koderek, rektujuan);
        }
        printf("Nominal \t\t: %d\n", nominaltf);
        printf("\nBerhasil!\n"); 
    }
    else{
        system("clear");
        printf("Mohon maaf saldo anda tidak cukup!\n");
        saldo = saldo + nominaltf;
        printf("Apakah ingin melajutkan transfer : \n");
        printf("1. YA\n");
        printf("2. TIDAK\n");
        printf("Masukan pilihan : ");
        scanf("%d", &pilihan);
        if (pilihan == 1){
            goto ulang;
        }
        else{
            system("clear");
        }
    }
}
void tarik(){
    system("clear");
    printf("Silahkan masukan jumlah yang ingin ditarik!\n");
    printf("1. 50.000\n");
    printf("2. 100.000\n");
    printf("3. 250.000\n");
    printf("4. 500.000\n");
    printf("5. Jumlah lain\n");
    printf("Masukan pilihan : ");
    scanf("%d", &pilihan);
    system("clear");
    if (pilihan == 1){
        if (saldo >= 75000){
            saldo = saldo - 50000;
            printf("Tarik tunai sebesar 50.000\n");
            printf("Total : %d", *ptr_saldo);
        }
        else{
            printf("Mohon maaf saldo anda tidak cukup!\n");
        }
    }
    else if (pilihan == 2){
        if (saldo >= 125000){
            saldo = saldo - 100000;
            printf("Tarik tunai sebesar 100.000\n");
            printf("Total : %d", *ptr_saldo);
        }
        else{
            printf("Mohon maaf saldo anda tidak cukup!\n");
        }
    }
    else if (pilihan == 3){
        if (saldo >= 275000){
            saldo = saldo - 250000;
            printf("Tarik tunai sebesar 250.000\n");
            printf("Total : %d", *ptr_saldo);
        }
        else{
            printf("Mohon maaf saldo anda tidak cukup!\n");
        }
    }
    else if (pilihan == 4){
        if (saldo >= 525000){
            saldo = saldo - 500000;
            printf("Tarik tunai sebesar 500.000\n");
            printf("Total : %d", *ptr_saldo);
        }
        else{
            printf("Mohon maaf saldo anda tidak cukup!\n");
        }
    }
    else if (pilihan == 5){
        kurang:
        system("clear");
        printf("Maksimal penarikan adalah 10.000.000!\n");
        printf("Masukan nominal yang akan ditarik : ");
        scanf("%d", &tariktunai);
        if (tariktunai >= 10000000){
            system("clear");
            printf("Maksimal penarikan adalah 10.000.000!");
            goto kurang;
        }
        else if (tariktunai < 50000){
            system("clear");
            printf("Minimal penarikan adalah 50.000!\n");
            goto kurang;
        }
        saldo = saldo - tariktunai;
        if (saldo < 25000){
            system("clear");
            printf("Mohon maaf saldo anda tidak cukup!\n");
            saldo = saldo + tariktunai;
        }
        else{
            system("clear");
            printf("Tarik tunai sebesar %d\n", tariktunai);
            printf("Total : %d", *ptr_saldo);
        }
    }
    else{
        printf("Tidak ada pilihan yang dipilih!");
    }
}
void depo(){
    system("clear");
    printf("\nSaldo anda : %d", *ptr_saldo);
    printf("\nMasukan nominal yang akan di deposit : ");
    scanf("%d", &deposit);
    saldo = saldo + deposit;
    system("clear");
    printf("\nJumlah deposit : %d", deposit);
    printf("\nTotal : %d", saldo);

}
void ceksaldo(){
    system("clear");
    printf("\nSaldo anda : %d", *ptr_saldo);
}
int main(){
    printf("Silahkan Login!\n");
    akun();
    if (z == 1){
        for (i = 1; i < 3; i++){
            akun();
            if (z == 1){
                continue;
            }
            else{
                break;
            }
        }
    }
    if (z == 1){
        printf("Anda telah mencoba 3 kali!\n");
        printf("Mohon maaf akun anda telah diblokir!\n");
        return 0;
    }
    balik:
    menu();
    printf("Silahkan pilih : ");
    scanf("%d", &pilihan);
    if (pilihan == 1){
        transfer();
    }
    else if (pilihan == 2){
        tarik();
    }
    else if (pilihan == 3){
        depo();
    }
    else if (pilihan == 4){
        saldo:
        ceksaldo();
        printf("\n\n1. Cek kembali\n");
        printf("2. Kembali ke MENU\n");
        printf("3. EXIT\n");
        printf("Silahkan pilih : ");
        scanf("%d", &pilihan);
        if (pilihan == 1){
            goto saldo;
        }
        else if (pilihan == 2){
            goto balik;
        }
        else if (pilihan == 3){
            printf("\n\nTerima Kasih :)");
            return 0;
        }
        else{
            return 0;
        }
    }
    else if (pilihan == 5){
        system("clear");
        printf("\n\nTerima Kasih! :)");
        return 0;
    }
    else{
        printf("Pilihan tidak ada!");
        goto balik;
    }
    printf("\n\nApakah ingin melajutkan transaksi : \n");
    printf("1. YA\n");
    printf("2. TIDAK\n");
    printf("Masukan pilihan : ");
    scanf("%d", &pilihan);
    if (pilihan == 1){
        goto balik;
    }
    else if (pilihan == 2){
        system("clear");
        printf("\n\nTerima Kasih! :)");
        return 0;
    }
    else{
        return 0;
    }
}
