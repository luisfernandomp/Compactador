/* 
    Autor: Luis Fernando de Mesquita Pereira 10410686
    Data: 29/03/2025
*/

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
        // Percorre o vetor até encontrar a próxima vetor igual ao inicio do subvetor criado
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
                // Com a palavra encontrada percorre o vetor maior para verificar se nas próximas possições existe ocorrências da 
                // Mesma palavra, somente se forem adjacentes
                for(j = 0; j < M; j++){
                    palavra[j] = argv[1][i];
                    i++;
                }

                palavra[j] = '\0';
    
                // Verifica se o subvetor encontrado é igual a palavra da primeira ocorrência
                // Se sim, incrementa o contador de ocorrencias
                if(strcmp(palavra, matches) == 0){
                    ocorrencias++;
                }
                else{
                    //  Se a próxima palavra encontrada for diferente, faz um decremento do vetor, pois o i foi incrementado para
                    // encontrar essa palavra e para de percorrer o vetor em busca da palavra
                    i -= strlen(palavra);
                    continuar = false;
                }
            }

            printf("%s%d", matches, ocorrencias);

            // Reinicia o vetor de subpalavra e o seu indice
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
