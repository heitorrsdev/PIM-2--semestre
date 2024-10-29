#include <iostream>
#include <vector>
#include "tipos.cpp"

using namespace std;

// limpa o terminal
void limparTerminal () {
    cout << "\033[2J\033[1;1H";
}

void exibirProdutos(vector <Produto> produtos) {
    cout << "\nProdutos disponíveis:\n";
    for (int i = 0; i < produtos.size(); ++i) {
        cout << endl << i + 1 << " "<< produtos[i].nome << ": R$" << produtos[i].preco;
        
        if (produtos[i].tipo == "1") {
            cout << " (unidade)";
        } else if (produtos[i].tipo == "2") {
            cout << " (kg)";
        }
        cout << endl;
    }
}

void adicionarProduto(vector <Produto> &produtos, const string& tipo, const string& nome, double preco, int quantidade) {
    produto Produto = {tipo, nome, preco, quantidade};
    produtos.push_back(Produto);
}

// menu de compra de produtos
void menuComprarProduto() {
    double total = 0.0;
    vector <Produto> produtos;
    //PARA TESTE:
    adicionarProduto(produtos, "1", "maçã", 3.50, 10);
    adicionarProduto(produtos, "2", "Banana", 5.00, 15);
    adicionarProduto(produtos, "1", "Laranja", 4.00, 20);
    

    limparTerminal();

    cout << "Bem-vindo ao Hortifruti do Sr. Elias!\n";

    while (true) {
        exibirProdutos(produtos);
        cout << "\nDigite o número do produto (ou 0 para sair):\n";
        
        int idProduto;
        cin >> idProduto;
        if (idProduto == 0) { // sair
            break;
        }
        idProduto -= 1;

        if (idProduto < 0 || idProduto > produtos.size()) { //entrada inválida
            cout << "Produto inválido, tente novamente.\n";
        }
        else if (produtos[idProduto].quantidadeEstoque == 0) { // sem estoque
            cout << "Produto sem estoque, tente novamente.\n";
        }
        else {
            while (true) {    
                if(produtos[idProduto].tipo == "1") { //unidade
                    int qtdUn;
                    cout << "\nQuantidade: ";
                    cin >> qtdUn;

                    if(qtdUn > produtos[idProduto].quantidadeEstoque || qtdUn <= 0) { // tratando erros
                        cout << "\nQuantidade inválida, há apenas " << produtos[idProduto].quantidadeEstoque;
                        cout << " unidades em estoque.\n";
                    }
                    else{
                        cout << "Adicionado: " << produtos[idProduto].nome << " x " << qtdUn << endl;
                        total += produtos[idProduto].preco * qtdUn;
                        // atualizar estoque somente na confirmação da compra!
                        produtos[idProduto].quantidadeEstoque -= qtdUn;
                        break; 
                    }
                }
                else if(produtos[idProduto].tipo == "2") { //kg
                    double qtdKg;
                    cout << "Quantidade (kg): ";
                    cin >> qtdKg;

                    if(qtdKg > produtos[idProduto].quantidadeEstoque || qtdKg <= 0) { // tratando erros
                        cout << "\nQuantidade inválida, há apenas" << produtos[idProduto].quantidadeEstoque;
                        cout << " kg em estoque.\n";
                    }
                    else{
                        cout << "\nAdicionado: " << produtos[idProduto].nome << " x " << qtdKg << " kg" << endl;
                        total += produtos[idProduto].preco * qtdKg;
                        // atualizar estoque somente na confirmação da compra!
                        produtos[idProduto].quantidadeEstoque -= qtdKg;
                        break; 
                    }
                }
            }
            
        }
        string opcao;
        while (true) {
            cout << "\nDeseja comprar outro item? (s/n): ";
            cin >> opcao;
            if (opcao != "s" && opcao != "n") {
                cout << "Opção inválida. Tente novamente.\n";
            }
            else{
                break;
            }
        }
        if (opcao == "n") {
            break;
        }
    }
    //compra finalizada
    cout << "\nTotal: R$" << total << endl;
}