package associacao4b.testes;

import associacao4b.Aluno;
import associacao4b.Residencia;

public class TestaAssociacao4b {

  public static void main(String[] args) {
    // TODO Auto-generated method stub
    Aluno a;
    Residencia r1, r2;
    a = new Aluno("Alex", 0, 0);
    r1 = new Residencia("Rua Abc", 100);
    //Metodo protected, não tem acesso. Está correto.
    //r1.setAluno(a);
    r2 = new Residencia("Rua Xyz", 200);
    a.adicionaResidencia(r1);
    a.adicionaResidencia(r2);
    
    
    System.out.println(a);
    System.out.println(r1 + r1.getAluno().getNome());
    System.out.println(r2 + r2.getAluno().getNome());

  }

}
