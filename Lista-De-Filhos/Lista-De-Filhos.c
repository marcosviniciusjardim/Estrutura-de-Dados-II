#include <stdio.h>
#include <stdlib.h>
#include "Lista-De-Filhos.h"

struct lista
{
    char info;
    struct lista *prox;
};
typedef struct lista Lista;

struct arvNaria
{
    char info;
    Lista *filhos;
};
typedef struct arvNaria ArvNaria;


ArvNaria *inicArvnaria(void) //cria e retorna uma arvNaria vazia
{
    return NULL;
} //Pos: inicArvnaria == arvore vazia

ArvNaria *criaArvNaria(char c) //cria e retorna uma arvNaria(folha)com a raiz igual à TipoAN
{
    ArvNaria *a = (ArvNaria*)malloc(sizeof(ArvNaria));
    a->info = c;
    a->filhos = NULL;
    return a;
} //Pos:criaArvNaria == ArvNaria a com raiz TipoAN

ArvNaria *subArvNaria(ArvNaria *a) //Retorna a lista de sub-árvoresassociadas a arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a não é vazia
    {
        Lista *p;
        for(p=a->filhos; p!=NULL; p=p->prox)
            printf("<%c\n",p->info);
    }
} //Pos:subArvNaria== lista das sub-arvores de a

ArvNaria *raizArvNaria(ArvNaria *a) //Retorna a raiz da arvNaria a
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
        Lista *l = (Lista*)malloc(sizeof(Lista));
        l->info = sa->info;
        l->prox = a->filhos;
        a->filhos = l;
        return l;
    }
} //Pos: insereArvNaria == sa é a primeira subárvore de a

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a árvore sa como última subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //Pre: a não é vazia e sa já existe
    {
        Lista *l = (Lista*)malloc(sizeof(Lista));
        if(a->filhos == NULL)
        {
            insereArvNaria(a,sa);
        }
        else
        {
            ArvNaria *pega = sa; //recebe a subárvore de a
            ArvNaria *ant; //recebe a última posição da árvore
            ArvNaria *p;
            for(p=a->filhos; p!=NULL; p=p->filhos)
                ant = p;
            ant->filhos = pega;
        }
        return l;
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
        for(p=a->filhos; p!=NULL; p=p->filhos)
        {
            if(p->info == c)  //caso seja o elem
            {
                pega = p;
                break;
            }
            ant = p;
        }
        prox = pega->filhos;
        if(ant == NULL && prox == NULL) //caso a arvore tenha somente o filho
        {
            free(pega);
            a->filhos = NULL;
        }
        else if(ant == NULL && pega->filhos != NULL) //caso seja o primeiro nó da arvore
        {
            free(pega);
            a->filhos = prox;
        }
        else if(ant != NULL && pega->filhos == NULL) //caso seja o último nó da arvore
        {
            free(pega);
            ant->filhos = NULL;
        }
        else
        {
            free(pega);
            ant->filhos = prox;
            prox->filhos = NULL;
        }
    }
} //pos: elimSubArvNaria == a arvore a não tem mais associada a subarvore i

void destruirArvNaria(ArvNaria *a) //destróie a ArvNaria a, desalocando a memória ocupada
{
    if(!vazioArvNaria(a))
    {
        Lista *p = a->filhos; //recebe o filho de a
        while(p != NULL)
        {
            Lista *t = p->prox; //t recebe o próximo filho
            free(p);
            p = t;
        }
    }
} //Pos: destruirArvNaria == toda memória alocada por ArvNaria a é devolvida.

int estaArvNaria(ArvNaria *a, char c) //verifica se elem está em ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        Lista *p;
        for(p=a->filhos; p!=NULL; p=p->prox)
        {
            if(p->info == c) //caso elem esteja nos filhos
                return 1;
        }
        return 0;
    }
} //pos: estaArvNaria == true se elem está em a e false do contrário

void imprimeArvNaria(ArvNaria *a) //imprime as informações associadas aos nós da ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a não é vazia
    {
        Lista *p;
        printf("<%c\n",raizArvNaria(a)); //imprime raiz
        for(p=a->filhos; p!=NULL; p=p->prox)
            printf("<%c\n",p->info); //imprime filhos
    }
} //pos: Imprime == o campo da informação da ArvNaria a e suas subarvores são exibidos
