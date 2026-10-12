#ifndef TAREFALISTA_LISTARESERVA_H
#define TAREFALISTA_LISTARESERVA_H

#include "listaEquipamento.h"

typedef struct Reserva {
    int CodeEquip;
    char usuario[53];
    int Data;
    int Horario;
}Reserva;

typedef struct NoReserva{
    Reserva reserva;
    struct NoReserva *proximo;
}NoReserva;

typedef struct ListaReserva{
    NoReserva *cabecalho;
    int tamanho;
}ListaReserva;

void lc_inicializar1(ListaReserva *lista1);
int lc_esta_vazia1(const ListaReserva *lista1);
void lc_ler_reserva(Reserva *r);
void lc_inserir_inicio1(ListaReserva *lista1);
void lc_inserir_fim1(ListaReserva *lista1);
int lc_inserir_posicao1(ListaReserva *lista1, int posicao);
int lc_remover_posicao1(ListaReserva *lista1, int posicao);
int lc_buscar1(const ListaReserva *lista1, int codigo);
void lc_imprimir1(const ListaReserva *lista1);
void lc_destruir1(ListaReserva *lista1);

#endif