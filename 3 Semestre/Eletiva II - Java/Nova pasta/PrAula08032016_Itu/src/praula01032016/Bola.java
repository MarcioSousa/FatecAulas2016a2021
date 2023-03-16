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
    
    private int x;
    private int y;
    private int incX=1;
    private int incY=1;
    private int tamanho  = 40;
    private Color cor;
    private boolean cresce = false;

    public boolean isCresce() {
        return cresce;
    }

    public void setCresce(boolean cresce) {
        this.cresce = cresce;
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
    
    public void aumentaTamanho()
    {
       if(cresce)
       {
           tamanho = tamanho + 10;
           cresce = false;
           
           if(tamanho == 100)
               tamanho =10;
       }
    }
    
    
    public void mover()
    {
       x = x + incX;
       y = y + incY;
    }

    public void desenhar(Graphics g) {
        g.setColor(cor);
        g.fillOval(x,y,tamanho,tamanho);
    }

    public void trataColisaoComJanela(int w, int h) {
            
            if( y + tamanho> h )
            {
                cor = Color.YELLOW;
                incY=-1;
            }
            else
               if( y < 20)
               {
                   cor = Color.RED;
                   incY=1;
               }
               
            
            if( x + tamanho > w)
            {
                cor = Color.BLUE;
                incX=-1;
            }
            else
                if( x < 3)
                {
                    cor = Color.ORANGE;
                    incX=1;
                }
    }

}
