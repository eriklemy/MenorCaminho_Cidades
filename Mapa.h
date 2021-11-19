#ifndef MAPA_H
#define MAPA_H
#include <string> 

constexpr int MAXNOS = 100;
constexpr int INFINITO = 1e9;
using TipoDado = std::string;

class Mapa {
    public: 
        Mapa(int numNos);
        void une(TipoDado a, TipoDado b, float p);
        void adiciona_cidade(TipoDado cidade);
        void remove(TipoDado a, TipoDado b);
        bool adjacente(TipoDado a, TipoDado b) const;
        void imprime() const;
        int peso(int corrente, int i) const ;
        void MenorCaminho(int corrente, int i, int precede[]);
    protected:
        struct Arco {
            bool adj;
            float peso;
        };
    private: 
        int numNos;
        int numCidades;
        Arco Table[MAXNOS][MAXNOS];
        TipoDado Cidades[MAXNOS];
        bool validos(int a, int b) const;
};
#endif // !MAPA_H