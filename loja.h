
struct Usuario {
    char nome[50];
    char senha[50];
    char email[80];
};

struct Jogo {
    char nome[50];
    float preco;
};

typedef struct NoUsuario {
    struct Usuario usuario;
    struct NoUsuario* prox;
} NoUsuario;

typedef struct NoJogo {
    struct Jogo jogo;
    struct NoJogo* prox;
} NoJogo;

void login(struct Usuario usuario);
int verificar_email(char* email, NoUsuario* lista);
NoUsuario* inserir_usuario(NoUsuario* lista, struct Usuario usuario);
void cadastrar_email(NoUsuario** lista);
NoJogo* inserir_jogo(NoJogo* lista, struct Jogo jogo);
void adicionar_jogo(NoJogo** lista);
struct Jogo* buscar_jogo(NoJogo* lista, char* nome);
void pesquisar_jogo(NoJogo* lista);
NoJogo* remover_jogo(NoJogo* lista, char* nome);
NoJogo* criar_lista_promocao(NoJogo* lista);
NoJogo* ordenar_jogos(NoJogo* lista);
void liberar_lista_usuarios(NoUsuario* lista);
void liberar_lista_jogos(NoJogo* lista);
void alterar_usuario(struct Usuario* usuario);
void alterar_senha(struct Usuario* usuario);
void mensagem_boas_vindas();


