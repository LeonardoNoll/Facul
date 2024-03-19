

/**
 *
 * @author silviacb
 */
public enum Bebida {
	CocaCola(2.00, "Coca-cola"), Suco(1.50, "Suco"), Agua(1.00, "�gua");

	private final double preco;
	private final String descricao;

	private Bebida(double preco, String descricao) {
		this.preco = preco;
		this.descricao = descricao;
	}

	public double getPreco() {
		return this.preco;
	}
	public String getDescricao() {
		return descricao;
	}

}
