import java.util.Scanner;

public class Main {
  private static boolean ehFim(String texto) {
    return (texto.length() == 3 && texto.charAt(0) == 'F' && texto.charAt(1) == 'I' && texto.charAt(2) == 'M');
  } // end ehFim

  public static boolean senha (String senha){
    boolean resp1 = false,resp2 = false,resp3 = false,resp4 = false;
    for (int i = 0; i < senha.length();i++){
      char c = senha.charAt(i);
      boolean ehMaiuscula = (c >= 'A' && c <= 'Z');
      boolean ehMinuscula = (c >= 'a' && c <= 'z');
      boolean ehDigito    = (c >= '0' && c <= '9');
      if (ehMaiuscula) {
        resp1 = true;
      } else if (ehMinuscula) {
        resp2 = true;
      } else if (ehDigito) {
        resp3 = true;
      } else {
        resp4 = true;   // não é letra nem dígito
      } // end if
    } // end for
    return (senha.length() >= 8 && resp1 && resp2 && resp3 && resp4);
  } // end senha

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    String senha = "";
    senha = sc.nextLine();
    while (!ehFim(senha)){
      if (senha(senha)){
      System.out.println ("SIM");
    } else {
      System.out.println ("NAO");
      }
      senha = sc.nextLine();
    }
    sc.close();
  }
}