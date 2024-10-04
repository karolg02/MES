#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
void loadGlobalData(GlobalData* globaldata, Grid* grid) {
    std::ifstream file("test.txt");

    std::string temp, line;
    std::stringstream xline;

    Node node;

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->SimulationTime;
    xline.clear();


    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->SimulationStepTime;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->Conductivity;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->Alfa;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->Tot;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->InitialTemp;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->Density;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> globaldata->SpecificHeat;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> temp >> globaldata->nN;
    xline.clear();

    getline(file, line);
    xline.str(line);
    xline >> temp >> temp >> globaldata->nE;
    xline.clear();

    grid->nN = globaldata->nN;
    grid->nE = globaldata->nE;

    //Node

    getline(file, line);

    char temporaryChar;
    int temporaryInt;

    for (int i = 0; i < globaldata->nN; i++) {
        getline(file, line);
        xline.str(line);
        xline >> temporaryInt >> temporaryChar >> node.x >> temporaryChar >> node.y;
        grid->node.push_back(node);
        xline.clear();
    }

    getline(file, line);

    Element temporaryElement;

    for (int i = 0; i < globaldata->nE; i++) {
        getline(file, line);
        xline.str(line);
        xline >> temporaryInt >> temporaryChar >> temporaryElement.ID[0] >> temporaryChar >> temporaryElement.ID[1] >> temporaryChar >> temporaryElement.ID[2] >> temporaryChar >> temporaryElement.ID[3];
        grid->element.push_back(temporaryElement);
        xline.clear();
    }

    file.close();
}