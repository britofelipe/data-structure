// -----------------------------------------------------------------------------
// Universidade Federal do Ceará, Centro de Ciências, Departamento de Computação
// Disciplina: Estruturas de Dados - TI0140 2022.2 T02A
// Professor: Pablo Mayckon Silva Farias
// Trabalho 2
// Interface para Implementação de Dicionário baseado em Árvore AVL.
// Autor: Pablo Mayckon Silva Farias, em 22/11/2022.
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// IDENTIFICAÇÃO DO(A) ESTUDANTE:
//
// NOME: FELIPE ARRUDA BRITO
// MATRÍCULA: 535658
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------
// Tudo o que está presente na interface abaixo deve ser mantido como está,
// pois é essa interface que será utilizada no programa do professor para a
// realização dos testes.
//
// A realização do trabalho consiste portanto em *completar* a implementação
// abaixo, tornando-a funcional e atendendo aos requisitos deste trabalho.
// -----------------------------------------------------------------------------

// APAGAR
struct DicioAVL {

    #define CONT 10

    typedef double TC;  // Tipo das Chaves
    typedef float  TV;  // Tipo dos Valores

    // Subclasse Nó
    struct Noh {  
        TC chave;  
        TV valor;  
        int altura;  
        Noh *esq; 
        Noh *dir;
    };

    Noh* novoNo(TC chave, TV valor) {
        Noh *novo = new Noh;

        novo->chave = chave;
        novo->valor = valor;
        novo->altura = 0;
        novo->esq = &sent;
        novo->dir = &sent;
    }

    Noh sent, *raiz;  // "sent": Sentinela.

    // Conforme a declaração acima, a implementação deve usar um nó sentinela,
    // que representará as subárvores varias. Assim, por exemplo, os campos
    // "esq" e "dir" das folhas, ao invés de serem ponteiros nulos, apontarão
    // para "sent"; idem para o ponteiro "raiz", quando a árvore estiver vazia.
    // O campo "altura" da sentinela deve sempre valer zero.

    // --------------------------------------------------------------------------

    // Deve criar um dicionário vazio.

    DicioAVL() {
        // Inicializa o ponteiro raiz com o endereço do nó sentinela.
        raiz = &sent;
        // Inicializa o campo altura do nó sentinela com 0.
        sent.altura = 0;
    }

   // --------------------------------------------------------------------------

   // Deve desalocar a árvore AVL.

    ~DicioAVL() {
        deletar(raiz);
        raiz = nullptr;
    }

    // --------------------------------------------------------------------------

    // Deve inserir a chave "c" e o valor "v" no dicionário, partindo da
    // PRÉ-CONDIÇÃO de que a chave "c" não existe no dicionário -- ou seja,
    // a função não precisa nem deve fazer esse teste.
    //
    // A função deve retornar um ponteiro apontando para o novo nó.
    // Em caso de falha de alocação de memória, a função deve retornar nullptr.
    //
    // ATENÇÃO: a chave deve permanecer no mesmo nó enquanto não for removida
    // -------  do dicionário. Isso significa que, antes de tal remoção,
    //          deve ser possÃ­vel acessar a chave e seu valor a partir do
    //          ponteiro retornado pela função de inserção.

    // Retorna verdadeiro se vazio
    bool vazio(Noh *raiz) {
        return(raiz == &sent);
    }

    Noh* inserir(TC c, TV v) {
        Noh *novoNoh = new Noh{c, v, 1, &sent, &sent};
        raiz = inserirAux(raiz, novoNoh, c, v);
        return novoNoh;
    }

    Noh* inserirAux (Noh *raiz, Noh *novoNoh, TC c, TV v) {

        // 1. Se a raiz estiver vazia, então a raiz será o novo nó
        if(vazio(raiz)){
            return novoNoh;
        }
        
        // // 2. Se a raiz não estiver vazia, o novo nó será alocado na esquerda ou na direita
        // 2.1. Caso seja na esquerda
        if(c < raiz->chave){
            raiz->esq = inserirAux(raiz->esq, novoNoh, c, v);
        }
        // 2.2. Caso o novo elemento esteja à direita
        else if(c > raiz->chave) {
            raiz->dir = inserirAux(raiz->dir, novoNoh, c, v);
        } else{
            return raiz;
        }

        // Recalcular a altura de todos os nós afetados
        raiz->altura = max(raiz->esq->altura, raiz->dir->altura) + 1;

        // Checa se a árvore está balanceada
        raiz = balancear(raiz);

        // Retorna a raiz, igual ou modificada
        return raiz;
    }

    // --------------------------------------------------------------------------

    // Deve retornar um ponteiro para o nó de chave "c", caso essa chave exista
    // no dicionário; caso a chave não esteja presente, deve retornar nullptr.

    Noh* buscar (TC c) {

        // Ponteiro para percorrer a árvore
        Noh* temp = raiz;  

        while (temp != &sent) {
            if (temp->chave == c) {
                // A chave foi encontrada, retorna o nó
                return temp;
            } else if (c < temp->chave) {
                // A chave pode estar na subárvore esquerda
                temp = temp->esq;
            } else {
                // A chave pode estar na subárvore direita
                temp = temp->dir;
            }
        }
        // A chave não foi encontrada na árvore
        return nullptr;
    }

    // FUNÇÕES AUXILIARES E SECUNDÁRIAS

    // Calcular a altura
    // int calcularAltura(Noh *Noh) {
    //     if(vazio(Noh))
    //         return -1;

    //     // Calculo da altura recursivo
    //     int alturaEsquerda = calcularAltura(Noh->esq);
    //     int alturaDireita = calcularAltura(Noh->dir);
    //     if(alturaEsquerda > alturaDireita)
    //         return alturaEsquerda + 1;
    //     else
    //         return alturaDireita + 1;
    // }

    // Calculo do fator de balanceamento, que deve estar entre {-1, 0, 1}
    int fatorDeBalanceamento(Noh *Noh) {
        if(Noh == nullptr)
            return -1;
        else 
            return(Noh->esq->altura - Noh->dir->altura);
    }

    int max(int a, int b) {
        return (a > b)? a : b;
    }

    // Equilibra a árvore
    Noh* balancear(Noh *raiz){

        int fator = fatorDeBalanceamento(raiz); 
        // Se o favor é menor que -1, estão é um desbalanceamento à direita
        // Se o favor é menor que 1, estão é um desbalanceamento à esquerda

        // DESEQUILÍBRIO ESQUERDA-ESQUERDA
        if(fator > 1 and fatorDeBalanceamento(raiz->esq) >= 0) // i.e nós estamos colocando na esquerda da esquerda
            return rotacaoDireita(raiz);

        // DESEQUILÍBRIO DIREITA-DIREITA
        if(fator < -1 and fatorDeBalanceamento(raiz->dir) <= 0) // i.e nós estamos colocando na direita da direita
            return rotacaoEsquerda(raiz);
            
        // DESEQUILÍBRIO ESQUERDA-DIREITA
        if(fator > 1 and fatorDeBalanceamento(raiz->esq) < 0) {// i.e nós estamos colocando na direita da esquerda
            raiz->esq = rotacaoEsquerda(raiz->esq);
            return rotacaoDireita(raiz);
        }

        // DESEQUILÍBRIO DIREITA-ESQUERDA
        if(fator < -1 and fatorDeBalanceamento(raiz->dir) > 0) { // i.e nós estamos colocando na esquerda da direita
            raiz->dir = rotacaoDireita(raiz->dir);
            return rotacaoEsquerda(raiz);
        }

        return raiz;
    }    

    // Rotação à esquerda
    Noh * rotacaoEsquerda(Noh *A) {
        //          A                                   B
        //     Ax        B              =>         A          C
        //           Bx     C                  Ax    Bx   Cx      Cy
        //              Cx     Cy

        Noh *B = A->dir;
        Noh *Bx = B->esq;

        A->dir = Bx;
        B->esq = A;

        A->altura = max(A->esq->altura, A->dir->altura) + 1;
        B->altura = max(B->esq->altura, B->dir->altura) + 1;

        return B;
    }

    // Rotação à direita
    Noh * rotacaoDireita(Noh *A) {
        //                 A                                       B  
        //          B             Ay              =>        C               A
        //      C      By                               Cx     Cy      By       Ay
        //   Cx     Cy             

        Noh *B = A->esq;
        Noh *By = B->dir;

        A->esq = By;
        B->dir = A;

        A->altura = max(A->esq->altura, A->dir->altura) + 1;
        B->altura = max(B->esq->altura, B->dir->altura) + 1;

        return B;
    }

    // // Imprimir a árvore (aux)
    // void imprimirAux(Noh* raiz, int espaco) {
    //     // Caso básico
    //     if (vazio(raiz))
    //         return;

    //     // Aumentando a distância 
    //     espaco += CONT;

    //     // Primeiro imprimir os nós da direita
    //     imprimirAux(raiz->dir, espaco);

    //     // Imprimir o nó atual após o espaco
    //     cout << endl;
    //     for (int i = CONT; i < espaco; i++)
    //         cout << " ";
    //     cout << raiz->chave << "[" << raiz->valor << "]" <<  "\n";

    //     // Imprimir nó da esquerda
    //     imprimirAux(raiz->esq, espaco);
    // }

    // // Imprimir a árvore -> Principal
    // void imprimir() {
    //     // Inicialmente, o espaco é 0
    //     imprimirAux(this->raiz, 0);
    // }

    void deletar(Noh *raiz) {
        if(raiz == &sent) {
            return;
        }

        // Deletar recursivamente
        deletar(raiz->esq);
        deletar(raiz->dir);

        delete raiz;
    }

}; 

// int main () {
//     DicioAVL D; 
//     int i;
//     DicioAVL::Noh* nohs[9];

//     for (i = 0; i <= 8; ++i) {
//         DicioAVL::Noh* n = D.inserir(i, i/4);

//         if (n == nullptr)
        
//         if (n->chave != i) 
//             cout << "1.2. FALHOU " << endl;
        
//         if (n->valor != i/4)
//             cout << "1.3. FALHOU " << endl;

//         nohs[i] = n;
//         cout << i << ":" << n->chave << "[" << n->valor << "]" << endl;

//     }

//     D.imprimir();

//     for (i = 0; i <= 8; ++i) {
//         if (D.buscar(i) != nohs[i]);
//             cout << "2. FALHOU" << endl;
//     }

//     cout << D.buscar(0) << endl;
//     cout << D.raiz->esq->esq << endl;
//     cout << nohs[0] << endl;

//     if (D.raiz->chave != 3)
//         cout << "3.1 FALHOU" << endl;
    
//     if(D.raiz->esq->valor != 1/4)
//         cout << "3.2 FALHOU" << endl;
    
//     if(D.raiz->dir->altura != 3)
//         cout << "3.3 FALHOU" << endl;
    
//     if(D.raiz->esq->esq->esq != &D.sent)
//         cout << "3.4 FALHOU" << endl;

// }

// DicioAVL  --------------------------------------------------------------

