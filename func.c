#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "shorting.h"
#include "searching.h"
#include "statistik.h"


int login(char role[]){
    char u[50], p[50];

    printf("+======================================+\n");
    printf("|               LOGIN                  |\n");
    printf("+======================================+\n");
    printf("| Username:                            |\n");
    scanf("%s", u);
    printf("| Password:                            |\n");
    scanf("%s", p);
    printf("+======================================+\n");

        for (int i = 0; i < 4; i++) {
            if (strcmp(u, adm[i].username) == 0 && strcmp(p, adm[i].password) == 0) {

                strcpy(role, adm[i].role);
                printf("\n>> Login berhasil! Selamat datang %s.\n");
                return 1;
            }
        }

        for (int i = 0; i < 4; i++) {
            if (strcmp(u, users[i].username) == 0 && strcmp(p, users[i].password) == 0) {

                strcpy(role, users[i].role);
                printf("\n>> Login berhasil! Selamat datang %s.\n");
                return 1;
            }
        }

        printf("\n!! Username atau password salah.\n");

    return 0;
}

void tampilData(){
    printf("+=====================================================================+\n");
    printf("| ID\t|        JUDUL\t\t|     STATUS\t\t| TINGKAT\t\t|   TANGGAL\t|\n");
    printf("+=====================================================================+\n");

    for(int i=0;i<jumlahKasus;i++){
        printf(" %d.\t|  %s\t\t|   %s\t\t| (Tingkat %d)\t\t|   %d-%d-%d\t|\n",
               daftarKasus[i].idKasus,
               daftarKasus[i].judul,
               daftarKasus[i].status,
               daftarKasus[i].tingkat,
               daftarKasus[i].day, daftarKasus[i].month, daftarKasus[i].year);
    }
    printf("+=====================================================================+\n");
}

void tambahKasus(){
    printf("+===============================================+\n");
    printf("|               TAMBAH KASUS                    |\n");
    printf("+===============================================+\n");
    printf("ID: \n");
    scanf("%d",&daftarKasus[jumlahKasus].idKasus);
    printf("Judul: \n");
    scanf(" %[^\n]", daftarKasus[jumlahKasus].judul);
    printf("Status: \n");
    scanf(" %[^\n]", daftarKasus[jumlahKasus].status);
    printf("Tingkat: \n");
    scanf("%d",&daftarKasus[jumlahKasus].tingkat);
    printf("Tanggal (dd-mm-yyyy): \n");
    scanf("%d-%d-%d",&daftarKasus[jumlahKasus].day,&daftarKasus[jumlahKasus].month,&daftarKasus[jumlahKasus].year);
    
    printf("\nKasus sudah berhasil ditambahkan\n");

    jumlahKasus++;
}

void editKasus(){
    int id, pilihan, found = 0;

    printf("Masukkan ID kasus : ");
    scanf("%d",&id);

    for (int i = 0; i < jumlahKasus; i++) {
        if (daftarKasus[i].idKasus == id) {
            found = 1;

    printf("+===============================================+\n");
    printf("|                 EDIT KASUS                    |\n");
    printf("+===============================================+\n");

    printf(" ID Kasus : %d ditemukan!!!  \n", daftarKasus[i].idKasus);

    do {
        printf("======= Masukkan Data Baru ========\n");
        printf("| [1] Edit Judul                  |\n");
        printf("| [2] Edit Status                 |\n");
        printf("| [3] Edit Tingkat                |\n");
        printf("| [4] Edit Tanggal                |\n");
        printf("| [0] Selesai                     |\n");
        printf("===================================\n");
        printf("Masukkan pilihan : ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
                    case 1: {
                        printf("Judul lama: %s\n", daftarKasus[i].judul);
                        printf("Masukkan judul baru: ");
                        scanf(" %[^\n]", daftarKasus[i].judul);
                        printf("Judul berhasil diperbarui!\n");
                        break;
                    }
                    case 2: {
                        printf("Status lama: %s\n", daftarKasus[i].status);
                        printf("Masukkan status baru: ");
                        scanf(" %[^\n]", daftarKasus[i].status);
                        printf("Status berhasil diperbarui!\n");
                        break;
                    }
                    case 3: {
                        printf("Tingkat lama: %d\n", daftarKasus[i].tingkat);
                        printf("Masukkan tingkat baru: ");
                        scanf("%d", &daftarKasus[i].tingkat);
                        printf("Tingkat berhasil diperbarui!\n");
                        break;
                    }
                    case 4: {
                        printf("Tanggal lama: %d/%d/%d\n",
                               daftarKasus[i].day,
                               daftarKasus[i].month,
                               daftarKasus[i].year);

                        printf("Masukkan tanggal baru (dd mm yyyy): ");
                        scanf("%d %d %d",
                            &daftarKasus[i].day,
                            &daftarKasus[i].month,
                            &daftarKasus[i].year);

                        printf("Tanggal berhasil diperbarui!\n");
                        break;
                    }
                    case 0:
                        printf("Edit selesai.\n");
                        break;
                    default:
                        printf("Pilihan tidak valid! Coba lagi.\n");
                }

            } while (pilihan != 0);

            return;
        }
    }

    if (!found) {
        printf("ID Kasus %d tidak ditemukan!\n", id);
        }
    }

void deleteKasus(){
    int id, pos = -1;
    char konfirmasi;

    printf("Masukkan ID Kasus yang ingin dihapus: ");
    scanf("%d", &id);

    for (int i = 0; i < jumlahKasus; i++) {
        if (daftarKasus[i].idKasus == id) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        printf("\n========== Hapus Kasus ==========+\n");
        printf("|                                  |\n");
        printf("|     ID Kasus : %d ditemukan!     |\n", daftarKasus[pos].idKasus);
        printf("|                                  |\n");
        printf("===================================+\n");
        printf("Detail Kasus:\n");
        printf("----------------------------------\n");
        printf("Judul   : %s\n", daftarKasus[pos].judul);
        printf("Status  : %s\n", daftarKasus[pos].status);
        printf("Tingkat : %d\n", daftarKasus[pos].tingkat);
        printf("Tanggal : %d/%d/%d\n",
               daftarKasus[pos].day,
               daftarKasus[pos].month,
               daftarKasus[pos].year);
        printf("----------------------------------\n");
        printf("Yakin ingin menghapus? (Y/N): ");
        getchar();
        scanf("%c", &konfirmasi);

        if (konfirmasi == 'Y' || konfirmasi == 'y') {

            for (int i = pos; i < jumlahKasus - 1; i++) {
                daftarKasus[i] = daftarKasus[i + 1];
            }
            jumlahKasus--;

            printf("\nKasus berhasil dihapus!\n");

        } else {
            printf("\nPenghapusan dibatalkan.\n");
        }

    } else {
        printf("ID Kasus %d tidak ditemukan!\n", id);
    }
}

void sortingMenu(){
    int pilihan;

    printf("\n=========== SORTING KASUS ============+\n");
    printf("|   Pilih metode sorting tanggal:       |\n");
    printf("|---------------------------------------|\n");
    printf("|  [1] Tanggal Ascending (lama → baru)  |\n");
    printf("|  [2] Tanggal Descending (baru → lama) |\n");
    printf("========================================+\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan);

    if (pilihan == 1)
        sortTanggalAsc();
    else if (pilihan == 2)
        sortTanggalDesc();
    else {
        printf("Pilihan tidak valid!\n");
        return;
    }

    printf("\nData berhasil diurutkan!\n\n");
    tampilData();
}

void searchingMenu(){
    int key;
    printf("Masukkan ID Kasus: ");
    scanf("%d", &key);

    int found = cariKasusBinary(key);
    hasilCariKasus(found, key);
}

void statistikMenu(){
    statistik();
}


void menuUtama(char role[]) {
    int pil;

    do {
        printf("\n=============================================\n");
        printf("                MENU UTAMA                  \n");
        printf("=============================================\n");
        printf("| Silakan pilih opsi di bawah:              |\n");
        printf("|-------------------------------------------|\n");
        printf("| [1] Lihat Data Kasus                      |\n");
        printf("| [2] Sorting Kasus                         |\n");
        printf("| [3] Searching Kasus                       |\n");

        if(strcmp(role, "admin") == 0){
            printf("|-------------------------------------------|\n");
            printf("| ADMIN MENU                                |\n");
            printf("| [4] Tambah Kasus                          |\n");
            printf("| [5] Edit Kasus                            |\n");
            printf("| [6] Hapus Kasus                           |\n");
            printf("| [7] Statistik Kasus                       |\n");
            printf("| [8] Logout                                |\n");
        } else {
            printf("|-------------------------------------------|\n");
            printf("| [4] Logout                                |\n");
        }

        printf("=============================================\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pil);

        if(strcmp(role,"admin") == 0){
            switch(pil){
                case 1: tampilData(); break;
                case 2: sortingMenu(); break;
                case 3: searchingMenu(); break;
                case 4: tambahKasus(); break;
                case 5: editKasus(); break;
                case 6: deleteKasus(); break;
                case 7: statistikMenu(); break;
                case 8: 
                    printf("Logout berhasil.\n");
                    break;
                default:
                    printf("Pilihan tidak valid!\n");
            }
        } else {
            switch(pil){
                case 1: tampilData(); break;
                case 2: sortingMenu(); break;
                case 3: searchingMenu(); break;
                case 4:
                    printf("Logout berhasil.\n");
                    break;
                default:
                    printf("Pilihan tidak valid!\n");
            }
        }

    } while( (strcmp(role,"admin")==0 && pil!=8) ||
             (strcmp(role,"user")==0  && pil!=4) );
}

void tampilMenu() {
    int pilihan;
    char role[20];

    do {
        printf("\n=================================================\n");
        printf("                  SELAMAT DATANG                 \n");
        printf("=================================================\n");
        printf("|  Silakan pilih menu:                           |\n");
        printf("|                                                 |\n");
        printf("|   [1] Login                                     |\n");
        printf("|   [0] Keluar                                    |\n");
        printf("|                                                 |\n");
        printf("=================================================\n");
        printf("Masukkan pilihan Anda : ");
        scanf("%d", &pilihan);

        switch(pilihan) {
            case 1:
                if(login(role)) {
                    menuUtama(role);
                }
                break;
            case 0:
                printf("\nTerima kasih sudah menggunakan program!\n");
                return;
            default:
                printf("\n!! Pilihan tidak tersedia, coba lagi.\n");
        }

    } while (pilihan != 0);
}