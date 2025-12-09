#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"
#include "func.h"
#include "shorting.h"
#include "searching.h"
#include "statistik.h"
#include <windows.h>

int main(){
    setConsoleOutputCP(CP_UTF8);
    setConsoleCP(CP_UTF8);
    system("chcp 65001 > nul");
    tampilMenu();
    return 0;
}