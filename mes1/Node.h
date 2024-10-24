#pragma once
#include <iomanip>
#include <iostream>
#include "Element.h"
#include "Libraries.h"
struct Node {
    double x, y;
    std::vector<double> weights;
    std::vector<double> points;

private:
    double scoreX = 0.0;
    double scoreY = 0.0;
    double scoreXY = 0.0;
    double scoreYX = 0.0;

public:

    double macierzJakobiego[4];
    int punktyCalkowania;
    Node(){}

    Node(int iloscWezlow) {
        punktyCalkowania = iloscWezlow*iloscWezlow;
        if (iloscWezlow == 2) {
            addTwoNode();
        }
        else if (iloscWezlow == 3) {
            addThreeNode();
        }
    }

    void addTwoNode() {
        points.push_back(-1.0 / std::sqrt(3.0));
        points.push_back(1.0 / std::sqrt(3.0));

        weights.push_back(1.0);
        weights.push_back(1.0);
    }

    void addThreeNode() {
        points.push_back((std::sqrt(3) / std::sqrt(5)) * (-1));
        points.push_back(0);
        points.push_back(std::sqrt(3) / std::sqrt(5));

        weights.push_back(-5.0 / 9.0);
        weights.push_back(8.0 / 9.0);
        weights.push_back(5.0 / 9.0);
    }
    
    void calculateDerivatives(Element* element) {

        double ksi[4] = { -0.57735, 0.57735, 0.57735, -0.57735 };
        double eta[4] = { -0.57735, -0.57735, 0.57735, 0.57735 };

        for (int i = 0; i < punktyCalkowania; i++) {
            // KSI
            element->Ksi[i][0] = -0.25 * (1 - eta[i]); // dN1/dKsi
            element->Ksi[i][1] = 0.25 * (1 - eta[i]);  // dN2/dKsi
            element->Ksi[i][2] = 0.25 * (1 + eta[i]);  // dN3/dKsi
            element->Ksi[i][3] = -0.25 * (1 + eta[i]); // dN4/dKsi

            // ETA
            element->Eta[i][0] = -0.25 * (1 - ksi[i]); // dN1/dEta
            element->Eta[i][1] = -0.25 * (1 + ksi[i]); // dN2/dEta
            element->Eta[i][2] = 0.25 * (1 + ksi[i]);  // dN3/dEta
            element->Eta[i][3] = 0.25 * (1 - ksi[i]);  // dN4/dEta

            // Wypisanie pochodnych
            //std::cout << "Punkt Gaussa " << i + 1 << std::endl;
            //for (int j = 0; j < 4; j++) {
            //    std::cout << "dN" << j + 1 << "/dKsi = " << element->Ksi[i][j] << "  ";
            //    std::cout << "dN" << j + 1 << "/dEta = " << element->Eta[i][j] << std::endl;
            //}
            //std::cout << std::endl;

            // Obliczanie macierzy Jakobiego
            scoreX = 0.0; scoreXY = 0.0;
            scoreY = 0.0; scoreYX = 0.0;
            for (int j = 0; j < 4; j++) {
                scoreX += element->Ksi[i][j] * element->ExamplesX[j];  // dX/dKsi
                scoreXY += element->Ksi[i][j] * element->ExamplesY[j]; // dX/dEta
                scoreY += element->Eta[i][j] * element->ExamplesY[j];  // dY/dKsi
                scoreYX += element->Eta[i][j] * element->ExamplesX[j];  // dY/dEta
            }

            macierzJakobiego[0] = scoreX;
            macierzJakobiego[1] = scoreXY;
            macierzJakobiego[2] = scoreYX;
            macierzJakobiego[3] = scoreY;

            std::cout << "Macierz Jakobiego (punkt Gaussa " << i + 1 << "):" << std::endl;
            for (int k = 0; k < 4; k++) {
                std::cout << std::setw(12) << std::fixed << std::setprecision(6) << macierzJakobiego[k];
                if (k == 1 || k == 3) std::cout << std::endl;
            }

            double detJ = scoreX * scoreY - scoreXY * scoreYX;
            std::cout << "Wyznacznik macierzy Jakobiego: " << detJ << std::endl;

            double macierzOdwrotna[] = {
                (1 / detJ) * scoreY, (-1 / detJ) * scoreXY,
                (-1 / detJ) * scoreYX, (1 / detJ) * scoreX
            };

            std::cout << "Macierz odwrotna Jakobiego (punkt Gaussa " << i + 1 << "):" << std::endl;
            for (int l = 0; l < 4; l++) {
                if (std::abs(macierzOdwrotna[l]) < 1e-10) macierzOdwrotna[l] = 0.0; // Zerowanie ma³ych wartoœci
                std::cout << std::setw(12) << std::fixed << std::setprecision(6) << macierzOdwrotna[l];
                if (l == 1 || l == 3) std::cout << std::endl;
            }
            std::cout << endl;
        }
    }

    
};