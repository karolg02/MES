#pragma 
void fixed(GlobalData* globaldata, Grid* grid) {
	grid->nN = globaldata->nN;
	grid->nE = globaldata->nE;
    //4x4(bo node'y)
    Node node;
    double width = 3.0;
    double height = 3.0;
    for (int i = 0; i < globaldata->nW; i++) {
        for (int j = 0; j < globaldata->nH; j++) {
            int index = j + (i * globaldata->nH);
            double x = i * (width / (globaldata->nW - 1));
            double y = j * (height / (globaldata->nH - 1));
            node.x = x;
            node.y = y;
            grid->node.push_back(node);
        }
    }

	//3x3(elementy)
    Element temporaryElement;
    int nodeId = 1;
    for (int i = 0; i < globaldata->nH-1; i++) {
        for (int j = 0; j < globaldata->nW-1; j++) {
            int n1 = nodeId + i * 4 + j;    // lewy dolny
            int n2 = n1 + 1;                // prawy dolny
            int n3 = n1 + 4 + 1;            // prawy gorny
            int n4 = n1 + 4;                // lewy gorny
            temporaryElement = { n1, n2, n3, n4 };
            grid->element.push_back(temporaryElement);
        }
    }
}