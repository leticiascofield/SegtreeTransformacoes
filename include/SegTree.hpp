#ifndef SEGTREE_HPP
#define SEGTREE_HPP

#include "Matriz.hpp"

class SegTree {
public:
    Matriz *posicao;

    SegTree(int n);
    void Atualizacao(int indiceSegTree, int inicioIntervalo, int fimIntervalo, int p, Matriz *mat);
    Matriz Consulta(int indiceSegTree, int inicioIntervalo, int fimIntervalo, int consultaInicio, int consultaFim);
    ~SegTree();

private:
    Matriz multiplicar(const Matriz &a, const Matriz &b);
};

#endif