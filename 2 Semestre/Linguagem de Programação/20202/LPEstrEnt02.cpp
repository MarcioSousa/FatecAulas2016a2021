#include <stdio.h>
#include <locale.h>
#include <string.h>

struct Aluno{
	int matricula;
	char nome[50];
	float nota1;
	float nota2;
	float nota3;
	float media;
};

int main() {
	setlocale(LC_ALL, "Portuguese");
	
	Aluno alunos[5];
	int maiorP1 = 0, maiorMedia=0, menorMedia=0;
	float MaiorPrimNota, MaiorMediaGeral, MenorMediaGeral;
	
	//a - Permita ao usu�rio entrar com os dados de 5 alunos
	printf("==== Cadastro de Alunos.====\n");
	
	for(int t = 0; t < 5; t++){
		printf("Dados do %i� Aluno:\n", t+1);
		printf("Numero de Matr�cula: ");
		scanf("%i", &alunos[t].matricula);
		fflush(stdin);
		printf("Nome do Aluno: ");
		gets(alunos[t].nome);
		fflush(stdin);
		printf("1� Nota: ");
		scanf("%f", &alunos[t].nota1);
		fflush(stdin);
		printf("2� Nota: ");
		scanf("%f", &alunos[t].nota2);
		fflush(stdin);
		printf("3� Nota: ");
		scanf("%f", &alunos[t].nota3);
		fflush(stdin);
		alunos[t].media = (alunos[t].nota1 + alunos[t].nota2 + alunos[t].nota3)/3;
		printf("media %.2f\n", alunos[t].media);
	}
	
	//b - Encontrando o aluno com maior nota da primeira prova
	for(int t = 0; t < 5; t++){
		if(t == 0){
			MaiorPrimNota = alunos[t].nota1;
			maiorP1 = t;
		}else{
			if(MaiorPrimNota < alunos[t].nota1){
				MaiorPrimNota = alunos[t].nota1;
				maiorP1 = t;
			}
		}
	}
	
	for(int t = 0; t < 5; t++){
		if(t == maiorP1){
			printf("Aluno com maior nota na primeira prova �: %s\n", alunos[t].nome);
		}
	}
	
	//c - Encontre o aluno com maior m�dia geral
	for(int t = 0; t < 5; t++){
		if(t == 0){
			MenorMediaGeral = alunos[t].media;
			maiorMedia = t;
		}else{
			if(MenorMediaGeral < alunos[t].media){
				MenorMediaGeral = alunos[t].media;
				maiorMedia = t;
			}
		}
	}
	for(int t = 0; t < 5; t++){
		if(t == maiorMedia){
			printf("Aluno com maior m�dia geral �: %s\n", alunos[t].nome);
		}
	}
	
	//d - Encontre o aluno com menor m�dia geral
	for(int t = 0; t < 5; t++){
		if(t == 0){
			MaiorMediaGeral = alunos[t].media;
			menorMedia = t;
		}else{
			if(MaiorMediaGeral > alunos[t].media){
				MaiorMediaGeral = alunos[t].media;
				menorMedia = t;
			}
		}
	}
	for(int t = 0; t < 5; t++){
		if(t == menorMedia){
			printf("Aluno com menor m�dia geral �: %s\n", alunos[t].nome);
		}
	}
	
	//e - Para cada aluno diga se ele foi aprovado ou reprovado, considerando o valor 6 para aprova��o.
	printf("Aprova��o/Reprova��o\n");
	for(int t = 0; t < 5; t++){
		if(alunos[t].media > 6){
			printf("Aluno Matricula %i: %s\n", alunos[t].matricula, "Aprovado");
		}else{
			printf("Aluno Matricula %i: %s\n", alunos[t].matricula, "Reprovado");
		}
	}
	
    return 0;
}
