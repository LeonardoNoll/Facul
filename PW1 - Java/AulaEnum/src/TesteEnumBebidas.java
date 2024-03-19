


/**
 *
 * @author silviacb
 */
public class TesteEnumBebidas {
    public static void main(String[] args) {
       // System.out.println(Bebida.CocaCola.getDescricao() + ": R$" + Bebida.CocaCola.getPreco());
       // Percorre a enumera��o (percorre as constantes) e para cada item da enum
       // vai permitir fazer uma a��o, neste caso linha 14 - estamos pegando a descri��o	
        for (Bebida bebida : Bebida.values()) {
            //System.out.println(bebida.getDescricao());
            
            System.out.print(bebida.getDescricao() + " -> ");
            System.out.println(bebida.getPreco());
        }
    }
}
