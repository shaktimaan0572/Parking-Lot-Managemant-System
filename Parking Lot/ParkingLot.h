#ifndef PARKINGLOT_H
#define PARKINGLOT_H
#include "Car_Block.h"
#include "Bike_Block.h"
#include "Bus_Block.h"
#include "Vehicle.h"
#include "Car.h"
#include "Bike.h"
#include "Bus.h"
class ParkingLot
{
    public:
        ParkingLot();
        virtual ~ParkingLot();
        void ParkingLotSetup();
        void VehicleEntry();
        void deleteBlock();
        void VehicleExit();
        void Show();

    protected:

    private:
        Bike_Block *BikeBlock;
        Car_Block *CarBlock;
        Bus_Block *BusBlock;
};

#endif // PARKINGLOT_H
