package dominio;
//*ESTADO: COMPLETO */
public class Disciplina {
    private String codigo;
    private String nome;
    private int cargaHoraria;

    //*Construtor*/
    public Disciplina(String c, String n, int ch){
        if (c == null) throw new RuntimeException("Codigo invalido");
        else this.codigo = c;

        if (n == null) throw new RuntimeException("Nome invalido");
        else this.nome = n;

        if (ch < 0) throw new RuntimeException("Carga horaria invalida");
        else this.cargaHoraria = ch;
    }

    //*Getters*/
    public String getNome() {
        return nome;
    }
    public String getCodigo() {
        return codigo;
    }
    public int getCargaHoraria() {
        return cargaHoraria;
    }
}
