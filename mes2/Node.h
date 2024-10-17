#pragma once
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
        double tabPsi[4];

        double eta = (-1.0 / std::sqrt(3.0));
        double psi = (1.0 / std::sqrt(3.0));

        double N1eta = -1.0 / 4.0 * (1 - eta);
        double N2eta = 1.0 / 4.0 * (1 - eta);
        double N3eta = 1.0 / 4.0 * (1 + eta);
        double N4eta = -1.0 / 4.0 * (1 + eta);

        double N1psi = -1.0 / 4.0 * (1 + psi);
        double N2psi = -1.0 / 4.0 * (1 - psi);
        double N3psi = 1.0 / 4.0 * (1 - psi);
        double N4psi = 1.0 / 4.0 * (1 + psi);

        tabEta[0] = N1eta;
        tabEta[1] = N2eta;
        tabEta[2] = N3eta;
        tabEta[3] = N4eta;

        tabPsi[0] = N1psi;
        tabPsi[1] = N2psi;
        tabPsi[2] = N3psi;
        tabPsi[3] = N4psi;

        std::cout << "Pochodne:" << std::endl;
        std::cout << "N1eta = " << N1eta << std::endl;
        std::cout << "N2eta = " << N2eta << std::endl;
        std::cout << "N3eta = " << N3eta << std::endl;
        std::cout << "N4eta = " << N4eta << std::endl << std::endl;

        std::cout << "N1psi = " << N1psi << std::endl;
        std::cout << "N2psi = " << N2psi << std::endl;
        std::cout << "N3psi = " << N3psi << std::endl;
        std::cout << "N4psi = " << N4psi << std::endl << std::endl;

        double scoreX = 0.0;
        double scoreY = 0.0;
        double scoreXY = 0.0;
        double scoreYX = 0.0;

        double przykladyX[4] = { 0, 4, 4, 0 };
        double przykladyY[4] = { 0, 0, 4, 5 };

        for (int i = 0; i < 4; i++) {
            scoreX += tabEta[i] * przykladyX[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreXY += tabEta[i] * przykladyY[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreY += tabPsi[i] * przykladyY[i];
        }

        for (int i = 0; i < 4; i++) {
            scoreYX += tabPsi[i] * przykladyX[i];
        }

        std::cout << "x = " << scoreX << std::endl;
        std::cout << "y = " << scoreY << std::endl;
        std::cout << "YX = " << scoreYX << std::endl;
        std::cout << "XY = " << scoreXY << std::endl;
        std::cout << std::endl;

        double detJ = scoreX * scoreY - scoreXY * scoreYX;
        std::cout << "Wyznacznik macierzy Jakobiego to: " << detJ << std::endl;
    }

};