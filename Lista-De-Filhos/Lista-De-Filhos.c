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

ArvNaria *criaArvNaria(char c) //cria e retorna uma arvNaria(folha)com a raiz igual � TipoAN
{
    ArvNaria *a = (ArvNaria*)malloc(sizeof(ArvNaria));
    a->info = c;
    a->filhos = NULL;
    return a;
} //Pos:criaArvNaria == ArvNaria a com raiz TipoAN

ArvNaria *subArvNaria(ArvNaria *a) //Retorna a lista de sub-�rvoresassociadas a arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a n�o � vazia
    {
        Lista *p;
        for(p=a->filhos; p!=NULL; p=p->prox)
            printf("<%c\n",p->info);
    }
} //Pos:subArvNaria== lista das sub-arvores de a

ArvNaria *raizArvNaria(ArvNaria *a) //Retorna a raiz da arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a n�o � vazia
        return a->info;
} //Pos: raizArvNaria == o elemento da raiz

int vazioArvNaria(ArvNaria *a) //informa se a �rvore � vazia
{
    return (a == NULL);
} //pos: vazioArvNaria == true se a for vazio do contr�rio false.

void insereArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a �rvore sa como primeira subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //pre: a n�o � vazia e sa j� existe
    {
        Lista *l = (Lista*)malloc(sizeof(Lista));
        l->info = sa->info;
        l->prox = a->filhos;
        a->filhos = l;
        return l;
    }
} //Pos: insereArvNaria == sa � a primeira sub�rvore de a

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a �rvore sa como �ltima subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //Pre: a n�o � vazia e sa j� existe
    {
        Lista *l = (Lista*)malloc(sizeof(Lista));
        if(a->filhos == NULL)
        {
            insereArvNaria(a,sa);
        }
        else
        {
            ArvNaria *pega = sa; //recebe a sub�rvore de a
            ArvNaria *ant; //recebe a �ltima posi��o da �rvore
            ArvNaria *p;
            for(p=a->filhos; p!=NULL; p=p->filhos)
                ant = p;
            ant->filhos = pega;
        }
        return l;
    }
} //Pos: adicionaArvNaria == sa � a �ltima sub�rvore de a

void elimSubArvNaria(ArvNaria *a, char c) //desassocia (mas n�o destr�i) a i-�sima subarvore de a
{
    if(!vazioArvNaria(a) && estaArvNaria(a,c)) //pre: a n�o � vazia e tem subavores
    {
        ArvNaria *ant = NULL; //posi��o anterior ao elem procurado
        ArvNaria *prox; //pr�xima posi��o ao elem procurado
        ArvNaria *pega; //posi��o do elem procurado
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
        else if(ant == NULL && pega->filhos != NULL) //caso seja o primeiro n� da arvore
        {
            free(pega);
            a->filhos = prox;
        }
        else if(ant != NULL && pega->filhos == NULL) //caso seja o �ltimo n� da arvore
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
} //pos: elimSubArvNaria == a arvore a n�o tem mais associada a subarvore i

void destruirArvNaria(ArvNaria *a) //destr�ie a ArvNaria a, desalocando a mem�ria ocupada
{
    if(!vazioArvNaria(a))
    {
        Lista *p = a->filhos; //recebe o filho de a
        while(p != NULL)
        {
            Lista *t = p->prox; //t recebe o pr�ximo filho
            free(p);
            p = t;
        }
    }
} //Pos: destruirArvNaria == toda mem�ria alocada por ArvNaria a � devolvida.

int estaArvNaria(ArvNaria *a, char c) //verifica se elem est� em ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        Lista *p;
        for(p=a->filhos; p!=NULL; p=p->prox)
        {
            if(p->info == c) //caso elem esteja nos filhos
                return 1;
        }
        return 0;
    }
} //pos: estaArvNaria == true se elem est� em a e false do contr�rio

void imprimeArvNaria(ArvNaria *a) //imprime as informa��es associadas aos n�s da ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        Lista *p;
        printf("<%c\n",raizArvNaria(a)); //imprime raiz
        for(p=a->filhos; p!=NULL; p=p->prox)
            printf("<%c\n",p->info); //imprime filhos
    }
} //pos: Imprime == o campo da informa��o da ArvNaria a e suas subarvores s�o exibidos
