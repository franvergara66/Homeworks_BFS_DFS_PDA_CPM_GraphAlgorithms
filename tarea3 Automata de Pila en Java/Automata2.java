/**Automata a Pila que acepta el lenguaje L={a^n b^m c^2(n+m), con n>=0, m>=0}
  *Asignatura: AUTOMATAS Y LENGUAJES FORMALES
  *Por: Miguel Angel Sanchez Mora **/

import java.util.*;
import javax.swing.*;
public class Automata2{
	public static void main( String args[] ){
	int j=1;  
	while(j <= 5){  //iterar 5 veces.  Para salir pulse "Cancelar"
	Stack pila=new Stack();  //crear pila

	boolean valor = true;
	Character Zo = new Character('Z');
	Character simboloA = new Character('a');
	Character simboloB = new Character('b');
	Character simboloC = new Character('c');
	int estado = 0;

	pila.push(Zo);    //poner tope de pila a Zo

	String salida="Automata que acepta el siguiente lenguaje:" +
			  "\n(a^n)(b^m)(c^2(n+m)), con n>=0, m>=0" +
			  "\n\nIntroduzca alguna cadena.";
      
	JTextArea areaSalida=new JTextArea();
        areaSalida.setText(salida);
      
        String tuCadena = JOptionPane.showInputDialog(null,areaSalida,"AUTOMATA A PILA",JOptionPane.INFORMATION_MESSAGE);
        int i=-1;
      
	try{  valor = tuCadena.matches("[a-c]*");  
	if(valor){ //si tuCadena consta de solo caracteres entre a y c entonces	
	char tuCadenaDeI;
	for(i=0; i<tuCadena.length(); i++){
		tuCadenaDeI=tuCadena.charAt(i);
		switch(estado){
			case 0:
				if(tuCadenaDeI=='a')
				pila.push(simboloA);
	  			else
				if(tuCadenaDeI=='b'){
				estado=1;
				pila.push(simboloB);}
				else
				if((tuCadenaDeI == 'c') && (pila.peek() == simboloA))
				estado=3;
				else 
				i=tuCadena.length();  //sin estado
				break;	

			case 1:
				if(tuCadenaDeI=='b')
				pila.push(simboloB);
				else
				if((tuCadenaDeI=='c') && (pila.peek() == simboloB ))
				estado=3;
				else 
				i=tuCadena.length();       //sin estado
				break;
	
			case 2:
				if(tuCadenaDeI=='c')
			 	estado=3;
				else 
				i=tuCadena.length();       //sin estado 
				break;

			case 3:
				if(tuCadenaDeI=='c'){
				estado=2;
				pila.pop();}            //excepcion de pila vacia
				else 
				i=tuCadena.length();       //sin estado
				break;
			default:;
				
	      }//fin switch
	   }//fin for
	}//fin if
	else ;
	}//fin try
	catch (EmptyStackException excepcionPilaVacia )  //excepcion de pila vacia
      {
		excepcionPilaVacia.printStackTrace();
      }
	
      if(i==tuCadena.length()+1){
	salida = "El orden de concatenacion es incorrecto.";
	salida += "\n\nLa cadena No se acepta.";}

	else
	if((estado==2) && (pila.peek() == Zo)){   //si estado=2 y tope de pila es Zo entonces
	pila.pop();				 //aceptacion por pila vacia
	salida=" \nLa cadena " + tuCadena + " Si se acepta.";
	salida +="\n\nLa pila esta vacia?  " +  pila.empty();}
	
	else
	if(i==0) {		//cadena vacia
	pila.pop();
	salida = "La cadena vacia Si se acepta.";
	salida +="\n\nLa pila esta vacia?  " +  pila.empty();}
	
	else 
	if( !valor ){
	salida = "El alfabeto utilizado es distinto de {a,b,c}";
	salida += "\n\nLa cadena No se acepta.";}
	
	else {
	salida = "El orden de concatenacion es correcto.";
	salida += "\nEl alfabeto utilizado es correcto.";
	salida += "\n\nLa cadena No se acepta.";}
	
	areaSalida.setText(salida);
	JOptionPane.showMessageDialog(null,areaSalida,"AUTOMATA A PILA",JOptionPane.INFORMATION_MESSAGE);	
	
   	j++;
	}  // fin del while.
   }  // fin del metodo main.
}  // fin de la clase Automata2.

