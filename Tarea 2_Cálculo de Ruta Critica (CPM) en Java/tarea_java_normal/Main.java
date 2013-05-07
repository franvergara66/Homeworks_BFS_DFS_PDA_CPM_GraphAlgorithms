import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    public static int c;
    private static String k;
    public static void recorrido(int[][] adj, int Casos) throws IOException{
        int n=adj.length;
        int casitas[][] = new int[n][2];
        int mejorCamino[] = new int [n];

        int temp;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp = adj[i][j];
                if(temp > -1){
                    if(temp + casitas[i][0]>casitas[j][0]){
                        casitas[j][0] = temp + casitas[i][0];
                        mejorCamino[j] = i;
                    }
                }
            }
        }
        //Hacemos el paso hacia atrás.
        for(int y=0;y<n;y++)
        casitas[y][1] = casitas[n-1][0];

        for (int j=n-1;j>=0;j--){
            for(int i=0;i<n;i++){
                temp = adj[i][j];
                 if(temp > -1){
                    casitas[i][1]= Math.min(casitas[j][1] - temp , casitas[i][1]);
                }
            }
        }

        int x=n-1;
        String cam = "";
        while(x>0){
            if(x==n-1)
                cam= mejorCamino[x] + " " + x;
            else
                cam= mejorCamino[x] + " " + x + "\n" + cam;
            adj[mejorCamino[x]][x] = -1;
            x = mejorCamino[x];

        }

        //Calculamos las holguras con nuestra nueva matriz
        String mac="";
        int HT , HL;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp = adj[i][j];
                if (temp > -1){
                    HT = casitas[j][1] - temp - casitas[i][0];
                    HL = casitas[j][0] - temp - casitas[i][0];
                    mac += "\n" + i + " " + j + " " + HT + " " + HL;
                    if (HT>HL)
                        mac += " R";
                }
            }
        }

        String sFichero = "tarea2.out";
        File fichero = new File(sFichero);



	BufferedWriter bw = new BufferedWriter(new FileWriter(sFichero, true));


			  bw.write("Caso " + Casos + ": Duracion Total " + casitas[n-1][0] );
                          bw.write("\n");
                          bw.write(cam);
                          bw.write(mac);
                          bw.write("\n");
                          bw.write("\n");
			  // Hay que cerrar el fichero
			  bw.close();

}

    public static void CrearCaso(BufferedReader br, int numCasos){
         int n,m;
         int[][] Adyacencias;
        try{
        String entrada=br.readLine();
        StringTokenizer token= new StringTokenizer(entrada);

        n=Integer.parseInt(token.nextToken());
        m=Integer.parseInt(token.nextToken());
        Adyacencias= new int[n][n];
        //
        for (int i=0;i<n;i++){
          Arrays.fill(Adyacencias[i], -1);
        }

        int aux1,aux2,aux3;
        for(int i=0;i<m;i++){
            entrada=br.readLine();
            token= new StringTokenizer(entrada);
            aux1=Integer.parseInt(token.nextToken());
            aux2=Integer.parseInt(token.nextToken());
            aux3=Integer.parseInt(token.nextToken());
            Adyacencias[aux1][aux2]=aux3;

        }
        recorrido(Adyacencias, numCasos);


        }catch(Exception e){
        }

    }
	
    public static void leer_archivo(){
        try{
       File archivo=new File("tarea2.in");
       FileReader fr= new FileReader(archivo);
       BufferedReader br= new BufferedReader(fr);
       String linea;
       linea=br.readLine();
       c=Integer.parseInt(linea);
       for(int i=0;i<c;i++){
           CrearCaso(br, i+1);
       }
        }catch(Exception e){
        }
    }
    public static void main(String[] args) {
        leer_archivo();
    }

}
