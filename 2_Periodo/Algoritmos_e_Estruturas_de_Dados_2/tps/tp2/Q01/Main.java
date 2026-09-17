import java.util.Scanner;
import java.util.Locale;
import java.io.File;

// javac Main.java
// java Main < Q01/pub.in > meu.out
// diff meu.out Q01/pub.out

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
	public String dataRegistro;

	public Veiculo(){
	} // Veiculo()

	public static Veiculo parseVeiculo(String linha){
		String[] campos = linha.split(",");
		Veiculo v = new Veiculo();
		v.id = Integer.parseInt(campos[0]);
		v.marca = campos[1];
		v.modelo = campos[2];
		v.ano = Integer.parseInt(campos[3]);
		v.categoria = campos[4];
		v.combustivel = campos[5].split(";");
		v.cilindros = Integer.parseInt(campos[6]);
		v.cilindrada = Double.parseDouble(campos[7]);
		v.transmissao = campos[8];
		v.tracao = campos[9];
		v.consumoCidade = Double.parseDouble(campos[10]);
		v.consumoEstrada = Double.parseDouble(campos[11]);
		v.co2 = Double.parseDouble(campos[12]);
		v.turbo = Boolean.parseBoolean(campos[13]);
		v.dataRegistro = inverterData(campos[14]);
		return v;
	} // parseVeiculo()

	// converte de AAAA-MM-DD para DD/MM/AAAA
	public static String inverterData(String data){
		String[] partes = data.split("-");
		return partes[2] + "/" + partes[1] + "/" + partes[0];
	} // inverterData()

	public String format(){
		String saida = "[" + id;
		saida += " ## " + marca;
		saida += " ## " + modelo;
		saida += " ## " + ano;
		saida += " ## " + categoria;
		saida += " ## [" + String.join(",", combustivel) + "]";
		saida += " ## " + cilindros;
		saida += " ## " + cilindrada;
		saida += " ## " + transmissao;
		saida += " ## " + tracao;
		saida += " ## " + String.format(Locale.US, "%.2f", consumoCidade);
		saida += " ## " + String.format(Locale.US, "%.2f", consumoEstrada);
		saida += " ## " + co2;
		saida += " ## " + turbo;
		saida += " ## " + dataRegistro;
		saida += "]";
		return saida;
	} // format()
} // class Veiculo

class LeitorCsv{
	public static int quantidade; // numero de veiculos efetivamente lidos

	public static Veiculo[] ler(String caminhoArquivo) throws Exception {
		File arquivo = new File(caminhoArquivo);
		Scanner sc = new Scanner(arquivo);
		sc.nextLine(); // descarta o cabecalho
		Veiculo[] veiculos = new Veiculo[1000];
		int cont = 0;
		while(sc.hasNextLine()){
			String linha = sc.nextLine().trim();
			if(linha.length() > 0){
				veiculos[cont] = Veiculo.parseVeiculo(linha);
				cont++;
			} // if
		} // while
		sc.close();
		quantidade = cont;
		return veiculos;
	} // ler()
} // class LeitorCsv

class Main{

	// busca sequencial pelo id; devolve -1 se nao achar
	public static int pesquisar(Veiculo[] veiculos, int n, int id){
		for(int i = 0; i < n; i++){
			if(veiculos[i].id == id){
				return i;
			} // if
		} // for
		return -1;
	} // pesquisar()

	public static void main(String[] args) throws Exception {
		Veiculo[] veiculos = LeitorCsv.ler("veiculos.csv");
		int n = LeitorCsv.quantidade;

		Scanner entrada = new Scanner(System.in);
		String linha = entrada.nextLine().trim();
		while(!linha.equals("-1")){
			if(linha.length() > 0){
				int id = Integer.parseInt(linha);
				int pos = pesquisar(veiculos, n, id);
				if(pos != -1){
					System.out.println(veiculos[pos].format());
				} // if
			} // if
			linha = entrada.nextLine().trim();
		} // while
		entrada.close();
	} // main()
} // class Main