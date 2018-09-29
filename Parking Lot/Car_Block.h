#ifndef CAR_BLOCK_H
#define CAR_BLOCK_H
#include "Spot.h"
#include "Vehicle.h"
#include<map>
#include<set>
class Car_Block
{
    public:
        Car_Block();
        virtual ~Car_Block();
        int SpotAllocation(Vehicle *);
        Vehicle * SpotDellocation(int );
        int Getbase_fare() { return base_fare; }
        void Setbase_fare(int val) { base_fare = val; }
        int Getpara_fare() { return para_fare; }
        void Setpara_fare(int val) { para_fare = val; }
        int GetCapacity() { return Capacity; }
        void SetCapacity(int val) { Capacity = val; }
        //const char * Getarea() { return area; }
        void showMap();
    protected:


    private:
        int Capacity;
        int CarID = 1;
        int base_fare;
        int para_fare;
        //const char *area = "Car_Area";
        std::map<int , Vehicle *> CarMap;
        std::map<int , Vehicle *> ::iterator itr;
        std::set<int> CarSet;
};

#endif // CAR_BLOCK_H
