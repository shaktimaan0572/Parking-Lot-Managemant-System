#ifndef SPOT_H
#define SPOT_H
#include "Vehicle.h"

class Spot
{
    public:
        Spot();
        virtual ~Spot()=0;
        virtual void SpotAllocation(Vehicle *)=0;
        virtual void SpotDellocation(Vehicle *)=0;
    protected:

    private:
};

#endif // SPOT_H
