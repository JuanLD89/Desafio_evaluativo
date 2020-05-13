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
    bool agregarcombos(string idc,string nomcomb,string precombo);                          //Permite al administrador agregar combos nuevos
    bool codigocombos(string combo__);                                                      //indica los productos y la cantidad de estos
    string productosdesencriptados(string idcombo,string nombrecombo,string valor_combo);   //desencripta la funcion pasada para saber el producto y la cantidad necesaria para crear el combo
    int puntoycoma();                                                                       //calcula el numero de puntos y comas en codigocombos
    bool existencia();                                                                      //busca si una id existe entre los productos disponibles
    void menucombos();                                                                      //despliega el menu para ver los combos
    string comboseleccionado(string idparacombo);                                           //verifica si la id del combo pedido existe y si existe retorna el valor del combo
    void sordenusuario(int valor);                                                          //implementación del problema1 practica2
    string pagocomborealizado(int idparacombos);                                            //resta una unidad a la cantidad de combos disponibles
    bool cntidadcombos(string idcc,string cantidad_combos);                                 //escribe la id con la cantidad de combos en un archivo de texto
    void cantidaddeproductosparaelcombo(int combo);                                         //aumenta la cantidad de combos dependiendo de la cantidad de combos
    string combosdisponibles();                                                             //elimina los combos agotados en el archivo C_combos
    string alteracionencombos(string numeroparacombos);                                     //elimina combos agotados en el archivo combos
    bool reportedeventas(string idparacomboss,string asiento,string sala,string UserName);  //escribe al final el archivo de texto Reportedeventas
    string reportedeventasimpresion();                                                      //imprime el reporte de ventas

};

#endif // COMBOS___H
