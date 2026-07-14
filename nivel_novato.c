#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Nível escolhido (Novato).

// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    int i, j;
    char temp[50]; // Variável auxiliar precisa ser um array de char para armazenar a string temporariamente
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - i - 1; j++) {
            // Incrementa o contador de comparações
            (*comparacoes)++;

            // Compara as strings. Se arr[j] for maior que arr[j+1], strcmp retorna > 0
            if (strcmp(arr[j], arr[j+1]) > 0) {
                // Realiza a troca das strings usando strcpy
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j+1]);
                strcpy(arr[j+1], temp);

                // Incrementa o contador de trocas e sinaliza que houve mudança
                (*trocas)++;
                trocou = 1;
            }
        }
        // Se nenhuma troca ocorreu nesta passada, o vetor já está ordenado
        if (!trocou) {
            break;
        }
    }
}

// ====================================================================
// FUNÇÃO PRINCIPAL
// ====================================================================

int main() {
    printf("=== BEM-VINDO AO CHEF SORT ===\n\n");

    // ---------------------------------------------------------
    // ÁREA DO NÍVEL NOVATO (Despensa / Bubble Sort)
    // ---------------------------------------------------------
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    	for (int i = 0; i < num_ingredientes; i++) {
        printf("  - %s\n", ingredientes[i]);
   	 }

    // Chamada da funcao bubbleSortStrings passando os endereços das variáveis de contagem (&)
    bubbleSortStrings(ingredientes, num_ingredientes, &comparacoes, &trocas);

    printf("\nLista DEPOIS da ordenacao:\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("  - %s\n", ingredientes[i]);
    }

    // Exibição das estatísticas do algoritmo
    printf("\nEstatisticas de Desempenho:\n");
    printf("-> Comparacoes realizadas: %d\n", comparacoes);
    printf("-> Trocas realizadas: %d\n", trocas);

    return 0;
}
