# -Jogo-Da-Cobrinha
Projeto De Estutura De Dados - Jogo Da Cobrinha


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct {
    int x, y;
} NO;

typedef struct {
    NO* arr;
    int pos, MAX;
} LISTA;
void criar(LISTA* lst) {
    lst->MAX = 10;
    lst->pos = 0;
    lst->arr = (NO*)malloc(sizeof(NO) * lst->MAX);
 
    
}

void apagar(LISTA* lst) {
    free(lst->arr);
}

int main() {
    int a;
    printf("Jogo Da Cobrinha , Aluno: Joao Gabriel Tavares De Vasconcelos Souza\n");
    printf("movimentacao: w = cima ; s = baixo ; d = direita ; a = esquerda\n");
    printf("para comecar aperte qualquer caracter, se for de movimento o boneco comecara andando naquela direcao\n");
  
    scanf_s("%d", &a);

    char matrix[20][40];
    char termo[1];
    srand(time(NULL));
    int m_linha = 6;
    int m_coluna = 6;
    int x_m = rand() % (16 - 3 + 1) + 3;
    int y_m = rand() % (36 - 3 + 1) + 3;
    matrix[x_m][y_m] = '@';//colocando a maçã
    LISTA COBRA;
    criar(&COBRA);
    COBRA.arr[0].x = 6;
    COBRA.arr[0].y = 6;
    COBRA.pos++;
    char lixo[1];
    char imagem[100] = {'O','o','o','o','o'};
    int k = 4;
    int aumentar = 1;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 40; j++) {
            matrix[i][j] = ' ';     
            }
        }
    while (1) {
        
        
        if (matrix[COBRA.arr[0].x][COBRA.arr[0].y] == matrix[x_m][y_m]) {//se a cobra bater na maçã
            x_m = rand() % (16 - 3 + 1) + 3;
            y_m = rand() % (37 - 3 + 1) + 3;

        }for (int l = 1; l < 18; l++)
            for (int c = 0; c < 38; c++)
                matrix[l][c] = matrix[18][38];
        
            if (COBRA.pos > 1) {
                COBRA.pos--;
                
                for (int i = COBRA.pos; i > 0; i--) {
                   
                    COBRA.arr[i].x = COBRA.arr[i-1].x;//craain a posição de x e y 
                    COBRA.arr[i].y = COBRA.arr[i-1].y;
                }
                COBRA.pos++;
                
            }
            //if(COBRA.pos <= 1)
                //matrix[COBRA.arr[0].x][COBRA.arr[0].y] = matrix[18][38];
            if (termo[0] == 'w') {
                
                COBRA.arr[0].x -= 1;


            }

            else if (termo[0] == 'a') {

                COBRA.arr[0].y -= 1;

            }
            else if (termo[0] == 's') {
                COBRA.arr[0].x += 1;

            }
            else if (termo[0] == 'd') {

                COBRA.arr[0].y += 1;

            
            

            }
            for (int i = 0; i < COBRA.pos; i++) {
                matrix[x_m][y_m] = '@';
                matrix[COBRA.arr[i].x][COBRA.arr[i].y] = imagem[i];
              
            }
        


      
   
                
            system("cls");
        //desenhando o mapa



            for (int i = 0; i < 20; i++) {
                for (int j = 0; j < 40; j++) {
                    if (i == 0 || i == 19 || j == 0 || j == 39) {
                        matrix[i][j] = '#';
                    }
                    printf("%c", matrix[i][j]);
                }
                printf("\n");
            }int p = 0;
        for (int i = 1; i < COBRA.pos; i++) {
            if(COBRA.arr[0].y == COBRA.arr[i].y && COBRA.arr[0].x == COBRA.arr[i].x){
                p++;
            }
        
        }
        if (COBRA.arr[0].x == 1 || COBRA.arr[0].x == 18 || COBRA.arr[0].y == 1|| COBRA.arr[0].y == 38 || p == 1) {
            printf("Game over\n");
            break;
        }

        if (matrix[x_m][y_m] == matrix[COBRA.arr[0].x][COBRA.arr[0].y]) {//crescendo cobra
            matrix[x_m][y_m] = matrix[x_m][y_m + 1];//apagando a maçã
            COBRA.pos++;
            imagem[k] = 'o';
            k++;
            COBRA.MAX++;
            
        }
        lixo[0] = termo[0];
        char term = 'x';
        
        scanf_s("%c", &term);
        if ((term == 'd' && lixo[0] != 'a') || (term == 'a' && lixo[0] != 'd')|| (term == 's' && lixo[0] != 'w') || (term == 'w' && lixo[0] != 's')) {
            termo[0] = term;
           

        }
    }
    apagar(&COBRA);
    return 0;
}

