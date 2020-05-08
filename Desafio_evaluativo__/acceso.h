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
    bool accesos(string UserName,string clave1);
};

#endif // ACCESO_H
