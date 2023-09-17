#include <iostream>

using namespace std;


int main()
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

