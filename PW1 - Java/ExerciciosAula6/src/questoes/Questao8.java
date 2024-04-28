package questoes;

public class Questao8 {
	 public static void main(String[] args) {
		 System.out.println("Início do main");
		 metodo1();
		 System.out.println("Fim do main");
	 }
 
	 static void metodo1() {
		 System.out.println("Início do metodo1");
		 metodo2();
		 System.out.println("Fim do metodo1");
	 }
 
	 static void metodo2() {
		 System.out.println("Início do metodo2");
		 int[] array = new int[10];
		 try {			 
			 for (int i = 0; i <= 15; i++) {
				 array[i] = i;
				 System.out.println(i);
			 }
		 } catch(ArrayIndexOutOfBoundsException e) {
			 System.out.println("Erro: tentando acessar posição fora do vetor");
		 }
		 System.out.println("Fim do metodo2");
	 }
 }