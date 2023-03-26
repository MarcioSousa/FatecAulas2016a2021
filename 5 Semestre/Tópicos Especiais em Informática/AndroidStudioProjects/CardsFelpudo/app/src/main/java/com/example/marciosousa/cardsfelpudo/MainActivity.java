package com.example.marciosousa.cardsfelpudo;

import android.annotation.NonNull;
import android.annotation.Nullable;
import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
    String[] listaNomes = {"Felpudo", "Fofura","Lesmo","Bugado","Uruca","Racing","iOS","Android","RealidadeAumentada","Sound FX","3D Studio Max","Games"};

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ListView minhaLista = findViewById(R.id.minhaLista);

        MeuAdaptador meuAdaptador;
        meuAdaptador = new MeuAdaptador(getApplicationContext(), R.layout.minha_celula);

        int i = 0;

        for(int t = 0; t < listaNomes.length; t++){
            DadosPersonagem dadosPersonagem = new DadosPersonagem(2,"Teste", "okay");
            meuAdaptador.add(dadosPersonagem);
        }

        minhaLista.setAdapter(meuAdaptador);

    }

}

class ViewPersonagem{
    ImageView icone;
    TextView titulo;
    TextView descricao;
}

class DadosPersonagem{
    private int icone;
    private String titulo;
    private  String descricao;

    public String getDescricao() {
        return descricao;
    }

    public String getTitulo() {
        return titulo;
    }

    public int getIcone() {
        return icone;
    }

    public DadosPersonagem(int icone, String titulo, String descricao) {
        this.icone = icone;
        this.titulo = titulo;
        this.descricao = descricao;
    }

}

class MeuAdaptador extends ArrayAdapter{
    public MeuAdaptador(@NonNull Context context, int resource) {
        super(context, resource);
    }

    @Override
    public void add(@Nullable Object object) {
        super.add(object);
    }

    @Override
    public int getCount() {
        return super.getCount();
    }

    @Override
    public View getView(int position, @Nullable View convertView, @NonNull ViewGroup parent) {

        View minhaView;
        minhaView = convertView;
        ViewPersonagem viewPersonagem;

        if(convertView == null){
            LayoutInflater inflater = (LayoutInflater) this.getContext().getSystemService(Context.LAYOUT_INFLATER_SERVICE);
            minhaView = inflater.inflate(R.layout.minha_celula,parent,false);

            viewPersonagem = new ViewPersonagem();
            viewPersonagem.icone = (ImageView) minhaView.findViewById(R.id.meuIcone);
            viewPersonagem.titulo = (TextView) minhaView.findViewById(R.id.meuTitulo);
            viewPersonagem.descricao = (TextView) minhaView.findViewById(R.id.meuDescricao);

            minhaView.setTag(viewPersonagem);
        }else{
            viewPersonagem = (ViewPersonagem) minhaView.getTag();
        }

        DadosPersonagem dadosPersonagem;
        dadosPersonagem = (DadosPersonagem)this.getItem(position);

        viewPersonagem.icone.setImageResource(dadosPersonagem.getIcone());
        viewPersonagem.titulo.setText(dadosPersonagem.getTitulo());
        viewPersonagem.descricao.setText(dadosPersonagem.getDescricao());

        return minhaView;
    }
}



















