package com.example.aluno_gti_ads.jogovelha;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends Activity {
    String jogador = "X";

    Button botao11 = (Button) findViewById(R.id.btn11);
    Button botao12 = (Button) findViewById(R.id.btn12);
    Button botao13 = (Button) findViewById(R.id.btn13);
    Button botao21 = (Button) findViewById(R.id.btn21);
    Button botao22 = (Button) findViewById(R.id.btn22);
    Button botao23 = (Button) findViewById(R.id.btn23);
    Button botao31 = (Button) findViewById(R.id.btn31);
    Button botao32 = (Button) findViewById(R.id.btn32);
    Button botao33 = (Button) findViewById(R.id.btn33);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void escolha(View v){
        Button botao = (Button) findViewById(v.getId());

        if(botao.getText().toString() == "") {
            botao.setText(jogador);

            if (jogador == "X") {
                jogador = "O";
            } else {
                jogador = "X";
            }
        }

        //Toast.makeText(this, "Jogador " + jogador + " Ganhou", Toast.LENGTH_SHORT).show();
        
    }

    public void novo(View v){
        Button botao11 = (Button) findViewById(R.id.btn11);
        Button botao12 = (Button) findViewById(R.id.btn12);
        Button botao13 = (Button) findViewById(R.id.btn13);
        Button botao21 = (Button) findViewById(R.id.btn21);
        Button botao22 = (Button) findViewById(R.id.btn22);
        Button botao23 = (Button) findViewById(R.id.btn23);
        Button botao31 = (Button) findViewById(R.id.btn31);
        Button botao32 = (Button) findViewById(R.id.btn32);
        Button botao33 = (Button) findViewById(R.id.btn33);
    }

    public void verifica(){
        btn11 = botao11.getText().toString();
        btn12 = botao12.getText().toString();
        btn13 = botao13.getText().toString();
        btn21 = botao21.getText().toString();
        btn22 = botap22.getText().toString();
        btn23 = botao23.getText().toString();
        btn31 = botao31.getText().toString();
        btn32 = botao32.getText().toString();
        btn33 = botao33.getText().toString();
    }

    public void finaliza(){

    }

    public void ganhou(){

    }


}
