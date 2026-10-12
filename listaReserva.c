#include "listaReserva.h"

/* Inicializa a lista com no cabecalho */
void lc_inicializar1(ListaReserva *lista1){
    lista1->cabecalho = malloc(sizeof(NoReserva));
    if (lista1->cabecalho == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lista1->cabecalho->proximo = NULL;
    lista1->tamanho = 0;
}
int lc_esta_vazia1(const ListaReserva *lista1){
    return lista1->cabecalho->proximo == NULL;
}
void lc_ler_reserva(Reserva *r){
    time_t horaAtual;
    struct tm *dataHora;
    printf("\n--- Cadastro de Reserva ---\n");
    printf("Codigo do equipamento: ");
    scanf("%d", &r->CodeEquip);
    printf("Usuario: ");
    scanf(" %52[^\n]", r->usuario);
    /* Obter data e hora atuais */
    horaAtual = time(NULL);
    dataHora = localtime(&horaAtual);
    if (dataHora == NULL){fprintf(stderr, "Erro: nao foi possivel obter data e hora.\n");
        exit(1);
    }
    r->Data = dataHora->tm_mday * 1000000
            + (dataHora->tm_mon + 1) * 10000
            + (dataHora->tm_year + 1900);
    r->Horario = dataHora->tm_hour * 100 + dataHora->tm_min;
    printf("Data da reserva: %02d/%02d/%04d\n",
           dataHora->tm_mday,
           dataHora->tm_mon + 1,
           dataHora->tm_year + 1900);
    printf("Horario da reserva: %02d:%02d\n",
           dataHora->tm_hour,
           dataHora->tm_min);
}
/* Inserir no inicio */
void lc_inserir_inicio1(ListaReserva *lista1){
    NoReserva *novo = malloc(sizeof(NoReserva));
    if (novo == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lc_ler_reserva(&novo->reserva);
    novo->proximo = lista1->cabecalho->proximo;
    lista1->cabecalho->proximo = novo;
    lista1->tamanho++;
}
/* Inserir no fim */
void lc_inserir_fim1(ListaReserva *lista1){
    NoReserva *novo = malloc(sizeof(NoReserva));
    if (novo == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lc_ler_reserva(&novo->reserva);
    novo->proximo = NULL;
    NoReserva *atual = lista1->cabecalho;
    while (atual->proximo != NULL){
        atual = atual->proximo;
    }
    atual->proximo = novo;
    lista1->tamanho++;
}
/* Inserir em posicao. Indice inicia em zero */
int lc_inserir_posicao1(ListaReserva *lista1, int posicao){
    if (posicao < 0 || posicao > lista1->tamanho){
        return 0;
    }
    NoReserva *anterior = lista1->cabecalho;
    for (int i = 0; i < posicao; i++){
        anterior = anterior->proximo;
    }
    NoReserva *novo = malloc(sizeof(NoReserva));
    if (novo == NULL){
        fprintf(stderr, "Erro - sem memoria.\n");
        exit(1);
    }
    lc_ler_reserva(&novo->reserva);
    novo->proximo = anterior->proximo;
    anterior->proximo = novo;
    lista1->tamanho++;
    return 1;
}
/* Remove pela posicao */
int lc_remover_posicao1(ListaReserva *lista1, int posicao){
    if (posicao < 0 || posicao >= lista1->tamanho){
        return 0;
    }
    NoReserva *anterior = lista1->cabecalho;
    for (int i = 0; i < posicao; i++){
        anterior = anterior->proximo;
    }
    NoReserva *remover = anterior->proximo;
    anterior->proximo = remover->proximo;
    free(remover);
    lista1->tamanho--;
    return 1;
}
/* Buscar pelo codigo do equipamento */
int lc_buscar1(const ListaReserva *lista1, int codigo){
    NoReserva *atual = lista1->cabecalho->proximo;
    int posicao = 0;
    while (atual != NULL) {
        if (atual->reserva.CodeEquip == codigo){
            return posicao;
        }
        atual = atual->proximo;
        posicao++;
    }
    return -1;
}
/* Imprime todas as reservas */
void lc_imprimir1(const ListaReserva *lista1){
    NoReserva *atual = lista1->cabecalho->proximo;
    int posicao = 0;
    printf("\n===== LISTA DE RESERVAS =====\n");
    if (atual == NULL){
        printf("Lista vazia.\n");
        return;
    }
    while (atual != NULL){
        Reserva r = atual->reserva;
        printf("\nReserva %d\n", posicao);
        printf("Codigo do equipamento: %d\n", r.CodeEquip);
        printf("Data: %02d/%02d/%04d\n",
               r.Data / 1000000,
               (r.Data / 10000) % 100,
               r.Data % 10000);
        printf("Horario: %02d:%02d\n",
               r.Horario / 100,
               r.Horario % 100);
        printf("Usuario: %s\n", r.usuario);
        atual = atual->proximo;
        posicao++;
    }
    printf("\nTotal de reservas: %d\n", lista1->tamanho);
}
/* Libera todos os nos, inclusive o cabecalho */
void lc_destruir1(ListaReserva *lista1)
{
    NoReserva *atual = lista1->cabecalho;
    while(atual != NULL){
        NoReserva *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    lista1->cabecalho = NULL;
    lista1->tamanho = 0;
}
