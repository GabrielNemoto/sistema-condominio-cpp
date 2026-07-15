#include <iostream>
#include <fstream>
#include <sstream>
#include "arquivo.h"
#include "morador.h"

using namespace std;

// Salva todos os moradores no arquivo TXT.
void SalvarTXT()
{
    ofstream arquivo("moradores.txt");

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo.\n";
        return;
    }

    arquivo << "PROXIMO_ID;" << ProximoID << '\n';

    for (const resident_class &morador : Moradores)
    {
        arquivo << morador.ID << ";"
                << morador.nome << ";"
                << morador.CPF << ";"
                << morador.AP << ";"
                << morador.tel << ";"
                << morador.bloc << ";"
                << morador.status << '\n';
    }

    arquivo.close();
}

//-------------------------------------------------------------//
//-------------------------------------------------------------//

// Carrega os dados de todos os moradores do arquivo TXT.
void CarregarTXT()
{
    ifstream arquivo("moradores.txt");

    if (!arquivo.is_open())
    {
        return;
    }

    Moradores.clear();

    string linha;

    if (getline(arquivo, linha))
    {
        stringstream dadosProximoID(linha);

        string identificador;
        string valor;

        getline(dadosProximoID, identificador, ';');
        getline(dadosProximoID, valor);

        if (identificador == "PROXIMO_ID" && !valor.empty())
        {
            ProximoID = stoi(valor);
        }
    }

    while (getline(arquivo, linha))
    {
        if (linha.empty())
        {
            continue;
        }

        resident_class morador;
        string campo;
        stringstream dados(linha);

        getline(dados, campo, ';');
        morador.ID = stoi(campo);

        getline(dados, morador.nome, ';');
        getline(dados, morador.CPF, ';');

        getline(dados, campo, ';');
        morador.AP = stoi(campo);

        getline(dados, morador.tel, ';');
        getline(dados, morador.bloc, ';');
        getline(dados, morador.status);

        Moradores.push_back(morador);
    }

    arquivo.close();
}
