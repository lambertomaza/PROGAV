package bitsdeunint;

/**
 *
 * @author 2MV3
 * @version 2016.04.14
 */
public class Util {
    /**
     * Mostrar los bits utilizados para representar 
     * el int que se recibe como argumento.
     * @param arg 
     */
    static void mostrarbits(int arg)
    {
        for(int i=Integer.SIZE-1;i>=0;i--){
            System.out.printf("%d",(arg>>i)&1);
        }
        System.out.println();
    }
    static void mostrarbits(float arg)
    {
        int partInt=(int)arg;
        System.out.println(partInt);
        //De acuerdo con IEEE-754, un float de 32 bits se divide en 
        //1 bit de signo, 8 bits de exponente + excess, y 23 bits de mantisa.
        //para 32 bits excess=127.  
        for(int i=Float.SIZE-1;i>=0;i--){
            //System.out.printf("%f",(arg>>i)&1);
        }
        System.out.println();
    }
}//end class Util
