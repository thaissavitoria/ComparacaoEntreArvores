#include "testes.hpp"

void testSearchBinaryTree(int qtddados, BinaryTree **binTree)
{
    cout << endl
         << endl
         << ".........PESQUISA ÁRVORE BINÁRIA.............." << endl;
    RecordBin auxRbin;

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
    /// ................................5000.......................................................

    binTree = CreateBinaryTree();

    criaBinaryTree(5000, &binTree);
    testSearchBinaryTree(5000, &binTree);

    /// ................................50000.......................................................

    binTree = CreateBinaryTree();

    criaBinaryTree(50000, &binTree);
    testSearchBinaryTree(50000, &binTree);

    /// ................................500000.......................................................
    binTree = CreateBinaryTree();

    criaBinaryTree(500000, &binTree);
    testSearchBinaryTree(500000, &binTree);
}

void testSearchAVLTree(int qtddados, AVLTree **avl)
{
    cout << endl
         << endl
         << ".........PESQUISA AVL.............." << endl;
    RecordAVL auxRavl;

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
    /// ................................5000.......................................................

    avl = CreateAVLTree();

    criaAVLTree(5000, &avl);
    testSearchAVLTree(5000, &avl);

    /// ................................50000.......................................................

    avl = CreateAVLTree();

    criaAVLTree(50000, &avl);
    testSearchAVLTree(50000, &avl);

    /// ................................500000.......................................................
    avl = CreateAVLTree();

    criaAVLTree(500000, &avl);
    testSearchAVLTree(500000, &avl);
}

void criaRBTree(int qtddados, RBTree **rb)
{
    cout << "...............INSERÇÃO RED BLACK...................." << endl;
    RecordRB auxRb;

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

void testSearchRBTree(int qtddados, RBTree **rb)
{
    cout << endl
         << endl
         << ".........PESQUISA RED BLACK.............." << endl;
    RecordRB auxRb;

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
            auxRb.key = numsrc;

            pesquisaRB(rb, *rb, auxRb, &cont);
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

void testRedBlack()
{
    RBTree *rb;
    CreateRBTree(&(rb));

    /// ................................500........................................................

    criaRBTree(500, &rb);
    testSearchRBTree(500, &rb);

    /// ................................5000.......................................................

    CreateRBTree(&(rb));

    criaRBTree(5000, &rb);
    testSearchRBTree(5000, &rb);

    /// ................................50000.......................................................

    CreateRBTree(&(rb));
    criaRBTree(50000, &rb);
    testSearchRBTree(50000, &rb);

    /// ................................500000.......................................................

    CreateRBTree(&(rb));
    criaRBTree(500000, &rb);
    testSearchRBTree(500000, &rb);
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

            itr = Map->find(numsrc);

            if (itr != Map->end())
            {
                Map->erase(itr);
                cout << "Valor encontrado: " << setw(4) << fixed << setprecision(4) << numsrc << endl;
                cont++;
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "O número de valores encontrados é de " << cont << " valores .";

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

    std::chrono::steady_clock::time_point comeco = std::chrono::steady_clock::now();

    arq.open("arq500000.txt");

    if (!arq.is_open())
    {
        cerr << "Não foi possível abrir o arquivo de entradas!" << endl;
    }

    else
    {
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

    /// ................................5000.......................................................
    Map.clear();
    criaMap(5000, &Map);
    testSearchMap(5000, &Map);

    /// ................................50000.......................................................

    Map.clear();
    criaMap(50000, &Map);
    testSearchMap(50000, &Map);

    /// ................................500000.......................................................
    Map.clear();
    criaMap(500000, &Map);
    testSearchMap(500000, &Map);
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
                UMap->erase(itr);
                cout << "Valor encontrado: " << setw(4) << fixed << setprecision(4) << numsrc << endl;
                cont++;
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << "O número de valores encontrados é de " << cont << " valores .";

        cout << endl
             << endl
             << "O tempo para pesquisar e remover no Unordered Map de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void criaUMap(int qtddados, unordered_map<double, int> *UMap)
{
    cout << "...............INSERÇÃO UMAP....................." << endl;
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

    /// ................................5000.......................................................
    UMap.clear();
    criaUMap(5000, &UMap);
    testSearchUMap(5000, &UMap);

    /// ................................50000.......................................................

    UMap.clear();
    criaUMap(50000, &UMap);
    testSearchUMap(50000, &UMap);

    /// ................................500000.......................................................
    UMap.clear();
    criaUMap(500000, &UMap);
    testSearchUMap(500000, &UMap);
}

void testSearchOrderedVector(int qtddados, vector<double> vec)
{
    cout << endl
         << endl
         << ".........PESQUISA ORDERED VECTOR.............." << endl;

    string line;

    ifstream arq;

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

            if (binary_search(vec.begin(), vec.end(), numsrc))
            {
                for (int i = 0; i < vec.size(); i++)
                {
                    if (vec[i] == numsrc)
                        vec.erase(vec.begin() + i);
                }
                cout << "Valor encontrado: " << setw(4) << fixed << setprecision(4) << numsrc << endl;
            }
        }
        std::chrono::steady_clock::time_point fimrem = std::chrono::steady_clock::now();

        cout << endl
             << endl
             << "O tempo para pesquisar e remover no Vector Ordenado é de " << qtddados << " dados é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fimrem - comecorem).count() << " ms.\n";
    }
    arq.close();
}

void criaOrderedVector(int qtddados, vector<double> vec)
{
    cout << "...............INSERÇÃO ORDERED VECTOR....................." << endl;
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
        for (int i = 0; i < qtddados; i++)
        {
            getline(arq, line);
            double numins = atof(line.c_str());
            vec.push_back(numins);
        }
        sort(vec.begin(), vec.end()); // ordena
        std::chrono::steady_clock::time_point fim = std::chrono::steady_clock::now();
        cout << "O tempo para criar o  com um arquivo ordenado de " << qtddados << " entradas é de " << std::chrono::duration_cast<std::chrono::milliseconds>(fim - comeco).count() << " ms.\n";
        testSearchOrderedVector(qtddados, vec);
    }
    arq.close();
}

void imprimeVector(vector<double> vec)
{
    cout << vec.size() << endl;
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << endl;
    }
}

void testOrderedVector()
{
    vector<double> vec;

    string line;

    ifstream arq;

    /// ................................500.......................................................
    vec.clear();
    criaOrderedVector(500, vec);

    /// ................................5000.......................................................
    vec.clear();
    criaOrderedVector(5000, vec);

    /// ................................50000.......................................................

    vec.clear();
    criaOrderedVector(50000, vec);

    /// ................................500000.......................................................
    vec.clear();
    criaOrderedVector(500000, vec);
    return;
}
