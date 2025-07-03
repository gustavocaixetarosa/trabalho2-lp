#include<limits.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


#define QTD_ALUNOS_TURMA 5
#define QTD_TURMAS 2


typedef struct vencQuadri {
    int maiorCarisma;
    int turmaCarisma;
    int maiorDestreza;
    int turmaDestreza;
} Quadri;

typedef struct bruxo {
    char nome[30];
    int inteligencia;
    int destreza;
    int carisma;
} Bruxo;

typedef struct equipePF {
    int aluno1;
    int aluno2;
    int aluno3;
    int destrezaEquipe;
} EquipePedra;

typedef struct turma {
    char nome[30];
    int pontos;
    Bruxo alunos[QTD_ALUNOS_TURMA];
} Turma;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

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
    limparBuffer();
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

int calcularSomaCarisma(Turma turma){
    int carismaTotal = 0;
    for(int i = 0; i < QTD_ALUNOS_TURMA; i++){
        carismaTotal += turma.alunos[i].carisma;
    }
    return carismaTotal;
}

int calcularSomaDestreza(Turma turma){
    int destrezaTotal = 0;
    for(int i = 0; i < QTD_ALUNOS_TURMA; i++){
        destrezaTotal += turma.alunos[i].destreza;
    }
    return destrezaTotal;
}

Quadri computaVencedoresQuadriLol(Turma turmas[]){
    Quadri vencedores;
    int somasCarismas[QTD_TURMAS], somasDestreza[QTD_TURMAS];
    vencedores.maiorCarisma = -1;
    vencedores.maiorDestreza = -1;

    for(int i = 0; i < QTD_TURMAS; i++){
        somasCarismas[i] = calcularSomaCarisma(turmas[i]);
        if(somasCarismas[i] > vencedores.maiorCarisma){
            vencedores.maiorCarisma = somasCarismas[i];
            vencedores.turmaCarisma = i;
        }
        
        somasDestreza[i] = calcularSomaDestreza(turmas[i]);
        if(somasDestreza[i] > vencedores.maiorDestreza){
            vencedores.maiorDestreza = somasDestreza[i];
            vencedores.turmaDestreza = i;
        }
    }
    return vencedores;
}

void anunciaVencedoresQuadri(Quadri vencedores, Turma turmas[]){
    printf("\n\nA disputa foi acirrada mas ja temos nossos vencedores...\n");
    printf("A frente a turma %s, os ganhadores com %d pontos do quesito carisma.Levaram pra casa 5 pontos! Deus tem seus preferidos...\n\n",
         turmas[vencedores.turmaCarisma].nome, vencedores.maiorCarisma);

    printf("Por outro lado, palmas para %s que se consagraram os mais ligeiros de toda Hogwarts! Venceram com incriveis %d pontos de destreza. Mais 10 pontos para eles. Parabens!!!\n\n",
        turmas[vencedores.turmaDestreza].nome, vencedores.maiorDestreza);
}

void distribuiPontosQuadri(Quadri vencedores, Turma turmas[]){
    turmas[vencedores.turmaCarisma].pontos += 5;
    turmas[vencedores.turmaDestreza].pontos += 10;
}

void quadriLol(Turma turmas[]){
    printf("Vai comecar o QUADRILOOOOOOOOL!!!!!\n");
    printf("Aqui, ganham as turmas mais carismaticas e de maior destreza! Boa sorte a todos!!\n");
    Quadri vencedores = computaVencedoresQuadriLol(turmas);
    anunciaVencedoresQuadri(vencedores, turmas);
    printf("Fim de mais um quadriLol. Ate o proximo!\n\n");
    distribuiPontosQuadri(vencedores, turmas);
}

void quadroDeDesafios(){
    printf("\n\n\n\n*#*#*# DESAFIOS #*#*#*\n\n\n\n");
    printf("**** 1. QuadriLOL                ****\n");
    printf("**** 2. Artes Arcanistas Arcanas ****\n");
    printf("**** 3. Pedra Floatzal           ****\n");
    printf("Escolha o desafio: ");
}

void sorteiaDuasTurmas(int *a, int *b){
    *a = rand() % QTD_TURMAS;
    do {
        *b = rand() % QTD_TURMAS;
    } while (*a == *b);
}

void sorteiaUmAlunoDaTurma(int *aluno){
    *aluno = rand() % QTD_ALUNOS_TURMA;
}

void artesArcanistasArcanas(Turma turmas[]){
    int turmaA, turmaB, alunoA, alunoB;
    sorteiaDuasTurmas(&turmaA, &turmaB);
    printf("\n\n\nTurmas sorteadas foram: %s contra %s!\n", turmas[turmaA].nome, turmas[turmaB].nome);
    sorteiaUmAlunoDaTurma(&alunoA);
    sorteiaUmAlunoDaTurma(&alunoB);
    printf("Temos nossos representantes! Pela turma %s, o bruxo %s. Do outro lado, %s da %s! Que venca o mais sabichao. RisosRisos\n\n",
        turmas[turmaA].nome, turmas[turmaA].alunos[alunoA].nome, turmas[turmaB].nome, turmas[turmaB].alunos[alunoB].nome);
    printf("Embate de inteligencias: \n");
    printf("%s : %d         %s : %d\n", turmas[turmaA].alunos[alunoA].nome, turmas[turmaA].alunos[alunoA].inteligencia,
         turmas[turmaB].alunos[alunoB].nome, turmas[turmaB].alunos[alunoB].inteligencia);

    if(turmas[turmaA].alunos[alunoA].inteligencia > turmas[turmaB].alunos[alunoB].inteligencia){
        printf("%s venceu o embate e conquistou 10 pontos para sua equipe. O desgracado e um genio!!!\n", turmas[turmaA].alunos[alunoA].nome);
        turmas[turmaA].pontos += 10;
    } else if(turmas[turmaB].alunos[alunoB].inteligencia > turmas[turmaA].alunos[alunoA].inteligencia){
        printf("%s venceu o embate e conquistou 10 pontos para sua equipe. O desgracado e um genio!!!\n", turmas[turmaB].alunos[alunoB].nome);
        turmas[turmaB].pontos += 10;
    } else {
        printf("Os dois sao bagres e conseguiram empatar. Vao pra casa!\n");
    }
}

void selecionaTresAlunos(EquipePedra *equipe){
    equipe->aluno1 = rand() % QTD_ALUNOS_TURMA;
    do {
        equipe->aluno2 = rand() % QTD_ALUNOS_TURMA;
    } while (equipe->aluno2 == equipe->aluno1);
    
    do {
        equipe->aluno3 = rand() % QTD_ALUNOS_TURMA;
    } while (equipe->aluno3 == equipe->aluno1 || equipe->aluno3 == equipe->aluno2);    
}

void calcularSomaDestrezaDaEquipe(EquipePedra *equipe, Turma turmas[], int numeroTurma){
    int destrezaTotal = 0;
    destrezaTotal += turmas[numeroTurma].alunos[equipe->aluno1].destreza;
    destrezaTotal += turmas[numeroTurma].alunos[equipe->aluno2].destreza;
    destrezaTotal += turmas[numeroTurma].alunos[equipe->aluno3].destreza;
    equipe->destrezaEquipe = destrezaTotal;
}

void zerarHabilidades(Turma turmas[], EquipePedra *equipe, int numeroEquipe){
    turmas[numeroEquipe].alunos[equipe->aluno1].carisma = 0;
    turmas[numeroEquipe].alunos[equipe->aluno1].inteligencia = 0;
    turmas[numeroEquipe].alunos[equipe->aluno1].destreza = 0;
    
    turmas[numeroEquipe].alunos[equipe->aluno2].carisma = 0;
    turmas[numeroEquipe].alunos[equipe->aluno2].inteligencia = 0;
    turmas[numeroEquipe].alunos[equipe->aluno2].destreza = 0;

    turmas[numeroEquipe].alunos[equipe->aluno3].carisma = 0;
    turmas[numeroEquipe].alunos[equipe->aluno3].inteligencia = 0;
    turmas[numeroEquipe].alunos[equipe->aluno3].destreza = 0;
}

bool equipeAchouAPedraFloatzal(){
    int numero = rand() % 10;
    if(numero == 0){
        return true;
    } else {
        return false;
    }
}

void pedraFloatzal(Turma turmas[]){
    printf("\n\n\n**** Desafio da Pedra Floatzal ****\n\n\n");
    EquipePedra equipes[QTD_TURMAS];
    int equipeComMenorDestreza, menorDestreza = INT_MAX, equipeEncontrouPedra = -1;
    for(int i = 0; i < QTD_TURMAS; i++){
        selecionaTresAlunos(&equipes[i]);
        calcularSomaDestrezaDaEquipe(&equipes[i], turmas, i);
        if(equipes[i].destrezaEquipe < menorDestreza){
            equipeComMenorDestreza = i;
            menorDestreza = equipes[i].destrezaEquipe;
        }
        printf("O carisma da turma %s e %d!\n", turmas[i].nome, equipes[i].destrezaEquipe); 
    }

    printf("Infelizmente a equipe dos %s foi pega pelo perigoso Valdechar(Aquele nao devemos pronunciar!!!)!\n", turmas[equipeComMenorDestreza].nome);
    printf("Por isso, todos os atributos da sua equipe foi completamente drenada!!\n");
    zerarHabilidades(turmas, &equipes[equipeComMenorDestreza], equipeComMenorDestreza);

    do {
        for(int i = 0; i < QTD_TURMAS; i++){
            if(i == equipeComMenorDestreza){
                continue;
            }
            if(equipeAchouAPedraFloatzal()){
                printf("A equipe %s encontrou a pedra floatzal!!! Palmas, por favor! Com isso, ganharam 20 grandes pontos!!!\n",
                turmas[i].nome);
                equipeEncontrouPedra = i;
                break;
            }
        }
    } while(equipeEncontrouPedra == -1);

    turmas[equipeEncontrouPedra].pontos += 20;
    printf("\n\n**** FIM DO DESAFIO DA PEDRA FLOATZ ****\n\n\n");
}

void executaDesafioEscolhido(int escolha, Turma turmas[]){
    switch (escolha)
    {
    case 1:
        quadriLol(turmas);
        break;
    case 2:
        artesArcanistasArcanas(turmas);
        break;
    case 3:
        pedraFloatzal(turmas);
        break;
    default:
        printf("Opcao nao encontrada. Tente novamente.\n");
    }
}

void zeraPontosDasTurmas(Turma turmas[]){
    for(int i = 0; i < QTD_TURMAS; i++){
        turmas[i].pontos = 0;
    }
}

void exibeQuadroDePontos(Turma turmas[]){
    printf("\n\n**** QUADRO DE PONTOS ****\n\n");
    for(int i = 0; i < QTD_TURMAS; i++){
        printf("Turma : %s\nPontos: %d\n\n", turmas[i].nome, turmas[i].pontos);
    }
}

int calculaEquipeVencedora(Turma turmas[]){
    int maiorPontos = -1, equipeVencedora;
    for(int i = 0; i < QTD_TURMAS; i++){
        if(turmas[i].pontos > maiorPontos){
            maiorPontos = turmas[i].pontos;
            equipeVencedora = i;
        }
    }
    return equipeVencedora;
}

void executarDesafios(Turma turmas[]){
    printf("\n\n\n**** DESAFIOS ****\n\n");
    printf("No total teremos 5 desafios de tirar o folego!\n");
    int desafio, equipeVencedora;
    zeraPontosDasTurmas(turmas);
    for(int i = 0; i < 5; i++){
        printf("%d desafio: ", i + 1);
        quadroDeDesafios();
        scanf("%d", &desafio);
        executaDesafioEscolhido(desafio, turmas);
        exibeQuadroDePontos(turmas);
    }

    equipeVencedora = calculaEquipeVencedora(turmas);
    printf("Com o fim dos desafios, temos a nossa campea!!!\n\n");
    printf("Muito barulho e palmas para a turma %s que venceu os desafios com o total de %d pontos!!!\n\n Clap* Clap*(Todo mundo aplaudindo...)\n\n",
        turmas[equipeVencedora].nome, turmas[equipeVencedora].pontos);
}

void dadosDasTurmas(Turma turmas[]){
    printf("\n\n**** DADOS DAS TURMAS ****\n\n");
    for(int i = 0; i < QTD_TURMAS; i++){
        printf("Turma %s\n", turmas[i].nome);
        printf("Alunos: ");
        for(int j = 0; j < QTD_ALUNOS_TURMA; j++){
            printf("Nome: %s ", turmas[i].alunos[j].nome);
        }
        printf("\n");
    }
}

void exibeNomeTodasTurmas(Turma turmas[]){
    for(int i = 0; i < QTD_TURMAS; i++){
        printf("\n%d. %s\n", i + 1, turmas[i]);
    }
}

void exibeDadosTurma(Turma *turma){
    printf("\nTurma %s\n", turma->nome);
    for(int i = 0; i < QTD_ALUNOS_TURMA; i++){
        printf("Aluno: %s   Inteligencia: %d   Destreza: %d   Carisma: %d\n", turma->alunos[i].nome, turma->alunos[i].inteligencia, turma->alunos[i].destreza, turma->alunos[i].carisma);
    }
}

void dadosAlunos(Turma turmas[]){
    int turmaEscolhida;
    printf("Escolha uma turma para ver os dados dos seus alunos: ");
    exibeNomeTodasTurmas(turmas);
    scanf("%d", &turmaEscolhida);
    turmaEscolhida -= 1;
    exibeDadosTurma(&turmas[turmaEscolhida]);
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

int mostrarMenu(){
    int opcao;
    header();
    printf("**** 1. Cadastrar Turmas  ****\n");
    printf("**** 2. Desafios          ****\n");
    printf("**** 3. Dados das Turmas  ****\n");
    printf("**** 4. Dados dos Alunos  ****\n");
    printf("**** 5. Sair              ****\n");
    printf("Entre com a funcao desejada: ");
    scanf("%d", &opcao);
    return opcao;
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