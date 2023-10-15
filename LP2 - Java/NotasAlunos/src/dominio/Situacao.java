package src.dominio;
//!!EM ANDAMENTO!!
public class Situacao {
    private String situacao;
    // private NotaDisciplina notaDisciplina; //Acho q pode ser retirado

    public Situacao(String s){ //TODO questionar o Alex de pq esse método tem nome de construtor mas é void
        this.situacao = s;
    }

    public String getSituacao() {
        return situacao;
    }
}
