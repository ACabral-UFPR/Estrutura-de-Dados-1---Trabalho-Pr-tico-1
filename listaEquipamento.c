#include "listaEquipamento.h"

/* Inicializa a lista com no cabecalho */
void lc_inicializar2(ListaEquipamento *lista2){
    lista2->cabecalho = malloc(sizeof(No));
    if (lista2->cabecalho == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lista2->cabecalho->proximo = NULL;
    lista2->tamanho = 0;
}
int lc_esta_vazia2(const ListaEquipamento *lista2){
    return lista2->cabecalho->proximo == NULL;
}
void lc_ler_equipamento(Equipamento *e){
    printf("\n--- Cadastro de Equipamento ---\n");
    printf("Codigo do equipamento: ");
    scanf("%d", &e->CodeEquip);
    printf("Nome do equipamento: ");
    scanf(" %52[^\n]", e->NomeEquip);
    printf("Tipo do equipamento: ");
    scanf(" %52[^\n]", e->TipoEquip);
    printf("Descricao do equipamento: ");
    scanf(" %255[^\n]", e->DescEquip);
}
/* Inserir no inicio */
void lc_inserir_inicio2(ListaEquipamento *lista2){
    No *novo = malloc(sizeof(No));
    if (novo == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lc_ler_equipamento(&novo->equipamento);
    novo->proximo = lista2->cabecalho->proximo;
    lista2->cabecalho->proximo = novo;
    lista2->tamanho++;
}
/* Inserir no fim */
void lc_inserir_fim2(ListaEquipamento *lista2){
    No *novo = malloc(sizeof(No));
    if (novo == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lc_ler_equipamento(&novo->equipamento);
    novo->proximo = NULL;
    No *atual = lista2->cabecalho;
    while (atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    lista2->tamanho++;
}
/* Inserir em posicao. Indice inicia em zero */
int lc_inserir_posicao2(ListaEquipamento *lista2, int posicao){
    if (posicao < 0 || posicao > lista2->tamanho){
        return 0;
    }
    No *anterior = lista2->cabecalho;
    for (int i = 0; i < posicao; i++){
        anterior = anterior->proximo;
    }
    No *novo = malloc(sizeof(No));
    if (novo == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lc_ler_equipamento(&novo->equipamento);
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
    lista2->tamanho++;
    return 1;
}
/* Remove pela posicao */
int lc_remover_posicao2(ListaEquipamento *lista2, int posicao){
    if (posicao < 0 || posicao >= lista2->tamanho){
        return 0;
    }
    No *anterior = lista2->cabecalho;
    for (int i = 0; i < posicao; i++){
        anterior = anterior->proximo;
    }
    No *remover = anterior->proximo;
    anterior->proximo = remover->proximo;
    free(remover);
    lista2->tamanho--;
    return 1;
}
/* Buscar pelo nome do equipamento */
int lc_buscar2(const ListaEquipamento *lista2,
               const char *equipamento){
    No *atual = lista2->cabecalho->proximo;
    int posicao = 0;
    while (atual != NULL){
        if (strcmp(atual->equipamento.NomeEquip, equipamento) == 0){
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}
/* Imprime todos os equipamentos */
void lc_imprimir2(const ListaEquipamento *lista2){
    No *atual = lista2->cabecalho->proximo;
    int posicao = 0;
    printf("\n===== LISTA DE EQUIPAMENTOS =====\n");
    if (atual == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while (atual != NULL){
        Equipamento e = atual->equipamento;
        printf("\nEquipamento N-%d\n", posicao);
        printf("Codigo: %d\n", e.CodeEquip);
        printf("Tipo: %s\n", e.TipoEquip);
        printf("Nome: %s\n", e.NomeEquip);
        printf("Descricao: %s\n", e.DescEquip);
        atual = atual->proximo;
        posicao++;
    }
    printf("\nTotal de equipamentos: %d\n", lista2->tamanho);
}
/* Libera todos os nos, inclusive o cabecalho */
void lc_destruir2(ListaEquipamento *lista2){
    No *atual = lista2->cabecalho;
    while (atual != NULL){
        No *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista2->cabecalho = NULL;
    lista2->tamanho = 0;
}