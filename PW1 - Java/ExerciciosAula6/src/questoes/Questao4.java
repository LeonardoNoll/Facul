package questoes;

 public class Questao4 {
 public static void main(String[] args) {
 try {
 int i = (int) Math.random();
 System.out.println(i);
 int j = 10 / i;
 }catch (ArithmeticException e) {
 e.printStackTrace();
 }
 }
}