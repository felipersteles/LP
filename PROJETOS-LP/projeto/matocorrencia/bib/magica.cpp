
#include <iostream>
using namespace std;

int magica(int **matriz,int ordem){

    int i,j;

    //aloc mat contadora
    int**cont;
    cont=new int*[ordem];
    for(i=1;i<=ordem;i++){
        cont[i]=new int[ordem];
    }

    //aloc mat contadora2
    int**cont2;
    cont2=new int*[ordem];
    for(i=1;i<=ordem;i++){
        cont2[i]=new int[ordem];
    }

    //desenha cont
    for(i=1;i<=ordem;i++){
        for(j=1;j<=ordem;j++){
            cont[i][j]=0;
        }
    }

    //desenha cont2
    for(i=1;i<=ordem;i++){
        for(j=1;j<=ordem;j++){
            cont2[i][j]=0;
        }
    }

    int p,q;

    //faz a magica
    for(i=0;i<ordem;i++){
        for(j=0;j<(ordem-1);j++){
            p=matriz[i][j];
            q=matriz[i][j+1];
            cont[p][q]++;
            cont2[q][p]++;
        }
    }

    //imprime cont
    cout<<"zero graus: "<<endl;
    for(i=1;i<=ordem;i++){
        for(j=1;j<=ordem;j++){
            cout<<cont[i][j]<<" ";
        }
        cout<<endl;
    }

    //imprime cont2
    cout<<endl<<"cento e oitenta graus: "<<endl;
    for(i=1;i<=ordem;i++){
        for(j=1;j<=ordem;j++){
            cout<<cont2[i][j]<<" ";
        }
        cout<<endl;
    }


    for(i=1;i<=ordem;i++){
        delete[]cont[i];
    }
    delete[]cont;

    for(i=1;i<=ordem;i++){
        delete[]cont2[i];
    }
    delete[]cont2;
}
