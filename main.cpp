#include <cmath>
#include <iostream>
//#include "ListadeNomes.h"

using namespace std;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::cin;
using std::endl;

class ListadeNomes
{
	public:
		struct No
		{
			No* dir_;
			char nome[10];
			
		};
		
		No objeto_Struct;
ListadeNomes()
{
	
	char res;
	No* novo_ = inic_ -> dir_;
	while(novo_ != inic_ && res!= 'N' && res != 'n')
    {	
		cout << "\nDigite o nome do arquivo desejado";
		cin >> *novo_-> nome;
		cout << "\nGostaria de continuar?";
		cin >> res;
		//No* h = new No;
		objeto_Struct.dir_ = new No;
	}
	
	
		
}

void Imprime(No ListadeNomes)
{
	No* auxiliar;
	
	*auxiliar = ListadeNomes;
	while(auxiliar -> dir_ != NULL)
	{
		cout << auxiliar -> nome;
		auxiliar == auxiliar -> dir_;	
	}

}

	private:
		No* inic_;
		int card_;
};

int main()
{

	ListadeNomes teste;
	//teste.Imprime(teste.objeto_Struct);
	return 0;
}