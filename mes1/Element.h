#pragma once
#include "Libraries.h"
struct Element {
    int ID[4];

    double Ksi[4];
    double Eta[4];
    double ExamplesX[4];
    double ExamplesY[4];

    void addExamplesX(double x1, double x2, double x3, double x4) {
        ExamplesX[0] = x1;
        ExamplesX[1] = x2;
        ExamplesX[2] = x3;
        ExamplesX[3] = x4;
    }

    void addExamplesY(double y1, double y2, double y3, double y4) {
        ExamplesY[0] = y1;
        ExamplesY[1] = y2;
        ExamplesY[2] = y3;
        ExamplesY[3] = y4;
    }
};