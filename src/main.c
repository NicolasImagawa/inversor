/* Data de submissao: 16/03/2020
 * Nome: Nicolas de Sousa Imagawa
 * RA:204147
 */

#include <stdio.h>
#include <string.h>

int main()
{
	/*input_str recebe a string de entrada pelo terminal e output_str devolve a string invertida.*/
	unsigned char input_str[300];
	unsigned char output_str[300];
	
	/*length salva o tamanho da string de entrada.*/
	int length;
	
	/*
	counter eh a referencia para as iteracoes do loop "for" externo deste codigo.
	Da mesma maneira, counter2 se refere as iteracoes do "for" interno.
	*/
	int counter;
	int counter2;
	/*
	Subcounter atua como um contador de caracteres ate que surja um espaco em braco na string.
	Tal variavel foi implementada para dividir a string de entrada e inverter as palavras do
	modo desejado.
	*/
	int subcounter;
	
	/*
	sub_str_end serve de referencia para determinar o limite inferior que sera escrito na string
	de saida. Ou seja, quando ha mais de uma palavra no vetor de entrada, deve-se atualizar a
	posicao de escrita na string de saida respeitando a ordem desejada.
	*/
	int sub_str_end;
	
	/*
	aux foi criada para escrever a palavra na ordem contraria a contagem do loop, para que fosse
	possivel inverter uma parte da string de entrada.
	*/
	int aux;
	
	/*
	scanf esta escrito assim para que tambem detectasse espacos em branco.
	*/
	scanf("%[^\n]", input_str);
	
	length = strlen(input_str);
	
	/*
	Inicialmente aux e sub_str_end sao 0.
	*/
	aux = 0;
	sub_str_end = 0;
	
	/*
	o for externo tem a funcao de contar o numero de caracteres antes de um espaco em branco.
	*/
	for(counter = 0; counter < length; counter++)
	{
		if(input_str[counter] != 32)
		{
			subcounter++;
		}
		
		/*
		Ao detectar um espaco em branco, interpreta-se que a primeira palavra da string acabou
		e assim, inverte-se a palavra.
		*/
		if((input_str[counter] == 32)||(counter == length - 1)) //
		{
			for(counter2 = subcounter - 1; counter2 >= sub_str_end; counter2 --)
			{
				output_str[aux] = input_str[counter2];
				aux = aux + 1;
			}
			
			/*
			Apos escrever a palavra invertida na string de saida, adiciona-se um espaco em
			branco para respeitar o resultado requisitado.
			*/
			if(counter < (length - 1))
			{
				output_str[aux] = 32;
			}
			/*
			Devido também ao espaco em branco, subcounter e aux devem ser atualizados de
			maneira a evitar a sobrescrita na string de saida.
			*/
			subcounter = subcounter + 1;
			aux = aux + 1;
			
			/*Atualiza-se sub_str_end para o novo limite inferior de escrita.*/
			sub_str_end = subcounter;
		}
	}
	
	/*Print da string invertida.*/
	for(counter = 0; counter < length; counter++)
	{
		printf("%c", output_str[counter]);
	}
	printf("\n");
	return 0;
}
