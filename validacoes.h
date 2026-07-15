// Declara as funções responsáveis por validar os dados informados no cadastro e na atualização de moradores.
#ifndef VALIDACOES_H
#define VALIDACOES_H

#include <string>

using namespace std;

string ValidaNome();
string ValidaCPF(int indiceAtual = -1);
int ValidaApartamento();
string ValidaTelefone();
string ValidaBloco();
string ValidaStatus();

#endif