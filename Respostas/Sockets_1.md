1. Com rela��o ao modelo cliente-servidor, responda:

	(a) Quais s�o as caracter�sticas b�sicas deste modelo?
	� um modelo de comunica��o com sockets o qual possui sempre uma comunica��o de duas vias
.
	A tecnologia cliente/servidor � uma arquitetura na qual o processamento da informa��o 
� dividido em m�dulos ou processos distintos. Um processo � respons�vel pela manuten��o 
da informa��o (servidores) e outros respons�veis pela obten��o dos dados (os clientes).
	Os processos cliente enviam pedidos para o processo servidor, e este por sua vez processa 
e envia os resultados dos pedidos.
	� no servidor que normalmente ficam os sistemas mais pesados da rede. As m�quinas clientes s�o menos poderosas, pois n�o rodam aplicativos que 
requerem tantos recursos.

	(b) Quais s�o as caracter�sticas b�sicas do servidor?
	� passivo aguardando a comunica��o do cliente
.
	Podem se conectar com outros servidores para atender uma solicita��o espec�fica do cliente; jamais podem se comunicar.

	(c) Quais s�o as caracter�sticas b�sicas do cliente?
	� ativo, inicia a comunica��o e tem que saber o endere�o e a porta para comunicar

.
	Conecta-se a um pequeno n�mero de servidores de uma vez.

2.  Com rela��o ao protocolo de comunica��o da internet, responda:

	(a) O que s�o protocolos de comunica��o?
	Um protocolo � uma conven��o que controla e possibilita uma conex�o, comunica��o, 
transfer�ncia de dados entre dois sistemas computacionais. De maneira simples, um 
protocolo pode ser definido como "as regras que governam" a sintaxe, sem�ntica e s
incroniza��o da comunica��o.
	(b) Quais s�o as caracter�sticas b�sicas de protocolos de comunica��o?
	Os protocolos variam muito em prop�sito e sofistifica��o. A maioria dos protocolos especifica uma ou mais das seguintes propriedades:
detec��o da conex�o f�sica subjacente ou a exist�ncia de um n�; handshaking (estabelecimento de liga��o); negocia��o de v�rias caracter�sticas de uma conex�o;
como iniciar e finalizar uma mensagem; como formatar uma mensagem; o que fazer com mensagens corrompidas ou mal formatadas; 
como detectar perda inesperada de conex�o e o que fazer em seguida.

3. Com rela��o ao protocolo TCP, responda:

	(a) O que s�o portas no protocolo TCP?
	Funcionam como endere�amentos do servidor para que as informa��es enviadas e recebidas cheguem at� o local.
	
	A comunica��o pela internet � feita, basicamente, atrav�s de protocolos, sendo o TCP (Transmission Control Protocol) um dos mais importantes deles. 
Isso porque o TCP est� inclu�do no conjunto de protocolos que formam o TCP/IP, a base de comunica��o via dados de toda a internet.

	(b) Para que servem estas portas?
	Para utiliza��o de diversos processos relacionados a comunica��o utilizando somente o endere�o IP.

