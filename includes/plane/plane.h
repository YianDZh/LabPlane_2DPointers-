#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/two_d_functions/two_d_functions.h"

#include <ostream>
#include "assert.h"
using namespace std;
bool **init_plane();
bool reserve(bool **plane, int row, int seat);
bool cancel(bool** plane, int row, int seat);
void print_plane(bool **plane);

bool **init_plane(){
    return nullptr;
}
bool reserve(bool **plane, int row, int seat){
    return false;
}
bool cancel(bool** plane, int row, int seat){
    return false;
}
void print_plane(bool **plane){
    return;
}
#endif
