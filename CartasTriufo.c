#include <stdio.h>
#include <string.h>

struct Carta {
    char estado[30];
    char codigo[10];
    char cidade[50];
    int populacao;
    int pontosTuristicos;
    float area;
    float pib;             // em bilhões de reais
    float densidade;
    float pibPerCapita;
};

float calcularDensidade(int populacao, float area) {
    return (float)populacao / area;
}

float calcularPibPerCapita(float pib, int populacao) {
    return (pib * 1000000000) / populacao;
}

void exibirCarta(struct Carta c, int numeroCarta) {
    printf("\n--- Carta %d ---\n", numeroCarta);
    printf("Estado: %s\n", c.estado);
    printf("Codigo: %s\n", c.codigo);
    printf("Cidade: %s\n", c.cidade);
    printf("Populacao: %d\n", c.populacao);
    printf("Area: %.2f km2\n", c.area);
    printf("PIB: %.2f bilhoes de reais\n", c.pib);
    printf("Pontos turisticos: %d\n", c.pontosTuristicos);
    printf("Densidade populacional: %.2f hab/km2\n", c.densidade);
    printf("PIB per capita: %.2f reais\n", c.pibPerCapita);
}

int main() {
    struct Carta cartas[2];

    // Carta 1: Duque de Caxias
    strcpy(cartas[0].estado, "Rio de Janeiro");
    strcpy(cartas[0].codigo, "RJ002");
    strcpy(cartas[0].cidade, "Duque de Caxias");
    cartas[0].populacao = 924624;
    cartas[0].pontosTuristicos = 5;
    cartas[0].area = 464.0;
    cartas[0].pib = 55.0; // bilhões
    cartas[0].densidade = calcularDensidade(cartas[0].populacao, cartas[0].area);
    cartas[0].pibPerCapita = calcularPibPerCapita(cartas[0].pib, cartas[0].populacao);

    // Carta 2: São Paulo
    strcpy(cartas[1].estado, "São Paulo");
    strcpy(cartas[1].codigo, "SP001");
    strcpy(cartas[1].cidade, "São Paulo");
    cartas[1].populacao = 12325000;
    cartas[1].pontosTuristicos = 12;
    cartas[1].area = 1521.0;
    cartas[1].pib = 700.0; // bilhões
    cartas[1].densidade = calcularDensidade(cartas[1].populacao, cartas[1].area);
    cartas[1].pibPerCapita = calcularPibPerCapita(cartas[1].pib, cartas[1].populacao);

    // Exibir cartas
    for (int i = 0; i < 2; i++) {
        exibirCarta(cartas[i], i + 1);
    }

    // Comparar para ver qual carta vence pelo PIB per capita
    printf("\n=== Carta vencedora (maior PIB per capita) ===\n");
    if (cartas[0].pibPerCapita > cartas[1].pibPerCapita) {
        printf("%s (%s)\n", cartas[0].cidade, cartas[0].estado);
    } else {
        printf("%s (%s)\n", cartas[1].cidade, cartas[1].estado);
    }

    return 0;
}