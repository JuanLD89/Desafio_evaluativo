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
    string productosdesencriptados(string idcombo,string nombrecombo,string valor_combo);
    string combocreado();
    int saltosdelinea();
    int puntoycoma();
    bool existencia();
    string menucombos();
    string comboseleccionado(string idparacombo);

};

#endif // COMBOS___H
