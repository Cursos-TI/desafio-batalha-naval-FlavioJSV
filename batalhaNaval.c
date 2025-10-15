#include<stdio.h>

void limparTabuleiro(int tabuleiro[10][10]){ //Condição para limpar o tabuleito.
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro[i][j] = 0;
        }
    }
}


int main () {  

  char coluna[] = {'A','B','C','D','E','F','G','H','I','J'}; //Declaração da coluna.
  int tabuleiro[10][10] = {0}; //Declaração da matriz 10x10.
  int opcao;        

    do{ //Loop (do-while) para escolhe as opçãos.      
      printf("\n  JOGO BATALHA NAVAL!!");    
      printf("\nDigite a opção desejada!\n");    
      printf("1 - Horizontal e Vertical\n");
      printf("2 - Diagonais\n");
      printf("3 - Cone\n");
      printf("4 - Cruz\n");
      printf("5 - Octaedro\n");
      printf("0 - Sair do Programa\n");
      scanf("%d", &opcao);

      if (opcao >= 1 && opcao <= 5){
        limparTabuleiro(tabuleiro); //Limpando tabuleiro após cada opção impressa.
      }      
       
        switch (opcao){
        case 1: //Imprimindo horizontais e verticais.          
            for (int h = 2 ; h <= 4 ; h++){
            tabuleiro[0][h] = 3; //Posicionamento Horizontal.
              tabuleiro[h][8] = 3; //Posicionamento Vertical.
            }
        break;     
        
        case 2: //imprimindo diaginais.            
            for (int i = 2; i <= 4 ; i++){
              tabuleiro[i][i] = 3; //Esquerda para direita.       
              tabuleiro[i][9 - i] = 3; //Direita para esquerda.
            }              
        break; 
        
        case 3: //imprimindo Cone.
            for (int i = 0; i < 5; i++){ //Limite do cone.
              for (int j = 0; j < 10; j++){ //Imprimindo da esquerda para direita.            
                if (j >= 4 - i && j <= 4 + i){ //Desenhando a base descendo.
                  tabuleiro[i + 2][j] = 3; //Começa na linha 2 e termina na 9.
                }
              }
            }            
        break;

        case 4: //Imprimindo uma cruz.
            for (int i = 2; i < 8; i++){ //Linha começa da 2 e termina na 8.
              for (int j = 2; j < 8; j++){ //Coluna começa na 2 e termina na 8.
                if (i == 4 || j == 4){ //Centro do tabuleiro.
                    tabuleiro[i][j] = 3;
                }
              }
            }            
        break;

        case 5: //Imprimindo Octaedro.
            for(int i = 0; i < 10; i++){
              for(int j = 0; j < 10; j++){       
                  int di = (i - 4 < 0) ? 4 - i : i - 4; //Centralizando a linha.    
                  int dj = (j - 4 < 0) ? 4 - j : j - 4; //Centralizando a coluna.
                  
                  if(di + dj <= 4) {//Definido o tamanho
                      tabuleiro[i][j] = 3;
                  }
              }              
            }
        break;

        case 0:           
          printf("\nSaindo do Programa..."); 
          break;                     
        
        default:
          printf("\nEntrada Invalida!");            
      }  
        
      //Criando tabuleiro.
      if (opcao < 6 && opcao > 0){ //Apos cada opção válida, imprime novamente o tabuleiro.
         for (int c = 0; c < 10; c++){        
          printf("  %c", coluna[c]); //Imprime coluna (A a J). 
         }
          
          for (int i = 0; i < 10; i++){    
              printf("\n"); //Pulando linha nas linhas (1 a 10).
                printf("%-2d", i + 1); //Imprimindo linhas e adc +1 para imprimir a partir do 1 e não do 0.
                  for (int y = 0; y < 10; y++){
                    printf("%d  ", tabuleiro[i][y]); //Imprimindo tabuleiro 10x10.
                  }      
        
          }
      }printf("\n");       
    }

    while (opcao != 0); //Se a entrada for maior que 6 ou 0, volta ao menu inicial
     
  return 0;
};

/*#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

    return 0;
}*/
