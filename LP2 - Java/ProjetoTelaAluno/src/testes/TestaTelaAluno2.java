package src.testes;

import src.telas.TelaAluno;
import src.dominio.Aluno;

public class TestaTelaAluno2 {

  public static void main(String[] args) {
    Aluno a1;
    Aluno a2;
    TelaAluno tela;

    //Instancia um aluno, instancia uma tela e associa ao aluno, chama a tela 
    //para fazer a leitura de todos os dados do aluno.
    a1 = new Aluno("---");    
    tela = new TelaAluno(a1);
    tela.leTodosDados();

    //Instancia um aluno, associa a tela a este aluno, chama a tela 
    //para fazer a leitura de todos os dados do aluno.
    a2 = new Aluno("---");
    tela.setAluno(a2);
    tela.leTodosDados();

    //Associa a tela ao primeiro aluno, para fazer a impressão na tela.
    tela.setAluno(a1);
    tela.imprimeComMoldura();
    //Associa a tela ao segundo aluno, para fazer a impressão na tela.
    tela.setAluno(a2);
    tela.imprimeComMoldura();

    //Associa a tela ao primeiro aluno, para ler novamente a nota 1.
    tela.setAluno(a1);
    tela.imprime();
    tela.leNota1();

    //Imprime os dados dos alunos.
    tela.imprimeComMoldura();
    tela.setAluno(a2);
    tela.imprimeComMoldura();

  }//main()

}//TestaTelaAluno2.