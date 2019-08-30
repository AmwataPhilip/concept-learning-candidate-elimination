/*
*
* Author: Philip Amwata
* Version: 1.0
*
*/

#include "../include/candidateE.h"

int main(int argc, const char **argv)
{
    using namespace AMWPHI001;
    std::string GENERAL = "?", SPECIFIC = "ɸ";

    Hypothesis generalHypo({GENERAL, GENERAL, GENERAL, GENERAL, GENERAL}, 2);
    Hypothesis specificHypo({SPECIFIC, SPECIFIC, SPECIFIC, SPECIFIC, SPECIFIC}, 3);

    // Training examples for target concept Japanese Economy Car
    Hypothesis hypo1({"Japan", "Honda", "Blue", "1980", "Economy"}, 1);
    Hypothesis hypo2({"Japan", "Toyota", "Green", "1970", "Sports"}, 0);
    Hypothesis hypo3({"Japan", "Toyota", "Blue", "1990", "Economy"}, 1);
    Hypothesis hypo4({"USA", "Chrysler", "Red", "1980", "Economy"}, 0);
    Hypothesis hypo5({"Japan", "Honda", "White", "1980", "Economy"}, 1);
    Hypothesis hypo6({"Japan", "Toyota", "Green", "1980", "Economy"}, 1);
    Hypothesis hypo7({"Japan", "Honda", "Red", "1990", "Economy"}, 0);
    std::vector<Hypothesis> japEconCar{hypo1, hypo2, hypo3, hypo4, hypo5, hypo6, hypo7};

    // Training examples for target concept Japanese Sports Car
    Hypothesis hypo8({"Japan", "Honda", "Blue", "1980", "Economy"}, 0);
    Hypothesis hypo9({"Japan", "Toyota", "Green", "1970", "Sports"}, 1);
    Hypothesis hypo10({"Japan", "Toyota", "Blue", "1990", "Economy"}, 0);
    Hypothesis hypo11({"USA", "Chrysler", "Red", "1980", "Economy"}, 0);
    Hypothesis hypo12({"Japan", "Honda", "White", "1980", "Economy"}, 0);
    Hypothesis hypo13({"Japan", "Toyota", "Green", "1980", "Economy"}, 0);
    Hypothesis hypo14({"Japan", "Honda", "Red", "1990", "Economy"}, 0);
    std::vector<Hypothesis> japSportsCar{hypo8, hypo9, hypo10, hypo11, hypo12, hypo13, hypo14};

    candidateE candidElimEcon;
    candidateE candidElimSports;

    candidElimEcon.runcandidateE(generalHypo, specificHypo, japEconCar);
    candidElimSports.runcandidateE(generalHypo, specificHypo, japSportsCar);

    return 0;
}
