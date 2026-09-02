import java.util.Scanner;

public class Main {
    private static boolean ehFim(String texto) {
        return (texto.length() == 3 && texto.charAt(0) == 'F' &&
                texto.charAt(1) == 'I' && texto.charAt(2) == 'M');
    } // end ehFim

    public static String inverte(String texto) {
        int inicio = 0;
        while (inicio < texto.length() && texto.charAt(inicio) == ' ') {
            inicio++;
        } // end while
        return inverte(texto, inicio);
    } // end inverte

    public static String inverte(String texto, int i) {
        String resp;
        if (i == texto.length()) {
            resp = "";
        } else {
            resp = inverte(texto, i + 1) + texto.charAt(i);
        } // end if
        return resp;
    } // end inverte

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String texto = sc.nextLine();

        while (!ehFim(texto)) {
            System.out.println(inverte(texto));
            texto = sc.nextLine();
        } // end while

        sc.close();
    } // end main

} // end class Main