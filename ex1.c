/* 
    Autor: Luis Fernando de Mesquita Pereira 10410686
    Data: 29/03/2025
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Recebe a palavra como argumento de entrada no programa 
int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Erro! É necessário executar o programa passando a palavra como argumento.");
        exit(EXIT_FAILURE);
    }

    int tamanho_palavra = strlen(argv[1]);
    printf("%d\n", tamanho_palavra);
    char palavra_atual;
    int cont = 1;

    // O objetivo desse for é contar as ocorrências de um a letra em uma palavra
    for(int i = 0; i < tamanho_palavra - 1; i++){
        palavra_atual = argv[1][i];

        // Se a letra atual for igual a próxima letra, ele soma um ao contador
        if(palavra_atual == argv[1][i+1]){
            cont++;
        } // Senão, ele apresenta a palavra e reinicia o contador
            // Assim ela iterar completamente o vetor
        else{
            printf("%c%d-", palavra_atual, cont);
            cont = 1;
        }

        if (i == (tamanho_palavra - 2)){
            printf("%c%d", argv[1][i+1], cont);
        }
    }

    printf("\n");
    return 0;
}