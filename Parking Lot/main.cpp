#include<iostream>
using namespace std;
#include "ParkingLot.h"
#include"stdlib.h"

int main()
{
    ParkingLot p;
    //system("cls");
    p.ParkingLotSetup();
    int w;
    bool f1=true;
    while(f1){
        cin.get();
        system("cls");
        cout<<"\tEnter 1. For Vehicle Entry"<<endl;
        cout<<"\tEnter 2. For Vehicle Exit"<<endl;
        cout<<"\tEnter 3. To see the Parking Lot Status"<<endl;
        cout<<"\tEnter 4. To Exit"<<endl<<endl;
        cin>>w;
        switch(w)
        {
            case 1: p.VehicleEntry();
            break;
            case 2: p.VehicleExit();
            break;
            case 3: p.Show();
            break;
            case 4: f1=false;
            break;
            default:
                cout<<"Enter valid option"<<endl;
            break;
        }
    }
    p.deleteBlock();


    return 0;
}
