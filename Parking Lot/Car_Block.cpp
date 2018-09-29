#include "Car_Block.h"
#include <iostream>
using namespace std;
Car_Block::Car_Block()
{
    //ctor
    //cout<<"car Lot created"<<endl;
}

Car_Block::~Car_Block()
{
    //dtor
    //cout<<"car Lot destroyed"<<endl;
}

int Car_Block:: SpotAllocation(Vehicle *v){
    int x;
    if(!CarSet.empty()){
        x=*(CarSet.begin());
        CarMap.insert(pair<int,Vehicle*>(x,v));
        v->Setbase_fare(Getbase_fare());
        v->Setpara_fare(Getpara_fare());
        CarSet.erase(CarSet.begin());
        return x;
    }
    else{
        if(CarID>Capacity)
        {
            std::cout<<"/tCar Area is Full"<<std::endl<<std::endl;
            delete v;
            return 0;
        }
        else{
            CarMap.insert(pair<int,Vehicle*>(CarID++,v));
            v->Setbase_fare(Getbase_fare());
            v->Setpara_fare(Getpara_fare());
        }
    }
    return CarID-1;

}
Vehicle * Car_Block::SpotDellocation(int key){
    itr = CarMap.find(key);
    Vehicle *v1 = itr->second;
    CarSet.insert(itr->first);
    CarMap.erase(itr);
    return v1;
}
void Car_Block :: showMap(){
    if(CarMap.size()==0)
    {
        cout<<"No Space is Acquired"<<endl;
        return;
    }
    for(itr=CarMap.begin(); itr!=CarMap.end();++itr )
    {
        cout<<itr->first<<". "<<itr->second->Getvehicle_no()<<endl;
    }
    cout<<endl;
}
