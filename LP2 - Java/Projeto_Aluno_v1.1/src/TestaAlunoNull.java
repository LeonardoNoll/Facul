//-----------------------------------------
// Programa para demonstrar um objeto null.
//-----------------------------------------

public class TestaAlunoNull {

  public static void main(String[] args) {
    //Declara a variavel a1 do tipo Aluno.
    //A variável a1 não foi utilizada em nenhuma parte do programa, 
    //então o compilador emite um alerta (warning),
    //mas o programa será compilado e executado normalmente.
    Aluno a1;

    System.out.println("Ponto 1");
    
    //Erro de compilacao se tentar usar a variavel a1: não foi inicializada.
    //Retire o comentário da linha abaixo e veja a mensagem do erro de compilação.
    //System.out.println(a1); 

    System.out.println("Ponto 2");
    
    //Declara a variavel a2 do tipo Aluno.
    Aluno a2;
    //Inicializa a2 com null.
    a2 = null; //comente esta linha para verificar os dois erros de compilação acusados nas linhas abaixo. 
    
    //Poderia ter sido feito em uma única linha: declara a2 e inicializa com null.
    //Aluno a2 = null;
    
    System.out.println("Ponto 3");
    
    System.out.println("a2 = " + a2);
    
    System.out.println("Ponto 4");
    
    //Erro de execucao (runtime): tentando acessar um objeto null (não existe).
    a2.nome = "Joao";
    System.out.println(a2.nome); 
   
    //Programa é abortado devido ao erro acima e as linhas abaixo nao serao executadas.

    System.out.println("Ponto 5");
    
    System.out.println("Ponto 6");
    
    System.out.println("Fim do programa");

  }//main()

}//TestaAlunoNull.