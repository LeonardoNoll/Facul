public class Endereco {
    
    private String rua;
    private int numero;

    public Endereco(String rua, int numero) {
        setRua(rua);
        setNumero(numero);
    }

    public String getRua() {
        return rua;
    }

    public void setRua(String rua) {
        if (rua.length() > 0) {
            this.rua = rua;
        } else {
            throw new RuntimeException("Rua não pode ser vazia");
        }
    }

    public int getNumero() {
        return numero;
    }

    public void setNumero(int numero) {
        if (numero > 0) {
            this.numero = numero;
        } else {
            throw new RuntimeException("Número deve ser maior que zero");
        }
    }

    @Override
    public String toString() {
        return "Endereco{rua=" + rua + ", numero=" + numero + '}';
    }
}
