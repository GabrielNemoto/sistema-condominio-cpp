// Declara as funções responsáveis pelo cadastro dos dados dos moradores.
#ifndef CRUD_H
#define CRUD_H

#include <string>

void cadastro();
void listar();
void BuscaCpf();
void Update();
void DeleteCadastro();
int BuscaIndice(std::string CPF);

#endif