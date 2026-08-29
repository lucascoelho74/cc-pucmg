import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);
        double R = 0.0, A = 0.0;
        R = entrada.nextDouble();
        // Area = π * r * r
        A = 3.14159 * R * R;
        System.out.println("A = " + A);
    } // end main
} // end class Main
