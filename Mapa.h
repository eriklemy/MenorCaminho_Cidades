#ifndef MAPA_H
#define MAPA_H
#include <string> 
#include <vector>

constexpr int MAXNOS = 100;
constexpr int INFINITO = 1e9;
using TipoDado = std::string;

class Mapa {
    public: 
        Mapa();
        void adiciona_cidade(TipoDado cidade);
        void une(TipoDado cidadeA, TipoDado cidadeB, float distancia);
        void remove(TipoDado cidadeA, TipoDado cidadeB);
        bool adjacente(int a, int b) const;
        void imprime() const;
        float peso(int corrente, int i) const;
        void MenorCaminho(TipoDado cidadeA, TipoDado cidadeB);
    private: 
        size_t numNos;
        float _peso[MAXNOS][MAXNOS];
        int adj[MAXNOS][MAXNOS];
        TipoDado Cidades[MAXNOS];
        std::vector<TipoDado> caminho;
        
        bool validos(int a, int b) const;
        int posCidade(TipoDado cidade) const;
        float MenorCaminho(int corrente, int i, int precede[]);
        void imprimeCaminho(std::vector<TipoDado> caminho, int corrente) const;
};
#endif // !MAPA_H