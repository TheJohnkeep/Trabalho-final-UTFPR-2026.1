#include <stdio.h>
#define DIM 10

void lerMatriz(float m[][DIM], int *lin, int *col){
    
    
    int i, j;


printf("insira o numero de linhas da matriz: ");
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
            printf("%2.f ", m[i][j]);
    }
    printf("\n");
}
printf("\n");


}

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
            printf("%2.f ", t[i][j]);
        }
        printf("\n");
 }
 printf("\n");
}


void somarMatrizes(float a[][DIM], float b[][DIM], float c[][DIM], int *lin, int *col){
    
    int i, j;
    
    printf("insira o numero de linhas das matrizes: ");
    scanf("%d", lin);
    
    while(*lin > DIM || *lin < 1){
        printf("insira o numero de linhas das matrizes novamente (1 - 10 linhas): ");
        scanf("%d", lin);
    }
    
    printf("insira o numero de colunas das matrizes: ");
    scanf("%d", col);
    while(*col > DIM || *col < 1){
        printf("insira o numero de colunas da matrizes novamente (1 - 10 colunas): ");
        scanf("%d", col);
    }


for(i = 0; i < *lin; i++){
    for(j = 0; j < *col; j++){
        printf("Insira o elemento [%d] [%d] da matriz A: ", i, j);
        scanf("%f", &a[i][j]);
    }
}



for(i = 0; i < *lin; i++){
    for(j = 0; j < *col; j++){
        printf("Insira o elemento [%d] [%d] da matriz B: ", i, j);
        scanf("%f", &b[i][j]);
    }

}


    for(i = 0; i < *lin; i++){
        for(j = 0; j < *col; j++){
          c[i][j] = a[i][j] + b[i][j];
    }
}

printf("MATRIZ A (%dx%d): \n", *lin, *col);
       for(i = 0; i < *lin; i++){
        for(j = 0; j < *col; j++){
            printf("%2.f ", a[i][j]);
    }
    
    printf("\n");
       }
       printf("\n");
       
    printf("MATRIZ B (%dx%d): \n", *lin, *col);
    
       for(i = 0; i < *lin; i++){
        for(j = 0; j < *col; j++){
            printf("%2.f ", b[i][j]);
    }
   printf("\n");
       }
       printf("\n");
       
    printf("Resultado C=A+B: \n");
        for(i = 0; i < *lin; i++){
        for(j = 0; j < *col; j++){
            printf("%2.f ", c[i][j]);
    }
    printf("\n");
}
printf("\n");

    
    
}


void multiplicarMatrizes(float a[][DIM], float b[][DIM], float c[][DIM], int *lA, int *cA, int *cB){
    
    int i, j, k;

    
    printf("insira o numero de linhas das matriz A: ");
    scanf("%d", lA);
    
    while(*lA > DIM || *lA < 1){
        printf("insira o numero de linhas da matriz A novamente (1 - 10 linhas): ");
        scanf("%d", lA);
    }
    
    printf("insira o numero de colunas da matriz A: ");
    scanf("%d", cA);
    while(*cA > DIM || *cA < 1){
        printf("insira o numero de colunas da matriz A novamente (1 - 10 colunas): ");
        scanf("%d", cA);
    }
    
    printf("insira o numero de colunas da matriz B: ");
    scanf("%d", cB);
    while(*cB > DIM || *cB < 1){
        printf("insira o numero de colunas da matriz B novamente (1 - 10 colunas): ");
        scanf("%d", cB);
    }
    
    
    for(i = 0; i < *lA; i++){
    for(j = 0; j < *cA; j++){
        printf("Insira o elemento [%d] [%d] da matriz A: ", i, j);
        scanf("%f", &a[i][j]);
    }
}



for(i = 0; i < *cA; i++){
    for(j = 0; j < *cB; j++){
        printf("Insira o elemento [%d] [%d] da matriz B: ", i, j);
        scanf("%f", &b[i][j]);
    }

}
    
    
    
    for (i = 0; i < *lA; i++) {
        for (j = 0; j < *cB; j++) {
            c[i][j] = 0;
        }
    }

    for (i = 0; i < *cA; i++) {         
        for (j = 0; j < *cB; j++) {     
            for (k = 0; k < *cA; k++) { 
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    printf("MATRIZ A (%dx%d): \n", *lA, *cA);
       for(i = 0; i < *lA; i++){
        for(j = 0; j < *cA; j++){
            printf("%2.f ", a[i][j]);
    }
    
    printf("\n");
       }
       printf("\n");
       
    printf("MATRIZ B (%dx%d): \n", *cA, *cB);
    
       for(i = 0; i < *cA; i++){
        for(j = 0; j < *cB; j++){
            printf("%2.f ", b[i][j]);
    }
   printf("\n");
       }
       printf("\n");
       
    printf("Resultado C=A*B: \n");
        for(i = 0; i < *lA; i++){
        for(j = 0; j < *cB; j++){
            printf("%2.f ", c[i][j]);
    }
    printf("\n");
}
printf("\n");

    
}


float tracoMatriz(float m[][DIM], int *n){
    
    int i, j;
    float tr = 0.0;
    
    printf("insira um numero equivalente às linhas e colunas da matriz: ");
    scanf("%d", n);
    
    while(*n > DIM || *n < 1){
        printf("insira o numero novamente (1 - 10 linhas/colunas): ");
        scanf("%d", n);
    }
    
    for(i = 0; i < *n; i++){
        
        tr = m[i][i] + tr;
        
        
    }
    
    return tr;
}

int isSimetrica(float m[][DIM], int *n){
    
    
    int i, j;

  printf("insira um numero equivalente às linhas e colunas da matriz: ");
    scanf("%d", n);
    
    while(*n > DIM || *n < 1){
        printf("insira o numero novamente (1 - 10 linhas/colunas): ");
        scanf("%d", n);
    }

    for(i = 0; i < *n; i++){
     for(j = i + 1; j < *n; j++){
            if(m[i][j] != m[j][i]){
                return 0; 
            }
        }
    }
    return 1;
    
}


int main() {
    int lin, col, lA, cA, cB, n;
    float m[DIM][DIM], t[DIM][DIM], a[DIM][DIM], b[DIM][DIM], c[DIM][DIM];

    
    lerMatriz(m, &lin, &col);
    
    exibirMatriz( m, lin, col);
    
    transporMatriz( m, t,  lin,  col);
    
    somarMatrizes(a, b, c, &lin,  &col);
    
    multiplicarMatrizes(a,b, c,  &lA,  &cA,  &cB);
    
    tracoMatriz(m, &n);
    
    isSimetrica( m,  &n);

    return 0;
}
