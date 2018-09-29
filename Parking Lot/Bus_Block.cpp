#include "Bus_Block.h"
#include <iostream>
using namespace std;
Bus_Block::Bus_Block()
{
    //ctor
    //cout<<"bus Lot created"<<endl;
}

Bus_Block::~Bus_Block()
{
    //dtor
    //cout<<"bus Lot destroyed"<<endl;
}

int Bus_Block:: SpotAllocation(Vehicle *v){
    int x;
    if(!BusSet.empty()){
        x = *(BusSet.begin());
        BusMap.insert(pair<int,Vehicle*>(x,v));
        v->Setbase_fare(Getbase_fare());
        v->Setpara_fare(Getpara_fare());
        BusSet.erase(BusSet.begin());
        return x;
    }
    else{
        if(BusID>Capacity)
        {
            std::cout<<"/tBus Area is Full"<<std::endl<<std::endl;
            delete v;
            return 0;
        }
        else{
            BusMap.insert(pair<int,Vehicle*>(BusID++,v));
            v->Setbase_fare(Getbase_fare());
            v->Setpara_fare(Getpara_fare());
        }
    }
    return BusID-1;
}
Vehicle * Bus_Block::SpotDellocation(int key){
    itr = BusMap.find(key);
    Vehicle *v1 = itr->second;
    BusSet.insert(itr->first);
    BusMap.erase(itr);
    return v1;
}
void Bus_Block :: showMap(){
    if(BusMap.size()==0)
    {
        cout<<"No Space is Acquired"<<endl;
        return;
    }
    for(itr=BusMap.begin(); itr!=BusMap.end();++itr )
    {
        cout<<itr->first<<". "<<itr->second->Getvehicle_no()<<endl;
    }
    cout<<endl;
}
