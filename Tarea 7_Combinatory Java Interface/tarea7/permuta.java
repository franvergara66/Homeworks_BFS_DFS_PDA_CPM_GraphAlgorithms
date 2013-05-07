//Genera permutaciones de n
//Para compilar:
// javac permuta.java
//Para ejecutar:
// java permuta <n> [-d]

public class permuta
{
static double p=0,p2=0;
static boolean detallado=false;
static String arreglo [] ={"control", "juego", "DVD"};

static void permutaciones(int n) {
//Genera las permutaciones utilizando
//el algoritmo de Kenneth H. Rosen

	int i=0,j=0,temp=0;
	int v[]=new int[n];
	boolean Repite=false;

	for(i=0;i<n;i++){
		v[i]=i;
	} //Inicia v[]

	Repite=true;

	while(Repite) {
		for(int f=0;f<v.length;f++) {
			System.out.print(arreglo[v[f]]+" ");
		}
			System.out.println("");


		//Halla el el mayor i tal que v[i]<v[i+1] 
		i=v.length-2;
		while(v[i]>v[i+1] && i>0)i--;

		if((i==0) && (v[i]>v[i+1])){ //Final
			Repite=false;
		}else{
			//Halla el menor v[j] tal que j>i y v[j]>v[i]
			j=v.length-1;
			
			while(v[i]>v[j]) j--;
			//Intercambia v[i] y v[j] 
			temp=v[j];
			v[j]=v[i];
			v[i]=temp;

			//Invierte el orden de los elementos a partir de la posición i+1
			int r=v.length-1;
			int s=i+1;
			while(r>s) {
				temp=v[s];
				v[s]=v[r];
				v[r]=temp;
				r--;
				s++;
			}
		}
	}
}

static double factorial(int n) {
double f=1;
while(n>1) {
f=f*n;
n--;
}
return f;
}

public static void main(String args[]) {
int n=0;
String d="-d";

boolean error=false;

if (args.length>2) {
error=true;
}

if (args.length==2) {
if (args[1].compareTo(d)==0) {
detallado=true;
} else {
error=true;
}
}
if (!error) {
try { //Captura la excepción para comprobar que el argumento es un entero
n=Integer.valueOf(args[0]).intValue();
} catch(Exception e) {
n=0;
}

if (n<1) {
error=true;
}
}

if (!error) {
p2=factorial(n);
permutaciones(n);
} else {
System.out.println("Uso: java permuta <n> [-d]");
System.out.println("n es un entero mayor que 0 .");
System.out.println("-d muestra el progreso sobre el total.");
}
}
}