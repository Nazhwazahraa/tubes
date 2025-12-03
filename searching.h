#ifndef SEARCH_H
#define SEARCH_H

#include <string.h>
#include "struct.h"

void cariKasus(int key){
    int ketemu = 0;
    for(int i=0;i<jumlahKasus;i++){
        if(daftarKasus[i].idKasus == key){
            printf("\nID: %d\n", daftarKasus[i].idKasus);
            printf("Judul: %s\n", daftarKasus[i].judul);
            printf("Status: %s\n", daftarKasus[i].status);
            printf("Tingkat: %d\n", daftarKasus[i].tingkat);
            printf("Tanggal: %d-%d-%d\n", daftarKasus[i].day, daftarKasus[i].month, daftarKasus[i].year);
            ketemu = 1;
            break;
        }
    }
    if(!ketemu) printf("Tidak ditemukan\n");
}

#endif
