#pragma once
#include "Libraries.h"
struct GlobalData {
    double SimulationTime = 500.0;
    double SimulationStepTime = 50.0;
    double Conductivity = 25.0;
    double Alfa = 300;
    double Tot = 1200;
    double InitialTemp = 100;
    double Density = 7800;
    double SpecificHeat = 700;

    int nH = 4;
    int nW = 4;

    int nN = nW * nH;
    int nE = (nH - 1) * (nW - 1);

    void getGlobalData() {
        cout << "SimulationTime " << SimulationTime << endl;
        cout << "SimulationStepTime " << SimulationStepTime << endl;
        cout << "Conductivity " << Conductivity << endl;
        cout << "Alfa " << Alfa << endl;
        cout << "Tot " << Tot << endl;
        cout << "InitialTemp " << InitialTemp << endl;
        cout << "Density " << Density << endl;
        cout << "SpecificHeat " << SpecificHeat << endl;
        cout << "nN " << nN << endl;
        cout << "nE " << nE << endl;
    }
};