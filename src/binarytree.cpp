#include "binarytree.hpp"

BinaryTree *CreateBinaryTree()
{
  return NULL;
}

bool TVazia(BinaryTree **t)
{
  return *t == NULL;
}

void insertBinaryTree(BinaryTree **t, RecordBin r)
{

  if (TVazia(t))
  {
    *t = (BinaryTree *)malloc(sizeof(BinaryTree));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->reg = r;
  }
  else
  {

    if (r.key < (*t)->reg.key)
    {
      insertBinaryTree(&(*t)->esq, r);
    }

    if (r.key > (*t)->reg.key)
    {
      insertBinaryTree(&(*t)->dir, r);
    }
  }
}

void pesquisaBinaryTree(BinaryTree **t, BinaryTree **aux, RecordBin r)
{

  if (*t == NULL)
  {
    return;
  }

  if ((*t)->reg.key > r.key)
  {
    pesquisaBinaryTree(&(*t)->esq, aux, r);
    return;
  }
  if ((*t)->reg.key < r.key)
  {
    pesquisaBinaryTree(&(*t)->dir, aux, r);
    return;
  }

  *aux = *t;
}


void antecessor(BinaryTree **t, BinaryTree *aux)
{

  if ((*t)->dir != NULL)
  {
    antecessor(&(*t)->dir, aux);
    return;
  }

  aux->reg = (*t)->reg;
  aux = *t;
  *t = (*t)->esq;
  free(aux);
}

void removeBinaryTree(BinaryTree **t, RecordBin r, int *cont)
{

  (*cont)++;
  BinaryTree *aux;

  if (*t == NULL)
  {
    return;
  }

  if (r.key < (*t)->reg.key)
  {
    removeBinaryTree(&(*t)->esq, r, cont);
    return;
  }
  if (r.key > (*t)->reg.key)
  {
    removeBinaryTree(&(*t)->dir, r, cont);
    return;
  }

  if ((*t)->dir == NULL)
  {
    aux = *t;
    *t = (*t)->esq;
    return;
  }

  if ((*t)->esq != NULL)
  {
    antecessor(&(*t)->esq, *t);
    return;
  }

  aux = *t;
  *t = (*t)->dir;
}

void centralBin(BinaryTree *t)
{
  if (!(t == NULL))
  {
    centralBin(t->esq);
    cout << t->reg.key << " ";
    centralBin(t->dir);
  }
}