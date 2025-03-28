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
    char letra_atual;
    int cont = 0;

    for(int i = 0; i < tamanho_palavra; i++){

        letra_atual = argv[1][i];

        int j = i + 1;
        while(argv[1][j] != '-' && argv[1][j] != '\0'){
            cont++;
            j++;
        }

        char digito[cont];

        int z = i + 1;
        for(int y = 0; y < cont; y++){
            digito[y] = argv[1][z];
            z++;
        }
        
        digito[cont] = '\0';

        int vezes = atoi(digito);
        for(int k = 0; k < vezes; k++)
          printf("%c", letra_atual);

        i += cont + 1;
        cont = 0;
    }

    printf("\n");
    return 0;
}