#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include "acceso.h"
#include <conio.h>
#include "comboss.h"

using namespace std;

int main()
{
    bool confirmacion;
    char producto[100];
    string UserName,clave1,UserName1,id,cantidad,costo,producto1,actualizar,resultadocombo,idplus,informacion,idcombo,nombrecombo,combo,valor_combo;
    int a, accion,adminprimeropcion,aentero,plusproductoexistente,temporal;
    cout<<"Ingrese codigo de la boleta: ";
    cin>>UserName;
    comboss Crearcomboss;
    acceso Usuario;
    clave1=Usuario.Desplegar();
    confirmacion=Usuario.accesos(UserName,clave1);
    if (confirmacion==true){
        if (confirmacion==true){
            cout<< "acceso permitido"<<endl;
        }
        else {
            cout << "acceso denegado"<<endl;
        }
        if (confirmacion==true){
            cout<<"Si desea ejecutar alguna accion como administrador ingrese 1, de lo contario ingrese otro numero: ";
            cin>>a;
            while(a==1){
                cout<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<"|              MENU                |"<<endl;
                cout<<"------------------------------------"<<endl;
                cout<<"|1.Ingresar productos al inventario|"<<endl;
                cout<<"|2.      Mostrar Inventario        |"<<endl;
                cout<<"|3.         Crear combos           |"<<endl;
                cout<<"|4. Reporte de ventas realizadas   |"<<endl;
                cout<<"|5.            Salir               |"<<endl;
                cout<<"------------------------------------"<<endl;

                cin >> accion;
                if (accion==1){
                    cout<<"1. Agregar producto existente al inventario"<<endl;
                    cout<<"2. Agregar producto nuevo al inventario    "<<endl;
                    cin>>adminprimeropcion;
                    cout<<endl;
                    if (adminprimeropcion == 1){
                        informacion=Usuario.inventario();
                        cout<<endl;
                        cout<<informacion<<endl;
                        cout<<"Ingrese la ID del producto desea agregar: ";  cin>>idplus;
                        actualizar=Usuario.Cproductos((idplus+ ' '));
                        string a = actualizar;
                        aentero= stoi(a);       //convertir string  a entero
                        cout<<"Que cantidad desea agregar? ";
                        cin>>plusproductoexistente;
                        Usuario.productexistente(aentero,plusproductoexistente,(idplus+ ' '));
                    }
                    if (adminprimeropcion == 2){
                        id=Usuario.generarid();
                        if (idcombo==""){
                            idcombo="0";
                        }
                        temporal=stoi(id);
                        temporal+=1;
                        id=to_string(temporal);
                        cin.ignore();

                        cout<<"Ingrese producto: ";
                        cin.getline(producto,100);//optienes la cadena completa del arreglo
                        for(int  i = 0; producto[i] != 0;++i)
                            if(producto[i] != 32)//32 significa espacio en codigo ascii!!
                                producto1+=producto[i];

                        cout<<"-Ingrese Cantidad: "; cin >> cantidad;
                        cout<<"-Ingrese costo: "; cin >> costo;
                        Usuario.agregar(id,producto1,cantidad,costo);
                    }
                }
                if (accion==2){
                    informacion=Usuario.inventario();
                    //printf("%30s",informacion);
                    cout << informacion;
                    cout<<endl;

                }
                if (accion==3){
                    idcombo=Usuario.generaridcombo();
                    temporal=stoi(idcombo);
                    temporal+=1;
                    idcombo=to_string(temporal);
                    cout<<"Que nombre desea ponerle al combo?: ";  cin>>nombrecombo;
                    informacion=Usuario.inventario();
                    cout << informacion;
                    cout <<endl;
                    cout <<"Escriba el ID de los productos que requiere el combo y la cantidad de estos separados por coma"<<endl;
                    cout <<"Separa con punto y coma los diferentes productos: ";      cin>>combo;
                    cout <<"Esriba el valor que desea ponerle al combo: ";        cin >>valor_combo;
                    Crearcomboss.codigocombos(combo);
                    resultadocombo=Crearcomboss.productosdesencriptados(idcombo,nombrecombo,valor_combo);
                    cout<<resultadocombo<<endl;

                }

                bool resu;
                if (accion==4){
                    resu=Crearcomboss.existencia();
                    cout<<resu<<endl;
                }
                if (accion==5){
                    break;
                }
                //else{break;}
            }
        }
    }

    else{
        acceso Usuario;
        confirmacion=Usuario.Desplegar1((UserName+ ' '));
        if (confirmacion==true){
            cout<< "Boleta valida"<<endl;
        }
        else {
            cout << "Boleta invalida"<<endl;
        }
        if (confirmacion==true){
            cout<<endl;
            cout<<"_________________________________________________________"<<endl;
            cout<<"||                    Oferta de Combos                 ||"<<endl;
            cout<<"---------------------------------------------------------"<<endl;
            cout<<"||Combos                  Productos               Costo||"<<endl;
            cout<<"========================================================="<<endl;
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
