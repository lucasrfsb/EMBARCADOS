1. Considerando a biblioteca-padrão da linguagem C, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

FILE * fopen(const char * path, const char * mode);
FILE * freopen(const char * path, const char * mode, FILE * stream);
int fclose(FILE * stream);
void fcloseall(void);


(b) Quais são as funções (e seus protótipos) para escrever em arquivos?


size_t fwrite(const void * ptr, size_t size, size_t nitems, FILE * stream);
int fprintf(FILE * stream, const char * format, ...);


(c) Quais são as funções (e seus protótipos) para ler arquivos?


size_t fread(void * ptr, size_t size, size_t nitems, FILE * stream);
int fscanf(FILE * stream, const char * format, ...);
char * fgets(char * str, int size, FILE * stream);


(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?


void rewind(FILE * stream);
int fseek(FILE * stream, long int offset, int whence);


(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

#include <stdio.h>


2. O que é a norma POSIX?

> POSIX (Portable Operating System Interface) é uma família de normas definidas pelo IEEE para manter compatibilidade entre sistemas operacionais. Tem como objetivo difundir uma mesma implementação para diferentes sistemas operacionais.

3. Considerando a norma POSIX, responda:

(a) Quais são as funções (e seus protótipos) para abrir e fechar arquivos?

int open(const char * path, int oflag, ...);
int close(int fildes);


(b) Quais são as funções (e seus protótipos) para escrever em arquivos?

ssize_t write(int fildes, const void *buf, size_t nbyte);


(c) Quais são as funções (e seus protótipos) para ler arquivos?

ssize_t read(int fildes, void *buf, size_t nbyte);


(d) Quais são as funções (e seus protótipos) para reposicionar um ponteiro para arquivo?

off_t lseek(int fd, off_t offset, int whence);


(e) Quais bibliotecas devem ser incluídas no código para poder utilizar as funções acima?

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



