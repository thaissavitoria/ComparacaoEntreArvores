#include "rb.hpp"

RBTree *nill;

void CreateRBTree(RBTree **root)
{
    nill = (RBTree *)malloc(sizeof(RBTree));
    (nill)->esq = NULL;
    (nill)->dir = NULL;
    (nill)->pai = NULL;
    (nill)->cor = true; // false: vermelho  true:preto
    (nill)->reg.key = 0;
    *root = nill;
}

void searchRB(RBTree *aux, RecordRB z)
{
    while (aux != nill && z.key != aux->reg.key)
    {
        if (z.key < aux->reg.key)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
}

void insertFixUp(RBTree **raiz, RBTree *child)
{
    RBTree *tio;

    while ((child != *raiz) && (child->pai->cor == false))
    {

        if (child->pai == child->pai->pai->esq)
        {

            tio = child->pai->pai->dir;

            // caso 1:
            if ((tio != nill) && (tio->cor == false))
            {
                child->pai->cor = true;
                tio->cor = true;
                child->pai->pai->cor = false;
                child = child->pai->pai;
            }
            else
            {

                // caso 2
                if (child == child->pai->dir)
                {
                    child = child->pai;
                    rotacaoSimplesEsquerda(raiz, child);
                }

                // caso 3
                child->pai->cor = true;
                child->pai->pai->cor = false;
                rotacaoSimplesDireita(raiz, child->pai->pai);
            }
        }
        else
        {

            tio = child->pai->pai->esq;

            // caso 1
            if ((tio != nill) && (tio->cor == false))
            {
                child->pai->cor = true;
                tio->cor = true;
                child->pai->pai->cor = false;
                child = child->pai->pai;
            }
            else
            {

                // caso 2
                if (child == child->pai->esq)
                {
                    child = child->pai;
                    rotacaoSimplesDireita(raiz, child);
                }

                // caso 3
                child->pai->cor = true;
                child->pai->pai->cor = false;
                rotacaoSimplesEsquerda(raiz, child->pai->pai);
            }
        }
    }

    (*raiz)->cor = true;
}

void insertRBTree(RBTree **t, RBTree **pai, RBTree **raiz, RecordRB r)
{

    if (*t == nill)
    {
        *t = (RBTree *)malloc(sizeof(RBTree));
        (*t)->esq = nill;
        (*t)->dir = nill;
        (*t)->pai = pai != t ? *pai : nill;
        (*t)->cor = false; // false: vermelho  true:preto
        (*t)->reg = r;
        insertFixUp(raiz, *t);
    }
    else
    {

        if (r.key < (*t)->reg.key)
        {
            insertRBTree(&(*t)->esq, t, raiz, r);
            return;
        }

        if (r.key > (*t)->reg.key)
        {
            insertRBTree(&(*t)->dir, t, raiz, r);
            return;
        }
    }
}

void removeSearchRB(RBTree **raiz, RBTree *aux, RecordRB r, int *cont)
{

    while (aux != nill && r.key != aux->reg.key)
    {
        if (r.key < aux->reg.key)
            aux = aux->esq;
        else
            aux = aux->dir;
    }
    if (aux->reg.key == r.key)
    {
        removeRB(raiz, aux, aux, aux, cont);
    }
}

void rotacaoSimplesEsquerda(RBTree **raiz, RBTree *child)
{
    RBTree *x, *y;

    x = child;
    y = child->dir;
    x->dir = y->esq;

    if (y->esq != nill)
        y->esq->pai = x;

    y->pai = x->pai;

    if (x->pai == nill)
        *raiz = y;

    else if (x == x->pai->esq)
        x->pai->esq = y;

    else if (x == x->pai->dir)
        x->pai->dir = y;

    y->esq = x;
    x->pai = y;
}

void rotacaoSimplesDireita(RBTree **raiz, RBTree *child)
{
    RBTree *x, *y;

    x = child;
    y = child->esq;
    x->esq = y->dir;

    if (y->dir != nill)
        y->dir->pai = x;

    y->pai = x->pai;

    if (x->pai == nill)
    {
        *raiz = y;
    }

    else if (x == x->pai->dir)
        x->pai->dir = y;

    else if (x == x->pai->esq)
        x->pai->esq = y;

    y->dir = x;
    x->pai = y;
}

RBTree *successor(RBTree *aux)
{
    while (aux->esq != nill)
        aux = aux->esq;
    return aux;
}

void removeFix(RBTree **root, RBTree *x, RBTree *w)
{
    while (x != (*root) && x->cor == true)
    {
        if (x == x->pai->esq)
        {
            w = x->pai->dir;
            if (w->cor == false)
            {
                w->cor = true;
                x->pai->cor = false;
                rotacaoSimplesEsquerda(root, x->pai);
                w = x->pai->dir;
            }
            else if (w->esq->cor == true && w->dir->cor == true)
            {
                w->cor = false;
                x = x->pai;
            }
            else if (w->dir->cor == true)
            {
                w->esq->cor = true;
                w->cor = false;
                rotacaoSimplesDireita(root, w);
                w = x->pai->dir;
            }
            else
            {
                w->cor = x->pai->cor;
                x->pai->cor = true;
                w->dir->cor = true;
                rotacaoSimplesEsquerda(root, x->pai);
                x = (*root);
            }
        }
        else
        {
            w = x->pai->esq;
            if (w->cor == false)
            {
                w->cor = true;
                x->pai->cor = false;
                rotacaoSimplesDireita(root, x->pai);
                w = x->pai->esq;
            }
            else if (w->dir->cor == true && w->esq->cor == true)
            {
                w->cor = false;
                x = x->pai;
            }
            else if (w->esq->cor == true)
            {
                w->dir->cor = true;
                w->cor = false;
                rotacaoSimplesEsquerda(root, w);
                w = x->pai->esq;
            }
            else
            {
                w->cor = x->pai->cor;
                x->pai->cor = true;
                w->esq->cor = true;
                rotacaoSimplesDireita(root, x->pai);
                x = (*root);
            }
        }
    }
    x->cor = true;
}

void transplant(RBTree **root, RBTree *aux, RBTree *auxchild)
{
    if (aux->pai == nill)
        (*root) = auxchild;
    else if (aux == aux->pai->esq)
        aux->pai->esq = auxchild;
    else
        aux->pai->dir = auxchild;
    auxchild->pai = aux->pai;
}

void removeRB(RBTree **root, RBTree *z, RBTree *y, RBTree *x, int *cont)
{
    bool corini = y->cor;

    (*cont)++;
    if (z->esq == nill)
    {
        x = z->dir;
        transplant(root, z, z->dir);
    }
    else if (z->dir == nill)
    {
        x = z->esq;
        transplant(root, z, z->esq);
    }
    else
    {
        y = successor(z->dir);
        corini = y->cor;
        x = y->dir;

        if (y->pai == z)
        {
            x->pai = y;
        }
        else
        {
            transplant(root, y, y->dir);
            y->dir = z->dir;
            y->dir->pai = y;
        }
        transplant(root, z, y);
        y->esq = z->esq;
        y->esq->pai = y;
        y->cor = z->cor;
    }
    if (corini == true)
        removeFix(root, x, x);

    free(z);
}

void centralRB(RBTree *t)
{
    if (!(t == nill))
    {
        centralRB(t->esq);
        printf("%f\t", t->reg.key);
        centralRB(t->dir);
    }
}
