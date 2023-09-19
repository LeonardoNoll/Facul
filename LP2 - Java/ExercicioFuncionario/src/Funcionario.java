public class Funcionario {

    private String nome;
    private Endereco endereco;

    public Funcionario(String nome) {
        setNome(nome);
    }

    public Funcionario(String nome, Endereco endereco) {
        this.nome = nome;
        this.endereco = endereco;
    }

    public void setEndereco(Endereco endereco) {
        this.endereco = endereco;
    }

    public void setNome(String nome) {
        if (nome.length() > 0) {
            this.nome = nome;
        } else {
            throw new RuntimeException("Nome não pode ser vazio");
        }
    }

    public String getNome() {
        return nome;
    }


}