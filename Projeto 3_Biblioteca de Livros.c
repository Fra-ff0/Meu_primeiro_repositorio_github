#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definições Globais (CONSTANTES)
#define MAX_TITULO 50
#define MAX_AUTOR 50
#define TAM_ISBN 13
#define MAX_LIVROS 100
#define MAX_USUARIOS 50
#define MAX_NOME_SENHA 50

// Estrutura para representar um Livro.
typedef struct {
    char titulo[MAX_TITULO + 1];
    char autor[MAX_AUTOR + 1];
    char isbn[TAM_ISBN + 1];
    int alugado;     
    int usuario_id;  
} Livro;

// Estrutura para representar um Usuário
typedef struct {
    char usuario[MAX_NOME_SENHA + 1];
    char senha[MAX_NOME_SENHA + 1];
} Usuario;

// Estrutura principal que agrupa todos os dados da Biblioteca.
typedef struct {
    Livro livros[MAX_LIVROS];
    int total_livros;

    Usuario usuarios[MAX_USUARIOS];
    int total_usuarios;
} Biblioteca;

Biblioteca biblioteca;

void salvar_biblioteca_em_arquivo();
void carregar_biblioteca_do_arquivo();
void limpar_buffer();
int ler_inteiro();

// Protótipos das funções
void menu_principal();
void tela_cadastro();
void tela_login();
void tela_politica();
void menu_livros(int usuario_logado);
void cadastrar_livro();
void listar_livros(int usuario_logado);
void alugar_livro(int usuario_logado);
void devolver_livro(int usuario_logado);

int main() {
    carregar_biblioteca_do_arquivo();
    
    while(1){
        menu_principal();
    }
    return 0;
}

/*Limpa o buffer de entrada do teclado para evitar
que caracteres extras (como o 'Enter') afetem a próxima leitura.*/
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int ler_inteiro() {
    int num;

    /* Loop infinito que mantém o menu principal em execução.
     O programa só termina quando o usuário escolhe a opção de sair.*/
    while (scanf("%d", &num) != 1) {
        printf("Entrada invalida. Digite um numero: ");
        limpar_buffer();
    }
    return num;
}

// Salva toda a estrutura 'biblioteca' em um arquivo binário.
void salvar_biblioteca_em_arquivo() {
    FILE *arquivo = fopen("biblioteca.dat", "wb");
    if (!arquivo) { // Verifica se o arquivo foi aberto com sucesso.
        printf("Erro ao salvar a biblioteca.\n");
        return;
    }
    // Escreve o conteúdo da variável global 'biblioteca' no arquivo.
    fwrite(&biblioteca, sizeof(Biblioteca), 1, arquivo);
    fclose(arquivo);
}

// Carrega os dados de um arquivo binário para a estrutura 'biblioteca'.
void carregar_biblioteca_do_arquivo() {
    FILE *arquivo = fopen("biblioteca.dat", "rb");
    if (!arquivo) {
        printf("Arquivo da biblioteca nao encontrado. Iniciando com lista vazia.\n");
        // Inicializa os contadores como zero.
        biblioteca.total_livros = 0;
        biblioteca.total_usuarios = 0;
        return;
    }
    // Lê o conteúdo do arquivo e o carrega na variável global 'biblioteca'.
    fread(&biblioteca, sizeof(Biblioteca), 1, arquivo);
    fclose(arquivo);// Fecha o arquivo.
}

// Exibe o menu principal e gerencia a navegação inicial.
void menu_principal() {
    int opcao;
    printf("\n--- MENU PRINCIPAL ---\n");
    printf("1-Cadastro\n");
    printf("2-Login\n");
    printf("3-Politica de devolucao e punicao\n");
    printf("0-Sair\n");
    printf("Escolha uma opcao: ");
    opcao = ler_inteiro();
    limpar_buffer();

    // Direciona o fluxo do programa com base na escolha do usuário.
    switch(opcao){
        case 1: tela_cadastro(); break;
        case 2: tela_login(); break;
        case 3: tela_politica(); break;
        case 0: 
            salvar_biblioteca_em_arquivo(); // Salva os dados antes de sair.
            printf("Salvando dados e saindo...\n");
            exit(0); // Encerra o programa.
        default: printf("Opcao invalida.\n");
    }
}

// Lida com o processo de cadastro de um novo usuário.
void tela_cadastro() {
    char usuario[MAX_NOME_SENHA + 1], senha[MAX_NOME_SENHA + 1];
    
    // Verifica se o limite de usuários foi atingido.
    if (biblioteca.total_usuarios >= MAX_USUARIOS) {
        printf("Limite de usuarios atingido.\n");
        return;
    }

    printf("\n--- CADASTRO ---\n");
    printf("Digite seu nome de usuario: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = 0;  // Remove o '\n' capturado pelo fgets.

    // Verifica se o nome de usuário já existe.
    for(int i = 0; i < biblioteca.total_usuarios; i++){
        if(strcmp(biblioteca.usuarios[i].usuario, usuario) == 0){ // Remove o '\n'
            printf("Usuario ja existe!\n");
            return;
        }
    }

    printf("Digite uma senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0;

    // Adiciona o novo usuário ao array.
    strcpy(biblioteca.usuarios[biblioteca.total_usuarios].usuario, usuario);
    strcpy(biblioteca.usuarios[biblioteca.total_usuarios].senha, senha);
    biblioteca.total_usuarios++; // Incrementa o contador de usuários.

    printf("Cadastro realizado com sucesso!\n");
}

// Lida com o processo de login de um usuário existente.
void tela_login() {
    char usuario[MAX_NOME_SENHA + 1], senha[MAX_NOME_SENHA + 1];
    int i, login_sucesso = 0;
    int usuario_logado = -1;// Armazena o índice (ID) do usuário logado.

    printf("\n--- LOGIN ---\n");
    printf("Digite seu nome de usuario: ");
    fgets(usuario, sizeof(usuario), stdin);
    usuario[strcspn(usuario, "\n")] = 0;

    printf("Digite sua senha: ");
    fgets(senha, sizeof(senha), stdin);
    senha[strcspn(senha, "\n")] = 0;

    // Procura pelo usuário e senha correspondentes no array de usuários.
    for (i = 0; i < biblioteca.total_usuarios; i++) {
        if (strcmp(biblioteca.usuarios[i].usuario, usuario) == 0 &&
            strcmp(biblioteca.usuarios[i].senha, senha) == 0) {
            login_sucesso = 1; 
            usuario_logado = i; // Guarda o índice do usuário.
            break; // Sai do loop assim que encontra o usuário.
        }
    }

    if (login_sucesso) {
        printf("Login realizado com sucesso!\n");
        menu_livros(usuario_logado); // Se o login for bem-sucedido, abre o menu de livros.
    } else {
        printf("Usuario ou senha incorretos.\n");
    }
}

// Exibe a política de devolução da biblioteca.
void tela_politica(){
    printf("\n--- POLITICA DE DEVOLUCAO ---\n");
    printf("O prazo para devolucao do livro e de 3 dias.\n");
    printf("Apos este periodo, sera aplicada uma multa de R$ 20,00 por dia de atraso.\n");
    printf("Pressione ENTER para voltar ao menu principal.\n");
    limpar_buffer();
}

// Exibe o menu de gerenciamento de livros após o login.
void menu_livros(int usuario_logado){
    int opcao;
    do {
        printf("\n--- MENU LIVROS ---\n");
        printf("1 - Cadastrar livro novo\n");
        printf("2 - Ver livros disponiveis / Alugar\n");
        printf("3 - Devolver livro\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        opcao = ler_inteiro();
        limpar_buffer();
        
        // Direciona para as funções de gerenciamento de livros.
        switch(opcao){
            case 1: cadastrar_livro(); break;
            case 2: listar_livros(usuario_logado); break;
            case 3: devolver_livro(usuario_logado); break;
            case 0: break; // Sai do loop e volta para o menu principal.
            default: printf("Opcao invalida\n");
        }
    } while(opcao != 0); // O menu continua até o usuário escolher 0.
}

// Cadastra um novo livro na biblioteca.
void cadastrar_livro() {
    // Verifica se o limite de livros foi atingido.
    if(biblioteca.total_livros >= MAX_LIVROS){
        printf("Limite de livros atingido!\n");
        return;
    }
    Livro novo; // Cria uma variável temporária para o novo livro.
    printf("Digite o titulo do livro (max %d caracteres): ", MAX_TITULO);
    fgets(novo.titulo, sizeof(novo.titulo), stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = 0;
    
    printf("Digite o autor do livro (max %d caracteres): ", MAX_AUTOR);
    fgets(novo.autor, sizeof(novo.autor), stdin);
    novo.autor[strcspn(novo.autor, "\n")] = 0;

    printf("Digite o ISBN do livro (13 digitos): ");
    fgets(novo.isbn, sizeof(novo.isbn), stdin);
    novo.isbn[strcspn(novo.isbn, "\n")] = 0;

    // Define os valores iniciais para um livro novo.
    novo.alugado = 0;
    novo.usuario_id = -1;

    // Adiciona o novo livro ao array da biblioteca.
    biblioteca.livros[biblioteca.total_livros] = novo;
    biblioteca.total_livros++;
    printf("Livro cadastrado com sucesso!\n");
}

// Lista todos os livros cadastrados e oferece a opção de alugar.
void listar_livros(int usuario_logado) {
    if(biblioteca.total_livros == 0){
        printf("Nenhum livro cadastrado.\n");
        return;
    }
    printf("\n--- LISTA DE LIVROS ---\n");
    // Percorre o array de livros e exibe suas informações.
    for(int i = 0; i < biblioteca.total_livros; i++){
        printf("%d - %s (%s) - ISBN: %s - Status: %s%s\n",
               i+1,
               biblioteca.livros[i].titulo,
               biblioteca.livros[i].autor,
               biblioteca.livros[i].isbn,
               // Operador ternário para exibir "ALUGADO" ou "DISPONIVEL".
               biblioteca.livros[i].alugado ? "ALUGADO" : "DISPONIVEL",
               // Operador ternário para indicar se o livro foi alugado pelo usuário atual.
               (biblioteca.livros[i].usuario_id == usuario_logado) ? " (SEU)" : "");
    }

    // Sub-menu para alugar um livro.
    printf("\n1 - Alugar um livro\n2 - Voltar\nEscolha uma opcao: ");
    int opcao = ler_inteiro();
    limpar_buffer();
    if(opcao == 1){
        alugar_livro(usuario_logado);
    }
}

// Processa o aluguel de um livro.
void alugar_livro(int usuario_logado) {
    int escolha;
    printf("Digite o numero do livro que deseja alugar: ");
    escolha = ler_inteiro();
    limpar_buffer();
    
    // Valida a escolha do usuário.
    if(escolha < 1 || escolha > biblioteca.total_livros){
        printf("Escolha invalida!\n");
        return;
    }
    // Verifica se o livro já está alugado.
    if(biblioteca.livros[escolha-1].alugado){
        printf("Esse livro ja esta alugado!\n");
    } else {
        // Atualiza o status do livro para alugado.
        biblioteca.livros[escolha-1].alugado = 1;
        // Associa o ID do usuário ao livro.
        biblioteca.livros[escolha-1].usuario_id = usuario_logado;
        printf("Voce alugou o livro: %s\n", biblioteca.livros[escolha-1].titulo);
    }
}
// Processa a devolução de um livro.
void devolver_livro(int usuario_logado) {
    int indices_alugados[MAX_LIVROS]; // Array para mapear a escolha do usuário ao índice real do livro.
    int contador = 0;

    printf("\n--- DEVOLVER LIVRO ---\n");
    // Lista apenas os livros que foram alugados pelo usuário atual.
    for(int i = 0; i < biblioteca.total_livros; i++){
        if(biblioteca.livros[i].alugado && biblioteca.livros[i].usuario_id == usuario_logado){
            contador++;
            indices_alugados[contador-1] = i;
            printf("%d - %s (%s)\n", contador, biblioteca.livros[i].titulo, biblioteca.livros[i].autor);
        }
    }

    if(contador == 0){
        printf("Voce nao possui livros alugados.\n");
        return;
    }

    printf("Digite o numero do livro que deseja devolver: ");
    int escolha = ler_inteiro();
    limpar_buffer();

    // Valida a escolha.
    if(escolha < 1 || escolha > contador){
        printf("Escolha invalida!\n");
        return;
    }

    // Obtém o índice real do livro a partir do array de mapeamento.
    int idx = indices_alugados[escolha-1];
    // Reseta o status do livro para disponível.
    biblioteca.livros[idx].alugado = 0;
    biblioteca.livros[idx].usuario_id = -1;
    printf("Voce devolveu o livro: %s\n", biblioteca.livros[idx].titulo);
}