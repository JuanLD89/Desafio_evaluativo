#include "comboss.h"
#include "acceso.h"


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

bool comboss::codigocombos(string combo__)
{
    ofstream registro;
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::out);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<combo__;
    registro<<endl;

    return true;
}

string comboss::productosdesencriptados()
{
    acceso func;
    string dat,arr;
    string arreglo[puntoycoma()][2];
    int cont1=0,cont2=0;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            if (tem==',' || tem=='\n'){
                arreglo[cont1][cont2]=dat;
                dat="";
                cont2+=1;
            }
            if (tem==';'){
                arreglo[cont1][cont2]=dat;
                cont1+=1;
                cont2=0;

                dat="";
            }
            if (tem==',' || tem == ';' || tem =='\n'){
            }
            else{
                dat+=tem;
            }
        }
    }
    string datos="";
    string arreg[func.cantidad1()-1][4];
    int contador1=0,contador2=0,cantidad2=func.cantidad1()-1,temporal_,temporal_2;
    ifstream regis;
    regis.open("../Desafio_evaluativo__/Productos.txt", ios::in);
    if (regis.fail())
        cerr << "Error" << endl;
    while (regis.good()){
        char tem=regis.get();
        if (regis.good()){
            if (tem!=' ' || tem!='\n'){
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;
                }
                }
            if (tem==' ' || tem=='\n'){
                arreg[contador2][contador1]=datos;
                contador1=contador1+1;
                if (tem=='\n'){
                    contador2=contador2+1;
                    contador1=0;
                    }
                datos="";
                }

            }
    }
    bool flag=false;
    int c1=0,c2=0,restantess;
    int c3=0;
    int contadorespecial=0;
    int final_=func.cantidad1()-2;
    string compara1,compara2;
    for (int h=0;h<final_;h++){
        compara1=arreglo[c1][c2];
        compara2=arreg[c3][0];
        compara1+=' ';
        if(contadorespecial==puntoycoma()-1){
            break;
        }
        if (compara1==compara2){
            c2+=1;
            temporal_=stoi(arreg[c3][2]);
            temporal_2=stoi(arreglo[c1][c2]);
            if (temporal_>=temporal_2){
                flag=true;
                c1+=1;
                c2=0;
                c3=0;
            }
            else{
                return "No tiene la cantidad de productos suficientes para este combo";
            }
         }

         else{
             flag=false;
         }
        c3+=1;
        contadorespecial+=1;
    }
    c1=0;
    c2=0;
    c3=0;

    if (flag==true){
        for (int h=0;h<=final_;h++){
            compara1=arreglo[c1][c2];
            compara2=arreg[c3][0];
            compara1+=' ';
            if (compara1==compara2){
                c2+=1;
                temporal_=stoi(arreg[c3][2]);
                temporal_2=stoi(arreglo[c1][c2]);
                if (temporal_>=temporal_2){
                    restantess=temporal_-temporal_2;
                    string numeroComoCadena = to_string(restantess);
                    arreg[c3][2]=numeroComoCadena+ ' ';
                    ofstream regi;
                    regi.open("../Desafio_evaluativo__/Productos.txt", ios::out);
                    if (regi.fail())
                        cerr << "Error----------------" << endl;
                    for(int j=0;j<cantidad2;j++){
                        for(int r=0;r<4;r++){
                            arr=arreg[j][r];
                            regi<<arr;
                            if (r==3 && j<=cantidad2-2){
                                regi<<'\n';
                            }
                        }
                    }
                    regi.close();
                    c2=0;
                }
             }
            c3+=1;
        }
    }
    else{
        return "ID no existente.....";
    }
    return "Combo creado....";

}

int comboss::saltosdelinea()
{
    int cantidadparaarreglo=1;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);
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

int comboss::puntoycoma()
{
    int cantidadparaarreglo=1;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            if (tem==';'){
                cantidadparaarreglo+=1;
            }
        }
        if (tem=='\n'){
            return cantidadparaarreglo;
        }
    }
    return cantidadparaarreglo;
}

