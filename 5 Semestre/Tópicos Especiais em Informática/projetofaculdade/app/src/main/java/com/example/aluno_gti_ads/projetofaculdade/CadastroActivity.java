package com.example.aluno_gti_ads.projetofaculdade;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;

public class CadastroActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_cadastro);

        EditText eMail = (EditText) findViewById(R.id.edtMail);
        SharedPreferences dados = getSharedPreferences("fatec",MODE_PRIVATE);
        String varMail = dados.getString("mail","");
        eMail.setText(varMail.toString());
    }
    public void gravar(View v){
        EditText eMail = (EditText) findViewById(R.id.edtMail);

        SharedPreferences.Editor dados = getSharedPreferences("fatec",MODE_PRIVATE).edit();
        dados.putString("mail", edtMail.getText().toString());

        if(dados.commit()){
            finish();
        }else{
            Toast.makeText(this, "Não foi gravado!", Toast.LENGTH_SHORT).show();
        }
    }
}
