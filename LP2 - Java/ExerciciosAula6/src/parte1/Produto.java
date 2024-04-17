package parte1;

public class Produto<C, V> {
   private C codigo;
   private V valor;
}

class Teste{
	public static void main(String[] args) {
		Produto<Integer, String> produto1 = new Produto();
		
		
		Produto<String, String> produto2 = new Produto();
	}
}