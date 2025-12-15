#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "shorting.h"
#include "searching.h"
#include "statistik.h"

struct kasus daftarKasus[100] = {
    {1, "Bom Bali 2002", "Terpecahkan", 3, 12, 10, 2002},
    {2, "Pembunuhan Munir", "Belum Terpecahkan", 3, 7, 9, 2004},
    {3, "Kasus Ferdy Sambo", "Terpecahkan", 3, 8, 7, 2022},
    {4, "KM 50 (Laskar FPI)", "Terpecahkan", 3, 1, 10, 2022},
    {5, "Kanjuruhan Tragedi", "Dalam Investigasi", 3, 7, 12, 2020},
    {6, "Kasus Ijazah Palsu Jokowi", "Hoax - Tidak Valid", 1, 1, 9, 2022},
    {7, "Korupsi BTS Kominfo", "Dalam Proses Hukum", 3, 10, 5, 2023},
    {8, "Kasus Robot Trading DNA Pro", "Terpecahkan", 2, 15, 3, 2024},
    {9, "Kasus Tambang Ilegal 2023", "Dalam Investigasi", 2, 2, 2, 2022},
    {10, "Korupsi Pertamina 2024", "Dalam Investigasi", 2, 5, 7, 2023},
    {11, "Ryan Pembunuh Berantai", "Terpecahkan", 3, 12, 7, 2008},
    {12, "Kasus Angelina Bali", "Belum Terpecahkan", 2, 10, 6, 2015},
    {13, "Kasus Vina Cirebon", "Dalam Investigasi", 3, 27, 8, 2016},
    {14, "Kasus Mirna Kopi Sianida", "Terpecahkan", 3, 6, 1, 2016},
    {15, "Kasus Akseyna UI", "Dalam Investigasi", 3, 26, 3, 2015},
    {16, "Kasus Arya Daru", "Belum Terpecahkan", 3, 8, 7, 2025},
    {17, "Kasus Mutilasi Siti Amelia", "Terpecahkan", 3, 14, 8, 2025},
};

int jumlahKasus = 17;

struct admin adm[50] = {
    {"detektif1", "12345", "admin"},
    {"detektif2", "54321", "admin"},
    {"detektif_kinara", "11111", "admin"},
    {"detektif_nazhwa", "22222", "admin"},
    {"polisi1", "12345", "user"},
    {"polisi2", "54321", "user"},
    {"polisi_kinara", "11111", "user"},
    {"polisi_nazhwa", "22222", "user"}
};

int jumlahAkun = 8;
