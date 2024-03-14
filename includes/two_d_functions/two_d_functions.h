#ifndef TWO_D_FUNCTIONS_H
#define TWO_D_FUNCTIONS_H
#include <iostream>
#include <ostream>
#include "../../includes/array_functions/array_functions.h"
#include "assert.h"
using namespace std;

int array_size(int* sizes);
void print_array(int* a);
//
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
    int count=0;
    int* w_size= sizes; 
    while (*w_size!=-1||w_size==nullptr)
    {
        count++;
        w_size++;
    }
    return count;    
}
void print_array(int* a){
    int * current = a;
    int count = array_size(a);
    for (int i=0; i<count;i++){
        cout<<*current<<" ";
        current++;
    }
}
bool index_is_valid(int* sizes, int row, int col){
    int count = array_size (sizes);
    int *current = sizes;
    for (int i =0; i<count; i++, current++){
        if (row<count&&col<=*current){
            return true;
        }
    }
    return false;
}



//To call: int** p = allocate_twod<int>(sizes_array)  

template <class T>
T** allocate_twod(int* sizes){
    int count = array_size (sizes);
    int* w_size=sizes;
    T** list = new T* [count];
    T** limit = list+count;
    T**walker=list;
    for (int i = 0; i < count; i++,w_size++){
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
    T**walkman = twod;
    for (int i=0; i<size;i++, walkman++){
        T*walkman_jr = *walkman;
        delete [] walkman_jr;
    }
    delete [] walkman;
    return twod;
}

template <class T>
T read_twod(T** twod, int row, int col){
        T** walkman = twod+row;
        assert (walkman!=NULL);
        T* walkman_jr =*walkman;
        walkman_jr+=col;
        assert (walkman_jr!=NULL);
        return *walkman_jr;
}

template <class T>
void write_twod(T** twod, int row, int col, const T& item){
    T** walkman = twod+row;
    if (walkman ==NULL){
        return;
    }
    T* walkman_jr =*walkman;
    walkman_jr+=col;
    // assert (walkman_jr!=NULL);
    //**Might need it 
    *walkman_jr = item;
}

template <class T>
T& get_twod(T** twod, int row, int col){
}

template<class T>
void init_twod(T** twod, int* sizes, T init_item){
    T** walkman = twod;
    int count = array_size (sizes);
    for (int i = 0; i < count; i++, walkman++){
        T* walkman_jr= *walkman;
        int* size_walker =sizes+i;
        int current_size= *size_walker;
            for (int j =0; j<current_size;j++, walkman_jr++){
            *walkman_jr=init_item;
        }
    }
    //!LOOK FOR A WAY TO MAKE THIS A SINGLE LOOP
}  

template<class T>
bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col){
}

//return a pointer to the item if found, nullptr if not found: 
//                                                 (Ms. Barskhian)
template<class T> 
T* search_twod(T** twod, int* sizes, const T& key){
    int count = array_size (sizes);
    T** walkman= twod;
    int* size_walker =sizes;
    T* walkman_jr;
    for (int i=0; i<count;i++,walkman++, sizes++){
        walkman_jr=*walkman;
        int current= *size_walker;
        search_entry <T> (walkman_jr,current,key);
    }
    return walkman_jr;
}

template <class T>
ostream& print_twod(T** twod, int* sizes, ostream& outs){
    cout<<"Printing 2D Array\n";
    T** walkman = twod;
    T* size_walker= sizes;
    int count = array_size (sizes);
    
    for (int i = 0; i < count; i++,size_walker++, walkman++)
    {
        int current= *size_walker;
        T* walkman_jr = *walkman;
        print (walkman_jr, current);
    }
    return outs;
    
}
#endif