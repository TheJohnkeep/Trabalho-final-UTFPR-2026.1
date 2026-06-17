#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX 20
#define DIM 10
//----------------------Protótipos---------------------------//

//--------------------------MENU--------------------------//

void MenuSelect();


//--------------------------MODULO 1--------------------------//

void lerVetor(float v[], int *n);
void exibirVetor(float v[], int n);
float somaVetor(float v[], int n);
float mediaVetor(float v[], int n);
float varianciaVetor(float v[], int n);
float desvioVetor(float v[], int n);
float medianaVetor(float v[], int n); 
void minMaxVetor(float v[], int n, float *min, float *max);

//--------------------------MODULO 2--------------------------//



//--------------------------MODULO 3--------------------------//



//--------------------------MODULO 4--------------------------//

void lerMatriz(float m[][DIM], int *lin, int *col);
void exibirMatriz(float m[][DIM], int lin, int col);
void transporMatriz(float m[][DIM], float t[][DIM], int lin, int col);
void somarMatrizes(float a[][DIM], float b[][DIM],
float c[][DIM], int lin, int col);
void multiplicarMatrizes(float a[][DIM], float b[][DIM],
float c[][DIM], int lA, int cA, int cB);
float tracoMatriz(float m[][DIM], int n);
int isSimetrica(float m[][DIM], int n);

//---------------------------MAIN----------------------------//

int main()
{
MenuSelect();

//--------------------------VARIAVEIS--------------------------//

int Choice;
scanf("%d",&Choice);
        
float v[MAX], min, max;
int n;

float m[DIM][DIM];
float t[DIM][DIM];
float a[DIM][DIM];
float b[DIM][DIM];
float c[DIM][DIM];

int lin, col;
int lA, cA, cB;

//--------------------------ESCOLHAS--------------------------//

        switch(Choice){
                    case 1: printf("1-Estatísticas de um vetor selecionado");
                    
                             lerVetor(v,  &n);
                             exibirVetor( v, n);
                             minMaxVetor( v,  n,  &min,  &max);
           
            break;
                    case 2:
            printf("2-Verificações e Classificações");
            break;
                    case 3:
            printf("3-Sequências Matemáticas");
                        break;
                    case 4: printf("4-Operações com Matrizes");
                    
                            lerMatriz(m, &lin, &col);
                            exibirMatriz( m, lin, col);
                            transporMatriz( m, t,  lin,  col);
                            somarMatrizes(a, b, c, lin,  col);
                            multiplicarMatrizes(a,b, c,  lA,  cA,  cB);
                            
                        break;
                    case 5:
            printf("5-Adivinhe o Vetor Secreto");
            break;
                    default:
            printf("Opção invalida");
            break;
}
}

//--------------------------FUNCAO MENU--------------------------//

    void MenuSelect(){
        printf("selecione o modulo desejado:\n");
        printf("1-Estatísticas de um Vetor\n");
        printf("2—Verificações e Classificações\n");
        printf("3-Sequências Matemáticas\n");
        printf("4-Operações com Matrizes\n");
        printf("5-Adivinhe o Vetor Secreto\n");
        printf("|------------------------------|\n");
        }
        
        
//--------------------------FUNCOES DO MODULO 1--------------------------//

float somaVetor(float v[], int n){
    
        
    float soma;
    
    int i = 0;
    soma = 0.0;
    
     
    while(i  < n){
    soma = soma + v[i];
    i++;
    }
    
    return soma;

    
}
float mediaVetor(float v[], int n){

    float soma = somaVetor(v, n);
    
    
    float media = soma / n;
     
    
    
    return media;
  
    
}
float varianciaVetor(float v[], int n){
    
   
    float variancia;
    float variancia1 = 0;
    float variancia2 = 0;
    float media = mediaVetor(v, n);

    for(int i = 0; i < n; i++){
        
        variancia2 = (v[i] - media) * (v[i] - media);
        variancia1 = variancia2 + variancia1;
        
    }
    
    variancia = variancia1 / (n - 1);

    return variancia;
    
    
} 
float desvioVetor(float v[], int n){

    float variancia = varianciaVetor(v, n);
    
    float desviopadrao;
    
    desviopadrao = sqrt(variancia);

    return desviopadrao;
    }

float medianaVetor(float v[], int n){
    
    float mediana;
    float k;
    float copia[MAX];
    int i, j;
    
   for (i = 0; i < n; i++) {
           copia[i] = v[i];
   }
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if ( copia[j] >  copia[j + 1]) {
                k =  copia[i];
                copia[j] =  copia[j + 1];
                copia[j + 1] = k;
            }
        }
    }
    
   
    if(n % 2 == 0){
        mediana = (copia[n / 2] + copia[(n / 2) - 1]) / 2;
    }
    else{
       mediana = copia[n / 2];
    }
    return mediana;
    
}




void minMaxVetor(float v[], int n, float *min, float *max){
    
    int i; 
        
    int posicaomax = 0;
    int posicaomin = 0;
    float confirmacao;
    *max = v[0];

    for(i = 1; i < n; i++){
        if(*max < v[i]){
            *max = v[i];
                posicaomax = i;
        }
    }
    
    *min = v[0];

    for(i = 1; i < n; i++){
        if(*min > v[i]){
            *min = v[i];
                posicaomin = i;
        }
    }
           
            
            
            
            
 printf("Maior valor: %.2f  (posicao %d)", *max, posicaomax);
 printf("\n");
 printf("Menor valor: %.2f  (posicao %d)", *min, posicaomin);
    
}

float produtoVetor(float v[], int n){
    
    float produto = 1;
    
    for(int i = 0; i < n; i++){
        produto = v[i] * produto;
    }
    
    return produto;
}
void lerVetor(float v[], int *n){
    
    int i;
   
   
        printf("\nQuantos elementos?");
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
void exibirVetor(float v[], int n){
   
    
    int i = 0;
   printf("Vetor:");
    while(i  < n){
 
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

//--------------------------FUNCOES DO MODULO 2--------------------------//



//--------------------------FUNCOES DO MODULO 3--------------------------//



//--------------------------FUNCOES DO MODULO 4--------------------------//

void transporMatriz(float m[][DIM], float t[][DIM], int lin, int col){
    
    int i, j;
    
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            t[j][i] = m[i][j];
    }
}

printf("Matriz Transposta: \n");

 for(i = 0; i < col; i++){
        for(j = 0; j < lin; j++){
            printf("%.2f ", t[i][j]);
        }
        printf("\n");
 }
 printf("\n");
}


void somarMatrizes(float a[][DIM], float b[][DIM], float c[][DIM], int lin, int col){
    
    int i, j;
    
    printf("SOMA DE DUAS MATRIZES:");
    printf("\n");
    printf("insira o numero de linhas das matrizes: ");
    scanf("%d", &lin);
    
    while(lin > DIM || lin < 1){
        printf("insira o numero de linhas das matrizes novamente (1 - 10 linhas): ");
        scanf("%d", &lin);
    }
    
    printf("insira o numero de colunas das matrizes: ");
    scanf("%d", &col);
    while(col > DIM || col < 1){
        printf("insira o numero de colunas da matrizes novamente (1 - 10 colunas): ");
        scanf("%d", &col);
    }


for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
        printf("Insira o elemento [%d] [%d] da matriz A: ", i, j);
        scanf("%f", &a[i][j]);
    }
}



for(i = 0; i < lin; i++){
    for(j = 0; j < col; j++){
        printf("Insira o elemento [%d] [%d] da matriz B: ", i, j);
        scanf("%f", &b[i][j]);
    }

}


    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
          c[i][j] = a[i][j] + b[i][j];
    }
}

printf("MATRIZ A (%dx%d): \n", lin, col);
       for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%.2f ", a[i][j]);
    }
    
    printf("\n");
       }
       printf("\n");
       
    printf("MATRIZ B (%dx%d): \n", lin, col);
    
       for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%.2f ", b[i][j]);
    }
   printf("\n");
       }
       printf("\n");
       
    printf("Resultado C=A+B: \n");
        for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%.2f ", c[i][j]);
    }
    printf("\n");
}
printf("\n");

    
    
}


void multiplicarMatrizes(float a[][DIM], float b[][DIM], float c[][DIM], int lA, int cA, int cB){
    
    int i, j, k;
    printf("PRODUTO DE DUAS MATRIZES:");
    printf("\n");
    
    printf("insira o numero de linhas das matriz A: ");
    scanf("%d", &lA);
    
    while(lA > DIM || lA < 1){
        printf("insira o numero de linhas da matriz A novamente (1 - 10 linhas): ");
        scanf("%d", &lA);
    }
    
    printf("insira o numero de colunas da matriz A: ");
    scanf("%d", &cA);
    while(cA > DIM || cA < 1){
        printf("insira o numero de colunas da matriz A novamente (1 - 10 colunas): ");
        scanf("%d", &cA);
    }
    
    printf("insira o numero de colunas da matriz B: ");
    scanf("%d", &cB);
    while(cB > DIM || cB < 1){
        printf("insira o numero de colunas da matriz B novamente (1 - 10 colunas): ");
        scanf("%d", &cB);
    }
    
    
    for(i = 0; i < lA; i++){
    for(j = 0; j < cA; j++){
        printf("Insira o elemento [%d] [%d] da matriz A: ", i, j);
        scanf("%f", &a[i][j]);
    }
}



for(i = 0; i < cA; i++){
    for(j = 0; j < cB; j++){
        printf("Insira o elemento [%d] [%d] da matriz B: ", i, j);
        scanf("%f", &b[i][j]);
    }

}
    
    
    
    for (i = 0; i < lA; i++) {
        for (j = 0; j < cB; j++) {
            c[i][j] = 0;
        }
    }

    for (i = 0; i < cA; i++) {         
        for (j = 0; j < cB; j++) {     
            for (k = 0; k < cA; k++) { 
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    printf("MATRIZ A (%dx%d): \n", lA, cA);
       for(i = 0; i < lA; i++){
        for(j = 0; j < cA; j++){
            printf("%.2f ", a[i][j]);
    }
    
    printf("\n");
       }
       printf("\n");
       
    printf("MATRIZ B (%dx%d): \n", cA, cB);
    
       for(i = 0; i < cA; i++){
        for(j = 0; j < cB; j++){
            printf("%.2f ", b[i][j]);
    }
   printf("\n");
       }
       printf("\n");
       
    printf("Resultado C=A*B: \n");
        for(i = 0; i < lA; i++){
        for(j = 0; j < cB; j++){
            printf("%.2f ", c[i][j]);
    }
    printf("\n");
}
printf("\n");

    
}


float tracoMatriz(float m[][DIM], int n){
    
    int i, j;
    float tr = 0.0;
    

    
    for(i = 0; i < n; i++){
        
        tr = m[i][i] + tr;
        
        
    }
    
    return tr;
}

int isSimetrica(float m[][DIM], int n){
    
   
int i, j;
    
    for(i = 0; i <n; i++){
     for(j = i + 1; j < n; j++){
            if(m[i][j] != m[j][i]){
                return 0; 
            }
        }
    }
    return 1;
    
}

void lerMatriz(float m[][DIM], int *lin, int *col){
    
    
    int i, j;


printf("\ninsira o numero de linhas da matriz: ");
    scanf("%d", lin);
    
    while(*lin > DIM || *lin < 1){
        printf("insira o numero de linhas da matriz novamente (1 - 10 linhas): ");
        scanf("%d", lin);
    }
    
    printf("insira o numero de colunas da matriz: ");
    scanf("%d", col);
    while(*col > DIM || *col < 1){
        printf("insira o numero de colunas da matriz novamente (1 - 10 colunas): ");
        scanf("%d", col);
    }


for(i = 0; i < *lin; i++){
    for(j = 0; j < *col; j++){
        printf("Insira o elemento [%d] [%d]: ", i, j);
        scanf("%f", &m[i][j]);
    }
}
}

void exibirMatriz(float m[][DIM], int lin, int col){
 
    int i, j;
    
    
    printf(" \n Matriz: \n");
    
    for(i = 0; i < lin; i++){
        for(j = 0; j < col; j++){
            printf("%.2f ", m[i][j]);
    }
    printf("\n");
}
printf("\n");



if (lin == col) {
    int n = lin; 
    
    int simetrica =  isSimetrica( m,  n);
    
    if (simetrica == 1) {
        printf("A matriz é simétrica \n");
    }
    else {
        printf("A matriz não é simétrica\n");
    }
    
    float tr = tracoMatriz(m, n);
    
    if (lin == col) {
    n = lin; 
    printf("O traço da matriz é: %.2f \n", tr);
    }
    
    
    printf("\n");
   }
}        
        
