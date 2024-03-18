#ifndef LAB_APPLICATION_H_
#define LAB_APPLICATION_H_
#include "../../includes/lab/lab.h"
#include "../../includes/two_d_functions/two_d_functions.h"
#include "../../includes/array_functions/array_functions.h"

void menu_lab(int **labs, int* stations);
void logining (int ** labs, int* stations, int id);
void leaving (int** labs, int* stations, int id);
void invalid (char& thisthing);
void print_lab(int **lab, int* stations);
void print_stations (int* station,int size);
void lab_input (int &lab, int &station);
void lab_exit (int &lab, int &station);
void invalid (char& thisthing){
    char change;
    cin>>change;
    cout<<"\n";
    if(change!='i'&&change!='I'&&change!='x'&&change!='X'&&change!='o'&&change!='O'){
        do{
            cout<<"Invalid output!\n";
            cin>>change;
            cout<<"\n";
        }
    while(change!='i'&&change!='I'&&change!='x'&&change!='X'&&change!='o'&&change!='O');
    thisthing=change;
    }
    else {
    thisthing = change;
    }
}
void logining (int ** labs, int* stations, int id){
    cout<<"These are all the available stations:\n";
    print_lab (labs,stations);
    int lab; //row
    int station; //col
    bool fst;
    do{
        lab_input (lab,station);
  
        fst=index_is_valid (stations,lab,station);
        if (!fst){
            cout<<"Please try again, station not found\n";
        }
    }
    while (!fst);
    
    bool snd = login (labs, lab, station, id);
    if (!snd){
        do {
            lab_input (lab,station);
            fst =index_is_valid (stations,lab,station);
            while (!fst){
                lab_input (lab, station);
                fst =index_is_valid (stations,lab,station);
            }
            if (fst)
            snd = login (labs, lab, station, id); 
        }
        while (!snd);
    }
    else{
    print_lab (labs,stations);
    }
}
void leaving (int** labs, int* stations, int id){
bool cond = logout (labs,stations, id);
if (!cond){
    return;
}
print_lab (labs,stations);

}

void menu_lab(int **labs, int* stations){
    int id;
    cout<<"Welcome to the lab!\n";
    cout<<"Please enter your id: ";
    cin>>id;
    cout<<"\n Please select what action you want to do: ";
    cout<<"log[i]n     log[o]ut     e[x]it\n";
    char action;
    invalid (action);
    switch (action)
    {
    case 'i':
    case 'I':
    logining (labs,stations,id);
        break;
    case 'o':
    case 'O':
    leaving (labs, stations, id);
    break;
    case 'X':
    case 'x':
    break;
    }
    cout<<"Please comeback soon!\n";
}


void print_lab(int **lab, int* stations){
    int count = array_size (stations);
    for (int i =0;i<count;i++){
        cout<<setw (5)<<i+1<<"  ";
    }
    cout<<"\n";
    int** walkman = lab;
    int* size_walker= stations;
    
    for (int i = 0; i < count; i++,size_walker++, walkman++)
    {
        cout<<i+1<<setw(3);
        int current= *size_walker;
        int* walkman_jr = *walkman;
        print_stations (walkman_jr, current);
    }

}
void print_stations (int* station,int size){
    int *walkman = station;
        for (int i = 0; i < size;i++, walkman++)
    {
        if (*walkman!=0)
        cout<<" | "<<'X'<<" | ";
        else if (*walkman==0)
        cout<<" | "<<0<<" | ";

    }
    cout<<"\n";
}

void lab_input (int &lab, int &station){
    cout<<"Please enter the station you want to use\n";
    cout<<"Lab #: ";
    cin>>lab;
    cout<<"\n";
    cout<<"Station # :";
    cin>>station;
    cout<< "\n";
    lab--;
    station--;
}

#endif // LAB_APPLICATION_H_