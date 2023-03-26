package com.example.aluno_gti_ads.projetofaculdade;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void abrirCadastro(View v){
        Intent tela = new Intent(this, CadastroActivity.class);
        startActivity(tela);
    }
}
