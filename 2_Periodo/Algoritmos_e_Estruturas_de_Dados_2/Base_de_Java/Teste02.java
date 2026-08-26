import java.util.*;

class Cliente {
  public int idade;
  public String nome;
  public Cliente (int idade, String nome){
    this.idade = idade;
    this.nome = nome;
  }
  public void set (int idade) throws Exception{
    if (idade >= 0){ 
      this.idade = idade;
    }
    else {
      throw new Exception("Valor invalido"); // Tratamento de erro com throws pelo terminal
    }
  }
}
class Teste02 {
  public static void main (String [] args) throws Exception{
    Scanner sc = new Scanner (System.in);
    Cliente c1 = new Cliente (13, "Joao");
    Cliente c2 = c1;
    System.out.println ("Idade: "+ c2.idade + " Nome: " + c2.nome );

    c2.set (-1);
    System.out.println ("Idade: "+ c2.idade + " Nome: " + c2.nome );
    // Fechar objeto
    sc.close();
  }
}
