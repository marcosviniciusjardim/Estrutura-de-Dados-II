typedef struct lista Lista;

typedef struct arvNaria ArvNaria;

ArvNaria *inicArvnaria(void);

ArvNaria *criaArvNaria(char c);

ArvNaria *subArvNaria(ArvNaria *a);

ArvNaria *raizArvNaria(ArvNaria *a);

int vazioArvNaria(ArvNaria *a);

void insereArvNaria(ArvNaria *a, ArvNaria *sa);

void adicionaArvNaria(ArvNaria *a, ArvNaria *sa);

void elimSubArvNaria(ArvNaria *a, char c);

void destruirArvNaria(ArvNaria *a);

int estaArvNaria(ArvNaria *a, char c);

void imprimeArvNaria(ArvNaria *a);
