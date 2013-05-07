#include<iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

typedef struct {
    int origin;
    int destination;
    char charRead;
    char actionTape;
    char movementTape;
}TuringMachine;


int main (){
	int testCases, numberStates, numberTransitions, initialState,numberFinals, current;
	int currentState, index;
	bool flagReject=false;
	int finalStates;
    int stateOrigin,stateDestination;
    char transitionCharacter,charTape,movementTape;
    int numberInputs;
    string inputString;
    vector <char> tapeMachine;
    int k;
    bool encontre;
    bool flagStop;
    int cont;

    set<int>::iterator it2;
    set <int> final;
    vector <TuringMachine> machineT;
    freopen("tarea6.in", "r", stdin);
    freopen("tarea6.out", "w", stdout);

    cin >> testCases;

    for(int k=0; k<testCases; k++){
        cout << "Caso #"<<k+1<<":"<< endl;

        cin >>numberStates>> numberTransitions>> initialState>> numberFinals;

        vector<int>::iterator it;

        for (int j=0;j<numberFinals;j++){
            cin>>finalStates;
            final.insert(finalStates);
        }
        for(int i=0; i<numberTransitions; i++){

            cin>> stateOrigin>>stateDestination>>transitionCharacter>>charTape>>movementTape;
            TuringMachine values= {stateOrigin,stateDestination,transitionCharacter,charTape,movementTape};
            machineT.push_back(values);
        }

        cin >> numberInputs;

        for (int i=0; i<numberInputs; i++){
            bool lol=true;
            bool existe = false;
            int j;

            cin>>inputString;
            flagStop = true;
            index=1000;
            currentState=initialState;

             for(int k=0; k<2000; k++){ ///fill the tape with #'s
                tapeMachine.push_back('#');
            }

            for(int i=0; i<inputString.size(); i++){ ///put the input string in the tape
                tapeMachine[1000+i]=inputString[i];
            }

            cout << inputString<<" ";

            while ((flagStop)&&(lol)){

                for (j=0; j<machineT.size(); j++){
                    encontre=false;

                    if( (machineT.at(j).origin==currentState)&&(machineT.at(j).charRead==tapeMachine[index]) ){
                        encontre=true;
                        currentState=machineT.at(j).destination;
                        tapeMachine[index]=machineT.at(j).actionTape;

                        if (machineT.at(j).movementTape=='R'){
                            index++;
                            }
                        if (machineT.at(j).movementTape=='L'){
                            index--;
                            }

                        if (machineT.at(j).movementTape=='S'){
                            index=index;
                            flagStop= false;
                        }
                    break;

                    }//end if

                 }//end for

                 if (encontre==false){
                    lol = false;
                    flagReject=false;
                 }

             }//end while

            for (it2 =final.begin(); it2!=final.end(); it2++){
                if (*it2==currentState){
                    flagReject=true;
                    }
            }

            if ((flagReject)&&(lol==true)){
                cout<<"Aceptada";
                }else{
                    cout<<"Rechazada";
                    }

            cout <<endl;
        }///end inputs


        cout <<endl;
        machineT.clear();
    } ///end test Cases

return 0;
}
