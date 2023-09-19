package composicao2;

import composicao1.Aluno;
import composicao1.Residencia;

public class TestaComposicao2 {

  public static void main(String[] args) {
    Aluno a1;
    Residencia r1;

    System.out.println("=============== Etapa 1 ===============");
    //Instancia um aluno e passa rua e número (Aluno irá instanciar a sua Residencia).
    a1 = new Aluno("Jose", 8, 9, "Rua abc", 100);
    System.out.println(a1);

    System.out.println("=============== Etapa 2 ===============");
    //Não é possível mexer diretamente na Residencia de a1.
    r1 = a1.getCopiaResidencia();
    System.out.println(r1);
    r1.setRua("Rua xyz");
    r1.setNumero(200);
    System.out.println(r1);

    //Residencia de a1 não foi modificada.
    System.out.println("Residencia de a1 nao foi modificada: " + a1);

    System.out.println("=============== Etapa 3 ===============");
    //Solicita ao objeto a1 para modificar sua rua e numero.
    a1.modificaRua("www");
    a1.modificaNumero(300);
    System.out.println("Residencia de a1 modificada: " + a1);
  }//main()

}//TestaComposicao2.