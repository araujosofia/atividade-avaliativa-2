#include <stdio.h>


int validaQuantidade() {
    int quantidade;
    do {
        printf("Digite a quantidade de peças fabricadas: ");
        scanf("%d", &quantidade);

        if (quantidade < 0) {
            printf("Quantidade inválida. Digite um valor maior ou igual a zero.\n");
        }
    } while (quantidade < 0);

    return quantidade;
}


float calculaSalario(int quantidade) {
    const float salarioBase = 600.0;
    const int limite1 = 50;
    const int limite2 = 80;
    const float adicional1 = 0.50;
    const float adicional2 = 0.75;

    float salarioTotal = salarioBase;

    if (quantidade > limite1) {
        if (quantidade <= limite2) {
            salarioTotal += (quantidade - limite1) * adicional1;
        } else {
            salarioTotal += (limite2 - limite1) * adicional1;
            salarioTotal += (quantidade - limite2) * adicional2;
        }
    }

    return salarioTotal;
}


void mostraFinal(float salarioTotal) {
    printf("O salário total é: R$ %.2f\n", salarioTotal);
}

int main() {
    char continuar;
    
    do {
        int quantidade = validaQuantidade();
        float salarioTotal = calculaSalario(quantidade);
        mostraFinal(salarioTotal);

        printf("Deseja calcular o salário de outro funcionário? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
