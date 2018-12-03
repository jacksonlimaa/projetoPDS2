//TP-PDS2 Aluno: Jackson Lima de Almeida Universidade Federal de Minas Gerais

//O programa foi feito de maneira que o usuario deveria digitar primeiramente o que desejaria fazer, entre as opções está 
//incluir arquivo de texto, excluir arquivo de texto, colocar palavra para pesquisar e sair.

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>

#include "Arquivo.h"

using namespace std;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;


Arquivo objArquivo;

Arquivo::Arquivo()
{

	card_ = 0;
	inic_ = new No;
	inic_ -> dir_ = inic_;
	inic_ -> esq_ = inic_;
	
}

char Arquivo::TratarArquivo(char ref[10])
{
	ref = objArquivo.LerArquivoDoTeclado();
	char a;
	in_stream.open(ref);
	char b = 'a';
	
	if(in_stream.fail())
	{
		cout<< "Falha em abrir arquivo.\n";
		exit(1);
	}
	else
	{
		cout << "Sucesso em abrir arquivo.\n";
	}
		
		
	out_stream.open("arq.txt");
	if (out_stream.fail())
	{
		cout << "Falha na abertura do arquivo de saida";
		exit(1);
	}
	else
	{
		cout << "Sucesso em abrir arquivo de saida";
	}
		
	while (!in_stream.eof())
	{
		in_stream.get(a);
		if(a == '.')
		{
			out_stream << ' ';
		}
		if(a != ',' && a != '\n' && a != '-' && a != '?' && a != '!' && a != ':' && a != ';' && a != 39 && a != '[' && a != ']' && a != '{' && a != '}' && a != '<' && a != '>' && a != '(' && a != ')' && a != '*' && a != '%')
		{
			
			out_stream << a;			
   	 	 }		
	}
		
	in_stream.close();
	out_stream.close();		
	
	return b;
	
}

void Arquivo::InserirArquivo(char ref[10])
{
	ref[10] = TratarArquivo();
	No* novo_ = inic_ -> dir_;
	while(novo_ != inic_)
	{
		novo_ = novo_ -> dir_;
	}
	
	if(novo_ != inic_)
	{
	   	No* etr_ = new No;
	   	etr_ -> nome[10] = ref[10];
	   	etr_ -> dir_ = inic_;
	   	novo_ -> esq_ = etr_;
	   	novo_ -> esq_ -> dir_ = etr_;
	   	novo_ -> dir_ = etr_;
	   	card_++;
	}
	
}

void removerArquivo(char aux[10])
{
	No* rem = inic_ -> dir_;
	while(rem != inic_ && rem -> nome[10] != aux[10])
	{
		rem = rem -> dir_;
	}
	
	rem -> esq_ -> dir_ = rem ->dir_;
	rem -> dir_ -> esq_ = rem -> esq_;
	delete rem;
	card_--;
	
}

void Arquivo::ColocandoNoMap(char palavra[15])
{
	No* cont = inic_ -> dir_;
	char a;
	for(cont = inic_ -> dir_; cont = inic_; cont = cont -> dir_)
	{
		out_stream.open("arq.txt");
		while (in_stream.eof())
		{
			out_stream.get(a);
			Lista_de_nomes.insert(pair<string,string>(cont -> nome[10], a ));
		}

	}
}

int Arquivo::LerOpcaoDoTeclado()
{
	int op;
	cout << "1. Adicionar arquivo para pesquisa " << endl;
	cout << "2. Remover arquivo de pesquisa " << endl;
	cout << "3. Fazer consulta " << endl;
	cout << "4. Sair " << endl;
	cout << "5. Digite a opção desejada: " << endl;
	cin >> op;
	while(op < 1 && op > 4)
	{
		cout << "Opção invalida. Digite o numero da opção desejada: ";
		cin >> op;
	}
	return op;
}

char Arquivo::LerArquivoDoTeclado(int op)
{
	op = LerOpcaoDoTeclado();
	char res, arc[10];
	if(op == 1)
	{
		while(res != 'n' && res != 'N')
		{
			cout << "Digite o nome do arquivo desejado para a pesquisa: " << endl;
			cin >> arc[10];
			
			return arc[10];
			
			
			cout << "\nGostaria de incluir mais um arquivo?";
			cin >> res;
		
			
		}
	}
	if(op == 2)
	{
		while(res != 'n' && res != 'N')
		{
			cout << "Digite o nome do arquivo que deseja retirar da pesquisa: " << endl;
			cin >> arc[10];
			
			return arc[10];
			
			cout << "\nGostaria de excluir mais um arquivo?";
			cin >> res;
		
			
		}
	}
}

string LerPalavraDigitada(int op)
{
	op = objArquivo.LerOpcaoDoTeclado();
	char palavra_consulta[15], res;
	if(op == 3)
	{
		cout << "Digite a palavra qu deseja pesquisar: " << endl;
		cin >> palavra_consulta;
		
		return palavra_consulta;
		
		cout << "Gostaria de consultar mais uma palavra?" << endl;
		cin >> res;
	}
}



