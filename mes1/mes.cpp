#include "Node.h"
#include "Element.h"
#include "Grid.h"
#include "GlobalData.h"
#include "LoadGlobalData.h"
#include "Fixed.h"

using namespace std;

int main()
{
    GlobalData* globaldata = new GlobalData;
    Grid* grid = new Grid;
    
    fixed(globaldata, grid);

    //globaldata->getGlobalData();

    grid->getGrid();


    return 0;
}