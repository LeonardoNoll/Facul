package pessoas;

import java.util.LinkedList;

import contatos.Telefone;
import documentos.Cpf;

public class Funcionario extends Pessoa{
	private long matricula;
	private double salario;
	private Cpf cpf;
	public Funcionario() {}
	public Funcionario(String nome, LinkedList<Telefone> telefones, 
	      long matricula, double salario, Cpf cpf) {
		super(nome, telefones);
		this.matricula = matricula;
		this.salario = salario;
		this.cpf = cpf;
	}
	public String toString() {
		return matricula + super.toString() + salario +
				(cpf!=null?cpf.toString():"Cpf inválido");
	}
	public long getMatricula() {
		return matricula;
	}
	public void setMatricula(long matricula) {
		this.matricula = matricula;
	}
	public double getSalario() {
		return salario;
	}
	public void setSalario(double salario) {
		this.salario = salario;
	}
	public Cpf getCpf() {
		return cpf;
	}
	public void setCpf(Cpf cpf) {
		this.cpf = cpf;
	}
	
	
	
}
