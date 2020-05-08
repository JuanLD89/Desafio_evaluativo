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

bool acceso::agregar(string id, string producto, string cantidad, string costo)
{
    ofstream registro;
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::app);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<id;
    registro<<"     ";
    registro<<producto;
    registro<<"     ";
    registro<<cantidad;
    registro<<"     ";
    registro<<costo;
    registro<<endl;

    return true;
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
int acceso::cantidad()
{
    int cantidadparaarreglo=1;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/usuarios.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
    if (registro.good()){
        if (tem=='\n'){
            cantidadparaarreglo+=1;
            }
        }
    }
    return cantidadparaarreglo;
}

bool acceso::Desplegar1(string UserName){
    bool flag=false;
    string datos;
    string arreglo[1][3];
    int contador1=0,contador2=0,contador3=0;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/usuarios.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
    if (registro.good()){

        if (tem!=' ' || tem!='\n'){
            datos+=tem;
            }
        if (tem==' ' || tem=='\n'){
            arreglo[contador2][contador1]=datos;
            contador1=contador1+1;
            if (tem=='\n'){
                contador2=contador2+1;
                contador1=0;
                }
            datos="";
            }
        }
    }
    string key,user,compararclave;
    for (int t=0;t<1;t++){
        user=arreglo[contador3][0];
        if (UserName==user){
            flag=true;
            break;
        }
        contador3=contador3+1;
    }
    compararclave=arreglo[contador3][1];
        if (flag==true){
            cout<<"ingrese clave: ";
            cin>>key;
            if((key+' ')==compararclave){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
}
