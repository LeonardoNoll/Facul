package associacao2;

//Este exemplo testa a associação obrigatória Aluno(0..*)-->(1..1)Residencia,
//mostrando que não será possível instanciar um Aluno sem associar a nenhuma Residencia,
//ou seja, todo objeto Aluno obrigatoriamente estará associado a um objeto Residencia.
public class TestaAssociacao2 {

  public static void main(String[] args) {
    Aluno a1;
    Residencia r1;

    System.out.println("=============== Etapa 1 ===============");

    //Conforme o diagrama de classes, a associação Aluno(0..*)-->(1..1)Residencia é obrigatória, ou seja,
    //um objeto Aluno deve estar obrigatoriamente associado a um objeto Residencia.
    //Portanto, não deve ser possível instanciar um aluno sem passar o parametro Residencia.
    //Isso é conseguido através dos construtores implementados na classe Aluno, ou seja, 
    //todo construtor implementado na classe Aluno deverá ter o parametro Residencia.
    //Portanto, a linha abaixo não deveria ser permitida, pois ela não tem o parâmetro Residencia e,
    //caso fosse permitido, seria possível instanciar um objeto Aluno sem nenhuma Residencia.
    //Foi por esse motivo que esse construtor não foi implementado na classe Aluno.
    //Tente compilar esta linha e verá o erro de compilação.
    //a1 = new Aluno("Jose", 8, 9);

    //Para associar um Aluno a uma Residencia, é obrigatório primeiro instanciar uma Residencia. 
    //Instancia residencia r1 para atribuir ao aluno a1.
    r1 = new Residencia("Rua xyz", 200);
    //Instancia um aluno e passa a Residencia r1.
    //Note que o construtor que foi implementado na classe Aluno obriga a passagem do parâmetro Residencia,
    //para garantir a associação obrigatória que foi especificada no diagrama de classes.
    a1 = new Aluno("Jose", 8, 9, r1);
    System.out.println(a1);


    System.out.println("=============== Etapa 2 ===============");

    r1 = null;

    System.out.println("A seguir será gerada uma exceção, conforme as regras estabelecidas.");

    //======================================
    //Todas as linhas a seguir acusarão erro em tempo de execução pois todas elas
    //tentam associar Aluno a um objeto Residencia null, o que não é permitido pela classe Aluno.
    //Tente executar uma de cada vez para verificar os erros gerados.
    //======================================

    //Esta linha irá gerar uma exceção, pois Aluno não pode ter uma Residencia null.
    //a1.setResidencia(null);

    //Esta linha irá gerar uma exceção, pois Aluno não pode ter uma Residencia null.
    a1.setResidencia(r1);

    //Não é possível instanciar um Aluno passando uma Residencia null:
    a1 = new Aluno("Jose", 8, 9, null);

    //Não é possível instanciar um Aluno passando uma Residencia null:
    a1 = new Aluno("Jose", 8, 9, r1);

    //Esta linha nunca será executada pois alguma das linhas acima irá gerar uma exceção,
    //provocando a interrupção do programa.
    System.out.println("Fim do programa");

  }//main()

}//TestaAssociacao2.