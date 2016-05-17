package ejemplointerfaces;

/**
 *
 * @author Toshiba
 */
public class Implementacion1 implements OpGaussJordan{

    @Override
    public void opdfilagj(float f, float[] filpiv, float[] fil) {
        for(int i=0;i<fil.length;i++)
            fil[i]=fil[i]-f*filpiv[i];
    }
    
}
