package ejemplointerfaces;

/**
 *
 * @author Toshiba
 */
public class TestInterface {

    OpGaussJordan OGJordan;

    public TestInterface(OpGaussJordan Impl) {
        OGJordan = Impl;
    }
    public static void main(String[] args) {
        float numf=2.5f;
        float fp[]={1f,3.4f,2.6f,7.3f};
        float fila[]={numf,5.3f,4.2f,0};
        OpGaussJordan OGJ=new Implementacion2();
        TestInterface TI=new TestInterface(OGJ);
        TestInterface.printArrF(fila);
        TI.OGJordan.opdfilagj(numf, fp, fila);
        TestInterface.printArrF(fila);
    }
    public static void printArrF(float fa[]){
        for(int i=0;i<fa.length;i++)
            System.out.print(fa[i]+" ");
        System.out.println();
    }
}//end class TestInterface







