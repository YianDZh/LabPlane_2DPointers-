#ifndef PLANE_H
#define PLANE_H
#include <iostream>
#include "../../includes/array_functions/array_functions.h"
#include "../../includes/two_d_functions/two_d_functions.h"
#include "iomanip"
#include <ostream>
#include "assert.h"
using namespace std;
bool **init_plane();
bool reserve(bool **plane, int row, int seat);
bool cancel(bool** plane, int row, int seat);
void print_plane(bool **plane);
void print_seats (bool* row,int size);

bool **init_plane(){
    int sizes [8]= {4,4,4,4,4,4,4,-1};
    bool ** plane = allocate_twod <bool> (sizes);
    init_twod <bool> (plane, sizes, false);
    return plane;
}
bool reserve(bool **plane, int row, int seat){
    bool prev = read_twod<bool> (plane, row,seat);
    if(prev){
        return !prev;
    }
    write_twod <bool> (plane, row, seat, true);
    bool ans = read_twod<bool> (plane, row,seat);
    return ans;
}
bool cancel(bool** plane, int row, int seat){
    write_twod <bool> (plane, row, seat, false);
    bool ans = read_twod<bool> (plane, row,seat);
    return ans;
}
void print_plane(bool **plane){
    int sizes [8]= {4,4,4,4,4,4,4,-1};
    int limit = array_size (sizes);
    for (int i =0;i<4;i++){
        char out='A'+i;
        cout<<setw (5)<<out<<"  ";
    }
    cout<<"\n";
    bool** walkman = plane;
    int* size_walker= sizes;
    int count = array_size (sizes);
    
    for (int i = 0; i < count; i++,size_walker++, walkman++)
    {
        cout<<i+1<<setw(3);
        int current= *size_walker;
        bool* walkman_jr = *walkman;
        print_seats (walkman_jr, current);
    }

}
void print_seats (bool* row,int size){
    bool *walkman = row;
        for (int i = 0; i < size;i++, walkman++)
    {
        if (*walkman)
        cout<<" | "<<'X'<<" | ";
        else if (!*walkman)
        cout<<" | "<<'O'<<" | ";
    }
    cout<<"\n";
}

#endif
