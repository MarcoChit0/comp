#include "hash.h"
#include <stdio.h>

int main(){
    hashInit();
    hashPrint();
    hashInsert("Robson", 1);
    hashInsert("Roberto", 1);
    hashInsert("Amanada", 1);
    hashInsert("Henrique", 1);
    hashInsert("Cleber", 1);
    hashInsert("Rodolfo", 1);
    hashInsert("Rocambole", 1);
    hashInsert("Rogério", 1);
    hashPrint();
    return 0;
}