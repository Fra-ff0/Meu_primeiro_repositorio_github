#include <stdio.h>      // Informções direcionadas ao senhor professor: - Tivemos um prazo de 1 semana para lhe entregar esse trabalho, certo?
#include <stdlib.h>     //                                              - Tivemos muita dificuldade de fazer no início mas, mesmo asssim continuamos a tentar todos dias.
#include <string.h>     //                                              - Foi dificil no começo mas, revisamos os principais tópicos e aprendemos outros novos  
#include <limits.h>     //                                                para trazer mais praticidade ao trabalho.
                        //                                              - Esperamos que possa compreender como foi feito este código.      At.te: Caio, Sávio e Francisco 
#define num_max_computadores 30      
#define num_laboratorios 3     

struct cadastro
{
    int identificacao; // Número do usuário
    char usuario [41]; // Nome do usuário
    float uso_disco;   // % do uso do disco
    int status;        // 1 = Ligado ou 0 = Desligado
};

// Os protótipos das funções são declarados fora do escopo principal do main()
// Declarei literalmente cada nome de cada função com seu respectivo objetivo no código, afim de facilitar a indetificação

void cadastro_de_computadores(struct cadastro laboratorios[][num_max_computadores], int numero_computadores[]);
void mostrar_computadores_ligados(const struct cadastro laboratorios[][num_max_computadores], const int numero_computadores[]);
void usuario_com_maior_uso(const struct cadastro laboratorios[][num_max_computadores], const int numero_computadores[]);
void buscar_computador_por_codigo(const struct cadastro laboratorios[][num_max_computadores], const int numero_computadores[]);

int main(){

    struct cadastro registro[num_laboratorios][num_max_computadores];
    int numero_computadores[num_laboratorios] = {0};
    int menu;

do{
    printf("\n\t-x- Menu IFCE -x-\n\n");
    printf("1_ Cadastrar computadores\n");
    printf("2_ Mostrar computadores ligados\n");
    printf("3_ Usuario com maior uso de disco por laboratorio\n");
    printf("4_ Buscar computador por codigo\n");
    printf("5_ Sair\n");
    printf("\n=> Selecione uma opcao: ");
    scanf("%i",&menu);

    while (getchar() != '\n'); // esse getchar está aqui para evitar erros possíveis em próximas leituras

    switch (menu) // Cada case está declaro para sua função específica
    {
    case 1:
        cadastro_de_computadores(registro, numero_computadores);
        break;
    
    case 2:
        mostrar_computadores_ligados(registro, numero_computadores);
        break;
    
    case 3:
        usuario_com_maior_uso(registro, numero_computadores);
        break;
    
    case 4:
        buscar_computador_por_codigo(registro, numero_computadores);
        break;
    
    case 5:
        printf("\n=> Saindo...\n\n");
        break;
    
    default:
        printf("-x- Selecione um valor valido! -x-\n");
        break;
    }
}while (menu!=5);
 
    return 0;
}

void cadastro_de_computadores(struct cadastro laboratorios[][num_max_computadores], int numero_computadores[]){
    int lab;
    int n_computadores;

    printf("--> Informe qual laboratorio para cadastro (0, 1 ou 2): ");
    scanf("\n%d", &lab);

        if(lab < 0 || lab >= num_laboratorios){
            printf("\n-x- Selecione um valor valido! -x-\n");
            return;
        }

    printf("--> Quantos computadores voce deseja cadastrar no laboratorio %i (ate %i)? ",lab,num_max_computadores);
    scanf("%i",&n_computadores);

        if (n_computadores < 0 || n_computadores > num_max_computadores){
        printf("\n-x- Insira um valor valido! -x-\n");    
        return;
        }

    numero_computadores[lab] = n_computadores;
    printf("\n-x- Cadastro no Laboratorio %d -x-\n", lab);

    for (int i = 0; i < n_computadores; i++){
        printf("\n\t-x- Computador %i -x-\n", i + 1);
        printf("\n=> Codigo de identificacao: ");
        scanf("%i", &laboratorios[lab][i].identificacao);

        printf("=> Nome do usuario logado: ");
        scanf(" %40[^\n]", laboratorios[lab][i].usuario); /* Estavamos tendo problema com esse scanf pelo motivo da leitura não funcionar corretamente(O scanf não lia os espaços), 
        por isso fizemos uma pesquisa para descobrir o porque não funcionava a leitura corretamente, constatamos que a maneira com o qual a gente declarava era errada para ler a 
        string, utilizamos o livro "C completo e total" disponibilizado pele senhor e exemplos de códigos na internet para contornar esse erro.*/

        printf("=> Porcentagem de uso do disco: ");             
        scanf("%f", &laboratorios[lab][i].uso_disco);

        printf("=> Status (1=ligado, 0=desligado): ");
        scanf("%i", &laboratorios[lab][i].status);
    }
    printf("\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-");
    printf("\n-x- Cadastro concluido com sucesso! -x-\n");
    printf("-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n");
}

void mostrar_computadores_ligados(const struct cadastro laboratorios[][num_max_computadores], const int numero_computadores[]){
    printf("\n-x- Computadores Ligados -x-\n");
    int encontrou = 0;

    // Para percorrer uma matriz utilizasse 2 for
    for(int i = 0; i < num_laboratorios; i++){
        for (int h = 0; h < numero_computadores[i]; h++)
        {
            if(laboratorios[i][h].status == 1){
                printf("\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n");
                printf("\n=> Laboratorio: %d\n", i);
                printf("=> Codigo: %d\n", laboratorios[i][h].identificacao);
                printf("=> Usuario: %s\n", laboratorios[i][h].usuario);
                printf("=> Uso do disco: %.2f%%\n", laboratorios[i][h].uso_disco);
                encontrou = 1;
            }
        }
    }

    if(!encontrou){
        printf("\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n");
        printf("-x- Nenhum computador ligado encontrado -x-");
    }
    printf("\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n");
}

void usuario_com_maior_uso(const struct cadastro laboratorios[][num_max_computadores], const int numero_computadores[]){
    int lab;
    printf("\n--> Informe o laboratorio para a busca (0, 1 ou 2): ");
    scanf("%i", &lab);

        if(lab < 0 || lab >= num_laboratorios){
            printf("\n-x- Laboratorio invalido! -x-\n");
            return;
        }

        if (numero_computadores[lab] == 0) {
        printf("\n-x- Nenhum computador cadastrado no laboratorio %i -x-\n", lab);
        return;
    }

    float maiorUso = -1.0;
    int indiceMaiorUso = -1;

    for (int i = 0; i < numero_computadores[lab]; i++) {
        if (laboratorios[lab][i].uso_disco > maiorUso) {
            maiorUso = laboratorios[lab][i].uso_disco;
            indiceMaiorUso = i;
        }
    }

    if (indiceMaiorUso != -1) {
        printf("\n-x- Maior Uso de Disco no Laboratorio %i -x-\n", lab);
        printf("\n=> Usuario: %s\n", laboratorios[lab][indiceMaiorUso].usuario);
        printf("=> Com um uso de disco de: %.2f%%\n", maiorUso);
        printf("\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n");
    } else {
        printf("\n-x- Nao foi possivel determinar o maior uso de disco no laboratorio %i -x-\n", lab);
    }
}
void buscar_computador_por_codigo(const struct cadastro laboratorios[][num_max_computadores], const int numero_computadores[]){
    int codigo;
    printf("\n--> Digite o codigo de identificacao do computador a ser buscado: ");
    scanf("%d", &codigo);

    int encontrou = 0;
    for (int i = 0; i < num_laboratorios; i++) {
        for (int h = 0; h < numero_computadores[i]; h++) {
            if (laboratorios[i][h].identificacao == codigo) {
                printf("\n-x- Informacoes do computador -x-\n");
                printf("\n=> Laboratorio: %i\n", i);
                printf("=> Codigo: %i\n", laboratorios[i][h].identificacao);
                printf("=> Usuario: %s\n", laboratorios[i][h].usuario);
                printf("=> Uso do disco: %.2f%%\n", laboratorios[i][h].uso_disco);
                printf("=> Status: %s\n", laboratorios[i][h].status == 1 ? "Ligado" : "Desligado"); // -> utilizamos um operador ternário ensinado pelo 
                                                                                                    //    senhor em sala para diminuir o uso de if e else
                printf("\n-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-\n");
                encontrou = 1;
                
            }
        }
    }

    if (!encontrou) {
        printf("\n-x- Computador com o codigo %i nao encontrado -x-\n", codigo);
    }
}