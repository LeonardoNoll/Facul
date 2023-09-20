package src.testes;

import src.dominio.Aluno;

public class TestaAluno {

  public static void main(String[] args) {
    //Declara dois objetos Aluno.
    Aluno a1, a2;

    //Instancia aluno somente com nome.
    a1 = new Aluno("Joao");
    //a1.setNome("Alex");
    //Atribui notas.
    a1.setNota1(8);
    a1.setNota2(9);

    //N�o � possivel acessar atributo private.
    //a1.nome = "Alex";
    //a1.nota1 = -8;
    //a1.nota2 = 9;

    System.out.println("--- Aluno 1 ---");
    System.out.println("Nome: " + a1.getNome());
    System.out.println("Nota1: " + a1.getNota1());
    System.out.println("Nota2: " + a1.getNota2());
    System.out.println("Media: " + a1.media());

    //Instancia Aluno com nome e notas.
    a2 = new Aluno("Joao", 7, 8);

    System.out.println("--- Aluno 2 ---");
    System.out.println("Nome: " + a2.getNome());
    System.out.println("Nota1: " + a2.getNota1());
    System.out.println("Nota2: " + a2.getNota2());
    System.out.println("Media: " + a2.media());

  }

}//TestaAluno.