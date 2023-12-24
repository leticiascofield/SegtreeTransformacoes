#include <iostream>
#include "../include/SegTree.hpp"

using namespace std;

int main() {
    int n, q;
    char comando;
    cin >> n >> q;

    SegTree *segTree = new SegTree(n);
    Matriz *matriz = nullptr;
    int novoX, novoY;
    Matriz resultado;

    while (q--) {
        cin >> comando;
        
        switch (comando) {
        case 'u':
            int a;
            cin >> a;
            unsigned long long int x1, x2, x3, x4;
            cin >> x1 >> x2 >> x3 >> x4;
            matriz = new Matriz(x1, x2, x3, x4);
            segTree->Atualizacao(0, 0, n - 1, a, matriz);
            break;
        case 'q':
            int t0, td, x, y;
            cin >> t0 >> td >> x >> y;
            resultado = segTree->Consulta(0, 0, n - 1, t0 , td );
            novoX = ( resultado.m[0][0] * x +  resultado.m[0][1] * y) % 100000000;
            novoY = ( resultado.m[1][0] * x +  resultado.m[1][1] * y) % 100000000;

            cout << novoX << " " << novoY << endl;
            break;
        default:
            cout << "Comando inválido" << endl;
            break;
        }
    }

    delete matriz;
    delete segTree;
    
    return 0;
}
