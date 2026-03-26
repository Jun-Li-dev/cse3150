#ifndef GASOLINEVEHICLE_H
#define GASOLINEVEHICLE_H

class GasolineVehicle {
protected:
    double mpg;

public:
    void setMPG(double m) {
        mpg = m;
    }

    double getMPG() {
        return mpg;
    }
};

#endif