#include <stdio.h>

int main() {
    
    const int TAM_TABULEIRO = 10; // Tamanho fixo 10x10
    const int TAM_NAVIO = 3;      // Cada navio ocupa 3 posições
    int tabuleiro[10][10];        // Matriz 10x10 representando o tabuleiro

    // ==============================
    // Inicializar o tabuleiro com 0 (água)
    // ==============================
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 = água
        }
    }

    // ==============================
    // Coordenadas iniciais dos navios
    // ==============================
    int linhaNavioHorizontal = 2; // Linha do navio horizontal
    int colunaNavioHorizontal = 4; // Coluna inicial
    int linhaNavioVertical = 5;   // Linha inicial do navio vertical
    int colunaNavioVertical = 7;  // Coluna fixa do navio vertical

    // ==============================
    // Posicionar Navio Horizontal
    // ==============================
    for (int j = 0; j < TAM_NAVIO; j++) {
        tabuleiro[linhaNavioHorizontal][colunaNavioHorizontal + j] = 3;
    }

    // ==============================
    // Posicionar Navio Vertical
    // ==============================
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[linhaNavioVertical + i][colunaNavioVertical] = 3;
    }

    // ==============================
    // Exibir Tabuleiro
    // ==============================
    printf("Tabuleiro de Batalha Naval (0 = agua, 3 = navio):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
