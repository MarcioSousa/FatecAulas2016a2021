#include <stdio.h>
#define MAX_STRING 100

int conta_ocorrencias(char str1[MAX_STRING], char str2[MAX_STRING]);

int main(){
    char texto[MAX_STRING], palavra[MAX_STRING];


    printf("Digite um texto: \n");
    scanf(" %[^\n]", texto); /* Le uma string terminada por enter */

    printf("Digite uma palavra: \n");
    scanf(" %[^\n]", palavra);
    printf("O texto contem %d ocorrências da palavra \"%s\".", conta_ocorrencias(texto, palavra), palavra);
    return 0;
}


int conta_ocorrencias(char str1[MAX_STRING], char str2[MAX_STRING]){
    int cont = 0, i = 0, j = 0;

    while (str1[i] != '\0') {

        while (str1[i+j] != '\0' && str2[j] != '\0' && str1[i+j] == str2[j])
            j++;
        if (str2[j] == '\0')
            cont++;
        j = 0;
        i++;
    }

    return cont;
}
