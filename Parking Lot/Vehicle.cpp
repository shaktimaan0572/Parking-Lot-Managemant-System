#include "Vehicle.h"
#include <iostream>
using namespace std;
Vehicle::Vehicle()
{
    //ctor
    //cout<<"vehicle created"<<endl;

}

Vehicle::~Vehicle()
{
    //dtor
    //cout<<"vehicle destroyed"<<endl;
}

Vehicle::Vehicle(const Vehicle& other)
{
    //copy ctor
    //cout<<"vehicle copy created"<<endl;
}
