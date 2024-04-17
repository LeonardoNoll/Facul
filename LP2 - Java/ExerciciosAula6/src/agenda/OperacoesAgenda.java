package agenda;

import java.util.Collection;

public interface OperacoesAgenda<E>{
    public boolean cadastrar(E obj);
    public Collection listarTodos();
    public int totalizar();
    public boolean remover(E obj);
    public boolean pesquisar(E obj);
}
