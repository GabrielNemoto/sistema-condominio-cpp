// Define a estrutura de dados dos moradores e declara as variáveis compartilhadas pelo sistema.
#ifndef MORADOR_H
#define MORADOR_H

#include <string>
#include <vector>

using namespace std;

// Declara a estrutura responsável por representar os dados de um morador.
struct resident_class
{
    int ID = 0;
    int AP;
    string nome;
    string CPF;
    string tel;
    string bloc;
    string status;
};

extern vector<resident_class> Moradores;
extern int ProximoID;

#endif