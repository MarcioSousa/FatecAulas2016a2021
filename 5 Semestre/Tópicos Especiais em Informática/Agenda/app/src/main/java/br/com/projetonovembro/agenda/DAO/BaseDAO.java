package br.com.projetonovembro.agenda.DAO;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

/**
 * Created by joseg_000 on 09/04/2016.
 */
public class BaseDAO extends SQLiteOpenHelper{
    public static final String TBL_AGENDA = "agenda";
    public static final String AGENDA_ID = "_id";
    public static final String AGENDA_NOME = "nome";
    public static final String AGENDA_ENDERECO = "endereco";
    public static final String AGENDA_TELEFONE = "telefone";

    private static final String DATABASE_NAME = "agenda.db";
    private static final int DATABASE_VERSION = 1;

    //Estrutura da tabela Agenda (sql statement)
    private static final String CREATE_AGENDA = "create table " +
            TBL_AGENDA + "( " + AGENDA_ID       + " integer primary key autoincrement, " +
            AGENDA_NOME     + " text not null, " +
            AGENDA_ENDERECO + " text not null, " +
            AGENDA_TELEFONE + " text not null);";

    public BaseDAO(Context context){
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }


    @Override
    public void onCreate(SQLiteDatabase db) {
        //Criação da tabela
        db.execSQL(CREATE_AGENDA);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        //Caso seja necessário mudar a estrutura da tabela
        //deverá primeiro excluir a tabela e depois recriá-la
        db.execSQL("DROP TABLE IF EXISTS " + TBL_AGENDA);
        onCreate(db);
    }
}
