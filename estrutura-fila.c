#include <stdio.h>
#include <stdlib.h>

struct fila{
    int capacidade;
    int *dados;
    int nElem;
    int primeiro;
    int ultimo;
};

void inicia_fila(struct fila *f, int tam){
    f->capacidade = tam;
    f->dados=(int*)malloc(f->capacidade*sizeof(int));
    f->primeiro=0;
    f->ultimo=-1;
    f->nElem=0;
}
void insere (struct fila *f, int val){
    if(f->ultimo==f->capacidade-1)
        f->ultimo=-1;
    f->ultimo++;
    f->dados[f->ultimo]=val;
    f->nElem++;
}
int remover(struct fila *f){
    int temp=f->dados[f->primeiro++];
    if(f->primeiro==f->capacidade){
        f->primeiro=0;
    }
    f->nElem--;
    return temp;
}
void mostraFila(struct fila *f){
    int cont, i;
    for (cont = 0, i = f->primeiro;cont<f->nElem;cont++){
        printf ("[%d]", f->dados[i++]);
        if(i==f->capacidade)
            i = 0;
    }
}
int fVazia(struct fila *f){

    return (f->nElem == 0);
}
int fCheia (struct fila *f){

    return (f->nElem==f->capacidade);
}

int main()
{
    struct fila f;
    int valor, tam, opcao;

    printf("qual é o tamanho maximo da fila?\n");
    scanf("%d", &tam);
    inicia_fila(&f, tam);
    while (1){
        printf("\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nOpcao? ");
		scanf("%d", &opcao);
		switch(opcao){
        case 0:
            exit(0);
            break;
        case 1:
            if (fCheia(&f)){
                printf("\nERRO!! FILA CHEIA");
                return -1;
            }
            else{
                printf("\nValor para inserir? ");
                scanf("%d", &valor);
                insere(&f, valor);
            }
            break;
        case 2:
             if (fVazia(&f))
                printf("\nFila vazia!");
            else{
                int temp;
                temp=remover(&f);
                printf("\nValor removido = %d", temp);
            }
        case 3:
            if (fVazia(&f))
                printf("\nFila vazia!");
            else{
                printf("\nFila => ");
                mostraFila(&f);
            }
            break;
        default:
            printf("\nOpcão inválida! Digite novamente\n");
		}
    }
    return 0;
}