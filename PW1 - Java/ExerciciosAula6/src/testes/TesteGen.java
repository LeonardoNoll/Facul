package testes;

import java.util.LinkedList;

import contatos.Telefone;
import documentos.Cpf;
import pessoas.Pessoa;

public class TesteGen {
	public static void main(String[] args) {
		LinkedList telefones = new LinkedList();
		telefones.add(new Cpf());
		telefones.add(new Telefone());
		telefones.add(new Pessoa());
		
		for (Object obj : telefones) {
			if(obj instanceof Pessoa)
				Pessoa p = (Pessoa)obj;
				p.getNome();
		}
		
		LinkedList<Telefone> telefones2 = new LinkedList<>();
		//telefones2.add(new Cpf());
		telefones2.add(new Telefone());
		//telefones2.add(new Pessoa());
	}
}





