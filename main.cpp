#include <iostream>
#include "Mapa.h"

using namespace std;

int main() {
    Mapa m(0);
    m.adiciona_cidade("Curitiba");  // 1a cidade
    m.adiciona_cidade("Registro");  // 2a cidade
    // etc.

    m.une("Curitiba", "Registro", 221.2);
    m.une("Registro", "São Paulo", 185.9);
    // etc.
    m.imprime();
 
}

/*
Cidade A: Curitiba
Cidade B: Sao Paulo

Menor distância = 407.1 km
Menor caminho = Curitiba -> Registro -> Sao Paulo

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

*/
