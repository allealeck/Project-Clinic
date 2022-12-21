#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variaveis globais acumulativas do relatorio mes
int relatorio_inter=0; //Internacao
int relatorio_lib=0; //Liberados

//Variaveis globais de contagem
int atendidos=0; //Pacientes atendidos
int prioridade_triagem=0; //Pacientes na fila de prioridade de triagem
int inter=0; //Pacientes que foram internados
int lib=0; //Pacientes que foram liberados
int contador_inserir=0; //Para o vetor no void inserir
int contador_tipo=0; //Para o vetor no void tipo_consulta
int espec=0; //Para o vetor no void cadastro_medico
int paciente=0; //Para o vetor no void diagnostico

//Struct Agenda
typedef struct agenda SCHEDULE;
struct	 agenda{

    char name[60];
    char addres[40];
    int cpf[5];
    int cellphone[5];
    int age[5];
};

//Struct Enfermaria
typedef struct enfermeiros TRIAGEM;
struct enfermeiros{
	
	int altura[5];
	int peso[5];
	int temperatura[5];
	struct agenda;
	
};

//Struct Medicos
typedef struct medicos MEDICOS;
struct medicos{
	
	char nome[70];
	int matricula_medico[15];
	
};

//Struct Login
typedef struct login LOGIN;
struct login{
	
	char usuario[11];
	char senha[6];
}padrao;

//No *ponteiro fila normal triagem
typedef struct no{
	
	int valor;
	struct no *proximo;
	
}No;

//No *ponteiro fila prioridade triagem
typedef struct no1{
	
	int valor1;
	struct no1 *proximo1;
	
}No1;

//No *ponteiro fila normal consulta 
typedef struct noC{
	
	int valorC;
	struct noC *proximoC;
	
}NoC;

//No *ponteiro fila prioridade consulta
typedef struct noC2{
	
	int valorC2;
	struct noC2 *proximoC2;
	
}NoC2;

//FILA NORMAL TRIAGEM
void Inserir_Paciente_Com_Prioridade(No **fila, int situacao){
	
	No *auxiliar, *novo = malloc(sizeof(No));
	
	if(novo){
			
		novo->valor = situacao;
		novo->proximo = NULL;
		
		if(*fila == NULL){
		
			
			*fila = novo;
	}			
			else{
				auxiliar = *fila;
				
				while(auxiliar->proximo){
				
					
					auxiliar = auxiliar->proximo;
				}
				auxiliar->proximo = novo;
				
			}
		}
	else {
		printf("\nERRO AO ALOCAR MEMORIA\n");
	}
}

No* Remover_Da_Fila(No **fila){
	
	No *remover = NULL;
	
	if(*fila){
		
		remover = *fila;
		*fila = remover->proximo;
	} else {
		
		printf("\nFila Vazia\n");
	}
	return remover;
}

void imprimir(No *fila){
	
	printf("\t--------------- FILA ---------------\n\t");
	
	while(fila){
		printf("\t%d", fila->valor);
		fila = fila->proximo; 
	}
	printf("\n\t------------- FIM FILA -------------\n");
}

//FILA PRIORIDADE TRIAGEM
void Inserir_Paciente_Com_Prioridade1(No1 **fila1, int situacao1){
	
	No1 *auxiliar1, *novo1 = malloc(sizeof(No1));
	
	if(novo1){
			
		novo1->valor1 = situacao1;
		novo1->proximo1 = NULL;
		
		if(*fila1 == NULL){
		
			
			*fila1 = novo1;
	}			
			else{
				auxiliar1 = *fila1;
				
				while(auxiliar1->proximo1){
				
					
					auxiliar1 = auxiliar1->proximo1;
				}
				auxiliar1->proximo1 = novo1;
				prioridade_triagem++;				
			}
		}
	else {
		printf("\nERRO AO ALOCAR MEMORIA\n");
	}
}

No1* Remover_Da_Fila1(No1 **fila1){
	
	No1 *remover1 = NULL;
	
	if(*fila1){
		
		remover1 = *fila1;
		*fila1 = remover1->proximo1;
	} else {
		
		printf("\nFila Vazia\n");
	}
	return remover1;
}

void imprimir1(No1 *fila1){
	
	printf("\t--------------- FILA ---------------\n\t");
	
	while(fila1){
		printf("\t%d", fila1->valor1);
		fila1 = fila1->proximo1; 
	}
	printf("\n\t------------- FIM FILA -------------\n");
}

//FILA NORMAL CONSULTA
void Inserir_Paciente_Com_PrioridadeC(NoC **filaC, int situacaoC){
	
	NoC *auxiliarC, *novoC = malloc(sizeof(NoC));
	
	if(novoC){
			
		novoC->valorC = situacaoC;
		novoC->proximoC = NULL;
		
		if(*filaC == NULL){
		
			
			*filaC = novoC;
	}			
			else{
				auxiliarC = *filaC;
				
				while(auxiliarC->proximoC){
				
					
					auxiliarC = auxiliarC->proximoC;
				}
				auxiliarC->proximoC = novoC;
				
			}
		}
	else {
		printf("\nERRO AO ALOCAR MEMORIA\n");
	}
}

NoC* Remover_Da_FilaC(NoC **filaC){
	
	NoC *removerC = NULL;
	
	if(*filaC){
		
		removerC = *filaC;
		*filaC = removerC->proximoC;
	} else {
		
		printf("\nFila Vazia\n");
	}
	return removerC;
}

void imprimirC(NoC *filaC){
	
	printf("\t--------------- FILA ---------------\n\t");
	
	while(filaC){
		printf("\t%d", filaC->valorC);
		filaC = filaC->proximoC; 
	}
	printf("\n\t------------- FIM FILA -------------\n");
}

//FILA PRIORIDADE CONSULTA
void Inserir_Paciente_Com_PrioridadeC2(NoC **filaC2, int situacaoC2){
	
	NoC2 *auxiliarC2, *novoC2 = malloc(sizeof(NoC2));
	
	if(novoC2){
			
		novoC2->valorC2 = situacaoC2;
		novoC2->proximoC2 = NULL;
		
		if(*filaC2 == NULL){
		
			
			*filaC2 = novoC2;
	}			
			else{
				auxiliarC2 = *filaC2;
				
				while(auxiliarC2->proximoC2){
				
					
					auxiliarC2 = auxiliarC2->proximoC2;
				}
				auxiliarC2->proximoC2 = novoC2;
				
			}
		}
	else {
		printf("\nERRO AO ALOCAR MEMORIA\n");
	}
}

NoC* Remover_Da_FilaC2(NoC2 **filaC2){
	
	NoC2 *removerC2 = NULL;
	
	if(*filaC2){
		
		removerC2 = *filaC2;
		*filaC2 = removerC2->proximoC2;
	} else {
		
		printf("\nFila Vazia\n");
	}
	return removerC2;
}

void imprimirC2(NoC2 *filaC2){
	
	printf("\t--------------- FILA ---------------\n\t");
	
	while(filaC2){
		printf("\t%d", filaC2->valorC2);
		filaC2 = filaC2->proximoC2; 
	}
	printf("\n\t------------- FIM FILA -------------\n");
}

//MENU DAS FILAS TRIAGEM
void menu_recepcao(){
	
	No *r, *fila = NULL;
	No1 *r1, *fila1 = NULL;
	
	int opcao_normal, opcao_prioridade, valor, opcao_rec;
	int opcao1, valor1;
	
	do{
		
		printf("1 - Fila Normal\n");
		printf("2 - Fila Prioridade\n");
		printf("3 - Voltar\n");
		printf("--------------------------------\n");
		printf("R: ");
		scanf("%d", &opcao_rec);
		
		switch(opcao_rec){
			
			case 1: //FILA NORMAL
			
		do{
		printf("--------------------------------\n");
		printf("      FILA NORMAL TRIAGEM\n");
		printf("Selecione uma das opcoes abaixo: \n");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("4 - Voltar\n");
		printf("R: ");
		scanf("%d", &opcao_normal);
		
		switch(opcao_normal){
			
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valor);
				
				Inserir_Paciente_Com_Prioridade(&fila, valor);
				prioridade_triagem++;
				
				break;
				
			case 2:
				
				r = Remover_Da_Fila(&fila);
				
				if(r){
					
					printf("Removido: %d\n", r->valor);
					free(r);
				}
				break;
			
			case 3:
				
				imprimir(fila);
				break;
				
			case 4: 
				
				printf("\n\nVoltando...\n");
				break;
			
			default:
				if(opcao_normal != 0){
					printf("\n\nOpcao invalida!\n");
					}
				}
		}while(opcao_normal != 4);
		
				break;
		
		case 2: //FILA PRIORIDADE
			
			do{
		printf("--------------------------------\n");
		printf("   FILA PRIORIDADE TRIAGEM\n");
		printf("Selecione uma das opcoes abaixo: \n");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("4 - Voltar\n");
		printf("R: ");
		scanf("%d", &opcao_prioridade);
		
		switch(opcao_prioridade){
			
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valor1);
				
				Inserir_Paciente_Com_Prioridade1(&fila1, valor1);
				break;
				
			case 2:
				
				r1 = Remover_Da_Fila1(&fila1);
				
				if(r1){
					
					printf("Removido: %d\n", r1->valor1);
					free(r1);
				}
				break;
			
			case 3:
				
				imprimir(fila1);
				break;
				
			case 4: 
				
				printf("\n\nVoltando...\n");
				break;
			
			default:
				if(opcao_prioridade != 0){
					printf("\n\nOpcao invalida!\n");
					}
				}
		}while(opcao_prioridade != 4);
			
			break;		
		}
		
		if(opcao_rec != 3){
			
			printf("\nOpcao Invalida!\n");
			system("pause");
		}
		
	}while(opcao_rec!=3);
	
}

//MENU DAS FILAS CONSULTA
void menu_recepcaoC(){
	
	NoC *rC, *filaC = NULL;
	NoC2 *rC2, *filaC2 = NULL;
	
	int opcao_normal, opcao_prioridade, opcao_rec;
	int valorC, valorC2;
	
	do{
		
		printf("\n--------------------------------\n");
		printf("1 - Fila Normal\n");
		printf("2 - Fila Prioridade\n");
		printf("3 - Voltar\n");
		printf("--------------------------------\n");
		printf("R: ");
		scanf("%d", &opcao_rec);
		
		switch(opcao_rec){
			
			case 1: //FILA NORMAL CONSULTA
			
		do{
		printf("--------------------------------\n");
		printf("	FILA NORMAL CONSULTA\n");
		printf("Selecione uma das opcoes abaixo: \n");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("4 - Voltar\n");
		printf("R: ");
		scanf("%d", &opcao_normal);
		
		switch(opcao_normal){
			
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valorC);
				
				Inserir_Paciente_Com_PrioridadeC(&filaC, valorC);
				break;
				
			case 2:
				
				rC = Remover_Da_FilaC(&filaC);
				
				if(rC){
					
					printf("Removido: %d\n", rC->valorC);
					free(rC);
				}
				break;
			
			case 3:
				
				imprimir(filaC);
				break;
				
			case 4: 
				
				printf("\n\nVoltando...\n");
				break;
			
			default:
				if(opcao_normal != 0){
					printf("\n\nOpcao invalida!\n");
					}
				}
		}while(opcao_normal != 4);
		
				break;
		
		case 2: //FILA PRIORIDADE CONSULTA
			
			do{
		printf("--------------------------------\n");
		printf("  FILA PRIORIDADE CONSULTA\n");
		printf("Selecione uma das opcoes abaixo: \n");
		printf("1 - Inserir\n");
		printf("2 - Remover\n");
		printf("3 - Imprimir\n");
		printf("4 - Voltar\n");
		printf("R: ");
		scanf("%d", &opcao_prioridade);
		
		switch(opcao_prioridade){
			
			case 1:
				printf("Digite um valor: ");
				scanf("%d", &valorC2);
				
				Inserir_Paciente_Com_PrioridadeC2(&filaC2, valorC2);
				break;
				
			case 2:
				
				rC2 = Remover_Da_FilaC2(&filaC2);
				
				if(rC2){
					
					printf("Removido: %d\n", rC2->valorC2);
					free(rC2);
				}
				break;
			
			case 3:
				
				imprimir(filaC2);
				break;
				
			case 4: 
				
				printf("\n\nVoltando...\n");
				break;
			
			default:
				if(opcao_prioridade != 0){
					printf("\n\nOpcao invalida!\n");
					}
				}
		}while(opcao_prioridade != 4);
			
			break;		
		}
		
	}while(opcao_rec!=3);
	
}

//LOGIN
void tela_login(){
	
	system("cls");
	printf("-------------------------------------------------------------\n");
    printf("Tela de Login\n");
    printf("-------------------------------------------------------------\n");
}

int login(){
	
	LOGIN loginzinho;
	
	int retorno;
	
	do{
	
		tela_login();
		printf("Digite o usuario: ");
		scanf("%s", loginzinho.usuario);
		printf("Digite a senha: ");
		scanf("%s", loginzinho.senha);
		
		retorno = strcmp(loginzinho.usuario, padrao.usuario);
		if(retorno==0){
			retorno = strcmp(loginzinho.senha, padrao.senha);
		}
		if (retorno!=0){
			printf("usuario ou senha invalido\n");
			system("pause");
		}
	}while(retorno!=0);
	
	return 1;
}

//RECEPCAO
void inserir(){

    FILE* archive;

    SCHEDULE registry;

    archive = fopen("registro.txt", "ab");

    if(archive == NULL){

        printf("Arquivo nao encontrado");
    } else {
			
			cabecalho();        
					
            fflush(stdin);
            printf("---------------------------------\n");
            printf("Digite o nome do paciente: ");
            gets(registry.name);
            
            printf("Digite o bairro do paciente: ");
            gets(registry.addres);

            printf("Digite o CPF do paciente: ");
            scanf("%d", &registry.cpf[contador_inserir]);
            
            printf("Digite a idade do paciente: ");
            scanf("%d", &registry.age[contador_inserir]);
        
            printf("Digite o telefone do paciente: ");
            scanf("%d", &registry.cellphone[contador_inserir]);
            
            fwrite(&registry, sizeof(SCHEDULE), 1, archive);
            
            contador_inserir++;
			atendidos++;
                   
    }
        fclose(archive);
}

void tipo_consulta(){
	
	int consulta[5], situacao[5];
				
		do{
		
		cabecalho();
		printf("Selecione o tipo de consulta:\n");
		printf("1 - Clinico Geral\n");
		printf("2 - Pediatria\n");
		printf("3 - Ortopedista\n");
		printf("4 - Obstetricia\n");
		printf("5 - Cardiologia\n");
		printf("6 - Dermatologista\n");
		printf("7 - Oftalmologista\n");
		printf("R: ");
		scanf("%d", &consulta[contador_tipo]);
		printf("\nTipo de consulta selecionada: %d\n\n", consulta[contador_tipo]);
		if(consulta[contador_tipo] < 1 || consulta[contador_tipo] > 7){
			
			printf("Opcao invalida\n");
			system("pause");
		}
		}while(consulta[contador_tipo] < 1 || consulta[contador_tipo] > 7);
		
		contador_tipo++;
	}

//MEDICO
void ler(){
	
	FILE* archive;
	SCHEDULE registry;
	int dia=0;
	
	archive = fopen("registro.txt", "rb");
	if(archive == NULL){
		printf("Arquivo nao encontrado!\n");
	} else {
		while(fread(&registry, sizeof(SCHEDULE), 1, archive) == 1){		
			
			printf("------------------------------------\n");
			printf("\nNome: %s", registry.name);
			printf("\nEndereco: %s", registry.addres);
			printf("\nCPF: %d", registry.cpf[dia]);
			printf("\nIdade: %d", registry.age[dia]);
			printf("\nTelefone: %d\n\n", registry.cellphone[dia]);
			dia++;
		}
	}
	fclose(archive);
	printf("\n");
	system("pause");
}

void cadastro_medico(){
	
	MEDICOS medico;
	
	int especialidade[15];
	
	cabecalho();
	fflush(stdin);
	printf("Seu nome: ");
	gets(medico.nome);
	printf("Seu numero de matricula: ");
	scanf("%d", &medico.matricula_medico[espec]);
	do{
		cabecalho();
		printf("Selecione a sua especialidade: \n");
		printf("1 - Clinico Geral\n");
		printf("2 - Pediatria\n");
		printf("3 - Ortopedista\n");
		printf("4 - Obstetricia\n");
		printf("5 - Cardiologia\n");
		printf("6 - Dermatologista\n");
		printf("7 - Oftalmologista\n");
		printf("R: ");
		scanf("%d", &especialidade[espec]);
		
		if(especialidade[espec] < 1 || especialidade[espec] > 7){
			printf("Opcao Invalida\n");
		}
		system("pause");
	}while(especialidade[espec] < 1 || especialidade[espec] > 7);
	
	printf("Nome: %s", medico.nome);
	printf("\n");
	printf("Matricula: %d", medico.matricula_medico[espec]);
	printf("\n");
	printf("Especialidade: %d", especialidade[espec]);
	printf("\n");
	system("pause");
	
	espec++;
}

void diagnostico(){

	SCHEDULE registry;
	
	char diag;

	printf("CPF do Paciente: %i\n", registry.cpf[paciente]);
	printf("\nO Paciente preciasa de Internacao?\n");
	printf("\nDigite (s) para Internar ou (n) para Liberar.\n");
	printf("R: ");
	scanf("%s", &diag);
	
	switch(diag){
		
		case 's':
			
			 printf("Paciente Internado.\n");
			inter++;
			
			break;
			
		case 'n':
			
			printf("Paciente Liberado.\n");	
			lib++;
			
			break;
			
		default:
			
			printf("Opcao Invalida.\n");
	}
	paciente++;
}

//TRIAGEM
void situacao_paciente(){
	
	TRIAGEM triagem;
	SCHEDULE registry;
	
	int contador=0;
	
	cabecalho();
	
	printf("CPF do Paciente: %i\n", registry.cpf[contador]);
			
	printf("----------------------------------------\n");
	printf("Qual a altura do paciente? ");
	scanf("%d", &triagem.altura[contador]);
	printf("\n");
	printf("Qual o peso do paciente? ");
	scanf("%d", &triagem.peso[contador]);
	printf("\n");
	printf("Qual a temperatura do paciente? ");
	scanf("%d", &triagem.temperatura[contador]);
	contador++;
	}

//GERENTE
void relatorio(){
	
	int relatorio_gerente;
	
	do{
	cabecalho_relatorio();
	printf("Selecione umas das opcoes abaixo: \n");
	printf("1 - Relatorio de 30 dias Recepcao\n");
	printf("2 - Relatorio de 30 dias Triagem\n");
	printf("3 - Relatorio de 30 dias Consultorio\n");
	printf("4 - Fechar Relatorio\n");
	printf("--------------------------------------------\n");
	printf("R: ");
	scanf("%d", &relatorio_gerente);
	
	switch(relatorio_gerente){
		
		case 1:
			
			Cabecalho_relatorio_recepcao();
			printf("\nTotal de Pacientes Atendidos no mes: %i\n", atendidos);
			system("pause");
			break;
			
		case 2: 
			
			Cabecalho_relatorio_triagem();
			printf("\nTotal de Pacientes na Fila de Prioridade da Triagem no mes: %i\n", prioridade_triagem);
			system("pause");
			break;
		
		case 3:
			
			Cabecalho_relatorio_consultorio();
			printf("\nTotal de Pacientes Internados no mes: %i\n", relatorio_inter);
			printf("Total de Pacientes Liberados no mes: %i\n\n", relatorio_lib);
			system("pause");
			break;
		
		case 4:
			
			printf("\n\nFECHANDO O RELATORIO...\n");
			break;
		default:
			
			printf("\n\nOpcao invalida\n");
			system("pause");
			
		}
	}while(relatorio_gerente != 4);
	system("pause");	
}

//INFORMACOES ADICIONAIS
void credits(){
	
	system("cls");
	printf("-------------------------------------------------------------\n");
    printf("copyright © 2022 todos os direitos reservados.\n");
	printf("- Eduardo de Andrade Bomfim Jr\n");
	printf("- Mari Alessandra Santana de Sousa\n");
	printf("- Felipe Soares Lisboa de Melo\n");
	printf("- Eider Souza Costa dos Santos\n");
	printf("- Bianca Hellen Oliveira Silva\n");
	printf("- Everton Jesus dos Santos\n\n");
    printf("-------------------------------------------------------------\n");
    
}

void cabecalho(){

    system("cls");
    printf("-------------------------------------------------------------\n");
    printf("Sistema Clinico Amado Batista\n");
    printf("-------------------------------------------------------------\n");
}

void information(){

    system("cls");
    printf("-------------------------------------------------------------\n");
    printf("                       RECEITA FEDERAL\n\n");
    printf("                       ESTADO DA BAHIA\n\n");
    printf("                       PODER EXECUTIVO\n\n");
    printf("            Secretaria Municipal de Saude Publica\n\n");
    printf("                    Clinica Amado Batista\n");
    printf("-------------------------------------------------------------\n");
}

void cabecalho_relatorio(){
	
	system("cls");
	printf("------------------------------\n");
	printf("	RELATORIO\n");
	printf("------------------------------\n");	
}

void Cabecalho_relatorio_recepcao(){
	
	system("cls");
	printf("-----------------------------------\n");
	printf("	   RELATORIO RECEPCAO\n");
	printf("-----------------------------------\n");
}

void Cabecalho_relatorio_triagem(){
	
	system("cls");
	printf("-----------------------------------\n");
	printf("         RELATORIO TRIAGEM\n");
	printf("-----------------------------------\n");
}

void Cabecalho_relatorio_consultorio(){
	
	system("cls");
	printf("-----------------------------------\n");
	printf("	 RELATORIO CONSULTORIO\n");
	printf("-----------------------------------\n");
}

//MENU
int main(){ 

    int option, dia, sair; 
	int option_case3;
	int rep_case1, rep_case2, rep_case3;
	    	
    do
    {
        cabecalho();
		
        printf("Selecione umas das opcoes abaixo:\n");
        printf("1 - Recepcao\n");
        printf("2 - Triagem\n");
        printf("3 - Consultorio\n");
        printf("4 - Gerente\n");
        printf("5 - Informacoes do Hospital\n");
        printf("6 - Creditos\n");
        printf("7 - Encerrar o Programa\n");
        printf("-------------------------------------------------------------\n");
        printf("R: ");
        scanf("%d", &option);
        printf("\n");
		
        switch(option){
		
            case 1: // Recepcao 
            
				for(rep_case1 = 1; rep_case1 < 31; rep_case1++){
				do{
				
				cabecalho();
				printf("\ndia: %d\n", rep_case1);
				
                inserir();
                tipo_consulta();
                menu_recepcao();
				
				printf("\n-----------------------------------\n");
				printf("Selecione uma das opcoes abaixo:\n");
				printf("1 - Para finalizar o dia\n");
				printf("2 - Para continuar o dia\n");
				printf("R: ");
				scanf("%d", &sair);
				
				if(sair < 1 || sair > 2){
		
				printf("\nOpcao invalida!\n");
				system("pause");					
				}
            	}while(sair != 1);
            
        }
            break;

            case 2: // Triagem
				
				for(rep_case2 = 1; rep_case2 < 31; rep_case2++){
			
				do{
					
				cabecalho();
				
				printf("\ndia: %d\n", rep_case2);
				
				menu_recepcao();
			    ler();
				situacao_paciente();
				menu_recepcaoC();
				
				printf("\n-----------------------------------\n");
				printf("Selecione uma das opcoes abaixo:\n");
				printf("1 - Para finalizar o dia\n");
				printf("2 - Para continuar o dia\n");
				printf("R: ");
				scanf("%d", &sair);
				
				if(sair < 1 || sair > 2){
		
				printf("\nOpcao invalida!\n");
				system("pause");
					}
					
				}while(sair != 1);
			}
            break;

            case 3: // Consultorio
            	
				for(rep_case3 = 1; rep_case3 < 31; rep_case3++){
				
				do{
				cabecalho();
				printf("\ndia: %d", rep_case3);
				
				cadastro_medico();
				menu_recepcaoC();
				ler();
				diagnostico();
				excluir_dados();
				
				printf("\n-----------------------------------\n");
				printf("Selecione uma das opcoes abaixo:\n");
				printf("1 - Para finalizar o dia\n");
				printf("2 - Para continuar o dia\n");
				printf("R: ");
				scanf("%d", &sair);
				
				if(sair < 1 || sair > 2){
		
				printf("\nOpcao invalida!\n");
				system("pause");	
				}
							
			}while(sair != 1);

			printf("Paciente Internado: %i\n", inter);
			printf("Paciente Liberado: %i\n", lib);

			relatorio_inter=relatorio_inter+inter;
			relatorio_lib=relatorio_lib+lib;
					
			system("pause");
			inter=0;
			lib=0;
		}
            break;

            case 4: // Gerente
            
                strcpy(padrao.usuario,"christiane");
				strcpy(padrao.senha, "admin");
				
				if(login()==1){
					
					printf("\nLOGIN REALIZADO COM SUCESSO!\n");
					printf(" \nSEJA BEM VINDO GERENTE!\n");
					system("pause");
					relatorio();
				}else {
					
					printf("Erro ao realizar o login\n");
					system("pause");
				}
            break;

            case 5: // Informacoes
				
				information();
                system("pause");						
            break;

            case 6: // Creditos
				
				credits();
				system("pause");
				
            break;
            
            case 7: // Mensagem de Finalizacao 
            	
            	printf("Obrigado por utilizar o nosso sistema\n");
            	break;

            default: // Caso seja digitado uma variavel invalida

                printf("Opcao invalida\n");
                system("pause");
	
}
   			}while (option != 7); // Encerrar

   		return 0;
}

