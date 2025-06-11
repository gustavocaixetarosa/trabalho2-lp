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
    printf("\nDestreza do aluno %s: %d", aluno.nome, aluno.destreza);
    aluno.carisma = habilidadeAleatoria();
    printf("\nCarisma do aluno %s: %d", aluno.nome, aluno.carisma);
    aluno.inteligencia = habilidadeAleatoria();
    printf("\nInteligencia do aluno %s: %d", aluno.nome, aluno.inteligencia);
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
    
    printf("\nTurma %s cadastrada com sucesso!", novaTurma.nome);
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

void header(){
    printf("\n\n\n\n#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
    printf("#*#*#*#* Gerenciador Ultra Mega Blaster da Escola de Bruxos 2.3 *#*#*#*#\n");
    printf("#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*#*\n");
    printf("                    manufaturado por: Wesley, Saulo, Alejandro e Gustavo\n\n\n\n");   
}

int mostrarMenu(){
    int opcao;
    header();
    printf("**** 1. Cadastrar Turmas  ****\n");
    printf("**** 2. Executar Desafios ****\n");
    printf("**** 3. Dados das Turmas  ****\n");
    printf("**** 4. Dados dos Alunos  ****\n");
    printf("**** 5. Sair              ****\n");
    printf("Entre com a funcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
}

void executarDesafios(Turma turmas[]){

}

void dadosDasTurmas(Turma turmas[]){

}

void dadosAlunos(Turma turmas[]){

}

void sair(){
    printf("Saindo...\n");
    exit(0);
}

void funcoes(int opcao, Turma turmas[]){
    switch (opcao){
        case 1:
            cadastrarTurmas(turmas);
            break;
        case 2:
            executarDesafios(turmas);
            break;
        case 3:
            dadosDasTurmas(turmas);
            break;
        case 4:
            dadosAlunos(turmas);
            break;
        case 5:
            sair();
            break;
        default:
            printf("Funcao nao encontrada. Tente novamente!\n");
        }
}

int main(){
    srand(time(NULL));
    Turma turmas[QTD_TURMAS];
    int opcao = 0;

    do {
        opcao = mostrarMenu();
        funcoes(opcao, turmas);
    } while(opcao != -1);

    return 0;
}