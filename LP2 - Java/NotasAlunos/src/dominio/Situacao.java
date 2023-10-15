//*ESTADO: PRONTO */
package src.dominio;
public class Situacao {
    private String situacao;
    // private NotaDisciplina notaDisciplina; //Acho q pode ser retirado

    public Situacao(String s){ //TODO questionar o Alex de pq esse método tem nome de construtor mas é void
        setSituacao(s);
    }

    public String getSituacao() {
        return situacao;
    }

    //Não esta explicito mas ache importante ter um setter para a situacao
    public void setSituacao(String s) {
        if (s == null) throw new RuntimeException("Situacao invalida");
        else this.situacao = s;
    }
}
