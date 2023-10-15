//*ESTADO: PRONTO */
package src.dominio;
import java.util.List;

public class AnoSemestre {
    private int ano;
    private int semestre;
    private Matricula matricula; //? N sei se deveria ter isso, acho q deveria
    private List<NotaDisciplina> notas;

    //*Construtor */
    protected AnoSemestre(int a, int sem, Matricula mat){
        if (a > 0) this.ano = a;
        else throw new RuntimeException("Ano invalido");

        if (sem > 0) this.semestre = sem;
        else throw new RuntimeException("Semestre inválido");
        
        setMatricula(mat); //1..1
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


    //*Diversos */
    public NotaDisciplina registraNotaDisciplina(float n, Disciplina d, Situacao s){
        NotaDisciplina notaD = new NotaDisciplina(n,d,s); //Instancia a nota
        notaD.setAnoSemestre(this); //Associa o anoSemestre a nota
        this.notas.add(notaD); //Associa a nota ao anoSemestre
        return notaD;
    }

    public List<NotaDisciplina> listNotaDisciplina(){
        return this.notas;
    }

    protected void setMatricula(Matricula m){
        if (m == null) throw new RuntimeException("Matricula invalida");
        else this.matricula = m; 
    }
}
