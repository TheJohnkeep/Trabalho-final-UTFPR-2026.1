


#include <stdio.h>
#include <math.h>
#define MAX 20

void lerVetor(float v[], int *n){
    
    int i;
   
   
        printf("Quantos elementos?");
        scanf("%d", n);
        
        while(*n>MAX || *n<2){
            printf("Digite novamente quantos elementos (entre 2 e 20): ");
            scanf("%d", n);
        }
        
        

for(i = 0; i < *n; i++){
    printf("Elemento [%d]: " , i);
    scanf("%f", &v[i]);
    
}

}
void exibirVetor(float v[], int *n){
    

    int i = 0;
   printf("Vetor:");
    while(i  < *n){
 
   printf(" %3.f", v[i]);
    i++;
    
    }
    printf("\n");
    
   

    
    
}
float somaVetor(float v[], int *n){
    
        
    float soma;
    
    int i = 0;
    soma = 0;
    
     
    while(i  < *n){
    soma = soma + v[i];
    i++;
    }
    printf("Soma: %2.f \n", soma);
    
    float produto;
    
     i = 0;
    produto = 1;
    
     
    while(i  < *n){
    produto = produto * v[i];
    i++;
   

    }
    printf("\n");
    printf("Produto: %2f \n", produto);
    
    return soma;

    
}
float mediaVetor(float v[], int *n){
    
    int i;
    float soma;
     soma = 0;
    
     
    while(i  < *n){
    soma = soma + v[i];
    i++;
    }
        
    float media;
    
    media = soma / *n;
    
    printf("Media: %f \n" , media);
    
    
    
    return media;
  
    
}
float varianciaVetor(float v[], int *n){
      float variancia;
    float variancia1 = 0;
    float variancia2;
    
   int i;
    float soma;
     soma = 0;
    
     
    while(i  < *n){
    soma = soma + v[i];
    i++;
    }
        
    float media;
    
    media = soma / *n;
    
    
    for(int i = 0; i < *n; i++){
        
        variancia2 = (v[i] - media) * (v[i] - media);
        variancia1 = variancia2 + variancia1;
        
    }
    
    variancia = variancia1 / (*n - 1);
    
    printf("Variância: %f \n", variancia);
    
    
}
float desvioVetor(float v[], int *n){
        float variancia;
    float variancia1 = 0;
    float variancia2;
    
   int i;
    float soma;
     soma = 0;
    
     
    while(i  < *n){
    soma = soma + v[i];
    i++;
    }
        
    float media;
    
    media = soma / *n;
    
    
    for(int i = 0; i < *n; i++){
        
        variancia2 = (v[i] - media) * (v[i] - media);
        variancia1 = variancia2 + variancia1;
        
    }
    
    variancia = variancia1 / (*n - 1);
    
        
    variancia  = varianciaVetor( v,  n);
        
    float desviopadrao;
    
    desviopadrao = sqrt(variancia);
    
    printf("Desvio padrão: %f \n", desviopadrao);
    
}
float medianaVetor(float v[], int *n){
     float mediana;
    float temp;
    int j;
    for (j = 0; j < *n - 1; j++) {
        
        if (v[j] > v[j + 1]) {
            temp = v[j];
            v[j] = v[j + 1];
            v[j + 1] = temp;
        }
    }
    if(*n%2 == 0){
        mediana = (v[((int)*n/2)]  + v[((int)(*n/2 - 1))])/2;
        printf("Mediana: %f", mediana);
    }
    else{
       mediana = v[((int)*n/2)];
       printf("Mediana: %f", mediana);
    }
    
    return mediana;
    
}
void minMaxVetor(float v[], int *n, float *min, float *max){
    
        int i; 
        
        int posicao;
    float confirmacao;
    *max = v[0];

    for(i = 1; i < *n; i++){
        if(*max < v[i]){
            *max = v[i];
        }
    }
    
    *min = v[0];

    for(i = 1; i < *n; i++){
        if(*min > v[i]){
            *min = v[i];
        }
    }
           
            
            
            
            
 printf("O menor valor é: %f e o Maior valor é: %f ", min, max);
    
}



int main()
{
    float v[MAX];
    int n;
    float min, max;
    
 lerVetor(v,  &n);
 exibirVetor( v, &n);
 somaVetor( v,  &n);
 mediaVetor( v, &n);
 varianciaVetor( v,  &n);
 desvioVetor( v,  &n);
 medianaVetor( v,  &n);
 minMaxVetor( v,  &n,  &min,  &max);

}

