#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "sorting.h"
#include "searching.h"
#include "statistik.h"

int login(char role[]){
    char u[50], p[50];
    printf("Username: ");
    scanf("%s", u);
    printf("Password: ");
    scanf("%s", p);

    for(int i=0;i<4;i++){
        if(strcmp(u, adm[i].username)==0 && strcmp(p, adm[i].password)==0){
            strcpy(role, adm[i].role);
            return 1;
        }
    }
    return 0;
}

void tampilData(){
    for(int i=0;i<jumlahKasus;i++){
        printf("%d. %s - %s (Tingkat %d) %d/%d/%d\n",
               daftarKasus[i].idKasus,
               daftarKasus[i].judul,
               daftarKasus[i].status,
               daftarKasus[i].tingkat,
               daftarKasus[i].day, daftarKasus[i].month, daftarKasus[i].year);
    }
}

void tambahKasus(){
    printf("ID: ");
    scanf("%d",&daftarKasus[jumlahKasus].idKasus);
    printf("Judul: ");
    scanf(" %[^\n]", daftarKasus[jumlahKasus].judul);
    printf("Status: ");
    scanf(" %[^\n]", daftarKasus[jumlahKasus].status);
    printf("Tingkat: ");
    scanf("%d",&daftarKasus[jumlahKasus].tingkat);
    printf("Tanggal (dd mm yyyy): ");
    scanf("%d %d %d",&daftarKasus[jumlahKasus].day,&daftarKasus[jumlahKasus].month,&daftarKasus[jumlahKasus].year);

    jumlahKasus++;
}

void editKasus(){
    int id;
    printf("ID edit: ");
    scanf("%d",&id);

    for(int i=0;i<jumlahKasus;i++){
        if(daftarKasus[i].idKasus == id){
            printf("Judul baru: ");
            scanf(" %[^\n]", daftarKasus[i].judul);
            printf("Status baru: ");
            scanf(" %[^\n]", daftarKasus[i].status);
            printf("Tingkat baru: ");
            scanf("%d",&daftarKasus[i].tingkat);
            return;
        }
    }
}

void deleteKasus(){
    int id,pos=-1;
    printf("ID hapus: ");
    scanf("%d",&id);

    for(int i=0;i<jumlahKasus;i++){
        if(daftarKasus[i].idKasus == id){
            pos=i;
            break;
        }
    }

    if(pos!=-1){
        for(int i=pos;i<jumlahKasus-1;i++){
            daftarKasus[i]=daftarKasus[i+1];
        }
        jumlahKasus--;
    }
}

void sortingMenu(){
    int pil;
    printf("1. Sort ID Asc\n2. Sort Tingkat Desc\n");
    scanf("%d",&pil);

    if(pil==1) sortIDAsc();
    else sortTingkatDesc();

    tampilData();
}

void searchingMenu(){
    int k;
    printf("Masukkan ID: ");
    scanf("%d",&k);
    cariKasus(k);
}

void statistikMenu(){
    statistik();
}

void menuUtama(char role[]){
    int pil;
    do{
        printf("\n1. Lihat\n2. Sorting\n3. Searching\n");
        if(strcmp(role,"admin")==0){
            printf("4. Tambah\n5. Edit\n6. Hapus\n7. Statistik\n8. Logout\n");
        } else {
            printf("4. Logout\n");
        }

        scanf("%d",&pil);

        if(strcmp(role,"admin")==0){
            switch(pil){
                case 1: tampilData(); break;
                case 2: sortingMenu(); break;
                case 3: searchingMenu(); break;
                case 4: tambahKasus(); break;
                case 5: editKasus(); break;
                case 6: deleteKasus(); break;
                case 7: statistikMenu(); break;
            }
        } else {
            switch(pil){
                case 1: tampilData(); break;
                case 2: sortingMenu(); break;
                case 3: searchingMenu(); break;
            }
        }
    } while( (strcmp(role,"admin")==0 && pil!=8) || (strcmp(role,"user")==0 && pil!=4) );
}
