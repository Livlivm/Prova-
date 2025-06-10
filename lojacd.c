#include <stdio.h>
#include <string.h>

struct CD {
    char banda[50];
    int ano;
    char genero[30];
    int quantidade;
    float preco;
};
void cadastrarCD();
void venderCD();
void pesquisarBanda();
void listarCD();
int main() {
    int opcao;

    do {
        printf("=== Loja de CDs ===\n");
        printf("1. Cadastrar CD\n");
        printf("2. Listar CD\n");
        printf("3. Pesquisar por Banda\n");
        printf("4. Vender CD\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCD();
                break;
            case 2:
                listarCD();
                break;
            case 3:
                pesquisarBanda();
                break;
            case 4:
                venderCD();
                break;
            case 0:
                printf("Sair...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}


struct CD cd;


void cadastrarCD() {
    printf("--- Cadastro de CD ---\n");
    printf("Banda: ");
    scanf("%s", cd.banda);

    printf("Ano: ");
    scanf("%d", &cd.ano);

    printf("Gênero: ");
    scanf("%s", cd.genero);

    printf("Quantidade em estoque: ");
    scanf("%d", &cd.quantidade);

    printf("Preço: ");
    scanf("%f", &cd.preco);

    printf("CD cadastrado com sucesso :)\n");
}


void venderCD() {
    int quantidade;
    printf("--- Venda de CD ---\n");
    if (cd.quantidade <= 0) {
        printf("CD esgotado :(\n");
        return;
    }

    printf("Quantidade que o cliente deseja comprar: ");
    scanf("%d", &quantidade);

    if (quantidade > cd.quantidade) {
        printf("Estoque insuficiente! Disponivel %d unidade.\n", cd.quantidade);
    } else {
        float total = quantidade * cd.preco;
        cd.quantidade -= quantidade;
        printf("Venda realizada! Valor total: R$ %.2f\n", total);
        printf("Estoque restante: %d unidades.\n", cd.quantidade);
    }
}


void pesquisarBanda() {
    char busca[50];
    printf("--- Pesquisa por Banda ---\n");
    printf("Digite o nome da banda: ");
    scanf("%s", busca);

    if (strcmp(busca, cd.banda) == 0) {
        printf("CD encontrado!\n");
        printf("Banda: %s\n", cd.banda);
        printf("Ano: %d\n", cd.ano);
        printf("Gênero: %s\n", cd.genero);
        printf("Quantidade em estoque: %d\n", cd.quantidade);
        printf("Preço: R$ %.2f\n", cd.preco);
    } else {
        printf("CD da banda '%s' não encontrado :( \n", busca);
    }
}

void listarCD() {
    printf("--- Detalhes do CD ---\n");
    printf("Banda: %s\n", cd.banda);
    printf("Ano: %d\n", cd.ano);
    printf("Gênero: %s\n", cd.genero);
    printf("Quantidade em estoque: %d\n", cd.quantidade);
    printf("Preço: R$ %.2f\n", cd.preco);
}


