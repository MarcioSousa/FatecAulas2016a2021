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
 * @author professor
 */
public abstract class Elemento {
    protected int x;
    protected int y;
    protected int incX=1;
    protected int incY=1;
    private int tamanho  = 40;
    protected Color cor;

    public abstract void desenhar(Graphics g);
    
    
    public boolean colisaoComElemento(Elemento elemento)
    {
        
        if(this.equals(elemento))
            return false;
        
        
        
        if( x + getTamanho()>= elemento.getX()                 &&   
            x           <  elemento.getX() + elemento.getTamanho() &&
            y + getTamanho() >= elemento.getY()                 &&
            y           <= elemento.getY() + elemento.getTamanho()
           )
            
            return true;
        else
            return false;
    
    }
    
    public void trataColisaoComJanela(int w, int h) {
            
            if( y + getTamanho()> h )
            {
                incY=-1;
            }
            else
               if( y < 20)
               {
                   incY=1;
               }
               
            
            if( x + getTamanho() > w)
            {
                incX=-1;
            }
            else
                if( x < 0)
                {
                    incX=1;
                }
    }
    
    
     public void mover()
    {
       x = x + incX;
       y = y + incY;
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

    public int getIncX() {
        return incX;
    }

    public void setIncX(int incX) {
        this.incX = incX;
    }

    public int getIncY() {
        return incY;
    }

    public void setIncY(int incY) {
        this.incY = incY;
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
