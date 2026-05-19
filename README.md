# Sistema ATM em C

## Integrantes
- Victor Do Prado Manzini

---

## Descrição do Sistema
Sistema de Caixa Eletrônico (ATM) desenvolvido em linguagem C, simulando as operações básicas de um banco via interface de console. O sistema mantém o saldo ativo durante a sessão e registra o histórico das últimas 3 operações realizadas.

---

## Funcionalidades Implementadas
- **Consultar Saldo** — exibe o saldo disponível atual
- **Realizar Saque** — solicita valor, valida saldo suficiente e atualiza o saldo
- **Realizar Depósito** — solicita valor, valida entrada positiva e atualiza o saldo
- **Extrato** — exibe as últimas 3 operações realizadas (tipo e valor) e o saldo atual
- **Validação de entradas** — rejeita valores negativos, zero e saques acima do saldo
- **Menu interativo** — loop contínuo até o usuário escolher sair

---

## Instruções de Compilação e Execução

### Pré-requisitos
- GCC instalado

### Compilar
```bash
gcc atm.c -o atm
```

### Executar
```bash
./atm
```

> **Nota:** o sistema usa `system("clear")` para limpar a tela, compatível com Mac e Linux. Para Windows, substituir por `system("cls")` no arquivo `atm.c`.

---

## Histórico de Commits

| Hash | Descrição | Autor | Data |
|------|-----------|-------|------|
| `48b085a` | Esqueleto do projeto ATM | VictorManzini | 19/05/2026 |
| `483e4a5` | Add MIT License to the project | VictorManzini | 19/05/2026 |
| `3ce8527` | Adicionado funções: registrarOperacao(); realizarDeposito(); realizarSaque(); exibir menu() | VictorManzini | 19/05/2026 |
| `7de85a4` | Finalizado o arquivo atm.c | VictorManzini | 19/05/2026 |
| `1916eb5` | Testado o codigo atm.c | VictorManzini | 19/05/2026 |