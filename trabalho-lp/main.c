#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define QTD_ALUNOS_TURMA 5
#define QTD_TURMAS 4


typedef struct bruxo {
    char nome[30];
    int inteligencia;
    int destreza;
    int carisma;
} Bruxo;

typedef struct turma {
    char nome[30];
    int pontos;
    Bruxo alunos[QTD_ALUNOS_TURMA];
} Turma;


int habilidadeAleatoria(){
    return rand() % 6;    
}

Bruxo cadastrarBruxo(){
    Bruxo aluno;
    printf("\n\n\n### CADASTRANDO BRUXO ###\n");
    printf("\nNome do bruxo: ");
    gets(aluno.nome);
    aluno.destreza = habilidadeAleatoria();
    printf("\nDestreza do aluno %s: %d\n", aluno.nome, aluno.destreza);
    aluno.carisma = habilidadeAleatoria();
    printf("\nCarisma do aluno %s: %d\n", aluno.nome, aluno.carisma);
    aluno.inteligencia = habilidadeAleatoria();
    printf("\nInteligencia do aluno %s: %d\n", aluno.nome, aluno.inteligencia);
    printf("\nAluno cadastrado com sucesso!\n\n");
    return aluno;
}

Turma cadastrarTurma(){
    Turma novaTurma;
    printf("\n\n\n### CADASTRANDO TURMA ###\n");
    printf("\nNome da turma: ");
    gets(novaTurma.nome);
    novaTurma.pontos = 0;

    for(int i = 0; i < QTD_ALUNOS_TURMA; i++){
        printf("\nCadastrando %d aluno: ", i + 1);
        novaTurma.alunos[i] = cadastrarBruxo();
    }
    
    printf("\nTurma %s cadastrada com sucesso!\n", novaTurma.nome);
    return novaTurma;
}

void cadastrarTurmas(Turma turmas[]){
    printf("\n### CADASTRANDO TODAS AS TURMAS ###\n");
    for(int i = 0; i < QTD_TURMAS; i++){
        printf("\nInicializando %d turma: ", i + 1);
        turmas[i] = cadastrarTurma();
    }
    printf("\nTodas turmas cadastradas com sucesso!");
}

int main(){
    srand(time(NULL));
    Turma turmas[QTD_TURMAS];
    cadastrarTurmas(turmas);
    return 0;
}