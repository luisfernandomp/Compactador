#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    for(int i = 0; i < tamanho_palavra - 1; i++){
        palavra_atual = argv[1][i];

        if(palavra_atual == argv[1][i+1]){
            cont++;
        }
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