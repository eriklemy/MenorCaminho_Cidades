#include "Mapa.h"
#include <iostream>
#include <strings.h>

using namespace std;

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
        // compara ignorando CAIXA ALTA | CAIXA BAIXA
        if(strcasecmp(cidade.c_str(), Cidades[i].c_str()) == 0) 
            return i;
    }
    return INFINITO;
};

void Mapa::une(TipoDado cidadeA, TipoDado cidadeB, float distancia) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    if(validos(a, b)) {
        adj[a][b] = adj[b][a] = true;
        _peso[a][b] = _peso[b][a] = distancia;
    }
};

void Mapa::remove(TipoDado cidadeA, TipoDado cidadeB) {
    int a = posCidade(cidadeA);
    int b = posCidade(cidadeB);
    if(validos(a, b)) {
        adj[a][b] = adj[b][a] = false;
        _peso[a][b] = _peso[b][a] = INFINITO;
    }
};

bool Mapa::adjacente(int a, int b) const {
    if(validos(a, b))
        return adj[a][b];
    else return false;
};

void Mapa::imprime() const {
    cout << "|-------------------------------------------------------------------------------------------------------|----------------|" << endl;
    cout << "|                                                      Adjacentes                                       |     Cidades    |" << endl;
    cout << "|-------------------------------------------------------------------------------------------------------|----------------|" << endl;
    
    // abreviação cidades -> primeiro linha
    for(size_t cidades = 0; cidades < numNos; cidades++) 
        cout << "| " << Cidades[cidades].substr(0, 5) << "\t";
    
    cout << endl;
    // Adjacentes -> peso / Falso (caso não seja)
    for(size_t i = 0; i < numNos; i++) {
        for(size_t j = 0; j < numNos; j++) {
            if(adj[i][j]) 
                cout << "| " << _peso[i][j] << "\t";
            if(!adj[i][j])
                cout << "| False" << "\t";
        }
        // Cidades -> ultima coluna
        cout << "| " << Cidades[i] << endl; 
    }
    cout << "------------------------------------------------------------------------------------------------------------------------\t" << endl;
};

float Mapa::peso(int corrente, int i) const {
    if(adjacente(i, corrente))
        return _peso[i][corrente];
    else return INFINITO;
};

void Mapa::imprimeCaminho(std::vector<TipoDado> caminho) const {  
    cout << "Menor Caminho = ";
    for (size_t i = caminho.size() - 1; i > 0; i--) 
        cout << caminho[i] << " -> ";
    
    cout << caminho[0];
};

void Mapa::MenorCaminho(TipoDado CidadeOrigem, TipoDado cidadeDestino) {
    int posCidadeOrigem = posCidade(CidadeOrigem);
    int posCidadeDestino = posCidade(cidadeDestino);
    int precede[numNos];

    if(posCidadeOrigem != INFINITO && posCidadeDestino != INFINITO) {
        cout << "Menor distancia = ";
        cout << MenorCaminho(posCidadeOrigem, posCidadeDestino, precede) << " Km" << endl;
        imprimeCaminho(caminho);
    } else cerr << "Cidade nao Encontrada!!" << endl;
};

// algoritmo de Dijkstra do menor caminho
float Mapa::MenorCaminho(int cidadeOrigem, int cidadeDestino, int precede[]) {
    float distancia[MAXNOS];
    bool calculado[MAXNOS];
    
    for(size_t i = 0; i < numNos; i++) {
        distancia[i] = INFINITO;
        calculado[i] = false;
    }

    distancia[cidadeOrigem] = 0;
    calculado[cidadeOrigem] = true;
    int corrente = cidadeOrigem;

    while(corrente != cidadeDestino) {
        float menordist = INFINITO;            // menor das novas distâncias calculadas
        int k;                                 // próximo corrente (aquele com menor distância)
        float dc = distancia[corrente];        // distância calculada de cidadeOrigem até o nó corrente
        for(size_t i = 0; i < numNos; i++) {
            if(!calculado[i]) {
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

    TipoDado cidadeAtual = Cidades[cidadeDestino];
    int cidadeInicial = posCidade(Cidades[corrente]);
    do {
        caminho.push_back(cidadeAtual);
        cidadeAtual = Cidades[precede[cidadeInicial]];
        cidadeInicial = posCidade(cidadeAtual);
    } while (cidadeAtual != Cidades[cidadeOrigem]);
    caminho.push_back(cidadeAtual);

    return distancia[cidadeDestino];
}