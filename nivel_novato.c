#include <stdio.h>
#include <string.h>

// ANÁLISE DE ALGORITMO - Desafio Chef Sort
// Este é o arquivo inicial para o desafio. 
// Nível escolhido (Novato).

// ====================================================================
// PROTÓTIPOS DAS FUNÇÕES DE ORDENAÇÃO
// ====================================================================

// Nível Novato: Bubble Sort para strings
// Dica: Use strcmp() da biblioteca <string.h> para comparar strings.
// Dica: Passe ponteiros para contadores de comparações e trocas se quiser alterá-los dentro da função.
void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    // Sua lógica do Bubble Sort aqui
    int i, j, temp;
    int trocou;

    for (i=0; i< tamanho - 1; i++) {
        trocou = 0;

        for (j=0; j< tamanho - i -1; j++){
            if (vetor[j] > vetor [j+1]) {
                temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
                trocou=1;

            }
        }
        if(!trocou)
            break;
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
    /*
    char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};
    int num_ingredientes = 5;
    int comparacoes = 0;
    int trocas = 0;

    printf("--- Nivel Novato: Organizando a Despensa ---\n");
    printf("Lista ANTES da ordenacao:\n");
    // Laco para imprimir ingredientes antes

    // Chamada da funcao bubbleSortStrings(...)

    printf("\nLista DEPOIS da ordenacao:\n");
    // Laco para imprimir ingredientes depois
    // Imprimir totais de comparacoes e trocas
    */


    

    return 0;
}
