#ifndef HYBRIDVEHICLE_H
#define HYBRIDVEHICLE_H

#include "Gas.h"
#include "Electric.h"

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
public:
    double costPerMile(double costOfGas) {

        double electricCostPerGallon = 33.7 * 0.24;

        double mpge = calcMPGe();
        double mpg = getMPG();

        double gasCost = costOfGas / mpg;
        double electricCost = electricCostPerGallon / mpge;

        return (gasCost + electricCost) / 2;
    }
};

#endif