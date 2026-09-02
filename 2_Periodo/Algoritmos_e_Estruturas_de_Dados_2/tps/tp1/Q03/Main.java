import java.util.Scanner;

public class Main {

    public static boolean ehFim(String text) {
        return (text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M');
    }

    public static boolean vogal(String text) {
        boolean resp = true;
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) != 'a' && text.charAt(i) != 'e' && text.charAt(i) != 'i' && text.charAt(i) != 'o'
                    && text.charAt(i) != 'u') {
                resp = false;
            } // end if
        } // end for
        return resp;
    } // end vogal

    public static boolean consoante(String text) {
        boolean resp = true;
        for (int i = 0; i < text.length(); i++) {
            if (!(text.charAt(i) >= 'a' && text.charAt(i) <= 'z')) {
                resp = false; // nao e nem letra minuscula
            } else if (text.charAt(i) == 'a' || text.charAt(i) == 'e' || text.charAt(i) == 'i' || text.charAt(i) == 'o'
                    || text.charAt(i) == 'u') {
                resp = false; // e letra, mas e vogal
            } // end if
        } // end for
        return resp;
    } // end consoante

    public static boolean numeroInteiro(String text) {
        boolean resp = true;
        for (int i = 0; i < text.length(); i++) {
            if (!(text.charAt(i) >= '0' && text.charAt(i) <= '9')) {
                resp = false;
            } // end if
        } // end for
        return resp;
    } // end numeroInteiro

    public static boolean numeroReal(String text) {
        boolean resp = true;
        int separadores = 0;
        for (int i = 0; i < text.length(); i++) {
            if (text.charAt(i) >= '0' && text.charAt(i) <= '9') {
                // digito, tudo certo
            } else if (text.charAt(i) == '.' || text.charAt(i) == ',') {
                separadores++;
            } else {
                resp = false;
            } // end if
        } // end for

        if (separadores > 1) {
            resp = false;
        } // end if

        return resp;
    } // end numeroReal

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String text = "";
        text = sc.nextLine();
        while (!ehFim(text)) {
            if (vogal(text)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            if (consoante(text)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            if (numeroInteiro(text)) {
                System.out.print("SIM ");
            } else {
                System.out.print("NAO ");
            }
            if (numeroReal(text)) {
                System.out.println("SIM");
            } else {
                System.out.println("NAO");
            }
            text = sc.nextLine();
        }
        sc.close();
    }
}