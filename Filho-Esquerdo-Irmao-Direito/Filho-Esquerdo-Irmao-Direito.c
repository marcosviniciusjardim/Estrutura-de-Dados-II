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

ArvNaria *criaArvNaria(char c) //cria e retorna uma arvNaria(folha)com a raiz igual � TipoAN
{
    ArvNaria *a = (ArvNaria*)malloc(sizeof(ArvNaria));
    a->info = c;
    a->filho = NULL;
    a->irmao = NULL;
    return a;
} //Pos:criaArvNaria == ArvNaria a com raiz TipoAN

ArvNaria *subArvNaria(ArvNaria *a) //Retorna a lista de sub-�rvoresassociadas a arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a n�o � vazia
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
        sa->irmao = a->filho;
        a->filho = sa;
    }
} //Pos: insereArvNaria == sa � a primeira sub�rvore de a

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a �rvore sa como �ltima subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //Pre: a n�o � vazia e sa j� existe
    {
        if(a->filho == NULL) //caso a �rvore esteja vazia
        {
            insereArvNaria(a,sa);
        }
        else
        {
            ArvNaria *pega = sa; //recebe a sub�rvore de a
            ArvNaria *ant; //recebe a �ltima posi��o da �rvore
            ArvNaria *p;
            for(p=a->filho; p!=NULL; p=p->irmao)
                ant = p;
            ant->irmao = pega;
        }
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
        else if(ant == NULL && pega->irmao != NULL) //caso seja o primeiro n� da arvore
        {
            free(pega);
            a->filho = prox;
        }
        else if(ant != NULL && pega->irmao == NULL) //caso seja o �ltimo n� da arvore
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
} //pos: elimSubArvNaria == a arvore a n�o tem mais associada a subarvore i

void destruirArvNaria(ArvNaria *a) //destr�ie a ArvNaria a, desalocando a mem�ria ocupada
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        ArvNaria *p = a->filho; //recebe o filho de a
        while(p != NULL)
        {
            ArvNaria *t = p->irmao; //t recebe o irm�o
            destruirArvNaria(p);
            p = t;
        }
        free(a); //libera a
    }
} //Pos: destruirArvNaria == toda mem�ria alocada por ArvNaria a � devolvida.

int estaArvNaria(ArvNaria *a, char c) //verifica se elem est� em ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        ArvNaria *p;
        if(a->info == c) //caso o elem esteja na raiz
            return 1;
        else
        {
            for(p=a->filho; p!=NULL; p=p->irmao)
            {
                if(estaArvNaria(p, c)) //caso elem esteja no filho ou nos irm�os
                    return 1;
            }
        }
        return 0;
    }
} //pos: estaArvNaria == true se elem est� em a e false do contr�rio

void imprimeArvNaria(ArvNaria *a) //imprime as informa��es associadas aos n�s da ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        ArvNaria *p;
        printf("<%c\n",raizArvNaria(a)); //imprime raiz
        for(p=a->filho; p!=NULL; p=p->irmao)
            imprimeArvNaria(p); //imprime filho depois seus irm�os
        printf(">");
    }
} //pos: Imprime == o campo da informa��o da ArvNaria a e suas subarvores s�o exibidos
