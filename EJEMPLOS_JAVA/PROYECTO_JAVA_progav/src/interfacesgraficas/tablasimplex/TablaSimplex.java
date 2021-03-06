/*



 */
package interfacesgraficas.tablasimplex;

import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.swing.JPanel;
import javax.swing.JFrame;
import java.awt.*;
import java.awt.event.*;

public class TablaSimplex {
    JFrame JF;
    Object datos[][];
    String cabeceras[]; 
    public TablaSimplex() {
        //super("");
        JF = new JFrame("Metodo Simplex");
        //array bidimencional de objetos con los datos de la tabla
        Object[][] data = {
            {"1", "2", "3", "4", "5", "6", "7"},
            {"8", "9", "10", "11", "12", "13", "14"},
            {"15", "16", "17", "18", "19", "20", "21"},
            {"22", "23", "24", "25", "26", "27", "28"},
            {"29", "30", "31", "1", "2", "3", "4"},};

        //array de String's con los tÃŒtulos de las columnas
        String[] columnNames = {"domingo", "lunes", "martes",
            "miercoles", "jueves", "viernes", "sabado"};
        //se crea la Tabla
        final JTable table = new JTable(data, columnNames);
        table.setPreferredScrollableViewportSize(new Dimension(500, 70));

        //Creamos un JscrollPane y le agregamos la JTable
        JScrollPane scrollPane = new JScrollPane(table);
        //Agregamos el JScrollPane al contenedor
        JF.getContentPane().add(scrollPane, BorderLayout.CENTER);
        //manejamos la salida
        JF.addWindowListener(new WindowAdapter() {
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        JF.setSize(400,140);
        JF.setLocationRelativeTo(null);
    }//end TablaSimplex()

    public TablaSimplex(Object dat[][],String cab[]) {
        datos=dat;
        cabeceras=cab;
        JF = new JFrame("Metodo Simplex");
        //se crea la Tabla
        final JTable table = new JTable(datos, cabeceras);
        table.setPreferredScrollableViewportSize(new Dimension(500, 70));

        //Creamos un JscrollPane y le agregamos la JTable
        JScrollPane scrollPane = new JScrollPane(table);
        //Agregamos el JScrollPane al contenedor
        JF.getContentPane().add(scrollPane, BorderLayout.CENTER);
        //manejamos la salida
        JF.addWindowListener(new WindowAdapter() {//3/5
            public void windowClosing(WindowEvent e) {
                System.exit(0);
            }
        });
        JF.setSize(400,140);
        JF.setLocationRelativeTo(null);//Centrar ventana
        JF.setVisible(true);
    }

    public static void main(String[] args) {
        //TablaSimplex frame = new TablaSimplex();
        ////frame.JF.pack();
        //frame.JF.setVisible(true);
        Object[][] data = {
            {"1/2", "2/3", "3/8", "4/5", "5/7", "5/6", "7/10"},
            {"8", "9", "10", "11", "12", "13", "14"},
            {"15", "16", "17", "18", "19", "20", "21"},
            {"22", "23", "24", "25", "26", "27", "28"},
            {"29", "30", "31", "1", "2", "3", "4"},};
        String[] columnNames = {"", "x1", "x2","x3", "S1", "S2", "S3"};
        TablaSimplex TS=new TablaSimplex(data,columnNames);
    }//end main()
}//end class TablaSimplex
