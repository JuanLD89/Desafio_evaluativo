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
    registro<<" ";
    registro<<producto;
    registro<<" ";
    registro<<cantidad;
    registro<<" ";
    registro<<costo;
    registro<<endl;

    return true;
}

string acceso::sinespacios()
{
    char producto[100];
    string producto1;

    cout<<"Ingresa una palabra: ";
    cin.getline(producto,100);//optienes la cadena completa del arreglo

    for(int  i = 0; producto[i] != 0;++i)
        if(producto[i] != 32)//32 significa espacio en codigo ascii!!
            producto1+=producto[i];
    return producto1;
}

string acceso::Cproductos(string idplus)
{
    string datos,user,saldo2;
    string arreglo[cantidad1()][4];
    int contador1=0,contador2=0,contador3=0;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);
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
    for (int t=0;t<(cantidad1()-1);t++){
        user=arreglo[contador3][0];
        saldo2=arreglo[contador3][2];
        if (idplus==user){
            return saldo2;
        }
            contador3+=1;
    }
}

bool acceso::accesos(string UserName,string datos){
    bool flag=false;
    string Key;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/clave_admin.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    if (UserName=="Administrador"){      //Si desea cambiar el usuario del administrador, cambie el nombre de esta linea conocida como "administrador"
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

int acceso::cantidad1()
{
    int cantidadparaarreglo=1;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);
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

int acceso::productexistente(int aentero, int plusproductoexistente, string idplus)
{
    string datos,user,saldo2,arr;
    string arreglo[cantidad1()][4];
    int contador1=0,contador2=0,contador3=0,restante,cantidad2=cantidad1();
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;
                }
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
    arreglo[contador2][contador1]=datos;
    for (int t=0;t<(cantidad1()-1);t++){
        user=arreglo[contador3][0];
        saldo2=arreglo[contador3][2];
        if (idplus==user){
            restante=aentero+plusproductoexistente;
            std::string numeroComoCadena = std::to_string(restante);
            arreglo[contador3][2]=numeroComoCadena+' ';
            ofstream registro;
            registro.open("../Desafio_evaluativo__/Productos.txt", ios::out);
            if (registro.fail())
                cerr << "Error" << endl;
            for(int j=0;j<cantidad2;j++){
                for(int r=0;r<4;r++){
                    arr=arreglo[j][r];
                    registro<<arr;
                    if (r==3 && j!=cantidad1()+2){
                        registro<<'\n';
                    }
                }
             }
             registro.close();
             return restante;
        }
        contador3+=1;
    }

}

string acceso::inventario()
{
    string info;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            info+=tem;
        }

    }
    return info;
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
        }
        contador3=contador3+1;
    }
    if (flag==true){
        return true;
    }

    else {
        return false;
    }
}
