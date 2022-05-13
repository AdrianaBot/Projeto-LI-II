#ifndef STACK_H
#define STACK_H

typedef struct stack STACK;

typedef enum {
    LONG, 
    DOUBLE, 
    CHAR,
    STRING,
    ARRAY
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


typedef void (*DispatchFunc) (STACK*);

typedef void (*DispatchType) (STACK*, ELEMENT, ELEMENT);

void setupTable(DispatchFunc table[]);

int func(STACK *x, char* c, DispatchFunc table[], int f);

 
/**
* @brief Utilização da Stack 
*/

STACK *newStack();
/**
 * @brief Função de push.
 * 
 * A função "push" "empurra" um elemento para o fundo da stack.
 * 
 * @param s 
 * @param elem 
 * @return int 
 */

int push(STACK *s, ELEMENT elem);

/**
 * @brief Função de pop
 * 
 * A função "pop" retira o elemento no topo da stack e devolve/guarda o seu valor.
 * 
 * @param s 
 * @param x 
 * @return int
 */

int pop(STACK *s, ELEMENT* x);

void newArray (STACK* s, int f);

void size(STACK* s);

void addToArray(STACK* s, char h[], int f);

void printArray(STACK* s, int n);

void newString (STACK* s, char h[], int f);

void pushArray(STACK *s);


/**
 * @brief Função da soma
 * 
 * A função "soma" dá a adição de dois números.
 * 
 * @param s 
 */

void soma (STACK *s);
void somaLongLong(STACK *s, ELEMENT x, ELEMENT y);
void somaLongDouble(STACK *s, ELEMENT x, ELEMENT y);
void somaLongChar(STACK *s, ELEMENT x, ELEMENT y);
void somaDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);
void somaDoubleLong(STACK *s, ELEMENT x, ELEMENT y);
void somaDoubleChar(STACK *s, ELEMENT x, ELEMENT y);
void somaCharChar(STACK *s, ELEMENT x, ELEMENT y);
void somaCharDouble(STACK *s, ELEMENT x, ELEMENT y);
void somaCharLong (STACK *s, ELEMENT x, ELEMENT y);
void somaElemArray(STACK *s, ELEMENT x, ELEMENT y);
void somaArrayElem(STACK *s, ELEMENT x, ELEMENT y);
void somaArrayArray(STACK *s, ELEMENT x, ELEMENT y);
void somaElemString(STACK *s, ELEMENT x, ELEMENT y);
void somaStringElem(STACK *s, ELEMENT x, ELEMENT y);
void somaStringString(STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de subtração
 * 
 * A função "subtracao" dá a subtração de dois números.
 * 
 * @param s
 */

void subtracao(STACK *s);
void subtracaoLongLong(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoLongDouble(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoLongChar(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoCharChar(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoCharDouble(STACK *s, ELEMENT x, ELEMENT y);
void subtracaoCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de multiplicação
 * 
 * A função "multiplicacao" dá o produto entre dois números.
 * 
 * @param s 
 */

void multiplicacao(STACK *s);
void multiplicacaoLongLong(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoLongDouble(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoLongChar(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoCharChar(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoCharDouble(STACK *s, ELEMENT x, ELEMENT y);
void multiplicacaoCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de divisão
 * 
 * A função "divisao" dá o quociente entre dois números.
 * 
 * @param s 
 */
void divisao(STACK *s);
void divisaoLongLong(STACK *s, ELEMENT x, ELEMENT y);
void divisaoLongDouble(STACK *s, ELEMENT x, ELEMENT y);
void divisaoLongChar(STACK *s, ELEMENT x, ELEMENT y);
void divisaoDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);
void divisaoDoubleLong(STACK *s, ELEMENT x, ELEMENT y);
void divisaoDoubleChar(STACK *s, ELEMENT x, ELEMENT y);
void divisaoCharChar(STACK *s, ELEMENT x, ELEMENT y);
void divisaoCharDouble(STACK *s, ELEMENT x, ELEMENT y);
void divisaoCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de exponenciação
 * 
 * A função "exponenciacao" dá a exponencial de um valor.
 * 
 * @param s 
 */
void exponenciacao(STACK *s);
void expLongLong(STACK *s, ELEMENT x, ELEMENT y);
void expLongDouble(STACK *s, ELEMENT x, ELEMENT y);
void expLongChar(STACK *s, ELEMENT x, ELEMENT y);
void expDoubleDouble(STACK *s, ELEMENT x, ELEMENT y);
void expDoubleLong(STACK *s, ELEMENT x, ELEMENT y);
void expDoubleChar(STACK *s, ELEMENT x, ELEMENT y);
void expCharChar(STACK *s, ELEMENT x, ELEMENT y);
void expCharDouble(STACK *s, ELEMENT x, ELEMENT y);
void expCharLong (STACK *s, ELEMENT x, ELEMENT y);

/**
 * @brief Função de decrementação
 *
 * A função "decrementacao" decrementa um número em um valor. 
 * 
 * @param s 
 */

void decrementacao(STACK *s);

/**
 * @brief Função de incrementação
 * 
 * A função "incrementacao" incrementa um número em um valor.
 * 
 * @param s 
 */

void incrementacao(STACK *s);

/**
 * @brief Função do modulo
 * 
 * A função "modulo" dá o resto da divisão inteira entre dois números.
 * 
 * @param s 
 */

void modulo(STACK *s);

/**
 * @brief Função lógica "e" - conjunção
 * 
 * A função "eBitwise" vai aplicar o modelo lógico de conjunção entre dois valores.
 * 
 * @param s 
 */

void eBitwise(STACK *s);

/**
 * @brief Função lógica "ou" - disjunção 
 * 
 * A função "ouBitwise" aplica o modelo lógico da disjunção entre dois valores.
 * 
 * @param s 
 */
void ouBitwise(STACK *s);

/**
 * @brief Função lógica "xor" - disjunção exclusiva 
 * 
 * A função "xorBitwise" vai aplicar o modelo lógico exclusivo entre dois valores,
 * ou seja, só um deles terá que ser verdadeiro (logicamente) para ser aplicável.
 * 
 * @param s 
 */
void xorBitwise(STACK *s);

/**
 * @brief Função lógica "not" - negação
 * 
 * A função "notBitwise" vai aplicar o modelo lógico da negação a qualquer valor.
 * 
 * @param s 
 */
void notBitwise(STACK *s);

/**
 * @brief Função de duplicação
 * 
 * A função "duplicacao" duplica o valor do 1º elemento.
 * 
 * @param s
 */
void duplicacao(STACK *s);

/**
 * @brief Função de troca
 * 
 * A função "troca" troca os dois elementos no topo da stack.
 * 
 * @param s
 */
void troca(STACK *s);

/**
 * @brief Função de rodagem
 * 
 * A função "roda" roda os três elementos no topo da stack.
 * 
 * @param s
 */
void roda(STACK *s);

/**
 * @brief Função auxiliar para a função "copia"
 * 
 * A função "nesimo" 
 */
void nesimo (STACK *s, ELEMENT* x, long n);


/**
 * @brief Função de cópia
 * 
 * A função "copia" copia o n-ésimo elemento para o topo da stack.
 * 
 * @param s
 */
void copia(STACK *s);

/**
 * @brief Função de pop (sem devolução de valor)
 *  
 * A função "pop2" retira o elemento do topo da stack sem guardar o seu valor, contrariamente à "pop" que retira o elemento e guarda o seu valor.
 * 
 * @param s
 */
void pop2(STACK *s);


/**
 * @brief Função convtoLong
 * 
 * A função converte um valor para Long
 * 
 * @param s 
 */
void convToLong(STACK *s);

/**
 * @brief Função convToDouble
 * 
 * A função converte um valor para Double
 * 
 * @param s 
 */
void convToDouble(STACK *s);

/**
 * @brief Função convToChar
 * 
 * A função converte um valor para Char
 * 
 * @param s 
 */
void convToChar(STACK *s);



/**
 * @brief Função convToString
 * 
 * A função converte um valor para String
 * 
 * @param s 
 */
void convToString(STACK *s);

void assign(STACK *s,char c,ELEMENT var[], int f);

void setupVar(ELEMENT var[]); 

/**
 * @brief Função Igual
 * 
 * A função compara ambos os valores e returna 0 caso sejam diferentes e != 0 caso sejam iguais 
 * 
 * @param s 
 */
void igual(STACK *s);


/**
 * @brief Função menor
 * 
 * A função compara ambos os valores e returna 0 caso o segundo seja menor do que o primeiro
 * 
 * @param s 
 */
void menor (STACK *s);

/**
 * @brief Função maior
 * 
 * A função compara ambos os valores e returna 0 caso o segundo seja maior do que o primeiro
 * 
 * @param s 
 */
void maior (STACK *s);

void nao (STACK *s);

void eShortcut (STACK *s);

void ouShortcut (STACK *s);

void menorDoisValores (STACK *s);

void maiorDoisValores (STACK *s); 

void ifThenElse (STACK *s);

void setupSumArray(DispatchType funcType[6][6]);

void setupSubArray(DispatchType funcType[4][4]);

void setupMulArray(DispatchType funcType[6][6]);

void setupDivArray(DispatchType funcType[4][4]);

void setupExpArray(DispatchType funcType[4][4]);

void readline(STACK *s);

void psd(STACK *s);

void funcT(STACK *s);


#endif 