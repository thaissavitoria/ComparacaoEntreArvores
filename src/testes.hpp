#ifndef TESTES_HPP
#define TESTES_HPP

#include "binarytree.hpp"
#include "avl.hpp"
#include "rb.hpp"
#include <time.h>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <map>
#include <unordered_map>

using std::stringstream;

void testSearchBinaryTree(int qtddados,BinaryTree**binTree);
void criaBinaryTree(int qtddados,BinaryTree** binTree);
void testBinaryTree();

void testSearchAVLTree(int qtddados,AVLTree** avl);
void criaAVLTree(int qtddados,AVLTree* avl);
void testAVLTree();

void criaRBTree(int qtddados,RBTree** rb);
void testSearchRBTree(int qtddados,RBTree** rb);
void testRedBlack();

void testSearchMap(int qtddados,map<double,int>*Map);
void criaMap(int qtddados,map<double,int>*Map);
void testMap();

void testSearchUMap(int qtddados,unordered_map<double,int>*Map);
void criaUMap(int qtddados,unordered_map<double,int>*Map);
void testUMap();


void testSearchOrderedVector(int qtddados,vector<double>vec);
void criaOrderedVector(int qtddados,vector<double>vec); //cria e ordena
void imprimeVector(vector<double>vec);
void testOrderedVector();



#endif