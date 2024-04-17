#include <stdio.h>

void conversao(char cpf[11]){
    int cpf_num[11];
    for(int i=0; i<11; i++){
        cpf_num[i] = cpf[i] - '0'; //converte o caractere para o número
    }
    calculo(cpf_num);
}

void calculo(int cpf[11]){
    int resto;
    int dig_ver1, dig_ver2;
    //Dígito verificador 1
    resto = soma(0,9,cpf);
    if(resto < 2)
        dig_ver1 = 0;
    else
        if(resto >= 2)
            dig_ver1 = 11-resto;
    //Dígito verificador 2
    resto = soma(1,10,cpf);
    if(resto < 2)
        dig_ver2 = 0;
    else
        if(resto >= 2)
            dig_ver2 = 11-resto;
    //comparação
    if(dig_ver1 == cpf[9] && dig_ver2 == cpf[10])
        printf("\n\tCPF valido!\n");
    else
        printf("\n\tCPF invalido!\n");
}

int soma(int inicio, int fim, int cpf[11]){
    int soma = 0, contador = 10;
    for(int i=inicio; i<fim; i++){
        soma += cpf[i]*contador;
        contador--;
    }
    return soma%11;
}

int main(){
    char cpf[12];
    printf("Digite os 11 digitos do CPF (somente numeros): ");
    scanf("%s", cpf);
    conversao(cpf);
    return 0;
}
