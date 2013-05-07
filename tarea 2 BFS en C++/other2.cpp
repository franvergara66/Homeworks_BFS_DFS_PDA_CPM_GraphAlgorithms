#include <iostream>

#include <map>

#include <math.h>

#include <queue>

#include <vector>

/**

 * Autores :           Juan Pablo Sandoval

 *                     Rodrigo Claros

 *

 * Fecha Publicacion:  9-nov-2009

 *

**/



using namespace std;


typedef priority_queue<int,vector<int>,greater<int> > cola;

int N,T,x;

/*

* Un Arbol n-ario,

* el metodo "solve" sirve para optener la cantidad minima que nescesita(recursivo)

*/

class Arbol{

public:

int nombre;

map<int,Arbol*> hijos;


        Arbol(int n):nombre(n){}


int solve(){

if(hijos.empty()){

return 1;

}else{

int hn=(int)ceil(hijos.size()*T/100.0);

cola xy;

for(map<int,Arbol*>::iterator it = hijos.begin();it!=hijos.end();it++)

xy.push(it->second->solve());

int acum=0;

for(int i=0;i<hn;i++){

   acum+=xy.top();

           xy.pop();

}

       hijos.clear();

return acum;

}

}

};

int main(){

    cin>>N>>T;

    Arbol **as = new Arbol*[100001];

    for(int c = 0; c<100001; c++)as[c]=new Arbol(c);


    while(N){

    // se llena la estructura en forma linea haciendo uso de un arreglo

        for(int i=1;i<=N;i++){

            cin>>x;

            as[x]->hijos[i] = as[i];

        }

    // una ves llenado se llama al metodo "solve" del jefe de jefes

        cout<<as[0]->solve()<<endl;

    cin>>N>>T;

    }
return 0;
}
