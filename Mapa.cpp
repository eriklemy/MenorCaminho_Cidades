#include "Mapa.h"
#include <iostream>

using std::cout;
using std::endl;

Mapa::Mapa() {
    numNos = numCidades = 0;
    Tabela[0][0].adj = false;
    Tabela[0][0].peso = INFINITO;
};

// sobrecarga
Mapa::Mapa(int N) {
    numNos = N;
    numCidades = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            Tabela[i][j].adj = false;
            Tabela[i][j].peso = INFINITO;
    }
};

bool Mapa::validos(int a, int b) const {
    return (a >= 0 && a < N && b >= 0 && b < N);
};

void Mapa::une(TipoDado a, TipoDado b, float p) {
    if(validos(a, b)) {
        adj[a][b] = true;
        peso[a][b] = p;
    }
};

void adiciona_cidade(TipoDado cidade) {
    Cidades[numCidades] = cidade;
    numCidades++;
};

void Mapa::remove(int a, int b) {
    if(validos(a, b))
        adj[a][b] = false;
};

bool Mapa::adjacente(int a, int b) const {
    if(validos(a, b))
        return adj[a][b];
    else return false;
};

void Mapa::imprime() const {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++)
            cout << adj[i][j];
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(adjacente(i, j))
                cout << peso[i][j] << "  ";
            else cout << "*    ";
        }
        cout << endl;
    }
};

int peso(int corrente, int i) const {
    return Tabela[i][corrente].peso;
};

int Mapa::MenorCaminho(int s, int t, int precede[]) {
    int distancia[MAXNOS];
    bool calculado[MAXNOS];

    for(size_t i = 0; i < numNos; i++) {
        distancia[i] = INFINITO;
        calculado[i] = false;
    }

    distancia[s] = 0;
    calculado[s] = true;
    int corrente = s;

    while (corrente != t) {
        float menordist = INFINITO;            // menor das novas distâncias calculadas
        int k;                               // próximo corrente (aquele com menor distância)
        float dc = distancia[corrente];        // distância calculada de s até o nó corrente
        for(size_t i = 0; i < numNos; i++) {
            if (!calculado[i]) {
                float novadist = dc + peso(corrente, i);
                if (novadist < distancia[i]) {
                    distancia[i] = novadist;
                    precede[i] = corrente;
                }
                if (distancia[i] < menordist) {
                    menordist = distancia[i];
                    k = i;
                }
            } // se já calculado não faz nada
        } // fim do for
        corrente = k;
        calculado[corrente] = true;
    }
    return distancia[t];
}