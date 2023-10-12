package composicao1;

//Esta classe implementa a associação do tipo composição Aluno()-->(1)Residencia.
//Observe que se trata de uma associação monovalorada obrigatória de Aluno para Residencia, ou seja, 
//um objeto Aluno deve estar obrigatoriamente associado a uma Residencia.
//E mais, como se trata de uma composição, cada objeto Residencia só pode estar associado a um unico Aluno
//e somente o objeto Aluno pode ter acesso ao seu objeto Residencia. 
//Por isso não foi implementado o método getResidencia(), mas sim, um método getCopiaResidencia() para retornar
//uma cópia do objeto Residencia e não o próprio objeto Residencia, pois, se assim fosse feito,
//um objeto externo poderia modificar os dados da Residencia de um Aluno.
public class Aluno {
  private String  nome;
  private float   nota1;
  private float   nota2;
  private Residencia residencia;

  //Ao instanciar um Aluno, deve ser informado obrigatoriamente a rua e número da Residencia, pois,
  //é o próprio objeto Aluno que irá instanciar a sua Residencia.
  public Aluno(String n, float n1, float n2, String rua, int numero) {
    this.setNome(n);
    this.setNota1(n1);
    this.setNota2(n2);

    Residencia r;
    r = new Residencia(rua, numero);
    this.setResidencia(r);
  }

  //Este método foi tornado privado para que nenhum outro objeto possa modificar o objeto Residencia do Aluno.
  //Somente o próprio objeto Aluno poderá chamar este método.
  private void setResidencia(Residencia r) {
    if (r == null) {
      new RuntimeException("Erro Aluno: Residencia nao pode ser null");
    }
    else {
      this.residencia = r;
    }
  }

  //Este método retorna uma cópia do objeto Residencia, assim, outros objetos podem solicitar os dados da Residencia
  //do Aluno mas não poderão modificar esses dados, já que eles estão recebendo uma cópia do objeto Residencia e 
  //não o próprio objeto Residencia.
  public Residencia getCopiaResidencia() {
    return residencia.copia();
  }

  //Permite modificar a rua da Residencia do Aluno.
  public void modificaRua(String rua) {
    this.residencia.setRua(rua);
  }

  //Permite modificar o número da Residencia do Aluno.
  public void modificaNumero(int numero) {
    this.residencia.setNumero(numero);
  }

  //Retorna a rua da Residencia do Aluno.
  public String getRua() {
    return this.residencia.getRua();
  }

  //Retorna o numero da Residencia do Aluno.
  public int getNumero() {
    return this.residencia.getNumero();
  }

  public String getNome() {
    return nome;
  }

  public void setNome(String nome) {
    if (nome == null) {
      //Lancando um excecao.
      new RuntimeException("Erro Aluno: nome nao pode ser null");
    }
    else if (nome.equals("")) {
      //Lancando um excecao.
      new RuntimeException("Erro Aluno: nome nao pode ser vazio");
    }
    else {
      this.nome = nome;
    }
  }

  public float getNota1() {
    return nota1;
  }

  public void setNota1(float nota1) {
    if ( (nota1 >= 0) && (nota1 <= 10) ) {
      this.nota1 = nota1;
    }
    else {
      //Lancando um excecao.
      throw new RuntimeException("Erro Aluno: Nota 1 invalida="+nota1+".");
    }
  }

  public float getNota2() {
    return nota2;
  }

  public void setNota2(float nota2) {
    if ( (nota2 >= 0) && (nota2 <= 10) ) {
      this.nota2 = nota2;
    }
    else {
      //Lancando um excecao.
      throw new RuntimeException("Erro Aluno: Nota 2 invalida="+nota2+".");
    }
  }

  public float media(){
    float m;
    m = (this.nota1 + this.nota2) / 2;
    return m;
  }

  public String situacao() {
    if (media() < 3) {
      return "REPROVADO";
    }
    else if ( media()< 7 ) {
      return "RECUPERACAO";
    }
    else {
      return "APROVADO";
    }
  }

  @Override
  public String toString() {
    return "Aluno [nome=" + nome + ", nota1=" + nota1 + ", nota2=" + nota2
        + ", residencia=" + residencia + "]";
  }

}//Aluno.