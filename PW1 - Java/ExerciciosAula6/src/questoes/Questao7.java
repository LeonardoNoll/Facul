package questoes;

import java.util.*;
public class Questao7{
 public static void main(String args[]) {
 TreeSet<Number> numeros = new TreeSet<>();
 try {	 
	 numeros.add(5);
	 numeros.add(8);
	 numeros.add(6);
	 numeros.add(null);
 } catch(NullPointerException e) {
	 System.out.println("Erro de inserção: Num inválido " + e.toString());
 }
 for(Number num : numeros)
		 System.out.println("Num: " + num.toString());
 }
}