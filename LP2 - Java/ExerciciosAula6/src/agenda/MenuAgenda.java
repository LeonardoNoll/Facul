package agenda;

import pessoas.*;

import java.util.LinkedList;

import javax.swing.JOptionPane;

import contatos.*;

public class MenuAgenda {
    public static void main(String[] args) {
        //Criando agenda
        Agenda<Pessoa> agenda = new Agenda<Pessoa>();

        //Criando telefones
        Telefone tel1 = new Telefone(1111, 1111);
        Telefone tel2 = new Telefone(2222, 222);
        LinkedList<Telefone> telefones = new LinkedList<Telefone>();

        //Cadastrando pessoas
        Pessoa p1 = new Pessoa("pessoa1", telefones);
        Pessoa p2 = new Pessoa("pessoa2", telefones);

        //Menu
        while (true) {
            switch (montaMenu()) {
                case 0:
                    agenda.cadastrar(new Pessoa(JOptionPane.showInputDialog("Informe o nome da pessoa:"), telefones));
                    break;
                case 1:
                    JOptionPane.showMessageDialog(null, agenda.toString());
                    break;
                case 2:
                    JOptionPane.showMessageDialog(null, agenda.totalizar());
                    break;
                case 3:
                    String aux = JOptionPane.showInputDialog("Que pessoa voce deseja pesquizar?");
                    if(agenda.pesquisar(new Pessoa(aux, telefones))) {
                        JOptionPane.showMessageDialog(null, "Pessoa encontrada");
                    } else {
                        JOptionPane.showMessageDialog(null, "Pessoa nao encontrada");
                    }
                    break;
                case 4:
                    String remove = JOptionPane.showInputDialog("Informe a pessoa a excluir");
                    if(agenda.remover(new Pessoa(remove, telefones))) {
                        JOptionPane.showMessageDialog(null, "Pessoa removida");
                    } else {
                        JOptionPane.showMessageDialog(null, "Pessoa nao removida");
                    }
                    break;
                case 5:
                    return;
			default:
                    break;
            }
        }
    }

    private static int montaMenu() {
        String menu = "0 - Cadastrar uma pessoa\n";
        menu += "1 - Listar pessoas\n";
        menu += "2 - Listar o número total de contatos\n";
        menu += "3 - Pesquisar pessoa\n";
        menu += "4 - Remover pessoa\n";
        menu += "5 - Sair";
        return Integer.parseInt(
            JOptionPane.showInputDialog(menu));
    }
}
