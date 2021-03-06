/* 
    PEDA (2021)
    ERICK LEMMY DOS SANTOS OLIVEIRA
    PROJETO FINAL: 
        MENOR CAMINHO ENTRE CIDADES
*/
#include <iostream>
#include <fstream>
#include <string>
#include "src/Mapa.h"
using namespace std;

void adicionaCidade(Mapa &m);
void adicionaCidadebyTxt(Mapa &m, string nomeArq);
void uneCidade(Mapa &m);
void inicio();

int main() {
    Mapa m;
    string cidadeA, cidadeB;
    // adicionaCidadebyTxt(m, "cidades");
    adicionaCidade(m);
    uneCidade(m);

    inicio();
    // m.imprime();  // visualizar matriz de adjacentes

    cout << "Digite o nome da Cidade de Origem: " << endl;
    getline(cin, cidadeA);
    cout << "Digite o nome da Cidade de Destino: " << endl;
    getline(cin, cidadeB);

    cout << "\nCidade A: " << cidadeA << endl;
    cout << "Cidade B: " << cidadeB << endl << endl;
    m.MenorCaminho(cidadeA, cidadeB);
}

void inicio() {
    cout << "|---------------------------------------|" << endl;
    cout << "|--- PEDA (2021)                        |" << endl;
    cout << "|--- Menor Caminho entre Cidades        |" << endl;
    cout << "|--- Erick Lemmy dos Santos Oliveira    |" << endl;
    cout << "|---------------------------------------|" << endl;
    cout << "Entre com a cidade de Origem e Destino para obter o menor caminho!!\n" << endl;
}

// Ao usar txt se atentar a forma 
// ex: Curitiba,Registro,Sao Paulo,Itarare,Londrina,...
void adicionaCidadebyTxt(Mapa &m, string nomeArq) {
    ifstream file(nomeArq + ".txt");
    string data = "";
    while(getline(file, data, ','))
       m.adiciona_cidade(data);
}

void adicionaCidade(Mapa &m) {
    m.adiciona_cidade("Curitiba");  // 1a cidade
    m.adiciona_cidade("Registro");  // 2a cidade
    m.adiciona_cidade("Sao Paulo");
    m.adiciona_cidade("Itarare");
    m.adiciona_cidade("Londrina");
    m.adiciona_cidade("Ponta Grossa");
    m.adiciona_cidade("Mafra");
    m.adiciona_cidade("Porto Uniao");
    m.adiciona_cidade("Blumenau");
    m.adiciona_cidade("Joinville");
    m.adiciona_cidade("Itajai");
    m.adiciona_cidade("Florianopolis");
    m.adiciona_cidade("Lages");
}

void uneCidade(Mapa &m) {
    m.une("Curitiba", "Registro", 221.2);
    m.une("Curitiba", "Ponta Grossa", 114);
    m.une("Curitiba", "Mafra", 115);
    m.une("Curitiba", "Joinville", 132);
    m.une("Curitiba", "Itarare", 208);
    m.une("Registro", "Sao Paulo", 185.9);
    m.une("Itarare", "Sao Paulo", 342);
    m.une("Itarare", "Londrina", 310);
    m.une("Itarare", "Ponta Grossa", 174);
    m.une("Ponta Grossa", "Londrina", 271);
    m.une("Ponta Grossa", "Porto Uniao", 209);
    m.une("Ponta Grossa" ,"Mafra", 155);
    m.une("Mafra", "Blumenau", 165);
    m.une("Mafra", "Joinville", 136);
    m.une("Mafra", "Porto Uniao", 143);
    m.une("Mafra", "Lages", 10);
    m.une("Lages", "Porto Uniao", 271);
    m.une("Lages", "Blumenau", 223);
    m.une("Lages", "Florianopolis", 231);
    m.une("Itajai", "Florianopolis", 102);
    m.une("Itajai", "Blumenau", 52.3);
    m.une("Itajai", "Joinville", 86.2);
}

