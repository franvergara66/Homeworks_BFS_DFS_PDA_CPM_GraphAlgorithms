package tarea7;

import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Locale;
import java.util.StringTokenizer;
import javax.swing.JFileChooser;

class product {

    String productName;
    int productWeight;
    int productValue;
}

public class EjemploJFrameConFondo extends JFrameConFondo {

    static double p = 0, p1 = 0, p2=0;
    static boolean detallado = false;
    static String test [];
    static int count;
    static int counterAssert=0;
    static int suma;
    static int max, pos;
    static String combinations [][];
    static String permutations [];

    
    public static void combinaciones(int n, int r, product[] arreglo, BufferedWriter a, String[][] combinations1) throws IOException {
        //Genera las combinaciones utilizando
        //el algoritmo de Kenneth H. Rosen

        int i, j, ci = 0;
        int v[] = new int[n];              
        pos=0;
        count=0;      
        
        for (i = 0; i < n; i++) {
            v[i] = i;
        } //Inicia v[]

        for (i = 0; i < r; i++) {
            a.write (arreglo[v[i]].productName + " ");
            combinations [ci][i]= arreglo[v[i]].productName;
            suma = suma + arreglo[v[i]].productValue;
            pos=count;        
            
        }
            
            System.out.println (max+" "+pos+" ");
            
            max =suma;           
            suma =0;
            a.write("\n");
            
        ci++;
        while (ci < p1) {
            i = r - 1;
            while (v[i] == n - r + i) {
                i--;
            }
            v[i] = v[i] + 1;
            for (j = i + 1; j < r; j++) {
                v[j] = v[i] + j - i;
            }
            
            for (i = 0; i < r; i++) {
                a.write (arreglo[v[i]].productName + " ");                
                combinations [ci][i]= arreglo[v[i]].productName;
                suma = suma + arreglo[v[i]].productValue;
                if (suma>max){                    
                    count++; max =suma;pos = count; 
                }   
            }
            System.out.println (max+" "+pos+" ");
                
            suma =0;
            a.write("\n");
            ci++;
        }
    }

static void permutaciones(int n, String arreglo[], String word) {
//Genera las permutaciones utilizando
//el algoritmo de Kenneth H. Rosen
        counterAssert=0;
	int i,j,temp;
	int v[]=new int[n];
	boolean Repite;

	for(i=0;i<n;i++){
		v[i]=i;
	} //Inicia v[]

	Repite=true;
	while(Repite) {
		for(int f=0;f<v.length;f++) {
                      System.out.print(arreglo[v[f]]+" ");
                      if ((f==0)&&(word.equals(arreglo[v[f]]) )){
                         counterAssert++;
                      }                         
		}
               
                System.out.println ();
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


public static double factorialCombina(int n,int m) {
     //Multiplica desde n hasta m-1. n>=m
    double f=1;
    while(n>m) {
        f=f*n;
        n--;
    }
return f;
}

static double factorialPermuta(int n) {
double f=1;
while(n>1) {
f=f*n;
n--;
}
return f;
}

    public static void leer_archivo(String fileName) {

        int testCases;
        int numberProducts;
        int capacityBag;
        String preference;
        

        try {
            File archivo = new File(fileName);
            FileReader fr = new FileReader(archivo);
            BufferedReader br = new BufferedReader(fr);
            String linea;
            String sFichero = "tarea7.out";
            File fichero = new File(sFichero);

            linea = br.readLine();
            testCases = Integer.parseInt(linea);
            //System.out.println(testCases);

            for (int i = 1; i <= testCases; i++) {
                
                String entrada = br.readLine();
                StringTokenizer token = new StringTokenizer(entrada);
                numberProducts = Integer.parseInt(token.nextToken());
                capacityBag = Integer.parseInt(token.nextToken());

                product[] itemBag = new product[numberProducts];
                for (int x = 0; x < numberProducts; x++) {
                    itemBag[x] = new product();
                }
                
                String aux1;
                int aux2, aux3;

                for (int j = 0; j < numberProducts; j++) {
                    entrada = br.readLine();
                    token = new StringTokenizer(entrada);
                    aux1 = token.nextToken();
                    aux2 = Integer.parseInt(token.nextToken());
                    aux3 = Integer.parseInt(token.nextToken());
                    itemBag[j].productName = aux1;
                    itemBag[j].productWeight = aux2;
                    itemBag[j].productValue = aux3;
                }
                
                String arreglo[]= new String[numberProducts];
               // for (int j = 0; j < numberProducts; j++) {
                //    System.out.println(itemBag[j].productName + " " + itemBag[j].productWeight + " " + itemBag[j].productValue);
                //}

                preference = br.readLine();
                            
             if((numberProducts-capacityBag)>capacityBag) {
                p1=factorialCombina(numberProducts,numberProducts-capacityBag)/factorialCombina(capacityBag,1);
            }else{
                p1=factorialCombina (numberProducts,capacityBag)/factorialCombina(numberProducts-capacityBag,1);
            }
             
             int a = (int) p1;
             combinations = new String [a][capacityBag];
             permutations = new String [capacityBag];
                try (BufferedWriter bw = new BufferedWriter(new FileWriter(sFichero, true))) {
                    bw.write("Caso #" + i + ":");
                    bw.write("\n");
                    bw.write("Parte A:");
                    bw.write("\n");
                    combinaciones(numberProducts,capacityBag,itemBag ,bw,combinations); 
                    
                    System.arraycopy(combinations [pos], 0, permutations, 0, capacityBag);                   
                    
                  
                    p2=factorialPermuta(capacityBag);
                    permutaciones(capacityBag,permutations, preference);  
                    
                    double probability;
                    
                    if (counterAssert==0){probability=0;}
                    else{
                    probability= counterAssert/p2;}
                    DecimalFormatSymbols otherSymbols = new DecimalFormatSymbols(Locale.GERMAN);
                    otherSymbols.setDecimalSeparator('.');  
                    DecimalFormat df = new DecimalFormat("0.000", otherSymbols);                                             
                    bw.write("Parte B: ");
                    bw.write(df.format(probability)); 
                    bw.write("\n");
                    bw.write("\n"); 
                } //End try to file in the output file
                
            } //end loop of Test Cases
        } catch (IOException | NumberFormatException e) {
        } 
} ///end Class

    public EjemploJFrameConFondo() {
        initComponents();
        setImagen("recursos/mochila2.jpg");
    }

    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        cajaTexto = new javax.swing.JTextField();
        jButton1 = new javax.swing.JButton();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);


        jLabel1.setText("Ruta: ");

        jButton1.setText("Examinar...");
        jButton1.addActionListener(new java.awt.event.ActionListener() {

            @Override
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGroup(layout.createSequentialGroup().addContainerGap().addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addComponent(cajaTexto).addGroup(layout.createSequentialGroup().addComponent(jLabel1).addGap(0, 0, Short.MAX_VALUE)).addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup().addGap(0, 217, Short.MAX_VALUE).addComponent(jButton1))).addContainerGap()));
        layout.setVerticalGroup(
                layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING).addGroup(layout.createSequentialGroup().addContainerGap(100, Short.MAX_VALUE).addComponent(jLabel1).addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED).addComponent(cajaTexto, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE).addGap(29, 29, 29).addComponent(jButton1).addGap(34, 34, 34)));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
        JFileChooser filechooser = new JFileChooser();
        int option = filechooser.showOpenDialog(this);
        if (option == JFileChooser.APPROVE_OPTION) {
            cajaTexto.setText(filechooser.getSelectedFile().getPath());
            String route = filechooser.getSelectedFile().getPath();
            leer_archivo(route);

        }
        // TODO add your handling code here:
    }//GEN-LAST:event_jButton1ActionPerformed
    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField cajaTexto;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    // End of variables declaration//GEN-END:variables
}