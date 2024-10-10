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
};