#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// IMPLEMENTAÇÃO TAD LISTA ESTÁTICA - INÍCIO //

typedef struct {
    char name[50];
    int CODE;
    int qtd_storage;
    double price;
} t_product;

typedef struct {
    int max_size;
    int n;
    t_product * itens;
} t_list;

t_list * listCreate(int max_size) {
    t_list * list = (t_list *) malloc(sizeof(t_list) * max_size);
    list -> max_size = max_size;
    list -> n = 0;
    list -> itens = (t_product *) malloc(sizeof(t_product) * max_size);
    return list;
}

int listInsertAtPosition(t_list * list, t_product prod, int index) {
    if (!full(list) && (index < list -> n)) {
        for (int i = list -> n - 1; i >= index; i--) {
            list -> itens[i+1] = list -> itens[i];
        }

        list -> itens[index] = prod;
        list -> n++;
        return 1;
    }
    return 0;
}

int listInsertAtEnd(t_list * list, t_product prod) {
    if (!full(list)) {
        list -> itens[list -> n] = prod;
        list -> n++;
        return 1;
    }
    return 0;
}

int listSizeOf(t_list * list) {
    return list -> n;
}

int listIsFull(t_list * list) {
    if (list -> n == list -> max_size) {
        return 1;
    }
    return 0;
}

int listIsEmpty(t_list * list) {
    if (list -> n == 0) {
        return 1;
    }
    return 0;
}

int listEmpty(t_list * list) {
    list -> n = 0;
}

int listFree(t_list *list) {
    free(list -> itens);
    free(list);
    return 1;
}


// IMPLEMENTAÇÃO TAD LISTA ESTÁTICA - FIM //

// USANDO A TAD LISTA DE PRODUTOS.

int listFindByCode(t_list * list, int code) {
    for (int i = 0 ; i < list -> n ; i++) {
        if (list -> itens[i].CODE == code) {
            return i;
        }
    }
    return -1;
}

int orderByQtd(t_list * list) {
    for (int i = 1 ; i < list -> n ; i++) {
        t_product aux = list -> itens[i];
        int j = i - 1;

        while (j >= 0 && (list -> itens[j].qtd_storage > aux.qtd_storage)) {
            list -> itens[j + 1] = list -> itens[j];
            j--;
        }
        list -> itens[j + 1] = aux;
    }
}

int orderByPrice(t_list * list) {
    for (int i = 1 ; i < list -> n ; i++) {
        t_product aux = list -> itens[i];
        int j = i - 1;

        while (j >= 0 && (list -> itens[j].price > aux.price)) {
            list -> itens[j + 1] = list -> itens[j];
            j--;
        }
        list -> itens[j + 1] = aux;
    }
}

int orderByCODE(t_list * list) {
    for (int i = 1 ; i < list -> n ; i++) {
        t_product aux = list -> itens[i];
        int j = i - 1;

        while (j >= 0 && (list -> itens[j].CODE > aux.CODE)) {
            list -> itens[j + 1] = list -> itens[j];
            j--;
        }
        list -> itens[j + 1] = aux;
    }
}

int orderByName(t_list * list) {
    for (int i = 1 ; i < list -> n ; i++) {
        t_product aux = list -> itens[i];
        int j = i - 1;

        while (j >= 0 && strcmp(list -> itens[j].name, aux.name) > 0) {
            list -> itens[j + 1] = list -> itens[j];
            j--;
        }
        list -> itens[j + 1] = aux;
    }
}

// CRUD DE VERDADE AGORA EM //

int imprimeProduto(t_list * list, int index) {
    int c = list -> itens[index].CODE;
    char n = list -> itens[index].name;
    double p = list -> itens[index].price;
    int s = list -> itens[index].qtd_storage;
    printf(">> COD: %d || PRODUTO: %s || VALOR: %.2f || EM ESTOQUE: %d\n");
    return 1;
}

int buscarProduto(t_list * list, int code) {
    for (int i = 0 ; i < list -> n ;) {
        if (list -> itens[i].CODE == code){
            return i;
        }
    }
    return -1; // Não existe
}

t_product criarProduto(int code) {
    t_product prod;
    prod.CODE = code;
    printf("Digite o nome do produto (max 50 caracteres): \n>>> ");
    fgets(prod.name, sizeof(prod.name), stdin);
    printf("Digite o valor do produto: \n>>> ");
    scanf("%lf", &prod.price);
    printf("Digite a quantidade em estoque do produto: \n>>> ");
    scanf("%d", &prod.qtd_storage);
    return prod;
}

int adicionarProduto(t_list * list) {
    int c;
    printf("Digite o CODIGO do produto: \n >>> ");
    scanf("%d",&c);
    int index = buscarProduto(list, c);
    if(index < 0){
        t_product prod = criarProduto(c);
        if (listInsertAtEnd(list,prod)){
            printf("PRODUTO CADASTRADO!!!");
        } else {
            printf("ERRO - ARMAZENAMENTO CHEIO...");
        }
    } else {
        printf("ERRO - PRODUTO JA FOI CADASTRADO...");
    }
}

int removerProduto(int code) {
    int index = buscarProduto(code);
    if (index > 0);
        list
}

int buscarProduto(int code) {
    
}

int menu() {
    int op;
    printf("\n1. Adicionar\n2. Remover\n3. Atualizar\n4. Consultar");
    scanf("%d", &op);
    return op;
}

int main(int argc, char const *argv[]) {

    #define MAX_SIZE 50;
        int option;

    
    do
    {
        printf("Digite uma dos processos: \n P R O D U T O :\n");
        option = menu();
        switch (option)
        {
        case 1:
            
            break;
        case 2:
            
            break;
        default:
            printf("ENTRADA INVALIDA");
            break;
        }

    } while (option != 6);
    
    return 0;
}
