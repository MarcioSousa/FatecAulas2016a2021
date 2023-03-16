#include <stdio.h>
#include <locale.h>
#include <string.h>

struct time{
	int hora;
	int min;
	int seg;
};

void ConverteHoras();
void ConverterHoraMinSeg();

int main() {
	setlocale(LC_ALL, "Portuguese");

	int escolha;
	
	printf("=== Escolha uma das opções 1, 2 ou 3. ===\n");
	printf("1 - Converter Segundos em hora, min, seg.\n");
	printf("2 - Converter Tempo em Segundos.\n");
	scanf("%i", &escolha);
	
	if(escolha ==1){
		ConverteHoras();
	}else if(escolha == 2){
		ConverterHoraMinSeg();
	}else{
		printf("Escolha não encontrada.\n");
	}
	
    return 0;
}

void ConverteHoras(){
	time tempo;
	int segundos;
	
	printf("Digite os segundos: ");
	scanf("%i", &segundos);
	
	tempo.hora = segundos/3600;
	tempo.min = (segundos - (3600*tempo.hora))/60;
	tempo.seg = segundos - ((tempo.hora*3600) + (tempo.min*60));
	
	printf("Hora(s): %i\n", tempo.hora);
	printf("Minuto(s): %i\n", tempo.min);
	printf("Segundo(s): %i\n", tempo.seg);
	
}

void ConverterHoraMinSeg(){
	time tempo;
	int segundos;
	
	printf("Digite:\nHora: ");
	scanf("%i", &tempo.hora);
	printf("Minuto: ");
	scanf("%i", &tempo.min);
	printf("Segundo: ");
	scanf("%i", &tempo.seg);
	
	segundos = tempo.hora * 3600 + tempo.min * 60 + tempo.seg;
	
	printf("Total de Segundo(s): %i\n", segundos);
	
}
