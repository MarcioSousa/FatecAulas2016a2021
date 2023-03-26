package br.com.arkasis.tela;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void telaSobre(View v)
    {
        Intent tela = new Intent(this, SobreActivity.class);

        Bundle dados = new Bundle();
        dados.putString("nome", "");
        dados.putString("email", "");
        dados.putInt("curso", 10);
        dados.putString("site", "");
        tela.putExtras(dados);

        startActivityForResult(tela, 1);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);
        if(requestCode == 1 && resultCode == RESULT_OK)
        {
            String texto = data.getStringExtra("texto");
        }
    }
}