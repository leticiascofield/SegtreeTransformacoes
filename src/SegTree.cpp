#include "../include/SegTree.hpp"


SegTree::SegTree(int n) {
    posicao = new Matriz[4 * n];
    for (int i = 0; i < 4 * n; i++) {
        posicao[i].m[0][0] = 1;
        posicao[i].m[0][1] = 0;
        posicao[i].m[1][0] = 0;
        posicao[i].m[1][1] = 1;
    }
}

void SegTree::Atualizacao(int indiceSegTree, int inicioIntervalo, int fimIntervalo, int p, Matriz *mat) {
    if (inicioIntervalo > p || fimIntervalo < p) {
        return;
    }
    if (inicioIntervalo == fimIntervalo) {
        this->posicao[indiceSegTree] = *mat;
        return;
    }
    int m = (inicioIntervalo + fimIntervalo) / 2;
    Atualizacao(2 * indiceSegTree + 1, inicioIntervalo, m, p, mat);
    Atualizacao(2 * indiceSegTree + 2, m + 1, fimIntervalo, p, mat);
    posicao[indiceSegTree] = multiplicar(this->posicao[2 * indiceSegTree + 1], this->posicao[2 * indiceSegTree + 2]);
}

Matriz SegTree::Consulta(int indiceSegTree, int inicioIntervalo, int fimIntervalo, int consultaInicio, int consultaFim) {

    if (inicioIntervalo > consultaFim || fimIntervalo < consultaInicio) {
        return Matriz(1, 0, 0, 1);
    }

    if (inicioIntervalo >= consultaInicio && fimIntervalo <= consultaFim) {
        return posicao[indiceSegTree];
    }

    int m = (inicioIntervalo + fimIntervalo) / 2;
    Matriz Esq = Consulta(2 * indiceSegTree + 1, inicioIntervalo, m, consultaInicio, consultaFim);
    Matriz Dir = Consulta(2 * indiceSegTree + 2, m + 1, fimIntervalo, consultaInicio, consultaFim);
    return multiplicar(Esq, Dir);
}

SegTree::~SegTree() {
    delete[] posicao;
}

Matriz SegTree::multiplicar(const Matriz &a, const Matriz &b) {
    Matriz resultado;
    resultado.m[0][0] = ( a.m[0][0] * b.m[0][0] +  a.m[0][1] * b.m[1][0]) % 100000000;
    resultado.m[0][1] = ( a.m[0][0] * b.m[0][1] +  a.m[0][1] * b.m[1][1]) % 100000000;
    resultado.m[1][0] = ( a.m[1][0] * b.m[0][0] +  a.m[1][1] * b.m[1][0]) % 100000000;
    resultado.m[1][1] = ( a.m[1][0] * b.m[0][1] +  a.m[1][1] * b.m[1][1]) % 100000000;

    return resultado;
}