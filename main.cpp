/* 
    PEDA (2021)
    ERICK LEMMY DOS SANTOS OLIVEIRA
    PROJETO FINAL: 
        MENOR CAMINHO ENTRE CIDADES
*/
#include <iostream>
#include <fstream>
#include <string>
#include "Mapa.h"

using namespace std;

void adiciona_cidade();
void uneCidade();

int main() {
    Mapa m;
    string cidadeA, cidadeB;

    adiciona_cidade();
    uneCidade();
    m.imprime();    

    // cout << "Digite o nome da Cidade de Origem: " << endl;
    // getline(cin, cidadeA);

    // cout << "Digite o nome da Cidade de Destino: " << endl;
    // getline(cin, cidadeB);

    // m.MenorCaminho(cidadeA, cidadeB);
}

void adiciona_cidade() {
    Mapa m;
    m.adiciona_cidade("Curitiba");  // 1a cidade
    m.adiciona_cidade("Registro");  // 2a cidade
    m.adiciona_cidade("São Paulo");
    m.adiciona_cidade("Itararé");
    m.adiciona_cidade("Londrina");
    m.adiciona_cidade("Ponta Grossa");
    m.adiciona_cidade("Mafra");
    m.adiciona_cidade("Porto União");
    m.adiciona_cidade("Blumenau");
    m.adiciona_cidade("Joinville");
    m.adiciona_cidade("Itajaí");
    m.adiciona_cidade("Florianópolis");
    m.adiciona_cidade("Lages");
}

void uneCidade() {
    Mapa m;
    m.une("Londrina", "Itarare", 310);
    m.une("Londrina", "Ponta Grossa", 271);
    m.une("Itarare", "Sao Paulo", 342);
    m.une("Itarare", "Curitiba", 208);
    m.une("Itarare", "Ponta Grossa", 174);
    m.une("Curitiba", "Ponta Grossa", 114);
    m.une("Curitiba", "Mafra", 115);
    m.une("Curitiba", "Joinville", 132);
    m.une("Registro", "Curitiba", 221.2);
    m.une("Registro", "Sao Paulo", 185.9);
    m.une("Mafra", "Joinville", 136);
    m.une("Mafra", "Blumenau", 165);
    m.une("Mafra", "Ponta Grossa", 155);
    m.une("Porto Uniao", "Mafra", 143);
    m.une("Porto Uniao", "Ponta Grossa", 209);
    m.une("Porto Uniao", "Lages", 271);
    m.une("Lages", "Mafra", 349);
    m.une("Lages", "Blumenau", 223);
    m.une("Lages", "Florianopolis", 231);
    m.une("Itajai", "Florianopolis", 102);
    m.une("Itajai", "Blumenau", 52.3);
    m.une("Itajai", "Joinville", 86.2);
}

/*
Cidade A: Curitiba
Cidade B: Sao Paulo

Menor distância = 407.1 km
Menor caminho = Curitiba -> Registro -> Sao Paulo
*/
