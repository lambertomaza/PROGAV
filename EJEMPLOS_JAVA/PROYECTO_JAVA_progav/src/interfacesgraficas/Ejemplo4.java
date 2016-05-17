package interfacesgraficas;

import java.awt.BorderLayout;
import java.awt.Frame;
import java.awt.Menu;
import java.awt.MenuBar;
import java.awt.MenuItem;
import java.awt.TextArea;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.awt.event.ActionEvent;//1/5 MI1,MI2,MI3
import java.awt.event.ActionListener;

/**
 *
 * @author Toshiba
 */
public class Ejemplo4 implements ActionListener{//2/5  MI1,MI2,MI3
    Frame F;
    MenuBar MB;
    Menu M;
    MenuItem MI1,MI2,MI3;
    TextArea TA;
    Calendario C;
    public Ejemplo4(Calendario C){
        this.C=C;
        F=new Frame("Ejemplo 4");
        MB=new MenuBar();
        F.setMenuBar(MB);
        M=new Menu("Calendario");
        MB.add(M);
        MI1=new MenuItem("Num de año");
        MI2=new MenuItem("Mes");
        MI3=new MenuItem("Dia");
        M.add(MI1);M.addSeparator();
        M.add(MI2);M.addSeparator();
        M.add(MI3);//M.addSeparator();
        MI1.addActionListener(this);//3/5  MI1,MI2,MI3
        MI2.addActionListener(this);
        MI3.addActionListener(this);
        F.setLayout(new BorderLayout());
        TA=new TextArea("Hello World!");
        F.add(TA, BorderLayout.CENTER);
        
        F.addWindowListener(new WindowAdapter() {//3/5 Frame
            @Override
            public void windowClosing(WindowEvent we){
              F.dispose();
              System.exit(0);
            }
        });
        F.setSize(400, 300);
        F.setLocationRelativeTo(null);
        F.setVisible(true);
    }//end Ejemplo4()
    public static void main(String[] args) {
        new Ejemplo4(new Calendario());
    }//end main()

    @Override
    public void actionPerformed(ActionEvent ae) {//4/5  MI1,MI2,MI3
        String s=ae.getActionCommand(),aux;
        if(s.equals(MI1.getLabel())){//5/5  MI1,MI2,MI3
            aux=TA.getText();
            aux+="\n"+C.anyo;
            TA.setText(aux);
        }
        if(s.equals("Mes")){
            aux=TA.getText();
            aux+="\n"+C.MesName+"\n";
            TA.setText(aux);
            TA.append(C.toString());
        }
        if(s.equals("Dia")){
            aux=TA.getText();
            aux+="\n"+C.DiaName;
            TA.setText(aux);
        }
    }
    
}//end class Ejemplo4
