//-----------------------------------------
// Programa para testar a classe Aluno.
//-----------------------------------------

public class TestaAluno_v1_1 {

  public static void main(String[] args) {
    //Declara a variável a1 do tipo Aluno.
    Funcionario a1; 

    //Instanciar a classe Aluno (criar um objeto da classe Aluno) e atribuir à variável a1.
    a1 = new Funcionario();

    //Atributos nome e nota1 são públicos, logo, podem ser acessados (violado o princípio do encapsulamento).
    a1.nome = "Maria";
    a1.nota1 = 8; 

    //a1.nota2 = 10; //Atributo privado não pode ser acessado (encapsulamento).
    //Deve ser chamado o método do objeto para atribuir sua nota 2.
    a1.registraNota2(10);

    //Declara a variável a2, instancia um Aluno e atribui a essa variável.
    Aluno a2 = new Aluno();
    
    a2.nome = "Joao";
    a2.nota1 = 6;
    a2.registraNota2(8);

    //Imprimindo um objeto: por padrão imprime somente o ID (referência) do objeto.
    //Depois veremos como fazer para imprimir todos os dados do objeto.
    System.out.println("Imprimindo a1  = " + a1);
    
    //Acessando os dados do objeto e imprimindo.
    System.out.println("-----------------");
    System.out.println(a1.nome);
    System.out.println(a1.nota1);
    System.out.println(a1.retornaNota2());

    System.out.println("-----------------");
    System.out.println(a2.nome);
    System.out.println(a2.nota1);
    System.out.println(a2.retornaNota2());

  }//main()

}//TestaAluno_v1_1.