#include <stdio.h>
#include <math.h>
#include <time.h>

/*  Crivo de Eratóstenes 
 *
 *  Implantação do crivo de Eratóstenes em linguagem C
 */

int main(){	
	//Declaração de variaveis;
	clock_t tInicio, tFim;
	double tGasto;
	int  max = 500000,
		 mult = 0,
		 i = 0,
		 k = 0,
		 c = 0,
		 j = 0,
		 count = 0,
		 max_num = 0,
		 list[max];
	
	//Inicio do timer.
	tInicio = clock();	
	
	//Popular o Array do 2 até o maximo;
	for(i = 0; i < max; i++)
		list[i] = i + 2;
	
	max_num = sqrt(max); //Verifica-se o numero limite para procurarmos por multiplos.
	
	//////////////////////////////////////////////////////////////////////////////////
	//O primeiro for corre o array atras do "proximo" primo. Se for diferente de ze-//
	//ro então a variavel 'mult' será igual ao array no indice de 'k', em seguida   //
	//percorremos o array inteiro fazendo todos os multiplos de 'mult' serem iguais //
	//a zero, menos ele mesmo.													    //
	//////////////////////////////////////////////////////////////////////////////////
	for(k = 0; k <= max_num; k++){
		if(list[k] != 0){
			mult = list[k];
			for(c = k; c < max; c += mult){
				if(list[k] != list[c])
					list[c] = 0;
			}
		}
	}
	
	//Contador de quantos numeros primos foram achados
	for(j = 0; j < max; j++){
		if(list[j] != 0)
			count++;		
	}
	
	//Iniciado outro timer
	tFim = clock();
	
	//Diferença entre o começo do primeiro timer e do segundo.
	tGasto = ( (double)(tFim - tInicio)) / (CLOCKS_PER_SEC / 1000);
	
	printf("\nTempo gasto: %.2fs\n", (tGasto / 100));
	printf("\nQuantidade de Numeros Primos: %d\n",count);
	
	return 0;
}
