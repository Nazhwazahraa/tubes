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

struct kasus daftarKasus[100] = {
    {1, "Pembunuhan Misterius", "Belum Terpecahkan", 5, 12, 1, 2022},
    {2, "Pencurian Berlian", "Terpecahkan", 3, 5, 5, 2023},
    {3, "Perampokan Bank", "Dalam Investigasi", 4, 18, 7, 2023}
};

int jumlahKasus = 0;

struct admin {
    char username[50];
    char password[50];
    char role[20];
};

struct admin adm[4] = {
    {"detektif1", "12345", "admin"},
    {"detektif2", "54321", "admin"},
    {"user1", "11111", "user"},
    {"user2", "22222", "user"}
};

#endif
