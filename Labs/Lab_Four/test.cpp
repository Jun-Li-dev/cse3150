#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Hybrid.h"

// ----------------------
// TEST CASES
// ----------------------

TEST_CASE("MPGe Calculation") {

    HybridVehicle h;

    h.setElectricMiles(300);
    h.setTotalkWh(70.0);

    double expected = 300 / (70.0 / 33.7);

    CHECK(h.calcMPGe() == doctest::Approx(expected));
}

TEST_CASE("MPG Getter/Setter") {

    HybridVehicle h;

    h.setMPG(40);

    CHECK(h.getMPG() == 40);
}

TEST_CASE("Cost Per Mile") {

    HybridVehicle h;

    h.setElectricMiles(300);
    h.setTotalkWh(70.0);
    h.setMPG(40);

    double result = h.costPerMile(3.10);

    double mpge = 300 / (70.0 / 33.7);
    double electricCostPerGallon = 33.7 * 0.24;

    double gasCost = 3.10 / 40;
    double electricCost = electricCostPerGallon / mpge;

    double expected = (gasCost + electricCost) / 2;

    CHECK(result == doctest::Approx(expected));
}