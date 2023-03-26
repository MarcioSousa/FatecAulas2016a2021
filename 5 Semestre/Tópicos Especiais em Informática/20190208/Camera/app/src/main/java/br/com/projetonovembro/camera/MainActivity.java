package br.com.projetonovembro.camera;

import android.content.Intent;
import android.graphics.Bitmap;
import android.provider.MediaStore;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {
    static final int REQUEST_IMAGE_CAPTURE = 1;
    //ImageView imagem = (ImageView) findViewById(R.id.imgFoto);

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }


    public void camera(View v)
    {
        Intent foto = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        if(foto.resolveActivity(getPackageManager()) != null)
        {
            startActivityForResult(foto, REQUEST_IMAGE_CAPTURE);
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        if(requestCode == REQUEST_IMAGE_CAPTURE && resultCode == RESULT_OK)
        {
            ImageView imagem = (ImageView) findViewById(R.id.imgFoto);

            Bundle extras = data.getExtras();
            Bitmap imagemRec = (Bitmap) extras.get("data");
            imagem.setImageBitmap(imagemRec);
        }
    }
}
