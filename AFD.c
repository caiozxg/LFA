#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 10;

int main() {
    int qtdEstados, qtdAlfabetos;
    char estados[MAX][10];
    char Alfabetos[MAX][10];
    char estadoInicial[10];
    char estadosFinais[MAX][10];
    int qtdFinais;

    char delta[MAX][MAX][10];

    // Ler alfabeto
    cout << "Quantidade de Alfabetos no alfabeto: ";
    cin >> qtdAlfabetos;
    for (int i = 0; i < qtdAlfabetos; i++) {
        cout << "Alfabeto " << i + 1 << ": ";
        cin >> Alfabetos[i];
    }

    // Ler estados
    cout << "Quantidade de estados: ";
    cin >> qtdEstados;
    for (int i = 0; i < qtdEstados; i++) {
        cout << "Estado " << i + 1 << ": ";
        cin >> estados[i];
    }

    // Ler estado inicial
    cout << "Estado inicial: ";
    cin >> estadoInicial;

    // Ler estados finais
    cout << "Quantidade de estados finais: ";
    cin >> qtdFinais;
    for (int i = 0; i < qtdFinais; i++) {
        cout << "Estado final " << i + 1 << ": ";
        cin >> estadosFinais[i];
    }

    // Ler transições
    cout << "Defina as transicoes:\n";
    for (int i = 0; i < qtdEstados; i++) {
        for (int j = 0; j < qtdAlfabetos; j++) {
            cout << "Delta(" << estados[i] << ", " << Alfabetos[j] << "): ";
            cin >> delta[i][j];
        }
    }

    // Ler palavra
    char palavra[100];
    cout << "\nDigite a palavra: ";
    cin >> palavra;

    // Processar palavra
    char estadoAtual[10];
    strcpy(estadoAtual, estadoInicial);
    cout << "Caminho: " << estadoAtual;

    bool erro = false;          //para testar se tem algum erroo, tipo Alfabeto ou estado que nao foi informado na hora da entrada
    for (int i = 0; i < strlen(palavra); i++) {
        char Alfabeto[10] = {palavra[i], '\0'};   //pega a letra especifica, com o /0 no final para garantir que a string esta no fim

        // Achar índice do símbolo
        int AlfabetoIndex = -1;
        for (int j = 0; j < qtdAlfabetos; j++) {
            if (strcmp(Alfabeto, Alfabetos[j]) == 0) {
                AlfabetoIndex = j;                  //pega o index do alfabeto
                break;
            }
        }

        if (AlfabetoIndex == -1) {
            cout << "\nAlfabeto '" << Alfabeto << "' nao pertence ao alfabeto!\n";
            erro = true;
            break;
        }

        // Achar índice do estado atual
        int estadoIndex = -1;
        for (int j = 0; j < qtdEstados; j++) {
            if (strcmp(estadoAtual, estados[j]) == 0) {
                estadoIndex = j;            //pega o index do estado
                break;
            }
        }
        //para fazer o teste que comentei na hora q declarei a variavel erro
        if (estadoIndex == -1) {
            cout << "\nEstado atual invalido!\n";
            erro = true;
            break;
        }

        // Fazer a transição
        strcpy(estadoAtual, delta[estadoIndex][AlfabetoIndex]);     //pegamos os index do estado e alfabeto que estamos, ele envia esses dois index para delta, que é onde esta o "manual" do automato, e passa para estadoatual o que seria o prox estado de acordo com o delta(manual)
        cout << " -> " << estadoAtual;
    }

    if (!erro) {
        // Verificar se está em estado final
        bool aceita = false;
        for (int i = 0; i < qtdFinais; i++) {
            if (strcmp(estadoAtual, estadosFinais[i]) == 0) {
                aceita = true;
                break;
            }
        }

        if (aceita) {
            cout << "\nA palavra foi reconhecida!\n";
        } else {
            cout << "\nA palavra NAO foi reconhecida.\n";
        }
    }

    return 0;
}
