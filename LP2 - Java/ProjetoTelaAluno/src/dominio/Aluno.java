package src.dominio;

public class Aluno {
  private String nome;
  private float nota1;
  private float nota2;

  //Construtor
  public Aluno(String n) {
    this.setNome(n);
  }

  //Outro construtor
  public Aluno(String n, float n1, float n2) {
    this.setNome(n);
    this.setNota1(n1);
    this.setNota2(n2);
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    //Regras para validação de nome (neste exemplo):
    //Nome deve ser diferente de null e ter pelo menos 3 caracteres.
    if (nome == null) 
      throw new RuntimeException("Nome NULL.");
    if (nome.length() < 3)
      throw new RuntimeException("Nome com menos que 3 caracteres.");
    this.nome = nome;
  }

  public float getNota1() {
    return nota1;
  }

  public void setNota1(float x) {
    if ( (x >= 0) && (x <= 10) ) {
      this.nota1 = x;
    }
    else {
      //Lançando um exceção.
      throw new RuntimeException("Nota 1 inv�lida.");
    }
  }

  public float getNota2() {
    return nota2;
  }

  //Utilizando o par�metro nota2 para receber a nota.
  public void setNota2(float nota2) {
    if ( (nota2 >= 0) && (nota2 <= 10) ) {
      this.nota2 = nota2;
    }
    else {
      //Lan�ando um exce��o.
      throw new RuntimeException("Nota 2 inv�lida.");
    }
  }

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

}//Aluno.
