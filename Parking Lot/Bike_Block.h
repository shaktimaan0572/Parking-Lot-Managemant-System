#ifndef BIKE_BLOCK_H
#define BIKE_BLOCK_H
#include "Spot.h"
#include "Vehicle.h"
#include<map>
#include<set>
class Bike_Block
{
    public:
        Bike_Block();
        virtual ~Bike_Block();
        int SpotAllocation(Vehicle *);
        Vehicle * SpotDellocation(int );
        int Getbase_fare() { return base_fare; }
        void Setbase_fare(int val) { base_fare = val; }
        int Getpara_fare() { return para_fare; }
        void Setpara_fare(int val) { para_fare = val; }
        void showMap();
        void SetCapacity(int val) { Capacity = val; }


    protected:

    private:
        int Capacity;
        int BikeID = 1;
        int base_fare;
        int para_fare;
        std::map<int , Vehicle *> BikeMap;
        std::map<int , Vehicle *> ::iterator itr;
        std::set<int> BikeSet;

};

#endif // BIKE_BLOCK_H
