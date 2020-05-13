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
    bool confirmacion;          //declaración de un valor booleano
    char producto[100];         //declaración de un arreglo de chars, para una operación mas abajo para una frase sin espacios
    string UserName,clave1,id,cantidad,costo,producto1="",actualizar, nombrepararegistro,contrasenapararegistro;    //declaración de strings
    string resultadocombo,idplus,informacion,idcombo,nombrecombo,combo,valor_combo,cantidad_combos;             //declaración de strings
    comboss Crearcomboss;                   //Conexión con la clase comboss
    acceso Usuario;                         //Conexión con la clase acceso
    int a, accion,adminprimeropcion,aentero,plusproductoexistente,temporal, pago,devuelta,cppc;     //declaración de enteros
    int adminousuario=1,eleccion___;            //declaración de enteros
    while (adminousuario==1){               //ciclo para la ventana inicial del programa
        cout<<"Que accion desea tomar:"<<endl;      //escribe en la ventana inicial lo que se encuentra entre comillas
        cout<<"1. Ingresar como Administrador."<<endl;          //escribe en la ventana inicial la opción de ingresar como administrador
        cout<<"2. Ingresar como Usuario."<<endl;            //escribe en la ventana inicial la opción de ingresar como usuario/cliente
        cout<<"3. Salir del programa."<<endl;           //escribe en la ventana inicial la opción de salir
        cin>>eleccion___;           //pide el dato definitivo para ingresar como admin, usuario o para salir del programa
        cout<<endl;             //Imprime un salto de linea
        if(eleccion___==1){         //si decides ingresar como administrador
            cout<<"Ingrese Usuario: ";      //imprime en pantalla que ingrese el usuario
            cin>>UserName;          //pide el dato usuario
            clave1=Usuario.Desplegar();         //invoca a la funcion Desplegar que se encuentra el la clase acceso
            confirmacion=Usuario.accesos(UserName,clave1);          //invoca a la funcion accesos que se encuentra el la clase acceso
            if (confirmacion==false){           //en caso de que tenga el usuario o la contraseña erronea, denegara el acceso
                cout << "acceso denegado"<<endl;
                cout<<endl;
            }
            if (confirmacion==true){            //en caso de que tenga el usuario y la contraseña correctos, permitira el acceso
                if (confirmacion==true){
                    cout<< "acceso permitido"<<endl;            //verifica nuevamente
                    cout<<endl;
                }
                else {
                    cout << "acceso denegado"<<endl;            //verifica nuevamente
                    cout <<endl;
                }
                if (confirmacion==true){            //Si el acceso es concedido desplegara la siguiente informacion
                    a=1;
                    while(a==1){                //un ciclo repetitivo para las funciones del administrador
                        cout<<endl;
                        cout<<"------------------------------------"<<endl;
                        cout<<"|              MENU                |"<<endl;
                        cout<<"------------------------------------"<<endl;
                        cout<<"|1.     Agregar usuario nuevo      |"<<endl;
                        cout<<"|2.Ingresar productos al inventario|"<<endl;
                        cout<<"|3.      Mostrar Inventario        |"<<endl;         //Todo lo que tenga cout al inicio lo imprimira
                        cout<<"|4.         Crear combos           |"<<endl;
                        cout<<"|5. Reporte de ventas realizadas   |"<<endl;
                        cout<<"|6.            Salir               |"<<endl;
                        cout<<"------------------------------------"<<endl;

                        cin >> accion;              //Pregunta cual acción de las anteriores desea ejecutar
                        if (accion==1){             //Acción para agregar usuarios al archivo de textos "usuarios" y de esta manera luego poder ingresar como este
                            cout<<"Ingrese el nombre del usuario: ";    cin>>nombrepararegistro;        //pregunta el usuario que desea usar
                            cout<<"Ingrese la contraseña que desee: ";  cin>>contrasenapararegistro;    //pregunta la clave para el ingreso
                            Usuario.agregarusuario(nombrepararegistro,contrasenapararegistro);      //Invoca la función agregarusuario localizada en acceso con los parametros de usuario y contraseña
                        }
                        if (accion==2){             //Acción para ingresar productos al inventario
                            cout<<"1. Agregar producto existente al inventario"<<endl;      //Pregunta si el rpoducto es existente
                            cout<<"2. Agregar producto nuevo al inventario    "<<endl;      //o es nuevo
                            cin>>adminprimeropcion;     //pregunta opción
                            cout<<endl;
                            if (adminprimeropcion == 1){        //Si el producto es existente

                                cout<<" ||=======================================================||"<<endl;
                                cout<<" ||               Inventario de productos                 ||"<<endl;
                                cout<<" ||=======================================================||"<<endl;
                                informacion=Usuario.inventario();       //Invoca la función inventario localizada en acceso
                                cout<<endl;
                                cout<<"Ingrese la ID del producto desea agregar: ";  cin>>idplus;       //pide la id de algún producto ya existente
                                actualizar=Usuario.Cproductos((idplus+ ' '));   //Invoca la función Cproductos localizada en acceso
                                string a = actualizar;          //denomina a a como string
                                aentero= stoi(a);       //convertir string  a entero
                                cout<<"Que cantidad desea agregar? ";
                                cin>>plusproductoexistente;         //pide la cantidad que desea agregar
                                Usuario.productexistente(aentero,plusproductoexistente,(idplus+ ' '));      //Invoca la función productoexistente localizada en acceso con los parametros de la id, el producto y la cantidad.
                            }
                            if (adminprimeropcion == 2){        //Si el producto es nuevo
                                id=Usuario.generarid();         //Invoca la función generarid localizada en acceso
                                if (idcombo==""){
                                    idcombo="0";        //si en el archivo de texto ni hay nada automaticamente id vale 0
                                }
                                temporal=stoi(id);      //convierte string a int
                                temporal+=1;            //se suma una unidad
                                id=to_string(temporal);     //convierte un entero a string
                                cin.ignore();           //cin dispone de ciertas ayudas que simplifican la lectura de datos

                                cout<<"-Ingrese producto: ";
                                cin.getline(producto,100);//obtienes la cadena completa del arreglo
                                for(int  i = 0; producto[i] != 0;++i)
                                    if(producto[i] != 32)//32 significa espacio en codigo ascii!!
                                        producto1+=producto[i];     //Por esto necestimos es arreglo char, y asi todo se va guardando en un string

                                cout<<"-Ingrese Cantidad: "; cin >> cantidad;       //pide la cantidad del producto
                                cout<<"-Ingrese costo: "; cin >> costo;             //pide costo del producto
                                Usuario.agregar(id,producto1,cantidad,costo);       // Invoca la funcion agregar  localizada en la clase acceso
                                producto1="";       //el string producto1 vuelva a ser un string vacio
                            }
                        }
                        if (accion==3){     //opcion por si se quiere ver el inventario
                            cout<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            cout<<" ||               Inventario de productos                 ||"<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            Usuario.inventario();       //invoca la funcion inventario() ubicada en la clase acceso
                        }
                        if (accion==4){     //opcion por si se desea crear un combo
                            idcombo=Usuario.generaridcombo();   //invoca la funcion generaridcombo() ubicada en la clase acceso
                            temporal=stoi(idcombo);             //convierte string a entero
                            temporal+=1;                        //aumenta en una unidad para id
                            idcombo=to_string(temporal);        //converte de entero a string
                            cout<<"Que nombre desea ponerle al combo?: ";  cin>>nombrecombo;    //pide el nombre del combo
                            cout<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            cout<<" ||               Inventario de productos                 ||"<<endl;
                            cout<<" ||=======================================================||"<<endl;
                            informacion=Usuario.inventario();  //invoca la funcion inventario() ubicada en la clase acceso
                            cout <<endl;
                            cout <<endl;
                            cout<< "-Ingrese cantidad de combos que desea crear: "; cin>>cantidad_combos;
                            cout <<"-Escriba el ID de los productos que requiere cada combo y la cantidad de estos separados por coma"<<endl;
                            cout <<"-Separa con punto y coma los diferentes productos: ";      cin>>combo;      //Describe detalladamente como ingresar los datos que tendra el combo
                            cppc=stoi(cantidad_combos);         //convierte string a entero
                            Crearcomboss.codigocombos(combo);       //invoca la funcion codigocombos() ubicada en la clase comboss con el parametro de los ingredientes del combo
                            Crearcomboss.cantidaddeproductosparaelcombo(cppc);  //invoca la funcion cantidaddeproductosparaelcombo() ubicada en la clase comboss con el parametro de cantidad
                            cout <<"-Esriba el valor que desea ponerle al combo: ";        cin >>valor_combo;
                            resultadocombo=Crearcomboss.productosdesencriptados(idcombo,nombrecombo,valor_combo);   //invoca la funcion productosdesencriptados() ubicada en la clase comboss con los parametros de id, nombre y precio
                            cout<<resultadocombo<<endl;
                            if (resultadocombo=="Combo creado...."){        //resultadocombo que retorna un string el cual puede se combo creado o cantidad insuficiente
                                Crearcomboss.cntidadcombos(idcombo,cantidad_combos);        //invoca la funcion cantidadcombos() ubicada en la clase comboss
                            }

                        }

                        if (accion==5){         //opción por si desea ver todas las ventas realizadas
                            cout<<Crearcomboss.reportedeventasimpresion()<<endl;        //invoca la funcion reportedeventasimpresion() ubicada en la clase comboss
                        }
                        if (accion==6){         //Opción por si quiere dejar de ser administrador y volver al menú inicial
                            cout<<endl;
                            a=0;            //el ciclo para ser administrador depende unicamente si el valor de a es: 1
                        }
                    }
                }
            }
        }


            if (eleccion___==2){            //Si ingresa como usuario
                string menu, idparacombo="0",numeroparacombo;       //definimos como strings
                string segdaopcion,sala,asiento;                    //definimos como string
                acceso Usuario;                                     //Conexion con la clase acceso
                int b=1, paracambio;                                //definimos como enteros
                while (b==1){                                       //Mientras b sea igual a 1
                    numeroparacombo=Crearcomboss.combosdisponibles();   //invoca la funcion combosdisponibles() ubicada en la clase comboss, para actualizar el archivo de cantidad de combos
                    Crearcomboss.alteracionencombos(numeroparacombo);   //invoca la funcion alteracionencombos() ubicada en la clase comboss, para actualizar el archivo de combos
                    cout<<"Ingrese Usuario: ";
                    cin>>UserName;          //Pide usuario
                    confirmacion=Usuario.Desplegar1((UserName+ ' '));//invoca función desplega1 que confirma si el usuario es acertado
                    if (confirmacion==true){
                        cout<< "Acceso permitido"<<endl;
                    }
                    else {
                        cout << "Acceso denegado"<<endl;
                        cout <<endl;
                        b=0;        //lo devuelve al menú inicial
                    }
                    if (confirmacion==true){//siempre mostrara el menú disponible al ingresar como usuario
                        cout<<endl;
                        cout<<" ||=======================================================||"<<endl;
                        cout<<" ||                    Oferta de Combos                   ||"<<endl;
                        cout<<" ||=======================================================||"<<endl;
                        cout<<" ||    ID                 Combo                 Precio    ||"<<endl;
                        cout<<" ||=======================================================||"<<endl;
                        Crearcomboss.menucombos();          //invoca menucombos ubicada en la clase comboss, y despliega combo
                        cout<<endl;
                        a=1;
                        while(a==1){                        //ciclo mientras a==1
                            cout<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"|              MENU                |"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<"|1.       seleccionar combo        |"<<endl;
                            cout<<"|2.        Terminar pedido         |"<<endl;
                            cout<<"|3.            Salir               |"<<endl;
                            cout<<"------------------------------------"<<endl;
                            cout<<endl;
                            cin >> accion;          //pregunta que desea hacer como usuario
                            if (accion==1){         //Si desea seleccionar combo
                                int valor;
                                if (Usuario.generaridcombo()=="0"){     //invoca la función generaridcombo localizada en la clase acceso
                                    cout<<"No hay ningun combo disponible al momento....."<<endl;       //si no hay combos disponibles imprimira este mensaje
                                }
                                else{
                                    cout<<"-Elija el combo que desea ordenar ecribiendo el ID de este: ";  cin>>idparacombo;//pide id del combo
                                    segdaopcion=Crearcomboss.comboseleccionado(idparacombo);  //invoca comboseleccionado que se encuentra en la clase combosss, para ver si la id existe
                                    cout<<segdaopcion<<endl;        //imprime un mensaje string
                                    if (segdaopcion!="la ID ingresada no existe entre los combos........."){ //si segundaopcion es dierente a la ID ingresada no existe entre los combos........
                                        valor=stoi(segdaopcion);        //de string a entero
                                        Crearcomboss.sordenusuario(valor);  //invoca la función sordenusuario para aplicar la función del problema1 practica2
                                        cout<<"Ingrese cantidad dinero para el pago: ";  cin>>pago;
                                        devuelta=valor-pago;        //resta el dinero ingresado con el valor del combo
                                        if (devuelta>0){
                                            cout<<"Para completar el pago hace falta: "<<devuelta<<endl;    //si falta dinero
                                        }
                                        while (devuelta>0){
                                            Crearcomboss.sordenusuario(pago);       //invoca la función sordenusuario para aplicar la función del problema1 practica2
                                            cout<<"Ingrese billete o moneda para el pago: ";  cin>>pago;
                                            devuelta=devuelta-pago;                 //resta el dinero ingresado con el valor del combo
                                            if (devuelta<0){
                                                break;          //si ya pago el combo completo lo saca del ciclo
                                            }
                                            cout<<"Para completar el pago hace falta: "<<devuelta;      //si no ha pagado el combo le solicita el dinero
                                        }
                                        cout<<"Su devuelta es de: "<<abs(devuelta)<<endl;
                                        if (abs(devuelta)!=0){          //vuelve positivo la devuelta en caso de sobrarle
                                            Crearcomboss.sordenusuario(abs(devuelta));  //invoca la función sordenusuario para aplicar la función del problema1 practica2
                                        }
                                        paracambio=stoi(idparacombo);                   //de string a int
                                        Crearcomboss.pagocomborealizado(paracambio);
                                        cout<<endl;
                                        cout<<"Favor, si ya ha realizado la compra de su combo digite 2 para terminar pedido y registrar su compra "<<endl;
                                        cout<<"Gracias por su colaboracion......."<<endl;
                                        cout<<endl;
                                        //pide el favor de ingresar a la segunda opcón para finalizar la compra y reitrar el pedido
                                    }
                                    else{
                                        cout<<segdaopcion<<endl;        //si no hay combos disponibles lo imprime
                                    }

                                }
                            }
                            if (accion==2){     //seguido de la primera opcion para terminar el proceso de compra de combo
                                if (Usuario.generaridcombo()!="0"){     //ingresa a la función generaridcombo para confirmar existencia de una id
                                    if(idparacombo!="0"){       //si la id existe
                                        cout<<"Favor ingresar el numero de la sala: ";  cin>>sala;      //pide el numero de sala
                                        cout<<"Favor ingresar el numero de asiento: ";  cin>>asiento;   //pide el numero de asiento
                                        cout<<endl;
                                        cout<<"Gracias por su compra. Le llevaremos su pedido la sala numero "<<sala<<" al asiento "<<asiento<<endl;
                                        Crearcomboss.reportedeventas(idparacombo,asiento,sala,UserName);//Agrega la venta realizada al reporte
                                    }
                                    else{
                                        cout<<"No selecciono ningun combo....."<<endl;      //sila id no existe se le dice al usuario
                                    }
                                }
                                else{
                                    cout<<"No hay ningun combo disponible al momento....."<<endl;       //si el administrador no ha creado combos o los predeterminados estan agotados
                                }
                            }
                            if (accion==3){ //si desea salir de la ventana de usuario
                                cout<<endl;
                                b=0;        //se sale del primer while que solo funciona si b=1
                                a=0;        //se sale del segundo while que solo funciona unicamente si a=1
                            }
                        }
                    }
                }
            }
        if (eleccion___==3){        //en la ventana de inicio si desea salir del programa
            return 0;//finaliza el programa
        }
    }
}
