/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fatec.poo.model;

/**
 *
 * @author Aluno - Gti-Ads
 */
public class VagaEstacionamento {
    private int identificacao;
    private boolean estado;
    private int horaEntrada;
    private double faturamento;
    
    public boolean getEstado(){
        return estado;
    }
    public double getFaturamento(){
        return faturamento;
    }
    public VagaEstacionamento(int identif){
        identificacao = identif;
    }
    public void ocupar(int horaEntr){
        horaEntrada = horaEntr;
        estado = true;
    }
    public double liberar(int horaSaida){
        estado = false;
        
        if(horaSaida > horaEntrada){
            faturamento = (((horaSaida - horaEntrada)* 0.6)/ 20)* 1.5; 
        }else{
            faturamento = ((((2400 - horaEntrada) + horaSaida)* 0.6)/ 20)* 1.5;
        }

        return faturamento;
    }
}
