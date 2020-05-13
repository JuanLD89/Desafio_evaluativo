#include "comboss.h"
#include "acceso.h"


bool comboss::agregarcombos(string idc, string nomcomb, string precomb)
{
    /*Esta función recibe 3 parametros, el objetivo de esta es escribir al final del archivo combos, los nuevos
      combos se digitara primero la identificación id/ espacio/ nombre del combo/ espacio/ el precio del combo/ y finalmente
      un salto de linea*/
    ofstream registro;          //ofstream Para escritura en el archivo
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::app);  //Abre el archivo y escribe al final de este
    if (registro.fail())
        cerr << "Error" << endl;            //en caso que ocurra un error al abrir el archivo, saldra error y se saldra de esta función
    registro<<idc;              //escribe al final del archivo
    registro<<" ";              //escribe al final del archivo
    registro<<nomcomb;          //escribe al final del archivo
    registro<<" ";              //escribe al final del archivo
    registro<<precomb;          //escribe al final del archivo
    registro<<endl;             //escribe al final del archivo

    return true;        //retorna verdadero
}

bool comboss::codigocombos(string combo__)
{
    /*Esta función recibe 3 parametros, el objetivo de esta es sobreescribir el archivo Codigocombos, los nuevos
      combos se digitara primero instrucciones del combo encriptadas y finalmente
      un salto de linea*/
    ofstream registro;          //ofsteram Para escritura en el archivo
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::out);   //Abre el archivo y escribe al final de este
    if (registro.fail())
        cerr << "Error" << endl;            //en caso que ocurra un error al abrir el archivo, saldra error y se saldra de esta función
    registro<<combo__;      //escribe al final del archivo
    registro<<endl;         //escribe al final del archivo

    return true;
}

string comboss::productosdesencriptados(string idcombo,string nombrecombo,string valor_combo)
{
    /*ingresa al archivo de texto Codigocombos lo desencripta tomando el valor antes de la coma como id del producto
      y el numero despues de esta la cantidad, esta función tendra como parametros, la ide del combo, el nombre y su valor
      ya que en esta misma función se invoca otra función que requiere estos parametros.
      Esta función tambien se encarga de alterar el archivo productos descontando los necesarios para el combo,
      la cantidad de combos que quieras se multiplicara por la cantidad de cada uno de los productos que hay en el
      archivo de codigocombos.
      Al final esta funcion retornara 3 posible strings que serian:
      -Combo creado
      -No cuenta con la cantidad suficiente de productos
      -Una de las ID no existe.....
      */

    bool decisiva;
    decisiva=existencia();                                              //llama a otra función que se encuentra en esta misma clase
    if (decisiva==false){                                               //la función existencia retornara un valor de verdad dependiendo de si el id existe o no
        return "Una de las ID no existe.....";                          //si no existe retornara "Una de las ID no existe....."
    }
    acceso func;                                                        //conexión con la clase acceso
    string dat,arr;                                                     //determinamos strings
    string arreglo[puntoycoma()][2];                                    //Definimos un array, puntoycoma es una función qu eretorna un int
    int cont1=0,cont2=0;                                                //definimos int
    ifstream registro;                                                  //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in); //lee el archivo para hacer un arreglo con los datos de este
    if (registro.fail())                                                //para ver si hay algún error
        cerr << "Error" << endl;                                        //Imprime error
    while (registro.good()){                                            //Mientras se encuentren datos
        char tem=registro.get();                                        //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){                                           //
            if (tem==',' || tem=='\n'){                                 //Si el caracter contenido en tem es una coma o un punto y coma entrara dentro del if
                arreglo[cont1][cont2]=dat;                              //el string contenido en dat para a ser el termino guardado en arreglo[cont1][cont2]
                dat="";                                                 //dat nuevamete a ser un string vacio
                cont2+=1;                                               //aumenta cont2 en 1 unidad
            }
            if (tem==';'){                                              //Si el caracter contenido en tem es un punto y coma entrara dentro del if
                arreglo[cont1][cont2]=dat;                              //el string contenido en dat para a ser el termino guardado en arreglo[cont1][cont2]
                cont1+=1;                                               //aumenta cont2 en 1 unidad
                cont2=0;                                                //cont2 vuelve a ser 0, para la primera posición de cada uno de las listas dentro del arreglo

                dat="";                                                  //dat nuevamete ser un string vacio
            }
            if (tem==',' || tem == ';' || tem =='\n'){
            }
            else{
                dat+=tem;                                                   //Si es diferente de ,; o \n  a dat se aregal caracter tem
            }
        }
    }
    string datos="";
    string arreg[func.cantidad1()-1][4];
    int contador1=0,contador2=0,cantidad2=func.cantidad1()-1,temporal_,temporal_2;
    ifstream regis;                                                                 //ifsteram Para lectura en el archivo
    regis.open("../Desafio_evaluativo__/Productos.txt", ios::in);                   //lee el archivo para hacer un arreglo con los datos de este
    if (regis.fail())                                                               //para ver si hay algún error
        cerr << "Error" << endl;                                                    //Imprime error
    while (regis.good()){                                                           //Mientras se encuentren datos
        char tem=regis.get();                                                       //tem sera un char y se obtiene caracter por caracter de registro.get
        if (regis.good()){
            if (tem!=' ' || tem!='\n'){                                             //Si el caracter contenido en tem es una coma o un punto y coma entrara dentro del if
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                     //Si es diferente de " " o \n  a dat se aregal caracter tem
                }
                }
            if (tem==' ' || tem=='\n'){                                             //Si el caracter contenido en tem es un espacio o un salto de linea entrara dentro del if
                arreg[contador2][contador1]=datos;                                  //el string contenido en datos para a ser el termino guardado en arreglo[contador1][contador2]
                contador1=contador1+1;                                              //se aumenta contador1 en unaundad
                if (tem=='\n'){
                    contador2=contador2+1;                                          //se aumenta contador2 en una unidad
                    contador1=0;                                                    //contador1 es igual a 0
                    }
                datos="";                                                           //datos vuelve a ser un string vacio
                }

            }
    }

    bool flag=false;                                                                //se asigna un valor de vardad
    int c1=0,c2=0,restantess;                                                       //se declcaran algunos int
    int c3=0;
    int contadorespecial=0;
    string compara1,compara2;
    while(contadorespecial<puntoycoma()){                                           //contadorespecial iniciara en 0, y la funcion puntoycoma es la cantidad de puntos y coma +1 en el archivo de codigocombos
        compara1=arreglo[c1][c2];                                                   //en esta linea y la siguiente se asignan valores para comparar entre codigocombos y productos
        compara2=arreg[c3][0];
        compara1+=' ';
        if(contadorespecial==puntoycoma()-1){                                       //para parar el ciclo
            break;
        }
        if (compara1==compara2){                                                     //comparar entre cantidad en codigocombos y cantidad de productos, para saber si es posible realizar el combo con la cantidad deseada
            c2+=1;                                                                   //aumenta c2 en una unidad
            temporal_=stoi(arreg[c3][2]);                                            //de string a int
            temporal_2=stoi(arreglo[c1][c2]);                                        //de string a int
            if (temporal_>=temporal_2){                                              //compara la cantidad de deseada ara el combo y la cantidad de productos disponibles
                flag=true;                                                           //bandera
                c1+=1;                                                               //c1 aumenta en una unidad
                c2=0;
                c3=0;

                contadorespecial+=1;                                                  //contadorespecia aumenta en una unidad para luego comparar
            }
            else{
                return "No tiene la cantidad de productos suficientes para este combo";// se sale de la funión y retorna No tiene la cantidad de productos suficientes para este combo
            }
         }

         else{
             flag=false;
         }
        c3+=1;                                                                          //c3 aumenta en una unidad
    }
    c1=0;
    c2=0;                                                                                //c1, c2, c3 se igualan a 0
    c3=0;
    contadorespecial=0;                                                                 //contador especial se iguala a 0
    if (flag==true){
        while(contadorespecial<puntoycoma()){                                           //mientras contadorespecial sea menor que el numero de puntoycoma de codigocombo
            compara1=arreglo[c1][c2];                                                   //se sacan de ambos arreglos que anteriormente se sacaron dos valores ara compararlos
            compara2=arreg[c3][0];
            compara1+=' ';

            if (compara1==compara2){                                                     //Se comparan id
                c2+=1;                                                                   //se aumenta c3 en 1 unidad
                temporal_=stoi(arreg[c3][2]);                                            //de string a entero
                temporal_2=stoi(arreglo[c1][c2]);                                        //de string a entero
                if (temporal_>=temporal_2){                                              //se analizan cantidades
                    c1+=1;
                    c2=0;
                    contadorespecial+=1;
                    restantess=temporal_-temporal_2;                                      //En este paso restante vendria siendo la cantidad restante de productos,los peroductos que quedan luego de sacar los que van ppara el combo
                    string numeroComoCadena = to_string(restantess);                      //De int a string
                    arreg[c3][2]=numeroComoCadena+ ' ';                                   //se le agrega espacio en blanco para luego en la impresión
                    c3=0;
                    ofstream regi;                                                      //ofstream Para escritura en el archivo
                    regi.open("../Desafio_evaluativo__/Productos.txt", ios::out);       //Abre el archivo y lo sobreescribe
                    if (regi.fail())                                                    //para ver si hay algún error al abrir el archivo
                        cerr << "Error----------------" << endl;                        //imprime error
                    for(int j=0;j<cantidad2;j++){                                       //este for es para moverse entre un arreglo en la primera posicion y poder sobreescribor el archivo abierto anteriormente
                        for(int r=0;r<4;r++){                                           //este for es para moverse entre un arreglo en la segunda posicion y poder sobreescribor el archivo abierto anteriormente
                            arr=arreg[j][r];                                            //a arr se le asigna un string perteneciente a un arreglo en la posicion [j][r]
                            regi<<arr;                                                  //se escribe en el archivo
                            if (r==3 && j<=cantidad2-2){                                //condiciones para escribir un salto de linea
                                regi<<'\n';
                            }
                            if(contadorespecial==puntoycoma() && r==3 && j==cantidad2-1){//condiciones para escribir un salto de linea
                                regi<<'\n';
                            }


                        }
                    }

                    regi.close();                                                           //se cierra el archivo el cual se sobreescribio
                }
             }
            c3+=1;                                                                          //se aumenta c3 en una unidad
        }
    }
    else{
        return "Una de las ID no existe.....";                                              //retornaun string indicando: "Una de las ID no existe....."
    }
    agregarcombos(idcombo,nombrecombo,valor_combo);                                         //para esto se solicitaban los parametros en esta funcion, para darselos a estafunción llamada agregarcombos
    return "Combo creado....";                                                              //retornaun string indicando: "Combo creado...."

}

int comboss::puntoycoma()
{
    /*retorna un entero con una cantiad de puntos y coma del archivo de texto Codigocombos y esto para separar los
      diferentes produtos de cada combo*/
    int cantidadparaarreglo=1;
    ifstream registro;                                                          //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);         //lee el archivo para hacer un arreglo con los datos de este
    if (registro.fail())                                                        //para ver si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                                //imprime error
    while (registro.good()){                                                    //Mientras se encuentren datos
        char tem=registro.get();                                                //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            if (tem==';'){                                                      //Si el caracter contenido en tem es un salto de linea entrara dentro del if
                cantidadparaarreglo+=1;                                         //cantidadparaarreglo se aumenta una unidad
            }
        }
        if (tem=='\n'){
            return cantidadparaarreglo;                                          //retorna un entero con una cantiad de puntos y coma
        }
    }
    return cantidadparaarreglo;                                                     //retorna un entero con una cantiad de puntos y coma
}

bool comboss::existencia()
{
    /*Esta función se encarga de retornar un valor de verdad para saber si la id ingresada por el usuario existe o no
      entre los productos disponibles, esta función es llamada unicamente en la función productosdesencriptados*/
    string dat,arr;
    string arreg[puntoycoma()][2];
    int cont1=0,cont2=0;
    ifstream regis;                                                         //ifsteram Para lectura en el archivo
    regis.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);        //lee el archivo para hacer un arreglo con los datos de este
    if (regis.fail())                                                       //para ver si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                            //imprime error
    while (regis.good()){                                                   //Mientras se encuentren datos
        char tem=regis.get();                                               //tem sera un char y se obtiene caracter por caracter de registro.get
        if (regis.good()){
            if (tem==',' || tem=='\n'){                                     //Si el caracter contenido en tem es un salto de linea o una coma entrara dentro del if
                arreg[cont1][cont2]=dat;                                    //el string contenido en datos para a ser el termino guardado en arreglo[cont1][cont2]
                dat="";                                                     //dat es un string vacio
                cont2+=1;                                                   //cont2 aumenta en una unidad
            }
            if (tem==';'){                                                   //Si el caracter contenido en tem es un punto y coma entrara dentro del if
                arreg[cont1][cont2]=dat;                                     //el string contenido en datos para a ser el termino guardado en arreglo[cont1][cont2]
                cont1+=1;                                                    //cont1 aumenta en una unidad
                cont2=0;                                                     //cont2 vuelve a ser 0

                dat="";                                                        //dat es un string vacio
            }
            if (tem==',' || tem == ';' || tem =='\n'){
            }
            else{
                dat+=tem;                                                      //Si es diferente de ,; o \n  a dat se aregal caracter tem
            }
        }
    }
    acceso funciones_;                                                          //conexión con la clase acceso
    string datos;                                                                //se declara un string
    string arreglo[funciones_.cantidad1()][4];                                  //se declara un arreglo
    int contador1=0,contador2=0;                                                //se declaran int
    ifstream registro;                                                      //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Productos.txt", ios::in);        //se intenta abrir el archivo de texto Productos
    if (registro.fail())                                                    //revisa si existe algun fallo al abrir el archivo
        cerr << "Error" << endl;                                            //imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                            //tem es declarado como char y se le asigna un caracter que se obtiene del .get
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                 //a datos se le agrega el char contenido en tem
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
    /*El pasado ciclo ya fue explicado en el ciclo anterior a este, la unica diferencia, es que el primero se encarga de leer
      wl archivo Codigocombos y el pasado ciclo el archivo productos*/
    contador1=0;
    contador2=0;
    string pruebaspru,pruebaspru1;
    int contador3=0,f;
    f=puntoycoma();                                                                 //f sere igual a lo que retorne la funcion puntoycomo que sera un entero con la cantidad de puntos y comas de codigocombo
    bool flag=false;                                                                //flag se le asigna falso
    while (contador3<puntoycoma()){                                                 //mientras el contador sea menor a la cantidad de puntoycoma
        pruebaspru=arreg[contador3][0];                                             //pruebaspru es igual a un elemento del arreglo que contiene una id
        pruebaspru+=' ';                                                            //se le adiciona un espacio para poder comparar
        for(int i=0;i<funciones_.cantidad1();i++){
            pruebaspru1=arreglo[i][0];                                              //pruebaspru1 es igual a un elemento del arreglo que contiene una id
            if(flag==true){                                                         //si flag es verdadero entrara al if
                i=0;                                                                //i es igual a 0
                if(contador3<f-1){                                                  //si contador3 es menor que el total de puntos y comas menos uno
                    flag=false;                                                     //flag será falso
                }

                break;                                                              //para el ciclo for
            }
            if(pruebaspru==pruebaspru1){                                            //si las id coinciden flag sera verdadero
                flag=true;
            }
            else{                                                                   //si las id no coinciden las id seran falsas
                flag=false;
            }

        }
        contador3+=1;                                                               //contador3 aumenta en una unidad

    }
    return flag;                                                                    //retorna falso
}

void comboss::menucombos()
{
    /*Esta función es para imprimir el menú en pantalla*/
    string info;
    ifstream registro;                                                  //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::in);       //lee el archivo para hacer un arreglo con los datos de este
    if (registro.fail())                                                //revisa si hay algún error al abrir el archivo
        cerr << "Error" << endl;                                        //imprime error
    printf("%2c",' ');                                                  //printfc tambien es un tipo de cout
    printf("%c",' ');                                                   //printfc tambien es un tipo de cout
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            info+=tem;
            printf("%c",tem);                                           //printfc tambien es un tipo de cout
        }
        if (tem=='\n'){

            cout<<" ||=======================================================||"<<endl;
            printf("%2c",' ');                                          //printfc tambien es un tipo de cout
            printf("%c",' ');                                           //printfc tambien es un tipo de cout
        }

    }
}

string comboss::comboseleccionado(string idparacombo)
{
    /*Esta función se encarga de verificar si la id del combo pedido existe y si existe retorna el valor del combo, si nno existe retorna un string indicando que no existe*/
    acceso funcionesss;                                                 //conexión con la clase acceso
    string datos="";
    string arreg[funcionesss.cantidad2()-1][3];                         //se crea un arreglo de strings con una longitud determinada por otra función que se encuentra en la clase acceso
    int contador1=0,contador2=0;
    ifstream regis;                                                     //ifsteram Para lectura en el archivo
    regis.open("../Desafio_evaluativo__/Combos.txt", ios::in);          //abre el archivo
    if (regis.fail())                                                   //si hay una falla al abrir el archivo
        cerr << "Error" << endl;                                        //si hay una falla imprime error y se sale de la función
    while (regis.good()){
        char tem=regis.get();                                           //se le asigna un char de el archivo que se esta leyendo a tem
        if (regis.good()){
            if (tem!=' ' || tem!='\n'){                                 //Si el caracter contenido en tem es una coma o un salto de linea entrara dentro del if
                if (tem==' '){}
                if (tem=='\n'){}
                else{
                    datos+=tem;                                         //a datos se le agrega el char contenido en tem
                }
                }
            if (tem==' ' || tem=='\n'){                                 //Si el caracter contenido en tem es una coma o un salto de linea entrara dentro del if
                arreg[contador2][contador1]=datos;                       //a datos se le asigna el string guardadp  en una posiciión del arreglo
                contador1=contador1+1;                                  //se aumenta comtador1 en una unidad
                if (tem=='\n'){
                    contador2=contador2+1;                              //se aumenta contador2 en una unidad
                    contador1=0;                                        //contador1 se iguala a 0
                    }
                datos="";                                               //datos vuelve a ser una string vacio
                }

            }
    }
    int limite=funcionesss.cantidad2()-1;                               //limite sera igual a lo que retorne la función cantidad2 localozada en la clase acceso
    idparacombo+=' ';                                                   //idparacombo inicaialmente es uno de los parametros ahoto se le agrega un espacio para poder comparar
    for(int i=0;i<limite;i++){                                          //el for es para recorrer el arreglo antes realizado
        string problema=arreg[i][0];                                    //a problema se le asigna el string contenido en esta parte de arreglo
        if(idparacombo==problema){                                      //por defecto problema tendra un espacio al final, por ello a idparacombo se le agrego un espacio, ahora se comparan,(¿que se comparan?)R:id
            return arreg[i][2];                                         //se retorna el precio del combo
        }
    }
    return "la ID ingresada no existe entre los combos.........";       //si la id no existe, o sea, el combo no existe, se imprime el mensaje despues del return y sale de la función
}

void comboss::sordenusuario(int valor)
{
    /*Estaes la implementación de el problema 1 de la practica 2 par el tema de realizción de pago al comprar un combo*/
    int monedas[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};      //arreglo de int
    for(int i=0;i<10;i++){                                                  //ciclo que recorre el arreglo
        int cantidad=valor/(*(monedas+i));                                  //operación matematica que hace uso del parametro
        if (cantidad != 0){
            cout<<*(monedas+i)<<": "<<cantidad<<endl;                       //si la cantidad es distinta de 0 se imprimira el valor de la minima cnatidad de billetes o monedas posible para realizar el pago
        }
        valor%=*(monedas+i);                                                //se realiza otra operación matematica con los parametros para actualizar este mismo
    }
}

string comboss::pagocomborealizado(int idparacombos)
{
    /*Esta función se encarga de ingresar al archivo de texto C_combos y restar una unidad a la cantidad de combos disponibles*/
    acceso funcionessss;                                                        //conexión con la clase acceso
    string datos,arr;                                                           //se declaran strings
    string arreglo[funcionessss.cantidad3()][2];                                //se declara un arreglo
    int contador1=0,contador2=0,restante,cantidad2=funcionessss.cantidad3();    //se declaran int
    ifstream registro;                                                          //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/C_combos.txt", ios::in);             //abre el archivo
    if (registro.fail())                                                        //si hay una falla al abrir el archivo
        cerr << "Error" << endl;                                                //si hay una falla imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                                //se le asigna un char de el archivo que se esta leyendo a tem
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){                                         //Si el caracter contenido en tem es un salto de linea una coma entrara dentro del if
                if (tem==' '){
                }
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                 //a datos se le agrega el char contenido en tem
                }
                }
            if (tem==' ' || tem=='\n'){                                         //Si el caracter contenido en tem es un salto de linea o una coma entrara dentro del if
                arreglo[contador2][contador1]=datos;                            //a datos se le asigna el string guardadp  en una posiciión del arreglo
                contador1=contador1+1;                                          //se aumenta contador1 en una unidad
                if (tem=='\n'){                                                 //Si el caracter contenido en tem es un salto de linea entrara dentro del if
                    contador2=contador2+1;                                      //se aumenta contador2 en una unidad
                    contador1=0;                                                //se iguala contador1 a 0
                    }
                datos="";                                                       //datos será un string vacio
                }

            }
    }
    datos=arreglo[idparacombos-1][1];                                           //a datos se le asigna el string guardadp  en una posiciión del arreglo
    int contadoressss=0;                                                        // se declara un int contador
    contadoressss=stoi(datos);                                                  //de string a entero
    restante=contadoressss-1;                                                   // se le resta una unidad al string antes convertido a string
    std::string numeroComoCadena = std::to_string(restante);                    //de int a string
    arreglo[idparacombos-1][1]=numeroComoCadena;                                //se reemplaza la informacion correspondiente a est posición en el arreglo con un nuevo el mismo valor-1, por ello se necesito convertir a int
    ofstream registross;                                                        //ofstream Para escritura en el archivo
    registross.open("../Desafio_evaluativo__/C_combos.txt", ios::out);          //abre el archivo de texto C_combos
    if (registross.fail())                                                      //si existe algún error al abrir el archivo
        cerr << "Error" << endl;                                                //imprime error y se sale de la función
    for(int j=0;j<cantidad2;j++){                                               //en estos siguientes ciclos for solo se aumenta el valor de los contadores para avanzar en el arreglo
        for(int r=0;r<2;r++){
            arr=arreglo[j][r];                                                  //a arr se le asigna el valor de la pocision que se encuentra en este momento en el arreglo
            registross<<arr;                                                    //escribe en el archivo la informacion registrada en arr
            if(r==1 && j!=cantidad2-1){
                registross<<'\n';                                               // escribe un salto de linea si es necesario

            }

        }
    }
    registro.close();                                                           //cierra el archivo de texto
}


bool comboss::cntidadcombos(string idcc,string cantidad_combos)
{
    /*Se encarga de escribir la id con la cantidad de combos en un archivo de texto para luego manipular facilmente la cantidad de los combos*/
    ofstream registro;                                                  //ofstream Para escritura en el archivo
    registro.open("../Desafio_evaluativo__/C_combos.txt", ios::app);    //intenta abrir el archivo C_combos que tiene la cantidad de combos
    if (registro.fail())                                                //revisa si eciste algún fallo al abrir el archivo
        cerr << "Error" << endl;                                        //imprime error y se sale de la función
    registro<<idcc;                                                     //escribe al final del archivo uno de los paramentros y es una id
    registro<<" ";                                                      //escribe al final del archivo un espacio en blanco
    registro<<cantidad_combos;                                          //escribe al final del archivo uno de los paramentros y es la cantidad de combos
    registro<<endl;                                                     //escribe al final del archivo un salto de linea

    return true;                                                        //retorna true y sale de la función
}

void comboss::cantidaddeproductosparaelcombo(int combo)
{       /*Esta función se encarga de primero obtener como parametro la cantidad de combos deseada y luego multiplicar esta cantidad por cada una
          de las cantidades que se requieren en productos para el combo*/
    string datos,arr;                                                           //declara strings
    bool flag=false;                                                            //declara un valor booleano
    string arreglo[puntoycoma()][2];                                            //declara un arreglo
    int contador1=0,contador2=0,cantidad2=puntoycoma();                         //declara valores int
    ifstream registro;                                                            //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);             //intenta abrir el archivo de texto Codigocombos
    if (registro.fail())                                                            //revisa si existe algún error al abrir el archivo
        cerr << "Error" << endl;                                                   //imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                                //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            if (flag==true){
            }
            if (tem!=',' || tem!=';'){                                              //Si el caracter contenido en tem es un punto y coma o una coma entrara dentro del if
                if (tem==','){
                }
                else{
                    datos+=tem;                                                     //a datos se le agrega el char contenido en tem
                }
                }
            if (tem==',' || tem==';' || tem=='\n'){                                 //Si el caracter contenido en tem es un salto de linea una coma o un punto y coma entrara dentro del if
                arreglo[contador2][contador1]=datos;
                contador1=contador1+1;
                if (tem==';'){                                                      //Si el caracter contenido en tem es un punto y coma entrara dentro del if
                    contador2=contador2+1;                                          //contador2 aumenta en una unidad
                    contador1=0;                                                    //contador1 se iguala a 0
                    }
                datos="";                                                           //datos seráun string vacio
                }
            }
    }
    string primeraparte1;                                                           //se declara un string
    for(int i=0;i<cantidad2;i++){                                                   //recorre el arreglo que en el pasado ciclo desarrollamos
        primeraparte1=arreglo[i][0];                                                //a primeraparte1 se se asigna el valor de una posición del archivo
        arreglo[i][0]=primeraparte1+',';                                            //se le agrega , a cada una de las primeras partes del arreglo
    }
    string primeraparte;                                                            //se declara string
    int primeraparteentera;                                                         //se declaran int
    bool falg1=false;                                                               //se declara bool
    for(int i=0;i<cantidad2;i++){                                                   //recorre el arreglo pasado
        primeraparte=arreglo[i][1];                                                 //las proximas 10 lineas de codigo, esta incluida de encargan de eliminar el salto de lineal al final de algunas partes del arreglo
        string palabra= primeraparte;
        size_t tam= palabra.length();
        if (palabra[tam-1]=='\n'){
            falg1=true;
        }
        else{
            falg1=false;
        }
        palabra.erase(tam-1);
        primeraparteentera=stoi(palabra);                                           //de string a int
        primeraparteentera*=combo;                                                  //se multiplica la candidad de cada producto necesario para el combo con el total de combos
        primeraparte=to_string(primeraparteentera);                                 //de int a string
        if (falg1==false){                                                          //en las proximas 8 lineas de codigo incluida esta se le agregara , o ; a los datos contenidos en el arreglo
            arreglo[i][1]=primeraparte+';';
        }
        else {
            arreglo[i][1]=primeraparte+'\n';
        }
    }
    /*Actualiza el archivo donde se encuentra el codigo para el combo con las cantidades actualizadas*/
    ofstream regi;                                                              //ofstream Para escritura en el archivo
    regi.open("../Desafio_evaluativo__/Codigocombos.txt", ios::out);            //abre el archivo Codigocombos
    if (regi.fail())                                                            //revisa si hay algún error al abrir el archivo
        cerr << "Error----------------" << endl;                                //imprime error y sale de la función
    for(int j=0;j<cantidad2;j++){                                               //en estos siguientes ciclos for solo se aumenta el valor de los contadores para avanzar en el arreglo
        for(int r=0;r<2;r++){
            arr=arreglo[j][r];                                                  //a arr se le da el string guardado en la pocisión del arreglo dependiendo de j/r
            regi<<arr;
            if (r==2 && j!=cantidad2-1){
                regi<<';';                                                       //se escribe ; cunado sea conveniente, la condición esta el la line a de codigo anterior
            }
            if(r==2 && j==cantidad2-1){
                regi<<'\n';                                                     //se escribe ; cunado sea conveniente, la condición esta el la line a de codigo anterior
            }
        }
    }

}

string comboss::combosdisponibles()
{
    /*Esta función se encarga de sobreescribir el archivo de texto donde se encuentran la cantidad de comobos elimnando los combos en donde ya no hay mas unidades disponibles*/
    acceso funcionessss;
    string datos,arr;
    string arreglo[funcionessss.cantidad3()][2];
    int contador1=0,contador2=0,restante,cantidad2=funcionessss.cantidad3();
    ifstream registro;                                                              //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/C_combos.txt", ios::in);                 //intenta abrir el archivo de texto C_combos
    if (registro.fail())                                                            // revisa si existe algún fallo al abrir el archivo
        cerr << "Error" << endl;                                                    //imprime error y se sale de la función
    while (registro.good()){
        char tem=registro.get();                                                    //tem sera un char y se obtiene caracter por caracter de registro.get
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){                                             //Si el caracter contenido en tem es un salto de linea o un espacio entrara dentro del if
                if (tem==' '){                                                      //Si el caracter contenido en tem es un espacio entrara dentro del if
                }
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                     //Si el caracter contenido en tem es diferenta a un salto de linea se agregara a datos
                }
                }
            if (tem==' ' || tem=='\n'){                                             //Si el caracter contenido en tem es un salto de linea o un espacio entrara dentro del if
                arreglo[contador2][contador1]=datos;
                contador1=contador1+1;
                if (tem=='\n'){                                                     //Si el caracter contenido en tem es un salto de linea entrara dentro del if
                    contador2=contador2+1;                                          //contador2 aumenta en una unidad
                    contador1=0;                                                    //contador1 se iguala a 0
                    }
                datos="";                                                           //datos vuelve a ser un string vacio
                }

            }
    }
    int ayuda,contador44=0;                                                         // se declaran valores int
    string u,f,w;                                                                   // se declaran algunos strings
    for (int i=0;i<cantidad2;i++){
        u=arreglo[i][1];                                                            //a u se le asugna el valor de dicha posición del arreglo, que sera la cantidad de combos
        restante=stoi(u);                                                           // de string a int
        f=arreglo[i][0];                                                            //a f se le asugna el valor de dicha posición del arreglo, que sera la id
        string palabra= f;                                                          //se define palabra como string y se le da el string contenido en f
        size_t tam= palabra.length();                                               //se toma el tamaño
        palabra.erase(tam-1);                                                       //se borra el espacio final del string que siepre tendra por defecto
        ayuda=stoi(palabra);                                                        //de string a int

        if (restante==0){                                                           //si la catidad es 0
            w=arreglo[i][0];                                                        //w toma el valor de esta posición de arreglo antes de ser convertida en 0, el valor es una id
            arreglo[i][0]="0";                                                      //esta linea y la siguiente,se encargas de asignar el valor 0 a pocisiones del archivo en donde la cantidad de combos ya sea 0
            arreglo[i][1]="0";
            ofstream regi;                                                      //ofstream Para escritura en el archivo
            regi.open("../Desafio_evaluativo__/C_combos.txt", ios::out);             //intenta abrir el archivo C_combos
            if (regi.fail())                                                        //revisa si hay algún error al abrir el archivo
                cerr << "Error----------------" << endl;                            //imprime error y se sale de la función
            for(int j=0;j<cantidad2;j++){                                           //en estos siguientes ciclos for solo se aumenta el valor de los contadores para avanzar en el arreglo
                for(int r=0;r<2;r++){
                    arr=arreglo[j][r];                                              //a arr se le da el string guardado en la pocisión del arreglo dependiendo de j/r
                    if (arr!="0"){                                                  //si la información contenida en arr es diferente de "0" ingresa al if
                        regi<<arr;                                                  //escribe al final del archivo la información contenida en arr
                        if(r==1 && j!=cantidad2-1){
                            regi<<'\n';                                             //escribe al final del archivo un salto de linea
                        }
                    }

                }
            }
            regi.close();                                                           //cierra el archivo que estabamos utilizando
            return w;                                                               //retorna el string contenido en w, que sera una id
        }
        else{
            contador44+=1;                                                          // contador44 aumneta en una unidad
            if (contador44==cantidad2-1){

                return "Final";                                                     //retorna un string que dira "Final" para funalizar la función
            }
        }

    }
    return "Final";                                                                 //retorna un string que dira "Final" para funalizar la función
}

string comboss::alteracionencombos(string numeroparacombos)
{
    /*Se encarga de revisr si hay algun combo agotado  y sobreescribe el archivo Combos para eliminar dicho combo agotado
     el resto permanece igual*/
    acceso funcionessss;                                                            // conexión con la clase acceso
    string datos,arr;                                                               //Se definen strings
    string arreglo[funcionessss.cantidad2()][3];                                        //se define un arreglo de strings de dimensiones total de (la cantidad que retorne una funcion perteneciente a la clase acceso)*3
    int contador1=0,contador2=0,cantidad2=funcionessss.cantidad2(),contador44=0;        //se definen enteros
    ifstream registro;                                                              //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::in);                       //abre el archivo Combos
    if (registro.fail())                                                                //se encarga de mirar si hay algún al abrir el archivo
        cerr << "Error" << endl;                                                        //imprime error y te saca de la función
    while (registro.good()){
        char tem=registro.get();                                                        //tem es una char y obtendra un caracter de registro.get que recorre el archivo
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){                                                 //Si el caracter contenido en tem es un salto de linea o un espacio entrara dentro del if
                if (tem==' '){
                }
                if (tem=='\n'){}
                else{
                    datos+=tem;                                                         //Si el caracter contenido en tem es un salto de linea o un espacio a datos se le agregará tem
                }
                }
            if (tem==' ' || tem=='\n'){                                                 //Si el caracter contenido en tem es un salto de linea o un espacio entrara dentro del if
                arreglo[contador2][contador1]=datos;                                    //arreglo[contador2][contador1] sera igual a la informacion contenida en datos
                contador1=contador1+1;                                                  //contador1 se aumenta en una unidad
                if (tem=='\n'){                                                         //Si el caracter contenido en tem es un salto de linea entrara dentro del if
                    contador2=contador2+1;                                              //contador2 se aumenta en una unidad
                    contador1=0;                                                        //contador1 se iguala a 0
                    }
                datos="";                                                               //datos será un string vacio
                }

            }
    }
    string u,f,g;                                                           //definimos u,f,g como strings
    for (int i=0;i<cantidad2;i++){                                          //recorre un arreglo
        g=arreglo[i][2];                                                    //g sera igual a lo contenido en dicha posición del arreglo que sera un precio
        u=arreglo[i][1];                                                    //u sera igual a lo contenido en dicha posición del arreglo que sera un nombre
        f=arreglo[i][0];                                                    //f sera igual a lo contenido en dicha posición del arreglo que sera una id


        if (f==numeroparacombos){                                           //se comparan id
            arreglo[i][0]="0";                                              //el valor contenido en esta posición de arreglo se iguala a 0
            arreglo[i][1]="0";                                              //el valor contenido en esta posición de arreglo se iguala a 0
            arreglo[i][2]="0";                                              //el valor contenido en esta posición de arreglo se iguala a 0
            ofstream regi;                                                      //ofstream Para escritura en el archivo
            regi.open("../Desafio_evaluativo__/Combos.txt", ios::out);      //intenta ingresar al archivo de texto Combos
            if (regi.fail())                                                //si el ingreso al archivo de texto falla
                cerr << "Error----------------" << endl;                    //imprime error en caso de que se encuente algún error y te saca de la función
            for(int j=0;j<cantidad2;j++){                                   //en estos siguientes ciclos for solo se aumenta el valor de los contadores para avanzar en el arreglo
                for(int r=0;r<3;r++){
                    arr=arreglo[j][r];                                      //se le agrega a arr el valor de una de las pocisiones del arreglo dependiendo de los contadores
                    if (arr!="0"){                                          //si la información contenida en arr es diferente de core ingresaal if
                        regi<<arr;                                          //escribe al final del archivo la información contenida en arr
                        if(r==2 && j!=cantidad2-1){                         //si cumple las condiciones de la posición del arreglo imprimira un salto de linea para salir del ciclo
                            regi<<'\n';                                     //escribe al final del archivo un salto de linea
                        }
                    }

                }
            }

        }
        else{
            contador44+=1;                                                  //aumenta contador44 en una unidad
            if (contador44==cantidad2-1){                                   //compara 2 cantidades para salirse del ciclo si cumple la condición

                return "Final";                                             //retorna un string que dice "Final"
            }
        }

    }
    return "Final";                                                         //retorna un string que dice "Final"
}

bool comboss::reportedeventas(string idparacomboss, string asiento, string sala, string UserName)
{       /*Esta función se encarga de escribir al final el archivo de texto Reportedeventas*/
    ofstream registro;                                                              //ofstream Para escritura en el archivo
    registro.open("../Desafio_evaluativo__/Reportedeventas.txt", ios::app);         //ingresa al archivo de texto Reportedeventas
    if (registro.fail())                                                                //se encarga de mirar si hay algun error al abrir el archivo
        cerr << "Error" << endl;                                                        //imprime error y sale de la función
    registro<<"-El dia de hoy se realizo la venta del combo numero: ";                  //al final del archivo escribe -El dia de hoy se realizo la venta del combo numero:
    registro<<idparacomboss;                                                            //al final del archivo escribe un parametro llamado idparacombos
    registro<<" al señor(a) con el usuario: ";                                          //al final del archivo escribe el señor(a)
    registro<<UserName;                                                                 //al final del archivo escribe un parametro llamado UserName
    registro<<"\nel combo se le llevo a la sala: ";                                     //al final del archivo escribe el combo se le llevo al asiento:
    registro<<sala;                                                                     //al final del archivo escribe un parametro llamado sala
    registro<<" con asiento: ";                                                         //al final del archivo escribe con asiento:
    registro<<asiento;                                                                  //al final del archivo escribe un parametro llamado asiento
    registro<<".........";                                                              //al final del archivo escribe puntos suspensivos
    registro<<endl;                                                                     //al final del archivo escribe un salto de linea

    return true;                                                                        //retorna un valor booleano verdadero
}

string comboss::reportedeventasimpresion()
{
    /*Esta función se encarga de retornar toda la información contenida en el archivo de Reportedeventas*/
    string info;                                                                //info es un string
    ifstream registro;                                                          //ifsteram Para lectura en el archivo
    registro.open("../Desafio_evaluativo__/Reportedeventas.txt", ios::in);      //abre el archivo Reportedeventas
    if (registro.fail())                                                        //si ocurre algun error al abrir el archivo
        cerr << "Error" << endl;                                                 //imprime error y te saca de la función
    while (registro.good()){
        char tem=registro.get();                                                //a char se le agregara un caracter del archivo
        if (registro.good()){
            info+=tem;                                                             //a info se le agregara el dato contenido en tem
        }

    }
    return info;                                                                 //retorna la información contenida en el archivp Reportedeventas
}

