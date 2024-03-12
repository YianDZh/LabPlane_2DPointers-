#ifndef TWO_D_FUNCTIONS_H
#define TWO_D_FUNCTIONS_H
#include <iostream>
#include <ostream>
#include "../../includes/array_functions/array_functions.h"
#include "assert.h"
using namespace std;

int array_size(int* sizes);
void print_array(int* a);
bool index_is_valid(int* sizes, int row, int col);



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes); 

template <class T>
T** deallocate_twod(T** twod, int size);

template <class T>
T read_twod(T** twod, int row, int col);

template <class T>
void write_twod(T** twod, int row, int col, const T& item);

template <class T>
T& get_twod(T** twod, int row, int col);

template<class T>
void init_twod(T** twod, int* sizes, T init_item = T());

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key); 

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs = cout);

//!!! 


int array_size(int* sizes){
}
void print_array(int* a){
}
bool index_is_valid(int* sizes, int row, int col){
}



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes){
    int count =0;
    int* w_size= sizes;
    while (*w_size!=-1)
    {
        count++;
        w_size++;
    }
    w_size=sizes;
    T** list = new T* [count];
    T** limit = list+count;
    T**walker=list;
    for (int i = 0; i < count; i++,w_size++)
    {
        if (walker==limit){
            break;
        }
        int current=*w_size;
        *walker = allocate <T> (current);
        walker++;
    }
    return list;
}

template <class T>
T** deallocate_twod(T** twod, int size){
}

template <class T>
T read_twod(T** twod, int row, int col){
}

template <class T>
void write_twod(T** twod, int row, int col, const T& item){
}

template <class T>
T& get_twod(T** twod, int row, int col){
}

template<class T>
void init_twod(T** twod, int* sizes, T init_item){
     T** walkman = twod;
     int* size_walker =sizes;
      while (*size_walker!=-1)
       {
        T* walkman_jr= *walkman;
        int current=*size_walker;
        for (int i = 0; i < current; i++){
            *walkman_jr=init_item;
            walkman_jr++;
            }
        walkman++;
        size_walker++;
 }  
}

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col){
}

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key){
}

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs){
    cout<<"Printing 2D Array\n";
    T** walkman = twod;
    T* size_walker= sizes;
    while (*size_walker!=-1){
    int current_size=*size_walker;
    T* walkman_jr=*walkman;
    for (int i = 0; i < current_size; i++, walkman_jr++){
        cout<<*walkman_jr<<" | ";
    }
    cout<<"\n";
    walkman++;
    size_walker++;
    }
}
#endif