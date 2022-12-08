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


struct DicioAVL
  {
   typedef double TC;  // Tipo das Chaves
   typedef float  TV;  // Tipo dos Valores

   struct Noh {  TC chave;  TV valor;  int altura;  Noh *esq, *dir;  };

   Noh sent, *raiz;  // "sent": Sentinela.

   // Conforme a declaração acima, a implementação deve usar um nó sentinela,
   // que representará as subárvores varias. Assim, por exemplo, os campos
   // "esq" e "dir" das folhas, ao invés de serem ponteiros nulos, apontarão
   // para "sent"; idem para o ponteiro "raiz", quando a árvore estiver vazia.
   // O campo "altura" da sentinela deve sempre valer zero.

   // --------------------------------------------------------------------------

   // Deve criar um dicionário vazio.

   DicioAVL ()
     {
      // TODO: Completar aqui.
     }

   // --------------------------------------------------------------------------

   // Deve desalocar a árvore AVL.

   ~DicioAVL ()
     {
      // TODO: Completar aqui.
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

   Noh* inserir (TC c, TV v)
     {
      // TODO: Completar aqui.

      // Fazer recursivamente
     }

   // --------------------------------------------------------------------------

   // Deve retornar um ponteiro para o nó de chave "c", caso essa chave exista
   // no dicionário; caso a chave não esteja presente, deve retornar nullptr.

   Noh* buscar (TC c)
     {
      // TODO: Completar aqui.
     }

  }; // DicioAVL  --------------------------------------------------------------