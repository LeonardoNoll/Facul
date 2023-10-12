package associacao4b;

//Esta classe implementa parte da navegabilidade nos dois sentidos entre Aluno<->Residencia.
//Esta classe implementa a navegabilidade de Residencia para Aluno.
//A classe Aluno implementa a navegabilidade de Aluno para as suas Residencias. 
//No entanto, as chamadas para efetivar a associação devem estar atreladas,
//isso foi implementado no método adicionaResidencia() da classe Aluno.
//O método setAluno() aqui da classe Residencia foi feito protected para evitar chamadas
//acidentais ou não adequadas por clientes fora deste pacote.
public class Residencia {

  private String rua;
  private int numero;
  private Aluno aluno; //Atributo para implementar a navegabilidade no sentido de Residencia para Aluno.

  public Residencia(String rua, int numero) {
    this.setRua(rua);
    this.setNumero(numero);
   
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
  
  //Método protegido para evitar que clientes de outros pacotes chamem acidentalmente
  //e não implementem a navegabilidade nos dois sentidos ou chamem de forma errada
  //causando loop infinito (recursivo).
  protected void setAluno(Aluno aluno) {
    this.aluno = aluno;
   
  }

  @Override
  public String toString() {
    return "Residencia [rua=" + rua + ", numero=" + numero + "]";
  }
  

}//Residencia.