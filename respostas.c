/*
 * Respostas das questoes de structs em C
 * Compilar: gcc respostas.c -o respostas -lm
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

/* ---------- Questao 1: novos tipos ---------- */

typedef struct {
    int hora;
    int minutos;
    int segundos;
} Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    Data data;
    Horario horario;
    char texto[100];
} Compromisso;

/* ---------- Questao 2: pessoa ---------- */

struct Pessoa {
    char nome[50];
    int idade;
    char endereco[100];
};

/* ---------- Questao 3: vetor no R3 ---------- */

struct Vetor {
    double x;
    double y;
    double z;
};

/* ---------- Questao 4: polar e cartesiano ---------- */

struct Polar {
    double r;
    double a;  /* argumento em radianos */
};

struct Cartesiano {
    double x;
    double y;
};

/* Descarta o que sobrou na linha de entrada (ex.: o Enter) */
void limpar_entrada(void) {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {
    }
}

void questao1(void) {
    Compromisso c;

    c.data.dia = 27;
    c.data.mes = 10;
    c.data.ano = 2026;
    c.horario.hora = 14;
    c.horario.minutos = 30;
    c.horario.segundos = 0;
    strcpy(c.texto, "Prova de Logica");

    printf("\n--- Questao 1 ---\n");
    printf("Compromisso: %s\n", c.texto);
    printf("Data: %02d/%02d/%04d\n", c.data.dia, c.data.mes, c.data.ano);
    printf("Horario: %02d:%02d:%02d\n",
           c.horario.hora, c.horario.minutos, c.horario.segundos);
}

void questao2(void) {
    struct Pessoa p;

    printf("\n--- Questao 2 ---\n");

    printf("Nome: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = '\0';

    printf("Idade: ");
    scanf("%d", &p.idade);
    limpar_entrada();

    printf("Endereco: ");
    fgets(p.endereco, sizeof(p.endereco), stdin);
    p.endereco[strcspn(p.endereco, "\n")] = '\0';

    printf("\nDados armazenados:\n");
    printf("Nome: %s\n", p.nome);
    printf("Idade: %d\n", p.idade);
    printf("Endereco: %s\n", p.endereco);
}

void questao3(void) {
    struct Vetor a, b, soma;

    printf("\n--- Questao 3 ---\n");

    printf("Vetor A (x y z): ");
    scanf("%lf %lf %lf", &a.x, &a.y, &a.z);
    limpar_entrada();

    printf("Vetor B (x y z): ");
    scanf("%lf %lf %lf", &b.x, &b.y, &b.z);
    limpar_entrada();

    soma.x = a.x + b.x;
    soma.y = a.y + b.y;
    soma.z = a.z + b.z;

    printf("Soma = (%.2lf, %.2lf, %.2lf)\n", soma.x, soma.y, soma.z);
}

void questao4(void) {
    struct Polar p;
    struct Cartesiano c;

    printf("\n--- Questao 4 ---\n");

    printf("Raio (r): ");
    scanf("%lf", &p.r);
    printf("Argumento (a) em radianos: ");
    scanf("%lf", &p.a);
    limpar_entrada();

    c.x = p.r * cos(p.a);
    c.y = p.r * sin(p.a);

    printf("Cartesiano: (%.4lf, %.4lf)\n", c.x, c.y);
}

int main(void) {
    int opcao;

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Novos tipos (Horario, Data, Compromisso)\n");
        printf("2 - Ler pessoa\n");
        printf("3 - Soma de vetores\n");
        printf("4 - Polar para cartesiano\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            break;
        }
        limpar_entrada();

        switch (opcao) {
            case 1: questao1(); break;
            case 2: questao2(); break;
            case 3: questao3(); break;
            case 4: questao4(); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
