#include <iostream>
#include <vector>
#include "Node.h"

double f(double x, double y) {
	return 5 * x * x * y*y + 3 * x * y + 6;
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
	Node Node(2);
	std::cout << gaussLegrende(f, Node);
	return 0;
}