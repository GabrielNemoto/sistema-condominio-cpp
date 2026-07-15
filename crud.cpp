#include <iostream>
#include <cctype>
#include "crud.h"
#include "morador.h"
#include "validacoes.h"

using namespace std;

// Cadastra um novo morador e adiciona seus dados ao sistema.
void cadastro()
{
    resident_class morador;

    cout << "==== CADASTRO DO MORADOR ====\n\n";

    morador.nome = ValidaNome();
    morador.CPF = ValidaCPF();
    morador.AP = ValidaApartamento();
    morador.tel = ValidaTelefone();
    morador.bloc = ValidaBloco();
    morador.status = ValidaStatus();

    morador.ID = ProximoID++;
    Moradores.push_back(morador);

    cout << "Morador cadastrado com sucesso!\n\n";

    return;
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Lista todos os moradores cadastrados.
void listar()
{
    cout << "==== REGISTROS DOS MORADORES ====\n\n";

    if (Moradores.empty())
        cout << "Nenhum morador cadastrado.\n";

    else
        for (int i = 0; i < Moradores.size(); i++)
        {
            cout << "Id do morador: " << Moradores[i].ID << endl;
            cout << "Nome: " << Moradores[i].nome << endl;
            cout << "CPF: " << Moradores[i].CPF << endl;
            cout << "Apartamento: " << Moradores[i].AP << endl;
            cout << "Telefone: " << Moradores[i].tel << endl;
            cout << "Bloco: " << Moradores[i].bloc << endl;
            cout << "Status: " << Moradores[i].status << endl;
            cout << "------------------------------------\n";
        }
    return;
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Busca e retorna o índice do morador no vector a partir do CPF.
// Retorna -1 caso o CPF não seja encontrado.
int BuscaIndice(string CPF)
{
    for (size_t i = 0; i < Moradores.size(); i++)
    {
        if (CPF == Moradores[i].CPF)
        {
            return (i);
        }
    }
    return -1;
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Pesquisa um morador pelo CPF e exibe seus dados caso seja encontrado.
void BuscaCpf()
{
    resident_class BUSCA;
    char RESP;

    cout << "==== PESQUISA DE MORADOR ====\n\n";

    do
    {
        cout << "Insira o CPF a ser pesquisado: ";
        getline(cin, BUSCA.CPF);
        cout << endl;

        int indice = BuscaIndice(BUSCA.CPF);

        if (indice != -1)
        {
            BUSCA = Moradores[indice];

            cout << "***** Dados do morador ***** \n\n";
            cout << "Id do morador: " << BUSCA.ID << endl;
            cout << "Nome: " << BUSCA.nome << endl;
            cout << "CPF: " << BUSCA.CPF << endl;
            cout << "Apartamento: " << BUSCA.AP << endl;
            cout << "Telefone: " << BUSCA.tel << endl;
            cout << "Bloco: " << BUSCA.bloc << endl;
            cout << "Status: " << BUSCA.status << endl;
            cout << "------------------------------------\n\n";
        }
        else
        {
            cout << "Pesquisa não encontrada.\n";
        }

        cout << "Deseja fazer outra pesquisa? [S] ou [N]\n";
        cin >> RESP;
        cin.ignore();

    } while (toupper(RESP) == 'S');
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Localiza um morador pelo CPF e permite atualizar seus dados.
void Update()
{
    resident_class morador;
    int opcao;
    char RESP;

    cout << "==== ATUALIZAR DADOS DE MORADOR ====\n\n";

    cout << "Insira o CPF do morador que deseja atualizar: \n";
    getline(cin, morador.CPF);
    cout << endl
         << endl;

    int indice = BuscaIndice(morador.CPF);

    if (indice == -1)
    {
        cout << "Morador nao encontrado!\n";
        return;
    }

    morador = Moradores[indice];

    cout << "***** Morador encontrado ***** \n\n";
    cout << "Id do morador: " << morador.ID << endl;
    cout << "Nome: " << morador.nome << endl;
    cout << "------------------------------------\n\n";
    do
    {
        bool Atualizou = false;

        cout << "Quais dados deseja alterar ?\n";
        cout << "[1] - Nome\n";
        cout << "[2] - CPF\n";
        cout << "[3] - Apartamento:\n";
        cout << "[4] - Telefone:\n";
        cout << "[5] - Bloco:\n";
        cout << "[6] - Status:\n";

        cin >> opcao;
        cin.ignore();

        switch (opcao)
        {
        case 1:
            Moradores[indice].nome = ValidaNome();
            Atualizou = true;
            break;

        case 2:
            Moradores[indice].CPF = ValidaCPF(indice);
            Atualizou = true;
            break;

        case 3:
            Moradores[indice].AP = ValidaApartamento();
            Atualizou = true;
            break;

        case 4:
            Moradores[indice].tel = ValidaTelefone();
            Atualizou = true;
            break;

        case 5:
            Moradores[indice].bloc = ValidaBloco();
            Atualizou = true;
            break;

        case 6:
            Moradores[indice].status = ValidaStatus();
            Atualizou = true;
            break;

        default:
            cout << "Comando invalido.\n";
            break;
        }

        cout << endl;

        if (Atualizou)
        {
            cout << "\nDados atualizados com sucesso!\n";
        }

        cout << "\nQuer fazer mais alguma alteração ? [S] ou [N]\n";
        cin >> RESP;
        cin.ignore();

    } while (toupper(RESP) == 'S');
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Localiza um morador pelo CPF e remove seu cadastro após confirmação.
void DeleteCadastro()
{
    resident_class morador;
    char RESP;

    cout << "==== EXCLUIR DADOS DE MORADOR ====\n\n";

    cout << "Insira o CPF do morador que deseja excluir: \n";
    getline(cin, morador.CPF);
    cout << endl
         << endl;

    int indice = BuscaIndice(morador.CPF);

    if (indice == -1)
    {
        cout << "Morador nao encontrado!\n";
        return;
    }

    morador = Moradores[indice];

    cout << "Morador encontrado! \n";
    cout << "ID: " << morador.ID << endl;
    cout << "Nome: " << morador.nome << endl;
    cout << "CPF: " << morador.CPF << endl;
    cout << "Apartamento: " << morador.AP << endl;
    cout << "Telefone: " << morador.tel << endl;
    cout << "Bloco: " << morador.bloc << endl;
    cout << "Status: " << morador.status << endl
         << endl;
    cout << "Deseja mesmo excluir este morador ? \n";
    cout << "Está operação será definitiva. [S] ou [N] \n";

    cin >> RESP;
    cin.ignore();

    if (toupper(RESP) == 'S')
    {
        Moradores.erase(Moradores.begin() + indice);
        cout << "Morador excluido com sucesso!\n";
    }
    else
    {
        cout << "Operação cancelada.\n";
    }
}