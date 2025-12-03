#include "func.h"
#include <stdio.h>

int main(){
    char role[20];
    if(login(role)){
        menuUtama(role);
    } else {
        printf("Login gagal\n");
    }
    return 0;
}
