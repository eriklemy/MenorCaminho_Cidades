#include "Mapa.h"
#include <iostream>

using std::cout;
using std::endl;

// sobrecarga
Mapa::Mapa() {
    numNos = 0;
    adj[0][0] = false;
    _peso[0][0] = INFINITO;
};

void Mapa::adiciona_cidade(TipoDado cidade) {
    Cidades[numNos] = cidade;
    numNos++;
};

bool Mapa::validos(int a, int b) const {
    return (a >= 0 && a < numNos && b >= 0 && b < numNos);
};

int Mapa::posCidade(TipoDado cidade) const {
    for(size_t i = 0; i < numNos; i++) {
        cout << "antes: " << Cidades[i] << "| " << cidade << endl;
        if(cidade.compare(Cidades[i]) == 0) {
            cout << "depois: " << Cidades[i] << "| " << cidade << endl;
            return i;
        }
    }
    cout << "teste 1" << endl;
    return INFINITO;
};

void Mapa::une(TipoDado cidadeA, TipoDado cidadeB, float distancia) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    cout << "une: " << Cidades[a] << "| " << Cidades[b] << endl;
    if(validos(a, b)) {
        adj[a][b] = true;
        _peso[a][b] = distancia;
    }
};

void Mapa::remove(TipoDado cidadeA, TipoDado cidadeB) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    if(validos(a, b)) {
        adj[a][b] = false;
        _peso[a][b] = INFINITO;
    }
};

bool Mapa::adjacente(int a, int b) const {
    if(validos(a, b))
        return adj[a][b];
    else return false;
};

void Mapa::imprime() const {
    cout << "------------------------------------" << endl;
    cout << "|       Adjacente       | Cidades  |" << endl;
    cout << "|-----------------------|----------|" << endl;
    for(size_t cidades = 0; cidades < numNos; cidades++) 
        cout << "| " << Cidades[cidades] << " ";

    cout << endl;
    
    for(size_t i = 0; i < numNos; i++) {
        for(size_t j = 0; j < numNos; j++) {
            // distancia se as cidades forem adjacentes
            if(adj[i][j]) 
                cout << "| " << _peso[i][j] << "\t";
            // cidades nao adjacentes
            if(!adj[i][j])
                cout << "|False" << "\t";
        }
        // nome das cidades na ultima coluna
        cout << "| " << Cidades[i] << endl;
    }
    cout << "---------------------------------\t" << endl;
};

int Mapa::peso(int corrente, int i) const {
    if(adjacente(i, corrente))
        return _peso[i][corrente];
    else return INFINITO;
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

    while(corrente != t) {
        float menordist = INFINITO;            // menor das novas distâncias calculadas
        int k;                                 // próximo corrente (aquele com menor distância)
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