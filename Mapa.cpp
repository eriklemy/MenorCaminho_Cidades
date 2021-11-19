#include "Mapa.h"
#include <iostream>

using std::cout;
using std::endl;

// sobrecarga
Mapa::Mapa() {
    numNos = numCidades = 0;
    adj[0][0] = false;
    _peso[0][0] = INFINITO;
};

void Mapa::adiciona_cidade(TipoDado cidade) {
    Cidades[numCidades] = cidade;
    numCidades++;
};

bool Mapa::validos(int a, int b) const {
    return (a >= 0 && a < numNos && b >= 0 && b < numNos);
};

int Mapa::posCidade(TipoDado cidade) const {
    for(size_t i = 0; i < numCidades; i++) {
        if(Cidades[i] == cidade) {
            cout << Cidades[i] << endl; 
            return i;
        }
    }
    return INFINITO;
};

void Mapa::une(TipoDado cidadeA, TipoDado cidadeB, float distancia) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    if(validos(a, b)) {
        adj[a][b] = true;
        _peso[a][b] = distancia;
        numNos++;
    }
};

void Mapa::remove(TipoDado cidadeA, TipoDado cidadeB) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    if(validos(a, b))
        adj[a][b] = false;
};

bool Mapa::adjacente(int a, int b) const {
    if(validos(a, b))
        return adj[a][b];
    else return false;
};

void Mapa::imprime() const {
    for(int i = 0; i < numNos; i++) {
        for(int j = 0; j < numNos; j++)
            cout << adj[i][j];
        cout << endl;
    }

    cout << endl;

    for(int i = 0; i < numNos; i++) {
        for(int j = 0; j < numNos; j++) {
            if(adjacente(i, j))
                cout << _peso[i][j] << "  ";
            else cout << "*    ";
        }
        cout << endl;
    }
};

int Mapa::peso(int corrente, int i) const {
    return i;
};

void Mapa::MenorCaminho(TipoDado cidadeA, TipoDado cidadeB) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    int precede[] = {INFINITO};
    cout << MenorCaminho(a, b, precede) << endl;
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