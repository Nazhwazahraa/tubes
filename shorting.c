#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "shorting.h"
#include "searching.h"
#include "statistik.h"

void sortIDAsc() {
    for(int i = 0; i < jumlahKasus - 1; i++) {
        for(int j = 0; j < jumlahKasus - i - 1; j++) {
            if(daftarKasus[j].idKasus > daftarKasus[j+1].idKasus) {
                struct kasus temp = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = temp;
            }
        }
    }
}

void sortIDDesc() {
    for(int i = 0; i < jumlahKasus - 1; i++) {
        for(int j = 0; j < jumlahKasus - i - 1; j++) {
            if(daftarKasus[j].idKasus < daftarKasus[j+1].idKasus) {
                struct kasus temp = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = temp;
            }
        }
    }
}

void sortTingkatAsc() {
    for(int i = 0; i < jumlahKasus - 1; i++) {
        for(int j = 0; j < jumlahKasus - i - 1; j++) {
            if(daftarKasus[j].tingkat > daftarKasus[j+1].tingkat) {
                struct kasus temp = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = temp;
            }
        }
    }
}

void sortTingkatDesc() {
    for(int i = 0; i < jumlahKasus - 1; i++) {
        for(int j = 0; j < jumlahKasus - i - 1; j++) {
            if(daftarKasus[j].tingkat < daftarKasus[j+1].tingkat) {
                struct kasus temp = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = temp;
            }
        }
    }
}

void sortTanggalAsc() {
    for (int i = 0; i < jumlahKasus - 1; i++) {
        for (int j = 0; j < jumlahKasus - i - 1; j++) {

            int y1 = daftarKasus[j].year;
            int m1 = daftarKasus[j].month;
            int d1 = daftarKasus[j].day;

            int y2 = daftarKasus[j+1].year;
            int m2 = daftarKasus[j+1].month;
            int d2 = daftarKasus[j+1].day;

            if (y1 > y2 ||
               (y1 == y2 && m1 > m2) ||
               (y1 == y2 && m1 == m2 && d1 > d2)) {

                struct kasus t = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = t;
            }
        }
    }
}

void sortTanggalDesc() {
    for (int i = 0; i < jumlahKasus - 1; i++) {
        for (int j = 0; j < jumlahKasus - i - 1; j++) {

            int y1 = daftarKasus[j].year;
            int m1 = daftarKasus[j].month;
            int d1 = daftarKasus[j].day;

            int y2 = daftarKasus[j+1].year;
            int m2 = daftarKasus[j+1].month;
            int d2 = daftarKasus[j+1].day;

            if (y1 < y2 ||
               (y1 == y2 && m1 < m2) ||
               (y1 == y2 && m1 == m2 && d1 < d2)) {

                struct kasus t = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = t;
            }
        }
    }
}
