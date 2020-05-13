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
    string Desplegar();                                                         //retorna la clave del administrador
    bool agregar(string id,string producto,string cantidad,string costo);       //para agregar productos al inventario
    string sinespacios();                                                       //quitar los espacion de un string
    string Cproductos(string idplus);                                           //retornar la cantidad de productos
    bool accesos(string UserName,string clave1);                                //Administra el ingreso como administrador
    bool Desplegar1(string UserName);                                           //Administra el ingreso como administrador
    int cantidad();                                                             //cantidad de saltod de linea en usuarios
    int cantidad1();                                                            //cantidad de saltod de linea en productos
    int cantidad2();                                                            //cantidad de saltod de linea en combos
    int cantidad3();                                                            //cantidad de saltod de linea en C_combos
    int productexistente(int aentero,int plusproductoexistente, string idplus); //adiciona cantidad de productos en productos
    string inventario();                                                        //imprime el inventario de productos
    string generarid();                                                         //crea una nueva id
    string generaridcombo();                                                    //crea una nueva id para combos
    bool agregarusuario(string usuario, string contasena);                      //permite al administrador agragar usuarios

};

#endif // ACCESO_H
