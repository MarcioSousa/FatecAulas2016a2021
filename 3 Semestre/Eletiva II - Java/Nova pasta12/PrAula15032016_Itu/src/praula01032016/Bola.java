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
public class Bola extends Elemento{
    
    private boolean cresce = false;

    public boolean isCresce() {
        return cresce;
    }

    public void setCresce(boolean cresce) {
        this.cresce = cresce;
    }
    
    public void aumentaTamanho()
    {
       if(cresce)
       {
           setTamanho(getTamanho() + 10);
           cresce = false;
           
           if(getTamanho() == 100)
               setTamanho(10);
       }
    }
    
    
   

    public void desenhar(Graphics g) {
        g.setColor(cor);
        g.fillOval(x,y,getTamanho(),getTamanho());
    }

    

}
