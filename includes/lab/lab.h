#ifndef LAB_H
#define LAB_H
#include <iostream>
#include <ostream>
#include "assert.h"
using namespace std;

int **init_lab(int* stations);
bool login(int** labs, int lab, int station, int id);
bool logout(int** labs, int* sizes, int id);

int **init_lab(int* stations){
    return nullptr;
}
bool login(int** labs, int lab, int station, int id){
    return false;
}
bool logout(int** labs, int* sizes, int id){
    return false;
}
#endif