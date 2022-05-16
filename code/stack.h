#ifndef STACK_H
#define STACK_H

typedef struct stack STACK;
/**
 * @brief estrutura que serve para identificar (e enumerar) os varios tipos existentes.
 * 
 */
typedef enum {
    LONG, 
    DOUBLE, 
    CHAR,
    STRING,
    ARRAY,
    BLOCK
} VARTYPE;

/**
 * @brief Definição e conversão de tipos.
 * 
 */
typedef struct {
    VARTYPE type;
    union {
        long typeLong;
        double typeDouble;
        char typeChar; 
        char *typeString; 
        STACK *typeArray;
    } info;
} ELEMENT;

/**
* @brief Definição da Stack
*/
typedef struct stack {
    ELEMENT stack[BUFSIZ];
    int sp;
} STACK;

/**
 * @brief Utilização da Dispatch em conjunção com a Stack
 * 
 */
typedef void (*DispatchFunc) (STACK*);

/**
 * @brief Utilização da Dispatch em conjunção com a Stack envonvendo os difrentes tipos. 
 * 
 */
typedef void (*DispatchType) (STACK*, ELEMENT, ELEMENT);

/**
 * @brief A Dispatch table.
 * 
 *  Esta função criada terá o propósito de tornar a escolha
 * da operação o mais eficiente possivel.
 * 
 * @param table funcao que consta na tabela.
 * 
 */
void setupTable(DispatchFunc table[]);

/**
 * @brief func é uma função que nos permite ler varias linhas
 * 
 * @param x pointer da Stack.
 * @param c character lido.
 * @param table funcao que consta na tabela.
 * @param f um inteiro de teste.
 * @return int 
 */
int func(STACK *x, char* c, DispatchFunc table[], int f);

/**
 * @brief readType vai ler os nossos tipos diferentes tipos.
 * 
 *  readType vai, após ser lida a linha, identificar os diferentes tipos e associar ao que é lido.
 * 
 * @param s pointer da Stack.
 * @param h character lido.
 */
void readType (STACK* s, char *h);

/**
* @brief Utilização da Stack 
*/
STACK *newStack();

/**
 * @brief Função de push.
 * 
 *  A função "push" "empurra" um elemento para o fundo da stack.
 * 
 * @param s pointer da Stack.
 * @param elem elemento.
 * @return int 
 */
int push(STACK *s, ELEMENT elem);

/**
 * @brief Função de pop
 * 
 *  A função "pop" retira o elemento no topo da stack e devolve/guarda o seu valor.
 * 
 * @param s pointer da Stack. 
 * @param x pointer para um Elemento.
 * @return int
 */
int pop(STACK *s, ELEMENT* x);

/**
 * @brief newArray é a função que cria um Array.
 * 
 * @param s pointer da Stack. 
 * @param f "bool".
 */
void newArray (STACK* s, int f);

/**
 * @brief size é uma função que define o tamanho de um array, ou o range de um certo valor.
 * 
 * @param s pointer da Stack. 
 */
void size(STACK* s);

/**
 * @brief addToArray, uma função que adiciona algum valor a um array 
 * 
 * @param s pointer da Stack. 
 * @param h character lido.
 * @param f "bool".
 */
void addToArray(STACK* s, char h[], int f);

/**
 * @brief printArray é a função que nos mostra o Array no terminal.
 * 
 * @param s pointer da Stack. 
 * @param n "bool". 
 */
void printArray(STACK* s, int n);

/**
 * @brief newString, uma função que cria uma nova string.
 * 
 * @param s pointer da Stack. 
 * @param h character lido.
 * @param f "bool".
 */
void newString (STACK* s, char h[], int f);

/**
 * @brief newBlock, uma função que cria um Bloco.
 * 
 * @param s pointer da Stack. 
 * @param h character lido. 
 * @param f "bool".
 */
void newBlock(STACK *s, char h[], int f);

/**
 * @brief pushArray é uma função que dá push de um array qualquer para a Stack.
 * 
 * @param s pointer da Stack. 
 */
void pushArray(STACK *s);


/**
 * @brief Função da soma
 * 
 *  A função "soma" dá a adição de dois números.
 * 
 * @param s pointer da Stack. 
 */
void soma (STACK *s);

/**
 * @brief somaLongLong é a função que soma dois longs.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaLongLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaLongDouble é a função que soma um Long com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento. 
 * @param y elemento.
 */
void somaLongDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaLongChar é a função que soma um Long com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaLongChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaDoubleDouble é a função que soma um Double com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaDoubleLong é a função que soma um Double com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaDoubleLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaDoubleChar é a função que soma um Double com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaDoubleChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaCharChar é a função que soma dois Chares.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaCharChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaCharDouble é a função que soma um Char com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento. 
 * @param y elemento.
 */
void somaCharDouble(STACK *s, ELEMENT x, ELEMENT y);
/**
 * @brief somaCharLong é a função que soma um Char com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaCharLong (STACK *s, ELEMENT x, ELEMENT y);


/**
 * @brief somaElemArray é a função que concatena um Elemento a um Array.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaElemArray(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaArrayElem é a função que concatena um Array a um Elemento.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaArrayElem(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaArrayArray é a função que concatena Arrays.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaArrayArray(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaElemString é a função que concatena um Elemento a uma String.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaElemString(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaStringElem é a função que concatena uma String a um Elemento.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaStringElem(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief somaStringString é a função que concatena duas Strings.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void somaStringString(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de subtração
 * 
 *  A função "subtracao" dá a subtração de dois números.
 * 
 * @param s pointer da Stack.
 */
void subtracao(STACK *s);

/**
 * @brief subtracaoLongLong é a função que subtrai dois Longs. 
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */

void subtracaoLongLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoLongDouble é a função que subtrai um Long com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoLongDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoLongChar é a função que subtrai um Long com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoLongChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoDoubleDouble é a função que subtrai dois Doubles.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoDoubleLong é a função que subtrai um Double com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoDoubleChar é a função que subtrai um Double com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoCharChar é a função que subtrai um Char com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoCharChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoCharDouble é a função que subtrai um Char com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoCharDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief subtracaoCharLong é a função que subtrai um Char com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void subtracaoCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de multiplicação
 * 
 *  A função "multiplicacao" dá o produto entre dois números.
 * 
 * @param s pointer da Stack. 
 */

void multiplicacao(STACK *s);

/**
 * @brief multiplicacaoLongLong é a função que multiplica dois Longs.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoLongLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoLongDouble é a função que multiplica um Long com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoLongDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoLongChar é a função que multiplica um Long com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoLongChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoDoubleDouble é a função que multiplica dois Doubles.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoDoubleLong é a função que multiplica um Double com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoDoubleChar é a função que multiplica um Double com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoCharChar é a função que multiplica dois Chares.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoCharChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoCharDouble é a função que multiplica um Char com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoCharDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoCharLong é a função que multiplica um Char com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief multiplicacaoblockArray é a função que aplica um ciclo for de uma operação em Bloco a um Array.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void multiplicacaoBlockArray(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de divisão
 * 
 * A função "divisao" dá o quociente entre dois números.
 * 
 * @param s pointer da Stack. 
 */
void divisao(STACK *s);

/**
 * @brief divisaoLongLong é a função que divide dois Longs.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoLongLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoLongDouble é a função que divide um Long com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoLongDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoLongChar é a função que divide um Long com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoLongChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoDoubleDouble é a função que divide dois Doubles.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoDoubleLong é a função que divide um Double com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoDoubleChar é a função que divide um Double com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoCharChar é a função que divide dois Chares.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoCharChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoCharDouble é a função que divide um Char com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoCharDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief divisaoCharLong é a função que divide um Char com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void divisaoCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de exponenciação
 * 
 *  A função "exponenciacao" dá a exponencial de um valor.
 * 
 * @param s pointer da Stack. 
 */
void exponenciacao(STACK *s);

/**
 * @brief expLongLong é a função que dá a exponencial de um Long com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expLongLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expLongDouble é a função que dá a exponencial de um Long com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expLongDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expLongChar é a função que dá a exponencial de um Long com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expLongChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expDoubleDouble é a função que dá a exponencial de um Double com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expDoubleLong é a função que dá a exponencial de um Double com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expDoubleLong(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expDoubleChar é a função que dá a exponencial de um Double com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expDoubleChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expCharChar é a função que dá a exponencial de um Char com um Char.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expCharChar(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expCharDouble é a função que dá a exponencial de um Char com um Double.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expCharDouble(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief expCharLong é a função que dá a exponencial de um Char com um Long.
 * 
 * @param s pointer da Stack. 
 * @param x elemento.
 * @param y elemento.
 */
void expCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de decrementação
 *
 *  A função "decrementacao" decrementa um número em um valor. 
 * 
 * @param s pointer da Stack. 
 */

void decrementacao(STACK *s);

/**
 * @brief Função de incrementação
 * 
 * A função "incrementacao" incrementa um número em um valor.
 * 
 * @param s pointer da Stack. 
 */

void incrementacao(STACK *s);

/**
 * @brief Função do modulo
 * 
 *  A função "modulo" dá o resto da divisão inteira entre dois números.
 * 
 * @param s pointer da Stack. 
 */

void modulo(STACK *s);

/**
 * @brief Função lógica "e" - conjunção
 * 
 *  A função "eBitwise" vai aplicar o modelo lógico de conjunção entre dois valores.
 * 
 * @param s pointer da Stack. 
 */

void eBitwise(STACK *s);

/**
 * @brief Função lógica "ou" - disjunção 
 * 
 *  A função "ouBitwise" aplica o modelo lógico da disjunção entre dois valores.
 * 
 * @param s pointer da Stack. 
 */
void ouBitwise(STACK *s);

/**
 * @brief Função lógica "xor" - disjunção exclusiva 
 * 
 *  A função "xorBitwise" vai aplicar o modelo lógico exclusivo entre dois valores,
 * ou seja, só um deles terá que ser verdadeiro (logicamente) para ser aplicável.
 * 
 * @param s pointer da Stack. 
 */
void xorBitwise(STACK *s);

/**
 * @brief Função lógica "not" - negação
 * 
 *  A função "notBitwise" vai aplicar o modelo lógico da negação a qualquer valor.
 * 
 * @param s pointer da Stack. 
 */
void notBitwise(STACK *s);

/**
 * @brief Função de duplicação
 * 
 *  A função "duplicacao" duplica o valor do 1º elemento.
 * 
 * @param s pointer da Stack.
 */
void duplicacao(STACK *s);

/**
 * @brief Função de troca
 * 
 *  A função "troca" troca os dois elementos no topo da stack.
 * 
 * @param s pointer da Stack.
 */
void troca(STACK *s);

/**
 * @brief Função de rodagem
 * 
 *  A função "roda" roda os três elementos no topo da stack.
 * 
 * @param s pointer da Stack.
 */
void roda(STACK *s);

/**
 * @brief Função auxiliar para a função "copia"
 * 
 *  A função "nesimo" 
 *  
 * @param s pointer da Stack.
 * @param x elemento.
 * @param n inteiro para decrescimo.
 */
void nesimo (STACK *s, ELEMENT* x, long n);

/**
 * @brief Função de cópia
 * 
 * A função "copia" copia o n-ésimo elemento para o topo da stack.
 * 
 * @param s pointer da Stack.
 */
void copia(STACK *s);

/**
 * @brief Função de pop (sem devolução de valor)
 *  
 * A função "pop2" retira o elemento do topo da stack sem guardar o seu valor, contrariamente à "pop" que retira o elemento e guarda o seu valor.
 * 
 * @param s pointer da Stack.
 */
void pop2(STACK *s);

/**
 * @brief Função convtoLong
 * 
 * A função converte um valor para Long
 * 
 * @param s pointer da Stack. 
 */
void convToLong(STACK *s);

/**
 * @brief Função convToDouble
 * 
 * A função converte um valor para Double
 * 
 * @param s pointer da Stack. 
 */
void convToDouble(STACK *s);

/**
 * @brief Função convToChar
 * 
 * A função converte um valor para Char
 * 
 * @param s pointer da Stack. 
 */
void convToChar(STACK *s);

/**
 * @brief Função convToString
 * 
 * A função converte um valor para String
 * 
 * @param s pointer da Stack. 
 */
void convToString(STACK *s);

/**
 * @brief  assign é a função (:) que atribui um valor a uma letra qualquer de A a z.
 * 
 * @param s pointer da Stack.s 
 * @param c character.
 * @param var array que agrega elementos.
 * @param f "bool".
 */
void assign(STACK *s,char c,ELEMENT var[], int f);

/**
 * @brief setupVar serve para identificar as variáveis pré-defenidas de A até z.
 * 
 * @param var array que agrega elementos.
 */
void setupVar(ELEMENT var[]); 

/**
 * @brief Função Igual
 * 
 * A função compara ambos os valores e returna 0 caso sejam diferentes e != 0 caso sejam iguais 
 * 
 * @param s pointer da Stack. 
 */
void igual(STACK *s);

/**
 * @brief Função menor
 * 
 * A função compara ambos os valores e returna 0 caso o segundo seja menor do que o primeiro
 * 
 * @param s pointer da Stack. 
 */
void menor (STACK *s);

/**
 * @brief Função maior
 * 
 * A função compara ambos os valores e returna 0 caso o segundo seja maior do que o primeiro
 * 
 * @param s pointer da Stack. 
 */
void maior (STACK *s);

/**
 * @brief  A Função nao é essencialmente uma função que retorna o valor inverso do seu valor booleano atual.
 * 
 * @param s pointer da Stack. 
 */
void nao (STACK *s);

/**
 * @brief Função de conjunção lógica com shortcut (e&).
 * 
 * Caso o primeiro elemento seja falso (0), já não verifica o segundo e dá, portanto, o primeiro. 
 * Caso contrário, dá o segundo.
 * 
 * @param s pointer da Stack. 
 */
void eShortcut (STACK *s);

/**
 * @brief Função de disjunção lógica com shortcut (e|)
 * 
 * Caso o primeiro valor seja verdadeiro (diferente de 0), já não verifica o segundo e dá, portanto, o primeiro. 
 * Caso contrário, dá o segundo.
 * 
 * @param s pointer da Stack. 
 */
void ouShortcut (STACK *s);

/**
 * @brief Função que coloca o menor de dois valores na stack (e<).
 * 
 * Esta função avalia dois valores com difrentes tipos e coloca na stack o menor de ambos.
 * 
 * @param s pointer da Stack. 
 */
void menorDoisValores (STACK *s);

/**
 * @brief Função que coloca o maior de dois valores na stack (e>).
 * 
 * Esta função avalia dois valores com difrentes tipos e coloca na stack o maior de ambos
 * 
 * @param s pointer da Stack. 
 */
void maiorDoisValores (STACK *s); 

/**
 * @brief Função if-then-else (se-então-de_outra_forma) (?) que, caso o primeiro elemento seja verdade (if), devolve o segundo (then). Caso contrário, dá o terceiro (else).
 * 
 * @param s pointer da Stack. 
 */
void ifThenElse (STACK *s);

/**
 * @brief Setup Array para a Soma
 * 
 * O proposito deste setup é conseguir identificar as diferentes opções da soma para cada tipo respetivo.
 * 
 * @param funcType 
 */
void setupSumArray(DispatchType funcType[6][6]);

/**
 * @brief Setup Array para a Subtração
 * 
 * O proposito deste setup é conseguir identificar as diferentes opções da subtração para cada tipo respetivo.
 * 
 * @param funcType 
 */
void setupSubArray(DispatchType funcType[4][4]);

/**
 * @brief Setup Array para a Multiplicação
 * 
 * O proposito deste setup é conseguir identificar as diferentes opções da multiplicação para cada tipo respetivo.
 * 
 * @param funcType 
 */
void setupMulArray(DispatchType funcType[6][6]);

/**
 * @brief Setup Array para a Divisão
 * 
 * O proposito deste setup é conseguir identificar as diferentes opções da divisão para cada tipo respetivo.
 *
 * @param funcType 
 */
void setupDivArray(DispatchType funcType[4][4]);

/**
 * @brief Setup Array para a Exponenciação
 * 
 * O proposito deste setup é conseguir identificar as diferentes opções de exponenciação para cada tipo respetivo.
 *
 * @param funcType 
 */
void setupExpArray(DispatchType funcType[4][4]);

/**
 * @brief readline function
 * 
 * Lê uma linha
 * 
 * @param s pointer da Stack. 
 */
void readline(STACK *s);

/**
 * @brief psdebugger é a nossa forma de "dar o debug" ao nosso projeto. 
 * 
 * psdebugger só tem a função de representar no terminal os tipos que estamos a trabalhar, para facilmente 
 * identificarmos qualquer problema.
 * 
 * @param s pointer da Stack. 
 */
void psdebugger(STACK *s);

/**
 * @brief funcT é uma função que nos premite utilizar a função func
 * 
 * @param s pointer da Stack. 
 */
void funcT(STACK *s); 

#endif 