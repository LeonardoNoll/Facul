package pessoas;

import java.util.LinkedList;

import contatos.Telefone;

public class Pessoa implements Comparable<Pessoa>{
	private String nome;
	private LinkedList<Telefone> telefones;
	
	@Override
	public int compareTo(Pessoa objPessoa) {
		return getNome().compareTo(objPessoa.getNome());
	}
	
	public Pessoa() {}
	public Pessoa(String nome, LinkedList<Telefone> telefones) {
		this.nome = nome;
		this.telefones = telefones;
	}
	public String getNome() {		return nome;	}
	public void setNome(String nome) {		this.nome = nome;	}
	public LinkedList<Telefone> getTelefones() {		return telefones;	}
	public void setTelefones(LinkedList<Telefone> telefones) {		this.telefones = telefones;	}
	@Override
	public String toString() {
		String aux = "";
		for (Telefone telefone : telefones) {
			if(telefone != null) 
				aux += telefone.toString()+"\n";
		}
		if(aux.isEmpty()) aux = "Sem telefones cadastrados";
		return "Nome: " + nome + "\n" + aux;
	}

}
