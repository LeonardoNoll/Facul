package questoes;

public class Questao2 {
	public static void main(String[] args) {
		String vetor[] = {"abc", "alfabeto", null};
		for (String str : vetor) {
			try {				
				System.out.println(str.charAt(0));
			} catch(NullPointerException e) {
				System.out.println("Erro: String nula");
			}
		}
	}
}
