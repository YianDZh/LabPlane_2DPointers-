#include <iostream>
#include <iomanip>
#include "includes/applications/lab_application.h"
#include "includes/two_d_functions/two_d_functions.h"
#include "includes/lab/lab.h"


using namespace std;

int main(int argv, char** argc) {
    cout << "\n\n"
         << endl;

    cout << "\n\n\n=====================" << endl;
    int size=6;
    int stations [size]={5,4,8,9,5,-1};
    int** labs = init_lab (stations);
    char cond;
    do {
    menu_lab (labs, stations);
    cout<<"Would you like to keep using this?\n";
    cin>>cond;
    } 
    while (cond=='y'||cond=='Y');
    labs = deallocate_twod <int> (labs, size);
    return 0;

}
