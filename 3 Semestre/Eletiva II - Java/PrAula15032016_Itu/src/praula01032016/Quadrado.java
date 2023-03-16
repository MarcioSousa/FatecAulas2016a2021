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
public class Quadrado extends Elemento{
    
    
    public void desenhar(Graphics g) {
        g.setColor(cor);
        g.fillRect(x,y,getTamanho(),getTamanho());
    }
    
    
}







