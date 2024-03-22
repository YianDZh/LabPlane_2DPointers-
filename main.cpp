#include <iostream>
#include <iomanip>
#include "includes/applications/lab_application.h"
#include "includes/applications/plane_application.h"
#include "includes/plane/plane.h"
#include "includes/two_d_functions/two_d_functions.h"
#include "includes/lab/lab.h"



using namespace std;
void lab_demo ();
void plane_demo ();

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    cout << "\n\n\n=====================" << endl;
    cout<<"What project would you like to try?\n";
    cout<<"[P]lane           [L]ab\n";
    char tum;
    cin>>tum;
    while (tum!='l'&&tum!='L'&&tum!='P'&&tum!='p'){
    cout<<"Invalid input!\n";
    cin>>tum;
    }
    switch (tum){
    case 'l':
    case 'L':
        lab_demo ();
        break;
    case'p':
    case'P':
        plane_demo ();
        break;
    default:
        break;
    
    }
    cout<<"Thank for trying it out!\n";
    return 0;

}

void lab_demo (){
    int size=6;
    int stations [size]={5,4,8,9,5,-1};
    int** labs = init_lab (stations);
    char cond;
    do {
    menu_lab (labs, stations);
    cout<<"Would you like to do another operation?\n";
    cin>>cond;
    } 
    while (cond=='y'||cond=='Y');
    labs = deallocate_twod <int> (labs, size);
}

void plane_demo (){
    bool** plane = init_plane();
    int size=7;
    char cond;
    do{
    plane_menu (plane);
    cout<<"Would you like to do another operation?\n";
    cin>>cond;
    }
    while (cond=='y'||cond=='Y');
    plane=deallocate_twod (plane,size);
}