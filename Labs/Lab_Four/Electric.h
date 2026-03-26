#ifndef ELECTRICVEHICLE_H
#define ELECTRICVEHICLE_H

class ElectricVehicle {
protected:
    double electricMiles;
    double totalKWh;

public:
    void setElectricMiles(double m) {
        electricMiles = m;
    }

    void setTotalkWh(double k) {
        totalKWh = k;
    }

    double calcMPGe() {
        return electricMiles / (totalKWh / 33.7);
    }
};

#endif