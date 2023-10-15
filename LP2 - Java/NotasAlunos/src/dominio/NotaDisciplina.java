package src.dominio;
//!EM ANDAMENTO!!
public class NotaDisciplina {
    private float nota;
    private Disciplina disciplina;
    private Situacao situacao;
    private AnoSemestre anoSemestre; //? N sei se é pra estar aqui

    //*Construtor
    protected NotaDisciplina(float n, Disciplina d, Situacao s) {
        if (d == null) throw new RuntimeException("Disciplina invalida"); //1..1
        else this.disciplina = d;
        
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
    protected void setAnoSemestre(AnoSemestre anoSemestre) {
        this.anoSemestre = anoSemestre; //!N sei se precisa de verificação
    }

    protected void setDisciplina(Disciplina disciplina) {
        this.disciplina = disciplina; //!N sei se precisa de verificação
    }
    
}
