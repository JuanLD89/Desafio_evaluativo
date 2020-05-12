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
    string Cproductos(string idplus);
    bool accesos(string UserName,string clave1);
    bool Desplegar1(string UserName);
    int cantidad();
    int cantidad1();
    int cantidad2();
    int cantidad3();
    int productexistente(int aentero,int plusproductoexistente, string idplus);
    string inventario();
    string generarid();
    string generaridcombo();
    bool agregarusuario(string usuario, string contasena);

};

#endif // ACCESO_H
