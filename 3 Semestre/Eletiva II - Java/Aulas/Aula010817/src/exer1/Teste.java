/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package exer1;

/**
 *
 * @author Aluno - Gti-Ads
 */
public class Teste {
    
    public static void main(String[] args) {
        
        Computador c1, c2, c3, c4;
        
        c1 = new Computador();
        c3 = c1;
        c2 = new Computador();
        c3 = c1;
        c1 = new Computador();
        c4 = c1;
        c1 = new Computador();
        
                
        System.out.println(c1);
        System.out.println(c2);
        System.out.println(c3);
        System.out.println(c4);
    }
    
}
