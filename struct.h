#ifndef STRUCT_H
#define STRUCT_H

struct kasus {
    int idKasus;
    char judul[100];
    char status[50];
    int tingkat;
    int day;
    int month;
    int year;
};
extern struct kasus daftarKasus[100];
extern int jumlahKasus;

struct admin {
    char username[50];
    char password[50];
    char role[20];
};
extern struct admin adm[50];
extern int jumlahAkun;

#endif
