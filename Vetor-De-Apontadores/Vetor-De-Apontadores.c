#include <stdio.h>
#include <stdlib.h>
#include "Vetor-De-Apontadores.h"
#define M 5

struct arvNaria
{
    int quantidade;
    char info;
    struct arvNaria *filhos[M];
};
typedef struct arvNaria ArvNaria;

ArvNaria *inicArvNaria(void) //cria e retorna uma arvNaria vazia
{
    return NULL;
} //Pos: inicArvnaria == arvore vazia

ArvNaria *criaArvNaria(char c) //cria e retorna uma arvNaria(folha)com a raiz igual � TipoAN
{
    ArvNaria *a = (ArvNaria*)malloc(sizeof(ArvNaria));
    a->quantidade = 0;
    a->info = c;
    int aux;
    for(aux=M; aux >=0; aux--)
        a->filhos[aux] = "None"; //preenchendo cada posi��o do vetor filho como None para melhor visualiza��o
    a->filhos[M -1] = '\0'; //�ltima posi��o do vetor filho recebe o \0
    return a;
} //Pos:criaArvNaria == ArvNaria a com raiz TipoAN

ArvNaria *subArvNaria(ArvNaria *a) //Retorna a lista de sub-�rvoresassociadas a arvNaria a
{
    if(!vazioArvNaria(a)) //Pre:ArvNaria a n�o � vazia
    {
        int i;
        for(i=0; a->filhos[i] != '\0'; i++)
        {
            if(a->filhos[i] == "None")
                printf("<None\n");
            else
                printf("<%c\n",a->filhos[i]);
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
        if(a->quantidade != M -1)
        {
            int aux;
            int pega = -1; //pega primeira posi��o livre
            for(aux=0; a->filhos[aux] != '\0'; aux++) //vetor filho incrementa at� �ltima posi��o
            {
                if(a->filhos[aux] == "None") //caso posi��o do vetor filho for None ele adicionar� nela
                {
                    pega = aux;
                    break;
                }
            }
            if(pega != -1)
            {
                a->filhos[pega] = sa->info;
                a->quantidade++;
            }
        }
        else
            printf("Arvore cheia\n\n");
    }
} //Pos: insereArvNaria == sa � a primeira sub�rvore de a

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa) //adiciona a �rvore sa como �ltima subarvore de a
{
    if(!vazioArvNaria(a) && !estaArvNaria(a,sa->info)) //Pre: a n�o � vazia e sa j� existe
    {
        if(a->quantidade != M -1)
        {
            int aux;
            int pega = -1; //pega ultima posi��o livre
            for(aux=M -1; aux>=0; aux--) //vetor filho decrementa at� primeira posi��o
            {
                if(a->filhos[aux] == "None") //caso posi��o do vetor filho for None ele adicionar� nela
                {
                    pega = aux;
                    break;
                }
            }
            if(pega != -1)
            {
                a->filhos[pega] = sa->info;
                a->quantidade++;
            }
        }
        else
            printf("Arvore cheia\n\n");
    }
} //Pos: adicionaArvNaria == sa � a �ltima sub�rvore de a

void elimSubArvNaria(ArvNaria *a, char c) //desassocia (mas n�o destr�i) a i-�sima subarvore de a
{
    if(!vazioArvNaria(a) && estaArvNaria(a, c)) //pre: a n�o � vazia e tem subavores
    {
        int aux;
        int pega = 0;
        for(aux = 0; a->filhos[aux] != '\0'; aux++)
        {
            if(a->filhos[aux] == c) //caso seja o elem
                pega = aux;
        }
        a->filhos[pega] = "None";
        a->quantidade--; //decrementa quantidade de filhos
    }
} //pos: elimSubArvNaria == a arvore a n�o tem mais associada a subarvore i

void destruirArvNaria(ArvNaria *a) //destr�ie a ArvNaria a, desalocando a mem�ria ocupada
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        int i;
        for(i=0; a->filhos[i] != '\0'; i++)
            a->filhos[i] = '\0';
        free(a);
    }
} //Pos: destruirArvNaria == toda mem�ria alocada por ArvNaria a � devolvida.

int estaArvNaria(ArvNaria *a, char c) //verifica se elem est� em ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        int i;
        for(i=0; a->filhos[i] != '\0'; i++)
        {
            if(a->filhos[i] == c) //caso elem esteja no vetor
                return 1;
        }
        return 0;
    }
} //pos: estaArvNaria == true se elem est� em a e false do contr�rio

void imprimeArvNaria(ArvNaria *a) //imprime as informa��es associadas aos n�s da ArvNaria a
{
    if(!vazioArvNaria(a)) //pre: a n�o � vazia
    {
        int i;
        printf("<%c\n",raizArvNaria(a)); //imprime raiz
        for(i=0; a->filhos[i] != '\0'; i++)
        {
            if(a->filhos[i] == "None")
                printf("<None\n");
            else
                printf("<%c\n",a->filhos[i]);
        }
    }
} //pos: Imprime == o campo da informa��o da ArvNaria a e suas subarvores s�o exibidos
