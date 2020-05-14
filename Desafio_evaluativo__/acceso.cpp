#include "acceso.h"
#include <fstream>
#include <stdlib.h>
#include <string>

string acceso::Desplegar(){
    /*Esta función se encarga de ingresar a un archivo de texto y obtener la información conteninda, para asi poder ingresar como administrador*/
    string clave1;                                                      //se declara string
    ifstream registro;                                                  //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/clave_admin.txt", ios::in);  //abre el archivo de texto clave_admin
    if (registro.fail())                                                //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                        //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                        //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){
        clave1+=tem;                                                    //a clave1 se le agrega el char tem
        }
    }
    return clave1;
}

bool acceso::agregar(string id, string producto, string cantidad, string costo)
{
    /*Esta función se encarga de agregar productos al archivo de texto Productos*/
    ofstream registro;                                                  //ofstream Para escritura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::app);   //Abre el archivo y escribe al final de este
    if (registro.fail())                                                //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                        //si hay una falla imprime error y se sale de la función
    registro<<id;                                                       //escribe al final del archivo la id
    registro<<" ";                                                      //escribe al final del archivo un espacio en blanco
    registro<<producto;                                                 //escribe al final del archivo el producto
    registro<<" ";                                                      //escribe al final del archivo un espacio en blanco
    registro<<cantidad;                                                 //escribe al final del archivo la cantidad del producto
    registro<<" ";                                                      //escribe al final del archivo un espacio en blanco
    registro<<costo;                                                    //escribe al final del archivo el costo del producto
    registro<<endl;                                                     //escribe al final del archivo un salto de linea
    producto="";                                                        //producto es un string vacio

    return true;                                                        //returna un valor booleano verdadero
}

string acceso::sinespacios()
{
    /*Esta función se encarga de eliminar los espacios en blanco de un string*/
    char producto[100];                                                     //se declara un arreglo de char
    string producto1;                                                       //se declara string

    cout<<"Ingresa una palabra: ";
    cin.getline(producto,100);                                              //optienes la cadena completa del arreglo

    for(int  i = 0; producto[i] != 0;++i)                                   //recorre el arreglo de char
        if(producto[i] != 32)                                               //32 significa espacio en codigo ascii!!
            producto1+=producto[i];                                         //al string producto se le agrega el char perteneciente a producto en dicha posición del arreglo
    return producto1;                                                       //retorna el string producto1 sin espacios
}

string acceso::Cproductos(string idplus)
{
    /*Esta función se encarga de retornar la cantidad del produco solicitado por el id producto*/
    string datos,user,saldo2;                                                   //se declaran strings
    string arreglo[cantidad1()][4];                                             //se declara un arreglo de strings
    int cont1=0,cont2=0,cont3=0;                                                //se declaran int
    ifstream registro;                                                          //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);            //abre el archivo de texto Productos
    if (registro.fail())                                                        //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                                //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                                //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){
        if (tem!=' ' || tem!='\n'){
            datos+=tem;                                                         //Si es diferente de espacio o \n  a datos se agrega el caracter tem
            }
        if (tem==' ' || tem=='\n'){
            arreglo[cont2][cont1]=datos;                                        //el string contenido en datos para a ser el termino guardado en arreglo[cont1][cont2]
            cont1=cont1+1;                                                      //cont1 aumenta en una unidad
            if (tem=='\n'){                                                     //si el caracter tem es igual a un salto de linea
                cont2=cont2+1;                                                  //cont2 aumenta en una unidad
                cont1=0;                                                        //cont1 se iguala a 0
            }
            datos="";                                                           //datos de iguala a un string vacio
            }

        }
    }
    for (int t=0;t<(cantidad1()-1);t++){                                        //se recorre el arreglo pasado
        user=arreglo[cont3][0];                                                 //se le asigna un string de una parte del arreglo que sera un id
        saldo2=arreglo[cont3][2];                                               //se le asigna un string de una parte del arreglo que sera una cantidad
        if (idplus==user){                                                      //cuando la id como parametro y user sena iguales
            return saldo2;                                                      //retorno la cantidad correspondiente a la id
        }
            cont3+=1;                                                           //cont3 aumenta en una unidad
    }
}

bool acceso::accesos(string UserName,string datos){
    /*Esta función se encarga de permitir o denegar el acceso como administrador*/
    bool flag=false;
    string Key;                                                             //se declaran strings
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/clave_admin.txt", ios::in);      //abre el archivo de clave_admin
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    if (UserName=="Administrador"){      //Si desea cambiar el usuario del administrador, cambie el nombre de esta linea conocida como "Administrador"
        flag=true;                      //Ahora si desea cambiar la clave tocaria ir al archivo de texto conocido como clave_admin y cambiarla
    }
    else {
        return false;
    }
    if (flag==true){
        cout<<"ingrese clave: ";
        cin>>Key;                                                           //pide la clave del administrador
        if (Key==datos){                                                    //si la clave ingresada es igual a la clave obtenida del archivo de texto
            return true;                                                    //retornar un booleano verdadero
        }
        else {                                                               //si las claves no son iguales
            return false;                                                   //retornar un booleano falso
        }
    }
}
int acceso::cantidad()
{
    /*Esta función se encarga de retornar la cantidad de saltos de linea del archivo de texto usuarios
      este retorno tambien sirve para averiociar el taaño de un arreglo que mas tarde en otra funcion se sabra*/
    int cantidadparaarreglo=1;
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/usuarios.txt", ios::in);         //abre el archivo de texto usuarios
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){
        if (tem=='\n'){                                                     //si el caracter tem es igual a un salto de linea
            cantidadparaarreglo+=1;                                         //cantidadparaarreglo aumenta en una unidad
            }
        }
    }
    return cantidadparaarreglo;                                             //retorna el valor de cantidadparaarreglo que son la cantidad de saltos de linea en el archivo de texto usuarios
}

int acceso::cantidad1()
{
    /*Esta función se encarga de retornar la cantidad de saltos de linea del archivo de texto Productos
      este retorno tambien sirve para averiociar el tamaño de un arreglo que mas tarde en otra funcion se sabra*/
    int cantidadparaarreglo=1;                                              //se declaran int
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);        //abre el archivo de texto Productos
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){
        if (tem=='\n'){                                                     //si el caracter tem es igual a un salto de linea
            cantidadparaarreglo+=1;                                         //cantidadparaarreglo aumenta en una unidad
            }
        }
    }
    return cantidadparaarreglo;                                             //retorna el valor de cantidadparaarreglo que son la cantidad de saltos de linea en el archivo de texto Productos
}

int acceso::cantidad2()
{
    /*Esta función se encarga de retornar la cantidad de saltos de linea del archivo de texto Combos
      este retorno tambien sirve para averiociar el taaño de un arreglo que mas tarde en otra funcion se sabra*/
    int cantidadparaarreglo=1;                                              //se declaran int
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::in);           //abre el archivo de texto Combos
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){
        if (tem=='\n'){                                                     //si el caracter tem es igual a un salto de linea
            cantidadparaarreglo+=1;                                         //cantidadparaarreglo aumenta en una unidad
            }
        }
    }
    return cantidadparaarreglo;                                             //retorna el valor de cantidadparaarreglo que son la cantidad de saltos de linea en el archivo de texto Combos
}

int acceso::cantidad3()
{
    /*Esta función se encarga de retornar la cantidad de saltos de linea del archivo de texto C_combos,
      este retorno tambien sirve para averiociar el taaño de un arreglo que mas tarde en otra funcion se sabra*/
    int cantidadparaarreglo=1;                                              //se declaran int
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/C_combos.txt", ios::in);         //abre el archivo de texto C_combos
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){
        if (tem=='\n'){                                                     //si el caracter tem es igual a un salto de linea
            cantidadparaarreglo+=1;                                         //cantidadparaarreglo aumenta en una unidad
            }
        }
    }
    return cantidadparaarreglo;                                             //retorna el valor de cantidadparaarreglo que son la cantidad de saltos de linea en el archivo de texto C_combos
}

int acceso::productexistente(int aentero, int plusproductoexistente, string idplus)
{
    /*Esta funcion se encarga de retornar un string despues de alterar el archivo de texto Productos
      con la cantidad actualizada*/
    string datos,user,saldo2,arr;                                               //se declaran strings
    string arreglo[cantidad1()][4];                                             //se declara un arreglo de strings
    int contador1=0,contador2=0,contador3=0,restante,cantidad2=cantidad1();     //se declaran int
    ifstream registro;                                                          //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);            //abre el archivo de texto Productos
    if (registro.fail())                                                        //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                                //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                                //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                  //Si es diferente de espacio o \n  a datos se agrega el caracter tem
                }
                }
            if (tem==' ' || tem=='\n'){
                arreglo[contador2][contador1]=datos;                             //el string contenido en datos para a ser el termino guardado en arreglo[contador1][contador2]
                contador1=contador1+1;
                if (tem=='\n'){                                                  //si el caracter tem es igual a un salto de linea
                    contador2=contador2+1;
                    contador1=0;
                    }
                datos="";                                                        //datos de iguala a un string vacio
                }

            }
    }
    arreglo[contador2][contador1]=datos;                                        //el string contenido en arreglo en la posición [contador2][contador1] para a ser el termino guardado en datos
    for (int t=0;t<(cantidad1()-1);t++){                                        //recorre el arreglo anterior
        user=arreglo[contador3][0];                                             //posiciones del arreglo se guardan en strings
        saldo2=arreglo[contador3][2];
        if (idplus==user){                                                      //si la id que hay como parametro(idplus) es iguala user
            restante=aentero+plusproductoexistente;                              //se suman cantidades para actualiazción
            std::string numeroComoCadena = std::to_string(restante);            //de int a string
            arreglo[contador3][2]=numeroComoCadena+' ';                         //se agrega un espacio en blanco para luego sobreescribir
            ofstream registro;                                              //ofstream Para escritura en el archivo
            registro.open("../Desafio_evaluativo__/Productos.txt", ios::out);//Abre el archivo y escribe al final de este
            if (registro.fail())                                            //revisa si hay algún error al abrir el archivo
                cerr << "Error" << endl;                                    //si hay una falla imprime error y se sale de la función
            for(int j=0;j<cantidad2;j++){                                   //este for es para moverse entre un arreglo en la primera posicion y poder sobreescribor el archivo abierto anteriormente
                for(int r=0;r<4;r++){                                       //este for es para moverse entre un arreglo en la segunda posicion y poder sobreescribor el archivo abierto anteriormente
                    arr=arreglo[j][r];                                      //se le asigna un string a arr
                    registro<<arr;                                          //escribe al final del archivo arr
                    if (r==3 && j<=cantidad2-2){                            //si ya se coloco el precio
                        registro<<'\n';                                     //escribe al final del archivo un salto de linea
                    }
                }
             }
             registro.close();                                              //se cierra el archivo de texto
             return restante;                                               //retorna la cantidad final
        }
        contador3+=1;                                                       //contador3 aumenta en una unidad
    }

}

string acceso::inventario()
{
    /*Esta función se encarga de retornar un string con la información guardada en el archivo de texto Productos para imprimir el inventario*/
    string info;                                                                    //se declara string
    ifstream registro;                                                              //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);                //abre el archivo de texto Productos
    if (registro.fail())                                                            //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                                    //si hay una falla imprime error y se sale de la función
    printf("%2c",' ');                                                              //printfc tambien es un tipo de cout
    printf("%c",' ');                                                               //printfc tambien es un tipo de cout
    while (registro.good()){
        char tem=registro.get();                                                     //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            info+=tem;                                                              // al string info se le agrega el char contenido en tem
            printf("%c",tem);                                                       //printfc tambien es un tipo de cout
            if (tem=='\n'){                                                         //si el caracter tem es igual a un salto de linea

                cout<<" ||=======================================================||"<<endl;
                printf("%2c",' ');                                                  //printfc tambien es un tipo de cout
                printf("%c",' ');                                                   //printfc tambien es un tipo de cout
            }
        }

    }
    return info;                                                                    //retorna el archivo de texto info donde esta el inventario
}

string acceso::generarid()
{
    /*esta función se encarga de crear una nueva id para Productos, ingresando al archivo de texto, tomando el ultimo id
      creado y adicionandole 1*/
    string datos;                                                           //se declaran strings
    string arreglo[cantidad1()][4];                                         //se declara un arreglo de strings
    int contador1=0,contador2=0,cantidad2=cantidad1();                      //se declaran int
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);        //abre el archivo de texto Productos
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){                                     //si el caracter tem es diferente a un salto de linea o a un espacio e blanco
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                             //Si es diferente de espacio o \n  a datos se agrega el caracter tem
                }
                }
            if (tem==' ' || tem=='\n'){                                     //si el caracter tem es diferente a un salto de linea o a un espacio e blanco
                arreglo[contador2][contador1]=datos;                        //el string contenido en datos para a ser el termino guardado en arreglo[contador1][contador2]
                contador1=contador1+1;                                      //contador1 aumenta en una unidad
                if (tem=='\n'){                                             //si el caracter tem es igual a un salto de linea
                    contador2=contador2+1;                                  //contador2 aumenta en una unidad
                    contador1=0;                                            //contador1 se iguala a 0
                    }
                datos="";                                                   //datos de iguala a un string vacio
                }

            }
    }
    if (cantidad2==1){                                                      //cantidad3 tiene el numero correspondiente a la cantidad de saldos de linea de C_combos y si es igual a 1
        cantidad2=2;                                                        //cantidad3 se le asigna el valor de 2
    }
    datos=arreglo[cantidad2-2][0];                                          //a datos se le dara el valor de un string correspondiente a una id
    if (datos==""){                                                           //si datos es igual a string vacio
        datos="0";                                                            //datos de iguala a "0"
    }
    return datos;                                                           //retorna una id
}

string acceso::generaridcombo()
{
    /*esta función se encarga de crear una nueva id para Combos, ingresando al archivo de texto, tomando el ultimo id
      creado y adicionandole 1*/
    string datos;                                                           //se declara string
    string arreglo[cantidad2()][4];                                         //se declara un arreglo de strings
    int contador1=0,contador2=0,cantidad3=cantidad2();                      //se declaran int
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::in);           //abre el archivo de texto Combos
    if (registro.fail())                                                    //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){                                     //si el caracter tem es diferente a un salto de linea o un espacio en blanco
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                             //Si es diferente de espacio o \n  a datos se agrega el caracter tem
                }
                }
            if (tem==' ' || tem=='\n'){                                     //si el caracter tem es igual a un salto de linea o un espacio en blanco
                arreglo[contador2][contador1]=datos;                        //el string contenido en datos para a ser el termino guardado en arreglo[contador1][contador2]
                contador1=contador1+1;
                if (tem=='\n'){                                             //si el caracter tem es igual a un salto de linea
                    contador2=contador2+1;
                    contador1=0;
                    }
                datos="";                                                   //datos de iguala a un string vacio
                }

            }
    }
    if (cantidad3==1){                                                      //cantidad3 tiene el numero correspondiente a la cantidad de saldos de linea de C_combos y si es igual a 1
        cantidad3=2;                                                        //cantidad3 se le asigna el valor de 2
    }
    datos=arreglo[cantidad3-2][0];
    if (datos==""){                                                           //si datos es igual a string vacio
        datos="0";                                                            //datos de iguala a "0"
    }
    return datos;                                                               //retorna datos que sera una id
}

bool acceso::agregarusuario(string usuario, string contasena)
{
    /*Esta función se encarga permitir al administrador ingresar nuevos usuarios al archivo de texto usuarios*/
    ofstream registro;                                                          //ofstream Para escritura en el archivo
    registro.open("../Desafio_evaluativo__/usuarios.txt", ios::app);            //Abre el archivo y escribe al final de este
    if (registro.fail())                                                        //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                                //si hay una falla imprime error y se sale de la función
    registro<<usuario;                                                          //escribe al final del archivo el usuario
    registro<<" ";                                                              //escribe al final del archivo un espacio en blanco
    registro<<contasena;                                                        //escribe al final del archivo la contraseña
    registro<<endl;                                                             //escribe al final del archivo un salto de linea

    return true;                                                                //retorna un valor booleano de verdad
}


bool acceso::Desplegar1(string UserName){
    /*Esta función permite o niega el ingreso al usuario*/
    bool flag=false;                                                    //se declara una bandera que inicialmente sera falsa
    string datos;                                                       //se declara string
    string arreglo[cantidad()][3];                                      //se declara un arreglo de strings
    int contador1=0,contador2=0,contador3=0;                            //se declaran int
    ifstream registro;                                                  //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/usuarios.txt", ios::in);     //abre el archivo de texto usuarios
    if (registro.fail())                                                //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                        //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                        //tem sera un char y se obtiene caracter por caracter de registro.get
    if (registro.good()){

        if (tem!=' ' || tem!='\n'){                                     //si el caracter tem es diferente a un salto de linea o un espacio en blanco
            datos+=tem;                                                 //Si es diferente de espacio o \n  a datos se agrega el caracter tem
            }
        if (tem==' ' || tem=='\n'){                                     //si el caracter tem es igual a un salto de linea o un espacio en blanco
            arreglo[contador2][contador1]=datos;                        //el string contenido en datos para a ser el termino guardado en arreglo[contador1][contador2]
            contador1=contador1+1;
            if (tem=='\n'){                                             //si el caracter tem es igual a un salto de linea
                contador2=contador2+1;
                contador1=0;
                }
            datos="";                                                   //datos de iguala a un string vacio
            }
        }
    }
    string key,user,compararclave;                                      //se declaran strings
    for (int t=0;t<(cantidad()-1);t++){                                 //se recorre el arreglo anterior
        user=arreglo[contador3][0];                                     // a user se le asigna el string que pertenece a una de las posiciones del arreglo que sera un usuario registrado
        if (UserName==user){                                            //si el usuario ingresado por el usuario es igual al registrado
            flag=true;                                                  //la bandera sera verdadera
            break;                                                      //saldra del ciclo
        }
        contador3=contador3+1;                                          //contador3 aumenta en una unidad
    }
    compararclave=arreglo[contador3][1];                                // a compararclave se le asigna el string que pertenece a una de las posiciones del arreglo que sera una clave registrada
        if (flag==true){                                                //si la bandera es verdadera
            cout<<"ingrese clave: ";
            cin>>key;                                                   //pide la clave al usuario
            if((key+'\n')==compararclave){                              //a la clave ingresado se le agregara un salto de linea para poder comparar y lo comparara con la clave ya registrada
                return true;                                            //si las claves son iguales retornara true y saldra de la función
            }
            else{                                                       //si las claves no son iguales
                return false;                                           //retornara false y saldra de la función
            }
        }
        else{                                                           //si la bandra es falsa
            return false;                                               //retornara false y saldra de la función
        }
}
