#ifndef AVL_HPP
#define AVL_HPP

#include <iostream>
#include <iomanip>
using namespace std;

typedef struct RecordAVL RecordAVL;
typedef struct AVLTree AVLTree;

struct RecordAVL
{
    double key;
    int value;
};

struct AVLTree
{
    RecordAVL reg;
    AVLTree *left, *right;
    int weight;
};

AVLTree *CreateAVLTree();
void insertAVLTree(AVLTree **t, RecordAVL r);

// muda o remove devido a necessidade de ponteiro para sub-árvore desbalanceada
void removeAVLTree(AVLTree **t, AVLTree **f, RecordAVL r,int *cont);
void antecessorAVL(AVLTree **t, AVLTree *aux);
void pesquisaAVL(AVLTree **t, AVLTree **aux, RecordAVL r);
void rebalanceAVLTree(AVLTree **t);

void centralAVL(AVLTree *t);

int getWeight(AVLTree **t);
int getMaxWeight(int left, int right);

void rotacaoSimplesDireita(AVLTree **t);
void rotacaoSimplesEsquerda(AVLTree **t);
void rotacaoDuplaDireita(AVLTree **t);
void rotacaoDuplaEsquerda(AVLTree **t);

#endif