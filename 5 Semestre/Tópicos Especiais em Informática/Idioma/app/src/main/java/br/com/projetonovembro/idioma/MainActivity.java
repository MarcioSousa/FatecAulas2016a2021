package br.com.projetonovembro.idioma;

import android.content.Intent;
import android.content.SharedPreferences;
import android.content.res.Configuration;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Toast;

import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        lerIdioma();

        setContentView(R.layout.activity_main);
    }

    @Override
    public void onResume()
    {
        super.onResume();
    }

    @Override
    public void onRestoreInstanceState(Bundle savedInstanceState)
    {
        recreate();
    }

    public void MudarIdioma(View v)
    {
        Intent tela = new Intent(this, frmIdioma.class);
        startActivityForResult( tela, 1 );
    }


    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        try {
            super.onActivityResult(requestCode, resultCode, data);
            //Toast.makeText(getApplicationContext(), "Voltou da tela", Toast.LENGTH_SHORT).show();
            this.setContentView(R.layout.activity_main);
        }
        catch (Exception e)
        {
            Toast.makeText(this, "Erro : " + e.getMessage(), Toast.LENGTH_SHORT).show();
        }
    }


    public void lerIdioma()
    {
        SharedPreferences pref = getSharedPreferences("pref", MODE_PRIVATE);
        String idioma = pref.getString("idioma", "pt");

        Configuration config = getBaseContext().getResources().getConfiguration();
        Locale locale = new Locale(idioma);
        Locale.setDefault(locale);
        config.setLocale(locale);
        getBaseContext().getResources().updateConfiguration(config, getBaseContext().getResources().getDisplayMetrics());

        //setContentView(R.layout.activity_main);
    }

}
