#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

void desenho_da_forca(int erros);
void exibir_status (int tentativas_erradas, const char* palavra_progresso, const char* letras_usadas);
int letra_ja_usada (char letra, const char* letras_usadas);
void limpa_buffer();

int main() {

    const char* palavras[] = {
        "FRUTA", "COMPUTACAO", "COMPUTADOR", "BRASIL",
        "CEARA", "PRAIA", "IFCE", "PROGRAMACAO"
    };
    int num_palavras = sizeof(palavras) / sizeof(palavras[0]);

    // Uso da biblioteca <time.h> para toda vez que reinicie o código a palavra sorteada não se repita
    srand(time(NULL));

    // Seleciona uma palavra aleatória da lista
    char palavra_secreta[50];
    strcpy(palavra_secreta, palavras[rand() % num_palavras]);

    char palavra_progresso[50];
    char letras_usadas[27] = "";

    int tamanho_palavra = strlen(palavra_secreta); // uso da biblioteca <string.h>
    int tentativas_maximas = 6;
    int tentativas_erradas = 0;
    int letras_corretas = 0;
    char chute;

    // Esse laço exibe como vai aparecer no console o escopo da palavra secreta, ex: FRUTA = "_ _ _ _ _"
    for (int i = 0; i < tamanho_palavra; i++) {
        palavra_progresso[i] = '_';
    }
    palavra_progresso[tamanho_palavra] = '\0';

    printf("--- Bem-vindo ao Jogo da Forca! ---\n");
    printf("Adivinhe a palavra oculta. Voce tem %d chances.\n", tentativas_maximas);
    system("pause"); // o pause serve para o usuário tenha tempo de ler a mensagem antes de prosseguir no código

    while (tentativas_erradas < tentativas_maximas && letras_corretas < tamanho_palavra) {
        exibir_status(tentativas_erradas, palavra_progresso, letras_usadas);

        printf("\nDigite uma letra: ");
        chute = getchar();
        limpa_buffer(); 

        if (!isalpha(chute)) {
            printf("Entrada invalida! Por favor, digite apenas uma letra.\n");
            system("pause");
            continue;
        }

        chute = toupper(chute); // Uso do toupper da bilioteca <ctype.h> para converter uma letra minúscula para maiúscula.

        if (letra_ja_usada(chute, letras_usadas)) {
            printf("Voce ja tentou a letra '%c'. Tente outra.\n", chute);
            system("pause");
            continue;
        }
        
        int pos_letras_usadas = strlen(letras_usadas);// Verificação de quando o jogador vence 
        letras_usadas[pos_letras_usadas] = chute;
        letras_usadas[pos_letras_usadas + 1] = '\0';

        int acertou = 0;
        for (int i = 0; i < tamanho_palavra; i++) {
            if (palavra_secreta[i] == chute) {
                if (palavra_progresso[i] == '_') {
                    palavra_progresso[i] = chute;
                    letras_corretas++;
                }
                acertou = 1;
            }
        }

        if (acertou) {
            printf("Bom chute! A letra '%c' esta na palavra.\n", chute);
        } else {
            printf("Que pena! A letra '%c' nao esta na palavra.\n", chute);
            tentativas_erradas++;
        }
        system("pause");
    }

    // Fim de Jogo 
    exibir_status(tentativas_erradas, palavra_progresso, letras_usadas); // Mostra o resultado final

    if (letras_corretas == tamanho_palavra) {
        printf("\n*********************************\n");
        printf("* PARABENS! VOCE VENCEU!       *\n");
        printf("*********************************\n");
        printf("A palavra era: %s\n\n", palavra_secreta);
    } else {
        printf("\n*********************************\n");
        printf("* QUE PENA! VOCE PERDEU.     *\n");
        printf("*********************************\n");
        printf("A palavra secreta era: %s\n\n", palavra_secreta);
    }

    return 0;
}
/*  para deixar o jogo da forca visualmente parecido como um jogo da forca real,
    fiz o mesmo desenho com as mesma funcionalidade do jogo real.

    1 erro desenha a cabeça
    2 erros desenha o tronco
    3 a 4 erros desenha os braços
    5 a 6 erros desenha as pernas

*/
void desenho_da_forca (int erros) {
    printf("  +---+\n");
    printf("  |   |\n");

    if (erros >= 1) {
        printf("  O   |\n");
    } else {
        printf("      |\n");
    }

    if (erros >= 4) {
        printf(" /|\\  |\n");
    } else if (erros >= 3) {
        printf(" /|   |\n");
    } else if (erros >= 2) {
        printf("  |   |\n");
    } else {
        printf("      |\n");
    }

    if (erros >= 6) {
        printf(" / \\  |\n");
    } else if (erros >= 5) {
        printf(" /    |\n");
    } else {
        printf("      |\n");
    }

    printf("      |\n");
    printf("=========\n\n");
}
void exibir_status(int tentativas_erradas, const char* palavra_progresso, const char* letras_usadas) {
    /* system("cls || clear") é um comando do sistema operacional para limpar a tela.
       "cls" é para Windows e "clear" é para Linux/macOS.*/
    system("cls || clear");

    printf("--- JOGO DA FORCA ---\n\n");
    desenho_da_forca(tentativas_erradas);

    // Exibe a palavra com espaços para melhor visualização
    printf("Palavra: ");
    for (int i = 0; palavra_progresso[i] != '\0'; i++) {
        printf("%c ", palavra_progresso[i]);
    }
    printf("\n\n");

    printf("Letras ja usadas: %s\n", letras_usadas);
    printf("Chances restantes: %d\n", 6 - tentativas_erradas);
}
int letra_ja_usada(char letra, const char* letras_usadas) {
    // A função strchr procura a primeira ocorrência de um caractere em uma string.
    // Se encontrar, retorna um ponteiro para ele; senão, retorna NULL.
    if (strchr(letras_usadas, letra)) {
        return 1; // True
    }
    return 0; // False
}
/*
    Limpa o buffer de entrada do teclado para evitar
    que caracteres extras (como o 'Enter') afetem a próxima leitura.
*/
void limpa_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}