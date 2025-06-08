#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 100

typedef struct {
    char estado[TAM];
    char codigo[TAM]; // corrigido de int para string
    char nome[TAM];
    long int populacao;
    float area;
    float pib;
    int pontosTuristicos;
} Cidade;

void cadastrarCidade(Cidade *c) {
    printf("Digite o nome da cidade: ");
    fgets(c->nome, TAM, stdin);
    c->nome[strcspn(c->nome, "\n")] = '\0';

    printf("Digite o estado: ");
    fgets(c->estado, TAM, stdin);
    c->estado[strcspn(c->estado, "\n")] = '\0';

    printf("Digite o código da carta: ");
    fgets(c->codigo, TAM, stdin);
    c->codigo[strcspn(c->codigo, "\n")] = '\0';

    printf("Digite a população:\n");
    scanf("%ld", &c->populacao);
    while (getchar() != '\n');

    printf("Digite a área (em km²):\n");
    scanf("%f", &c->area);
    while (getchar() != '\n');

    printf("Digite o PIB (em bilhões):\n");
    scanf("%f", &c->pib);
    while (getchar() != '\n');

    printf("Digite o número de pontos turísticos:\n");
    scanf("%d", &c->pontosTuristicos);
    while (getchar() != '\n');
}

void exibirCidade(Cidade c) {
    printf("\n---- Carta da Cidade ----\n");
    printf("Nome: %s\n", c.nome);
    printf("Estado: %s\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("População: %ld\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões\n", c.pib);
    printf("Pontos turísticos: %d\n", c.pontosTuristicos);
    printf("-------------------------\n");
}

void comparar(Cidade c1, Cidade c2, int opcao) {
    printf("\n🔍 Comparando pelo atributo selecionado...\n");

    switch (opcao) {
        case 1:
            if (c1.populacao > c2.populacao)
                printf("🏆 Vencedora: %s (maior população)\n", c1.nome);
            else if (c2.populacao > c1.populacao)
                printf("🏆 Vencedora: %s (maior população)\n", c2.nome);
            else
                printf("🤝 Empate em população!\n");
            break;

        case 2:
            if (c1.area > c2.area)
                printf("🏆 Vencedora: %s (maior área)\n", c1.nome);
            else if (c2.area > c1.area)
                printf("🏆 Vencedora: %s (maior área)\n", c2.nome);
            else
                printf("🤝 Empate em área!\n");
            break;

        case 3:
            if (c1.pib > c2.pib)
                printf("🏆 Vencedora: %s (maior PIB)\n", c1.nome);
            else if (c2.pib > c1.pib)
                printf("🏆 Vencedora: %s (maior PIB)\n", c2.nome);
            else
                printf("🤝 Empate em PIB!\n");
            break;

        case 4:
            if (c1.pontosTuristicos > c2.pontosTuristicos)
                printf("🏆 Vencedora: %s (mais pontos turísticos)\n", c1.nome);
            else if (c2.pontosTuristicos > c1.pontosTuristicos)
                printf("🏆 Vencedora: %s (mais pontos turísticos)\n", c2.nome);
            else
                printf("🤝 Empate em pontos turísticos!\n");
            break;

        case 5: {
            float dens1 = c1.area != 0 ? c1.populacao / c1.area : 0;
            float dens2 = c2.area != 0 ? c2.populacao / c2.area : 0;
            if (dens1 < dens2)
                printf("🏆 Vencedora: %s (menor densidade populacional)\n", c1.nome);
            else if (dens2 < dens1)
                printf("🏆 Vencedora: %s (menor densidade populacional)\n", c2.nome);
            else
                printf("🤝 Empate em densidade populacional!\n");
            break;
        }

        default:
            printf("❌ Atributo inválido!\n");
    }
}

int menuComparacao() {
    int opcao;
    printf("\nEscolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos turísticos\n");
    printf("5 - Densidade populacional (menor vence)\n");
    printf("Sua escolha: ");
    scanf("%d", &opcao);
    while (getchar() != '\n');
    return opcao;
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Cidade cidade1, cidade2;

    printf("Cadastro da primeira cidade:\n");
    cadastrarCidade(&cidade1);

    printf("\nCadastro da segunda cidade:\n");
    cadastrarCidade(&cidade2);

    exibirCidade(cidade1);
    exibirCidade(cidade2);

    int opcao = menuComparacao();
    comparar(cidade1, cidade2, opcao);

    return 0;
}
