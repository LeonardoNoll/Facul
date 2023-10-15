//!EM ANDAMENTO!!
package src.dominio;
public class NotaDisciplina {
    private float nota;
    private Disciplina disciplina;
    private Situacao situacao;
    private AnoSemestre anoSemestre; //? N sei se é pra estar aqui, acho q deveria

    //*Construtor
    protected NotaDisciplina(float n, Disciplina d, Situacao s) {
        setDisciplina(d); //1..1
        
        if (n > 10 || n < 0) throw new RuntimeException("Nota invalida");
        else this.nota = n;
        
        if (s == null) throw new RuntimeException("Situacao invalida"); //1..1
        else this.situacao = s;
    }


    //*Getters
    public float getNota() {
        return nota;
    }

    public Disciplina getDisciplina() {
        return disciplina;
    }

    public Situacao getSituacao() {
        return situacao;
    }

    public AnoSemestre getAnoSemestre() {
        return anoSemestre;
    }


    //*Setters
    protected void setAnoSemestre(AnoSemestre as) {
        if (anoSemestre == null) throw new RuntimeException("Ano/semestre invalido");
        else this.anoSemestre = as; 
    }

    protected void setDisciplina(Disciplina d) {
        if (disciplina == null) throw new RuntimeException("Disciplina invalida");
        else this.disciplina = d; 
    }
    
}
