#ifndef ACCESO_H
#define ACCESO_H

#include <iostream>
#include <string.h>
#include <fstream>
#include <stdlib.h>

using namespace std;

//definir clases

class acceso
{
public:
    string Desplegar();
    bool agregar(string id,string producto,string cantidad,string costo);
    string sinespacios();
    bool accesos(string UserName,string clave1);
    bool Desplegar1(string UserName);
    int cantidad();
};

#endif // ACCESO_H
