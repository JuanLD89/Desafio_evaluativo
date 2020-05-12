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
    string UserName,clave1,UserName1,id,cantidad,costo,producto1="",actualizar;
    string resultadocombo,idplus,informacion,idcombo,nombrecombo,combo,valor_combo,cantidad_combos;
    comboss Crearcomboss;
    acceso Usuario;
    int a, accion,adminprimeropcion,aentero,plusproductoexistente,temporal, pago,devuelta,cppc;
    int adminousuario=1,eleccion___;
    while (adminousuario==1){
        cout<<"Que accion desea tomar:"<<endl;
        cout<<"1. Ingresar como Administrador."<<endl;
        cout<<"2. Ingresar como Usuario."<<endl;
        cout<<"3. Salir del programa."<<endl;
        cin>>eleccion___;
        cout<<endl;
        if(eleccion___==1){
            cout<<"Ingrese Usuario: ";
            cin>>UserName;
            clave1=Usuario.Desplegar();
            confirmacion=Usuario.accesos(UserName,clave1);
            if (confirmacion==false){
                cout << "acceso denegado"<<endl;
                cout<<endl;
            }
            if (confirmacion==true){
                if (confirmacion==true){
                    cout<< "acceso permitido"<<endl;
                    cout<<endl;
                }
                else {
                    cout << "acceso denegado"<<endl;
                    cout <<endl;
                }
                if (confirmacion==true){
                    a=1;
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

                                cout<<" ||=======================================================||"<<endl;
                                cout<<" ||               Inventario de productos                 ||"<<endl;
                                cout<<" ||=======================================================||"<<endl;
                                informacion=Usuario.inventario();
                                cout<<endl;
                                //cout<<informacion<<endl;
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

                                cout<<"-Ingrese producto: ";
                                cin.getline(producto,100);//optienes la cadena completa del arreglo
                                for(int  i = 0; producto[i] != 0;++i)
                                    if(producto[i] != 32)//32 significa espacio en codigo ascii!!
                                        producto1+=producto[i];

                                cout<<"-Ingrese Cantidad: "; cin >> cantidad;
                                cout<<"-Ingrese costo: "; cin >> costo;
                                Usuario.agregar(id,producto1,cantidad,costo);
                                producto1="";
                            }
                        }
                        if (accion==2){
                            cout<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            cout<<" ||               Inventario de productos                 ||"<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            Usuario.inventario();
                        }
                        if (accion==3){
                            idcombo=Usuario.generaridcombo();
                            temporal=stoi(idcombo);
                            temporal+=1;
                            idcombo=to_string(temporal);
                            cout<<"Que nombre desea ponerle al combo?: ";  cin>>nombrecombo;
                            cout<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            cout<<" ||               Inventario de productos                 ||"<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            informacion=Usuario.inventario();
                            cout <<endl;
                            cout <<endl;
                            cout<< "-Ingrese cantidad de combos que desea crear: "; cin>>cantidad_combos;
                            cout <<"-Escriba el ID de los productos que requiere cada combo y la cantidad de estos separados por coma"<<endl;
                            cout <<"-Separa con punto y coma los diferentes productos: ";      cin>>combo;
                            cppc=stoi(cantidad_combos);
                            Crearcomboss.codigocombos(combo);
                            Crearcomboss.cantidaddeproductosparaelcombo(cppc);
                            cout <<"-Esriba el valor que desea ponerle al combo: ";        cin >>valor_combo;
                            resultadocombo=Crearcomboss.productosdesencriptados(idcombo,nombrecombo,valor_combo);
                            cout<<resultadocombo<<endl;
                            if (resultadocombo=="Combo creado...."){
                                Crearcomboss.cntidadcombos(idcombo,cantidad_combos);
                            }

                        }

                        if (accion==4){
                            cout<<"En mantenimiento.........."<<endl;
                        }
                        if (accion==5){
                            cout<<endl;
                            a=0;
                        }
                    }
                }
            }
        }


            if (eleccion___==2){
                string menu, idparacombo,numeroparacombo;
                string segdaopcion,sala,asiento;
                acceso Usuario;
                int b=1,cant, paracambio;
                while (b==1){
                    numeroparacombo=Crearcomboss.combosdisponibles();
                    Crearcomboss.alteracionencombos(numeroparacombo);
                    cout<<"Ingrese Usuario: ";
                    cin>>UserName;
                    confirmacion=Usuario.Desplegar1((UserName+ ' '));
                    if (confirmacion==true){
                        cout<< "Acceso permitido"<<endl;
                    }
                    else {
                        cout << "Acceso denegado"<<endl;
                        cout <<endl;
                        b=0;
                    }
                    if (confirmacion==true){
                        cout<<endl;
                        cout<<" ||=======================================================||"<<endl;
                        cout<<" ||                    Oferta de Combos                   ||"<<endl;
                        cout<<" ||=======================================================||"<<endl;
                        cout<<" ||    ID                 Combo                 Precio    ||"<<endl;
                        cout<<" ||=======================================================||"<<endl;
                        Crearcomboss.menucombos();
                        cout<<endl;
                        a=1;
                        while(a==1){
                            cout<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"|              MENU                |"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"|1.       seleccionar combo        |"<<endl;
                            cout<<"|2.        Terminar pedido         |"<<endl;
                            cout<<"|3.            Salir               |"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<endl;
                            cin >> accion;
                            if (accion==1){
                                int valor;
                                if (Usuario.generaridcombo()=="0"){
                                    cout<<"No hay ningun combo disponible al momento....."<<endl;
                                }
                                else{
                                    cout<<"-Elija el combo que desea ordenar ecribiendo el ID de este: ";  cin>>idparacombo;
                                    segdaopcion=Crearcomboss.comboseleccionado(idparacombo);
                                    cout<<segdaopcion<<endl;
                                    valor=stoi(segdaopcion);
                                    Crearcomboss.sordenusuario(valor);
                                    cout<<"Ingrese billete o moneda para el pago: ";  cin>>pago;
                                    cout<<"Ingrese cantidad de este: "; cin>>cant;
                                    pago=pago*cant;
                                    devuelta=valor-pago;
                                    if (devuelta>0){
                                        cout<<"Para completar el pago hace falta: "<<devuelta<<endl;
                                    }
                                    while (devuelta>0){
                                        Crearcomboss.sordenusuario(pago);
                                        cout<<"Ingrese billete o moneda para el pago: ";  cin>>pago;
                                        cout<<"Ingrese cantidad de este: "; cin>>cant;
                                        pago=pago*cant;
                                        devuelta=devuelta-pago;
                                        if (devuelta<0){
                                            break;
                                        }
                                        cout<<"Para completar el pago hace falta: "<<devuelta;
                                    }
                                    cout<<"Su devuelta es de: "<<abs(devuelta)<<endl;
                                    Crearcomboss.sordenusuario(abs(devuelta));
                                    paracambio=stoi(idparacombo);
                                    Crearcomboss.pagocomborealizado(paracambio);
                                }
                            }
                            if (accion==2){
                                if (Usuario.generaridcombo()!="0"){
                                    cout<<"No hay ningun combo disponible al momento....."<<endl;
                                    cout<<"Favor ingresar el numero de la sala: ";  cin>>sala;
                                    cout<<"Favor ingresar el numero de la sala: ";  cin>>asiento;
                                    cout<<endl;
                                    cout<<"Le llevaremos su pedido la sala numero "<<sala<<" al asiento "<<asiento<<endl;
                                }
                            }
                            if (accion==3){
                                cout<<endl;
                                b=0;
                                a=0;
                            }
                        }
                    }
                }
            }
        if (eleccion___==3){
            return 0;
        }
    }
}
