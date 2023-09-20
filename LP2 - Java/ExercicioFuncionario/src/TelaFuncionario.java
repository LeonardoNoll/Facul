import java.util.Scanner;

public class TelaFuncionario {
    private Funcionario funcionario;
    private Scanner scan = new Scanner(System.in);
    
    //Controi tela atrelada a 1 funcionario
    public TelaFuncionario(Funcionario f) {
        setFuncionario(f);
    }

    //Seta funcionario 
    public void setFuncionario(Funcionario f) {
        if (f == null) {
            throw new RuntimeException("Funcionario null");
        } else {
            this.funcionario = f;
        }
    }

    //Getter
    public Funcionario getFuncionario() {
        return funcionario;
    }

    //Le nome digitado
    public void leNome() {
        System.out.print("Digite o nome: ");
        String s = scan.nextLine();
        funcionario.setNome(s);
    }

    //Le endereco digitado
    public void leEndereco() {
        System.out.print("Digite a rua: ");
        String rua = scan.nextLine();
        System.out.print("Digite o número: ");
        int numero = scan.nextInt();
        scan.nextLine();
        Endereco e = new Endereco(rua, numero);
        funcionario.setEndereco(e);
    }

    //Imprime funcionario
    public String imprimeFuncionario() {
        return funcionario.toString();
    }

    public String imprimeBonito(){
        return "Nome: " + this.funcionario.getNome() + "\n" 
             + "Endereço: " + this.funcionario.getEndereco().toString();
    }

    //Le todos os dados de uma vez
    public void leTodosDados() {
        leNome();
        leEndereco();
    }


}
