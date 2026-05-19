#include <stdio.h>
void exibirMenu();
void consultarSaldo(float saldo);
float realizarSaque(float saldo);
float realizarDeposito(float saldo);
void registrarOperacao(char tipo, float valor);
void exibirExtrato(float saldo);

char  tipoOp[3]  = {' ', ' ', ' '}; 
float valorOp[3] = {0.0, 0.0, 0.0};



int main() {
    float saldo = 500.0;
    int opcao; 
    do {
        system("cls");
        exibirMenu();
        scanf("%d", &opcao);
        if(opcao <0 || opcao > 4){
            printf("Opcao invalida... tente novamente\n");
        }
        while (getchar() != '\n');

        switch(opcao){
            case 1: 
            printf("Opcao 1, Consultar saldo, selecionada\n");
            consultarSaldo(saldo);
            break;

            case 2: 
            printf("Opcao 2, Realizar saque, selecionada\n");
            saldo = realizarSaque(saldo);
            break;

            case 3:
            printf("Opcao 3, Realizar deposito, selecionada\n"); 
            saldo = realizarDeposito(saldo);
            break;

            case 4: 
            printf("Opcao 4, Ver o extrato, selecionada\n");
            exibirExtrato(saldo); 
            break;

            case 0: 
            printf("Opcao Sair selecionada...\n");
            printf("Obrigado por usar nossa ATM\n");
            printf("Ate logo...\n");
            break;

            default:
            printf("Opcao invalida... tente novamente\n");
        }

    } while (opcao != 0);

    return 0;
}

void exibirMenu() {

    printf("\n========ATM=======\n");
    printf("Selecione as opcoes abaixo: \n");
    printf("1 - Consultar saldo\n");
    printf("2 -  Realizar saque\n");
    printf("3 - Realizar deposito\n");
    printf("4 - Ver o extrato\n");
    printf("0 - Encerrar o programa\n"); 
    printf("Digite uma das opcoes: ");

}


void consultarSaldo(float saldo) {
    printf("Saldo disponivel %.2f\n", saldo);

    printf("Precione Enter para continuar...");
    getchar();
    printf("\n");


}

float realizarSaque(float saldo) {
    float valor;
    int sucesso = 0;
    
    do {
        printf("Digite o valor que deseja sacar: ");
        scanf("%f", &valor);
        while(getchar() != '\n');
        
        if(valor <= 0) {
            printf("Valor invalido... tente novamente\n");
        }
        else if(valor > saldo) {
            printf("Saldo insuficiente... tente novamente\n");
        }
        else {
            printf("Saque de R$ %.2f realizado\n", valor);
            saldo -= valor;
            registrarOperacao('S', valor);
            sucesso = 1;
        }
    } while(sucesso == 0);

    return saldo;
}

float realizarDeposito(float saldo) {
    float valor;

    do{
        printf("Digite o valor que deseja depositar: ");
        scanf("%f", &valor);
        while(getchar() != '\n');
        if(valor <= 0){
            printf("Valor invalido, tente novamente...\n"); 
        }
        else{
            printf("Valor depositado: %.2fR$\n", valor);
            saldo += valor; 
            registrarOperacao('D', valor);
        }
    }while(valor <= 0);

    return saldo;
}


void registrarOperacao(char tipo, float valor) {
    tipoOp[0]  = tipoOp[1];
    tipoOp[1]  = tipoOp[2];
    tipoOp[2]  = tipo;

    valorOp[0] = valorOp[1];
    valorOp[1] = valorOp[2];
    valorOp[2] = valor;
}

void exibirExtrato(float saldo) {
    int i;
    printf("\n========== EXTRATO ==========\n");
    for(i = 0; i < 3; i++){
        if(tipoOp[i] == ' '){
            printf("Sem operacao\n"); 
        }
        else if(tipoOp[i] == 'S'){
            printf("Saque realizado; valor: %.2fR$\n", valorOp[i] );
        }
        else if (tipoOp[i] == 'D'){
            printf("Deposito realizado; valor: %.2fR$\n", valorOp[i]);
        }
        else{
            printf("ERRO!");
        }
        }
    printf("Saldo atual %.2fR$\n", saldo); 
    printf("=============================\n");
    printf("Pressione Enter para continuar:\n");
    getchar();
}