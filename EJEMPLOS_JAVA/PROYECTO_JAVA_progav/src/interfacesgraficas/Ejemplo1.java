package interfacesgraficas;
import java.awt.Frame;
import java.awt.Button;
import java.awt.FlowLayout;
/**
 *
 * @author Toshiba
 */
public class Ejemplo1 {
  Frame F;
  Button B1,B2,B3,B4;
  public Ejemplo1(){
      F=new Frame("Ejemplo 1");
      B1=new Button("Boton 1");
      B2=new Button("Boton 2");
      F.setLayout(new FlowLayout());
      F.add(B1);
      F.add(B2);
      F.add((B3=new Button("Boton 3")));
      B4=new Button("Boton 4");
      F.add(B4);
      F.setSize(300, 200);
      F.setLocationRelativeTo(null);
      F.setVisible(true);
  }
    public static void main(String[] args) {
        new Ejemplo1();
    }
}






