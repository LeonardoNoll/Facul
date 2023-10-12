package associacao1;

public class Residencia {

  private String rua;
  private int numero;

  //Este construtor não foi implementado para não permitir 
  //instanciar uma Residência sem rua e número.
  /*
   public Residencia() {

  }
   */

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

  @Override
  public String toString() {
    return "Residencia [rua=" + rua + ", numero=" + numero + "]";
  }

}//Residencia.