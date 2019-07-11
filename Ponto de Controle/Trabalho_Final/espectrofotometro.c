#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <wiringPi.h>
#include <stdint.h>

#define PINO_LED_VER 1   //PINO CONECTADO AO LED VERMELHO
#define PINO_LED_ULTRA 4 //PINO CONECTADO AO LED ULTRAVIOLETA
#define PINO_LED_BRA 5   //PINO CONECTADO AO LED BRANCO



int ver, bra, ultra, brilho;
int i;
int pino;



void setaPinos()
{
  
	pinMode(PINO_LED_VER, OUTPUT);    
	pinMode(PINO_LED_ULTRA, OUTPUT);
	pinMode(PINO_LED_BRA, OUTPUT);

}

void prevcp (){ 

system ("tail -n 1 /var/log/apache2/access.log | grep -o 'cor.*cust*' > led.txt"); //pega a última linha do arquivo disponibilizado 																				    pelo apache2, filtra o pedaço desejado e subescreve 																					em led.txt								

}

int retbrilho()  //lê led.txt e compara com as intensidades desejadas
{ 


	char* p1;
	int ver, bra, ultra;	
	int i = 0;
    int num = 0;
    char resp[50];
    char txt[50];

	char um[] = "=1";
	char dois[] = "=2";
	char tres[] = "=3";
	char quatro[] = "=4";

    FILE * arquivo2;
    arquivo2 = fopen("led.txt", "r");

    if (arquivo2 == NULL)
        return 0;
	while (!feof (arquivo2)) {
	
	fgets(txt, 50, arquivo2);

	p1 = strstr(txt,um);

		if (p1) {
		brilho = 1;
		printf ("\nbrilho = %d\n", brilho);
		break;
		
	 	}
		else 
		{

		p1 = strstr(txt,dois);
			if (p1)
			{
				brilho =2;
				printf ("\nbrilho = %d\n", brilho);
				break;
				
			}
			else 
			p1 = strstr(txt,tres);
			if (p1)
			{
				brilho =3;
				printf ("\nbrilho = %d\n", brilho);
				break;
				
			}
				 else 
				p1 = strstr(txt,quatro);
					if (p1)
					{
						brilho =4;
						printf ("\nbrilho = %d\n", brilho);
						break;
					} 
		}

	}

	
}

void retled()    //lê led.txt e compara com as possibilidades de acionamento dos leds
{
	char* p1;
    char txt[50];
	char verT[] = "vermelho";
	char braT[] = "branco";
	char ultraT[] = "ultra";

    FILE * arquivo;
    arquivo = fopen("led.txt", "r");

    if (arquivo == NULL)
        return 0;
	while (!feof (arquivo)) {
	
	fgets(txt, 50, arquivo);

	    p1 = strstr(txt,braT);

		if (p1) {
		ver=0;bra=1;ultra=0;
		printf ("\nvermelho = %d , branco = %d , ultra = %d\n", ver, bra, ultra);
		break;
	 	}
		else 
		{

		p1 = strstr(txt,verT);
			if (p1)
			{
				ver=1;bra=0;ultra=0;
				printf ("\nvermelho = %d , branco = %d , ultra = %d\n", ver, bra, ultra);
				break;
				
			}
			else 
			p1 = strstr(txt,ultraT);
			if (p1)
			{
				ver=0;bra=0;ultra=1;
				printf ("\nvermelho = %d , branco = %d , ultra = %d\n", ver, bra, ultra);
				break;
			}
		}	
	} 
   fclose(arquivo);
}
	
void main()
{
	wiringPiSetup();
	setaPinos();

	while (1)
	{
	prevcp();
	sleep(2);
	retled();
	retbrilho();
	sleep(2);
	printf ("\nvermelho = %d; branco = %d; ultra = %d; brilho = %d\n", ver, bra, ultra, brilho); //apenas para verificar a leitura do 																										arquivo led.txt


	
	if (ver) {
			pino = PINO_LED_VER;
			digitalWrite (PINO_LED_VER, HIGH);
			digitalWrite (PINO_LED_ULTRA, LOW);
			digitalWrite (PINO_LED_BRA, LOW);
			printf("vermelho!!");

			}

	if (ultra) {
			pino = PINO_LED_ULTRA;
			digitalWrite (PINO_LED_VER, LOW);
			digitalWrite (PINO_LED_ULTRA, HIGH);
			digitalWrite (PINO_LED_BRA, LOW);
			printf("ultra!!");
			}
	if (bra) {
			pino = PINO_LED_BRA;
			digitalWrite (PINO_LED_VER, LOW);
			digitalWrite (PINO_LED_ULTRA, LOW);
			digitalWrite (PINO_LED_BRA, HIGH);
			printf("branco!!");
			}

		if (brilho==1){
			pwmWrite (pino, 256);
			printf("\n %d DE INTENSIDADE %d \n",pino, brilho);
		}
		else if (brilho ==2){
			pwmWrite (pino, 512);
			printf("\n %d DE INTENSIDADE %d \n",pino, brilho);
		}
		else if (brilho ==3){
			pwmWrite (pino, 769);
			printf("\n %d DE INTENSIDADE %d \n",pino, brilho);
		}
		else if (brilho ==4){
			pwmWrite (pino, 769);
			printf("\n %d DE INTENSIDADE %d \n",pino, brilho);
		}
		else printf ("ERRO NO BRILHO!!");


	
   }

}














