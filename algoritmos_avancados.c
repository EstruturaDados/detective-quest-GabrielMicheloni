#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct da sala da mansao
// Cada sala tem um nome e dois caminhos: esquerda e direita
typedef struct Sala {
    char nome[50];
    struct Sala *esq;
    struct Sala *dir;
} Sala;

// Funcao que cria uma sala dinamicamente
Sala* criarSala(char nome[]) {
    Sala *nova = (Sala*) malloc(sizeof(Sala));

    // Copia o nome para dentro da sala
    strcpy(nova->nome, nome);

    // Comeca sem caminhos
    nova->esq = NULL;
    nova->dir = NULL;

    return nova;
}

// Funcao que deixa o jogador explorar a mansao
void explorarSalas(Sala *atual) {
    char escolha;

    // Enquanto existir uma sala para explorar
    while (atual != NULL) {

        // Mostra onde o jogador esta
        printf("\nVocê esta em: %s\n", atual->nome);

        // Se a sala nao tem caminhos, acaba o jogo
        if (atual->esq == NULL && atual->dir == NULL) {
            printf("Fim do caminho. Nao existem mais salas.\n");
            return;
        }

        // Mostra opcoes de caminho
        printf("Escolha (e - esquerda, d - direita, s - sair): ");
        scanf(" %c", &escolha);

        // Escolha do jogador
        if (escolha == 'e') {
            atual = atual->esq;   // Vai para esquerda
        }
        else if (escolha == 'd') {
            atual = atual->dir;   // Vai para direita
        }
        else if (escolha == 's') {
            printf("Exploracao encerrada pelo usuario.\n");
            return;
        }
        else {
            printf("Opcao invalida! Tente novamente.\n");
        }
    }
}

int main() {
    // Criacao manual da arvore (como pedido no nivel novato)
    Sala *hall = criarSala("Hall de entrada");
    Sala *salaEstar = criarSala("Sala de estar");
    Sala *cozinha = criarSala("Cozinha");
    Sala *quarto = criarSala("Quarto");
    Sala *jardim = criarSala("Jardim");

    // Montagem da arvore (ligacoes)
    hall->esq = salaEstar;
    hall->dir = cozinha;

    salaEstar->esq = quarto;   // caminho da sala de estar
    salaEstar->dir = jardim;

    // cozinha nao leva a lugar nenhum
    // quarto e jardim tambem nao (folhas)

    // Inicia a exploracao
    explorarSalas(hall);

    return 0;
}
