#include <iostream>

using namespace std;


int todosencendidos()
{
    char high='+', low='-';
    char matriz[8][8];
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            matriz[i][j]= high;
        }
    }
    //Imprimir la matriz
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            char posicion= matriz[i][j];
            char espacio= ' ';
            cout<< espacio<< posicion;
        }
        cout<<endl;
    }
}

int primeraFigura()
{
    char high='+', low='-';
    char matriz[8][8];
    int cotainferior=3, cotasuperior=5;
    //primera parte de la figura
    for(int i=0; i<5; i++){
        for(int j=0;j<8;j++){
            if(j>=cotainferior and j<cotasuperior){
                for(int control2=j; control2<cotasuperior;control2++){
                    matriz[i][j]=high;}
            }else{
                matriz[i][j]=low;
            }
        }
        if(i<4){
            cotainferior-=1;
            cotasuperior+=1;
        }

    }
    //segunda parte de la figura
    cotainferior=1; cotasuperior=7;
    for(int i=5; i<8; i++){
        for(int j=0;j<8;j++){
            if(j>=cotainferior and j<cotasuperior){
                for(int control2=j; control2<cotasuperior;control2++){
                    matriz[i][j]=high;}
            }else{
                matriz[i][j]=low;
            }
        }
        cotainferior+=1;
        cotasuperior-=1;
    }

    //Imprimir la matriz
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            char posicion= matriz[i][j];
            char espacio= ' ';
            cout<< espacio<< posicion;
        }
        cout<<endl;
    }
}

int cruz()
{
    char high='+', low='-';
    char matriz[8][8];
    int extremoIzquierdo=0, extremoDerecho=7;
    //Figura
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            if(j==extremoIzquierdo){
                matriz[i][j]=high;
            }else if(j==extremoDerecho){
                matriz[i][j]=high;
            }else{
                matriz[i][j]=low;
            }
        }
        extremoIzquierdo+=1;
        extremoDerecho-=1;
    }
    //Imprimir la matriz
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            char posicion= matriz[i][j];
            char espacio= ' ';
            cout<< espacio<< posicion;
        }
        cout<<endl;
    }
}

int terceraFigura()
{
    char high = '+', low='-';
    char matriz[8][8];
    int i = 0;
    int sep1 = 0,sep2 = 2, sep3 = 3, sep4 = 5, sep5 = 6; //señalamos los leds apagados
    //introducimos el ciclo for que se encarga de llenar la matriz
    while(i >=0 && i<8){
        //hacemos los ciclos que van a crear las filas
        for(int a=0; a<2; a++){
            for(int j=0; j<8; j++){
                if(j==sep2 || j==sep4){
                    matriz[i][j]=low;
                }else{
                    matriz[i][j]=high;
                }
            }
            i += 1;
        }
        for(int a=0;a<2;a++){
            for(int j=0; j<8; j++){
                if(j==sep1 || j==sep3 || j==sep5){
                    matriz[i][j]=low;
                }else{
                    matriz[i][j]=high;
                }
            }
            i += 1;
        }

    }
    //imprimimos la matriz

    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            char posicion= matriz[i][j];
            char espacio= ' ';
            cout<< espacio<< posicion;
        }
        cout<<endl;
    }
}

int flecha()
{
    char high='+', low='-';
    char matriz[8][8];
    int cotainferior=0, cotasuperior=4;
    //primera parte de la figura
    for(int i=0; i<5; i++){
        for(int j=0;j<8;j++){
            if(j>=cotainferior and j<cotasuperior){
                for(int control2=j; control2<cotasuperior;control2++){
                    matriz[i][j]=high;}
            }else{
                matriz[i][j]=low;
            }
        }
        if(i<3){
            cotainferior+=1;
            cotasuperior+=1;
        }

    }
    //segunda parte de la figura
    cotainferior=2; cotasuperior=6;
    for(int i=5; i<8; i++){
        for(int j=0;j<8;j++){
            if(j>=cotainferior and j<cotasuperior){
                for(int control2=j; control2<cotasuperior;control2++){
                    matriz[i][j]=high;}
            }else{
                matriz[i][j]=low;
            }
        }
        cotainferior-=1;
        cotasuperior-=1;
    }

    //Imprimir la matriz
    for(int i=0; i<8; i++){
        for(int j=0;j<8;j++){
            char posicion= matriz[i][j];
            char espacio= ' ';
            cout<< espacio<< posicion;
        }
        cout<<endl;
    }
}
