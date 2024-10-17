#include <iostream>
#include <vector>
#include "Node.h"

double f(double x, double y) {
	return -2 * x * x * y + 2 * x * y + 4;
}

double gaussLegrende(double (*function)(double, double), Node node) {

	double score = 0.0;

	for (int i = 0; i < node.points.size(); i++) {
		for (int j = 0; j < node.points.size(); j++) {
			score += function(node.points[i], node.points[j]) * node.weights[i] * node.weights[j];
		}
	}

	return score;

}

int main() {
	//2 or 3 nodes
	Node node(2);
	//std::cout << gaussLegrende(f, node) << std::endl;

	//1 = (-1.0 / std::sqrt(3.0))
	//2 = (1.0 / std::sqrt(3.0))
	node.calculateDerivatives();

	return 0;
}