import java.util.*;

class Teste03 {
  public static int recursividade (int x){
    int soma = 0;
    if (x > 0){
      soma = (x%10) + recursividade (x/10);
    } 
    if (x < 0){
      soma = recursividade (-x);
    }
    return soma;
  }
  public static void main (String[] args){
    Scanner sc = new Scanner (System.in);
    int x = sc.nextInt();
    System.out.println ("> Teste");
    System.out.println (recursividade (x));
    System.out.println ("< Teste");
    sc.close ();
  } 
}