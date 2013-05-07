#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <stdio.h>

using namespace std;


class edge{
	public:
	int recognize;
	vector<char> input;
	vector<char> top;
	vector<string> accion;
	edge(){
		recognize=0;
		input.clear();
		top.clear();
		accion.clear();
	}
};

class node{
	public:
	int id;
	int recognize;
	int visited;
	node(){
		id=0;
		recognize=0;
		visited=0;
	}
};



int main(){
    freopen("tarea5.in","r",stdin);
    freopen("tarea5.out","w",stdout);
    int testCases;
    int i,j, k, n, l,m, it, b;
    int numberStates, numberTransitions,numberFinalStates, initialState;
    int origin, destination, lambda, charFlag, counter;
    int numberStrings, stringSize, currentState, flagAccepted;


    char characterRead,stackTop, bottom='Z';


    string api, actionStack;

    stack<char> automatonStack;

    edge **adjacencyMatrix;

    cin>>testCases;

    for(i=0;i<testCases;i++){
        cout<<"Caso #"<<i+1<<":"<<endl;
        cin>>numberStates>>numberTransitions>>initialState>>numberFinalStates;

        vector<node> nodos;
        adjacencyMatrix=new edge*[numberStates];
        int arrayFinalStates [numberFinalStates];

        for(j=0;j<numberStates;j++)
            adjacencyMatrix[j]=new edge[numberStates];

        for(j=0;j<numberStates;j++){
            node *ptr;
            ptr=new node();
            ptr->id=j;
            nodos.push_back(*ptr);
            delete(ptr);
        }

        for(j=0;j<numberFinalStates;j++)
            cin>>arrayFinalStates[j];

        for(j=0;j<numberFinalStates;j++){
            counter=0;
            while(counter<numberStates){
                if(arrayFinalStates[j]==nodos.at(counter).id && nodos.at(counter).visited==0){
                    nodos.at(counter).recognize=1;
                    nodos.at(counter).visited=1;
                    counter++;
                    break;
                }
                counter++;
            }
        }


        for(j=0;j<numberTransitions;j++){
            cin>>origin>>destination>>characterRead>>stackTop>>actionStack;
                adjacencyMatrix[origin][destination].input.push_back(characterRead);
                adjacencyMatrix[origin][destination].top.push_back(stackTop);
                adjacencyMatrix[origin][destination].accion.push_back(actionStack);
        }

        cin >>numberStrings;

        for(j=0;j<numberStrings;j++){
            stack<char> stringStack;///stringStack::stack determines if all elements of inputString were processed
                                    ///stringStack.empty() means that all elements were processed...
            string inputString;
            cin>>inputString;
            cout << inputString<< " ";

		for(k=0;k<inputString.size();k++){
            stringStack.push(inputString[j]);
		}

		automatonStack.push(bottom);
        currentState=0;
        flagAccepted=0;

            for(k=0;k<=inputString.size();k++){
                charFlag =0;///charFlag::indicates whether processed or not a character in the input String

                lambda=0;///lambda::Indicates whether I processed all the input string and if it comes
                         ///from a lambda transition

                for(l=0;l<(numberStates-1);l++){      ///the loop goes until numberStates-1 so that only reaches the final currentState
                    if(charFlag==1)						     ///matrix and not continues to travel to the last row
                        break;

                    for(m=0;m<numberStates;m++){
                        if(charFlag==1 || l!=currentState)///charFlag == 1 implies that an element of inputString process and therefore should be skipped to
                            break;			       ///next character in the inputString

                        if(l==currentState || k==inputString.size()){
                            if(k==inputString.size() && charFlag==0)
                                lambda=1;/// If the string is processed completely and I
                                         ///have not changed anything enters here

                            for(it=0;it<adjacencyMatrix[l][m].input.size();it++){

                                if((adjacencyMatrix[l][m].input.at(it)==inputString[k] || (adjacencyMatrix[l][m].input.at(it)=='L' && l==currentState))&& adjacencyMatrix[l][m].top.at(it)==automatonStack.top()){

                                    if(adjacencyMatrix[l][m].input.at(it)==inputString[k] && adjacencyMatrix[l][m].top.at(it)==automatonStack.top()){

                                        if(adjacencyMatrix[l][m].accion.at(it).size()>1){

                                            api=adjacencyMatrix[l][m].accion.at(it);

                                            for(b=adjacencyMatrix[l][m].accion.at(it).size()-2;b>=0;b--){
                                                automatonStack.push(api[b]);
                                                currentState=m;
                                                charFlag=1;
                                            }

                                            stringStack.pop();
                                            break;
                                        }


                                        if(adjacencyMatrix[l][m].accion.at(it).size()==1 && adjacencyMatrix[l][m].accion.at(it)!="L"){
                                            currentState=m;
                                            charFlag=1;
                                            stringStack.pop();
                                            break;
                                        }

                                        if(adjacencyMatrix[l][m].accion.at(it).size()==1 && adjacencyMatrix[l][m].accion.at(it)=="L"){
                                            automatonStack.pop();
                                            stringStack.pop();
                                            currentState=m;
                                            charFlag=1;
                                            break;
                                        }
								}

								if(adjacencyMatrix[l][m].input.at(it)=='L' && adjacencyMatrix[l][m].top.at(it)==automatonStack.top() && !stringStack.empty()){
									charFlag=1;
									break;
								}

								if(adjacencyMatrix[l][m].input.at(it)=='L' && adjacencyMatrix[l][m].top.at(it)==automatonStack.top() && lambda==1 && stringStack.empty()){
									currentState=m;
									charFlag=1;
									break;
								}
							}
						}
					}
				}
			}
		}

		for(k=0;k<numberStates;k++){
			if(nodos.at(k).recognize==1){
				if(currentState == nodos.at(k).id){
					cout<<"Aceptada"<<endl;
					flagAccepted=1;
					break;
				}
			}
		}
            if(flagAccepted==0)
                cout<<"Rechazada"<<endl;
	}
    cout<<"\n";
    }
return 0;
}

