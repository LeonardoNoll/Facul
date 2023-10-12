package associacao4a;

public class Residencia {

  private String rua;
  private int numero;
  private Aluno aluno; //Atributo para implementar a navegabilidade no sentido de Residencia para Aluno.

  public Residencia(String rua, int numero, Aluno aluno) {
    this.setRua(rua);
    this.setNumero(numero);
    this.setAluno(aluno);
  }

  public String getRua() {
    return rua;
  }

  public void setRua(String rua) {
    if (rua==null) {
      //Lancando uma excecao.
      throw new RuntimeException("Erro Residencia: rua não pode ser null");
    }
    else if (rua.equals("")) {
      //Lancando uma excecao.
      throw new RuntimeException("Erro Residencia: rua não pode ser vazio");
    }
    else {
      this.rua = rua;
    }
  }

  public int getNumero() {
    return numero;
  }

  public void setNumero(int numero) {
    this.numero = numero;
  }

  public Aluno getAluno() {
    return this.aluno;
  }
  
 
  public void setAluno(Aluno aluno) {
    this.aluno = aluno;
    aluno.adicionaResidencia(this);
  }

  @Override
  public String toString() {
    return "Residencia [rua=" + rua + ", numero=" + numero + "]";
  }
  

}//Residencia.