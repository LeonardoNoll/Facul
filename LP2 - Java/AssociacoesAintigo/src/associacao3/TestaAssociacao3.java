package associacao3;

import java.util.List;

//Este exemplo testa a navegabilidade da associação opcional multivalorada Aluno(0..*)-->(0..*)Residencia,
//mostrando que é possível instanciar um Aluno sem nenhuma Residencia, com apenas uma Residencia ou com muitas Residencias.
public class TestaAssociacao3 {

  public static void main(String[] args) {
    Aluno a1, a2;
    Residencia r;

    System.out.println("=============== Etapa 1 ===============");
    //Instancia Aluno a1 sem associar a nenhuma Residencia: 
    a1 = new Aluno("Pedro", 6, 7);
    System.out.println(a1);

    System.out.println("=============== Etapa 2 ===============");
    //Instancia uma Residencia para associar ao aluno a1.
    r = new Residencia("Rua abc", 100);
    a1.adicionaResidencia(r);
    System.out.println(a1);

    System.out.println("=============== Etapa 3 ===============");
    //Instancia outra Residencia para associar ao aluno a1.
    r = new Residencia("Rua abc", 200);
    a1.adicionaResidencia(r);
    System.out.println(a1);

    System.out.println("=============== Etapa 4 ===============");
    //Instancia Aluno a2 já associando a um objeto Residencia:
    //Primeiro instancia uma Residencia.
    r = new Residencia("Rua abc", 300);
    //Agora instancia Aluno passando o objeto Residencia.
    a2 = new Aluno("Pedro", 6, 7, r);
    System.out.println(a2);

    System.out.println("=============== Etapa 5 ===============");
    //Pega todas as residencias do Aluno a1.
    List<Residencia> lista_residencias;
    lista_residencias = a1.getResidencias();

    //Imprime essas residencias (utilizando laço for clássico):
    System.out.println("----- Todas Residencias do Aluno a1 -----");
    int i;
    for (i = 0; i<lista_residencias.size(); i++) {
      r = lista_residencias.get(i);
      System.out.println("Residencia " + i + ": " + r.getRua() + ", " + r.getNumero());
    }

    //Imprime essas residencias (utilizando laço for avançado):
    System.out.println("----- Todas Residencias do Aluno a1 -----");
    i = 0;
    for (Residencia rr: lista_residencias) {
      System.out.println("Residencia " + i + ": " + rr.getRua() + ", " + rr.getNumero());
      i++;
    }

  }//main()

}//TestaAssociacao3