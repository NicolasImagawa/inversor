/* Data de submissao: 16/03/2020
 * Nome: Nicolas de Sousa Imagawa
 * RA:204147
 */

#include <stdio.h>
#include <string.h>

int main(){
	
	/*String para armazenar os dados de entrada.*/
	unsigned char input_str[100];
	
	/*Como ha casos com mais de uma palavra para ser invertida, fez-se uma matriz onde cada palavra
	eh armazenada em uma de suas linhas, basicamente, um vetor de strings.*/
	unsigned char str_vect[100][100];
	
	/*Row e column sao os indicadores de linha e coluna da matriz respectivamente.*/
	int row = 0;
	int column = 0;
	
	/*Para as palavras invertidas, se usa outra matriz.*/
	unsigned char out_str_vect[100][100];
	
	/*Len serve para armazenar o tamanho de cada string.*/
	int len = 0;
	
	/*Counter fara a contagem de letra apos letra de uma string de entrada.*/
	int counter = 0;
	
	/*Rev_counter faz a contagem reversa quando for necessario escrever dados na matriz de saida.*/
	int rev_counter = 0;
	
	/*X e Y sao os contadores para a posicao na matriz ao realizar o processo de inverter os dados de entrada.*/
	int x = 0;
	int y = 0;
	
	/*Scanf para a entrada.*/
	scanf("%[^\n]", input_str);


	/*Enquanto o fim da string de entrada nao ocorre.*/
	
	while(input_str[counter] != '\0'){
		
		/*Se o char em questao nao eh um espaco em branco
		escreve-se o elemento na matriz de strings e passa-se para o proximo char da palavra.*/
		if(input_str[counter] != ' '){
			str_vect[row][column] = input_str[counter];
			column = column + 1;
		}
		
		/*Em caso de espaco em branco, entende-se que ha uma palavra nova e assim, uma nova linha da matriz
		sera usada para escrita de caracteres.*/
		else if(input_str[counter] == ' '){
			str_vect[row][column] = '\0';
			row = row + 1;
			column = 0;
		}
		
		/*Incremento da posicao da string de entrada.*/
		counter++;
	}
	
	/*Enquanto o contador x for menor do que o numero de linhas escritas da matriz de strings.*/
	while(x <= row){
		
		/*Usa-se len para saber o numero de letras da palavra em questao*/
		len = strlen(str_vect[x]);
		/*Atribui-se a rev_counter o inicio da contagem reversa.*/
		rev_counter = len - 1;
		
		/*Enquanto o contador y for menor do o numero de letras de uma palavra da matriz.*/
		while(y < len){
			
			/*Inversao de uma palavra da matriz e escrita da invertida na matriz de saida.*/
			out_str_vect[x][rev_counter] = str_vect[x][y];
			rev_counter = rev_counter - 1;
			y = y + 1;
		}
		
		/*Com y = 0, eh possivel ler a proxima palavra da esquerda para a direita.*/
		y = 0;
		
		/*Inicio da analise da proxima palavra.*/
		x = x + 1;
	}
	
	/*Print da matriz com palavras invertidas.
	Como os espacos nao foram adicionados a matriz inicial, aqui tambem eh adicionado
	um espaco em branco entre duas palavras.*/
	x = 0;

	while (x <= row){
		if(x < row){
			printf("%s", out_str_vect[x]);
			printf("%c", 32);
		}
		
		else if(x == row){
			printf("%s", out_str_vect[x]);
		}
		x = x + 1;
	}
	printf("\n");
	return 0;
}
