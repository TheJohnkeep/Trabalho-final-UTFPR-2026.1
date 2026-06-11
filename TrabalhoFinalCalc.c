#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
//----------------------Protótipos---------------------------//
    void MenuSelect(){
        printf("selecione o modulo desejado:\n");
        printf("1-Estatísticas de um Vetor\n");
        printf("2—Verificações e Classificações\n");
        printf("3-Sequências Matemáticas\n");
        printf("4-Operações com Matrizes\n");
        printf("5-Adivinhe o Vetor Secreto\n");
        printf("|------------------------------|\n");
        }
//---------------------------MAIN----------------------------//
int main()
{
MenuSelect();
        int Choice;
        scanf("%d",&Choice);
        switch(Choice){
                    case 1:
            printf("1-Estatísticas de um vetor selecionado");
            break;
                    case 2:
            printf("2-Verificações e Classificações");
            break;
                    case 3:
            printf("3-Sequências Matemáticas");
            goto
                        break;
                    case 4:
            printf("4-Operações com Matrizes");
            goto
                        break;
                    case 5:
            printf("5-Adivinhe o Vetor Secreto");
            break;
                    default:
            printf("Opção invalida");
            break;
}
teste1:
printf("\nteste1");
return 0;
teste2:
printf("\n mein gott");
}
