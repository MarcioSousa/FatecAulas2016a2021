package br.com.arkasis.webservice;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

public class UsuarioActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_usuario);
    }

    public void enviarDados(View v)
    {
        EditText login = (EditText) findViewById(R.id.edtLogin);
        EditText senha = (EditText) findViewById(R.id.edtSenha);

        soapService(login.getText().toString(), senha.getText().toString());
    }

    private void soapService(String login, String senha)
    {
        new EnviarUsuarioTask(login, senha, new EnviarUsuarioTask.OnReturnServiceArrayStrings() {
            @Override
            public void onCompletion(String[] response) {
                setupList(response);
            }

            @Override
            public void onError() {
                //Toast.makeText(getBaseContext(), "Ocorreu um erro.", Toast.LENGTH_SHORT).show();
            }
        }).execute();
    }

    private void setupList(String[] list) {
        String retorno = list[0];

        if( retorno.toString().equals( "OK" ) )
        {

        }
        else
        {

        }
    }
}
