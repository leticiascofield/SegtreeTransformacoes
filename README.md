# SegTree para Transformações Lineares

## Introdução

Neste projeto, exploramos a aplicação de uma árvore de segmentação (SegTree) para resolver um problema específico envolvendo transformações lineares em pares de coordenadas bidimensionais. A SegTree é uma estrutura de dados fundamental na computação que permite realizar consultas e atualizações em intervalos de um conjunto de dados. No contexto deste trabalho, utilizamos ela para otimizar as operações de atualização e consulta em uma matriz 2x2 que representa transformações lineares.

O problema consiste em realizar duas operações principais: a atualização de uma matriz de um determinado instante e a consulta do resultado da multiplicação cumulativa das matrizes em um intervalo específico. Cada ponto da SegTree armazena o resultado acumulado da multiplicação das matrizes associadas a seus descendentes.

Consideremos um exemplo para melhor compreensão. Primeiramente, foi criada uma árvore com 4 instantes (do 0 a 3) com matrizes identidade, depois todos eles foram atualizados para a matriz de valores 0, 1, 99999999 e 0, respectivamente. Como consequência disso, os pais também foram atualizados com a multiplicação dos filhos, obtendo a seguinte árvore:

![Captura de tela 2024-03-20 172904](https://github.com/leticiascofield/SegtreeTransformacoes/assets/125830543/70fab3f7-6d92-4567-9854-43ecf7976c11)


Nessa imagem, está representado os intervalos que são mantidos na árvore e, na raiz, a matriz do intervalo completo (de 0 a 3), como esse é o intervalo requerido nas consultas no exemplo, essa será a matriz considerada. A parte dos números em parênteses na imagem (99999998) na verdade não está presente na árvore, foi colocada apenas para melhor entendimento, pois apenas os 8 dígitos menos significativos serão considerados na impressão, então apenas eles são armazenados na matriz.

Com a matriz resultante já definida, é necessário apenas multiplicá-la pelas coordenadas x e y dadas na entrada. No caso, as duas consultas são (1,0) e (0,1) gerando então as seguintes operações e resultados esperados:

![Captura de tela 2024-03-20 173019](https://github.com/leticiascofield/SegtreeTransformacoes/assets/125830543/ed5069bb-5d72-4663-8633-53a5e44c4350)

Desse modo, é possível entender claramente tudo que engloba o problema.

## Método

#### Descrição da Implementação

O código foi desenvolvido em C++ para abordar a problemática apresentada, utilizando a estrutura de dados Segment Tree (SegTree). A implementação visa otimizar a realização de operações de atualização e consulta em uma matriz 2x2, representando transformações lineares bidimensionais.

#### Estruturas de Dados

**Matriz:**
A estrutura de dados Matriz representa uma matriz 2x2 de números inteiros positivos, essencial para as operações de transformações lineares. Cada instância dessa estrutura armazena os 4 elementos da matriz (m[0][0], m[0][1], m[1][0] e m[1][1]) e cada elemento é armazenado como um número de 64 bits para que haja precisão no cálculo.

**SegTree:**
A estrutura de dados SegTree foi implementada de forma particular. Ao invés de utilizar uma representação explícita da árvore, optou-se por armazenar os nós em um heap. Cada nó da árvore é armazenado sequencialmente no heap, e as relações entre os nós são mantidas por meio de índices.

#### Funções e Métodos Implementados do SegTree.cpp

**Atualizacao(int indiceSegTree, int inicioIntervalo, int fimIntervalo, int p, Matriz mat):**
Este método realiza uma atualização na árvore de segmentação, modificando o valor do elemento na posição p pela matriz fornecida (mat). A atualização ocorre de forma recursiva, percorrendo os nós da árvore até o nó folha correspondente ao intervalo que contém o elemento p, depois disso ele atualiza os valores de todos os ascendentes desse nó de acordo com a mudança em p.

**Consulta(int indiceSegTree, int inicioIntervalo, int fimIntervalo, int consultaInicio, int consultaFim):**
Esse método realiza uma consulta na árvore de segmentação, retornando o resultado da multiplicação matricial dentro do intervalo especificado. A consulta também é realizada de forma recursiva, considerando os intervalos associados aos nós da árvore.

**multiplicar(const Matriz &a, const Matriz &b):**
Este método privado realiza a multiplicação de duas matrizes e retorna o resultado. Essa operação é essencial para as operações de atualização e consulta na árvore de segmentação. Além disso, ele também usa “% 100000000” para retornar apenas os 8 dígitos menos significativos, como especificado no enunciado, impedindo que os valores tendam ao infinito (ou, na realidade, ao limite da máquina) para casos consideravelmente grandes.
