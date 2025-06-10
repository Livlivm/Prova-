#include <stdio.h>
struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};
void cadastrarProduto();
void visualizarProduto();
void realizarCompra();

int main() {
    int opcao;

    do {
        printf("=== SuperMais ===\n");
        printf("1. Cadastrar produto\n");
        printf("2. Visualizar produto\n");
        printf("3. Realizar compra\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                visualizarProduto();
                break;
            case 3:
                realizarCompra();
                break;
            case 0:
                printf("Sair...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}
struct Produto produto;

void cadastrarProduto() {
    printf("--- Cadastro de Produto ---\n");
    printf("Nome do produto: ");
    scanf("%s", produto.nome);

    printf("Preço do produto: ");
    scanf("%f", &produto.preco);

    printf("Quantidade em estoque: ");
    scanf("%d", &produto.quantidade);
}


void visualizarProduto() {
    printf("--- Informações do Produto ---\n");
    printf("Nome: %s\n", produto.nome);
    printf("Preço: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
}

void realizarCompra() {
    int quantidade;
    printf("--- Compra de Produto ---\n");
    printf("Quantidade a comprar: ");
    scanf("%d", &quantidade);

    if (quantidade <= produto.quantidade) {
        produto.quantidade -= quantidade;
        printf("Compra realizada com sucesso!\n");
    } else {
        printf("Estoque insuficiente!\n");
    }
}
