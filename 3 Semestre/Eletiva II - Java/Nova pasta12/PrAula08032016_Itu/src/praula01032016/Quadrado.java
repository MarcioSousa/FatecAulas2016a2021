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
    
    private int x=200;
    private  int y=50;
    private  int incX=0;
    private  int incY=1;
    private int tamanho  = 80;
    private  Color cor;
    
    
    public void mover()
    {
       x = x + incX;
       y = y + incY;
    }

    public void desenhar(Graphics g) {
        g.setColor(cor);
        g.fillRect(x,y,tamanho,tamanho);
    }
    
    
    public boolean colisaoComBola(Bola bola)
    {
        if( x + tamanho >= bola.getX()                 &&   
            x           <  bola.getX() + bola.getTamanho() &&
            y + tamanho >= bola.getY()                 &&
            y           <= bola.getY() + bola.getTamanho()
           )
            
            return true;
        else
            return false;
    
    }

    public void trataColisaoComJanela(int width, int height) {
            
            if( y + tamanho > height)
            {
                incY=-1;
            }
            else
                if( y < 20)
                {
                    incY=1;
                }
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getTamanho() {
        return tamanho;
    }

    public void setTamanho(int tamanho) {
        this.tamanho = tamanho;
    }

    public Color getCor() {
        return cor;
    }

    public void setCor(Color cor) {
        this.cor = cor;
    }
            
    
    
    
    
    
    
    
    
    
}







