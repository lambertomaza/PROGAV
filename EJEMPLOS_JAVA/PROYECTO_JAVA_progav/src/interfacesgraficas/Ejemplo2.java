/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package interfacesgraficas;

import java.awt.Button;
import java.awt.Frame;
import java.awt.GridLayout;
import java.awt.Label;

/**
 *
 * @author Toshiba
 */
public class Ejemplo2 {
    Frame F;
    Button B1,B2,B3,B4;
    Label L1;
      public Ejemplo2(String s){
          F=new Frame(s);
          F.setLayout(new GridLayout(2,2));
          B1=new Button("B1");
          F.add(B1);
          F.add(B2=new Button("B2"));
          L1=new Label("MENSAJE");
          F.add(L1);
          B3=new Button("B3");
          F.add(B3);
          F.setSize(300, 200);
          F.setLocationRelativeTo(null);
      }
      public static void main(String[] args) {
        Ejemplo2 E2=new Ejemplo2("Ejemplo 2");
        E2.F.setVisible(true);
    }
}//end class Ejemplo2
