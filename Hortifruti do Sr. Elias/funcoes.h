#ifndef FUNCOES_H
#define FUNCOES_H

#include "tipos.h"
#include <vector>
#include <string>

extern std::vector<Produto> produtos;
extern std::vector<Fornecedor> fornecedores;

void limparTerminal();
Produto criarProduto(int id, const std::vector<Fornecedor>& fornecedores);
void salvarProdutos(const std::vector<Produto>& produtos);
void salvarFornecedores(const std::vector<Fornecedor>& fornecedores);
void adicionarProduto(std::vector<Produto>& produtos, const std::vector<Fornecedor>& fornecedores);
void editarProduto(std::vector<Produto>& produtos, const std::vector<Fornecedor>& fornecedores);
void listarProdutos(const std::vector<Produto>& produtos, const std::vector<Fornecedor>& fornecedores);
void listarFornecedores(const std::vector<Fornecedor>& fornecedores);
Fornecedor criarFornecedor(int id);
void adicionarFornecedor(std::vector<Fornecedor>& fornecedores);
void carregarProdutos(std::vector<Produto>& produtos);
void carregarFornecedores(std::vector<Fornecedor>& fornecedores);
void calcularCompra(std::vector<Produto>& produtos);
void menuPrograma();

#endif // FUNCOES_H
