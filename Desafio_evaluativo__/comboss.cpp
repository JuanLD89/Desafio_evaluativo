#include "comboss.h"


bool comboss::agregarcombos(string idc, string nomcomb, string precomb)
{
    ofstream registro;
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::app);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<idc;
    registro<<" ";
    registro<<nomcomb;
    registro<<" ";
    registro<<precomb;
    registro<<endl;

    return true;
}
