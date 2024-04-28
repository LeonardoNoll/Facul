package questoes;

import contatos.Telefone;

public class Questao1 {
	 public static void main(String[] args) {
	 Telefone telefones[] = new Telefone[5];
	 telefones[0] = new Telefone();
	 telefones[2] = new Telefone(51, 55667788);
	 for (int i = 0; i < telefones.length; i++) {
		 //Corrigido com try/catch
		 try {			 
			 System.out.println(telefones[i].toString());
		 } catch(NullPointerException e) {
			 System.out.println("telefones["+i+"] é nulo");
		 }
	 	}
	 }
}
