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
#include <set>
#include <unordered_map>

using std::stringstream;

void testSearchBinaryTree(int qtddados, BinaryTree **binTree);
void testRemoveBinaryTree(int qtddados, BinaryTree **binTree);
void criaBinaryTree(int qtddados, BinaryTree **binTree);
void testBinaryTree();

void testSearchAVLTree(int qtddados, AVLTree **avl);
void testRemoveAVLTree(int qtddados, AVLTree **avl);
void criaAVLTree(int qtddados, AVLTree *avl);
void testAVLTree();

void criaRBTree(int qtddados, RBTree **rb);
void testRemoveRBTree(int qtddados, RBTree **rb);
void testSearchRBTree(int qtddados, RBTree **rb);
void testRedBlack();

void testSearchMap(int qtddados, map<double, int> *Map);
void testRemoveMap(int qtddados, map<double, int> *Map);
void criaMap(int qtddados, map<double, int> *Map);
void testMap();

void testSearchUMap(int qtddados, unordered_map<double, int> *Map);
void testRemoveUMap(int qtddados, unordered_map<double, int> *Map);
void criaUMap(int qtddados, unordered_map<double, int> *Map);
void testUMap();

void testSearchOrderedVector(int qtddados, set<double> *vec);
void testRemoveOrderedVector(int qtddados, set<double> *vec);
void criaOrderedVector(int qtddados, set<double> *vec); // cria e ordena
void testOrderedVector();

#endif