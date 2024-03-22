#ifndef PLANE_APPLICATION_H_
#define PLANE_APPLICATION_H_
#include "../../includes/plane/plane.h"
#include "../../includes/two_d_functions/two_d_functions.h"
#include "../../includes/array_functions/array_functions.h"
using namespace  std;
void plane_menu (bool**plane);
void invalid_plane (char& thisthing);
void reserved (bool**plane);
void cancelled (bool **plane);

void invalid_plane (char& thisthing){
    char change;
    cin>>change;
    cout<<"\n";
    if(change!='r'&&change!='R'&&change!='c'&&change!='C'&&change!='x'&&change!='X'){
        do{
            cout<<"Invalid output!\n";
            cin>>change;
            cout<<"\n";
        }
    while(change!='r'&&change!='R'&&change!='x'&&change!='X'&&change!='C'&&change!='c');
    thisthing=change;
    }
    else {
    thisthing = change;
    }
    
}
void plane_menu (bool**plane){
cout<<"Plese input what kind of action you would like to do\n";
char desicion;
  cout<<"[r]eserve     [c]ancel     e[x]it\n";
  invalid_plane (desicion);
  cout<<"\n";
  switch (desicion)
    {
    case 'r':
    case 'R':
    reserved (plane);
        break;
    case 'C':
    case 'c':
    cancelled (plane);
    break;
    case 'X':
    case 'x':
    break;
    }
    cout<<"Please comeback soon!\n";
}

void reserved (bool**plane){
    cout<<"Please write where do you want to make your reservation\n";
    print_plane (plane);
    cout<<"Please write the row number you want\n";
    int row;
    cin>>row;
    cout<<"Please write the seat number you want\n";
    int col;
    cin>>col;
    bool yesno=reserve (plane, row-1, col-1);
    if (!yesno){
        cout<<"Couldn't do the reservation!\n";
        return;
    }
    else{
        cout<<"Reservation succesful!\n";
        print_plane (plane);

    }
}
void cancelled (bool **plane){
    cout<<"Please write the possition you want to cancel\n";
     print_plane (plane);
    cout<<"Please write the row number you want\n";
    int row;
    cin>>row;
    cout<<"Please write the seat you want\n";
    int col;
    cin>>col;
    bool truth = cancel (plane, row-1, col-1);
    if (truth){
        cout<<"Seat is still unreserved!\n";
        return;
    }
    else{
        cout<<"Cancellation succesful!\n";
        print_plane (plane);
    }
}

#endif // PLANE_APPLICATION_H_