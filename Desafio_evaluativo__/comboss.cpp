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

string comboss::productosdesencriptados(string idcombo,string nombrecombo,string valor_combo)
{
    bool decisiva;
    decisiva=existencia();
    if (decisiva==false){
        return "Una de las ID no existe.....";
    }
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
    string compara1,compara2;
    while(contadorespecial<puntoycoma()){
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

                contadorespecial+=1;
            }
            else{
                return "No tiene la cantidad de productos suficientes para este combo";
            }
         }

         else{
             flag=false;
         }
        c3+=1;
    }
    c1=0;
    c2=0;
    c3=0;
    contadorespecial=0;
    if (flag==true){
        while(contadorespecial<puntoycoma()){
            compara1=arreglo[c1][c2];
            compara2=arreg[c3][0];
            compara1+=' ';

            if (compara1==compara2){
                c2+=1;
                temporal_=stoi(arreg[c3][2]);
                temporal_2=stoi(arreglo[c1][c2]);
                if (temporal_>=temporal_2){
                    c1+=1;
                    c2=0;
                    contadorespecial+=1;
                    restantess=temporal_-temporal_2;
                    string numeroComoCadena = to_string(restantess);
                    arreg[c3][2]=numeroComoCadena+ ' ';
                    c3=0;
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
                            if(contadorespecial==puntoycoma() && r==3 && j==cantidad2-1){
                                regi<<'\n';
                            }


                        }
                    }

                    regi.close();
                }
             }
            c3+=1;
        }
    }
    else{
        return "Una de las ID no existe.....";
    }
    agregarcombos(idcombo,nombrecombo,valor_combo);
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

bool comboss::existencia()
{
    string dat,arr;
    string arreg[puntoycoma()][2];
    int cont1=0,cont2=0;
    ifstream regis;
    regis.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);
    if (regis.fail())
        cerr << "Error" << endl;
    while (regis.good()){
        char tem=regis.get();
        if (regis.good()){
            if (tem==',' || tem=='\n'){
                arreg[cont1][cont2]=dat;
                dat="";
                cont2+=1;
            }
            if (tem==';'){
                arreg[cont1][cont2]=dat;
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
    acceso funciones_;
    string datos;
    string arreglo[funciones_.cantidad1()][4];
    int contador1=0,contador2=0;
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
    contador1=0;
    contador2=0;
    string pruebaspru,pruebaspru1;
    int contador3=0,f;
    f=puntoycoma();
    bool flag=false;
    while (contador3<puntoycoma()){
        pruebaspru=arreg[contador3][0];
        pruebaspru+=' ';
        for(int i=0;i<funciones_.cantidad1();i++){
            pruebaspru1=arreglo[i][0];
            if(flag==true){
                i=0;
                if(contador3<f-1){
                    flag=false;
                }

                break;
            }
            if(pruebaspru==pruebaspru1){
                flag=true;
            }
            else{
                flag=false;
            }

        }
        contador3+=1;

    }
    return flag;
}

void comboss::menucombos()
{
    string info;
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Combos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    printf("%2c",' ');
    printf("%c",' ');
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            info+=tem;
            printf("%c",tem);
        }
        if (tem=='\n'){

            cout<<" ||=======================================================||"<<endl;
            printf("%2c",' ');
            printf("%c",' ');
        }

    }
}

string comboss::comboseleccionado(string idparacombo)
{
    acceso funcionesss;
    string datos="";
    string arreg[funcionesss.cantidad2()-1][3];
    int contador1=0,contador2=0;
    ifstream regis;
    regis.open("../Desafio_evaluativo__/Combos.txt", ios::in);
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
    int limite=funcionesss.cantidad2()-1;
    idparacombo+=' ';
    for(int i=0;i<limite;i++){
        if(idparacombo==arreg[i][0]){
            return arreg[i][2];
        }
    }
    return "la ID ingresada no existe entre los combos.........";
}

void comboss::sordenusuario(int valor)
{
    int monedas[10]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    for(int i=0;i<10;i++){
        int cantidad=valor/(*(monedas+i));
        if (cantidad != 0){
            cout<<*(monedas+i)<<": "<<cantidad<<endl;
        }
        valor%=*(monedas+i);
    }
}

string comboss::pagocomborealizado(int idparacombos)
{
    acceso funcionessss;
    string datos,arr;
    string arreglo[funcionessss.cantidad3()][2];
    int contador1=0,contador2=0,restante,cantidad2=funcionessss.cantidad3();
    ifstream registro;
    registro.open("../Desafio_evaluativo__/C_combos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            if (tem!=' ' || tem!='\n'){
                if (tem==' '){
                }
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
    datos=arreglo[idparacombos-1][1];
    int contadoressss=0;
    contadoressss=stoi(datos);
    restante=contadoressss-1;
    std::string numeroComoCadena = std::to_string(restante);
    arreglo[idparacombos-1][1]=numeroComoCadena;
    ofstream registross;
    registross.open("../Desafio_evaluativo__/C_combos.txt", ios::out);
    if (registross.fail())
        cerr << "Error" << endl;
    for(int j=0;j<cantidad2;j++){
        for(int r=0;r<2;r++){
            arr=arreglo[j][r];
            registross<<arr;
            if (r==1 && j==cantidad2-1){
                registross<<'\n';
            }
        }
    }
    registro.close();
}


bool comboss::cntidadcombos(string idcc,string cantidad_combos)
{
    ofstream registro;
    registro.open("../Desafio_evaluativo__/C_combos.txt", ios::app);
    if (registro.fail())
        cerr << "Error" << endl;
    registro<<idcc;
    registro<<" ";
    registro<<cantidad_combos;
    registro<<endl;

    return true;
}

void comboss::cantidaddeproductosparaelcombo(int combo)
{
    string datos,arr;
    bool flag=false;
    string arreglo[puntoycoma()][2];
    int contador1=0,contador2=0,cantidad2=puntoycoma();
    ifstream registro;
    registro.open("../Desafio_evaluativo__/Codigocombos.txt", ios::in);
    if (registro.fail())
        cerr << "Error" << endl;
    while (registro.good()){
        char tem=registro.get();
        if (registro.good()){
            if (flag==true){
            }
            if (tem!=',' || tem!=';'){
                if (tem==','){
                }
                else{
                    datos+=tem;
                }
                }
            if (tem==',' || tem==';' || tem=='\n'){
                arreglo[contador2][contador1]=datos;
                contador1=contador1+1;
                if (tem==';'){
                    contador2=contador2+1;
                    contador1=0;
                    }
                datos="";
                }
            }
    }
    string primeraparte1;
    for(int i=0;i<cantidad2;i++){
        primeraparte1=arreglo[i][0];
        arreglo[i][0]=primeraparte1+',';
    }
    string primeraparte;
    int primeraparteentera;
    bool falg1=false;
    for(int i=0;i<cantidad2;i++){
        primeraparte=arreglo[i][1];
        string palabra= primeraparte;
        size_t tam= palabra.length();
        if (palabra[tam-1]=='\n'){
            falg1=true;
        }
        else{
            falg1=false;
        }
        palabra.erase(tam-1);
        primeraparteentera=stoi(palabra);
        primeraparteentera*=combo;
        primeraparte=to_string(primeraparteentera);
        if (falg1==false){
            arreglo[i][1]=primeraparte+';';
        }
        else {
            arreglo[i][1]=primeraparte+'\n';
        }
    }
    ofstream regi;
    regi.open("../Desafio_evaluativo__/Codigocombos.txt", ios::out);
    if (regi.fail())
        cerr << "Error----------------" << endl;
    for(int j=0;j<cantidad2;j++){
        for(int r=0;r<2;r++){
            arr=arreglo[j][r];
            regi<<arr;
            if (r==2 && j!=cantidad2-1){
                regi<<';';
            }
            if(r==2 && j==cantidad2-1){
                regi<<'\n';
            }
        }
    }

}

string comboss::combosdisponibles()
{

}
