#include <stdio.h>
#include <stdlib.h>

#define tam_bucket 100
#define num_bucket 10
#define max 10


typedef struct {
         int topo;
         int balde[tam_bucket];
 }bucket;
 
void bucket_sort(int v[],int tam);                   //cabe�alho das fun��es
void bubble(int v[],int tam);   
int valor[20] = {11,30,3,4,49,50,1,2,4,3,1,2,3,4,50,15,16,18,19,20};

main(){
	
	bucket_sort(valor, 20);
	
	for(int t = 0; t<20; t++){
		printf("%i ",valor[t]);
	}
	
}

 void bucket_sort(int v[],int tam){                                     
         bucket b[num_bucket];                                      
         int i,j,k;
		                                                  
 /* 1 */ for(i=0;i<num_bucket;i++)                    //inicializa todos os "topo"
                 b[i].topo=0;
         
 /* 2 */ for(i=0;i<tam;i++){                          //verifica em que balde o elemento deve ficar
                 j=(num_bucket)-1;
                 while(1){
                         if(j<0)
                                 break;
                         if(v[i]>=j*10){
                                 b[j].balde[b[j].topo]=v[i];
                                 (b[j].topo)++;
                                 break;
                         }
                         j--;
                         
                 }
         }
         
 /* 3 */ for(i=0;i<num_bucket;i++)                     //ordena os baldes
                 if(b[i].topo)
                         bubble(b[i].balde,b[i].topo);
         
         i=0;
 /* 4 */ for(j=0;j<num_bucket;j++){                    //p�e os elementos dos baldes de volta no vetor
                 for(k=0;k<b[j].topo;k++){
                         v[i]=b[j].balde[k];
                         i++;
                 }
         }
 }
 
 void bubble(int v[],int tam){
         int i,j,temp,flag;
         if(tam)
                 for(j=0;j<tam-1;j++){
                         flag=0;
                         for(i=0;i<tam-1;i++){
                                 if(v[i+1]<v[i]){
                                         temp=v[i];
                                         v[i]=v[i+1];
                                         v[i+1]=temp;
                                         flag=1;
                                 }
                         }
                         if(!flag)
                                 break;
                 }
 }

