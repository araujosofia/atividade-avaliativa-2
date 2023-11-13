#include <stdio.h>


char obterSexo() {
    char sexo;
    do {
        printf("Digite o sexo (M/F): ");
        scanf(" %c", &sexo);
    } while (sexo != 'M' && sexo != 'm' && sexo != 'F' && sexo != 'f');

    return sexo;
}


float obterSalario() {
    float salario;
    do {
        printf("Digite o salário (maior que R$1,00): ");
        scanf("%f", &salario);
    } while (salario <= 1.0);

    return salario;
}


void classificarSalario(float salario) {
    const float salarioMinimo = 1400.0;

    if (salario > salarioMinimo) {
        printf("Classificação: Acima do salário mínimo\n");
    } else if (salario == salarioMinimo) {
        printf("Classificação: Igual ao salário mínimo\n");
    } else {
        printf("Classificação: Abaixo do salário mínimo\n");
    }
}


void mostrarResultados(float salario, char sexo) {
    printf("Salário: R$ %.2f\n", salario);

    if (sexo == 'M' || sexo == 'm') {
        printf("Sexo: Masculino\n");
    } else {
        printf("Sexo: Feminino\n");
    }
}

int main() {
    char continuar;
    
    do {
        char sexo = obterSexo();
        float salario = obterSalario();

        classificarSalario(salario);
        mostrarResultados(salario, sexo);

        printf("Deseja cadastrar outro assalariado? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}
