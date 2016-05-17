package interfacesgraficas;

/**
 *
 * @author Toshiba
 */
public class Calendario {

    int anyo;
    String MesName;
    String DiaName;
    int Mes[][];

    public Calendario() {
        anyo = 2016;
        MesName = "mayo";
        DiaName = "Martes";
        Mes = new int[6][7];
        int cnt = 1;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                Mes[i][j] = cnt;
                if (cnt < 31) {
                    cnt++;
                } else {
                    cnt = 0;
                }
            }
        }
    }//end Calendario

    @Override
    public String toString() {
        String cad = "";
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 7; j++) {
                cad += Mes[i][j] + " ";
            }
            cad+="\n";
        }
        return cad;
    }
}//end class Calendario
