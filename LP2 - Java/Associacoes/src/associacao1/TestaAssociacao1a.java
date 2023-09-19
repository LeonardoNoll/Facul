package associacao1;

//Este exemplo testa a associação opcional Aluno(0..*)-->(0..1)Residencia,
//mostrando que pode ser instanciado um Aluno sem nenhuma Residencia.
public class TestaAssociacao1a {

  public static void main(String[] args) {
    Aluno a1, a2, a3;
    Residencia r2, r3;

    System.out.println("=============== Etapa 1 ===============");
    //Instancia Aluno a1 sem associar a nenhuma Residencia: 
    a1 = new Aluno("Pedro", 6, 7);
    System.out.println(a1);

    System.out.println("=============== Etapa 2 ===============");
    //Instancia um Aluno (a2) e associa a uma Residencia (r2):
    //Insancia Aluno a2:
    a2 = new Aluno("Maria", 8, 9);
    System.out.println(a2);
    //Instancia residência r2:
    r2 = new Residencia("Rua abc", 200);
    //Associa a2 a r2:
    a2.setResidencia(r2);
    System.out.println(a2);

    System.out.println("=============== Etapa 3 ===============");
    //Associa Aluno a3 à Residencia r3, instanciando primeiro a Residencia:
    //Instancia residência r3:
    r3 = new Residencia("Rua abc", 300);
    //Insancia Aluno a2:
    a3 = new Aluno("Carlos", 9, 9);
    System.out.println(a3);
    //Associa a3 a r3:
    a3.setResidencia(r3);
    System.out.println(a3);

  }//main()

}//TestaAssociacao1a.