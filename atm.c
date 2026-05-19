#include <stdio.h>

/* ============================================================
   PROTÓTIPOS — declara as funções antes do main
   ============================================================ */
void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void registrarOperacao(char tipo, float valor);
void exibirExtrato(float saldo);


/* ============================================================
   HISTÓRICO GLOBAL — 3 slots para tipo e valor
   Usamos variáveis globais aqui para que todas as funções
   consigam acessar e atualizar o histórico sem precisar
   passar vários parâmetros.
   ============================================================ */
char  tipoOp[3]  = {' ', ' ', ' '}; /* 'S' = Saque, 'D' = Deposito */
float valorOp[3] = {0.0, 0.0, 0.0};


/* ============================================================
   MAIN
   ============================================================ */
int main() {
    int opcao; 
    system("cls");
    exibirMenu();
    scanf("%d", &opcao);
    while (getchar() != '\n');
    if(opcao <0 || opcao > 3){
        printf("Opcao invalida... tente novamente\n");
    }

    /* TODO: declare a variável saldo com valor inicial R$500.00 */
    float saldo = 500.0;

    int opcao;

    /* TODO: implemente o loop do-while que mantém o sistema rodando
       enquanto opcao != 0 */
    do {

        /* TODO: chame exibirMenu() aqui */

        /* TODO: leia a opção do usuário com scanf */

        /* TODO: limpe o buffer do teclado com:
           while (getchar() != '\n'); */

        /* TODO: implemente o switch-case com os casos:
           1 - Consultar Saldo   → consultarSaldo(saldo)
           2 - Realizar Saque    → saldo = realizarSaque(saldo)
           3 - Realizar Deposito → saldo = realizarDeposito(saldo)
           4 - Extrato           → exibirExtrato(saldo)
           0 - Sair              → printf de despedida
           default               → printf de opção inválida        */

    } while (opcao != 0);

    return 0;
}


/* ============================================================
   exibirMenu
   Apenas imprime as opções na tela. Não recebe nem retorna nada.
   ============================================================ */
void exibirMenu() {

    printf("\n========ATM=======\n");
    printf("Selecione as opcoes abaixo: \n");
    printf("1 - Consultar saldo\n");
    printf("2 -  Realizar saque\n");
    printf("3 - Realizar deposito\n");
    printf("0 - Encerrar o programa\n"); 
    printf("Digite uma das opcoes: ");

}


/* ============================================================
   consultarSaldo
   Recebe o saldo por valor (cópia) e apenas exibe.
   Não altera nada, por isso retorno void.
   ============================================================ */
void consultarSaldo(float saldo) {
    /* TODO: imprima o saldo formatado com %.2f */

    /* TODO: pause para o usuário ler:
       printf("\nPressione Enter para continuar...");
       getchar();                                    */
}


/* ============================================================
   realizarSaque
   Recebe saldo atual, pede valor ao usuário,
   valida (valor > 0 E valor <= saldo) e retorna saldo atualizado.
   ============================================================ */
float realizarSaque(float saldo) {
    float valor;

    /* TODO: peça o valor do saque com printf + scanf */

    /* TODO: valide:
       - se valor <= 0           → "Valor invalido!"
       - se valor > saldo        → "Saldo insuficiente!"
       - se tudo ok              → subtraia do saldo,
                                   chame registrarOperacao('S', valor),
                                   confirme ao usuário               */

    /* TODO: pause para o usuário ler */

    return saldo;
}


/* ============================================================
   realizarDeposito
   Recebe saldo atual, pede valor ao usuário,
   valida (valor > 0) e retorna saldo atualizado.
   ============================================================ */
float realizarDeposito(float saldo) {
    float valor;

    /* TODO: peça o valor do depósito com printf + scanf */

    /* TODO: valide:
       - se valor <= 0  → "Valor invalido!"
       - se tudo ok     → some ao saldo,
                          chame registrarOperacao('D', valor),
                          confirme ao usuário                  */

    /* TODO: pause para o usuário ler */

    return saldo;
}


/* ============================================================
   registrarOperacao
   Faz o SHIFT do histórico e insere a nova operação no slot [2].
   Exemplo de shift:
       tipoOp[0]  = tipoOp[1];
       tipoOp[1]  = tipoOp[2];
       tipoOp[2]  = tipo;       ← nova operação entra aqui
   Faça o mesmo para valorOp.
   ============================================================ */
void registrarOperacao(char tipo, float valor) {
    /* TODO: implemente o shift para tipoOp  */

    /* TODO: implemente o shift para valorOp */
}


/* ============================================================
   exibirExtrato
   Percorre os 3 slots e exibe tipo + valor de cada operação.
   Se tipoOp[i] == ' ', significa que o slot está vazio
   (nenhuma operação foi feita ainda).
   ============================================================ */
void exibirExtrato(float saldo) {
    printf("\n========== EXTRATO ==========\n");

    /* TODO: use um loop (for de i=0 até i<3) para percorrer os slots.
       Para cada slot:
       - se tipoOp[i] == ' '  → printf("Sem operacao\n")
       - se tipoOp[i] == 'S'  → printf("Saque:    R$ %.2f\n", valorOp[i])
       - se tipoOp[i] == 'D'  → printf("Deposito: R$ %.2f\n", valorOp[i]) */

    /* TODO: ao final exiba o saldo atual */

    printf("=============================\n");

    /* TODO: pause para o usuário ler */
}