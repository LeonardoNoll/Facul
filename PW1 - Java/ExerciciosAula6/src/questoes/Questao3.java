package questoes;

 public class Questao3{
 public static void main(String args[]) {
 int i = 5571;
 try {	 
	 i = i / 0;
 } catch(ArithmeticException e) {
	 System.out.println("Erro: expressão matemática inválida: "  + e.getMessage());
	//  System.out.println(e.getMessage());
 }
 System.out.println("O resultado " + i);
 }
}
