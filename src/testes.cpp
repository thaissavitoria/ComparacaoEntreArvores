#include "testes.hpp"

void testSearchBinaryTree(int qtddados, BinaryTree **binTree)
{
    cout << endl
         << endl
         << ".........PESQUISA ÁRVORE BINÁRIA.............." << endl;
    RecordBin auxRbin;

    BinaryTree *aux = CreateBinaryTree();

    string line;

    ifstream arq;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());
            auxRbin.key = numsrc;
            auxRbin.value = 1;

            pesquisaBinaryTree(binTree, &aux, auxRbin);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisa na Árvore Binária de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void testRemoveBinaryTree(int qtddados, BinaryTree **binTree)
{
    cout << endl
         << endl
         << ".........REMOÇÃO ÁRVORE BINÁRIA.............." << endl;
    RecordBin auxRbin;

    string line;

    ifstream arq;

    int cont = 0;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());
            auxRbin.key = numsrc;
            auxRbin.value = 1;

            removeBinaryTree(binTree, auxRbin, &cont);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "A quantidade de vezes que o método de remoção da Árvore Binária foi acessado é de " << cont << ".";

        cout << endl
             << endl
             << "O tempo para pesquisar e remover na Árvore Binária de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void criaBinaryTree(int qtddados, BinaryTree **binTree)
{
    cout << endl
         << "...............INSERÇÃO ÁRVORE BINÁRIA....................." << endl;
    RecordBin auxRbin;

    string line;

    ifstream arq;

    std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        cout << endl
             << "..............." << qtddados << " dados.....................";

        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());
            auxRbin.key = numins;
            auxRbin.value = 1;
            insertBinaryTree(binTree, auxRbin);
        }

        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << endl
             << endl
             << "O tempo para criar a Árvore Binária com um arquivo de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
    }
    arq.close();
}

void testBinaryTree()
{
    BinaryTree *binTree = CreateBinaryTree();

    /// ................................500........................................................

    criaBinaryTree(500, &binTree);
    testSearchBinaryTree(500, &binTree);
    testRemoveBinaryTree(500, &binTree);
    /// ................................5000.......................................................

    binTree = CreateBinaryTree();

    criaBinaryTree(5000, &binTree);
    testSearchBinaryTree(5000, &binTree);
    testRemoveBinaryTree(5000, &binTree);

    /// ................................50000.......................................................

    binTree = CreateBinaryTree();

    criaBinaryTree(50000, &binTree);
    testSearchBinaryTree(50000, &binTree);
    testRemoveBinaryTree(50000, &binTree);

    /// ................................500000.......................................................
    binTree = CreateBinaryTree();

    criaBinaryTree(500000, &binTree);
    testSearchBinaryTree(500000, &binTree);
    testRemoveBinaryTree(500000, &binTree);
}

void testSearchAVLTree(int qtddados, AVLTree **avl)
{
    cout << endl
         << endl
         << ".........PESQUISA AVL.............." << endl;
    RecordAVL auxRavl;

    AVLTree *aux = CreateAVLTree();

    string line;

    ifstream arq;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecopes = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());
            auxRavl.key = numsrc;
            auxRavl.value = 1;

            pesquisaAVL(avl, &aux, auxRavl);
        }
        std::chrono::steady_clock::time_point fimpes = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisa na Árvore AVL de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimpes - comecopes).count() << " ms.\n";
    }
    arq.close();
}

void testRemoveAVLTree(int qtddados, AVLTree **avl)
{
    cout << endl
         << endl
         << ".........REMOÇÃO AVL.............." << endl;
    RecordAVL auxRavl;

    string line;

    ifstream arq;

    int cont = 0;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());
            auxRavl.key = numsrc;
            auxRavl.value = 1;

            removeAVLTree(avl, avl, auxRavl, &cont);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "O número de vezes que o método de remoção da AVL foi acessado foi de " << cont << ".";

        cout << endl
             << endl
             << "O tempo para pesquisar e remover na Árvore AVL de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void criaAVLTree(int qtddados, AVLTree **avl)
{
    cout << "...............INSERÇÃO AVL...................." << endl;
    RecordAVL auxRavl;

    string line;

    ifstream arq;

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        cout << endl
             << "..............." << qtddados << " dados.....................";

        std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());
            auxRavl.key = numins;
            auxRavl.value = 1;
            insertAVLTree(avl, auxRavl);
        }

        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << endl
             << endl
             << "O tempo para criar a Árvore AVL com um arquivo de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
    }
    arq.close();
}

void testAVLTree()
{
    AVLTree *avl = CreateAVLTree();

    /// ................................500........................................................

    criaAVLTree(500, &avl);
    testSearchAVLTree(500, &avl);
    testRemoveAVLTree(500, &avl);

    /// ................................5000.......................................................

    avl = CreateAVLTree();

    criaAVLTree(5000, &avl);
    testSearchAVLTree(5000, &avl);
    testRemoveAVLTree(5000, &avl);

    /// ................................50000.......................................................

    avl = CreateAVLTree();

    criaAVLTree(50000, &avl);
    testSearchAVLTree(50000, &avl);
    testRemoveAVLTree(50000, &avl);

    /// ................................500000.......................................................
    avl = CreateAVLTree();

    criaAVLTree(500000, &avl);
    testSearchAVLTree(500000, &avl);
    testRemoveAVLTree(500000, &avl);
}

void criaRBTree(int qtddados, RBTree **rb)
{
    cout << "...............INSERÇÃO RED BLACK...................." << endl;
    RecordRB auxRb;

    string line;

    ifstream arq;

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

        cout << endl
             << "..............." << qtddados << " dados.....................";

        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());
            auxRb.key = numins;
            insertRBTree(rb, rb, rb, auxRb);
        }

        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << endl
             << endl
             << "O tempo para criar a Árvore Red Black com um arquivo de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
    }
    arq.close();
}

void testRemoveRBTree(int qtddados, RBTree **rb)
{
    cout << endl
         << endl
         << ".........REMOÇÃO RED BLACK.............." << endl;
    RecordRB auxRb;

    string line;

    ifstream arq;

    int cont = 0;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());
            auxRb.key = numsrc;

            removeSearchRB(rb, *rb, auxRb, &cont);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "O número de vezes que o método de remoção da Red Black foi acessado foi de " << cont << ".";

        cout << endl
             << endl
             << "O tempo para pesquisar e remover na Árvore Red Black de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void testSearchRBTree(int qtddados, RBTree **rb)
{
    cout << endl
         << endl
         << ".........PESQUISA RED BLACK.............." << endl;
    RecordRB auxRb;

    string line;

    ifstream arq;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();
        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());
            auxRb.key = numsrc;

            searchRB(*rb, auxRb);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisar na Árvore Red Black de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void testRedBlack()
{
    RBTree *rb;
    CreateRBTree(&(rb));

    /// ................................500........................................................

    criaRBTree(500, &rb);
    testSearchRBTree(500, &rb);
    testRemoveRBTree(500, &rb);

    /// ................................5000.......................................................

    CreateRBTree(&(rb));

    criaRBTree(5000, &rb);
    testSearchRBTree(5000, &rb);
    testRemoveRBTree(5000, &rb);

    /// ................................50000.......................................................

    CreateRBTree(&(rb));
    criaRBTree(50000, &rb);
    testSearchRBTree(50000, &rb);
    testRemoveRBTree(50000, &rb);

    /// ................................500000.......................................................

    CreateRBTree(&(rb));
    criaRBTree(500000, &rb);
    testSearchRBTree(500000, &rb);
    testRemoveRBTree(500000, &rb);
}

void testSearchMap(int qtddados, map<double, int> *Map)
{
    cout << endl
         << endl
         << ".........PESQUISA MAP.............." << endl;
    map<double, int>::iterator itr;

    string line;

    ifstream arq;

    int cont = 0;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());

            itr = Map->find(numsrc);

            if (itr != Map->end())
            {
                cont++;
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "O número de valores encontrados é de " << cont << " valores .";

        cout << endl
             << endl
             << "O tempo para pesquisar no Map de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void testRemoveMap(int qtddados, map<double, int> *Map)
{
    cout << endl
         << endl
         << ".........REMOÇÃO MAP.............." << endl;
    map<double, int>::iterator itr;

    string line;

    ifstream arq;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());

            itr = Map->find(numsrc);

            if (itr != Map->end())
            {
                Map->erase(itr);
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisar e remover no Map de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void criaMap(int qtddados, map<double, int> *Map)
{
    cout << "...............INSERÇÃO MAP....................." << endl;
    string line;
    ifstream arq;

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());
            Map->insert({numins, 1});
        }
        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << "O tempo para criar o MAP com um arquivo de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
    }
    arq.close();
}

void testMap()
{
    cout << endl
         << endl
         << "...............INSERÇÃO MAP....................." << endl;

    map<double, int> Map;

    string line;

    ifstream arq;

    /// ................................500.......................................................
    Map.clear();
    criaMap(500, &Map);
    testSearchMap(500, &Map);
    testRemoveMap(500, &Map);

    /// ................................5000.......................................................
    Map.clear();
    criaMap(5000, &Map);
    testSearchMap(5000, &Map);
    testRemoveMap(5000, &Map);

    /// ................................50000.......................................................

    Map.clear();
    criaMap(50000, &Map);
    testSearchMap(50000, &Map);
    testRemoveMap(50000, &Map);

    /// ................................500000.......................................................
    Map.clear();
    criaMap(500000, &Map);
    testSearchMap(500000, &Map);
    testRemoveMap(500000, &Map);
}

void testRemoveUMap(int qtddados, unordered_map<double, int> *UMap)
{
    cout << endl
         << endl
         << ".........REMOÇÃO MAP.............." << endl;
    unordered_map<double, int>::iterator itr;

    string line;

    ifstream arq;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());

            itr = UMap->find(numsrc);

            if (itr != UMap->end())
            {
                UMap->erase(itr);
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisar e remover no Unordered Map de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void testSearchUMap(int qtddados, unordered_map<double, int> *UMap)
{
    cout << endl
         << endl
         << ".........PESQUISA UMAP.............." << endl;
    unordered_map<double, int>::iterator itr;

    string line;

    ifstream arq;

    int cont = 0;

    std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());

            itr = UMap->find(numsrc);

            if (itr != UMap->end())
            {
                cont++;
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "O número de valores encontrados é de " << cont << " valores .";

        cout << endl
             << endl
             << "O tempo para pesquisar no Unordered Map de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void criaUMap(int qtddados, unordered_map<double, int> *UMap)
{
    cout << "...............INSERÇÃO UMAP....................." << endl;
    string line;
    ifstream arq;

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());
            UMap->insert({numins, 1});
        }
        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << "O tempo para criar o UNORDERED MAP com um arquivo de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
    }
    arq.close();
}

void testUMap()
{
    unordered_map<double, int> UMap;

    string line;

    ifstream arq;

    /// ................................500.......................................................
    UMap.clear();
    criaUMap(500, &UMap);
    testSearchUMap(500, &UMap);
    testRemoveUMap(500, &UMap);

    /// ................................5000.......................................................
    UMap.clear();
    criaUMap(5000, &UMap);
    testSearchUMap(5000, &UMap);
    testRemoveUMap(5000, &UMap);

    /// ................................50000.......................................................

    UMap.clear();
    criaUMap(50000, &UMap);
    testSearchUMap(50000, &UMap);
    testRemoveUMap(50000, &UMap);

    /// ................................500000.......................................................
    UMap.clear();
    criaUMap(500000, &UMap);
    testSearchUMap(500000, &UMap);
    testRemoveUMap(500000, &UMap);
}

void testRemoveOrderedVector(int qtddados, set<double> *vec)
{
    cout << endl
         << endl
         << ".........REMOVE ORDERED VECTOR.............." << endl;

    string line;

    ifstream arq;

    set<double>::iterator itr;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());

            itr = vec->find(numsrc);

            if (itr != vec->end())
                vec->erase(itr);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisar e remover no Vector Ordenado é de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void testSearchOrderedVector(int qtddados, set<double> *vec)
{
    cout << endl
         << endl
         << ".........PESQUISA ORDERED VECTOR.............." << endl;

    string line;

    ifstream arq;

    set<double>::iterator itr;

    arq.open("arqConsulta.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comecorem = std::chrono::steady_clock::now();

        for (int i = 0; i < 10000; i++)
        {
            getline(arq, line);
            double numsrc = atof(line.c_str());

            itr = vec->find(numsrc);

            if (itr != vec->end())
                vec->erase(itr);
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisar no Vector Ordenado é de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";

        testRemoveOrderedVector(qtddados, vec);
    }
    arq.close();
}

void criaOrderedVector(int qtddados, set<double> *vec)
{
    cout << "...............INSERÇÃO ORDERED VECTOR....................." << endl;
    string line;
    ifstream arq;

    set<double>::iterator itr;

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
        std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());

            itr = vec->find(numins);

            if (itr == vec->end())
                vec->insert(numins);
        }
        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << "O tempo para criar o  com um arquivo ordenado, sem inserir números repetidos, de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
        testSearchOrderedVector(qtddados, vec);
    }
    arq.close();
}

void testOrderedVector()
{
    set<double> vec;

    string line;

    ifstream arq;

    /// ................................500.......................................................
    vec.clear();
    criaOrderedVector(500, &vec);

    /// ................................5000.......................................................
    vec.clear();
    criaOrderedVector(5000, &vec);

    /// ................................50000.......................................................

    vec.clear();
    criaOrderedVector(50000, &vec);

    /// ................................500000.......................................................
    vec.clear();
    criaOrderedVector(500000, &vec);
}
