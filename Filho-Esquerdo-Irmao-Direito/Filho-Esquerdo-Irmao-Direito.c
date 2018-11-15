#include <stdio.h>
#include <stdlib.h>
#include "Filho-Esquerdo-Irmao-Direito.h"

struct arvNaria
{
    char info;
    struct arvNaria *filho;
    struct arvNaria *irmao;
};
typedef struct arvNaria ArvNaria;

ArvNaria *inicArvNaria(void) //cria e retorna uma arvNaria vazia
{
    return NULL;
} //Pos: inicArvnaria == arvore vazia

ArvNaria *criaArvNaria(char c) //cria e retorna uma arvNaria(folha)com a raiz igual à TipoAN
{
    ArvNaria *a = (ArvNaria*)malloc(sizeof(ArvNaria));
    a->info = c;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
} //Pos:criaArvNaria == ArvNaria a com raiz TipoAN

ArvNaria *subArvNaria(ArvNaria *a) //Retorna a lista de sub-árvoresassociadas a arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a não é vazia
    {
        ArvNaria *p = a->filho; //recebe o filho de a
        while(p != NULL)
        {
            printf("<%c\n",p->info);
            p = p->irmao;
        }
    }
} //Pos:subArvNaria== lista das sub-arvores de a

char raizArvNaria(ArvNaria *a) //Retorna a raiz da arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a não é vazia
        return a->info;
} //Pos: raizArvNaria == o elemento da raiz

int vazioArvNaria(ArvNaria *a) //informa se a árvore é vazia
{
    return (a == NULL);
} //pos: vazioArvNaria == true se a for vazio do contrário false.

void insereArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a árvore sa como primeira subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //pre: a não é vazia e sa já existe
    {
        sa->irmao = a->filho;
        a->filho = sa;
    }
} //Pos: insereArvNaria == sa é a primeira subárvore de a

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a árvore sa como última subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //Pre: a não é vazia e sa já existe
    {
        if(a->filho == NULL) //caso a árvore esteja vazia
        {
            insereArvNaria(a,sa);
        }
        else
        {
            ArvNaria *pega = sa; //recebe a subárvore de a
            ArvNaria *ant; //recebe a última posição da árvore
            ArvNaria *p;
            for(p=a->filho; p!=NULL; p=p->irmao)
                ant = p;
            ant->irmao = pega;
        }
    }
} //Pos: adicionaArvNaria == sa é a última subárvore de a

void elimSubArvNaria(ArvNaria *a, char c) //desassocia (mas não destrói) a i-ésima subarvore de a
{
    if(!vazioArvNaria(a) && estaArvNaria(a,c)) //pre: a não é vazia e tem subavores
    {
        ArvNaria *ant = NULL; //posição anterior ao elem procurado
        ArvNaria *prox; //próxima posição ao elem procurado
        ArvNaria *pega; //posição do elem procurado
        ArvNaria *p;
        for(p=a->filho; p!=NULL; p=p->irmao)
        {
            if(p->info == c) //caso seja o elem
            {
                pega = p;
                break;
            }
            ant = p;
        }
        prox = pega->irmao;
        if(ant == NULL && prox == NULL) //caso a arvore tenha somente o filho
        {
            free(pega);
            a->filho = NULL;
        }
        else if(ant == NULL && pega->irmao != NULL) //caso seja o primeiro nó da arvore
        {
            free(pega);
            a->filho = prox;
        }
        else if(ant != NULL && pega->irmao == NULL) //caso seja o último nó da arvore
        {
            free(pega);
            ant->irmao = NULL;
        }
        else
        {
            free(pega);
            ant->irmao = prox;
            prox->irmao = NULL;
        }
    }
} //pos: elimSubArvNaria == a arvore a não tem mais associada a subarvore i

void destruirArvNaria(ArvNaria *a) //destróie a ArvNaria a, desalocando a memória ocupada
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        ArvNaria *p = a->filho; //recebe o filho de a
        while(p != NULL)
        {
            ArvNaria *t = p->irmao; //t recebe o irmão
            destruirArvNaria(p);
            p = t;
        }
        free(a); //libera a
    }
} //Pos: destruirArvNaria == toda memória alocada por ArvNaria a é devolvida.

int estaArvNaria(ArvNaria *a, char c) //verifica se elem está em ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        ArvNaria *p;
        if(a->info == c) //caso o elem esteja na raiz
            return 1;
        else
        {
            for(p=a->filho; p!=NULL; p=p->irmao)
            {
                if(estaArvNaria(p, c)) //caso elem esteja no filho ou nos irmãos
                    return 1;
            }
        }
        return 0;
    }
} //pos: estaArvNaria == true se elem está em a e false do contrário

void imprimeArvNaria(ArvNaria *a) //imprime as informações associadas aos nós da ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        ArvNaria *p;
        printf("<%c\n",raizArvNaria(a)); //imprime raiz
        for(p=a->filho; p!=NULL; p=p->irmao)
            imprimeArvNaria(p); //imprime filho depois seus irmãos
        printf(">");
    }
} //pos: Imprime == o campo da informação da ArvNaria a e suas subarvores são exibidos
