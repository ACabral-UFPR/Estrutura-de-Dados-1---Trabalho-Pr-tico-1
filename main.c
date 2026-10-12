#include "listaEquipamento.h"
#include "listaReserva.h"

int main(void){
    ListaEquipamento lista2;
    ListaReserva lista1;
    int opcao, posicao, codigo;
    char equipamento[53];
    lc_inicializar2(&lista2);
    lc_inicializar1(&lista1);
    do{
        printf("\n===== MENU DE EQUIPAMENTOS =====\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no fim\n");
        printf("3 - Inserir em uma posicao\n");
        printf("4 - Imprimir equipamentos\n");
        printf("5 - Buscar equipamento\n");
        printf("6 - Remover por posicao\n");
        printf("7 - Seguir para reservas\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        if(scanf("%d", &opcao) != 1){
            printf("Entrada invalida.\n");
            break;
        }
        switch(opcao){
            case 1:
                lc_inserir_inicio2(&lista2);
                break;
            case 2:
                lc_inserir_fim2(&lista2);
                break;
            case 3:
                printf("Posicao (comeca em 0): ");
                if(scanf("%d", &posicao) != 1){
                    printf("Entrada invalida.\n");
                    goto encerrar;
                }
                if(!lc_inserir_posicao2(&lista2, posicao)){
                    printf("Posicao invalida.\n");
                }
                break;
            case 4:
                lc_imprimir2(&lista2);
                break;
            case 5:
                printf("Nome do equipamento: ");
                scanf(" %52[^\n]", equipamento);
                posicao = lc_buscar2(&lista2, equipamento);
                if(posicao >= 0){
                    printf("Equipamento encontrado na posicao %d.\n", posicao);
                }else{
                    printf("Equipamento nao encontrado.\n");
                }
                break;
            case 6:
                printf("Posicao para remover: ");
                if(scanf("%d", &posicao) != 1){
                    printf("Entrada invalida.\n");
                    goto encerrar;
                }
                if(lc_remover_posicao2(&lista2, posicao)){
                    printf("Equipamento removido.\n");
                }else{
                    printf("Posicao invalida.\n");
                }
                break;
            case 7:{
                int sairReservas = 0;
                printf("Seguindo para reservas.\n");
                do{
                    printf("\n===== MENU DE RESERVAS =====\n");
                    printf("1 - Inserir no inicio\n");
                    printf("2 - Inserir no fim\n");
                    printf("3 - Inserir em uma posicao\n");
                    printf("4 - Imprimir reservas\n");
                    printf("5 - Buscar reserva por codigo\n");
                    printf("6 - Remover por posicao\n");
                    printf("0 - Voltar ao menu de equipamentos\n");
                    printf("Opcao: ");
                    if(scanf("%d", &opcao) != 1){
                        printf("Entrada invalida.\n");
                        sairReservas = 1;
                        break;
                    }
                    switch(opcao){
                        case 1:
                            lc_inserir_inicio1(&lista1);
                            break;
                        case 2:
                            lc_inserir_fim1(&lista1);
                            break;
                        case 3:
                            printf("Posicao (comeca em 0): ");
                            if(scanf("%d", &posicao) != 1){
                                printf("Entrada invalida.\n");
                                sairReservas = 1;
                                break;
                            }
                            if (!lc_inserir_posicao1(&lista1, posicao)){
                                printf("Posicao invalida.\n");
                            }
                            break;
                        case 4:
                            lc_imprimir1(&lista1);
                            break;
                        case 5:
                            printf("Codigo do equipamento: ");
                            if(scanf("%d", &codigo) != 1){
                                printf("Entrada invalida.\n");
                                sairReservas = 1;
                                break;
                            }
                            posicao = lc_buscar1(&lista1, codigo);
                            if(posicao >= 0) {
                                printf("Reserva encontrada na posicao %d.\n",
                                       posicao);
                            }else{
                                printf("Reserva nao encontrada.\n");
                            }
                            break;
                        case 6:
                            printf("Posicao para remover: ");
                            if (scanf("%d", &posicao) != 1){
                                printf("Entrada invalida.\n");
                                sairReservas = 1;
                                break;
                            }
                            if (lc_remover_posicao1(&lista1, posicao)){
                                printf("Reserva removida.\n");
                            } else{
                                printf("Posicao invalida.\n");
                            }
                            break;
                        case 0:
                            sairReservas = 1;
                            break;
                        default:
                            printf("Opcao invalida.\n");
                    }
                } while(!sairReservas);
                break;
            }
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }while(opcao != 0);
encerrar:
    lc_destruir1(&lista1);
    lc_destruir2(&lista2);
    return 0;
}