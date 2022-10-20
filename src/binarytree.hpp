#ifndef BINARYTREE_HPP 
#define BINARYTREE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct RecordBin RecordBin;
typedef struct BinaryTree BinaryTree;

struct RecordBin{
	double key;
	int value;
};

struct BinaryTree{
	RecordBin reg;
	BinaryTree *esq, *dir;
};

BinaryTree* CreateBinaryTree();
bool TVazia(BinaryTree **t);
void insertBinaryTree(BinaryTree **t, RecordBin r);

void removeBinaryTree(BinaryTree **t, RecordBin r,int *cont);
void pesquisaBinaryTree(BinaryTree **t,BinaryTree **aux, RecordBin r);
void antecessor(BinaryTree **t, BinaryTree *aux);

void centralBin(BinaryTree *t);



#endif