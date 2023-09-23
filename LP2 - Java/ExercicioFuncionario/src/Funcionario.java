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

    public Endereco getEndereco() {
        return endereco;
    }

    @Override
    public String toString() {
        return "Funcionario{nome=" + nome + ", endereco=" + endereco + '}';
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Funcionario) {
            Funcionario f = (Funcionario) obj;
            return this.nome.equals(f.nome) && this.endereco.toString().equals(f.endereco.toString());
        } else {
            return false;
        }
    }

}