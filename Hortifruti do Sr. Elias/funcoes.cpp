#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <locale.h>
#include "tipos.cpp"

using namespace std;

const string NOME_ARQUIVO_PRODUTOS = "../DB/produtos.csv"; // alterar para o caminho de rede para referenciar o servidor
const string NOME_ARQUIVO_FORNECEDORES = "../DB/fornecedores.csv"; // alterar para o caminho de rede para referenciar o servidor

vector<Produto> produtos;
vector<Fornecedor> fornecedores;

void limparTerminal () {
    cout << "\033";
}

Produto criarProduto(int id, const vector<Fornecedor>& fornecedores) {
    Produto produto;
    produto.id = id;

    cin.ignore();
    cout << "Nome: ";
    
    getline(cin, produto.nome);
    
    cout << "Preço: ";
    cin >> produto.preco;
    cout << "Tipo (1 para unitário, 2 para por kilo): ";
    cin >> produto.tipo;
    cout << "Quantidade: ";
    cin >> produto.quantidade;

    cout << "\nSelecione o Fornecedor pelo ID: " << endl;
    for(const auto& fornecedor : fornecedores) {
        cout << "ID: " << fornecedor.id << " Nome: " << fornecedor.nome << endl;
    }
    cout << "Fornecedor (ID): ";
    cin >> produto.fornecedorID;

    return produto;
}

void salvarProdutos(const vector<Produto>& produtos) {
    ofstream arquivo(NOME_ARQUIVO_PRODUTOS);
    arquivo << "ID,Nome,Preco,Tipo,Quantidade,FornecedorID\n";
    
    for(const auto& produto : produtos) {
        arquivo << produto.id << ","
                << produto.nome << ","
                << produto.preco << ","
                << produto.tipo << ","
                << produto.quantidade << ","
                << produto.fornecedorID << "\n";
    }
    
}

void salvarFornecedores(const vector<Fornecedor>& fornecedores) {
    ofstream arquivo(NOME_ARQUIVO_FORNECEDORES);
    arquivo << "ID,Nome,Contato\n";
    for(const auto& fornecedor : fornecedores) {
        arquivo << fornecedor.id << ","
                << fornecedor.nome << ","
                << fornecedor.contato << "\n";
    }
}

void adicionarProduto(vector<Produto>& produtos, const vector<Fornecedor>& fornecedores) {
    int id;
    cout << "ID do Produto: ";
    cin >> id;
    Produto novoProduto = criarProduto(id, fornecedores);
    produtos.push_back(novoProduto);
    salvarProdutos(produtos);
    cout << "\nProduto adicionado com sucesso!" << endl;
}

void editarProduto(vector<Produto>& produtos, const vector<Fornecedor>& fornecedores) {
    cout << "Informe o ID do produto que deseja editar: ";
    int id;
    cin >> id;

    bool encontrado = false;
    for(auto& produto : produtos) {
        if(produto.id == id) {
            cout << "Editando produto ID: " << id << endl;
            Produto editado = criarProduto(id, fornecedores);
            produto = editado;
            encontrado = true;
            break;
        }
    }
    if(encontrado) {
        salvarProdutos(produtos);
        cout << "Produto editado com sucesso!" << endl;
    } else {
        cout << "Produto não encontrado." << endl;
    }
}

void listarProdutos(const vector<Produto>& produtos, const vector<Fornecedor>& fornecedores) {
    for(const auto& produto : produtos) {
        cout << "\n-------------------------" << endl << "ID: " << produto.id << endl;
        cout << "Nome: " << produto.nome << endl;
        cout << "Preço: " << produto.preco << endl;
        cout << "Tipo: " << (produto.tipo == 1 ? "Unitário" : "Por Kilo") << endl;
        cout << "Quantidade: " << produto.quantidade << endl;
        
        // Buscar fornecedor
        auto it = find_if(fornecedores.begin(), fornecedores.end(), [&](const Fornecedor& f) {
            return f.id == produto.fornecedorID;
        });

        if (it != fornecedores.end()) {
            cout << "Fornecedor: " << it->nome << endl;
            cout << "Contato do Fornecedor: " << it->contato << endl;
        } else {
            cout << "Fornecedor: Não encontrado" << endl;
        }

        cout << "-------------------------" << endl;
    }
}

void listarFornecedores(const vector<Fornecedor>& fornecedores) {
    for(const auto& fornecedor : fornecedores) {
        cout << "\n-------------------------" << endl;
        cout << "ID: " << fornecedor.id << endl;
        cout << "Nome: " << fornecedor.nome << endl;
        cout << "Contato: " << fornecedor.contato << endl;
        cout << "-------------------------\n" << endl;
    }
}

Fornecedor criarFornecedor(int id) {
    Fornecedor fornecedor;
    fornecedor.id = id;

    cin.ignore();
    cout << "Nome: ";
    getline(cin, fornecedor.nome);
    
    cout << "Contato: ";
    getline(cin, fornecedor.contato);
    
    return fornecedor;
}

void adicionarFornecedor(vector<Fornecedor>& fornecedores) {
    int id;
    cout << "ID do Fornecedor: ";
    cin >> id;
    
    Fornecedor novoFornecedor = criarFornecedor(id);
    fornecedores.push_back(novoFornecedor);
    salvarFornecedores(fornecedores);
    
    cout << "Fornecedor adicionado com sucesso!" << endl;
}

void carregarProdutos(vector<Produto>& produtos) {
    ifstream arquivo(NOME_ARQUIVO_PRODUTOS);
    
    if(!arquivo.is_open()) return;
    
    string linha;
    getline(arquivo, linha); // Ignorar a linha de cabeçalho
    
    while(getline(arquivo, linha)) {
        Produto produto;
        stringstream ss(linha);
        string valor;
        
        getline(ss, valor, ',');
        produto.id = stoi(valor);
        
        getline(ss, produto.nome, ',');
        
        getline(ss, valor, ',');
        produto.preco = stod(valor);

        getline(ss, valor, ',');
        produto.tipo = stoi(valor);

        getline(ss, valor, ',');
        produto.quantidade = stoi(valor);
        
        getline(ss, valor, ',');
        produto.fornecedorID = stoi(valor);
        
        produtos.push_back(produto);
    }
    arquivo.close();
}

void carregarFornecedores(vector<Fornecedor>& fornecedores) {
    ifstream arquivo(NOME_ARQUIVO_FORNECEDORES);
    
    if(!arquivo.is_open()) return;
    
    string linha;
    getline(arquivo, linha); // Ignorar a linha de cabeçalho
    while(getline(arquivo, linha)) {
        Fornecedor fornecedor;
        stringstream ss(linha);
        string valor;
        
        getline(ss, valor, ',');
        fornecedor.id = stoi(valor);
        
        getline(ss, fornecedor.nome, ',');
        
        getline(ss, fornecedor.contato, ',');
        
        fornecedores.push_back(fornecedor);
    }
    arquivo.close();
}

void calcularCompra(vector<Produto>& produtos) {
    double total = 0;
    bool produtoEncontrado = false;

    string nomeProduto = "";
    cout << "Nome do Produto: ";
    cin >> nomeProduto;
    
    int tipo;
    cout << "Tipo (1 para unitário, 2 para por kilo): ";
    cin >> tipo;

    double quantidadeDesejada;
    cout << "Quantidade desejada: ";
    cin >> quantidadeDesejada;

    // Buscar o produto pelo nome no vetor de produtos
    if (!produtos.empty()) {
        for (auto& produto : produtos) {
            if (produto.nome == nomeProduto && produto.tipo == tipo) {
                produtoEncontrado = true;
                
                // Verificar se a quantidade em estoque é suficiente
                if (produto.quantidade >= quantidadeDesejada) {
                    // Calcular o preço total
                    total = produto.preco * quantidadeDesejada;
                    
                    // Subtrair a quantidade comprada do estoque
                    produto.quantidade -= quantidadeDesejada;

                    cout << "Valor total da compra de " << nomeProduto << ": R$" << total << endl;
                    cout << "Quantidade restante no estoque: " << produto.quantidade << endl;
                } else {
                    cout << "Quantidade em estoque insuficiente para a compra!" << endl;
                }
                break;
            }else {
                produtoEncontrado = false;
                cout << "\nProduto nao encontrado!" << endl;
            }
        }
        if (!produtoEncontrado) {
            cout << "Produto não encontrado!" << endl;
        }
    }else {
        cout << "\nNenhum produto cadastrado." << endl;
    }

}

void relatorioEstoque(vector<Produto>& produtos) {
    int quantidadeMinima = 10;
    if (!produtos.empty()) {
        cout << "\nProdutos em baixa quantidade de estoque:" << endl;
        for (auto& produto : produtos) {
            if (produto.quantidade <= quantidadeMinima) {
                cout << "\n-------------------------" << endl;
                cout << "ID: " << produto.id << endl;
                cout << "Produto: " << produto.nome << endl;
                cout << "Quantidade em estoque: " << produto.quantidade << endl;
                cout << "Fornecedor: " << produto.fornecedorID << endl;
                cout << "-------------------------" << endl;
            }
        }
    }else{
        cout << "\nNenhum produto cadastrado." << endl;
    }
}


void menuPrograma(){
    int opcao = 0;

    carregarProdutos(produtos);
    carregarFornecedores(fornecedores);
    const int opcaoSair = 8;
    do {
        cout << "\n Menu:" << endl;
        cout << " 1. Calcular Compra" << endl;
        cout << " 2. Adicionar Produto" << endl;
        cout << " 3. Editar Produto" << endl;
        cout << " 4. Listar Produtos" << endl;
        cout << " 5. Adicionar Fornecedor" << endl;
        cout << " 6. Listar Fornecedores" << endl;
        cout << " 7. Relatório de Estoque" << endl;
        cout << " " << opcaoSair << ". Sair" << endl;

        cout << "\nEscolha uma opção: ";
        cin >> opcao;
        cout << endl;
        
        switch(opcao) {
            case 1:
                calcularCompra(produtos);
                break;
            case 2:
                adicionarProduto(produtos, fornecedores);
                break;
            case 3:
                editarProduto(produtos, fornecedores);
                break;
            case 4:
                listarProdutos(produtos, fornecedores);
                break;
            case 5:
                adicionarFornecedor(fornecedores);
                break;
            case 6:
                listarFornecedores(fornecedores);
                break;
            case 7:
                relatorioEstoque(produtos);
                break;
            case opcaoSair:
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while(opcao != opcaoSair);
}