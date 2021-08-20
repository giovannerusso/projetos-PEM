#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool calculoDigito(int cpf[], int mult[], int N) {
	int soma = 0, i, resto = 0;
	for (i = 0; i < N; i++) {
		soma = soma + cpf[i] * mult[i];
	}
	
	resto = ((soma*10)%11)%10;
	
	if (resto == cpf[N]) {
		return true;
	}
	else {
		return false;
	}
}

bool repetidos(int cpf[]) {
	int i;
	for (i = 1; i < 11; i++) {
		if (cpf[0] != cpf[i]) {
			return false;
		}
	}
	return true;
}

void verificaRegiao(int cpf[]) {
	switch (cpf[8]) {
		case 0: 
			printf("Rio Grande do Sul");
			break;
	    case 1: 
			printf("Distrito Federal, Goiás, Mato Grosso, Mato Grosso do Sul e Tocantins");
			break;
	    case 2: 
			printf("Amazonas, Pará, Roraima, Amapá, Acre e Rondônia");
			break;
	    case 3: 
			printf("Ceará, Maranhão e Piauí");
			break;
	    case 4: 
			printf("Paraíba, Pernambuco, Alagoas e Rio Grande do Norte");
			break;
	    case 5: 
			printf("Bahia e Sergipe");
			break;
	    case 6: 
			printf("Minas Gerais");
			break;
	    case 7: 
			printf("Rio de Janeiro e Espírito Santo");
			break;
	    case 8: 
			printf("São Paulo");
	    	break;
	    case 9: 
			printf("Paraná e Santa Catarina");
			break;
	}
}

int main() {   
	setlocale (LC_ALL, "Portuguese");
	
	int cpf[11];
	int m1[9]={10,9,8,7,6,5,4,3,2};
	int m2[10]={11,10,9,8,7,6,5,4,3,2};
	int i;
	
	printf("Entre com os 11 digitos do CPF:");
	for(i=0;i<11;i++) {	
		scanf("%d", &cpf[i]);
	}
	
	if (repetidos(cpf) == false && calculoDigito(cpf, m1, 9) && calculoDigito(cpf, m2, 10)) {
		printf("\nCPF válido.");
		printf("\nEstado de Origem: ");
		verificaRegiao(cpf);
	}
	else {
		printf("\nCPF inválido.");
	}

	return 0;
}
