1. Quais são as vantagens e desvantagens em utilizar:
	
	(a) fork?
	
O fork é usado para criar um novo processo em sistemas do tipo Unix, e isso só pode ser feito via fork.
O processo filho, que será idêntico ao pai, inclusive tendo as mesmas variáveis, registros, descritores de arquivos etc.
, depois de criado o processo filho, ele vai ser executado e o que acontece em um processo não ocorre no outro, 
são processos distintos agora, cada um seguindo seu rumo, onde é possível mudar o valor de uma variável em um e isso 
não irá alterar o valor desta variável no outro processo, por exemplo.
	
	(b) threads?

	É uma forma de um processo dividir a si mesmo em duas ou mais tarefas que podem ser executadas concorrentemente. 
Processadores Intel também possuem threads para aumentar sua eficiência. Os processadores Pentium HT foram 
os primeiros da Intel a terem multi-threads implementados onde seu SO entendia que havia dois processadores, 
mas na verdade havia um com duas threads, que auxiliavam na execução do seu SO e aplicações. 


	
	2. Quantas threads serão criadas após as linhas de código a seguir? Quantas coexistirão? Por quê?
	
	(a)
		
		void* funcao_thread_1(void *arg);
		
		void* funcao_thread_2(void *arg);
		
		
		int main (int argc, char** argv)
		
		{
			
			pthread_t t1, t2;
			
			pthread_create(&t1, NULL, funcao_thread_1, NULL);
			
			pthread_create(&t2, NULL, funcao_thread_2, NULL);
			
			pthread_join(t1, NULL);
			
			pthread_join(t2, NULL);
			
		return 0;
		
		}

		
	3 threads, a thread principal, a thread t1 e a threadt2.
	(b)
		
		void* funcao_thread_1(void *arg);
		
		void* funcao_thread_2(void *arg);
		
		
		int main (int argc, char** argv)
		
		{
			
			pthread_t t1, t2;
			
			pthread_create(&t1, NULL, funcao_thread_1, NULL);
			
			pthread_join(t1, NULL);
			
			pthread_create(&t2, NULL, funcao_thread_2, NULL);
			
			pthread_join(t2, NULL);
			return 0;
		
			}

3 threads, a thread principal, a thread t1 e a threadt2. Primeiramente, a principal e t1. Assim que, a thread t1 for destruída, então será criada a thread t2, coexistindo com a thread principal.

	

3. Apresente as características e utilidades das seguintes funções:
(DICA: elas são relacionadas à função pthread_cancel().)	

	(a) pthread_setcancelstate()

	A função aciona o cancelamento estado por estado e retorna o estado de cancelamento em um ponteiro de estado de cancelamento anterior (oldstate)

	

	(b) pthread_setcanceltype()

	A função aciona o cancelamento tipo a tipo e retorna o tipo de cancelamento em um ponteiro de tipo de cancelamento anterior (oldtype)
