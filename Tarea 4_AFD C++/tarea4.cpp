#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main (){

    freopen ("tarea4.in", "r", stdin);
    freopen ("tarea4.out", "w", stdout);

    /// Variables ///////////////
    int testCases, i, j,k, cont=1,finalStates,numberInputs,stateOrigin, stateDestination;
    int numberStates, numberTransitions, initialState;
    int  numberFinals;
    char transitionCharacter ;

    /// contenedores/////////////

    set<int> current;
    set<int> next;
    set<int>::iterator it;
    set <int> final;
    set<int> the_intersection;  // Destination of intersect
    map<pair<int, int>, char>::iterator p;
    string inputString;

    /// map para las transiciones///////////////////

    typedef std::pair<int, int> trigger;
    std::map<trigger, char> transitions;
    map<trigger, char>::iterator r;

    cin>> testCases;
    for (i=0;i< testCases;i++){

        final.clear();
        next.clear();
        current.clear();
        the_intersection.clear();
        transitions.clear();
        cin>>numberStates>>numberTransitions>>initialState>>numberFinals;

        for (j=0;j<numberFinals;j++){
            cin>>finalStates;
            final.insert(finalStates);
        }

        for (j=0; j<numberTransitions;j++){
            cin>> stateOrigin>>stateDestination>>transitionCharacter;
            transitions.insert(make_pair(make_pair(stateOrigin, stateDestination), transitionCharacter));
        }

        cin>>numberInputs;
        current.insert (initialState);
        cout<<"Caso #"<<cont++<<":"<<endl;

        for (j=0; j<numberInputs;j++){
            current.clear();
            current.insert (initialState);
            the_intersection.clear();
            cin>> inputString;
            cout<<inputString<<" ";

            for (k=0; k<inputString.size();k++){
                next.clear();
                for (it = current.begin(); it!=current.end(); it++){
                    for (r =transitions.begin(); r!=transitions.end(); r++){
                        if ( ((*r).first.first == *it) && ( (*r).second == inputString[k] ) ){
                            next.insert((*r).first.second);
                        }
                    }

                }
                current = next;
            }
            std::set_intersection(current.begin(), current.end(), final.begin(), final.end(), std::inserter(the_intersection, the_intersection.end()));

            if (the_intersection.empty()){
                cout<<"Rechazada"<<endl;
            }else {
                cout<<"Aceptada"<<endl;
            }

        }
        cout<<endl;
    }
return 0;
}
