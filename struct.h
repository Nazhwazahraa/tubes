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
    {1, "Bom Bali 2002", "Terpecahkan", 5, 12, 10, 2002},
    {2, "Pembunuhan Munir", "Belum Terpecahkan", 5, 7, 9, 2004},
    {3, "Kasus Ferdy Sambo (Brigadir J)", "Tepercahkan", 5, 8, 7, 2022},
    {4, "KM 50 (Laskar FPI)", "Terpecahkan", 4, 1, 10, 2022},
    {5, "Kanjuhuruan Tragedi", "Dalam Investigasi", 4, 7, 12, 2020},
    {6, "Kasus Ijazah Palsu Jokowi", "Hoax - Tidak Valid", 1, 1, 9, 2022},
    {7, "Korupsi BTS Komminfo", "Dalam Proses Hukum", 4, 10, 5, 2023},
    {8, "Kasus Robot Trading DNA Pro", "Terpecahkan", 3, 15, 3, 2024},
    {9, "Kasus Tambang Ilegal 2023", "Dalam Investigasi", 3, 2, 2, 2022},
    {10, "Korupsi Pertamina 2024", "Dalam Investigasi", 2, 5, 7, 2023},
};

int jumlahKasus = 10;

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

struct admin adm[4] = {
    {"detektif1", "12345", "admin"},
    {"detektif2", "54321", "admin"},
    {"detektif Kinara", "11111", "admin"},
    {"dekettif Nazhwa", "22222", "admin"}
};

struct user users[4] = {
    {"ara", "12345", "user"},
    {"awa", "54321", "user"},
    {"user1", "11111", "user"},
    {"user2", "22222", "user"}
};

#endif
