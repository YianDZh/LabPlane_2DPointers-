#ifndef LAB_H
#define LAB_H
#include <iostream>
#include <ostream>
#include "assert.h"
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/two_d_functions/two_d_functions.h"
using namespace std;

int **init_lab(int* stations);
bool login(int** labs, int lab, int station, int id);
bool logout(int** labs, int* sizes, int id);

int **init_lab(int* stations){
    int ** lab = allocate_twod <int> (stations);
    init_twod (lab,stations, 0);
    return lab;
}

bool login(int** labs, int lab, int station, int id){
int current = read_twod <int> (labs, lab, station);
if (current==0){
write_twod <int> (labs, lab, station, id );
cout<<"Logged id: "<< id<< " in station: "<<station+1<< " ,at lab: "<<lab+1<<"\n";
return true;
}
else {
    cout<<"Station is use, try another!\n";
    return false;
}
}

bool logout(int** labs, int* sizes, int id){
int row , col;
bool condition = search_twod <int> (labs,sizes, id, row, col);
if (condition){
write_twod <int> (labs, row, col, 0);
cout<<"User id: "<<id<< " has Logged Out\n";
return true;
    }
cout<<"Not in use\n";
return false;
}
void lab_test (){}
#endif