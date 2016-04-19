package holamundo;

/**
 *
 * @author 2MV3
 * @version 2016.04.12
 */
public class Hola {
    public static void main(String[] args) {
        String saludo="Hola Mundo JAVA";
        char c=saludo.charAt(0);
        System.out.println(saludo);
        System.out.println(0+" En el String saludo tenemos "
                + saludo.length()+" caracteres");
        int A[]={2,0,1,6,0,4,1,2};
        //boolean b=estaincluido(-1, A);
        //boolean b0=estaincluido(-1, A);
        Hola H=new Hola();
        boolean b=H.estaincluido(-1, A);
        if(b){
            System.out.println("El entero si esta incluido en el "
                    + "arreglo");
        }else{
            System.out.println("El entero no esta incluido en el "
                    + "arreglo");
        }
    }
    boolean estaincluido(int a,int arr[]){
        for(int i=0;i<arr.length;i++)
        {
            if(a==arr[i])
                return true;
        }
        return false;
    }
}//end class Hola
