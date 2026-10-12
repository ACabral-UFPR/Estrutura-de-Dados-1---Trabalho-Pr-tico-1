#ifndef TAREFALISTA_LISTAEQUIPAMENTO_H
#define TAREFALISTA_LISTAEQUIPAMENTO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Equipamento {
    int CodeEquip;
    char TipoEquip[53];
    char NomeEquip[53];
    char DescEquip[256];
} Equipamento;

typedef struct No {
    Equipamento equipamento;
    struct No *proximo;
} No;

typedef struct ListaEquipamento {
    No *cabecalho;
    int tamanho;
} ListaEquipamento;

void lc_inicializar2(ListaEquipamento *lista2);
int lc_esta_vazia2(const ListaEquipamento *lista2);
void lc_ler_equipamento(Equipamento *e);
void lc_inserir_inicio2(ListaEquipamento *lista2);
void lc_inserir_fim2(ListaEquipamento *lista2);
int lc_inserir_posicao2(ListaEquipamento *lista2, int posicao);
int lc_remover_posicao2(ListaEquipamento *lista2, int posicao);
int lc_buscar2(const ListaEquipamento *lista2, const char *equipamento);
void lc_imprimir2(const ListaEquipamento *lista2);
void lc_destruir2(ListaEquipamento *lista2);

#endif