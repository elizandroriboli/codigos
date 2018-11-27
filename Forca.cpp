#include <iostream>
#include <string.h>
#include <string>
#include <cstdlib>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
	char vet [20][20], letra, palavra;
	int sorteio, tamanho, tentativas = 0, correto;
	strcpy(vet[0], "banana"), strcpy(vet[1], "morango"), strcpy(vet[2], "abacaxi"), strcpy(vet[3], "melancia"),
		   strcpy(vet[4], "mexerica"), strcpy(vet[5], "mamao"), strcpy(vet[6], "abacate"), strcpy(vet[7], "laranja"),
		   strcpy(vet[8], "jabuticaba"), strcpy(vet[9], "goiaba"), strcpy(vet[10], "acelora"), strcpy(vet[11], "ameixa"),
		   strcpy(vet[12], "carambola"), strcpy(vet[13], "cereja"), strcpy(vet[14], "damasco"), strcpy(vet[15], "graviola"),
		   strcpy(vet[16], "kiwi"), strcpy(vet[17], "pessego"), strcpy(vet[18], "pitanga"), strcpy(vet[19], "maracuja");

	srand ( ( time (NULL) ) );
	sorteio = rand() % 20;
	tamanho = strlen(vet[sorteio]);
	string espaco[15];
	int acertos [15];
	for(int inserir = 0; inserir <= acertos[inserir] ; inserir++)
	{
		acertos[inserir] = 0;
	}

	cout << " \n A palavra sorteada tem: " << tamanho << " letras." <<
		 "Dica: Eh uma fruta! \n" << endl;
	cout << "Você possui 6 chances para adivinhar a palavra \n" << endl;
	for ( int i = 0 ; i < tamanho; i++)
	{
		espaco[i] = " _ ";
		cout << espaco [i];
	}
	do
	{
		cout << "\n \n Digite uma letra para tentar adivinhar a palavra" << endl;
		cin >> letra;
		cout << "Letra digitada: " << letra << "\n" << endl;

		for(int j = 0; j < tamanho ; j++)
		{
			palavra = vet[sorteio][j];
			if(palavra == letra)
			{
				espaco[j] = letra;
				cout << espaco[j];
				acertos[j] = 1;
			}
			if (palavra != letra)
			{
				cout << espaco[j];
				acertos[j] == 0;
			}
			if((palavra == letra && acertos[j] == 1))
			{
				acertos[j] = 1;
			}
		}


		for (int n = 0 ; n < tamanho; n++)
		{
			if (acertos[n] == 1)
			{
				correto = 1;
			}
			else
			{
				correto = 0;
				break;

			}
		}

		for (int aux = 0 ; aux < tamanho; aux++)
		{
			if(palavra == letra )
			{
				tentativas = 0;
				break;
			}
			else
			{
				tentativas++;
				break;	
			}
		}
	}
	while ((tentativas < 7) && (correto == 0));


	if(correto == 1 || tentativas > 7)
	{
		cout << " \n Parabens você adivinhou a palavra em: " << tentativas;
	}
	else
	{
		cout << " \nPrezado familiar, providencie o enterro, porque temos um enforcado!" <<endl;
		cout << "\nA palavra que levou ao enforcamento foi: " << palavra <<endl;
	}
	return 0;
}
