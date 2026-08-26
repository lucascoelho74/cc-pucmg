import java.util.*;

/*
    javac --version                           // Mostrar Versao do Java
    javac NOMEDOARQUIVO.java                  // Compilar o Java
    java  NOMEDOARQUIVO                       // Executar o Java
    java  NOMEDOARQUIVO < pub.in              // Executa as entradas do pub.in
    diff  NOMEDOARQUIVO1 NOMEDOARQUIVO2       // Compara 2 arquivos
*/

class Teste01 {
    public static void main (String [] args){
        // Entrada
        Scanner sc = new Scanner (System.in);
        int x = 0;
        String word = "";
        char c = ' ';
        int size = 0;
        int [] array = new int [4]; // Em java so da pra criar array dinamico 
        
        // Saida
        System.out.println ("Hello World");  // Em java println => Em C printf + \n
        System.out.printf ("Hello World\n"); // Em java printf => Em C printf
        System.out.println ("");
        // boolean < char < int < double < String (utilizar)
        // byte < short < long < float            (nao utilizar)

        x       = sc.nextInt ();        // sc.nextTIPO
        word    = sc.next ();           // sc.next para string
        c       = word.charAt (0);      // pega o caracter no index x
        size    = word.length();        // string nao tem \0
        System.out.println ("");
        // Saida
        System.out.println ("Int: " + x);
        System.out.println ("String: " + word);
        System.out.println ("Char: " + c);
        System.out.println ("Size: " + size);
        System.out.println ("");

        System.out.printf ("Int: %d\n" , x);
        System.out.printf ("String: %s\n" , word);
        System.out.printf ("Char: %c\n" , c);
        System.out.printf ("Size: %d\n" , size);
        System.out.println ("");
        System.out.println ("Size: " + size + " Int: " + x);     // CERTO
        // System.out.println ("Size: " + size + x + " Int: ");  // ERRADO

        System.out.println ("" + x + x);   // concatena -> xx
        System.out.println ("" +(x + x));  // soma -> x + x
        System.out.println ("");
        
        for (int i = 0; i < 4 ; i++)
        {
            array [i] = sc.nextInt ();
        }

        for (int j = 0; j < 4 ; j++)
        {
            System.out.print ("array[j]: " + array[j]);
            System.out.printf ("\t");
        }
        // Fechar objeto
        sc.close();
    }
}