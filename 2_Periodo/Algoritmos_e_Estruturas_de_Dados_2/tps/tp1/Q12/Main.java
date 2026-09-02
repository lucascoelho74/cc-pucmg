import java.util.Scanner;

public class Main {
  public static int somarDigitos (int num){
    int sum = 0;
    if (num == 0){
      sum = 0;
    } else {
      sum = sum + (num % 10) + somarDigitos (num / 10);
    }
    return sum;
  }
  public static void main (String[] args){
    Scanner sc = new Scanner (System.in);
    int num = 0;
    while (sc.hasNextInt()){
      num = sc.nextInt();
      System.out.println(somarDigitos(num));
    }
    sc.close();
  }
}