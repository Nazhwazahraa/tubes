#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "shorting.h"
#include "searching.h"
#include "statistik.h"
#include <windows.h>

int cariKasusBinary(int key) {
    int low = 0;
    int high = jumlahKasus - 1;

    while(low <= high) {
        int mid = low + (high - low) / 2;

        if(daftarKasus[mid].idKasus == key) {
            return mid;
        } 
        else if(daftarKasus[mid].idKasus < key) {
            low = mid + 1;
        } 
        else {
            high = mid - 1;
        }
    }
    return -1;
}

void hasilCariKasus(int found, int key) {
    if(found != -1) {

        printf("\n--------------------------------------------\n");
        printf("|               DATA KASUS                 |\n");
        printf("--------------------------------------------\n");
        printf("| ID Kasus   : %-28d |\n", daftarKasus[found].idKasus);
        printf("| Judul      : %-28s |\n", daftarKasus[found].judul);
        printf("| Status     : %-28s |\n", daftarKasus[found].status);
        printf("| Tingkat    : %-28d |\n", daftarKasus[found].tingkat);
        printf("| Tanggal    : %02d-%02d-%04d                 |\n",
                daftarKasus[found].day,
                daftarKasus[found].month,
                daftarKasus[found].year);
        printf("--------------------------------------------\n");

    } else {
        printf("\n--------------------------------------------\n");
        printf("|     Kasus dengan ID %d tidak ditemukan   |\n", key);
        printf("--------------------------------------------\n");
    }
}

