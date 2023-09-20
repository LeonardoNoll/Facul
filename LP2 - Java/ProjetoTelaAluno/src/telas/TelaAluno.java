package src.telas;

import java.util.Scanner;

import src.dominio.Aluno;

public class TelaAluno {

  //Atributo que mantem uma referencia ao objeto aluno.
  private Aluno aluno;

  //Atributo para fazer leitura pelo teclado.
  private Scanner scan = new Scanner(System.in);

  //Construtor.
  public TelaAluno(Aluno a) {
    setAluno(a);
  }

  public void setAluno(Aluno a){
    if (a == null) {
      throw new RuntimeException("Erro: aluno null.");
    }
    else {
      this.aluno = a;
    }
  }

  public Aluno getAluno() {
    return aluno;
  }

  public void leNome() {
    System.out.print("Digite o nome: ");
    String s = scan.nextLine();
    aluno.setNome(s);
  }

  public void leNota1() {
    System.out.print("Digite a Nota 1: ");
    Float f = scan.nextFloat();
    scan.nextLine(); //Necess�rio sempre depois que l� um n�mero (para limpar o ENTER do buffer do teclado).
    aluno.setNota1(f);
  }

  public void leNota2() {
    System.out.print("Digite a Nota 2: ");
    Float f = scan.nextFloat();
    scan.nextLine(); //Necess�rio sempre depois que l� um n�mero (para limpar o ENTER do buffer do teclado).
    aluno.setNota2(f);
  }

  public void leNotas() {
    leNota1();
    leNota2();
  }

  public void leTodosDados() {
    leNome();
    leNota1();
    leNota2();
  }

  public void imprime() {
    System.out.println("Nome   : " + aluno.getNome());
    System.out.println("Nota 1 = " + aluno.getNota1());
    System.out.println("Nota 2 = " + aluno.getNota2());
  }

  public void imprimeComMoldura() {
    System.out.println("----------------------------------");
    System.out.println("-------- Dados do Aluno ----------");
    System.out.println("Nome   : " + aluno.getNome());
    System.out.println("Nota 1 = " + aluno.getNota1());
    System.out.println("Nota 2 = " + aluno.getNota2());
    System.out.println("----------------------------------");
  }

}//TelaAluno.