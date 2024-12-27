#include <stdlib.h>
#include<stdio.h>
#include <locale.h>
    
struct fila{
    int *dados;
    int nElem;
    int capacidade;
    int ultimo;
    int primeiro;
};
void inicia_fila( struct fila *f, int tam){
    f-> capacidade=tam;
    f->dados=(int*)malloc(f->capacidade * sizeof (int));
    f->nElem=0;
    f->ultimo=-1;
    f->primeiro=0;
}

void insere (struct fila *f, int val){
    if (f->ultimo==f->capacidade-1)
        f->ultimo=-1;
    f->ultimo+=1;
    f->dados[f->ultimo]=val;
    f->nElem+=1;
}
int verifica_vazia (struct fila *f) {
    return(f->nElem==0);
};
int verifica_cheia (struct fila *f){
    return (f->nElem==f->capacidade);
}
int remover (struct fila *f){
    int temp;
    temp = f->dados[f->primeiro];
    f->primeiro+=1;
    f->nElem-=1;
    return temp;
}
void mostrar (struct fila *f){
    int cont, i;
    printf("\nFILA ============>");
    for (cont = 0, i = f->primeiro; cont<f->nElem;cont++){
        printf("[%d]", f->dados[i++]);
        if (i==f->capacidade)
            i=0;
    }
}
int main(){
    setlocale(LC_ALL,"Portuguese");
    int tam, valor, opcao;
    struct fila f;
    printf("\n\nDigite o tamanho da fila: ");
    scanf ("%d", &tam);
    inicia_fila(&f,tam);
    while (1){
        wprintf(L"\n\n1 - Inserir elemento\n2 - Remover elemento\n3 - Mostrar Fila\n0 - Sair\n\nDigite a opção desejada: ");
        scanf ("%d", &opcao);
        switch (opcao)
        {
        case 1:
            if(verifica_cheia(&f))
                printf("\nFILA CHEIA!!");
            else {
                printf("\nDigite o valor para inserir na fila: ");
                scanf("%d", &valor);
                insere(&f, valor);
                mostrar(&f);
            }
            break;
        case 2:
            if(verifica_vazia(&f))
                printf("\nFILA VAZIA!!");
            else{
                printf("Valor removido: %d\nFILA ATUALIZADA=====> ", remover(&f));
                mostrar(&f);
            }
            break;
        case 3:
            if(verifica_vazia(&f))
                printf("\nFILA VAZIA!!");
            else
                mostrar(&f);
            break;
        case 0:
            exit(0);
        default:
            wprintf(L"Opção inválida!\n");
            break;
        }
    }
    return 0;
}