
public class TesteFuncionario{

  public static void main(String[] args) {
    Funcionario f1 = new Funcionario("---");
    TelaFuncionario tela;  
    
    System.out.println("===================================");
    tela = new TelaFuncionario(f1);
    tela.leTodosDados();
    tela.imprimeFuncionario(f1);
    tela.imprimeBonito();

    System.out.println("===================================");
    Funcionario f2 = new Funcionario("---");
    // TelaFuncionario tela2;  
    
    // tela2 = new TelaFuncionario(f2);
    tela.setFuncionario(f2);
    tela.leTodosDados();
    tela.imprimeFuncionario(f2);
    tela.imprimeBonito();
    
    System.out.println("===================================");
    // tela.setFuncionario(f1);
    tela.imprimeFuncionario(f1);
    // tela.setFuncionario(f2);
    tela.imprimeFuncionario(f2);
    System.out.println("Funcionarios são iguais? " + (f1.equals(f2)? "Sim" : "Não"));
  }
}

