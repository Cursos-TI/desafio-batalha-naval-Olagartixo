#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_NAVIO 3

// Função auxiliar para verificar se é possível posicionar um navio
// (não sai dos limites e não se sobrepõe a outro)
int podePosicionar(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                   int linha, int coluna, 
                   int orientacao, int diagonal) {
    // orientacao: 0 = horizontal, 1 = vertical
    // diagonal: 0 = não diagonal, 1 = diagonal principal, -1 = diagonal secundária

    for (int k = 0; k < TAM_NAVIO; k++) {
        int i = linha, j = coluna;

        if (diagonal == 0) {
            if (orientacao == 0) j += k;       // horizontal
            else i += k;                       // vertical
        } else if (diagonal == 1) {            // diagonal principal (\)
            i += k; j += k;
        } else if (diagonal == -1) {           // diagonal secundária (/)
            i += k; j -= k;
        }

        // Verifica limites
        if (i < 0 || i >= TAM_TABULEIRO || j < 0 || j >= TAM_TABULEIRO) 
            return 0;

        // Verifica sobreposição
        if (tabuleiro[i][j] == 3) return 0;
    }

    return 1;
}

// Função para posicionar efetivamente o navio (assumindo que já foi validado)
void posicionarNavio(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                     int linha, int coluna, 
                     int orientacao, int diagonal) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        int i = linha, j = coluna;

        if (diagonal == 0) {
            if (orientacao == 0) j += k;       // horizontal
            else i += k;                       // vertical
        } else if (diagonal == 1) {            // diagonal principal (\)
            i += k; j += k;
        } else if (diagonal == -1) {           // diagonal secundária (/)
            i += k; j -= k;
        }

        tabuleiro[i][j] = 3;
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicializa o tabuleiro com 0 (água)
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ---- Posicionamento de navios ----
    // Dois normais (horizontal e vertical)
    if (podePosicionar(tabuleiro, 2, 4, 0, 0))
        posicionarNavio(tabuleiro, 2, 4, 0, 0); // horizontal em (2,4)

    if (podePosicionar(tabuleiro, 5, 7, 1, 0))
        posicionarNavio(tabuleiro, 5, 7, 1, 0); // vertical em (5,7)

    // Dois diagonais
    if (podePosicionar(tabuleiro, 0, 0, 0, 1))
        posicionarNavio(tabuleiro, 0, 0, 0, 1); // diagonal principal (\) em (0,0)

    if (podePosicionar(tabuleiro, 0, 9, 0, -1))
        posicionarNavio(tabuleiro, 0, 9, 0, -1); // diagonal secundária (/) em (0,9)

    // ---- Impressão do tabuleiro ----
    printf("Tabuleiro de Batalha Naval (0 = agua, 3 = navio):\n\n");
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
