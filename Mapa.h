#ifndef MAPA_H
#define MAPA_H
#include <string> 

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
        int numNos;
        float _peso[MAXNOS][MAXNOS];
        int adj[MAXNOS][MAXNOS];
        TipoDado Cidades[MAXNOS];
        bool validos(int a, int b) const;
        int posCidade(TipoDado cidade) const;
        float MenorCaminho(int corrente, int i, int precede[]);
};
#endif // !MAPA_H