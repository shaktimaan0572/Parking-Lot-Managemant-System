#include "Bike_Block.h"
#include <iostream>
using namespace std;
Bike_Block::Bike_Block()
{
    //ctor
    //cout<<"bike Lot created"<<endl;
}

Bike_Block::~Bike_Block()
{
    //dtor
    //cout<<"bike Lot destroyed"<<endl;
}
int Bike_Block:: SpotAllocation(Vehicle *v){
    int x;
    if(!BikeSet.empty()){
        x=*(BikeSet.begin());
        BikeMap.insert(pair<int,Vehicle*>(x,v));
        v->Setbase_fare(Getbase_fare());
        v->Setpara_fare(Getpara_fare());
        BikeSet.erase(BikeSet.begin());
        return x;
    }
    else{
        if(BikeID>Capacity)
        {
            std::cout<<"\tBike Area is Full"<<std::endl<<std::endl;
            delete v;
            return 0;
        }
        else{
            BikeMap.insert(pair<int,Vehicle*>(BikeID++,v));
            v->Setbase_fare(Getbase_fare());
            v->Setpara_fare(Getpara_fare());
        }
    }
    return BikeID-1;
}
Vehicle * Bike_Block::SpotDellocation(int key){
    itr = BikeMap.find(key);
    Vehicle *v1 = itr->second;
    BikeSet.insert(itr->first);
    BikeMap.erase(itr);
    return v1;
}
void Bike_Block :: showMap(){
    if(BikeMap.size()==0)
    {
        cout<<" No Space is Acquired"<<endl;
        return;
    }
    for(itr=BikeMap.begin(); itr!=BikeMap.end();++itr )
    {
        cout<<itr->first<<". "<<itr->second->Getvehicle_no()<<endl;
    }
    cout<<endl;
}
