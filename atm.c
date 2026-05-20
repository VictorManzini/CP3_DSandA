#include <stdio.h>
#include <stdlib.h>
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
        system("clear"); //Para Mac e Linux
        //system("cls");  //para Windows
        exibirMenu();
        scanf("%d", &opcao);
        if(opcao <0 || opcao > 4){
            printf("Opcao invalida... tente novamente\n");
        }
        while (getchar() != '\n');

        switch(opcao){
            case 1: 
            printf("\nOpcao 1, Consultar saldo, selecionada\n");
            consultarSaldo(saldo);
            break;

            case 2: 
            printf("\nOpcao 2, Realizar saque, selecionada\n");
            saldo = realizarSaque(saldo);
            break;

            case 3:
            printf("\nOpcao 3, Realizar deposito, selecionada\n"); 
            saldo = realizarDeposito(saldo);
            break;

            case 4: 
            printf("\nOpcao 4, Ver o extrato, selecionada\n");
            exibirExtrato(saldo); 
            break;

            case 0: 
            printf("\nOpcao Sair selecionada...\n");
            printf("Obrigado por usar nossa ATM\n");
            printf("Ate logo...\n");
            break;

            default:
            printf("Opcao invalida... tente novamente\n");
        }

    } while (opcao != 0);

    return 0;
}
//Exibe o menu para o usuario
void exibirMenu() {

    printf("\n========ATM=======\n");
    printf("Selecione as opcoes abaixo: \n");
    printf("1 - Consultar saldo\n");
    printf("2 - Realizar saque\n");
    printf("3 - Realizar deposito\n");
    printf("4 - Ver o extrato\n");
    printf("0 - Encerrar o programa\n"); 
    printf("Digite uma das opcoes: ");

}

//Consulta o saldo e exibe
void consultarSaldo(float saldo) {
    printf("Saldo disponivel %.2f\n", saldo);
    printf("\n");
    printf("Pressione Enter para continuar...");
    getchar();
    printf("\n");


}

//simula um saque de ATM
float realizarSaque(float saldo) {
    float valor;
    int sucesso = 0;
    
    do {
        printf("\nDigite o valor que deseja sacar: ");
        scanf("%f", &valor);
        while(getchar() != '\n');
        
        if(valor <= 0) {
            printf("Valor invalido... tente novamente\n");
        }
        else if(valor > saldo) {
            printf("\nSaldo insuficiente... tente novamente\n");
        }
        else {
            printf("Saque de R$ %.2f realizado\n", valor);
            saldo -= valor;
            registrarOperacao('S', valor);
            sucesso = 1;
        }
    } while(sucesso == 0);
    printf("\nPressione Enter para continuar...\n");
    getchar();

    return saldo;
}

//simula um deposito em uma ATM, adicionando o valor depositado ao saldo
float realizarDeposito(float saldo) {
    float valor;
    int sucesso = 0;

    do {
        printf("\nDigite o valor que deseja depositar: ");
        scanf("%f", &valor);
        while(getchar() != '\n');
        if(valor <= 0) {
            printf("\nValor invalido, tente novamente...\n");
        } else {
            printf("\nValor depositado: R$ %.2f\n", valor);
            saldo += valor;
            registrarOperacao('D', valor);
            sucesso = 1;
        }
    } while(sucesso == 0);
    printf("Pressione Enter para continuar...\n");
    getchar();

    return saldo;
}
//Registro das ultimas 3 operacoes
void registrarOperacao(char tipo, float valor) {
    tipoOp[0]  = tipoOp[1];
    tipoOp[1]  = tipoOp[2];
    tipoOp[2]  = tipo;

    valorOp[0] = valorOp[1];
    valorOp[1] = valorOp[2];
    valorOp[2] = valor;
}

//Printa o extrato das ultimas 3 operacoes
void exibirExtrato(float saldo) {
    int i;
    printf("\n========== EXTRATO ==========\n");
    for(i = 0; i < 3; i++){
        if(tipoOp[i] == ' '){
            printf("Sem operacao\n"); 
        }
        else if(tipoOp[i] == 'S'){
            printf("Saque realizado; valor: R$%.2f\n", valorOp[i] );
        }
        else if (tipoOp[i] == 'D'){
            printf("Deposito realizado; valor: R$%.2f\n", valorOp[i]);
        }
        else{
            printf("\nERRO!\n");
        }
        }
    printf("Saldo atual: R$%.2f\n", saldo); 
    printf("=============================\n");
    printf("Pressione Enter para continuar:\n");
    getchar();
}