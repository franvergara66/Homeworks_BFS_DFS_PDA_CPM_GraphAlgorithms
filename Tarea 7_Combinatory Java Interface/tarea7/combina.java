//Genera combinaciones de n,r
//Para compilar:
// javac combina.java
//Para ejecutar:
// java combina <n> <r> [-d]

public class combina {
	static double p=0,p1=0;
	static boolean detallado=false;
	static String arreglo[]={"control","juego","DVD", "correa", "brujula"};     
	
	
	static void combinaciones(int n,int r) {
		//Genera las combinaciones utilizando
		//el algoritmo de Kenneth H. Rosen

		int i,j,ci=0;
		int v[]=new int[n];

		for(i=0;i<n;i++){v[i]=i;} //Inicia v[]

			for(i=0;i<r;i++) {
				System.out.format(arreglo [v[i]]+" ");
			}
			System.out.println("");
			ci++;
			while(ci<p1) {
				i = r - 1;
				while (v[i] == n - r + i) {
					i--;
				}
				v[i] = v[i] + 1;
				for (j = i + 1; j < r; j++) {
					v[j] = v[i] + j - i;
				}
				for(i=0;i<r;i++) {
					System.out.format(arreglo [v[i]]+" ");
				}
				System.out.println("");
				ci++;
			}
	}

	static double factorial(int n,int m) {
	//Multiplica desde n hasta m-1. n>=m
		double f=1;
		while(n>m) {
		f=f*n;	
		n--;
		}
	return f;
	}

public static void main(String args[]) {
int n=0,r=0;
String d="-d";

boolean error=false;

	if (args.length>3) {
		error=true;
	}

	if (args.length==3) {
	if (args[2].compareTo(d)==0) {
		detallado=true;
	}else{
		error=true;
	}
	}
	if (!error) {
	try { //Captura la excepción para comprobar que n es un entero
	n=Integer.valueOf(args[0]).intValue();
	} catch(Exception e) {
	n=0;
	}

try { //Captura la excepción para comprobar que r es un entero
r=Integer.valueOf(args[1]).intValue();
} catch(Exception e) {
r=0;
}

if (n<1 || r<1 || n<r) {
error=true;
}
}

if (!error) {
//p1=factorial(n)/factorial(r)/factorial(n-r)
//Lo hace de esta forma para evitar errores de redondeo
if((n-r)>r) {
p1=factorial(n,n-r)/factorial(r,1);
} else {
p1=factorial(n,r)/factorial(n-r,1);
}
combinaciones(n,r);
} else {
	System.out.println("Uso: java combina <n> <r> [-d]");
	System.out.println("n,r son enteros mayores que 0");
	System.out.println("n>=r");
System.out.println("-d muestra el progreso sobre el total.");
}
}
}
