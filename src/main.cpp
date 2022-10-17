#include "testes.hpp"

int main()
{
    int op;

    do
    {
        cout << endl
             << endl
             << "Qual deseja testar?" << endl;
        cout << "\t1. Árvore Binária; " << endl;
        cout << "\t2. Árvore AVL; " << endl;
        cout << "\t3. Árvore Red Black; " << endl;
        cout << "\t4. MAP; " << endl;
        cout << "\t5. UNORDERED MAP; " << endl;
        cout << "\t6. ORDERED VECTOR; " << endl;
        cout << "\t0. Sair do programa; " << endl;

        cin >> op;

        switch (op)
        {
        case 1:
            testBinaryTree();
            break;

        case 2:
            testAVLTree();
            break;  

        case 3:
            testRedBlack();
            break;

        case 4:
            testMap();
            break;

        case 5:
            testUMap();
            break;

        case 6:
            testOrderedVector();
            break;

        case 0:
            break;

        default:
            break;
        }

    } while (op != 0);

    return 0;
}