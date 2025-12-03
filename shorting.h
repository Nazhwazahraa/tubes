#ifndef SORTING_H
#define SORTING_H

#include "struct.h"

void sortIDAsc(){
    for(int i=0;i<jumlahKasus-1;i++){
        for(int j=0;j<jumlahKasus-i-1;j++){
            if(daftarKasus[j].idKasus > daftarKasus[j+1].idKasus){
                struct kasus t = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = t;
            }
        }
    }
}

void sortTingkatDesc(){
    for(int i=0;i<jumlahKasus-1;i++){
        for(int j=0;j<jumlahKasus-i-1;j++){
            if(daftarKasus[j].tingkat < daftarKasus[j+1].tingkat){
                struct kasus t = daftarKasus[j];
                daftarKasus[j] = daftarKasus[j+1];
                daftarKasus[j+1] = t;
            }
        }
    }
}

#endif
