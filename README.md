# ANÁLISE DE ALGORITMO - Desafio Chef Sort 👨‍🍳👩‍🍳

Bem-vindo ao desafio **Chef Sort**! A Enigma Studios recrutou você para desenvolver o sistema de organização interna de seu novo jogo educativo. Neste jogo, os jogadores simulam uma cozinha profissional e devem organizar ingredientes, montar pratos e atender comandas.

Seu papel é implementar o núcleo lógico do jogo utilizando a linguagem C, aplicando algoritmos de ordenação clássicos e analisando suas eficiências. 

O desafio está dividido em três níveis: **Novato**, **Aventureiro** e **Mestre**. Cada nível adiciona novos conceitos de estruturas de dados e novos algoritmos de ordenação.

### 🚨 Atenção: 
O nível **Novato** é o ponto de partida, focado na manipulação básica de arrays de caracteres (strings) e no uso do algoritmo Bubble Sort com contagem de operações.

---

## 🎮 Nível Novato: A Organização da Despensa

Nesta primeira fase, o jogador chega à cozinha e encontra a bancada em completo caos. Os ingredientes foram entregues em horários aleatórios e precisam ser ordenados alfabeticamente para facilitar o trabalho do chef.

### 🚩 Objetivo:
- Ordenar um vetor fixo contendo os nomes dos ingredientes em ordem alfabética.

### ⚙️ Funcionalidades e Requisitos:
- **Estrutura de Dados:** Utilizar um vetor bidimensional de `char` (array de strings) fixo, sem necessidade de entrada do usuário via `scanf`.
- char ingredientes[5][50] = {"Tomate", "Cebola", "Alho", "Cenoura", "Batata"};

- **Algoritmo:** Implementar o algoritmo **Bubble Sort**.
- void bubbleSortStrings(char arr[][50], int n, int *comparacoes, int *trocas) {
    int i, j;
    char temp[50]; // Variável auxiliar precisa ser um array de char para armazenar a string temporariamente
    int trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = 0;

        for (j = 0; j < n - i - 1; j++) {
            // Incrementa o contador de comparações
            (*comparacoes)++;

            // Compara as strings lexicograficamente. Se arr[j] for maior que arr[j+1], strcmp retorna > 0
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

- **Métricas:** O algoritmo deve contabilizar e exibir o total de *comparações* realizadas e o total de *trocas* efetuadas.
 // Exibição das estatísticas do algoritmo
    printf("\nEstatisticas de Desempenho:\n");
    printf("-> Comparacoes realizadas: %d\n", comparacoes);
    printf("-> Trocas realizadas: %d\n", trocas);

### 📥 Entrada e 📤 Saída de Dados:
- **Entrada:** Vetor fixo no código (Ex: `{"Tomate", "Cebola", "Alho", "Cenoura"}`).
- **Saída:** O sistema deverá imprimir:
  - A lista de ingredientes ANTES da ordenação.
  -  printf("Lista ANTES da ordenacao:\n");
    	for (int i = 0; i < num_ingredientes; i++) {
        printf("  - %s\n", ingredientes[i]);
   	 }
  - A lista de ingredientes DEPOIS da ordenação.
  -  printf("\nLista DEPOIS da ordenacao:\n");
    for (int i = 0; i < num_ingredientes; i++) {
        printf("  - %s\n", ingredientes[i]);
    }
  - O total de comparações realizadas.
  - printf("-> Comparacoes realizadas: %d\n", comparacoes);
  - O total de trocas efetuadas.
  -  printf("-> Trocas realizadas: %d\n", trocas);


---

## 🛡️ Nível Aventureiro: A Criação dos Pratos

Agora que a cozinha está organizada, é hora de montar os pratos. Para um serviço mais ágil, o chef quer preparar primeiro os pratos mais simples (com menos ingredientes) e deixar os mais complexos para depois.

### 🆕 Diferenças em relação ao Nível Novato:
- **Estrutura de Dados:** Em vez de um vetor de strings, você utilizará um vetor de **`structs`**. Cada `struct` representará um prato contendo: `Nome do prato` (string) e `Quantidade de ingredientes` (int). Você deve criar um vetor fixo com 5 pratos.
- **Critério de Ordenação:** A ordenação não será mais alfabética, mas sim numérica, baseada na *quantidade de ingredientes* (do menor para o maior).
- **Algoritmo:** Implementar o algoritmo **Selection Sort**.

### 📤 Saída de Dados:
- Imprimir a lista de pratos (nome e quantidade de ingredientes) ANTES e DEPOIS da ordenação pelo Selection Sort.

---

## 🏆 Nível Mestre: O Atendimento das Comandas

O restaurante está a todo vapor! As comandas chegaram fora de ordem e, para que o fluxo de preparo seja correto, é preciso organizá-las pela prioridade de atendimento (número da comanda). 

### 🆕 Diferenças em relação ao Nível Aventureiro:
- **Estrutura de Dados:** Nova `struct` representando a comanda, contendo: `Nome do prato` (string) e `Número da comanda` (int).
- **Critério de Ordenação:** Ordenar de forma crescente baseando-se no *número da comanda*.
- **Algoritmo:** Substituir os laços tradicionais pela recursividade. Você deve implementar o **Recursive Insertion Sort** (Insertion Sort Recursivo).

### 📤 Saída de Dados:
- Imprimir a lista de comandas ANTES e DEPOIS da ordenação recursiva, provando que a fila de pedidos está pronta para o chef executar!

---

💡 **Dica do Professor:** Lembre-se de comentar seu código! Explicar a lógica dos laços, as condições de troca e, especialmente, o *caso base* da sua função recursiva no nível Mestre será fundamental para a sua avaliação.

Boa sorte, Chef! E divirta-se codando! 🚀
