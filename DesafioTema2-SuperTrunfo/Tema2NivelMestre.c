// TEMA 2 - Nível mestre
// Implementando Comparações Avançadas com Atributos Múltiplos no Super Trunfo

#include <stdio.h>
#include <string.h>

typedef struct {
    char estado[50];
    char codigo[4];
    char cidade[50];
    unsigned long populacao;
    float area;
    float pib;
    int pontosTur;
    float densidade;
    float pibPerCapita;
    float superpoder;
} Carta;

/* ---------- Utilidades ---------- */
static void limpaBufferAteQuebra(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}
}

static void calcularAtributos(Carta *c) {
    c->densidade   = (float)c->populacao / c->area;
    c->pibPerCapita= c->pib / (float)c->populacao;
    c->superpoder  = (float)c->populacao + c->area + c->pib + (float)c->pontosTur
                   + c->pibPerCapita + (1.0f / c->densidade);
}

static void imprimirCabecalhoCarta(int idx) {
    printf("\n==============================================================\n");
    printf("                 Carta cadastrada com sucesso!                  \n");
    printf("                           Carta %d:\n", idx);
    printf("\n==============================================================\n");
}

static void imprimirCarta(const Carta *c, int idx) {
    imprimirCabecalhoCarta(idx);
    printf("Estado: %s\n", c->estado);
    printf("Código: %s\n", c->codigo);
    printf("Nome da Cidade: %s\n", c->cidade);
    printf("População: %lu\n", c->populacao);
    printf("Área: %.2f km²\n", c->area);
    printf("PIB: %.2f\n", c->pib);
    printf("Número de Pontos Turísticos: %d\n", c->pontosTur);
    printf("Densidade populacional: %.2f hab/km²\n", c->densidade);
    printf("PIB per Capita: %.2f reais\n", c->pibPerCapita);
    printf("Super Poder: %.2f\n\n", c->superpoder);
}

static int compararRodada(
    int opcao,
    const Carta *c1, const Carta *c2,
    float *valorC1, float *valorC2
) {
    int resultado = 0;

    switch (opcao) {
        case 1:
            printf("Você escolheu a opção *População*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *População*: %lu\n", c1->cidade, c1->populacao);
            printf("Carta 2: %s, *População*: %lu\n", c2->cidade, c2->populacao);
            resultado = c1->populacao > c2->populacao ? 1 : 0;
            *valorC1 = (float)c1->populacao; *valorC2 = (float)c2->populacao;
            break;

        case 2:
            printf("Você escolheu a opção *Área*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *Área*: %.2f\n", c1->cidade, c1->area);
            printf("Carta 2: %s, *Área*: %.2f\n", c2->cidade, c2->area);
            resultado = c1->area > c2->area ? 1 : 0;
            *valorC1 = c1->area; *valorC2 = c2->area;
            break;

        case 3:
            printf("Você escolheu a opção *PIB*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *PIB*: %.2f\n", c1->cidade, c1->pib);
            printf("Carta 2: %s, *PIB*: %.2f\n", c2->cidade, c2->pib);
            resultado = c1->pib > c2->pib ? 1 : 0;
            *valorC1 = c1->pib; *valorC2 = c2->pib;
            break;

        case 4:
            printf("Você escolheu a opção *Número de pontos turísticos*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *Número de pontos turísticos*: %d\n", c1->cidade, c1->pontosTur);
            printf("Carta 2: %s, *Número de pontos turísticos*: %d\n", c2->cidade, c2->pontosTur);
            resultado = c1->pontosTur > c2->pontosTur ? 1 : 0;
            *valorC1 = (float)c1->pontosTur; *valorC2 = (float)c2->pontosTur;
            break;

        case 5:
            printf("Você escolheu a opção *Densidade populacional*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *Densidade populacional*: %.2f\n", c1->cidade, c1->densidade);
            printf("Carta 2: %s, *Densidade populacional*: %.2f\n", c2->cidade, c2->densidade);
            resultado = c1->densidade < c2->densidade ? 1 : 0;
            *valorC1 = c1->densidade; *valorC2 = c2->densidade;
            break;

        case 6:
            printf("Você escolheu a opção *PIB per Capita*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *PIB per Capita*: %.2f\n", c1->cidade, c1->pibPerCapita);
            printf("Carta 2: %s, *PIB per Capita*: %.2f\n", c2->cidade, c2->pibPerCapita);
            resultado = c1->pibPerCapita > c2->pibPerCapita ? 1 : 0;
            *valorC1 = c1->pibPerCapita; *valorC2 = c2->pibPerCapita;
            break;

        case 7:
            printf("Você escolheu a opção *Super Poder*, vamos ao duelo de comparações desta rodada!\n");
            printf("Carta 1: %s, *Super Poder*: %.2f\n", c1->cidade, c1->superpoder);
            printf("Carta 2: %s, *Super Poder*: %.2f\n", c2->cidade, c2->superpoder);
            resultado = c1->superpoder > c2->superpoder ? 1 : 0;
            *valorC1 = c1->superpoder; *valorC2 = c2->superpoder;
            break;

        default:
            printf("Opção inválida.");
            *valorC1 = *valorC2 = 0.0f;
            resultado = 0;
            break;
    }

    return resultado;
}

/* ---------- Fluxo principal ---------- */
int main(void) {
    Carta c1 = {0}, c2 = {0};
    int rodada1 = 0, rodada2 = 0, resultado1 = 0, resultado2 = 0;
    float v1r1 = 0.0f, v2r1 = 0.0f, v1r2 = 0.0f, v2r2 = 0.0f;

    /* Cadastro Carta 1 */
    printf("Cadastre a Carta 1:\n");
    printf("Digite o Estado:");                scanf("%49s", c1.estado);
    printf("Digite o código da carta:");       scanf("%3s",  c1.codigo);
    printf("Digite o nome da cidade:");        limpaBufferAteQuebra(); fgets(c1.cidade, sizeof c1.cidade, stdin); c1.cidade[strcspn(c1.cidade, "\n")] = '\0';
    printf("Digite a população:");             scanf("%lu", &c1.populacao);
    printf("Digite a área (km²):");            scanf("%f",  &c1.area);
    printf("Digite o PIB:");                   scanf("%f",  &c1.pib);
    printf("Digite o número de pontos turísticos:"); scanf("%d", &c1.pontosTur);

    calcularAtributos(&c1);

    /* Exibe Carta 1 */
    imprimirCabecalhoCarta(1);
    printf("Estado: %s\n", c1.estado);
    printf("Código: %s\n", c1.codigo);
    printf("Nome da Cidade: %s\n", c1.cidade);
    printf("População: %lu\n", c1.populacao);
    printf("Área: %.2f km²\n", c1.area);
    printf("PIB: %.2f\n", c1.pib);
    printf("Número de Pontos Turísticos: %d\n", c1.pontosTur);
    printf("Densidade populacional: %.2f hab/km²\n", c1.densidade);
    printf("PIB per Capita: %.2f reais\n", c1.pibPerCapita);
    printf("Super Poder: %.2f\n\n", c1.superpoder);

    printf("-----------------------------------------------------\n");
    printf("-----------------------------------------------------\n");

    /* Cadastro Carta 2 */
    printf("Cadastre a Carta 2:\n");
    printf("Digite o Estado:");                scanf("%49s", c2.estado);
    printf("Digite o código da carta:");       scanf("%3s",  c2.codigo);
    printf("Digite o nome da cidade:");        limpaBufferAteQuebra(); fgets(c2.cidade, sizeof c2.cidade, stdin); c2.cidade[strcspn(c2.cidade, "\n")] = '\0';
    printf("Digite a população:");             scanf("%lu", &c2.populacao);
    printf("Digite a área (km²):");            scanf("%f",  &c2.area);
    printf("Digite o PIB:");                   scanf("%f",  &c2.pib);
    printf("Digite o número de pontos turísticos:"); scanf("%d", &c2.pontosTur);

    calcularAtributos(&c2);

    /* Exibe Carta 2 */
    imprimirCabecalhoCarta(2);
    printf("Estado: %s\n", c2.estado);
    printf("Código: %s\n", c2.codigo);
    printf("Nome da Cidade: %s\n", c2.cidade);
    printf("População: %lu\n", c2.populacao);
    printf("Área: %.2f km²\n", c2.area);
    printf("PIB: %.2f\n", c2.pib);
    printf("Número de Pontos Turísticos: %d\n", c2.pontosTur);
    printf("Densidade populacional: %.2f hab/km²\n", c2.densidade);
    printf("PIB per Capita: %.2f reais\n", c2.pibPerCapita);
    printf("Super Poder: %.2f\n\n", c2.superpoder);

    /* Duelo */
    printf("\n==============================================================\n");
    printf("-------                 HORA DO DUELO                  -------\n");
    printf("\n==============================================================\n");

    printf("Escolha a opção correspondente ao primeiro atributo que você deseja comparar: \n");
    printf("1. População\n2. Área\n3. PIB\n4. Número de pontos turísticos\n5. Densidade demográfica\n6. Pib per Capita\n7. Super poder\n");
    printf("\nEscolha: ");
    scanf("%d", &rodada1);

    resultado1 = compararRodada(rodada1, &c1, &c2, &v1r1, &v2r1);

    printf("\n==============================================================\n");
    printf("Escolha a opção correspondente ao segundo atributo que você deseja comparar: \n");
    printf("1. População\n2. Área\n3. PIB\n4. Número de pontos turísticos\n5. Densidade demográfica\n6. Pib per Capita\n7. Super poder\n");
    printf("\nEscolha: ");
    scanf("%d", &rodada2);

    if (rodada1 == rodada2) {
        printf("Você escolheu o mesmo atributo da rodada 1!\n");
    } else {
        resultado2 = compararRodada(rodada2, &c1, &c2, &v1r2, &v2r2);

        /* RESULTADOS */
        printf("\n========================================================================\n");
        printf("                              RESULTADOS                             \n");
        printf("                                                                          \n");
        printf("\n    =================== RESULTADO POR RODADA =====================  \n");
        printf("                                                                          \n");
        if (resultado1 == 1 && resultado2 == 1) {
            printf("A carta 1 (%s) Venceu!\n", c1.cidade);
        } else if (resultado1 == 0 && resultado2 == 0) {
            printf("A carta 2 (%s) Venceu!\n", c2.cidade);
        } else {
            printf("Empate!");
        }
        printf("                                                                          \n");
        printf("\n=================== RESULTADO POR SOMA DOS ATRIBUTOS ===================\n");
        printf("                                                                          \n");
        {
            float soma1 = v1r1 + v1r2;
            float soma2 = v2r1 + v2r2;

            printf("Carta 1 (%.2f + %.2f) = %.2f\n", v1r1, v1r2, soma1);
            printf("Carta 2 (%.2f + %.2f) = %.2f\n", v2r1, v2r2, soma2);

            if (soma1 > soma2) {
                printf("*** Carta 1 venceu no somatório das duas rodadas! ***\n");
            } else if (soma1 < soma2) {
                printf("*** Carta 2 venceu no somatório das duas rodadas! ***\n");
            } else {
                printf("*** Empate no somatório das duas rodadas! ***\n");
            }
            printf("                                                               ");
        }
    }

    return 0;
}
