#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 20

int main(){
    int matriz[MAX][MAX];
    int lin, col, aux, pontos_lin[MAX];
    int i, j;
    char opcao;


    printf("Qual o numero de maquinas ?\n");
    scanf("%d", &lin);
    printf("Qual o numero de produtos ?\n");
    scanf("%d", &col);
    printf("Relacione as maquinas com os produtos\n");

    for(i=1; i <= lin; i++){
        pontos_lin[i] = 0;
        for(j=1; j <= col; j++){
            printf("A maquina %d processa o produto %d ? (S/N)\n", i, j);
            fflush(stdin);
            scanf("%c", &opcao);

            //INCREMENTA A MATRIZ COM 1 E 0
            if(opcao == 's' || opcao == 'S'){
                matriz[i][j] = 1;
            } else if(opcao == 'n' || opcao == 'N'){
                matriz[i][j] = 0;
            }
        }
    }

    for(i=1; i <= lin; i++){
        aux = (col-1);
        for(j=1; j<=col; j++){
            if(matriz[i][j] == 1){
                //CONTA OS PONTOS POR LINHA FAZENDO (1x2^col-1) + (1x2^col-2) ....
                //ADICIONA AO VETOR "pontos_lin" CADA VALOR DAS LINHAS
                pontos_lin[i] = pontos_lin[i] + pow(2, aux);
            }
            aux--;
        }
    }

    aux = 0;



    //ORDENA EM ORDEM DECRESCENTE AS LINHAS
    for(i=1; i <= col; i++ ){
        for(j=i+1; j <= col; j++ ){
            if( pontos_lin[i] < pontos_lin[j] ){
               aux = pontos_lin[i];
               pontos_lin[i] = pontos_lin[j];
               pontos_lin[j] = aux;
            }
        }
    }

    /*printf("\n");
    for(i=1; i <= lin; i++){
        for(j=1; j <= col; j++){
            printf("%d ", matriz[i][j]);
        }
    }*/

    return 0;
}
