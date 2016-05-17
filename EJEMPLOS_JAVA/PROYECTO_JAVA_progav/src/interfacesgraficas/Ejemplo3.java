/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfacesgraficas;
import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
/**
 *
 * @author Toshiba
 */
public class Ejemplo3 {
    Frame F;
    Button B1,B2,B3,B4;
    TextArea TA;
    public Ejemplo3(){
        F=new Frame("Ejemplo 3");
        F.setLayout(new BorderLayout());
        B1=new Button("NORTE");
        B2=new Button("ESTE");
        B3=new Button("OESTE");
        B4=new Button("SUR");
        TA=new TextArea("CENTRO");
        F.add(B1,BorderLayout.NORTH);
        F.add(B2,BorderLayout.EAST);
        F.add(B3, BorderLayout.WEST);
        F.add(B4, BorderLayout.SOUTH);
        F.add(TA, BorderLayout.CENTER);
        F.addWindowListener(new WindowAdapter() {
          public void windowClosing(WindowEvent we){
              F.dispose();
              System.exit(0);
          }  
        });
        
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }
    public static void main(String[] args) {
        new Ejemplo3().F.setVisible(true);
    }
}//end class Ejemplo3
















