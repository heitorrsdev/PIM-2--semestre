#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "tipos.cpp"

using namespace std;

const string NOME_ARQUIVO_PRODUTOS = "DB/produtos.csv";
const string NOME_ARQUIVO_FORNECEDORES = "DB/fornecedores.csv";

vector<Produto> produtos;
vector<Fornecedor> fornecedores;

void limparTerminal () {
    cout << "\033[2J\033[1;1H";
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

    cout << "Selecione o Fornecedor pelo ID: " << endl;
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
    arquivo.close();
}

void salvarFornecedores(const vector<Fornecedor>& fornecedores) {
    ofstream arquivo(NOME_ARQUIVO_FORNECEDORES);
    arquivo << "ID,Nome,Contato\n";
    for(const auto& fornecedor : fornecedores) {
        arquivo << fornecedor.id << ","
                << fornecedor.nome << ","
                << fornecedor.contato << "\n";
    }
    arquivo.close();
}

void adicionarProduto(vector<Produto>& produtos, const vector<Fornecedor>& fornecedores) {
    int id;
    cout << "ID do Produto: ";
    cin >> id;
    Produto novoProduto = criarProduto(id, fornecedores);
    produtos.push_back(novoProduto);
    salvarProdutos(produtos);
    cout << "Produto adicionado com sucesso!" << endl;
}

void editarProduto(vector<Produto>& produtos, const vector<Fornecedor>& fornecedores) {
    int id;
    cout << "Informe o ID do produto que deseja editar: ";
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
        cout << "ID: " << produto.id << endl;
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


void menuPrograma(){
    cout <<"ta exibindo alguma coisa?";
    int opcao = 0;
    carregarProdutos(produtos);
    carregarFornecedores(fornecedores);
    do {
        cout << "Menu:" << endl;
        cout << "1. Adicionar Produto" << endl;
        cout << "2. Editar Produto" << endl;
        cout << "3. Listar Produtos" << endl;
        cout << "4. Listar Fornecedores" << endl;
        cout << "5. Adicionar Fornecedor" << endl;
        cout << "6. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;
        
        switch(opcao) {
            case 1:
                adicionarProduto(produtos, fornecedores);
                break;
            case 2:
                editarProduto(produtos, fornecedores);
                break;
            case 3:
                listarProdutos(produtos, fornecedores);
                break;
            case 4:
                listarFornecedores(fornecedores);
                break;
            case 5:
                adicionarFornecedor(fornecedores);
                break;
            case 6:
                salvarProdutos(produtos);
                salvarFornecedores(fornecedores);
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    } while(opcao != 6);
}

