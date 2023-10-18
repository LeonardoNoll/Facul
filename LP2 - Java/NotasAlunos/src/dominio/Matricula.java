//*ESTADO: "PRONTO" */
package dominio;

import java.util.List;

public class Matricula {
    private List<AnoSemestre> anoSemestres;
    private Aluno aluno;
    private Curso curso;
    private String matricula;
    private int ano;
    private int semestre;

    //*Construtor */
    public Matricula(String m, int ano, int sem, Aluno a, Curso c){
        if (m == null) throw new RuntimeException("Matricula invalida");
        else this.matricula = m;
        
        if (ano < 1) throw new RuntimeException("Ano invalido"); 
        else this.ano = ano;

        if (sem < 1) throw new RuntimeException("Semestre invalido"); 
        else this.semestre = sem;

        setAluno(a);

        setCurso(c);
    }


    //*Getters */
    public String getMatricula() {
        return matricula;
    }
    public int getAno() {
        return ano;
    }
    public int getSemestre() {
        return semestre;
    }
    public Aluno getAluno() {
        return aluno;
    }
    public Curso getCurso() {
        return curso;
    }
    public List<AnoSemestre> listAnoSemestre(){
        return anoSemestres;
    }


    //*Outros */
    public void registraAnoSemestre(int ano, int sem){ //Instancia e vincula anoSemestre a matricula
        AnoSemestre as;
        as = new AnoSemestre(ano, sem, this);
        anoSemestres.add(as); 
    }

    public List<AnoSemestre> listAnoSemestres(){
        return anoSemestres;
    }

    protected void setAluno(Aluno a) {
        if (a == null) throw new RuntimeException("Aluno invalido");
        else this.aluno = a;
    }

    protected void setCurso(Curso c){
        if (c == null) throw new RuntimeException("Curso invalido");
        else this.curso = c;
        // this.curso.incluiMatricula(this);
    }
}
