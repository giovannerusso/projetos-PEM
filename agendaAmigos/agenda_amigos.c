
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
	char email[30];
	char dt_nascimento [10];
	bool ativo;
};

int procurar(char procurado[], struct ficha vetor[], int num_fichas) {
	int i;
	for(i=0; i<num_fichas; i++) {
		if(strstr(vetor[i].nome, procurado) != NULL) {
			return i;
		}
	}
	return -1;
}

void alterar(struct ficha vetor[], int n) {
	char op_alterar[10] = "0";
	printf("Qual informação você deseja alterar?\n1 - Nome;\n2 - Nº de Telefone;\n3 - Email;\n4 - Data de Nascimento;\n");
	gets(op_alterar);
	if (op_alterar[0] == '1') {
		printf("Digite o novo nome: ");
		gets(vetor[n].nome);
		return;
	}
	if (op_alterar[0] == '2') {
		printf("Digite o novo número de telefone: ");
		gets(vetor[n].telefone);
		return;
	}
	if (op_alterar[0] == '3') {
		printf("Digite o novo email: ");
		gets(vetor[n].email);
		return;
	}
	if (op_alterar[0] == '4') {
		printf("Digite a nova data de nascimento (DD/MM/AAAA): ");
		gets(vetor[n].dt_nascimento);
		return;
	}
}

int main() {
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
        setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '5') {

		printf("\nEntre com a opção desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Alterar uma informação:");
		printf("\n6) Sair\n\n");
		gets(opcao);

		if(opcao[0] == '1') {//inserir
			printf("\nEntre com um nome: ");
			gets(agenda[proxima].nome);
			printf("\nEntre com um telefone: ");
			gets(agenda[proxima].telefone);
			printf("\Entre com um email: ");
			gets(agenda[proxima].email);
			printf("\Entre com a data de nascimento (DD/MM/AAAA): ");
			gets(agenda[proxima].dt_nascimento);
			agenda[proxima].ativo = true;
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') { //procurar
			char procurado[40];
			printf("\nEntre com o nome procurado: ");
			gets(procurado);
			
			int proc = procurar(procurado, agenda, fichas_existentes);
			if (proc != -1) {
			    printf("\n\nO telefone de %s é %s, o email é %s e a data de nascimento é %s.\n",
			      agenda[proc].nome, agenda[proc].telefone, agenda[proc].email, agenda[proc].dt_nascimento);
			    //depois de achar nao preciso procurar mais
			}
			else {
			  printf("\n\nNome não encontrado.\n");
			}
		}
		if(opcao[0] == '3') {//listar tudo
			printf("\n\n");
			int i;
			
			if(fichas_existentes == 0) printf("A base de dados está vazia!\n");
			for(i=0; i<fichas_existentes; i++) {
				if (agenda[i].ativo == true) {
				    printf("O telefone de %s é %s, o email é %s e a data de nascimento é %s.\n",
				    agenda[i].nome, agenda[i].telefone, agenda[i].email, agenda[i].dt_nascimento);
				}
			}
		}
		if(opcao[0] == '4') {//excluir
			char procurado[40];
			printf("\nEntre com o nome que será excluído: ");
			gets(procurado);
			
			int j;
			int proc = procurar(procurado, agenda, fichas_existentes);
			if (proc != -1) {
				printf("\n\nO telefone de %s será removido!\n", agenda[proc].nome);
			    agenda[proc].ativo = false;
				fichas_existentes--;
				proxima--;
			}
			else {
			  printf("\n\nNome não encontrado.\n");
			}
		}
		if (opcao[0] == '5') { 
			char nm_alterar[40];
			printf("\nEntre com o nome do contato a ser alterado: ");
			gets(nm_alterar);
			
			int proc = procurar(nm_alterar, agenda, fichas_existentes);
			if (proc != -1) {
				alterar(agenda, proc);
				printf("Informações alteradas!");
				gets(opcao);
			}
			else {
				printf("\nNome não encontrado.\n");
				gets(opcao);
			}
		}
	}
	return 0;
}
 
