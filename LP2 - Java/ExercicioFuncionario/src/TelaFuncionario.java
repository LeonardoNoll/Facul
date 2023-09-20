import java.util.Scanner;

public class TelaFuncionario {
    private Funcionario funcionario;
    private Endereco endereco;
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
        endereco = new Endereco(rua, numero);
        funcionario.setEndereco(endereco);
    }

    //Imprime funcionario
    public void imprimeFuncionario(Funcionario f) {
        System.out.println(f.toString());
    }

    public void imprimeBonito(){
        System.out.println("Nome: " + funcionario.getNome() + "\n" 
             + "Endereço: " + endereco.getRua() +", " + endereco.getNumero());
    }

    //Le todos os dados de uma vez
    public void leTodosDados() {
        leNome();
        leEndereco();
    }

    public boolean compareFuncionario(Funcionario a, Funcionario b){
        if (a.toString() == b.toString()){
            return true;
        }
        return false;
    }


}
