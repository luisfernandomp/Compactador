#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool existe_letra(char* palavra, int t, char letra);

int main(int argc, char *argv[])
{
    if(argc < 2){
        printf("Erro! É necessário executar o programa passando a palavra como argumento.");
        exit(EXIT_FAILURE);
    }

    int tamanho_palavra = strlen(argv[1]);

    char *matches = (char*)malloc(tamanho_palavra * sizeof(char));

    if (matches == NULL) {
        printf("Erro ao alocar memória para matches.\n");
        exit(EXIT_FAILURE);
    }   

    matches[0] = '\0';

    int ocorrencias = 1, indice_match = 0;

    for(int i = 0; i < tamanho_palavra; i++){ 
        if(matches[0] != argv[1][i]){
            matches[indice_match] = argv[1][i];
            indice_match++;
        }
        else{
            matches[indice_match] = '\0';
            
            int M = strlen(matches);
            char *palavra = (char*)malloc((M + 1) * sizeof(char));

            bool continuar = true;

            while(continuar && i <= tamanho_palavra){

                int j;
                for(j = 0; j < M; j++){
                    palavra[j] = argv[1][i];
                    i++;
                }

                palavra[j] = '\0';
    
                if(strcmp(palavra, matches) == 0){
                    ocorrencias++;
                }
                else{
                    i -= strlen(palavra);
                    continuar = false;
                }
            }

            printf("%s%d", matches, ocorrencias);
            indice_match = 0;
            ocorrencias = 1;
            matches[0] = '\0';
            i--;
                    
            if(i < tamanho_palavra)
                printf("-");
                    

            free(palavra);
        }
    }

    free(matches);
    printf("\n");
    
    return 0;
}
