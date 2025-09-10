#include <stdlib.h>
#include <stdio.h>

    int Operacao(int a, int b);

    int main(){

        int a = 0, b = 0, r = 0;
        scanf("%i",& a);
        scanf("%i",& b);
        system("cls");

    if(a > 0 && b > 0){
        while (b != 0) {

        r = Operacao(a, b);
        a = b;
        b = r;

        printf("Proximo a = %i, Proximo b = %i\n", a, b);

        }

        printf("\nO Maximo Divisor Comum (MDC) e: %i\n", a);
    }
         
    else if(a == 0 && b > 0){
        printf("\nO numero %i ja e o maximo divisor comum.\n",b);
    }
    else if(a > 0 && b == 0){
        printf("\nO numero %i ja e o maximo divisor comum.\n",a);
    }
    else if(a == 0 && b == 0){
        printf("\nO numero %i ja e o maximo divisor comum.\n",a);
    }
    else{
        printf("\nDigite uma entrada valida!\n");
    }
    
    return 0;
    
}

    int Operacao(int a, int b){
       
        int operacao = a % b; 

        return operacao;
    }