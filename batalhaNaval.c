#include <stdio.h>
#include <stdlib.h>

#define TAM 10   // tamanho do tabuleiro
#define NAVIO 3  // valor que representa navio
#define AGUA 0   // valor que representa água
#define HABILIDADE 5 // valor que representa habilidade

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Função para posicionar navios fixos (exemplo)
void posicionarNavios(int tabuleiro[TAM][TAM]) {
    // Navio horizontal (linha 2, colunas 1 a 3)
    for (int j = 1; j < 4; j++) {
        tabuleiro[2][j] = NAVIO;
    }

    // Navio vertical (coluna 6, linhas 4 a 6)
    for (int i = 4; i < 7; i++) {
        tabuleiro[i][6] = NAVIO;
    }

    // Navio diagonal principal (começando em [5][1])
    for (int k = 0; k < 3; k++) {
        tabuleiro[5+k][1+k] = NAVIO;
    }

    // Navio diagonal secundária (começando em [1][8])
    for (int k = 0; k < 3; k++) {
        tabuleiro[1+k][8-k] = NAVIO;
    }
}

// Função para aplicar habilidade no tabuleiro
void aplicarHabilidade(int tabuleiro[TAM][TAM], int habilidade[5][5], int origemX, int origemY) {
    int raio = 2; // metade do tamanho da matriz 5x5

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (habilidade[i][j] == 1) {
                int x = origemX + (i - raio);
                int y = origemY + (j - raio);

                // Validação de limites
                if (x >= 0 && x < TAM && y >= 0 && y < TAM) {
                    if (tabuleiro[x][y] == AGUA) {
                        tabuleiro[x][y] = HABILIDADE;
                    }
                }
            }
        }
    }
}

// Construir habilidade em cone 5x5
void construirCone(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            habilidade[i][j] = 0;
            if (j >= 2 - i && j <= 2 + i) { // forma do cone
                habilidade[i][j] = 1;
            }
        }
    }
}

// Construir habilidade em cruz 5x5
void construirCruz(int habilidade[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            habilidade[i][j] = (i == 2 || j == 2) ? 1 : 0;
        }
    }
}

// Construir habilidade em octaedro (losango) 5x5
void construirOctaedro(int habilidade[5][5]) {
    int centro = 2;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (abs(i - centro) + abs(j - centro) <= 2) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int cone[5][5], cruz[5][5], octaedro[5][5];

    // Inicializar tabuleiro
    inicializarTabuleiro(tabuleiro);

    // Posicionar navios
    posicionarNavios(tabuleiro);

    printf("Tabuleiro inicial com navios:\n");
    exibirTabuleiro(tabuleiro);

    // Construir habilidades
    construirCone(cone);
    construirCruz(cruz);
    construirOctaedro(octaedro);

    // Aplicar habilidades no tabuleiro em pontos específicos
    aplicarHabilidade(tabuleiro, cone, 4, 4);
    aplicarHabilidade(tabuleiro, cruz, 7, 2);
    aplicarHabilidade(tabuleiro, octaedro, 2, 7);

    printf("Tabuleiro com habilidades aplicadas:\n");
    exibirTabuleiro(tabuleiro);

    return 0;
}
