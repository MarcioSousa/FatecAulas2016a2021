package br.com.arkasis.tela;

import android.content.Intent;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.TextView;
import android.widget.Toast;

public class SobreActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sobre);

        Intent intent = getIntent();
        Bundle dados = new Bundle();

        dados = intent.getExtras();
        String nome = dados.getString("nome").toString();
        String email = dados.getString("email").toString();
        int curso = dados.getInt("curso");
        String site = dados.getString("site").toString();

        TextView tNome = (TextView) findViewById(R.id.txtNome);
        tNome.setText( nome );
        TextView tMail = (TextView) findViewById(R.id.txtMail);
        tMail.setText( email );
        TextView tCurso = (TextView) findViewById(R.id.txtCurso);
        tCurso.setText( String.valueOf( curso ) );
        TextView tSite = (TextView) findViewById(R.id.txtSite);
        tSite.setText( site );

    }

    public void fechar(View v)
    {
        Intent intent = new Intent();
        intent.putExtra("texto", "Olá Mundo");
        setResult(RESULT_OK, intent);
        finish();
    }
}
