#pragma once
#include <iomanip>
struct Node {
	std::vector<double> weights;
	std::vector<double> points;

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

    void calculateDerivatives() {
        double tabEta[4];
        double tabKsi[4];

        double eta = (-1.0 / std::sqrt(3.0));
        double ksi = (1.0 / std::sqrt(3.0));

        double N1eta = -1.0 / 4.0 * (1 - eta);
        double N2eta = 1.0 / 4.0 * (1 - eta);
        double N3eta = 1.0 / 4.0 * (1 + eta);
        double N4eta = -1.0 / 4.0 * (1 + eta);

        double N1ksi = -1.0 / 4.0 * (1 + ksi);
        double N2ksi = -1.0 / 4.0 * (1 - ksi);
        double N3ksi = 1.0 / 4.0 * (1 - ksi);
        double N4ksi = 1.0 / 4.0 * (1 + ksi);

        tabEta[0] = N1eta;
        tabEta[1] = N2eta;
        tabEta[2] = N3eta;
        tabEta[3] = N4eta;

        tabKsi[0] = N1ksi;
        tabKsi[1] = N2ksi;
        tabKsi[2] = N3ksi;
        tabKsi[3] = N4ksi;

        std::cout << "Pochodne:" << std::endl;
        std::cout << "N1eta = " << N1eta << std::endl;
        std::cout << "N2eta = " << N2eta << std::endl;
        std::cout << "N3eta = " << N3eta << std::endl;
        std::cout << "N4eta = " << N4eta << std::endl << std::endl;

        std::cout << "N1ksi = " << N1ksi << std::endl;
        std::cout << "N2ksi = " << N2ksi << std::endl;
        std::cout << "N3ksi = " << N3ksi << std::endl;
        std::cout << "N4ksi = " << N4ksi << std::endl << std::endl;

        double scoreX = 0.0;
        double scoreY = 0.0;
        double scoreXY = 0.0;
        double scoreYX = 0.0;

        //double przykladyX[4] = { 0, 4, 4, 0 };
        //double przykladyY[4] = { 0, 0, 4, 5 };
        double przykladyX[4] = { 0,0.025,0.025,0 };
        double przykladyY[4] = { 0,0,0.025,0.025 };

        for (int i = 0; i < 4; i++) {
            scoreX += tabEta[i] * przykladyX[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreXY += tabEta[i] * przykladyY[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreY += tabKsi[i] * przykladyY[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreYX += tabKsi[i] * przykladyX[i];
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
        std::cout << "Wyznacznik macierzy Jakobiego to: " << detJ << std::endl;

        //odwrotnosc
        std::cout << (1 / detJ) * (scoreX * scoreY - (-1) * scoreXY * (-1) * scoreYX) << std::endl;

    }

};