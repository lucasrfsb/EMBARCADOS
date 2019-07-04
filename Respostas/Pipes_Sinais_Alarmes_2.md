1. Crie um programa em C que cria um processo-filho e um pipe de comunica��o. Fa�a com que o processo-pai envie os valores 1, 2, 3, 4, 5, 6, 7, 8, 9 e 10 para o processo-filho, com intervalos de 1 segundo entre cada envio. Depois de o processo-pai enviar o n�mero 10, ele aguarda 1 segundo e termina a execu��o. O processo-filho escreve na tela cada valor recebido, e quando ele receber o valor 10, ele termina a execu��o.

	
#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>

int main(int argc, char *argv[])
	
{
    
	int fd[2];
    
	int I, O[10];
    
	pipe(fd);
    
	pid_t pid = fork();

    
	if (pid != 0)
        
		for(int i = 0 ; i < 10 ; i++)
        
	{
	        
	I = i + 1;
	        
		write(fd[1], &I, sizeof(int));
	        sleep(1);
   		
	}

    
	else
    
	{ 
        
	for(int i = 0 ; i < 10 ; i++)
	        
		if(read(fd[0], &O[i], sizeof(int))>=0)
	        	
	printf("%d ", O[i]);
	    
	exit(1);
    
		}
    
	return 0;

		}



2. Crie um programa em C que cria um processo-filho e um pipe de comunica��o. Utilize o pipe para executar a seguinte conversa entre processos:

	
	FILHO: Pai, qual � a verdadeira ess�ncia da sabedoria?
	
	PAI: N�o fa�ais nada violento, praticai somente aquilo que � justo e equilibrado.
	
	FILHO: Mas at� uma crian�a de tr�s anos sabe disso!
	
	PAI: Sim, mas � uma coisa dif�cil de ser praticada at� mesmo por um velho como eu...


	Neste exerc�cio, quem recebe a mensagem via pipe � quem as escreve no terminal.


#include <stdio.h>	
#include <stdlib.h>
#include <unistd.h>
	
int main(int argc, char *argv[])
	
{
    
	int fd[2];
    
	char m[4][100] = {"Pai, qual � a verdadeira ess�ncia da sabedoria? ",
 
			  "N�o fa�ais nada violento, praticai somente aquilo que � justo e equilibrado.",
    				  
			  "Mas at� uma crian�a de tr�s anos sabe disso!",
    				  
			  "Sim, mas � uma coisa dif�cil de ser praticada at� mesmo por um velho como eu..."}, 
	s[100];
    
	pipe(fd);
    
	pid_t pid = fork();

    
	if (pid != 0)
    	
		for(int i = 0 ; i < 2 ; i++)
    	
		{
    			
	write(fd[1], m[2*i], sizeof(m[0]));
	    	
	sleep(1);
	    	
		if(read(fd[0], s, 100)>=0)
	    		
	printf("PAI: %s\n", s);
    	
	}
    
	else
    	
	for(int i = 0 ; i < 2 ; i++)
    	
	{
	    	
	if(read(fd[0], s, 100)>=0)
	    		
	printf("FILHO: %s\n", s);
	    	
	write(fd[1], m[2*i+1], sizeof(m[0]));
	    	
	sleep(1);
    	
	}
    
	return 0;

	}



3. Crie um programa em C que cria dois processos-filhos e um pipe de comunica��o. Utilize o pipe para executar a seguinte conversa entre processos:

	
	FILHO1: Quando o vento passa, � a bandeira que se move.
	
	FILHO2: N�o, � o vento que se move.
	
	PAI: Os dois se enganam. � a mente dos senhores que se move.
	


	
Neste exerc�cio, quem recebe a mensagem via pipe � quem as escreve no terminal.


#include <stdio.h>	
#include <stdlib.h>	
#include <unistd.h>	

int main(int argc, char *argv[])

	{
    
	int fd[2];
    
	char m[3][100] = {"Quando o vento passa, � a bandeira que se move. ",
    				  
			  "N�o, � o vento que se move.",
    				  
			  "Os dois se enganam. � a mente dos senhores que se move."}, 
	s[100];
    
	pipe(fd);
    
	pid_t pid = fork();
    
	if(pid == 0)
    
	{
    	
	if(read(fd[0], s, 100) >= 0)
    		
	printf("FILHO1: %s\n", s);
    	
	exit(0);
    
	}
    
	else
    
	{
    	
	pid_t pid2 = fork();
    	
		if(pid2 == 0)
    	
	{
    		
	sleep(1);
	    	
		if(read(fd[0], s, 100) >= 0)
	    		
	printf("FILHO2: %s\n", s);
	    	
	write(fd[1], m[2], sizeof(m[0]));
    		
	exit(0);
    	
	}
    	
	else
    	
	{
    		
	write(fd[1], m[0], sizeof(m[0]));
    		
	sleep(1);
    		
	write(fd[1], m[1], sizeof(m[0]));
    		
	sleep(1);
    		
	if(read(fd[0], s, 100) >= 0)
    			
	printf("PAI: %s\n", s);
    		
    		
	exit(0);
    	
		}
    
	}
    
	return 0;

	}


	4. Crie um programa em C que cria um processo-filho e um pipe de comunica��o. O processo-filho dever� pedir o nome do usu�rio, envia-lo para o pai via pipe, e o pai dever� escrever o nome do usu�rio no terminal.


#include <stdio.h>
#include <stdlib.h>	
#include <unistd.h>


int main(int argc, char *argv[])
	
{
    
	int fd[2];
    
	char s[100], o[100];
    
	pipe(fd);
    
	pid_t pid = fork();

    
	if(pid == 0)
    
	{
    	
		printf("Escreva seu nome: ");
    	
	scanf("%[^'\n']", s);
    	
	write(fd[1], s, sizeof(s));
    
	}
    
	else
    
	{
    	
	while(read(fd[0], o, 100) < 0)
    	
	{
	}
    	
	printf("Nome do usuario: %s\n", o);
    
	}
    
	return 0;
	
}
	
	

5. Utilize o sinal de alarme para chamar a cada segundo o comando 'ps' ordenando todos os processos de acordo com o uso da CPU. Ou seja, seu c�digo atualizar� a lista de processos a cada segundo. Al�m disso, o c�digo dever� tratar o sinal do CTRL-C, escrevendo "Processo terminado!" na tela antes de terminar a execu��o do processo.


#include <signal.h>
#include <unistd.h>	
#include <stdio.h>
#include <stdlib.h>

	void acabou(int sig)

	{
	
		printf("Processo terminado!\n");
	
		exit(0);
	
}
	

void tratamento_alarme(int sig)

	{
	
	system("ps --sort -time");
	
	alarm(1);
	
}
	

int main()
	
{
	
	signal(SIGALRM, tratamento_alarme);
	
	signal(SIGINT,acabou);
	
	alarm(1);
	
	printf("Aperte CTRL+C para acabar:\n");
	
	while(1);
	
	return 0;

}
