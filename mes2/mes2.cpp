#include <iostream>
#include <vector>

double f(double x, double y) {
	return 5 * x * x * y*y + 3 * x * y + 6;
}

struct wezly {
	std::vector<double> weights;
	std::vector<double> points;

	wezly(int iloscWezlow) {
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

double gaussLegrende(double (*function)(double, double), wezly node) {

	double score = 0.0;

	for (int i = 0; i < node.points.size(); i++) {
		for (int j = 0; j < node.points.size(); j++) {
			score += function(node.points[i], node.points[j]) * node.weights[i] * node.weights[j];
		}
	}

	return score;

}

int main() {
	//2 lub 3
	wezly Node(2);
	double wynik = gaussLegrende(f, Node);
	std::cout << wynik;
	return 0;
}