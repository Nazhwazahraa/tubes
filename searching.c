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

        printf("\n+------------------------------------------+\n");
        printf("| HASIL PENCARIAN ID : %-18d  |\n", key);
        printf("+------------------------------------------+\n");
        printf("| ID Kasus   : %-26d  |\n", daftarKasus[found].idKasus);
        printf("| Judul      : %-26s  |\n", daftarKasus[found].judul);
        printf("| Status     : %-26s  |\n", daftarKasus[found].status);
        printf("| Tingkat    : %-26d  |\n", daftarKasus[found].tingkat);
        printf("| Tanggal    : %02d-%02d-%04d                  |\n",
               daftarKasus[found].day,
               daftarKasus[found].month,
               daftarKasus[found].year);
        printf("+------------------------------------------+\n");

    } else {
        printf("+------------------------------------------+\n");
        printf("| Kasus dengan ID %-4d tidak ditemukan     |\n", key);
        printf("+------------------------------------------+\n");
    }
}

void cariKasusByStatus(char status[]) {
    int found = 0;

    printf("\n+------------------------------------------+\n");
    printf("| HASIL PENCARIAN STATUS : %-13s   |\n", status);
    printf("+------------------------------------------+\n");

    for (int i = 0; i < jumlahKasus; i++) {
        if (strcmp(daftarKasus[i].status, status) == 0) {
            found = 1;

            printf("| ID Kasus   : %-26d  |\n", daftarKasus[i].idKasus);
            printf("| Judul      : %-26s  |\n", daftarKasus[i].judul);
            printf("| Status     : %-26s  |\n", daftarKasus[i].status);
            printf("| Tingkat    : %-26d  |\n", daftarKasus[i].tingkat);
            printf("| Tanggal    : %02d-%02d-%04d                  |\n",
                   daftarKasus[i].day,
                   daftarKasus[i].month,
                   daftarKasus[i].year);
            printf("+------------------------------------------+\n");
        }
    }

    if (!found) {
        printf("| Tidak ada kasus dengan status %-8s   |\n", status);
        printf("+------------------------------------------+\n");
    }
}

void cariKasusByTingkat(int tingkat)
{
    int found = 0;

    printf("\n+------------------------------------------+\n");
    printf("| HASIL PENCARIAN TINGKAT : %-12d   |\n", tingkat);
    printf("+------------------------------------------+\n");

    for (int i = 0; i < jumlahKasus; i++)
    {
        if (daftarKasus[i].tingkat == tingkat)
        {
            found = 1;

            printf("| ID Kasus   : %-26d  |\n", daftarKasus[i].idKasus);
            printf("| Judul      : %-26s  |\n", daftarKasus[i].judul);
            printf("| Status     : %-26s  |\n", daftarKasus[i].status);
            printf("| Tingkat    : %-26d  |\n", daftarKasus[i].tingkat);
            printf("| Tanggal    : %02d-%02d-%04d                  |\n",
                   daftarKasus[i].day,
                   daftarKasus[i].month,
                   daftarKasus[i].year);
            printf("+------------------------------------------+\n");
        }
    }

    if (!found)
    {
        printf("| Kasus dengan tingkat %-16d |\n", tingkat);
        printf("| Tidak ditemukan                  |\n");
        printf("+------------------------------------------+\n");
    }
}
