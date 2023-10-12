package src.dominio;
//!!EM ANDAMENTO!!
import java.util.List;

public class AnoSemestre {
    private int ano;
    private int semestre;
    private Matricula matricula; //? N sei se deveria ter isso
    private List<NotaDisciplina> notas;

    //*Construtor
    protected AnoSemestre(int a, int sem, Matricula mat){
        if (a > 0) this.ano = a;
        else throw new RuntimeException("Ano invalido");

        if (sem > 0) this.semestre = sem;
        else throw new RuntimeException("Semestre inválido");

        this.matricula = mat; // 0..*
    }


    //*Getters
    public int getAno(){
        return this.ano;
    }

    public int getSemestre(){
        return this.semestre;
    }

    public Matricula getMatricula(){
        return this.matricula;
    }


    //*Diversos
    public NotaDisciplina registraNotaDisciplina(float n, Disciplina d, Situacao s){
        NotaDisciplina notaD = new NotaDisciplina(n,d,s);
        return notaD;
    }

    public List<NotaDisciplina> listNotaDisciplina(){
        return this.notas;
    }

    protected void setMatricula(Matricula m){
        //TODO descobrir como faz saporra
    }
}
