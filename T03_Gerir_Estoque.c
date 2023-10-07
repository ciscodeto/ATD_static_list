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
    if (!listIsFull(list) && (index < list -> n)) {
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
    if (!listIsFull(list)) {
        list -> itens[list -> n] = prod;
        list -> n++;
        return 1;
    }
    return 0;
}

int listRemoveAtPosition(t_list *list, int position) {
    if (!listIsEmpty(list) && list -> n >= position) {
        for (int i = position ; i < list -> n ; i ++) {
            list -> itens[i] = list -> itens[i+1];
        }
        list -> n--;
        return 1;
    }
    return 0;
}

int listRemoveAtEnd(t_list *list) {
    if (!listIsEmpty(list)) {
        list -> n--;
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
    char * n = list -> itens[index].name;
    double p = list -> itens[index].price;
    int s = list -> itens[index].qtd_storage;
    printf("\n>> COD: %d || PRODUTO: %s || VALOR: %.2f || EM ESTOQUE: %d\n\n", c, n, p, s);
    return 1;
}

int buscarProduto(t_list * list, int c) {
    for (int i = 0 ; i < list -> n ; i++) {
        if (list -> itens[i].CODE == c){
            return i;
        }
    }
    return -1; // Não existe
}

t_product criarProduto(int c) {
    t_product prod;
    prod.CODE = c;
    printf("Digite o nome do produto (max 50 caracteres): \n>>> ");
    fgets(prod.name, sizeof(prod.name), stdin);
    printf("Digite o valor do produto: \n>>> ");
    scanf("%lf%*c", &prod.price);
    printf("Digite a quantidade em estoque do produto: \n>>> ");
    scanf("%d%*c", &prod.qtd_storage);
    return prod;
}

int consultarProduto(t_list * list) {
    int c;
    printf("\nDigite o codigo do produto que deseja consultar: \n>>> ");
    scanf("%d%*c",&c);
    int index = buscarProduto(list, c);

    if (index > list -> n || index < 0) {
        printf("\nERRO - PRODUTO INEXISTENTE...");
        return 0;
    }
    if (index >= 0) {
        imprimeProduto(list, index);
    }
}

int atualizarProduto(t_list * list) {
    int c;
    printf("\nDigite o codigo do produto que deseja atualizar: \n>>> ");
    scanf("%d%*c", &c);
    int index = buscarProduto(list, c);

    if (index >= 0) {
        list -> itens[index] = criarProduto(c);
        printf("\nPRODUTO ATUALIZADO COM SUCESSO!!!");
    } else {
        printf("\nERRO...");
    }
}

int adicionarProduto(t_list * list) {
    int c;
    printf("\nDigite o CODIGO do produto: \n >>> ");
    scanf("%d%*c",&c);
    int index = buscarProduto(list, c);
    
    if(index < 0){
        t_product prod = criarProduto(c);
        if (listInsertAtEnd(list,prod)){
            printf("\nPRODUTO CADASTRADO!!!");
        } else {
            printf("\nERRO - ARMAZENAMENTO CHEIO...");
        }
    } else {
        printf("\nERRO - PRODUTO JA FOI CADASTRADO...");
    }
    return 0;
}

int removerProduto(t_list * list) {
    int c;
    printf("\nDigite o CODIGO do produto que deseja remover: \n >>> ");
    scanf("%d%*c",&c);

    int index = buscarProduto(list, c);
    if (index >= 0){
        if (listRemoveAtPosition(list, index)) {
            printf("\nPRODUTO REMOVIDO COM SUCESSO!!! ");
            return 1;
        }
    }
    printf("\nERRO - PRODUTO INEXISTENTE...");
    return 0;
}

int pothermu() {
    int op;
    printf("\n1. Adicionar\n2. Remover\n3. Atualizar\n4. Consultar \n5. Relatorios\n>>> ");
    scanf("%d%*c", &op);
    return op;
}

int opSubmenuRelatorios() {
    int op;
    printf("\nLISTAR POR\n1. CODIGO\n2. Nome\n3. Quantidade\n4. Valor \n5. Estoque baixo\n6. Voltar\n>>> ");
    scanf("%d%*c", &op);
    return op;
}

int imprimirTodos(t_list * list) {
    for (int i = 0 ; i < list -> n ; i++) {
        imprimeProduto(list , i);
    }
}

int imprimirTodosEstoqueBaixo(t_list * list) {
    for (int i = 0 ; i < list -> n ; i++) {
        if (list -> itens[i].qtd_storage < 10) {
            imprimeProduto(list , i);
        }
    }
}

int submenuRelatorios(t_list * list) {
    int option;
    do
    {
        printf("Digite uma dos processos: \n R E L A T O R I O :\n");
        option = opSubmenuRelatorios();
        switch (option)
        {
        case 1:
            orderByCODE(list);
            imprimirTodos(list);
            break;
        case 2:
            orderByName(list);
            imprimirTodos(list);
            break;
        case 3:
            orderByQtd(list);
            imprimirTodos(list);
            break;
        case 4:
            orderByPrice(list);
            imprimirTodos(list);
            break;
        case 5:
            imprimirTodosEstoqueBaixo(list);
            break;
        case 6:
            printf("VALEU FALOU TUDO SALVO!!!\n\n");
        default:
            printf("ENTRADA INVALIDA\n");
        }
    } while (option != 6);
    return 0;
}

int main() {
    int option;
    t_list * lista_prods = listCreate(50);
    
    do
    {
        printf("\nDigite um dos processos: \n P R O D U T O :\n");
        option = pothermu();
        switch (option)
        {
        case 1:
            adicionarProduto(lista_prods);
            break;
        case 2:
            removerProduto(lista_prods);
            break;
        case 3:
            atualizarProduto(lista_prods);
            break;
        case 4: 
            consultarProduto(lista_prods);
            break;
        case 5:
            submenuRelatorios(lista_prods);
            break;
        case 6:
            printf("VALEU FALOU TUDO SALVO!!!");
            break;
        default:
            printf("ENTRADA INVALIDA");
            break;
        }
    } while (option != 6);
    return 0;
}