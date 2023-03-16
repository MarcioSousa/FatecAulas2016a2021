package managedbean;

import java.util.ArrayList;

import javax.faces.bean.ManagedBean;
import javax.faces.bean.SessionScoped;

import entidades.Aluno;

@ManagedBean
@SessionScoped
public class AlunoMB {
	private Aluno aluno = new Aluno();
    private ArrayList<Aluno> listaAlunos = new ArrayList<Aluno>();

    public Aluno getAluno() {
		return aluno;
	}

	public void setAluno(Aluno aluno) {
		this.aluno = aluno;
	}

	public ArrayList<Aluno> getListaAlunos() {
		return listaAlunos;
	}

	public void setListaAlunos(ArrayList<Aluno> listaAlunos) {
		this.listaAlunos = listaAlunos;
	}
	
	public void salvar(){
		listaAlunos.add(aluno);
		aluno = new Aluno();
	}
	
	
	
	
	
	
	

}
