package composicao1;

public class Residencia {

  private String rua;
  private int numero;

  public Residencia(String rua, int numero) {
    this.setRua(rua);
    this.setNumero(numero);
  }

  //Implementação de um método para retornar uma cópia do objeto.
  //Poderia utilizar o método clone(), mas aqui eh mostrada uma forma manual. 
  public Residencia copia() {
    Residencia r = new Residencia(this.rua, this.numero);
    return r;
  }

  public String getRua() {
    return rua;
  }

  public void setRua(String rua) {
    if (rua==null) {
      //Lancando um excecao.
      throw new RuntimeException("Erro Residencia: rua não pode ser null");
    }
    else if (rua.equals("")) {
      //Lancando um excecao.
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

  @Override
  public String toString() {
    return "Residencia [rua=" + rua + ", numero=" + numero + "]";
  }

}//Residencia.