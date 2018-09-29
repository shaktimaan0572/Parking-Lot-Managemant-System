#ifndef BUS_H
#define BUS_H
#include<ctime>
#include "Vehicle.h"

class Bus : public Vehicle
{
    public:
        Bus();
        ~Bus();
        int Getbase_fare() { return base_fare; }
        void Setbase_fare(int val) { base_fare = val; }
        int Getpara_fare() { return para_fare; }
        void Setpara_fare(int val) { para_fare = val; }
        time_t Getentry_time() { return entry_time; }
        void Setentry_time(time_t val) { entry_time = val; }

    protected:

    private:
        int base_fare;
        int para_fare;
        time_t entry_time;
};

#endif // BUS_H
