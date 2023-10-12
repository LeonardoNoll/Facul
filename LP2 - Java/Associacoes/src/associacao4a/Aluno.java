package associacao4a;

import java.util.ArrayList;
import java.util.List;

public class Aluno {
  private String nome;
  private float nota1;
  private float nota2;

  //Atributo para implementar a multiplicidade "muitos" da associação.
  private List<Residencia> residencias = new ArrayList<Residencia>();

  //Construtor
  public Aluno(String n, float n1, float n2) {
    this.setNome(n);
    this.setNota1(n1);
    this.setNota2(n2);
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    if (nome == null) {
      new RuntimeException("Erro Aluno: nome nao pode ser null");
    }
    else if (nome.equals("")) {
      new RuntimeException("Erro Aluno: nome nao pode ser vazio");
    }
    else {
      this.nome = nome;
    }
  }

  public float getNota1() {
    return nota1;
  }

  public void setNota1(float nota1) {
    if ( (nota1 >= 0) && (nota1 <= 10) ) {
      this.nota1 = nota1;
    }
    else {
      //Lancando um excecao.
      throw new RuntimeException("Erro Aluno: Nota 1 invalida="+nota1+".");
    }
  }

  public float getNota2() {
    return nota2;
  }

  public void setNota2(float nota2) {
    if ( (nota2 >= 0) && (nota2 <= 10) ) {
      this.nota2 = nota2;
    }
    else {
      //Lancando um excecao.
      throw new RuntimeException("Erro Aluno: Nota 2 invalida="+nota2+".");
    }
  }

  public List<Residencia> getResidencias() {
    return residencias;
  }

  protected void adicionaResidencia(Residencia residencia) {
    if (residencia == null) {
      throw new RuntimeException("Erro Aluno: Residencia null");
    }
    else {
      //Adiciona a residencia na lista de residencias deste aluno.
      this.residencias.add(residencia);
    }
  }//adicionaResidencia()

  public float media(){
    float m;
    m = (this.nota1 + this.nota2) / 2;
    return m;
  }

  public String situacao() {
    if (media() < 3) {
      return "REPROVADO";
    }
    else if ( media()< 7 ) {
      return "RECUPERACAO";
    }
    else {
      return "APROVADO";
    }
  }

  @Override
  public String toString() {
    return "Aluno [nome=" + nome + ", nota1=" + nota1 + ", nota2=" + nota2
        + ", residencias=" + residencias + "]";
  }

}//Aluno.