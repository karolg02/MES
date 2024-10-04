#pragma once
#include "Libraries.h"
struct GlobalData {
    double SimulationTime, SimulationStepTime, Conductivity, Alfa, Tot, InitialTemp, Density, SpecificHeat, nN, nE;

    void getGlobalData() {
        cout << "SimulationTime " << SimulationTime << endl;
        cout << "SimulationStepTime " << SimulationStepTime << endl;
        cout << "Conductivity " << Conductivity << endl;
        cout << "Alfa " << Alfa << endl;
        cout << "InitialTemp " << InitialTemp << endl;
        cout << "Density " << Density << endl;
        cout << "SpecificHeat " << SpecificHeat << endl;
        cout << "nN " << nN << endl;
        cout << "nE " << nE << endl;
    }
};