import java.util.Scanner;
import java.util.Random;

public class Main {
  private static boolean ehFim (String text){
    return (text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M');
  }
  private static Random gerador = new Random();
  private static String random (String texto) {
        char letra1 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        char letra2 = (char) ('a' + (Math.abs(gerador.nextInt()) % 26));
        String resp = "";
        int i;

        for (i = 0; i < texto.length(); i++) {
            if (texto.charAt(i) == letra1) {
                resp = resp + letra2;
            } else {
                resp = resp + texto.charAt(i);
            } // end if
        } // end for

        return resp;
    } // end random
  public static void main (String[] args){
    Scanner sc = new Scanner (System.in);
    String text = "";
    gerador.setSeed(4);
    text = sc.nextLine();
    while (!ehFim(text)){
      System.out.println(random(text));
      text = sc.nextLine();
    }
    sc.close();
  } // end main
} //end class