#include "Node.h"
#include "Element.h"
#include "Grid.h"
#include "GlobalData.h"
#include "LoadGlobalData.h"
#include "Fixed.h"
#include "vector"

using namespace std;

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

void lab1() {
    GlobalData* globaldata = new GlobalData;
    Grid* grid = new Grid;

    loadGlobalData(globaldata, grid);

    globaldata->getGlobalData();

    grid->getGrid();
}

void lab2() {
    //2 or 3 nodes
    Node node(2);
    std::cout << gaussLegrende(f, node) << std::endl;
}

void lab3() {
    Node node(2);
    Element element;
    //element.addExamplesX(0, 0.025, 0.025, 0);
    //element.addExamplesY(0, 0, 0.025, 0.025);
    //node.calculateDerivatives(&element);
    //element.addExamplesX(0, 4, 4, 0);
    //element.addExamplesY(0, 0, 4, 4);
    //node.calculateDerivatives(&element);
    //element.addExamplesX(0, 4, 4, 0);
    //element.addExamplesY(0, 0, 4, 5);
    //node.calculateDerivatives(&element);
    element.addExamplesX(0.01, 0.025, 0.025, 0);
    element.addExamplesY(-0.01, 0, 0.025, 0.025);
    node.calculateDerivatives(&element);
}

void lab4(){}

int main()
{
    //lab1();
    //lab2();
    lab3();
    return 0;
}