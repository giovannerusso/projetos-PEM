#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <string.h>

bool calculoDigito(int cnpj[], int mult[], int N) {
	int soma = 0, i, resto = 0;
	for (i = 0; i < N; i++) {
		soma = soma + cnpj[i] * mult[i];
	}
	
	resto = soma%11;
	
	if (resto <= 2) {
		resto = 0;
	}
	else {
		resto = 11 - resto;
	}
	
	if (resto == cnpj[N]) {
		return true;
	}
	else {
		return false;
	}
}

void lerCNPJ(int cnpj[]) {
	char texto[50];
	int i, j = 13;
	
	fgets(texto, 50, stdin);
	
	for (i = strlen(texto) - 1; i>=0 ; i--) {
		if (texto[i] >= '0' && texto[i] <= '9') {
			cnpj[j] = texto[i] - '0';
			j--;
 		}
	}
	//Preenchendo com 0 a esquerda em caso de CNPJ com menos de 14 dígitos
	while (j >= 0) {
		cnpj[j] = 0;
		j--;
	}
}

void imprimeCNPJ(int cnpj[]) {
	int i;
	printf("\n");
	 for(i=0; i<14;i++) {
        printf("%d", cnpj[i]);
        if (i==1 || i == 4) 
        	printf(".");
        if (i == 7)
        	printf("/");
        if (i == 11)
        	printf("-");
    }
}

int main() {
	setlocale (LC_ALL, "Portuguese");
	
	int cnpj[14];
	int m1[12]={5,4,3,2,9,8,7,6,5,4,3,2};
	int m2[13]={6,5,4,3,2,9,8,7,6,5,4,3,2};
	int i;
	
	printf("Entre com o CNPJ:");
	lerCNPJ(cnpj);
	
	if (calculoDigito(cnpj, m1, 12) && calculoDigito(cnpj, m2, 13)) {
		printf("CNPJ Válido.");
		imprimeCNPJ(cnpj);
	}
	else {
		printf("CNPJ Inválido.");
	}
	
	
	return 0;
}
