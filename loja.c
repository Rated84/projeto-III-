#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "loja.h"


NoUsuario* criar_no_usuario(struct Usuario usuario) {
    NoUsuario* novo = (NoUsuario*)malloc(sizeof(NoUsuario));
    novo->usuario = usuario;
    novo->prox = NULL;
    return novo;
}

NoJogo* criar_no_jogo(struct Jogo jogo) {
    NoJogo* novo = (NoJogo*)malloc(sizeof(NoJogo));
    novo->jogo = jogo;
    novo->prox = NULL;
    return novo;
}


NoUsuario* inserir_usuario(NoUsuario* lista, struct Usuario usuario) {
    NoUsuario* novo = criar_no_usuario(usuario);
    novo->prox = lista;
    return novo;
}

NoJogo* inserir_jogo(NoJogo* lista, struct Jogo jogo) {
    NoJogo* novo = criar_no_jogo(jogo);
    novo->prox = lista;
    return novo;
}

void cadastrar_email(NoUsuario** lista) {
    struct Usuario usuario;
    printf("Digite seu email: ");
    scanf("%s", usuario.email);

    if (verificar_email(usuario.email, *lista)) {
        *lista = inserir_usuario(*lista, usuario);
        printf("Email cadastrado com sucesso!\n\n");
    } else {
        printf("Email inválido ou já cadastrado.\n\n");
    }
}


int verificar_email(char* email, NoUsuario* lista) {
    if (strchr(email, '@') == NULL || strlen(email) >= 80) return 0;

    while (lista != NULL) {
        if (strcmp(lista->usuario.email, email) == 0) return 0;
        lista = lista->prox;
    }
    return 1;
}


void adicionar_jogo(NoJogo** lista) {
    struct Jogo jogo;
    printf("Digite o nome do jogo: ");
    scanf("%s", jogo.nome);
    printf("Digite o preço do jogo: ");
    scanf("%f", &jogo.preco);

    *lista = inserir_jogo(*lista, jogo);
    printf("Jogo adicionado com sucesso!\n\n");
}

void pesquisar_jogo(NoJogo* lista) {
    char nome[50];
    printf("Digite o nome do jogo: ");
    scanf("%s", nome);

    struct Jogo* jogo = buscar_jogo(lista, nome);
    if (jogo) {
        printf("Jogo encontrado:\nNome: %s\nPreço: %.2f\n\n", jogo->nome, jogo->preco);
    } else {
        printf("Jogo não encontrado.\n\n");
    }
}

struct Jogo* buscar_jogo(NoJogo* lista, char* nome) {
    while (lista != NULL) {
        if (strcmp(lista->jogo.nome, nome) == 0) {
            return &lista->jogo;
        }
        lista = lista->prox;
    }
    return NULL;
}


NoJogo* remover_jogo(NoJogo* lista, char* nome) {
    NoJogo* atual = lista;
    NoJogo* anterior = NULL;

    while (atual != NULL) {
        if (strcmp(atual->jogo.nome, nome) == 0) {
            if (anterior == NULL) {
                lista = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Jogo removido!\n\n");
            return lista;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Jogo não encontrado.\n\n");
    return lista;
}


NoJogo* criar_lista_promocao(NoJogo* lista) {
    NoJogo* promocao = NULL;

    while (lista != NULL) {
        if (lista->jogo.preco < 30) {
            promocao = inserir_jogo(promocao, lista->jogo);
        }
        lista = lista->prox;
    }
    return promocao;
}

NoJogo* ordenar_jogos(NoJogo* lista) {
    if (lista == NULL) return lista;

    int trocado;
    NoJogo *atual, *ultimo = NULL;

    do {
        trocado = 0;
        atual = lista;

        while (atual->prox != ultimo) {
            if (atual->jogo.preco > atual->prox->jogo.preco) {
                struct Jogo temp = atual->jogo;
                atual->jogo = atual->prox->jogo;
                atual->prox->jogo = temp;
                trocado = 1;
            }
            atual = atual->prox;
        }
        ultimo = atual;
    } while (trocado);

    return lista;
}

// Alterações de usuário e senha
void alterar_usuario(struct Usuario* usuario) {
    printf("Novo nome de usuário: ");
    scanf("%s", usuario->nome);
    printf("Nome de usuário alterado!\n\n");
}

void alterar_senha(struct Usuario* usuario) {
    printf("Nova senha: ");
    scanf("%s", usuario->senha);
    printf("Senha alterada com sucesso!\n\n");
}


void liberar_lista_usuarios(NoUsuario* lista) {
    while (lista != NULL) {
        NoUsuario* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

void liberar_lista_jogos(NoJogo* lista) {
    while (lista != NULL) {
        NoJogo* temp = lista;
        lista = lista->prox;
        free(temp);
    }
}

void mensagem_boas_vindas() {
    printf("Bem-vindo ao Sistema de Gerenciamento de Usuários e Jogos!\n\n");
}
