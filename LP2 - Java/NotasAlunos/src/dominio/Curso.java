package src.dominio;
//!!EM ANDAMENTO!!
import java.util.List;

public class Curso {
    private String nome;
    private List<Disciplina> disciplinas;
    private List<Matricula> matriculas;

    //*Construtor */
    public Curso(String n){
        if (n == null) throw new RuntimeException("Nome invalido");
        else this.nome = n;
    }


    //*Getters */
    public String getNome() {
        return nome;
    }
    public List<Disciplina> getDisciplinas() {
        return disciplinas;
    }
    public List<Matricula> getMatriculas() {
        return matriculas;
    }


    //*Diversos */
    public void incluiDisciplina(Disciplina d){
        if (d == null) throw new RuntimeException("Disciplina invalida");
        else this.disciplinas.add(d);
    }
    public void incluiMatricula(Matricula m){ //!Não está incluso no diagrama de classes //TODO perguntar pro Alex
        if (m == null) throw new RuntimeException("Matricula invalida");
        else this.matriculas.add(m);
    }


}
