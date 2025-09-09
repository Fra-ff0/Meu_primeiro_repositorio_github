#include <stdio.h>
#include <stdlib.h>

#define  alunos 5
#define  notas 5


float calculo_notas(int a, int b);

int main(void){
    //int matriz [alunos][notas];
    float medias [5];

        for(int i = 0; i < 5; i++){
            scanf("%f",& medias[i]);
                
        }
            for(int j = 0; j < 5; j++){
                printf("%.2f\n",medias[j]);
                }

        
        
    return 0;
}
/*
float calculo_notas(int a, int b){
    float resultado = (a + b) / 2;
    return resultado;
}*/