#include <iostream>
#include "Hybrid.h"

using namespace std;

int main() {

    HybridVehicle aHybrid;

    double miles = 300;

    aHybrid.setElectricMiles(miles);
    aHybrid.setTotalkWh(70.0);
    aHybrid.setMPG(40);

    double MPGe = aHybrid.calcMPGe();
    cout << "MPGe: " << MPGe << endl;

    double costOfOneGallon = 3.10;

    double avgCost = aHybrid.costPerMile(costOfOneGallon);
    cout << "Cost per mile: " << avgCost << endl;

    return 0;
}