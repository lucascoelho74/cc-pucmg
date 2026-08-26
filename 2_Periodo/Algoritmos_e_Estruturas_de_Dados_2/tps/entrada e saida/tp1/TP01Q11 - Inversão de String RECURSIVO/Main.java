import java.util.Scanner;

public class Main {

  private static boolean ehFim (String text){
    return (text.length() == 3 && text.charAt(0) == 'F' && text.charAt(1) == 'I' && text.charAt(2) == 'M');
  }
  private static String inverte (String text){
    int i = 0;
    int size = text.length();
    char aux = ' ';

    while (i < text.length()){
      aux = text.charAt(i);
     (char) text.charAt(i) = (char)text.charAt(size);
      i++;
      size--;
      aux = 0;
    }
    return text;
  }
  public static void main (String[] args){
    Scanner sc = new Scanner (System.in);
    String text = "";
    text = sc.nextLine();
    while (!ehFim(text)){
      System.out.println(inverte (text));
      text = sc.nextLine();
    }
    sc.close();
  }
}