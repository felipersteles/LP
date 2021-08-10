
#include<iostream>
#include <cmath>
using namespace std;

float distancia(float Ax, float Ay,
                float Bx, float By){

    float distancia;

    distancia =sqrt(pow((Bx-Ax),2)+pow((By-Ay),2));

    return distancia;
}

float media(float coordenada1, float coordenada2){

    float media;

    media = (coordenada1+coordenada2)/2;

    return media;
}
