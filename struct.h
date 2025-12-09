#ifndef DATA_H
#define DATA_H

struct kasus {
    int idKasus;
    char judul[100];
    char status[50];
    int tingkat;
    int day;
    int month;
    int year;
};

struct admin {
    char username[50];
    char password[50];
    char role[20];
};

struct user {
    char username[50];
    char password[50];
    char role[20];
};

extern struct kasus daftarKasus[100];
extern int jumlahKasus;

extern struct admin adm[4];
extern struct user users[4];

#endif
