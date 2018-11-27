#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

string mensagem()
{
	string opcao;
	cout << "\n Digite as letras A, B, C ou D para responder";
	cout << "\n Caso queira pular essa pergunta, aperte a letra P";
	cout << "\n Caso queira a ajuda dos universitarios, aperte a letra H";
	cout << "\n Caso queira parar e garantir sua premiacao, aperte a letra E" << endl;
	cout << " Letra: ";
	cin >> opcao;
	return opcao;
}

int main(int argc, char *argv[])
{
	int sorteio;
	int valor = 0, erro = 0, pulos = 0, ajuda = 0, parar = 0, sorteados[25], cont=0;
	string  teste[5], aux, resposta;
	string certas[] = {"B) Hematoma", "B) Labios", "D) Iglu", "A) Pe de Moleque", "A) Canarinho", "C) 1500", "D) Tarzan", "C) India", "D) Omelete", "A) Sete", "C) Windows Dez",
					   "D) 3", "B) 26", "A) 7", "B) 50", "C) Vitamina D", "B) LI", "A) Bahia", "C) Moqueca", "A) Amazonas", "B) Carpideiras", "C) Coin", "D) Inalacao", "B) Crase", "C) Antartida",
					   "A) Conclave", "B) 20", "C) Jupiter", "D) 6", "C) Camberra", "B) Peru", "A) Sebaceas", "C) Tarsila do Amaral", "D) Nova Delhi", "B) Mamute", "D) Marte", "A) Cafila", "D) Palmeiras",
					   "C) Acre", "B) Espaco", "D) 32", "B) Fonema", "C) Thomas Edison", "A) Oscar Niemeyer", "B) Argentina", "D) Ulceras", "B) Paris", "C) Belgica", "A) Extremo Oriente", "D) N"
					  };
	string milhao[][5] = {"\n Como eh chamado o acumulo localizado de sangue em uma parte do corpo?", "A) Machucado", "B) Hematoma", "C) Vermelhidao", "D) Coagulo Sanguineo",
						  "\n Qual parte do corpo o ventriloquo naum mexe?", "A) Olhos", "B) Labios", "C) Maos", "D) Pernas",
						  "\n Como eh chamada a tipica casa dos esquimos?", "A) Oca", "B) Alvenaria", "C) Palafita", "D) Iglu",
						  "\n Qual o nome do doce feito a partir do amendoim torrado com rapadura?", "A) Pe de Moleque", "B) Bolo", "C) Pacoca", "D) Amendoim Doce Crocante",
						  "\n Que passaro simboliza a Selecao Brasileira?", "A) Canarinho", "B) Periquito", "C) Falcao", "D) Arara",
						  "\n Qual foi o ano do descobrimento do Brasil?", "A) 1550", "B) 1505", "C) 1500", "D) 1555",
						  "\n Qual eh o heroi, considerado rei da floresta, que anda pelas arvores?", "A) Mogli", "B) Homem Formiga", "C) Peter Pan", "D) Tarzan",
						  "\n No tempo dos descobrimentos, qual era o destino de Colombo?", "A) Australia", "B) China", "C) India", "D) Japao",
						  "\n Como eh chamada a iguaria de ovos batidos, fritos na manteiga, oleo ou azeite?", "A) Mexidao", "B) Panqueca", "C) Tortilha", "D) Omelete",
						  "\n Quantas silabas tem a palavra paralelepipedo?", "A) Sete", "B) Seis", "C) Cinco", "D) Oito",
						  "\n Qual a versao mais nova so sitema operacional Windows?", "A) Windows Sete", "B) Windows Oito", "C) Windows Dez", "D) Windows XP",
						  "\n A palavra chave em ingles tem quantas letras?", "A) 5", "B) 4", "C) 6", "D) 3",
						  "\n Quantas letras existem no alfabeto? ", "A) 24", "B) 26", "C) 25", "D) 23",
						  "\n Quantas letras existem no arco-iris? ", "A) 7", "B) 6", "C) 8", "D) 5",
						  "\n Com quantos anos de casado se comemora bodas de ouro?", "A) 30", "B) 50", "C) 60", "D) 40",
						  "\n Qual a vitamina absorvemos quando entramos em contato com o sol?", "A) Vitamina A", "B) Vitamina K", "C) Vitamina D", "D) Vitamina C",
						  "\n Como se escreve 51 em algarismos romanos? ", "A) XXXXXI", "B) LI", "C) LXI", "D) XI",
						  "\n A cidade de Feira de Santana fica em que estado?", "A) Bahia", "B) Sergipe", "C) Espirito Santo", "D) Pernambuco",
						  "\n Como eh conhecido o guisado de peixe ou marisco com azeite e pimenta?", "A) Vatapa", "B) Fricasse", "C) Moqueca", "D) Mokelin",
						  "\n O Rio Negro eh afluente de qual grande Rio do Brasil?", "A) Amazonas", "B) Sao Francisco", "C) Paraiba", "D) Tiete",
						  "\n Como sao chamadas as mulheres que ganham dinheiro para chorar em velorios de defuntos alheios as familias delas?", "A) Choradeiras", "B) Carpideiras", "C) Martedeiras", "D) Artimedeiras",
						  "\n Como eh chamado moeda, em ingles? ", "A) Chain", "B) Cain", "C) Coin", "D) Cin",
						  "\n Como eh chamada a absorcao de um medicamento por via respiratoria? ", "A) Aero Respirataria", "B) Articular", "C) Venosa", "D) Inalacao",
						  "\n Em Gramatica, como eh chamada a contracao de duas ou mais vogais em uma so? ", "A) Conjugacao", "B) Crase", "C) Ditongo", "D) Hiato",
						  "\n Qual eh o maior deserto do globo terrestre? ", "A) Kalahari", "B) Gobi", "C) Antartida", "D) Saara",
						  "\n Como eh chamada a assembleia que elege o papa?", "A) Conclave", "B) Reuniao Bispo-papal", "C) Conciliacao", "D) Reuniao Papal",
						  "\n Quantos algarismos 9 existem entre 0 e 100?", "A) 10", "B) 20", "C) 12", "D) 15",
						  "\n Qual o maior planeta do Sistema Solar?", "A) Saturno", "B) Mercurio", "C) Jupiter", "D) Urano",
						  "\n Quantos sao os continentes da terra?", "A) 5", "B) 4", "C) 7", "D) 6",
						  "\n Qual a capital da Australia?", "A) Sydney", "B) Melbourne", "C) Camberra", "D) Brisbane",
						  "\n Onde fica Machu Picchu?", "A) Equador", "B) Peru", "C) Colombia", "D) Bolivia",
						  "\n Como sao chamadas as glandulas superficiais da pele?", "A) Sebaceas", "B) Subcutaneas", "C) Sudoriparas", "D) Paratireoides",
						  "\n Qual eh o nome da pintor(a), autor(a) da famosa obra 'Abaporu'?", "A) Candido Portinari", "B) Leonardo Da Vinci", "C) Tarsila do Amaral", "D) Vincent van Gogh",
						  "\n Qual eh a capital da India?", "A) Bombaim", "B) Bangalore", "C) Chennai", "D) Nova Delhi",
						  "\n Como eh chamado o elefante pre-historico?", "A) Mamelute", "B) Mamute", "C) Manute", "D) Molute",
						  "\n Qual eh o quarto planeta a partir do Sol?", "A) Mercurio", "B) Terra", "C) Saturno", "D) Marte",
						  "\n Qual eh o coletivo de camelo?", "A) Cafila", "B) Manada", "C) Alcateia", "D) Armento",
						  "\n Qual time eh o maior campeao nacional?", "A) Corinthians", "B) Flamengo", "C) Cruzeiro", "D) Palmeiras",
						  "\n Rio Branco eh a capital de qual estado brasileiro?", "A) Amapa", "B) Rondonia", "C) Acre", "D) Maranhao",
						  "\n O Ano-Luz eh uma medida de:", "A) Tempo", "B) Espaco", "C) Tempo-Espaco", "D) Velocidade",
						  "\n Quantos dentes uma pessoa adulta possui, se naum perdeu nenhum?", "A) 28", "B) 30", "C) 34", "D) 32",
						  "\n No estudo da lingua, cada unidade de som da palavra recebe o nome de:", "A) Silaba", "B) Fonema", "C) Letras", "D) Hiato",
						  "\n Quem inventou a lampada?", "A) Galileu Galilei", "B) Isaac Newton", "C) Thomas Edison", "D) Alexander Graham Bell",
						  "\n Quem projetou Brasilia?", "A) Oscar Niemeyer", "B) Joao Filgueiras Lima", "C) Prestes Maia", "D) Marcio Kogan",
						  "\n Qual o segundo maior pais da america do sul?", "A) Colombia", "B) Argentina", "C) Paraguai", "D) Chile",
						  "\n Qual eh a sexta praga do Egito?", "A) Gafanhotos", "B) Trevas", "C) Chuva de pedras", "D) Ulceras",
						  "\n O Arco do Triunfo eh um monumento historico de qual cidade?", "A) Berlim", "B) Paris", "C) Barcelona", "D) Roma",
						  "\n Bruxelas eh capital de que pais europeu?", "A) Holanda", "B) Hungria", "C) Belgica", "D) Suecia",
						  "\n Qual regiao Asia estao localizados dois dos quatro paises mais ricos do mundo?", "A) Extremo Oriente", "B) Oriente Medio", "C) Sul da Asia", "D) Norte da Asia",
						  "\n Na Tabela Periodica, qual o simbolo do elemento Nitrogenio?", "A) In", "B) Na", "C) Ne", "D) N",
						 };

	cout << "\n Todas as palavras estao sem acentuacao" << endl;
	while(valor != 1000000 && erro == 0 && parar == 0)
	{
		srand ( ( time (NULL) ) );
		sorteio = rand() % 49;
		for(int sort = cont; sort <=sorteados[sort] ; sort++)
		{
			sorteados[sort] = sorteio;
			cont++;
			if(sorteados[sort] != sorteio){
				srand ( ( time (NULL) ) );
				sorteio = rand() % 49;
			}
			break;
		}
		
		for(int i = 0; i < 5; i++)
		{
			teste[i] = milhao[sorteio][i];
			cout << " " << teste[i] << endl;
		}
		resposta = mensagem();

		for(int j = 1; j < 5 ; j++)
		{
			if(resposta == "a")
			{
				aux = teste[1];

			}
			else if(resposta == "b")
			{
				aux = teste[2];

			}
			else if(resposta == "c")
			{
				aux = teste[3];

			}
			else if(resposta == "d")
			{
				aux = teste[4];

			}
			else if(resposta == "p")
			{
				if(pulos < 2)
				{
					pulos++;
					system("cls");
					srand ( ( time (NULL) ) );
					sorteio = rand() % 49;
					for(int i = 0; i < 5; i++)
					{
						teste[i] = milhao[sorteio][i];
						cout << " " << teste[i] << endl;
					}
					resposta = mensagem();
				}
				else
				{
					cout << "\n Infelizmente ja acabou sua cota de pulos!" << endl;
					resposta = mensagem();
				}

			}
			else if(resposta == "h")
			{
				if(ajuda < 2)
				{
					int cont = 0;
					for(int aju = 1; aju < 5; aju++)
					{

						if(teste[aju] != certas[sorteio] && cont < 2)
						{
							cout << "---" << endl;
							cont++;
						}
						if(teste[aju] != certas[sorteio] && cont == 2)
						{
							cout << " " << teste[aju] << endl;
							cont++;
						}
						if(teste[aju] == certas[sorteio])
						{
							cout << " " << teste[aju] << endl;
						}
					}
					ajuda++;
				}
				else
				{
					cout << "\n Voce naum pode mais pedir ajuda aos universitarios" << endl;
				}
				resposta =	mensagem();
			}
			else if(resposta == "e")
			{
				char certeza;
				cout << "\n Voce tem certeza que deseja parar? Digite S para sim" << endl;
				cin >> certeza;
				if(certeza == 's')
				{
					aux = "e";
					break;
				}
				else
				{
					resposta =	mensagem();
				}

			}
			else
			{
				cout << "\n Letra digitada naum eh uma das letras permitidas";
				resposta =	mensagem();
				break;
			}
		}


		for(int k = 0; k <= certas[k].length() ; k++)
		{
			if(aux == "e")
			{
				system("cls");
				cout << "Voce parou!  Sua premiacao eh: " << valor << " reais" << endl;
				parar++;
				break;
			}
			if(certas[sorteio] == aux)
			{
				if(valor <= 4000)
				{
					system("cls");
					valor = valor + 1000;
					cout << "\n Certa resposta! Voce agora possui: " << valor << " reais" << endl;
					break;
				}
				else if(valor == 5000)
				{
					system("cls");
					valor = valor + 5000;
					cout << "\n Certa resposta! Voce agora possui: " << valor << " reais" << endl;
					break;
				}
				else if(valor >= 10000 && valor <= 40000)
				{
					system("cls");
					valor = valor + 10000;
					cout << "\n Certa resposta! Voce agora possui: " << valor << " reais" << endl;
					break;
				}
				else if(valor == 50000)
				{
					system("cls");
					valor = valor + 50000;
					cout << "\n Certa resposta! Voce agora possui: " << valor << " reais" << endl;
					break;
				}
				else if(valor >= 100000 && valor <= 400000)
				{
					system("cls");
					valor = valor + 100000;
					cout << "\n Certa resposta! Voce agora possui: " << valor << " reais" << endl;
					break;
				}
				else if(valor == 500000)
				{
					system("cls");
					valor = valor + 500000;
					cout << "\n Certa resposta! Voce agora eh um Milionario!" << endl <<
						 " Sua premiacao final eh: " << valor << " reais" << endl;
					break;
				}
			}
			else
			{
				cout << "\n Voce errou e perdeu tudo! Sua resposta foi: " << aux << endl <<
					 " A resposta correta era: " << certas[sorteio] << endl;
				erro++;
				break;
			}
		}
	}
	return 0;
}
