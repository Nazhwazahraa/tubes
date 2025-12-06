#ifndef STAT_H 
#define STAT_H

#include "struct.h"

void statistik() {
    int solved = 0, unsolved = 0;
    int max = 0, min = 10;

    for(int i = 0; i < jumlahKasus; i++){
        if(strcmp(daftarKasus[i].status, "Terpecahkan") == 0)
            solved++;
        else
            unsolved++;

        if(daftarKasus[i].tingkat > max) max = daftarKasus[i].tingkat;
        if(daftarKasus[i].tingkat < min) min = daftarKasus[i].tingkat;
    }

    printf("\n╔══════════════════════════════════════╗\n");
    printf("║              STATISTIK               ║\n");
    printf("╠══════════════════════════════════════╣\n");
    printf("║ Total Kasus              : %-10d║\n", jumlahKasus);
    printf("║ Kasus Terpecahkan        : %-10d║\n", solved);
    printf("║ Kasus Belum Terpecahkan  : %-10d║\n", unsolved);
    printf("║ Kesulitan Tertinggi      : %-10d║\n", max);
    printf("║ Kesulitan Terendah       : %-10d║\n", min);
    printf("╚══════════════════════════════════════╝\n");
}


#endif
