#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void readCSV(const string& filename) {
    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Erro ao abrir o arquivo: " << filename << endl;
        return;
    }
    cout << "\033[2J\033[1;1H";

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<string> row;

        while (getline(ss, value, ',')) {
            row.push_back(value);
        }

        // Exibe a linha completa
        for (const auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    file.close();
}

int main() {
    string filename = "teste.csv"; // Nome do arquivo CSV
    readCSV(filename);

    return 0;
}
