
#include <iostream>
using namespace std;

char printM(char **matriz, int ordem){

    int i,j;

    cout<<endl;
    for(i=0;i<ordem;i++){
        for(j=0;j<ordem;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
}

char desenhaM(char **matriz, int ordem){

    int i,j;

    for(i=0; i<ordem; i++){
        for(j=0;j<ordem;j++)
        cin>>matriz[i][j];
    }
}



