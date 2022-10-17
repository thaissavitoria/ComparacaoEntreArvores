#include "geraArquivo.hpp"

void gera500000()
{
    /////................Escrevendo no arquivo..................
    ofstream arq;
    arq.open("arq500000.txt");

    if(!arq.good())
    {
        cout<<"Não foi possível criar o arquivo!"<<endl;
        return;
    }
    else
        cout<<"Arquivo de 500000 entradas criado!"<<endl;

    random_device semente;
    mt19937 gen(semente());
    uniform_real_distribution<double> dis(1,300);

    string esp="\n";

    for (int i = 0; i < 500000; i++)
    {
        arq<<dis(gen);
        arq<<esp;    
    } 

    arq.close();
}


void geraArquivoConsulta()
{
    /////................Escrevendo no arquivo..................
    ofstream arq;
    arq.open("arqConsulta.txt");

    if(!arq.good())
    {
        cout<<"Não foi possível criar o arquivo!"<<endl;
        return;
    }
    else
        cout<<"Arquivo de consultas criado!"<<endl;

    random_device semente;
    mt19937 gen(semente());
    uniform_real_distribution<double> dis(1,300);

    string esp="\n";

    for (int i = 0; i < 10000; i++)
    {
        arq<<dis(gen);
        arq<<esp;    
    } 

    arq.close();
}