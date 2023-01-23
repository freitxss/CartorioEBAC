#include <stdio.h> //biblioteca de comunica�ao com o usuario
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em memoria
#include <locale.h> // biblioteca de aloca�oes de texto por regiao
#include <string.h> //biblioteca responsavel pelas strings


int registro()//fun�ao de casdastrar usuario no sistema
	{
		//inicio da cria�ao de variaveis/string
		char arquivo[40];
		char cpf[40];
		char nome[40];
		char sobrenome[40];
		char cargo[40];
		//final da cria�ao
		
		printf("Digite seu CPF para ser cadastrado: ");//coletando informa�ao do usuario
		scanf("%s", cpf);//%s armazena as strings
		
		strcpy(arquivo, cpf); //responsavel por copiar valores das strings
		
		FILE *file; // cria o arquivo na pasta em que salvamos
		file = fopen(arquivo, "w"); //2, w significa escrever
		fprintf(file,cpf); //salva o valor da variavel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o nome para o cadastro: ");
		scanf("%s",nome);
		
		file = fopen(arquivo, "a");
		fprintf(file,nome);
		fclose(file);
		
		file = fopen(arquivo,"a");
		fprintf(file,",");
		fclose(file);
		
		printf("Digite o sobrenome para o cadastro: ");
		scanf("%s", sobrenome);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		file = fopen(arquivo, "a");
		fprintf(file,sobrenome);
		fclose(file);
		
		printf("Digite o cargo para o cadastro: ");	
		scanf("%s",cargo);
		
		file = fopen(arquivo, "a");
		fprintf(file,cargo);
		fclose(file);
		
		system("pause");
		
	}	

int consulta()
	{	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[100];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
  	
	FILE *file;
	file = fopen(cpf,"r");
  	
	if(file == NULL)
	{
	printf("Nao foi possivel abrir o arquivo, nao localizado!.\n");
	};
	
	while(fgets(conteudo, 100, file) != NULL);
	{
	printf("\nEssas sao as informa�oes do usu�rio: ");
	printf("%s", conteudo);
	printf("\n\n");
	}
  	
	system ("pause");
	}

int deletar()
	{
		
		char cpf[40];
		
		printf("Digite o CPF do usuario que deseja deletar: ");
		scanf("%s",cpf);
		
		remove(cpf);
		
		FILE *file;
		file = fopen(cpf,"r");
		
		if(file == NULL)
		{
			printf("O usuario nao existe no sistema!.\n");
			system("pause");
		}
	
	}

int main ()
	{
	int opcao=0; //defini�ao da variavel
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
				
		setlocale(LC_ALL, "Portuguese"); //defini�ao da linguagem
	
		printf("\t@@@ Cart�rio da EBAC @@@\n\n"); //inicio do meno
	
		printf("\tEscolha no menu a op�ao desejada:\n\n");
	
		printf("\t1 - Registrar os nomes\n");
	
		printf("\t2 - Consultar os nomes\n");

		printf("\t3 - Deletar os nomes\n"); 
		
		printf("\t4 - Sair do sistema\n");
	
		printf("\tOp�ao: "); //fim do menu
	
		scanf("%d", &opcao); //armazena�ao de escolha do usuario
	
		system("cls"); //limpa a tela

		switch(opcao)//inicio da sele�ao de menu
		{
			case 1: //come�o da sele�ao
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3: 
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default: //fim da sele�ao
			printf("As op�oes funcionais sao apenas do 1 at� o 3, tente novamente!\n");
			system("pause");
			break;	
		}

	
	}
	
}
