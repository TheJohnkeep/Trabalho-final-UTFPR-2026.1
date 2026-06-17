


#include <stdio.h>
#include <math.h>
#define MAX 20

float somaVetor(float v[], int *n);
float mediaVetor(float v[], int *n);
float varianciaVetor(float v[], int *n);
float desvioVetor(float v[], int *n);
float medianaVetor(float v[], int *n);
float produtoVetor(float v[], int *n);

void lerVetor(float v[], int *n){
    
    int i;
   
   
        printf("Quantos elementos?");
        scanf("%d", n);
        
        while(*n>MAX || *n<2){
            printf("Digite novamente quantos elementos (entre 2 e 20): ");
            scanf("%d", n);
        }
        
        

for(i = 0; i < *n; i++){
    printf("Elemento [%d]:  " , i);
    scanf("%f", &v[i]);
      
    
}

}
void exibirVetor(float v[], int *n){
   
    
    int i = 0;
   printf("Vetor:");
    while(i  < *n){
 
   printf(" %.2f", v[i]);
    i++;
    
    }
    printf("\n");
     float variancia =  varianciaVetor(v, n);
    float desvio = desvioVetor(v, n);
    float soma = somaVetor(v, n);
    float media = mediaVetor(v, n);
    float mediana = medianaVetor(v, n);
    float produto = produtoVetor(v, n);
    
    printf("Soma: %.2f", soma);
    printf("\n");
    printf("Produto:  %.2f", produto);
    printf("\n");
    printf("Média:  %.2f", media);
     printf("\n");
    printf("Variância:  %.2f", variancia);
    printf("\n");
    printf("Desvio Padrão: %.2f ", desvio);
    printf("\n");
    printf("Mediana:  %.2f", mediana);
printf("\n");
    
    
}
float somaVetor(float v[], int *n){
    
        
    float soma;
    
    int i = 0;
    soma = 0.0;
    
     
    while(i  < *n){
    soma = soma + v[i];
    i++;
    }
    
    return soma;

    
}
float mediaVetor(float v[], int *n){

    float soma = somaVetor(v, n);
    
    
    float media = soma / *n;
     
    
    
    return media;
  
    
}
float varianciaVetor(float v[], int *n){
    
   
    float variancia;
    float variancia1 = 0;
    float variancia2 = 0;
    float media = mediaVetor(v, n);

    for(int i = 0; i < *n; i++){
        
        variancia2 = (v[i] - media) * (v[i] - media);
        variancia1 = variancia2 + variancia1;
        
    }
    
    variancia = variancia1 / (*n - 1);

    return variancia;
    
    
} 
float desvioVetor(float v[], int *n){

    float variancia = varianciaVetor(v, n);
    
    float desviopadrao;
    
    desviopadrao = sqrt(variancia);

    return desviopadrao;
    }

float medianaVetor(float v[], int *n){
    
    float mediana;
    float k;
  
    int i, j;
    
  
    
    for (i = 0; i < *n - 1; i++) {
        for (j = 0; j < *n - i - 1; j++) {
            if ( v[i] >  v[j + 1]) {
                k =  v[i];
                v[i] =  v[j + 1];
                v[j + 1] = k;
            }
        }
    }
    
   
    if(*n % 2 == 0){
        mediana = (v[*n / 2] + v[(*n / 2) - 1]) / 2;
    }
    else{
       mediana = v[*n / 2];
    }
    return mediana;
    
}




void minMaxVetor(float v[], int *n, float min, float max){
    
    int i; 
        
    int posicao;
    float confirmacao;
    max = v[0];

    for(i = 1; i < *n; i++){
        if(max < v[i]){
            max = v[i];
        }
    }
    
    min = v[0];

    for(i = 1; i < *n; i++){
        if(min > v[i]){
            min = v[i];
        }
    }
           
            
            
            
            
 printf("Maior valor: %f", max);
 printf("\n");
 printf("Menor valor: %f", min);
    
}

float produtoVetor(float v[], int *n){
    
    float produto = 1;
    
    for(int i = 0; i < *n; i++){
        produto = v[i] * produto;
    }
    
    return produto;
}



int main(){
    float v[MAX];
    int n;
    float min, max;
    
 lerVetor(v,  &n);
 exibirVetor( v, &n);
 minMaxVetor( v,  &n,  min,  max);

}

