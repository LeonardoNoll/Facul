package agenda;

import java.util.Collection;
import java.util.LinkedList;

import pessoas.Pessoa;

public class Agenda<E> implements OperacoesAgenda<E>{
    private LinkedList<E> pessoas = new LinkedList<E>();

    @Override
    public boolean cadastrar(E obj) {
        if(obj == null) {
            System.err.println("Objeto invalido");
            return false;
        } else {
            return pessoas.add(obj);
        }
    }

    @Override
    public Collection listarTodos(){
        return pessoas;
    }

    @Override
    public int totalizar(){
        return pessoas.size();
    }

    @Override
    public boolean remover(E obj){
        return pessoas.remove(obj);
    }

    @Override
    public boolean pesquisar(E obj){
        return pessoas.contains(obj);
    }

    @Override
    public String toString(){
        String aux = "";
        for (E e : pessoas) {
            aux += e.toString() + "\n";
        }
        return aux;
    }
}
