
#include<iostream>
#include "estruturas.h"
#include "biblioteca.h"
#include <cmath>

using namespace std;

int main(){

    //quantos pontos
    int qtdP;

    cout<<"quantidade de pontos :"<<endl;
    cin>>qtdP;

    //auxiliares
    int i,j,k;

    //pontos
    pontos *ponto;
    ponto = new pontos[qtdP];

    for(i=0;i<qtdP;i++){
    cout<<endl<<"digite o ponto "<< i+1 <<" :"<<endl;
    cout<<"x:";
    cin>>ponto[i].x;
    cout<<"y:";
    cin>>ponto[i].y;
    }

    //circulo
    int qtdC;


    qtdC=0;
    for(i=0;i<(qtdP);i++){
        for(j=(qtdP-1);j>i;j--){
            qtdC++;
        }
    }
    circulos *circulo;
    circulo= new circulos[qtdC];

    k=0;
    for(i=0;i<(qtdP);i++){
        for(j=(qtdP-1);j>i;j--){
            circulo[k].diametro = distancia(ponto[i].x,ponto[i].y,ponto[j].x,ponto[j].y);

            circulo[k].centroX = media(ponto[i].x,ponto[j].x);
            circulo[k].centroY = media(ponto[i].y,ponto[j].y);

            circulo[k].baseX = ponto[i].x;
            circulo[k].base1X = ponto[j].x;
            circulo[k].baseY = ponto[i].y;
            circulo[k].base1Y = ponto[j].y;


            k++;
        }
    }

    for(i=0;i<qtdC;i++){
        cout<<endl<<"Circulo "<<i+1<<": ";
        cout<<endl<<"Formado pelos pontos: ("<<circulo[i].baseX<<","<<circulo[i].baseY<<") e ("<<circulo[i].base1X<<","<<circulo[i].base1Y<<")";
        cout<<endl<<"Diametro: "<<circulo[i].diametro;
        cout<<endl<<"Centro: ("<<circulo[i].centroX<<","<<circulo[i].centroY<<")"<<endl;
        circulo[i].pontos = 0;
    }

    for(i=0;i<qtdC;i++){
        for(j=0;j<qtdP;j++){
            if((distancia(circulo[i].centroX , circulo[i].centroY , ponto[j].x , ponto[j].y)*2) < circulo[i].diametro){
            circulo[i].pontos++;
            }
        }
    }

    float maior;

    maior=circulo[0].pontos;
    k=0;
    for(i=0;i<(qtdC-1);i++){
        if(circulo[i+1].pontos>maior){
            maior=circulo[i+1].pontos;
            k=i+1;
        }
    }

    cout<<endl<<"O circulo com mais pontos: "<<endl;
    cout<<"Circulo "<<k+1<<endl;
    cout<<"Centro: ("<<circulo[k].centroX<<","<<circulo[k].centroY<<")"<<endl;
    cout<<"Possui: "<<maior<<" pontos"<<endl;

    //delete
    delete[]circulo;
    delete[]ponto;

    return 0;
}
