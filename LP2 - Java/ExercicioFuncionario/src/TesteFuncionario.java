
public class TesteFuncionario{

  public static void main(String[] args) {
    Funcionario f1 = new Funcionario("---");
    TelaFuncionario tela1;  
    

    tela1 = new TelaFuncionario(f1);
    tela1.leTodosDados();
    tela1.imprimeFuncionario();
    tela1.imprimeBonito();

  }
}

