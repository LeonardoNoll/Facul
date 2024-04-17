package parte1;

import java.util.*;

import javax.swing.JOptionPane;

import contatos.Telefone;
import documentos.Cpf;
import pessoas.Funcionario;

public class Teste1 {
	public static void main(String[] args) {
		//conjunto ordenado de funcionarios
		TreeSet<Funcionario> funcionarios = new TreeSet<>();
		
		//cadastrar dois funcionarios
		//cria o objeto f1 passando os valores dos atributos
		LinkedList<Telefone>  fones1 = new LinkedList<>();
		fones1.add(new Telefone(51, 88999911));
		Funcionario f1 = new Funcionario("Wilson", fones1,
				1234, 2000.0, new Cpf(123, 23));
		funcionarios.add(f1);
	
		//cria o objeto f2 passando os valores dos atributos
		LinkedList<Telefone>  fones2 = new LinkedList<>();
		fones2.add(new Telefone(51, 66554433));
		fones2.add(new Telefone(51, 22668899));
		funcionarios.add(new Funcionario("Alexandre", fones2,
				4567, 3000.0, new Cpf(156, 88)));
		//listar todos os funcionarios
		for (Funcionario func : funcionarios) {
			JOptionPane.showMessageDialog(null, func.toString());
		}
		
	}
}
