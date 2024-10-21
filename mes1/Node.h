#pragma once
#include <iomanip>
#include <iostream>
#include "Element.h"
#include "Libraries.h"
struct Node {
    double x, y;

    std::vector<double> weights;
    std::vector<double> points;

    Node(){}

    Node(int iloscWezlow) {
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

    void calculateDerivatives(Element *element) {

        //points[0] - eta (-)
        //points[1] - ksi (+)

        element->Eta[0] = -1.0 / 4.0 * (1 - points[0]);
        element->Eta[1] = 1.0 / 4.0 * (1 - points[0]);
        element->Eta[2] = 1.0 / 4.0 * (1 + points[0]);
        element->Eta[3] = -1.0 / 4.0 * (1 + points[0]);

        element->Ksi[0] = -1.0 / 4.0 * (1 + points[1]);
        element->Ksi[1] = -1.0 / 4.0 * (1 - points[1]);
        element->Ksi[2] = 1.0 / 4.0 * (1 - points[1]);
        element->Ksi[3] = 1.0 / 4.0 * (1 + points[1]);

        std::cout << "Pochodne:" << std::endl;
        std::cout << "N1eta = " << element->Eta[0] << std::endl;
        std::cout << "N2eta = " << element->Eta[1] << std::endl;
        std::cout << "N3eta = " << element->Eta[2] << std::endl;
        std::cout << "N4eta = " << element->Eta[3] << std::endl << std::endl;

        std::cout << "N1ksi = " << element->Ksi[0] << std::endl;
        std::cout << "N2ksi = " << element->Ksi[1] << std::endl;
        std::cout << "N3ksi = " << element->Ksi[2] << std::endl;
        std::cout << "N4ksi = " << element->Ksi[3] << std::endl << std::endl;

        double scoreX = 0.0;
        double scoreY = 0.0;
        double scoreXY = 0.0;
        double scoreYX = 0.0;

        for (int i = 0; i < 4; i++) {
            scoreX += element->Eta[i] * element->ExamplesX[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreXY += element->Eta[i] * element->ExamplesY[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreY += element->Ksi[i] * element->ExamplesY[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreYX += element->Ksi[i] * element->ExamplesX[i];
        }

        double macierzJakobiego[] = {
            scoreX,scoreXY,
            scoreYX, scoreY
        };

        std::cout << "Macierz Jakobiego" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << std::setw(3) << std::setprecision(3) << macierzJakobiego[i] << " ";
            if (i == 1 || i == 3) {
                std::cout << std::endl;
            }
        }

        double detJ = scoreX * scoreY - scoreXY * scoreYX;
        std::cout << "Wyznacznik macierzy Jakobiego to: " << detJ << std::endl << std::endl;

        //odwrotnosc
        std::cout << "Macierz odwrotna:" << std::endl;

        double macierzOdwrotna[] = {
            (1 / detJ) * scoreY,(-1 / detJ) * scoreXY,
            (-1 / detJ) * scoreYX,(1 / detJ) * scoreX
        };

        for (int i = 0; i < 4; i++) {
            std::cout << std::setw(3) << std::setprecision(3) << macierzOdwrotna[i] << " ";
            if (i == 1 || i == 3) {
                std::cout << std::endl;
            }
        }

    }
};