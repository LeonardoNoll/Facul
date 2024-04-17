package genericos;

//classe genérica - com 2 param. 
//O primeiro param é P
//O segundo param é S
public class Par<P, S> {
	//declarando dois atributos usando os param.
	private P primeiro;
	private S segundo;

	public Par() {}
	//construtor com param genéricos
	public Par(P p, S s) {
		primeiro = p;
		segundo = s;
	}
	//método com retorno genérico
	public P getPrimeiro() {return primeiro;}
	public S getSegundo() {	return segundo;}
	public void setPrimeiro(P p) {	primeiro = p;}
	public void setSegundo(S s) {	segundo = s;}
	public String toString() {
		return primeiro + " " + segundo;
	}
}
