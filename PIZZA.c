#include <stdio.h>
#include <string.h>
struct Pizza {
    char nome[50];
    float preco;
};
void cadastrarPizza();
void listarPizzas();
void cadastrarCliente();
void listarClientes();
void venderPizza();
int main() {
    int opcao;

    do {
        printf("=== Nostra Pizza ===\n");
        printf("1. Cadastrar Pizza\n");
        printf("2. Listar Pizzas\n");
        printf("3. Cadastrar Cliente\n");
        printf("4. Listar Clientes\n");
        printf("5. Vender Pizza\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPizza();
                break;
            case 2:
                listarPizzas();
                break;
            case 3:
                cadastrarCliente();
                break;
            case 4:
                listarClientes();
                break;
            case 5:
                venderPizza();
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
struct Cliente {
    char nome[50];
};
struct Pizza pizzas[10];
int totalPizzas = 0;

struct Cliente clientes[10];
int totalClientes = 0;


void cadastrarPizza() {
    if (totalPizzas >= 10) {
        printf("Limite atingido!\n");
        return 0;
    }

    printf("--- Cadastro de Pizza ---\n");
    printf("Nome da pizza: ");
    scanf("%s", pizzas[totalPizzas].nome);
    printf("Preço: ");
    scanf("%f", &pizzas[totalPizzas].preco);

    totalPizzas++;
    printf("Pizza cadastrada!\n");
}

void listarPizzas() {
    printf("--- Pizzas Cadastradas ---\n");
    if (totalPizzas == 0) {
        printf("Nenhuma pizza cadastrada.\n");
        return 0;
    }

    for (int i = 0; i < totalPizzas; i++) {
        printf("%d. %s - R$ %.2f\n", i + 1, pizzas[i].nome, pizzas[i].preco);
    }
}

void cadastrarCliente() {
    if (totalClientes >= 10) {
        printf("Limite de clientes atingido!\n");
        return;
    }

    printf("\n--- Cadastro de Cliente ---\n");
    printf("Nome do cliente: ");
    scanf("%s", clientes[totalClientes].nome);

    totalClientes++;
    printf("Cliente cadastrado com sucesso!\n");
}

void listarClientes() {
    printf("\n--- Clientes Cadastrados ---\n");
    if (totalClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    for (int i = 0; i < totalClientes; i++) {
        printf("%d. %s\n", i + 1, clientes[i].nome);
    }
}

int clienteExiste(const char* nome) {
    for (int i = 0; i < totalClientes; i++) {
        if (strcmp(nome, clientes[i].nome) == 0) {
            return 1;
        }
    }
    return 0;
}

void venderPizza() {
    char nomeCliente[50];
    int indice, quantidade, escolha;
    float total = 0;

    if (totalPizzas == 0 || totalClientes == 0) {
        printf("É necessário ter clientes e pizzas cadastradas.\n");
        return;
    }

    printf("\n--- Venda de Pizza ---\n");
    printf("Nome do cliente: ");
    scanf("%s", nomeCliente);

    if (!clienteExiste(nomeCliente)) {
        printf("Cliente não cadastrado. Cadastre antes de comprar.\n");
        return;
    }

    listarPizzas();
    printf("\nQuantas pizzas deseja comprar? (máx 5): ");
    scanf("%d", &quantidade);

    if (quantidade > 5) {
        printf("Quantidade excede o máximo permitido!\n");
        return;
    }

    printf("\n--- Selecione as pizzas pelo número ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Pizza %d: ", i + 1);
        scanf("%d", &escolha);

        if (escolha < 1 || escolha > totalPizzas) {
            printf("Pizza inválida!\n");
            i--;
        } else {
            total += pizzas[escolha - 1].preco;
            printf("Adicionada: %s - R$ %.2f\n", pizzas[escolha - 1].nome, pizzas[escolha - 1].preco);
        }
    }

    printf("Venda concluída!\n");
    printf("Cliente: %s\n", nomeCliente);
    printf("Total a pagar: R$ %.2f\n", total);
}
