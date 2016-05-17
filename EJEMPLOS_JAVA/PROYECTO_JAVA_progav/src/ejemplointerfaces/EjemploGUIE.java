package ejemplointerfaces;

/**
 *
 * @author Toshiba
 */
import java.awt.*;
import java.awt.event.*;//1/5
public class EjemploGUIE implements ActionListener{//2/5
    Frame F;
    Button B1,B2,B3,B4;
  public EjemploGUIE(){
      F=new Frame("Ejemplo 1");
      B1=new Button("Boton 1");
      B2=new Button("Boton 2");
      F.setLayout(new FlowLayout());
      F.add(B1);
      F.add(B2);
      F.add((B3=new Button("Boton 3")));
      B4=new Button("Boton 4");
      F.add(B4);
      B1.addActionListener(this);//3/5
      F.addWindowListener(new WindowAdapter() {
          public void windowClosing(WindowEvent we){
              F.dispose();
              System.exit(0);
          }  
        });
      F.setSize(300, 200);
      F.setLocationRelativeTo(null);
      F.setVisible(true);
  }
    @Override
    public void actionPerformed(ActionEvent ae) {//4/5
        String s=ae.getActionCommand();
        //System.out.println(s);
        if(s.equals("Boton 1")){//5/5
          //  System.out.println("HOLA");
            //F.dispose();
            //System.exit(0);
            B2.setLabel("Otra cad");
        }
    }
    public static void main(String[] args) {
        new EjemploGUIE();
    }
}
