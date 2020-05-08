#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "acceso.h"

using namespace std;

int main()
{
    bool confirmacion;
    cout<<"-Si desea ingresar como administrador el usuario es: " << "administrador"<<endl;
    cout<<"-La clave es: cajero"<<endl;
    cout<<"-Si desea cambiar el nombre de usuario, ingrese al codigo y en la plantilla acceso\nen la funcion llamada accesos, lo puede cambiar"<<endl;
    cout<<"-Ahora si desea cambiar la clave tocaria ir al archivo de texto conocido como sudo y cambiarla"<<"\n\n"<<endl;
    string UserName,clave1;
    int a, accion, controlador=0;
    cout << "-Si desea ingresar como administrador ingrese 1, " <<endl;
    cout << "-Si desea ingresar como usuario ingrese 2 " <<endl;
    cin>>controlador;
    if (controlador==1){
        cout<<"Ingrese el usuario: ";
        cin>>UserName;
        acceso Usuario;
        clave1=Usuario.Desplegar();
        confirmacion=Usuario.accesos(UserName,clave1);
        if (confirmacion==true){
            cout<< "acceso permitido"<<endl;
        }
        else {
            cout << "acceso denegado"<<endl;
        }
        if (confirmacion==true){
            cout<<"Si desea ejecutar alguna accion como administrador ingrese 1, de lo contario ingrese otro numero."<<endl;
            cin>>a;
            while(a==1){
                cout<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<"|              MENU                |"<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<"|1.Ingresar productos al inventario|"<<endl;
                cout<<"|2.         Crear combos           |"<<endl;
                cout<<"|3. Reporte de ventas realizadas   |"<<endl;
                cout<<"|4.            Salir               |"<<endl;
                cout<<"------------------------------------"<<endl;

                cin >> accion;
                if (accion==1){
                    cout<<"-En mantenimiento ";
                }
                if (accion==2){
                    cout<<"-En mantenimiento ";
                }
                if (accion==3){
                    cout<<"-En mantenimiento ";
                }
                if (accion==4){
                    break;
                }
            }
        }
    }
}
