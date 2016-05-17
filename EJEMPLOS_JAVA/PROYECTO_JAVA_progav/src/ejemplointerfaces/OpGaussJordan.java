package ejemplointerfaces;

/**
 *
 * @author Toshiba
 */
public interface OpGaussJordan {
    /**
     * Operacion de fila Gauss Jordan
     * @param f factor
     * @param filpiv fila pivote
     * @param fil fila de trabajo que se actualiza con la operacion Gauss Jordan
     * @pre los arreglos filpiv y fil deben ser del mismo tamanio, i.e.,
     * filpiv.length==fil.length debe ser true
     */
    public void opdfilagj(float f,float filpiv[],float fil[]);
}
