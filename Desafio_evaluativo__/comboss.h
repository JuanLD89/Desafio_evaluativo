#ifndef COMBOSS_H
#define COMBOSS_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;


class comboss
{
public:
    bool agregarcombos(string idc,string nomcomb,string precombo);
    bool codigocombos(string combo__);
    string productosdesencriptados();
    string combocreado();
    int saltosdelinea();
    int puntoycoma();

};

#endif // COMBOS___H
