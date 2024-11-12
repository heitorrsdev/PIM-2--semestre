#ifndef FUNCOES_H
#define FUNCOES_H

#include <vector>
#include "tipos.h"

// Declaração de funções
void limparTerminal();
Produto criarProduto(int id, const vector<Fornecedor>& fornecedores);
void salvarProdutos(const vector<Produto>& produtos);
void salvarFornecedores(const vector<Fornecedor>& fornecedores);
void adicionarProduto(vector<Produto>& produtos, const vector<Fornecedor>& fornecedores);
void editarProduto(vector<Produto>& produtos, const vector<Fornecedor>& fornecedores);
void listarProdutos(const vector<Produto>& produtos, const vector<Fornecedor>& fornecedores);
void listarFornecedores(const vector<Fornecedor>& fornecedores);
Fornecedor criarFornecedor(int id);
void adicionarFornecedor(vector<Fornecedor>& fornecedores);
void carregarProdutos(vector<Produto>& produtos);
void carregarFornecedores(vector<Fornecedor>& fornecedores);
void calcularCompra(vector<Produto>& produtos);
void menuPrograma();

#endif // FUNCOES_H
