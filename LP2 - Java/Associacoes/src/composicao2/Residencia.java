package composicao2;

public class Residencia implements Cloneable {

  private String rua;
  private int numero;

  public Residencia(String rua, int numero) {
    this.setRua(rua);
    this.setNumero(numero);
  }

  public Object clone() {
    try {
      return super.clone();
    } catch (CloneNotSupportedException e1) {
      // TODO Auto-generated catch block
      e1.printStackTrace();
      return null;
    }
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