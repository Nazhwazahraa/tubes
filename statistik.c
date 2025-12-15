#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "shorting.h"
#include "searching.h"
#include "statistik.h"
#include <windows.h>

void statistik() {
    int solved = 0, unsolved = 0;
    int rendah = 0, sedang = 0, tinggi = 0;

    for(int i = 0; i < jumlahKasus; i++){
        
        if(strcmp(daftarKasus[i].status, "Terpecahkan") == 0)
            solved++;
        else
            unsolved++;

        if(daftarKasus[i].tingkat == 1)
            rendah++;
        else if(daftarKasus[i].tingkat == 2)
            sedang++;
        else if(daftarKasus[i].tingkat == 3)
            tinggi++;
    }

    printf("\n+==========================================+\n");
    printf("|                 STATISTIK                |\n");
    printf("|==========================================|\n");
    printf("| Total Kasus             : %-5d          |\n", jumlahKasus);
    printf("|==========================================|\n");
    printf("| STATUS KASUS                             |\n");
    printf("| - Terpecahkan           : %-5d          |\n", solved);
    printf("| - Belum Terpecahkan     : %-5d          |\n", unsolved);
    printf("|==========================================|\n");
    printf("| TINGKAT KESULITAN                        |\n");
    printf("| - Rendah  (1)           : %-5d          |\n", rendah);
    printf("| - Sedang  (2)           : %-5d          |\n", sedang);
    printf("| - Tinggi  (3)           : %-5d          |\n", tinggi);
    printf("+==========================================+\n");
}
