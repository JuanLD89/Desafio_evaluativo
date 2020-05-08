#include "acceso.h"
#include <fstream>
#include <stdlib.h>
#include <string>

string acceso::Desplegar(){
    string clave1;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/clave_admin.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
    if (registro.good()){
        clave1+=tem;
        }
    }
    return clave1;
}
bool acceso::accesos(string UserName,string datos){
    bool flag=false;
    string Key;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/clave_admin.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    if (UserName=="administrador"){      //Si desea cambiar el usuario del administrador, cambie el nombre de esta linea conocida como "administrador"
        flag=true;                      //Ahora si desea cambiar la clave tocaria ir al archivo de texto conocido como sudo y cambiarla
    }
    else {
        return false;
    }
    if (flag==true){
        cout<<"ingrese clave: ";
        cin>>Key;
        if (Key==datos){
            return true;
        }
        else {
            return false;
        }
    }
}
