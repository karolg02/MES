#pragma once
#include "Libraries.h"
#include <iomanip>
struct Grid {
    int nN, nE;

    std::vector<Node> node;
    std::vector<Element> element;

    void getGrid() {
        cout << "Nodes:" << endl;
        for (int i = 0; i < nN; i++) {
            cout << setw(3)<< "[" << i + 1 << "] " << setw(10) << node[i].x << " " << setw(10) << node[i].y << endl;
        }
        cout << "Elements:" << endl;
        for (int i = 0; i < nE; i++) {
            cout << setw(3)<< "[" << i + 1 << "] " << setw(3) << element[i].ID[0] << ", " << setw(3) << element[i].ID[1] << ", " << setw(3) << element[i].ID[2] << ", " << setw(3) << element[i].ID[3] << endl;
        }
    }
};