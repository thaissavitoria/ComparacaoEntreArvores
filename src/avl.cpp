#include "avl.hpp"

AVLTree *CreateAVLTree()
{
	return NULL;
}

void insertAVLTree(AVLTree **t, RecordAVL r)
{

	if (*t == NULL)
	{
		*t = (AVLTree *)malloc(sizeof(AVLTree));
		(*t)->left = NULL;
		(*t)->right = NULL;
		(*t)->weight = 0;
		(*t)->reg = r;
	}
	else
	{

		if (r.key < (*t)->reg.key)
		{
			insertAVLTree(&(*t)->left, r);
			if ((getWeight(&(*t)->left) - getWeight(&(*t)->right)) == 2)
			{
				if (r.key < (*t)->left->reg.key)
					rotacaoSimplesDireita(t);
				else
					rotacaoDuplaDireita(t);
			}
		}

		if (r.key > (*t)->reg.key)
		{
			insertAVLTree(&(*t)->right, r);
			if ((getWeight(&(*t)->right) - getWeight(&(*t)->left)) == 2)
			{
				if (r.key > (*t)->right->reg.key)
					rotacaoSimplesEsquerda(t);
				else
					rotacaoDuplaEsquerda(t);
			}
		}
	}

	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
}


void antecessorAVL(AVLTree **t, AVLTree *aux)
{

	if ((*t)->right != NULL)
	{
		antecessorAVL(&(*t)->right, aux);
		return;
	}

	aux->reg = (*t)->reg;
	aux = *t;
	*t = (*t)->left;
	free(aux);
}

void rebalanceAVLTree(AVLTree **t)
{
	int balance;
	int left = 0;
	int right = 0;

	balance = getWeight(&(*t)->left) - getWeight(&(*t)->right);
	if ((*t)->left)
		left = getWeight(&(*t)->left->left) - getWeight(&(*t)->left->right);
	if ((*t)->right)
		right = getWeight(&(*t)->right->left) - getWeight(&(*t)->right->right);

	if (balance == 2 && left >= 0)
		rotacaoSimplesDireita(t);
	if (balance == 2 && left < 0)
		rotacaoDuplaDireita(t);

	if (balance == -2 && right <= 0)
		rotacaoSimplesEsquerda(t);
	if (balance == -2 && right > 0)
		rotacaoDuplaEsquerda(t);
}

void removeAVLTree(AVLTree **t, AVLTree **f, RecordAVL r, int *cont)
{
	AVLTree *aux;
	(*cont)++;

	if (*t == NULL)
	{
		return;
	}

	if (r.key < (*t)->reg.key)
	{
		removeAVLTree(&(*t)->left, t, r, cont);
		return;
	}
	if (r.key > (*t)->reg.key)
	{
		removeAVLTree(&(*t)->right, t, r, cont);
		return;
	}

	cout << "NÓ ENCONTRADO: " << setw(4) << fixed << setprecision(4) << (*t)->reg.key << endl;

	if ((*t)->right == NULL)
	{
		aux = *t;
		*t = (*t)->left;
		free(aux);
		rebalanceAVLTree(f);
		return;
	}

	if ((*t)->left != NULL)
	{
		antecessorAVL(&(*t)->left, *t);
		rebalanceAVLTree(t);
		rebalanceAVLTree(f);
		return;
	}

	aux = *t;
	*t = (*t)->right;
	free(aux);
	rebalanceAVLTree(t);
	rebalanceAVLTree(f);
}

void centralAVL(AVLTree *t)
{
	if (!(t == NULL))
	{
		centralAVL(t->left);
		printf("%f\t", t->reg.key);
		centralAVL(t->right);
	}
}

int getWeight(AVLTree **t)
{
	if (*t == NULL)
		return -1;
	return (*t)->weight;
}

int getMaxWeight(int left, int right)
{
	if (left > right)
		return left;
	return right;
}

void rotacaoSimplesDireita(AVLTree **t)
{
	AVLTree *aux;
	aux = (*t)->left;
	(*t)->left = aux->right;
	aux->right = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoSimplesEsquerda(AVLTree **t)
{
	AVLTree *aux;
	aux = (*t)->right;
	(*t)->right = aux->left;
	aux->left = (*t);
	(*t)->weight = getMaxWeight(getWeight(&(*t)->left), getWeight(&(*t)->right)) + 1;
	aux->weight = getMaxWeight(getWeight(&aux->left), (*t)->weight) + 1;
	(*t) = aux;
}

void rotacaoDuplaDireita(AVLTree **t)
{
	rotacaoSimplesEsquerda(&(*t)->left);
	rotacaoSimplesDireita(t);
}

void rotacaoDuplaEsquerda(AVLTree **t)
{
	rotacaoSimplesDireita(&(*t)->right);
	rotacaoSimplesEsquerda(t);
}