#ifndef VEHICLE_H
#define VEHICLE_H
#include<string>


class Vehicle
{
    public:
        Vehicle();
        virtual ~Vehicle();
        Vehicle(const Vehicle& other);
        int Getbase_fare() { return base_fare; }
        void Setbase_fare(int val) { base_fare = val; }
        int Getpara_fare() { return para_fare; }
        void Setpara_fare(int val) { para_fare = val; }
        time_t Getentry_time() { return entry_time; }
        void Setentry_time(time_t val) { entry_time = val; }
        std::string Getvehicle_no() { return vehicle_no; }
        void Setvehicle_no(std::string val) { vehicle_no = val; }
        std::string Getvehicle_co_name() { return vehicle_co_name; }
        void Setvehicle_co_name(std::string val) { vehicle_co_name = val; }

    protected:

    private:
        int base_fare;
        int para_fare;
        time_t entry_time;
        std::string vehicle_no;
        std::string vehicle_co_name;
};

#endif // VEHICLE_H
