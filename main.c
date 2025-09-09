#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num1;
int num2;

/*vazio=não precisa de return
void somar(){
    printf("%d\n",(num1+num2));
}*/

int somar(int a, int b, int *p){
    *p=(a+b);
    return 0;
}

//parametros de uma função [tipo] [nome]([parametros]){}
int main() {

    num1=10;
    num2=11;
    int *p;

    printf("%d\n",num1);
    p = &num1;
    *p = 101;
    printf("%d\n",num1);

    //int resultado = somar(10,23);
    int resultado=0;
    somar(12,3,&resultado);
    printf("%d\n",resultado);

    return 0;
}

/* 0149
Tipos de variáveis:

    • int: use para números inteiros, entre −32,767 e +32,767
    • float: use para números de ponto flutuante (com parte decimal), como 1555.456 (para o computador o ponto é a vírgula)
    • double: use para números de ponto flutuante bem grandes (tem duas vezes mais “espaço” que o float)
    • char: use para caracteres, como “a”, “M”, etc
 
    • int: use %d
    • float: use %f
    • double: use %lf
    • char: use %c

Se estiver printando um número de ponto flutuante e quiser definir o número de casas decimais,
pode usar %.2f, por exemplo, para limitar para duas casas decimais.

       int idade;

        printf("\tOlá! Bem-vindo.\n\n");

        printf("Digite sua idade: \n");
        scanf("%d", &idade);

        printf("Você tem \"%d anos\" de idade\n", idade);

Especificadores de formato: printf()

    • %d ou %i = Números em base decimal
    • %x = Números inteiros em base hexa decimal
    • %f = Números em ponto flutuante(com casa decimais)
    • %e = Números em notação científica(com casa decimais)
    • %c = Carácteres alfanuméricos(texto)
    • %s = Sequência de caractéres alfanuméricos(texto)
    • .<num> = Especifica quantos dígitos serão impressos após a vírgula
    
Sequências de escape: printf()

    • \a = Toca um bipe, alarme sonoro padrão do sistema
    • \b = Backspace
    • \n = Quebra de linha
    • \t = Tabulação horizontal(TAB)
    • \r = Retorna ao início da linha
    • \0 = Cractere nulo
    • \v = Tabulação vertical
    
        printf("Meu nome é Francisco\n");
        printf("Tenho \"%i\" anos\n",18);
    
Entrada de dados: scanf()

        int idade;

        printf("Digite sua idade:");
        scanf("%i",&idade);
        printf("Sua idade e: %i",idade);

Progama que fiz:

        char nome[30];
        int idade;
        float peso;

        printf("Digite sua idade:\n");
        scanf("%i",&idade);
        printf("Digite seu peso:\n");
        scanf("%f",&peso);
        printf("Digite seu nome:\n");
        scanf("%s",nome);

        printf("Seu idade é: %i\n",idade);
        printf("Seu peso é: %.f\n",peso);
        printf("Seu nome é: %s\n",nome);

------------------------------------------------------------------------------------------------------------------------------------------        

Operacões com cálculo
  
        int A,B,soma,subtracao,divisao,multiplicacao;  

        printf("Digite o primeiro valor: \n");
        scanf("%i",&A);
        printf("Digite o segundo valor: \n");
        scanf("%i",&B);
    
        soma=A+B;
        subtracao=A-B;
        divisao=A/B;
        multiplicacao=A*B;
    
    
        printf("\n");
        printf("A soma de %i + %i e: %i\n",A,B,soma);
        printf("A subtraçao de %i - %i e: %i\n",A,B,subtracao);
        printf("A divisao de %i / %i e: %i\n",A,B,divisao);
        printf("A multiplicacao de %i * %i e: %i\n",A,B,multiplicacao);

------------------------------------------------------------------------------------------------------------------------------------------                

Atribuições aritméticas

    • Decremento de 1 unidade: --
    • Incremento de 1 unidade: ++
    • Decremento genérico: -=
    • Incremento generérico: +=
    • Atribuição com multiplicação: *=
    • Atribuição com divisão: /=
    
 
        int a=10;
        printf("Valor original: %i\n",a);

        a--;
        printf("Valor --: %i\n",a);
        a++;
        printf("Valor ++: %i\n",a);
        a+=2;
        printf("Valor +=2: %i\n",a);
        a-=2;
        printf("Valor -=2: %i\n",a);
        a/=2;
        printf("Valor /=2: %i\n",a);
        a*=2;
        printf("Valor *=2: %i\n",a);

------------------------------------------------------------------------------------------------------------------------------------------        
Relações lógicas:

    If(se):

        if(condição){
           codigo
        }

    Else(senao):

        else{
           codigo
        }

        Meu código exemplo:

            int nota=0;

            printf("Digite sua nota: \n");
            scanf("%i",&nota);

                if(nota>=7){
                    printf("Voce esta aprovado!");
                }
                else{
                    printf("Voce esta reprovado!");
                }
    

Operadores relacionais

    • Maior (>): >
    • Maior ou igual(>=): >=
    • Menor (<): <
    • Maior ou igual(<=): <=
    • Igual(=): ==
    • Diferente(≠): !=

Operadores lógicos

    Conjunção("e"): &&
    Disjunção("ou"): ||
    Inversão("não"): !

Meu código:

//Escrever uma calculadora

        char sexo;
        int A,B,multiplicacao;

        printf("Digite primeiro valor: \n");
        scanf("%i",&A);
        printf("Digite o segundo valor: \n");
        scanf("%i",&B);
        printf("Digite seu sexo (f ou m): \n");
        scanf(" %c",&sexo);


            if(sexo=='m' || sexo=='M'){

                multiplicacao=(A+B)*2;

                printf("Resultado e: %i\n",multiplicacao);
            }
            else if(sexo=='f' || sexo=='F'){

                multiplicacao=A+B;

                printf("Resultado e: %i\n",multiplicacao);
            }

Estrutura do escolha caso:

    switch = escolha
    switch(variavel selecionada){

        case n1:
            <Código a ser escrito>
            break;------>pare

        case n2:
            <Código a ser escrito>
            break;------>pare

        default:-------->caso contrário
            <Código a ser escrito>
            break;------>pare
            
    Código exemplo:

        int n;

        printf("Escolha um número de 1 ate 7 para indicar um dia da semana:\n");
        scanf("%i",&n);

        switch (n)
        {
        case 1:
            printf("Hoje e segunda-feira!");
            break;

        case 2:
            printf("Hoje e terca-feira!\n");
            break;

        case 3:
            printf("Hoje e quarta-feira!\n");
            break;

        case 4:
            printf("Hoje e quinta-feira!\n");
            break;

        case 5:
            printf("Hoje e sexta-feira!\n");
            break;

        case 6:
            printf("Hoje e sabado!\n");
            break;

        case 7:
            printf("Hoje e domingo!\n");
            break;

        default:
            printf("Insira uma opcao valida!\n");
            break;
        }

------------------------------------------------------------------------------------------------------------------------------------------

Laços de repetições

Comando while(Enquanto):
    
    • Inicialização de uma ou mais variáveis de controle                    !!!NOTA!!!
    • Definição de uma condição de parada                       Se lembrar de iniciar as variáveis
        -> Enquanto for verdadeira: repete
    •Atualização da(s) variável(eis) de controle
    ->Loop infinito

Sintaxe:

    while(<condição>){
        <comando>
    }

    Meu código:

        int i=1; // O ponto de partida começa no 1
    
        while (i<=10) //enquanto i for menor ou igual a 10
        {
            printf("%i - ",i); 
            i++; // adicione 1
        }


for: Perfeito para quando você sabe o número de repetições. (Ex: "Repita 10 vezes").

while: Perfeito para quando você não sabe o número de repetições, mas sabe a
condição para parar. Ele primeiro testa, depois faz. (Ex: "Enquanto a porta estiver fechada, continue tentando abrir").

do-while: Quase igual ao while, mas ele primeiro faz, depois testa. Garante que a ação aconteça pelo menos uma vez. 
(Ex: "Mostre o menu uma vez, depois continue mostrando enquanto o usuário não escolher sair").
*/

/*  Códigos que fiz usando Laços de repetição
-+-+-+-+-+-+-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+--+-+-+-++-+-+-+--+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+++-+-+-+-+-+-+-++-+--

---> Construção de um triângulo com repetições:

    int main()
{
    int altura;
    int linha;  
    int coluna;  

    printf("Digite a altura do triangulo: ");
    scanf("%d", &altura);

    printf("\nAqui esta o seu triangulo:\n\n");

    for (linha = 1; linha <= altura; linha++) {

        for (coluna = 1; coluna <= linha; coluna++) {

            printf("*");
        }

        printf("\n");

}
    return 0;
    }

===> Código de soma (Usei uma forma de armazenar valores e somalos depois)/ For:

    int N;
    int i;
    int soma=0;

    printf("Digite um numero inteiro positivo: \n");
    scanf("%i",&N);

        for ( i = 0; i <= N; i++)
        {

            if (i % 2 == 0)
            {
                soma+=i;
            }
        }
        
        printf("A soma de todos os numeros pares de 1 a %d e: %d\n", N, soma);

--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++--++

==> outro parecido mas com fatorial:

    int num;
    int i;
    int fat=1;

    printf("Digite um número para calcular o seu fatorial: \n");
    scanf("%i",&num);

        for ( i = num; i > 1; i--)
        {
            fat*=i;
        }
    printf("O fatorial de %i e: %i",num,fat);

*/

/*
Exemplo de execução (para entrada 4):

Digite o tamanho do lado do quadrado: 4

****
****
****
****

Dica: É muito parecido com o desafio do triângulo. O laço de fora controla as linhas. O laço de dentro controla as colunas. 
A diferença é que, para um quadrado, o número de colunas é sempre igual ao lado do quadrado, não dependendo mais do número da linha.
*/

/*

#include <stdio.h>

#include <string.h>

struct PC {

    int codigo;

    char Usuario[41];  

    float uso_disc;

    char status;

};

int main(){

    struct PC biblioteca;

   

    printf("--- REGISTRO DE MAQUINAS ---\n");

    printf("Digite o seu codigo de registro: ");

    if (scanf("%d%*c", &biblioteca.codigo)!= 1){

        printf("Digite um codigo valido!\n");

        return 1;

    }

    printf("Digite o seu usuario(ate 15 caracteres): \n");

    if (scanf("%40[^\n]%*c", biblioteca.Usuario) != 1){

        printf("Digite usuario valido!");

         return 1;

    }

    printf("Digite a Porcentagem de Uso do Disco (ex: 75.5): \n");

    if (scanf("%f%*c", &biblioteca.uso_disc) !=1 || biblioteca.uso_disc < 0.0 || biblioteca.uso_disc > 100.00) {

        printf("Digite um numero valido!");

        return 1;

    }

    printf("O computador esta ligado? (1 para sim, 0 para nao)\n");

    char temp_status_char;

    if (scanf(" %c%*c", &temp_status_char) != 1 || (temp_status_char != '0' && temp_status_char != '1')) {

            printf("Por favor digite uma entrada valida! (1 ou 0)\n");

        return 1;

    }

        biblioteca.status = temp_status_char;



        printf("=-=-REGISTRO FINALIZADO=-=-\n");

        printf("Codigo: %d\n", biblioteca.codigo);

        printf("Usuario: %s\n", biblioteca.Usuario);

        printf("Uso de disco: %f2.%%\n", biblioteca.uso_disc);



        if(biblioteca.status == '1'){

            printf("O computador esta ligado!\n");

        } else if(biblioteca.status == '0'){

            printf("O computador esta desligado\n");

        } else {printf("Status Desconhecido!\n");}



            return 0;

}

*/

/*
struct PC {

    int codigo;
    char Usuario[41];  
    float uso_disc;
    char status;

};

int Registro(){

    

            return 0;
    }

int main()
{
    
    int menu;
    
    printf("\t- MENU -\n");
    printf("1. Registro dos computadores.\n");
    printf("2. Mostre todos os computadores que estão ligados.\n");
    printf("3. Mostre o nome do usuário que está utilizando o computador com maior uso de disco, em um laboratório informado pelo usuário (0, 1 ou 2).\n");
    printf("4. Permita que o usuário busque por código e veja os dados de um computador específico, independente do laboratório.\n");
    printf("\n");
    scanf("%i",&menu);

        switch (menu)
        {
        case 1:
            
            struct PC biblioteca;

        printf("--- REGISTRO DE MAQUINAS ---\n");
        printf("Digite o seu codigo de registro: ");

            if (scanf("%d%*c", &biblioteca.codigo)!= 1){
                printf("Digite um codigo valido!\n");

            return 1;
        }
        printf("Digite o seu usuario(ate 15 caracteres): \n");

            if (scanf("%40[^\n]%*c", biblioteca.Usuario) != 1){
                printf("Digite usuario valido!");

             return 1;
        }
        printf("Digite a Porcentagem de Uso do Disco (ex: 75.5): \n");

            if (scanf("%f%*c", &biblioteca.uso_disc) !=1 || biblioteca.uso_disc < 0.0 || biblioteca.uso_disc > 100.00) {
                printf("Digite um numero valido!");

            return 1;
        }

        printf("O computador esta ligado? (1 para sim, 0 para nao)\n");

        char temp_status_char;

        if (scanf(" %c%*c", &temp_status_char) != 1 || (temp_status_char != '0' && temp_status_char != '1')) {
            printf("Por favor digite uma entrada valida! (1 ou 0)\n");

        return 1;
    }
        biblioteca.status = temp_status_char;

        printf("=-=-REGISTRO FINALIZADO=-=-\n");
        printf("Codigo: %d\n", biblioteca.codigo);
        printf("Usuario: %s\n", biblioteca.Usuario);
        printf("Uso de disco: %.2f %%\n", biblioteca.uso_disc);

        if(biblioteca.status == '1'){
            printf("O computador esta ligado!\n");

        } else if(biblioteca.status == '0'){
            printf("O computador esta desligado\n");

        } else {printf("Status Desconhecido!\n");}    

            break;
        
        case 2:
        
           break;
        
        case 3:
             code *
            break;
        
        case 4:
            * code *
            break;
        
        default:
            break;
        }
*/


/* Ponteiros

• Guarda endereço de memória em outra variável
• Manipulação de memória
• Qualquer tipo de dado, seu tamanho se baseia nisso

Declaração e iniação

    int *ptr;


*/