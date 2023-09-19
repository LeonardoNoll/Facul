package associacao1;

//Este exemplo testa a associação opcional Aluno(0..*)-->(0..1)Residencia.
//Faz a recuperação, modificação e atribuição entre objetos Residencia de dois objetos Aluno,
//enfatizando o comportamento dos tipos referenciais da linguagem Java.
public class TestaAssociacao1b {

  public static void main(String[] args) {
    //Declara dois objetos Aluno.
    Aluno a1, a2;

    //Declara dois objetos Residencia.
    Residencia r1, r2;

    System.out.println("=============== Etapa 1 ===============");

    //Instancia um aluno (a1):
    a1 = new Aluno("Pedro", 6, 7);
    //Instancia uma Residencia (r1):
    r1 = new Residencia("Argentina", 1000);
    //Associa o aluno a1 à Residencia r1:
    a1.setResidencia(r1);

    //Instancia uma Residencia (r2):
    r2 = new Residencia("Bolivia", 2000);
    //Instancia um Aluno (a2):
    a2 = new Aluno("Maria", 8, 9);
    //Associa o aluno a2 à Residencia r2:
    a2.setResidencia(r2);

    //Imprime os Alunos:
    System.out.println(a1);
    System.out.println(a2);

    System.out.println("=============== Etapa 2 ===============");

    //Declara a variável local r do tipo Residencia e pega a Residencia do aluno a1:
    Residencia r;
    r = a1.getResidencia();
    //Modifica o número da Residencia r:
    r.setNumero(1100);

    //Imprime os Alunos:
    System.out.println(a1); //Note que o número da Residencia de a1 foi modificada.
    System.out.println(a2);

    System.out.println("=============== Etapa 3 ===============");

    //Faz com que a Residencia do aluno a1 seja a mesma do aluno a2,
    //ou seja, a1 vai referenciar a mesma Residência de a2:
    //Pega a Residencia do a2:
    r = a2.getResidencia();
    //Atribui essa Residencia para a1:    
    a1.setResidencia(r);

    //Imprime os Alunos (a1 e a2 estão referenciando a mesma Residencia r2):
    System.out.println(a1);
    System.out.println(a2);

    System.out.println("=============== Etapa 4 ===============");

    //Pega a Residencia do a1:
    r = a1.getResidencia();
    //Modifica o número.
    r.setNumero(1200);
    //Veja que a Residencia de a1 e a2 foram modificadas, 
    //pois os dois objetos aluno estão referenciando o mesmo objeto Residencia.

    //Imprime os Alunos:
    System.out.println(a1);
    System.out.println(a2);

  }//main()

}//TestaAssociacao1b.