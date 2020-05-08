#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "acceso.h"
#include <conio.h>

using namespace std;

int main()
{
    bool confirmacion;
    cout<<"-Si desea ingresar como administrador el usuario es: " << "administrador"<<endl;
    cout<<"-La clave es: cajero"<<endl;
    cout<<"-Si desea cambiar el nombre de usuario, ingrese al codigo y en la plantilla acceso\nen la funcion llamada accesos, lo puede cambiar"<<endl;
    cout<<"-Ahora si desea cambiar la clave tocaria ir al archivo de texto conocido como sudo y cambiarla"<<"\n\n"<<endl;
    char producto[100];
    string UserName,clave1,UserName1,id,cantidad,costo,producto1;
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
                cout<<endl;

                cin >> accion;
                if (accion==1){
                    cout<<"-Ingrese ID: "; cin >> id;
                    cin.ignore();

                    cout<<"Ingresa una palabra: ";
                    cin.getline(producto,100);//optienes la cadena completa del arreglo
                    for(int  i = 0; producto[i] != 0;++i)
                        if(producto[i] != 32)//32 significa espacio en codigo ascii!!
                            producto1+=producto[i];

                    cout<<"-Ingrese Cantidad: "; cin >> cantidad;
                    cout<<"-Ingrese costo: "; cin >> costo;
                    Usuario.agregar(id,producto1,cantidad,costo);
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
                //else{break;}
            }
        }
    }

    if (controlador==2){
        cout<<"Ingrese el usuario: ";
        cin>>UserName1;
        acceso Usuario;
        confirmacion=Usuario.Desplegar1((UserName1+ ' '));
        if (confirmacion==true){
            cout<< "acceso permitido"<<endl;
        }
        else {
            cout << "acceso denegado"<<endl;
        }
        if (confirmacion==true){
            cout<<endl;
            cout<<"                     Oferta de Combos                    "<<endl;
            cout<<"---------------------------------------------------------"<<endl;
            cout<<"||Combos                  Productos               Costo||"<<endl;
            cout<<"_________________________________________________________"<<endl;
            cout<<"---------------------------------------------------------"<<endl;
            cout<<"||   1    Dos perros calientes y dos gaseosas    $35000||"<<endl;
            cout<<"||   2           Dos gaseosas con nachos         $17900||"<<endl;
            cout<<"||   3           hambuerguesa mas gaseosa        $16500||"<<endl;
            cout<<"---------------------------------------------------------"<<endl;
            cout<<endl;
            cout<<"Si desea ejecutar alguna accion como usuario ingrese 1, de lo contario ingrese otra letra"<<endl;
            cin>>a;
            while(a==1){
                cout<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<"|              MENU                |"<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<"|1.       seleccionar combo        |"<<endl;
                cout<<"|2.            Salir               |"<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<endl;
                cin >> accion;
                if (accion==1){
                   cout<<"-En mantenimiento"<<endl;
                }
                if (accion==2){
                    break;
                }
            }
        }
        return 0;
    }
}
