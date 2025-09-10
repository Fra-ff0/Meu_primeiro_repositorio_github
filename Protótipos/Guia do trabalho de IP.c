#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h> // Para INT_MIN

#define NUM_LABS 3
#define MAX_COMPUTADORES 30

// Estrutura para armazenar os dados de um computador
struct Computador {
    int codigoIdentificacao;
    char nomeUsuario[41];
    float porcentagemUsoDisco;
    int status; // 1 = ligado, 0 = desligado
};

// --- Protótipos das Funções ---
void cadastrarComputadores(struct Computador laboratorios[][MAX_COMPUTADORES], int numComputadores[]);
void mostrarComputadoresLigados(const struct Computador laboratorios[][MAX_COMPUTADORES], const int numComputadores[]);
void usuarioMaiorUsoDisco(const struct Computador laboratorios[][MAX_COMPUTADORES], const int numComputadores[]);
void buscarComputadorPorCodigo(const struct Computador laboratorios[][MAX_COMPUTADORES], const int numComputadores[]);

int main() {
    struct Computador laboratorios[NUM_LABS][MAX_COMPUTADORES];
    int numComputadores[NUM_LABS] = {0}; // Inicializa o número de computadores em cada laboratório como 0
    int opcao;

    do {
        printf("\n--- Controle de Laboratórios do IFCE ---\n");
        printf("1. Cadastrar Computadores\n");
        printf("2. Mostrar Computadores Ligados\n");
        printf("3. Usuário com Maior Uso de Disco por Laboratório\n");
        printf("4. Buscar Computador por Código\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarComputadores(laboratorios, numComputadores);
                break;
            case 2:
                mostrarComputadoresLigados(laboratorios, numComputadores);
                break;
            case 3:
                usuarioMaiorUsoDisco(laboratorios, numComputadores);
                break;
            case 4:
                buscarComputadorPorCodigo(laboratorios, numComputadores);
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}

/**
 * @brief Cadastra N computadores em um laboratório específico.
 * * @param laboratorios A matriz de computadores.
 * @param numComputadores O vetor que armazena a quantidade de computadores por laboratório.
 */
void cadastrarComputadores(struct Computador laboratorios[][MAX_COMPUTADORES], int numComputadores[]) {
    int lab;
    printf("Informe o laboratório para cadastro (0, 1 ou 2): ");
    scanf("%d", &lab);

    if (lab < 0 || lab >= NUM_LABS) {
        printf("Laboratório inválido!\n");
        return;
    }

    printf("Quantos computadores deseja cadastrar neste laboratório (até %d)? ", MAX_COMPUTADORES);
    int n;
    scanf("%d", &n);

    // Limpa o buffer de entrada
     

    if (n <= 0 || n > MAX_COMPUTADORES) {
        printf("Número inválido de computadores.\n");
        return;
    }

    numComputadores[lab] = n;
    printf("\n--- Cadastro no Laboratório %d ---\n", lab);
    for (int i = 0; i < n; i++) {
        printf("--- Computador %d ---\n", i + 1);
        printf("Código de Identificação: ");
        scanf("%d", &laboratorios[lab][i].codigoIdentificacao);

        printf("Nome do Usuário Logado: ");
        scanf(" %40[^\n]", laboratorios[lab][i].nomeUsuario); // Lê a string com espaços

        printf("Porcentagem de Uso do Disco: ");
        scanf("%f", &laboratorios[lab][i].porcentagemUsoDisco);

        printf("Status (1=ligado, 0=desligado): ");
        scanf("%d", &laboratorios[lab][i].status);
    }
    printf("\nCadastro concluído com sucesso!\n");
}

/**
 * @brief Mostra todos os computadores que estão ligados em todos os laboratórios.
 * * @param laboratorios A matriz de computadores.
 * @param numComputadores O vetor com a quantidade de computadores por laboratório.
 */
void mostrarComputadoresLigados(const struct Computador laboratorios[][MAX_COMPUTADORES], const int numComputadores[]) {
    printf("\n--- Computadores Ligados ---\n");
    int encontrou = 0;
    for (int i = 0; i < NUM_LABS; i++) {
        for (int j = 0; j < numComputadores[i]; j++) {
            if (laboratorios[i][j].status == 1) {
                printf("----------------------------------------\n");
                printf("Laboratório: %d\n", i);
                printf("Código: %d\n", laboratorios[i][j].codigoIdentificacao);
                printf("Usuário: %s\n", laboratorios[i][j].nomeUsuario);
                printf("Uso do Disco: %.2f%%\n", laboratorios[i][j].porcentagemUsoDisco);
                encontrou = 1;
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum computador ligado encontrado.\n");
    }
     printf("----------------------------------------\n");
}

/**
 * @brief Mostra o nome do usuário que está utilizando o computador com maior uso de disco em um laboratório informado.
 * * @param laboratorios A matriz de computadores.
 * @param numComputadores O vetor com a quantidade de computadores por laboratório.
 */
void usuarioMaiorUsoDisco(const struct Computador laboratorios[][MAX_COMPUTADORES], const int numComputadores[]) {
    int lab;
    printf("Informe o laboratório para a busca (0, 1 ou 2): ");
    scanf("%d", &lab);

    if (lab < 0 || lab >= NUM_LABS) {
        printf("Laboratório inválido!\n");
        return;
    }

    if (numComputadores[lab] == 0) {
        printf("Nenhum computador cadastrado no laboratório %d.\n", lab);
        return;
    }

    float maiorUso = -1.0;
    int indiceMaiorUso = -1;

    for (int i = 0; i < numComputadores[lab]; i++) {
        if (laboratorios[lab][i].porcentagemUsoDisco > maiorUso) {
            maiorUso = laboratorios[lab][i].porcentagemUsoDisco;
            indiceMaiorUso = i;
        }
    }

    if (indiceMaiorUso != -1) {
        printf("\n--- Maior Uso de Disco no Laboratório %d ---\n", lab);
        printf("Usuário: %s\n", laboratorios[lab][indiceMaiorUso].nomeUsuario);
        printf("Com um uso de disco de: %.2f%%\n", maiorUso);
    } else {
        // Este caso é improvável se houver computadores cadastrados, mas é uma boa prática.
        printf("Não foi possível determinar o maior uso de disco no laboratório %d.\n", lab);
    }
}

/**
 * @brief Permite que o usuário busque por código e veja os dados de um computador específico.
 * * @param laboratorios A matriz de computadores.
 * @param numComputadores O vetor com a quantidade de computadores por laboratório.
 */
void buscarComputadorPorCodigo(const struct Computador laboratorios[][MAX_COMPUTADORES], const int numComputadores[]) {
    int codigo;
    printf("Digite o código de identificação do computador a ser buscado: ");
    scanf("%d", &codigo);

    int encontrou = 0;
    for (int i = 0; i < NUM_LABS; i++) {
        for (int j = 0; j < numComputadores[i]; j++) {
            if (laboratorios[i][j].codigoIdentificacao == codigo) {
                printf("\n--- Informações do Computador ---\n");
                printf("Laboratório: %d\n", i);
                printf("Código: %d\n", laboratorios[i][j].codigoIdentificacao);
                printf("Usuário: %s\n", laboratorios[i][j].nomeUsuario);
                printf("Uso do Disco: %.2f%%\n", laboratorios[i][j].porcentagemUsoDisco);
                printf("Status: %s\n", laboratorios[i][j].status == 1 ? "Ligado" : "Desligado");
                encontrou = 1;
                // Para a busca assim que encontrar o primeiro resultado
                // Se códigos puderem ser únicos, pode adicionar 'return;' aqui.
            }
        }
    }

    if (!encontrou) {
        printf("Computador com o código %d não encontrado.\n", codigo);
    }
}