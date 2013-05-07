
package tarea2;

import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;
import javax.swing.JFileChooser;


public class EjemploJFrameConFondo extends JFrameConFondo {
    
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
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(sFichero, true))) {
            bw.write("Caso " + Casos + ": Duracion Total " + casitas[n-1][0] );
            bw.write("\n");
            bw.write(cam);
            bw.write(mac);
            bw.write("\n");
            bw.write("\n");
        }
		
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
    
    
    public static void leer_archivo(String fileName){
        try{
       File archivo=new File(fileName);
       FileReader fr= new FileReader(archivo);
       BufferedReader br= new BufferedReader(fr);
       String linea;


       linea=br.readLine();
       c=Integer.parseInt(linea);
       for(int i=0;i<c;i++){
           CrearCaso(br, i+1);
       }
        }catch(IOException | NumberFormatException e){
        }
    }
    
   

    public EjemploJFrameConFondo() {
        initComponents();
        setImagen("recursos/satelite.jpg");
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
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton1ActionPerformed(evt);
            }
        });

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(cajaTexto)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jLabel1)
                        .addGap(0, 0, Short.MAX_VALUE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addGap(0, 217, Short.MAX_VALUE)
                        .addComponent(jButton1)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(100, Short.MAX_VALUE)
                .addComponent(jLabel1)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(cajaTexto, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(29, 29, 29)
                .addComponent(jButton1)
                .addGap(34, 34, 34))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents
    
    private void jButton1ActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton1ActionPerformed
         JFileChooser filechooser = new JFileChooser();
         int option = filechooser.showOpenDialog (this);
         if (option==JFileChooser.APPROVE_OPTION){
            cajaTexto.setText(filechooser.getSelectedFile().getPath());
         String route = filechooser.getSelectedFile().getPath();
         leer_archivo (route); 
         
        }
        // TODO add your handling code here:
    }//GEN-LAST:event_jButton1ActionPerformed
  



    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextField cajaTexto;
    private javax.swing.JButton jButton1;
    private javax.swing.JLabel jLabel1;
    // End of variables declaration//GEN-END:variables

}
