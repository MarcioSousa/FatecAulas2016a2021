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
public class Bola {
    
    int x;
    int y;
    int incX=1;
    int incY=1;
    int tamanho  = 40;
    Color cor;
    
    
    void mover()
    {
       x = x + incX;
       y = y + incY;
    }

    void desenhar(Graphics g) {
        g.setColor(cor);
        g.fillOval(x,y,tamanho,tamanho);
    }
    
    
}
