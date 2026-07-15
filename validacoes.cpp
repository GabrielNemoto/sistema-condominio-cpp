// Implementa as regras de validação dos campos do morador.
#include <iostream>
#include <cctype>
#include "validacoes.h"
#include "morador.h"

using namespace std;

// Solicita e valida o nome do morador.
// Não permite nome vazio, muito curto ou contendo números.
// Retorna o nome validado.
string ValidaNome()
{
    bool NomeValido;
    string nome;
    cout << "Nome do morador: ";

    do
    {
        NomeValido = true;

        getline(cin, nome);

        if (nome.empty())
        {
            cout << "Nome não pode estar vazio.\n";
            cout << "Insira novamente: \n";
            NomeValido = false;
            continue;
        }

        if (nome.length() < 3)
        {
            cout << "Quantidade minima permitida de 3 caracteres.\n";
            cout << "Insira novamente: \n";
            NomeValido = false;
            continue;
        }

        bool TemLetra = false;

        for (char c : nome)
        {
            if (isalpha(c))
            {
                TemLetra = true;
                break;
            }
        }

        if (!TemLetra)
        {
            cout << "Nome invalido.\n";
            cout << "Insira novamente: ";

            NomeValido = false;
            continue;
        }

        bool NomeInvalido = false;

        for (char c : nome)
        {
            if (isdigit(c))
            {
                NomeInvalido = true;
                break;
            }
        }

        if (NomeInvalido)
        {
            cout << "Nome nao pode conter numeros.\n";
            cout << "Insira novamente: ";

            NomeValido = false;
            continue;
        }

    } while (!NomeValido);
    cout << endl;

    return (nome);
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Solicita e valida o CPF do morador.
// Verifica tamanho, presença apenas de números, repetição de dígitos e duplicidade entre os moradores cadastrados.
// Retorna o CPF validado.
string ValidaCPF(int indiceAtual)
{
    cout << "CPF (Apenas números): ";
    bool CPF_Valido;
    string CPF;

    do
    {
        CPF_Valido = true;

        getline(cin, CPF);

        if (CPF.empty())
        {
            cout << "CPF não pode estar vazio!\n";
            cout << "Insira novamente: \n";
            CPF_Valido = false;
            continue;
        }

        if (CPF.length() != 11)
        {
            cout << "CPF deve conter 11 digitos!\n";
            cout << "Insira novamente: \n";
            CPF_Valido = false;
            continue;
        }

        bool ApenasNumeros = true;

        for (char c : CPF)
        {
            if (!isdigit(c))
            {
                ApenasNumeros = false;
                break;
            }
        }

        if (!ApenasNumeros)
        {
            cout << "CPF deve conter apenas numeros!\n";
            cout << "Insira novamente: ";
            CPF_Valido = false;
            continue;
        }

        bool CPFInvalido = true;

        for (int i = 1; i < CPF.length(); i++)
        {
            if (CPF[i] != CPF[0])
            {
                CPFInvalido = false;
                break;
            }
        }

        if (CPFInvalido)
        {
            cout << "CPF invalido.\n";
            cout << "Insira novamente: ";
            CPF_Valido = false;
            continue;
        }

        for (int i = 0; i < Moradores.size(); i++)
        {
            if (i != indiceAtual && CPF == Moradores[i].CPF)
            {
                cout << "CPF já cadastrado!\n";
                cout << "Insira novamente: ";
                CPF_Valido = false;
                break;
            }
        }

    } while (!CPF_Valido);
    cout << endl;

    return (CPF);
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Solicita e valida o número do apartamento.
// Aceita somente valores numéricos entre 1 e 9999.
// Retorna o apartamento validado.
int ValidaApartamento()
{

    int AP;

    cout << "Apartamento: ";

    do
    {
        cin >> AP;

        if (cin.fail())
        {
            cout << "Formato invalido, insira somente números. \n";
            cout << "Apartamento: ";
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (AP <= 0 || AP > 9999)
        {
            cout << "Apartamento invalido. \n";
            cout << "Apartamento: ";
            continue;
        }

    } while (AP <= 0 || AP > 9999);

    cin.ignore(1000, '\n');
    cout << endl;

    return (AP);
}
//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Solicita e valida o telefone do morador.
// Aceita somente números com 10 ou 11 dígitos.
// Retorna o telefone validado.
string ValidaTelefone()
{
    cout << "Telefone ou Celular: ";

    bool TelValido;
    string tel;
    do
    {
        TelValido = true;

        getline(cin, tel);

        if (tel.empty())
        {
            cout << "Número vazio não é permitido.\n";
            cout << "Insira novamente: ";
            TelValido = false;
            continue;
        }

        bool ApenasNumeros = true;

        for (char c : tel)
        {
            if (!isdigit(c))
            {
                ApenasNumeros = false;
                break;
            }
        }

        if (!ApenasNumeros)
        {
            cout << "Insira apenas numeros.\n";
            cout << "Insira novamente: ";
            TelValido = false;
            continue;
        }

        if (tel.length() != 11 && tel.length() != 10)
        {
            cout << "Telefone invalido.\n";
            cout << "Insira novamente: ";
            TelValido = false;
            continue;
        }
    } while (TelValido == false);
    cout << endl;

    return (tel);
}

//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Solicita e valida o bloco do apartamento.
// Não permite valor vazio, aceita no máximo 3 caracteres, apenas espaços ou caracteres inválidos.
// Retorna o bloco validado.
string ValidaBloco()
{
    cout << "Bloco do apartamento: ";

    bool BlocoValido;
    string bloc;

    do
    {
        BlocoValido = true;
        getline(cin, bloc);

        if (bloc.empty())
        {
            cout << "Bloco invalido.\n";
            cout << "Insira novamente: ";
            BlocoValido = false;
            continue;
        }

        if (bloc.length() > 3)
        {
            cout << "Bloco invalido.\n";
            cout << "Insira novamente: ";
            BlocoValido = false;
            continue;
        }

        bool Espacos = true;

        for (char c : bloc)
        {
            if (c != ' ')
            {
                Espacos = false;
                break;
            }
        }

        if (Espacos)
        {
            cout << "Bloco invalido.\n";
            cout << "Insira novamente: ";

            BlocoValido = false;
            continue;
        }

        bool BlocoCerto = false;
        for (char c : bloc)
        {
            if (!isalnum(c))
            {
                BlocoCerto = true;
                break;
            }
        }

        if (BlocoCerto)
        {
            cout << "Bloco invalido.\n";
            cout << "Insira novamente: ";

            BlocoValido = false;
            continue;
        }
    } while (!BlocoValido);
    cout << endl;

    return (bloc);
}
//-------------------------------------------------------------//

//-------------------------------------------------------------//

// Solicita e valida o status do morador.
// Permite somente as opções Ativo ou Desativado.
// Retorna o status selecionado.
string ValidaStatus()
{
    int op;
    string status;

    cout << "Status do morador?\n";
    cout << "[1] Ativo\n[2] Desativado\nInsira a opção desejada: ";

    do
    {
        cin >> op;
        cin.ignore();

        if (op != 1 && op != 2)
        {
            cout << "Opção invalida.\n";
            cout << "Insira novamente: ";
        }
        else
        {

            switch (op)
            {
            case 1:
                status = "Ativo";
                break;
            case 2:
                status = "Desativado";
                break;
            default:
                break;
            }
        }
    } while (op != 1 && op != 2);

    return (status);
}