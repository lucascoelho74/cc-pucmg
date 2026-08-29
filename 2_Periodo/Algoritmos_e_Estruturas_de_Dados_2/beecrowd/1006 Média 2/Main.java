import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        double A = 0.0, B = 0.0, C = 0.0, MEDIA = 0.0;
        A = entrada.nextDouble ();
        B = entrada.nextDouble ();
        C = entrada.nextDouble ();
        MEDIA = ((A * 2.0) + (B * 3.0) + (C * 5.0))/10.0;
        System.out.println ("MEDIA =" + MEDIA);
    } // end main
} // end class Main
