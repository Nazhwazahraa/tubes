#ifndef STAT_H 
#define STAT_H

#include "struct.h"

void statistik(){
    int solved = 0, unsolved = 0;
    int max=0, min=10;

    for(int i=0;i<jumlahKasus;i++){
        if(strcmp(daftarKasus[i].status, "Terpecahkan") == 0) solved++;
        else unsolved++;

        if(daftarKasus[i].tingkat > max) max = daftarKasus[i].tingkat;
        if(daftarKasus[i].tingkat < min) min = daftarKasus[i].tingkat;
    }

    printf("\nTotal Kasus: %d\n", jumlahKasus);
    printf("Kasus Terpecahkan: %d\n", solved);
    printf("Belum Terpecahkan: %d\n", unsolved);
    printf("Tingkat Kesulitan Tertinggi: %d\n", max);
    printf("Tingkat Kesulitan Terendah: %d\n", min);
}

#endif
