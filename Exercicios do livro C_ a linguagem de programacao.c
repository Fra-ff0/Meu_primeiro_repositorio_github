#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*


Projeto 2: Gerenciador de Tarefas (Todo List)

Desenvolver um sistema simples de gerenciamento de tarefas, onde o usuário pode organizar tarefas pessoais ou acadêmicas.

Funcionalidades:

Adicionar tarefas, solicitando:

Descrição não vazia e com tamanho limitado.
Prioridade numérica entre 1 (mais alta) e 5 (mais baixa).
Listar todas as tarefas ou apenas as pendentes.
Marcar tarefas como concluídas.
Remover tarefas, com confirmação da ação.

Tratamento de entrada:

Garantir que a prioridade seja um número válido.
Validar escolhas do menu (opções inválidas devem ser rejeitadas com aviso).
Informar claramente o usuário sobre erros e permitir nova tentativa.


*/
    void adicionar_tarefas();//organizar tarefas pessoais ou acadêmicas.
    void consultar_tarefas();
    void marcar_tarefas();
    
    int main(){
        setlocale(LC_ALL, "pt_BR.UTF-8");
        int menu;
do{
        printf("\n\tMenu\n");
        printf("1_ Adicionar tarefas\n");
        printf("2_ Consultar tarefas\n");
        printf("3_ Marcar tarefa como concluída\n");
        printf("4_ Sair\n");
        scanf("%i",&menu);
        system("cls");

        while (getchar() != '\n');

        switch (menu)
        {
        case 1:
            adicionar_tarefas();
            break;
        case 2:
            consultar_tarefas();
            break;
        case 3:
            marcar_tarefas();
            break;
        case 4:
            printf("Saindo...");
            system("cls");
            break;
        
        default:
            break;
        }}while (menu != 4);
        
        void adicionar_tarefas();{/*       
    Descrição não vazia e com tamanho limitado.
    Prioridade numérica entre 1 (mais alta) e 5 (mais baixa).
    Listar todas as tarefas ou apenas as pendentes.
    Marcar tarefas como concluídas.
    Remover tarefas, com confirmação da ação.*/
            int;
           
        }    
        
        return 0;
    }
    