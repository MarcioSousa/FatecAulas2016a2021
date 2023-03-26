package br.com.arkasis.webservice;

import android.os.AsyncTask;

import org.ksoap2.serialization.PropertyInfo;
import org.ksoap2.serialization.SoapObject;
import org.ksoap2.serialization.SoapSerializationEnvelope;
import org.ksoap2.transport.HttpTransportSE;

import java.util.Vector;

/**
 * Created by android on 11/11/2017.
 */

public class EnviarUsuarioTask extends AsyncTask<Void, Void, Boolean> {
    private String login;
    private String senha;

    private String[] mResponse;
    private EnviarUsuarioTask.OnReturnServiceArrayStrings mListener;


    public EnviarUsuarioTask(String login, String senha, EnviarUsuarioTask.OnReturnServiceArrayStrings mListener) {
        this.login = login;
        this.senha = senha;

        this.mListener = mListener;
    }

    @Override
    protected void onPreExecute() {
        super.onPreExecute();
    }

    @Override
    protected Boolean doInBackground(Void... params) {
        final String METHOD_NAME = "cadastro";
        final String SOAP_ACTION = "http://www.arkau.com.br/webservice/cadastro";
        final String NAMESPACE = "http://www.arkau.com.br/webservice/";
        final String URL = "http://www.arkau.com.br/webservice/usuario.php";

        try {

            SoapObject request = new SoapObject(NAMESPACE, METHOD_NAME);

            PropertyInfo varLogin = new PropertyInfo();
            varLogin.setName("login");
            varLogin.setValue(login);
            varLogin.setType(String.class);
            request.addProperty(varLogin);

            PropertyInfo varSenha = new PropertyInfo();
            varSenha.setName("senha");
            varSenha.setValue(senha);
            varSenha.setType(String.class);
            request.addProperty(varSenha);

            SoapSerializationEnvelope envelope = new SoapSerializationEnvelope(SoapEnvelope.VER11);
            envelope.setOutputSoapObject(request);

            HttpTransportSE httpTransport = new HttpTransportSE(URL);
            httpTransport.call(SOAP_ACTION, envelope);

            Vector response = (Vector) envelope.getResponse();

            mResponse = new String[response.size()];

            for (int i = 0; i < response.size(); i++) {
                mResponse[i] = response.get(i).toString();
            }

            return true;
        } catch (Exception e) {
            e.printStackTrace();
        }
        return false;
    }

    protected void onPostExecute(Boolean sucess) {
        if (mListener != null) {
            if (sucess) mListener.onCompletion(mResponse);
            else mListener.onError();
        }
    }

    public interface OnReturnServiceArrayStrings {
        public void onCompletion(String[] response);

        public void onError();
    }

}