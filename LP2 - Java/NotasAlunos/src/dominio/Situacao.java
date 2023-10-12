package src.dominio;

public class Situacao {
    private String situacao;
    private NotaDisciplina notaDisciplina;

    public void Situacao(String s){ //TODO questionar o Alex de pq esse método tem nome de construtor mas é void
        this.situacao = s;
    }

    public String getSituacao() {
        return situacao;
    }
}
