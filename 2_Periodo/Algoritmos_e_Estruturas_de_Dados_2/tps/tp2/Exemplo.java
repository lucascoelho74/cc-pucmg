import java.util.Scanner;
import java.io.File;

class Veiculo{
	public int id;
	public String marca;
	public String modelo;
	public int ano;
	public String categoria;
	public String[] combustivel;
	public int cilindros;
	public double cilindrada;
	public String transmissao;
	public String tracao;
	public double consumoCidade;
	public double consumoEstrada;
	public double co2;
	public boolean turbo;

	public Veiculo(int id, String marca, String modelo, int ano, String categoria, String[] combustivel, int cilindros, double cilindrada, String transmissao, String tracao, double consumoCidade, double consumoEstrada, double co2, boolean turbo){
		this.id = id;
		this.marca = marca;
		this.modelo = modelo;
		this.ano = ano;
		this.categoria = categoria;
		this.combustivel = combustive
	}

	public static Veiculo parseVeiculo(String s){
		String[] atributos = s.split(",");
		int id = Integer.parseInt(atributos[0]);
		String marca = atributos[1];
		return new Veiculo(id, marca);
	}

	public String format(){
		return "[" + id + " ## " + marca + " ## " + modelo + " ## " + ano + " ## " + categoria " ## " + combustivel + " ## " + cilindros + " ## " + cilindrada + " ## " + transmissao + " ## " + tracao + " ## " + consumoCidade + " ## " + consumoEstrada + " ## " + co2 + " ## " + turbo + " ## " + dataRegistro "]";
	}
}

class LeitorCsv{
	public static Veiculo[] ler(String veiculo) throws Exception {
		File f = new File("veiculos.csv");
		Scanner sc = new Scanner(f);
		String cabecalho = sc.nextLine();
		Veiculo[] veiculos = new Veiculo[500];	
		int cont = 0;
		while(sc.hasNextLine()){
			String linha = sc.nextLine();
			veiculos[cont] = Veiculo.parseVeiculo(linha);
			cont++;
		}

		sc.close();
		return veiculos;
	}
}

class Exemplo{

	public static void main(String[] args) throws Exception {
		// Veiculo[] veiculos = LeitorCsv.ler("/tmp/veiculos.csv"); -> versao do Verde
		Veiculo[] veiculos = LeitorCsv.ler("veiculos.csv");
		for(int i=0; i<veiculos.length; i++){
			System.out.println(veiculos[i].format());
		}
	}
}
