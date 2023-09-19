//-----------------------------------------
// Implementacao parcial da classe Aluno
//-----------------------------------------

public class Funcionario {

  //-----------------------------------------
  //-------------- Atributos ----------------
  //-----------------------------------------

  //Dois atributos públicos.
  //Não devem ser utilizados dessa forma pois violam o conceito de encapsulamento.
  public String nome;
  public float nota1;

  //Atributo privado. Forma correta. Implementa o encapsulamento.
  private float nota2;
  
  //-----------------------------------------
  //-------------- Métodos ------------------
  //-----------------------------------------

  //Método para atribuir a nota 2 ao objeto aluno.
  public void registraNota2(float n2) {
    if (n2 >=0 && n2<=10)
      nota2 = n2;
  }//registraNota2()

  //Método que retorna a nota 2 do aluno.
  public float retornaNota2() {
    return nota2;
  }//retornaNota2()

}//Final da classe Aluno.