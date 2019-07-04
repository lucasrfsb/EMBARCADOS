1.Quantos pipes ser�o criados ap�s as linhas de c�digo a seguir? Por qu�?
	
(a) 	int pid;
		
	int	fd[2];
		
	pipe(fd);
		
	pid = fork();
	
	
Ser� criado 1 pipe, pois o canal foi criado antes de realizar o fork, ou seja, os dois processos tem o mesmo pipe.

	

(b) 	int pid;
		
	int	fd[2];
		
	pid = fork();
		
	pipe(fd);


		
Ser�o criados 2 pipes, pois a linha de codigo pipe(fd) foi executada por dois processos diferentes depois do
	fork() ser executado.



2. Apresente mais cinco sinais importantes do ambiente Unix, al�m do SIGSEGV, SIGUSR1, SIGUSR2, SIGALRM e SIGINT. Quais s�o suas caracter�sticas e utilidades?


SIGHUP - Sinal emitido aos processos associados a um terminal quanto este se desconecta. Este sinal tamb�m  emitido a cada processo
quando o chefe termina sua execu��o.

SIGQUIT - Sinal emitido aos processos do terminal quando com a tecla de abandono (quit ou ctrl+d) do teclado s�o acionadas.

SIGILL - Quando uma instru��o ilegal � detectada.

SIGTRAP - Sinal emitido ap�s cada instrul��o em caso de gera��o de traces dos processos.

SIGIOT - Sinal emitido em caso de problemas de hardware.


Temos tamb�m, SIGCLD,SIGTERM, SIGPIPE, SIGSYS, SIGPWR.



3. Considere o c�digo a seguir:

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void tratamento_alarme(int sig)
{
	system("date");
	alarm(1);
}

int main()
{
	signal(SIGALRM, tratamento_alarme);
	alarm(1);
	printf("Aperte CTRL+C para acabar:\n");
	while(1);
	return 0;
}
	
Sabendo que a fun��o alarm() tem como entrada a quantidade de segundos para terminar a contagem, qu�o precisos s�o os alarmes criados neste c�digo? De onde vem a imprecis�o? Este � um m�todo confi�vel para desenvolver aplica��es em tempo real?


	
	A precis�o desta fun��o � relacionada a segundos, portanto, sua precis�o � de at� 1 segundo. O met�do tem uma imprecis�o baseada no delay causado pela chamada do processo. O c�digo funciona normalmente, retorna a data de 1 em 1 segundo. O problema ocorre quando o sinal � acionado durante
uma opera��o de I/O proveniente de outra parte do c�digo, o que causa sua interrup��o e n�o � executada at� o final.
