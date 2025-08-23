#include <stdio.h>

/*
Desafio Super Trunfo - Países
Tema 1 - Cadastro das Cartas
Este código inicial serve como base para o desenvolvimento do sistema de cadastro de cartas de cidades.
Siga os comentários para implementar cada parte do desafio.
Teste larissa
  ---------------------------------------------------
  - Cadastro de 2 cartas via scanf (sem laços e sem condicionais).
  - Atributos:
      Estado (char), Código (string), Nome (string),
      População (unsigned long int), Área (float),
      PIB (float), Pontos turísticos (int).
  - Cálculos:
      Densidade Populacional = População / Área
      PIB per Capita = PIB / População
      Super Poder = Pop + Área + PIB + Pontos + PIB per Capita + (1 / Densidade)
  - Comparações:
      Para Densidade Populacional: vence a menor.
      Para os demais atributos (incluindo Super Poder): vence a maior.
  - Saída:
      Mostra atributos e cálculos das cartas,
      depois imprime comparações (1 = Carta 1 venceu, 0 = Carta 2 venceu).
*/

int main(void) {
    /* -------- Carta 1 -------- */
    char estado1;
    char codigo1[8];
    char cidade1[64];
    unsigned long int pop1;
    float area1;
    float pib1;
    int ptur1;
    float dens1;
    float pibpc1;
    float sp1;

    /* -------- Carta 2 -------- */
    char estado2;
    char codigo2[8];
    char cidade2[64];
    unsigned long int pop2;
    float area2;
    float pib2;
    int ptur2;
    float dens2;
    float pibpc2;
    float sp2;

    /* ===== Entrada de dados: CARTA 1 ===== */
    printf("Carta 1:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado1);
    printf("Codigo (ex: A01): ");
    scanf(" %7s", codigo1);
    printf("Nome da Cidade: ");
    scanf(" %63[^\n]", cidade1);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &pop1);
    printf("Area (float, km2): ");
    scanf("%f", &area1);
    printf("PIB (float): ");
    scanf("%f", &pib1);
    printf("Numero de Pontos Turisticos (int): ");
    scanf("%d", &ptur1);

    /* Cálculos da Carta 1 */
    dens1  = (float)pop1 / area1;
    pibpc1 = pib1 / (float)pop1;
    sp1    = (float)pop1 + area1 + pib1 + (float)ptur1 + pibpc1 + (1.0f / dens1);

    /* ===== Entrada de dados: CARTA 2 ===== */
    printf("\nCarta 2:\n");
    printf("Estado (A-H): ");
    scanf(" %c", &estado2);
    printf("Codigo (ex: B02): ");
    scanf(" %7s", codigo2);
    printf("Nome da Cidade: ");
    scanf(" %63[^\n]", cidade2);
    printf("Populacao (unsigned long int): ");
    scanf("%lu", &pop2);
    printf("Area (float, km2): ");
    scanf("%f", &area2);
    printf("PIB (float): ");
    scanf("%f", &pib2);
    printf("Numero de Pontos Turisticos (int): ");
    scanf("%d", &ptur2);

    /* Cálculos da Carta 2 */
    dens2  = (float)pop2 / area2;
    pibpc2 = pib2 / (float)pop2;
    sp2    = (float)pop2 + area2 + pib2 + (float)ptur2 + pibpc2 + (1.0f / dens2);

    /* ===== Exibição dos atributos ===== */
    printf("\n--- Carta 1 ---\n");
    printf("Estado: %c\nCodigo: %s\nNome: %s\n", estado1, codigo1, cidade1);
    printf("Populacao: %lu\nArea: %.2f km²\nPIB: %.2f\n", pop1, area1, pib1);
    printf("Pontos Turisticos: %d\n", ptur1);
    printf("Densidade Populacional: %.2f hab/km²\n", dens1);
    printf("PIB per Capita: %.2f\n", pibpc1);
    printf("Super Poder: %.2f\n", sp1);

    printf("\n--- Carta 2 ---\n");
    printf("Estado: %c\nCodigo: %s\nNome: %s\n", estado2, codigo2, cidade2);
    printf("Populacao: %lu\nArea: %.2f km²\nPIB: %.2f\n", pop2, area2, pib2);
    printf("Pontos Turisticos: %d\n", ptur2);
    printf("Densidade Populacional: %.2f hab/km²\n", dens2);
    printf("PIB per Capita: %.2f\n", pibpc2);
    printf("Super Poder: %.2f\n", sp2);

    /* ===== Comparações ===== */
    printf("\nComparacao de Cartas (1 = Carta 1 venceu, 0 = Carta 2 venceu):\n");
    printf("Populacao: %d\n", (pop1 > pop2));
    printf("Area: %d\n", (area1 > area2));
    printf("PIB: %d\n", (pib1 > pib2));
    printf("Pontos Turisticos: %d\n", (ptur1 > ptur2));
    printf("Densidade Populacional (menor vence): %d\n", (dens1 < dens2));
    printf("PIB per Capita: %d\n", (pibpc1 > pibpc2));
    printf("Super Poder: %d\n", (sp1 > sp2));

    return 0;
}
