#ifndef _ARQUIVO_H_
#define _ARQUIVO_H_

#include <string>
#include <map>
#include <fstream>

using namespace std;
using std::ifstream;
using std::ofstream;

struct No
{
	No* dir_;
	char nome[10];
	No* esq_;
			
	No()
	{
		dir_ = this;
		esq_ = this;
	}
};

class Arquivo
{	
	public:
		//Cria uma lista vazia para receber os nomes dos arquivos
		Arquivo();
		
		//Tira caracteres indesejados
		char TratarArquivo(char ref[10]);
		
		//Insere arquivo tratado na lista encadeada
		void InserirArquivo();
		
		//Remove um arquivo da lista encadeada
		void removerArquivo();
		
		//Associa as palavras ao arquivo delas
		void ColocandoNoMap(char palavra[15]);
		
		//Procurar palavra no Map
		string ProcurarPalavraNoMap(char palavra[15]);
		
		//Menu para saber o que é desejado fazer
		int LerOpcaoDoTeclado();
		
		//Retorna o nome do arquivo que será tratado ou do que será excluido
		char LerArquivoDoTeclado(int op);
		
		//Retorna a palavra que quer ser encontrada nos arquivos
		string LerPalavraDigitada(int op);
		
		
		
		
	private:
		No* inic_;
		int card_;
		ifstream in_stream;
		ofstream out_stream;
		map<string,string>::iterator Lista_de_nomes;

};
#endif