import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner entrada = new Scanner (System.in);
         int codeA = 0, codeB = 0;
         int qtdeA = 0, qtdeB = 0;
         double priceA = 0.0, priceB = 0.0;
         double productA = 0.0, productB = 0.0;
         double result = 0.0;
         codeA  = codeA.nextInt();
         qtdeA  = qtdeA.nextInt();
         priceA = priceA.nextDouble();
         productA = qtdeA * priceA;
         System.out.println ("");
         codeB  = codeB.nextInt();
         qtdeB  = qtdeB.nextInt();
         priceB = priceB.nextDouble();
         productB = qtdeB * priceB;
         result = productA + productB;
         System.out.println ("VALOR A PAGAR: R$ " + result);
    } // end main
} // end class Main
