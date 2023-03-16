/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package praula01032016;

/**
 *
 * @author Abutua
 */
public class PrAula23022016 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       
        Bola b1 = new Bola();
        Bola b2 = new Bola();
        
        b1.x = 50;
        b1.y = 30;
        
        for(int i=0; i < 10; i++)
        {
            b1.mover();
            b2.mover();
            System.out.println(b1.x);
            System.out.println(b1.y);
            System.out.println(b2.x);
            System.out.println(b2.y);
        }
        
        
        
       
    }
    
}
