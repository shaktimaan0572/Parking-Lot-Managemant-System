#include <iostream>
#include "ParkingLot.h"
#include<string>
#include<ctime>
#include"stdlib.h"
using namespace std;

ParkingLot::ParkingLot():BikeBlock(new Bike_Block) , CarBlock(new Car_Block) , BusBlock(new Bus_Block)
{
    //ctor
    //cout<<"parking Lot created"<<endl;
}

ParkingLot::~ParkingLot()
{
    //dtor
    //cout<<"parking Lot destroyed"<<endl;

}
void ParkingLot:: deleteBlock()
{
    delete BikeBlock;
    delete CarBlock;
    delete BusBlock;
}
void ParkingLot :: VehicleEntry(){

    int v_type;

    Vehicle* vehicle;
    system("cls");

    cout<<"\t\t\tVehicle Entry"<<endl;
    cout<<"\tChoose Your Vehicle: "<<endl;
    cout<<"\tEnter 1. For Bike"<<endl;
    cout<<"\tEnter 2. For Car"<<endl;
    cout<<"\tEnter 3. For Bus"<<endl;
    cin>>v_type;

    switch(v_type)
    {
        case 1: vehicle = new Bike();
        break;
        case 2: vehicle = new Car();
        break;
        case 3: vehicle = new Bus();
        break;
        default:
            cout<<"\tChoose Valid option"<<endl;
    }
    //Enter vehicle details
    cout<<"\tEnter Vehicle Details: "<<endl;
    cout<<"\tEnter Vehicle NO.: ";
    string number, company_name;
    cin>>number;
    vehicle->Setvehicle_no(number);
    cout<<"\tEnter Vehicle's Company Name: ";
    cin>>company_name;
    vehicle->Setvehicle_co_name(company_name);
    time_t entry_time = time(nullptr);
    vehicle->Setentry_time(entry_time);
    //end vehicle details
    int sNo=0;
    string code;
    switch(v_type)
    {
        case 1: {
            sNo=BikeBlock->SpotAllocation(vehicle);
            if(sNo!=0){
            code="Bike+"+vehicle->Getvehicle_no()+"%"+to_string(sNo);}
            break;
        }

        case 2: {
            //code="Car";
            sNo=CarBlock->SpotAllocation(vehicle);
            if(sNo!=0){
            code="Car+"+vehicle->Getvehicle_no()+"%"+to_string(sNo);}
        break;}
        case 3: {
            //code="Bus";
            sNo=BusBlock->SpotAllocation(vehicle);
            if(sNo!=0){
            code="Bus+"+vehicle->Getvehicle_no()+"%"+to_string(sNo);}
        break;}
        default:
            cout<<"\tChoose Valid option"<<endl;
    }
    if(sNo!=0)
    {
        tm* x= localtime(&entry_time);
        cout<<"\tYour Entry Time: "<<asctime(x)<<endl;
        cout<<"\tYour Unique Code: "<<code<<endl;
        string area(code,0,code.find('+'));
        string spot_area(code,code.find('%')+1);
        cout<<"\tPark your "<<area<<" in a "<<area<<" area at spot number : "<<spot_area<<endl;
        cout<<"P.S.- Remember your unique code it will help you to exit from the parking."<<endl;

    }
    cin.get();


}
void ParkingLot::VehicleExit()
{
    system("cls");
    string code;
    cout<<endl<<"\t\tVehicle Exit"<<endl;
    cout<<"\tEnter Your Unique Code: ";
    cin>>code;
    string area(code,0,code.find('+'));
    string spot_area(code,code.find('%')+1);
    Vehicle *returned_Vehicle;
    if(area=="Car")
    {
        returned_Vehicle= CarBlock->SpotDellocation(stoi(spot_area));
    }
    else if(area=="Bike")
    {
        returned_Vehicle= BikeBlock->SpotDellocation(stoi(spot_area));
    }
    else if(area=="Bus")
    {
        returned_Vehicle= BusBlock->SpotDellocation(stoi(spot_area));
    }
    else
    {
        cout<<"\tEnter Valid Code"<<endl;
        cin.get();
        VehicleExit();
    }
    int base = returned_Vehicle->Getbase_fare();
    int price = returned_Vehicle->Getpara_fare();
    time_t entrytime= returned_Vehicle->Getentry_time();
    time_t exittime = time(nullptr);
    double time_taken=(difftime(exittime,entrytime))/60;

    double cost = (double)base + (price * time_taken);

    tm* x= localtime(&exittime);
    cout<<"\tYour Exit Time: "<<asctime(x);
    cout<<"\tBill Details: "<<endl;
    cout<<"\t  Base Price: Rs. "<<base<<endl;
    cout<<"\t  Parking Lot Price : Rs. "<<price<<"/min"<<endl;
    cout<<"\t  Time taken inside Parking: "<<time_taken<<"mins"<<endl;
    //cout<<base<<" "<<price<<" "<<time_taken<<endl;
    cout<<"\tYou have to pay: Rs. "<<cost<<endl;
    cout<<"\tThanks For Coming!!"<<endl;
    delete returned_Vehicle;
    cin.get();

}
void ParkingLot:: ParkingLotSetup(){

    cout<<"\t\t\tParking Lot Setup:"<<endl;

    cout<<"\tSet-up Bike Block Area:"<<endl;
    cout<<"\tEnter the Capacity of the spots in Bike Block Area: ";
    int cap,b_fare,price;
    cin>>cap;
    BikeBlock->SetCapacity(cap);
    cout<<"\tEnter the base fair for the Bike Block Area: ";
    cin>>b_fare;
    BikeBlock->Setbase_fare(b_fare);
    cout<<"\tEnter the price fair for the Bike Block Area as per /min cost : ";
    cin>>price;
    BikeBlock->Setpara_fare(price);
    cout<<endl;


    cout<<"\tSet-up Car Block Area:"<<endl;
    cout<<"\tEnter the Capacity of the spots in Car Block Area: ";
    //int cap,b_fare,price;
    cin>>cap;
    CarBlock->SetCapacity(cap);
    cout<<"\tEnter the base fair for the Car Block Area: ";
    cin>>b_fare;
    CarBlock->Setbase_fare(b_fare);
    cout<<"\tEnter the price fair for the Car Block Area as per /min cost : ";
    cin>>price;
    CarBlock->Setpara_fare(price);
    cout<<endl;


    cout<<"\tSet-up Bus Block Area:"<<endl;
    cout<<"\tEnter the Capacity of the spots in Bus Block Area: ";
    //int cap,b_fare,price;
    cin>>cap;
    BusBlock->SetCapacity(cap);
    cout<<"\tEnter the base fair for the Bus Block Area: ";
    cin>>b_fare;
    BusBlock->Setbase_fare(b_fare);
    cout<<"\tEnter the price fair for the Bus Block Area as per /min cost : ";
    cin>>price;
    BusBlock->Setpara_fare(price);
    cout<<endl;
    //cin.get();



}
void ParkingLot:: Show(){
    system("cls");
    cout<<"\tParking Lot Status: "<<endl<<endl;
    //map<int , Vehicle *> :: iterator itr;
    cout<<"\tBike Area: "<<endl;
    BikeBlock->showMap();
    cout<<"\tCar Area :"<<endl;
    CarBlock->showMap();
    cout<<"\tBus Area :"<<endl;
    BusBlock->showMap();
    cin.get();
    cout<<endl<<"P.S.- Press any key .. to Goto Main Menu...";

}
