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
    void menucombos();
    string comboseleccionado(string idparacombo);
    void sordenusuario(int valor);
    string pagocomborealizado(int idparacombos);
    bool cntidadcombos(string idcc,string cantidad_combos);
    void cantidaddeproductosparaelcombo(int combo);
    string combosdisponibles();
    string alteracionencombos(string numeroparacombos);
    bool reportedeventas(string idparacomboss,string asiento,string sala,string UserName);

};

#endif // COMBOS___H
