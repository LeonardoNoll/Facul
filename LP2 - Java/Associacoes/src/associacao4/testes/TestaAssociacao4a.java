package associacao4.testes;

import associacao4a.Aluno;
import associacao4a.Residencia;

public class TestaAssociacao4a {

  public static void main(String[] args) {
    // TODO Auto-generated method stub
    Aluno a;
    Residencia r1, r2;
    a = new Aluno("Alex", 0, 0);
    r1 = new Residencia("Rua Abc", 100, a);
    r2 = new Residencia("Rua Xyz", 200, a);
    //Metodo protected, nao tem acesso. Está correto.
    //a.adicionaResidencia(r1);
       
    System.out.println(a);
    System.out.println(r1 + r1.getAluno().getNome());
    System.out.println(r2 + r2.getAluno().getNome());

  }

}
