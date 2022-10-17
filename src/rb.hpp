#ifndef RB_HPP
#define RB_HPP

#include <iostream>

using namespace std;

typedef struct RecordRB RecordRB;
typedef struct RBTree RBTree;

struct RecordRB
{
	double key;
};

struct RBTree
{
	RecordRB reg;
	RBTree *esq, *dir;
	RBTree *pai;
	bool cor; // específico para rubro negra (FALSE = VERMELHO, TRUE = PRETO)
};

void CreateRBTree(RBTree **root);

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child);
void rotacaoSimplesDireita(RBTree **raiz, RBTree *child);

void insertFixUp(RBTree **raiz, RBTree *child);
void insertRBTree(RBTree **t, RBTree **pai, RBTree **raiz, RecordRB r);
void pesquisaRB(RBTree **raiz, RBTree *aux, RecordRB r,int *cont);

RBTree *successor(RBTree *aux);
void transplant(RBTree **root, RBTree *aux, RBTree *auxchild);
void removeFix(RBTree **root, RBTree *x, RBTree *w);
void removeRB(RBTree **root, RBTree *z, RBTree *y, RBTree *x, int *cont);

void centralRB(RBTree *t);

#endif