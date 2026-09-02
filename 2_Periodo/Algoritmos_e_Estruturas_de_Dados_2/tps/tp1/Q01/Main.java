import java.util.Scanner;

public class Main {

    private static boolean ehFim(String texto) {
        return (texto.length() == 3 && texto.charAt(0) == 'F' && texto.charAt(1) == 'I' && texto.charAt(2) == 'M');
    } // end ehFim

    private static String ciframento(String texto) {
        String resp = "";
        for (int i = 0; i < texto.length(); i++) {
                
                resp = resp + (char) (texto.charAt(i) + 3);
            }
    return resp;
    } // end ciframento

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String linha = "";

        linha = sc.nextLine();
        while (!ehFim(linha)) {
            System.out.println (ciframento(linha));
            linha = sc.nextLine();
        } // end while

        sc.close();
    } // end main

} // end class