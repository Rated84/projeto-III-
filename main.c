#include <stdio.h>
#include <stdlib.h>
#include "loja.h"

int main() {
    NoUsuario* usuarios = NULL;
    NoJogo* jogos = NULL;

    mensagem_boas_vindas();

    while (1) {
        printf("\n1. Cadastrar email\n2. Adicionar jogo\n3. Pesquisar jogo\n4. Remover jogo\n5. Sair\nEscolha: ");
        int opcao;
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: cadastrar_email(&usuarios); break;
            case 2: adicionar_jogo(&jogos); break;
            case 3: pesquisar_jogo(jogos); break;
            case 4: jogos = remover_jogo(jogos, "nome"); break;
            case 5: liberar_lista_usuarios(usuarios); liberar_lista_jogos(jogos); return 0;
            default: printf("Opção inválida!\n");
        }
    }
}
