/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package praula01032016;

import java.awt.Color;
import java.awt.Graphics;

/**
 *
 * @author Abutua
 */
public class Quadrado {
    
    int x=200;
    int y=50;
    int incX=0;
    int incY=1;
    int tamanho  = 200;
    Color cor;
    
    
    void mover()
    {
       x = x + incX;
       y = y + incY;
    }

    void desenhar(Graphics g) {
        g.setColor(cor);
        g.fillRect(x,y,tamanho,tamanho);
    }
    
    
    boolean colisao(Bola bola)
    {
        if( x + tamanho >= bola.x                 &&   
            x           <  bola.x + bola.tamanho  &&
            y + tamanho >= bola.y                 &&
            y           <= bola.y + bola.tamanho    
           )
            
            return true;
        else
            return false;
    
    }
            
    
    
    
    
    
    
    
    
    
}







