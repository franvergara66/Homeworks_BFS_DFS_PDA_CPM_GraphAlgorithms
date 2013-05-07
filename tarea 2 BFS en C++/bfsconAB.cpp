/// /////////////////////////////////////////
///Francisco Vergara seccion: Elizer Correa
///C.I 17.389.551
///Matemáticas Discretas iii tarea º1
/// /////////////////////////////////////////

#ifndef ArbolNarioa
#define ArbolNarioa
#include<iostream>
#include<queue>
#define MAX 100
#include <vector>
#include <stdlib.h>

using namespace std;

class NodosArbolNario{
	public:
	int datos;
	NodosArbolNario *padre;
	NodosArbolNario *hijo;
	NodosArbolNario *hermanoD;
	NodosArbolNario *hermanoI;
	//Constructores
	NodosArbolNario(){
		datos=0;
		padre=NULL;
		hijo=NULL;
		hermanoD=NULL;
		hermanoI=NULL;
	}
	NodosArbolNario(int valor){
		datos=valor;
		padre=NULL;
		hijo=NULL;
		hermanoD=NULL;
		hermanoI=NULL;
	}
	NodosArbolNario(int valor,int valor2){
		datos=valor;
		padre=NULL;
		hijo=NULL;
		hermanoD=NULL;
		hermanoI=NULL;
	}
};
class ArbolNario{
	public:

	NodosArbolNario *ElementoB;
	bool enco;
	NodosArbolNario *Raiz;
	//Constructor
	ArbolNario(){
		ElementoB=NULL;
		Raiz=NULL;
		enco=false;
	}
	//Retorna si esta vacio el Arbol N-ario
	int VacioArbol(){
		return Raiz==NULL;
	}
	//Inserta un elemento en el arbol con el sig formato
	//Padre,Tipo,Valor,Peso
	//donde Tipo es 1:insercion como hermano
	//				0:insercion como hijo
	void Insertar(int,int,int);
	//Imprime el arbol N-Ario por referencias del hermano
	void ImprimirRefHermano();
	//Imprime el arbol N-Ario por referencias del padre
	void ImprimirRefPadre();
	//Retorna el nodo donde esta el elemento Nota:El elemento esta en ElementoB
	void EncontrarElem(int);

	private:

	//Imprime el arbol N-Ario por referencias del padre (aux)
	void ImprimirRefPadreaux(NodosArbolNario *raizaux);
	//Imprime el arbol N-Ario por referencias del hermano (aux)
	void ImprimirRefHermanoaux(NodosArbolNario *raizaux);
	//Retorna el nodo donde esta el papa
	void EncontrarElemaux(NodosArbolNario *raizaux,int);
}
;
//------------------------------------------------------
//Metodos para Arbol N-ario
//------------------------------------------------------
//HijooHermano=1 lo inserta como hermano
//HijooHermano=0 lo inserta como hijo
//Inserta al inicio un elemento
void ArbolNario::Insertar(int Padre, int HijooHermano, int Valor){
	if(VacioArbol())
		Raiz=new NodosArbolNario (Valor);
	else{
		EncontrarElem(Padre);
		if(ElementoB==NULL)
			cout<<"No se encontro el elemento\n";
		else{
			NodosArbolNario *p=ElementoB;
			if(HijooHermano==1){
				if(p->hermanoD!=NULL){
					NodosArbolNario *temp=p->hermanoD;
					p->hermanoD=new NodosArbolNario (Valor);
					p->hermanoD->hermanoI=p;
					p->hermanoD->hermanoD=temp;
					temp->hermanoI=p->hermanoD;
					temp=NULL;
					delete temp;
				}
				else{
					p->hermanoD=new NodosArbolNario (Valor);
					p->hermanoD->hermanoI=p;
				}
				if(ElementoB->padre!=NULL){
					p->hermanoD->padre=ElementoB->padre;
				}
			}
			else{
				if(p->hijo!=NULL){
					p=p->hijo;
					while(p->hermanoD!=NULL){
						p=p->hermanoD;
					}
					p->hermanoD=new NodosArbolNario (Valor);
					p->hermanoD->padre=ElementoB;
					p->hermanoD->hermanoI=p;
				}
				else{
					p->hijo=new NodosArbolNario (Valor);
					p->hijo->padre=ElementoB;
				}
			}
			p=NULL;
			delete p;
		}
		ElementoB=NULL;
		delete ElementoB;
	}
}

//Retorna el nodo donde esta el elemento (aux)
void ArbolNario::EncontrarElemaux(NodosArbolNario *raizaux,int elem){
	if(raizaux==NULL){
		return;
	}
	else{
		if(enco==false){
			if(elem==raizaux->datos){
				ElementoB=raizaux;
				enco=true;
				return;
			}
			else{
				EncontrarElemaux(raizaux->hermanoD,elem);
				EncontrarElemaux(raizaux->hijo,elem);
			}
		}
		else{
			return;
		}
	}
}

//Retorna el nodo donde esta el elemento
void ArbolNario::EncontrarElem(int elem){
	enco=false;
	ElementoB=NULL;
	EncontrarElemaux(Raiz,elem);
	enco=false;
}

//Imprime el arbol por referencia del hermano
void ArbolNario::ImprimirRefHermano(){
	if(VacioArbol())
			cout<<"No hay elementos\n";
		else{
			cout<<"Arbol por Ref Hermano es: ";
			ImprimirRefHermanoaux(Raiz);
			cout<<"\n";
	}
}

//Imprime el arbol por referencia del hermano (aux)
void ArbolNario::ImprimirRefHermanoaux(NodosArbolNario *raizaux){
	if(raizaux==NULL){
		return;
	}
	else{
		if(raizaux->hermanoD!=NULL || raizaux->hermanoI!=NULL)
			cout<<raizaux->datos<<" ";
		ImprimirRefHermanoaux(raizaux->hermanoD);
		ImprimirRefHermanoaux(raizaux->hijo);
	}
}

//Imprime el arbol por referencia del padre
void ArbolNario::ImprimirRefPadre(){
	if(VacioArbol())
		cout<<"No hay elementos\n";
	else{
		cout<<"Arbol por Ref Padre es: ";
		ImprimirRefPadreaux(Raiz);
		cout<<"\n";
	}
}
//Imprime el arbol por referencia del padre (aux)
void ArbolNario::ImprimirRefPadreaux(NodosArbolNario *raizaux){
	if(raizaux==NULL){
		return;
	}
	else{
		ImprimirRefPadreaux(raizaux->hermanoD);
		if(raizaux->hijo!=NULL){
			cout<<raizaux->datos<<" ";
		}
		ImprimirRefPadreaux(raizaux->hijo);
	}
}
queue<int> myQueue;
int visit[MAX];
int grafo_BFS[MAX][MAX];
int arbolBFS [ MAX ];
int V, it2=0;


void bfs(int );

void preorder(int);



int main(int argc, char *argv []){

    /// //////////////////////////////////
#ifndef ONLINE_JUDGE
#pragma warning(disable: 4996)
	freopen("input.in", "r", stdin); ///entrada y salida standard se redirige a un archivo
   // freopen("tarea1.out", "w", stdout);
/// //////////////////////////////////
#endif


    int numeroVertices, numeroAristas;

    int origen ,destino, i, j, k, contCasos=1;
    ///numero de casos de prueba
    int casosPrueba, inicial;
     memset(visit, 0, sizeof(visit));
    cin>>casosPrueba;


        for (i=0; i<casosPrueba; i++){

        cout<< "Caso "<<i+1<<":"<<endl;

        cin>>numeroVertices>>numeroAristas;
        V=numeroVertices;

    int nodosVertices [numeroVertices]; ///arreglo para almacenar los nodos
        int ordenamientoSeguir [numeroVertices];



        for (int j=0; j<numeroAristas; j++){
            cin >>origen>>destino;
            grafo_BFS[origen][destino]=1;                        //se llena la matriz ady (u,v) = (v,u)
            grafo_BFS[destino][origen]=1;
        }


        for (int j=0; j<numeroAristas; j++){
        cin >> ordenamientoSeguir[j];
        }

       inicial=ordenamientoSeguir[0];

        /*Algoritmo BFS*/
        cout<< "BFS= ";
            bfs (inicial);
        for (int j=0; j<V; ++j)
            cout <<arbolBFS[j]<<" "; //aca en vez de imprimir directamente se
            //llamaria a preorden ()

        /*Algoritmo DFS*/
        cout <<endl<<endl;


    } //fin casos prueba

return 0;
}
//////////////FIN DEL MAIN ///////////////////
/////////////////////////////////////////////


void bfs(int s) {
     int i, j,it2=0, node;
     memset(visit, 0, sizeof(visit));
     myQueue.push(s);

     while(!myQueue.empty())
     {
          node = myQueue.front();
          myQueue.pop();
          if(visit[node]) continue;
          visit[node] = 1;
          arbolBFS[it2]=node; //aqui en vez de ir almacenando en un arreglo hay que ir
          //insertando una estructura de arbol para luego llamar a una funcion preorden
          it2++;

          for(i=0; i<V; i++){
               if( grafo_BFS[i][node]) myQueue.push(i);
               if( grafo_BFS[node][i]) myQueue.push(i);
               }
     }

}


#endif

