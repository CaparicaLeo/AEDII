/*
ABB.h
*/
#include <iostream>
#include <queue>
#include <conio.h>
using namespace std;

struct no
{
	int info;
	no *Llink;
	no *Rlink;
};

no *ini_AB(no *T)
{
	return NULL;
}

no *novoNo_AB(no *T, int x)
{
	T = new no;
	if (T != NULL)
	{
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
	}
	return T;
}

no *insere_AB(no *T, int x)
{
	if (T == NULL)
	{
		T = novoNo_AB(T, x);
		return T;
	}
	else
	{
		if (x < T->info)
		{
			T->Llink = insere_AB(T->Llink, x);
		}
		else
		{
			T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}

void emOrdem_AB(no *T)
{
	if (T != NULL)
	{
		emOrdem_AB(T->Llink);
		cout << T->info << " ";
		emOrdem_AB(T->Rlink);
	}
}

void preOrdem_AB(no *T)
{
	if (T != NULL)
	{
		cout << T->info << " ";
		preOrdem_AB(T->Llink);
		preOrdem_AB(T->Rlink);
	}
}

void posOrdem_AB(no *T)
{
	if (T != NULL)
	{
		posOrdem_AB(T->Llink);
		posOrdem_AB(T->Rlink);
		cout << T->info << " ";
	}
}

void percursoEmLargura(no *T)
{
	if (T == NULL)
	{
		return;
	}

	queue<no *> fila;
	fila.push(T);
	int nivel = 0;

	while (!fila.empty())
	{
		int tamanhoNivel = fila.size();
		cout << "Nivel " << nivel << ": ";

		for (int i = 0; i < tamanhoNivel; i++)
		{
			no *atual = fila.front();
			fila.pop();

			cout << atual->info << " ";

			if (atual->Llink != nullptr)
			{
				fila.push(atual->Llink);
			}

			if (atual->Rlink != nullptr)
			{
				fila.push(atual->Rlink);
			}
		}
		cout << endl;
		nivel++;
	}

	cout << "PRESSIONE QUALQUER TECLA PARA SAIR." << endl;
	getch();
}

bool buscaAB(no *T, int x)
{
	if (T == NULL)
	{
		cout << "Elemento " << x << " nao encontrado." << endl;
		return false;
	}
	else if (T->info == x)
	{
		cout << "Elemento " << x << " encontrado!" << endl;
		return true;
	}
	else if (x < T->info)
	{
		return buscaAB(T->Llink, x);
	}
	else
	{
		return buscaAB(T->Rlink, x);
	}
}
