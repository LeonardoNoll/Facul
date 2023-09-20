package src.testes;

import src.telas.TelaAluno;
import src.dominio.Aluno;

public class TestaTelaAluno1 {

  public static void main(String[] args) {
    Aluno a1;
    Aluno a2;
    TelaAluno tela1;
    TelaAluno tela2;

    //Instancia um aluno, instancia uma tela e associa ao aluno, chama a tela 
    //para fazer a leitura de todos os dados do aluno.
    a1 = new Aluno("---");    
    tela1 = new TelaAluno(a1);
    tela1.leTodosDados();

    //Instancia um aluno, instancia uma tela e associa ao aluno, chama a tela 
    //para fazer a leitura de todos os dados do aluno.
    a2 = new Aluno("---");
    tela2 = new TelaAluno(a2);
    tela2.leTodosDados();

    //Imprime os dados dos dois alunos.
    tela1.imprimeComMoldura();
    tela2.imprimeComMoldura();

    //Le novamente a nota 1 do aluno 1.
    tela1.imprime();
    tela1.leNota1();

    //Imprime os dados dos dois alunos.
    tela1.imprimeComMoldura();
    tela2.imprimeComMoldura();

  }//main()

}//TestaTelaAluno1.