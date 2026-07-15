#include <iostream>
#include <locale>
#include <windows.h>
#include <cctype>

#include "crud.h"
#include "arquivo.h"

using namespace std;


// Permite uso de caracteres especiais no Windows.
void pt_br()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
}

// Inicializa o sistema, carrega os dados salvos e controla o menu principal.
int main()
{
    pt_br();
    CarregarTXT();

    int opcao;
    char RESP;

    do
    {
        cout << "==== SISTEMA DE CONDOMINIO v1.0 ====\n\n";
        cout << "[1] - Cadastrar morador\n";
        cout << "[2] - Ver registros de moradores\n";
        cout << "[3] - Pesquisar morador\n";
        cout << "[4] - Atualizar dados de morador\n";
        cout << "[5] - Excluir dados de morador\n";
        cout << "Qualquer outro numero para encerrar\n";

        cin >> opcao;
        cin.ignore(1000, '\n');

        switch (opcao)
        {
        case 1:
            cadastro();
            SalvarTXT();
            break;

        case 2:
            listar();
            break;

        case 3:
            BuscaCpf();
            break;

        case 4:
            Update();
            SalvarTXT();
            break;

        case 5:
            DeleteCadastro();
            SalvarTXT();
            break;

        default:
            return 0;
        }

        cout << "\nDeseja fazer outra operacao? [S/N]\n";
        cin >> RESP;
        cin.ignore(1000, '\n');

    } while (toupper(RESP) == 'S');

    return 0;
}