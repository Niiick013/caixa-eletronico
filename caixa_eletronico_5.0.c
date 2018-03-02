#include"stdio.h"
#include"stdlib.h"
#include"string.h"
#include"locale.h"
#define NULO '\0'

leituraArquivo(char conta[], int linha)
{//fun��o para ler as linhas dentro do arquivo.
    FILE *arq;
    char c[7];
    int i, result;
    float x=0;
    arq = fopen(conta, "r+");// Abre um arquivo TEXTO para LEITURA
if (arq == NULL)// Se houve erro na abertura apresenta a mensagem abaixo.
    {
        printf("Problemas na abertura do arquivo\n");//mensagem.
        return;
    }
 i = 1;//essa vari�vel cont�m o valor 1 para come�ar apartir da primeira linha dentro do arquivo com o c�digo abaixo
 while (!feof(arq))
    {
        result = fscanf(arq, "%s %f",&c ,&x);//L� uma linha dentro do arquivo(inclusive com o '\n')
        if(i == 1 && linha == 1)
        {
            if (i == linha)
           {//fun��o que verifica  se a vari�vel i for igual a vari�vel linha.C�digo abaixo � semelhante e faz a mesma fun��o.
               return x;//retorna a vari�vel x
               break;//linha para parar o ciclo.
	         }
	      }
	    if(i == 2 && linha == 2)
	    {
            if (i == linha)
           {
               return x;
               break;
	         }
	     }
	    if(i == 3 && linha == 3)
	    {
            if (i == linha)
           {
               return x;
               break;
	         }
        }
        if(i == 4 && linha == 4)
        {
            if (i == linha)
           {
               return x;
               break;
	         }
	      }

     i++;//++ para acrescentar +1 na vari�vel i
    }
fclose(arq);//fecha o arquivo
}
gravarArquivo(char conta[], int linhaArq, float linhaValor)
{//fun��o para gravar linhas dentro do arquivo
    FILE *arqEntrada;//ponteiro para a vari�vel arqEntrada
    FILE *arqSaida;//ponteiro para a vari�vel arqSaida
    int linha = 1;
    int i,limite;
    char textoArquivo[100];
    if((arqEntrada = fopen(conta, "r+")) == 0)
    {//testa se o arquivo pode ser aberto
        printf("Imposs�vel abrir arquivo...\n");//informa o erro
        exit(1); //finaliza execu��o
    }
    arqSaida = fopen(conta, "r+");//arquivo de sa�da para salvar no fim do processo.
    rewind(arqEntrada);//certifica de que o cursor est� no primeiro caracter do arquivo
    for(i = 0; !feof(arqEntrada);i++)
    {//incrementa 'i' enquando nao for fim de arquivo
        memset(textoArquivo, NULO, 100);//inicializa e/ou limpa string 'textoArquivo'
        fgets(textoArquivo, 101, arqEntrada);//pega uma string de 100 caracteres
        if(linha == 1 && linhaArq == 1)
        {//se a linha 1 for a escolhida, vai modificar a linha 1, que � numero da conta dentro do arquivo
            fprintf(arqSaida, "conta: %.0f\n",linhaValor);//imprime dentro do arquivo, a linha correspondente
            linha++;//incrementa o contador de linhas
            continue;//volta ao in�cio do loop sem executar o resto do c�digo abaixo
        }
            else if(linha == 2 && linhaArq == 2)
            {//se a linha 2 for a escolhida, vai modificar a linha 2, que e senha
                fprintf(arqSaida, "senha: %.0f\n",linhaValor);//imprime dentro do arquivo, a linha correspondente
                linha++;//incrementa o contador de linhas
                continue;//volta ao in�cio do loop sem executar o resto do c�digo abaixo
            }
                else if(linha == 3 && linhaArq == 3)
                {//se a linha 3 for a escolhida, vai modificar a linha 3
                    fprintf(arqSaida, "saldo: %.2f\n",linhaValor);//imprime dentro do arquivo, a linha correspondente
                    linha++;//incrementa o contador de linhas
                    continue;//volta ao in�cio do loop sem executar o resto do c�digo abaixo
                }
                    else if(linha == 4 && linhaArq == 4)
                    {//se a linha 4 for a escolhida, vai modificar a linha 4
                        fprintf(arqSaida, "limite: %.2f",linhaValor);//imprime dentro do arquivo, a linha correspondente
                        linha++;//incrementa o contador de linhas
                        continue;//volta ao in�cio do loop sem executar o resto do c�digo abaixo
                    }
                        linha++;//incrementa o contador de linhas
                        fputs(textoArquivo, arqSaida);//coloca a string 'textoArquivo' no arquivo arqsaida
    }
    fclose(arqEntrada);//fecha a stream 'arqEntrada'
    fclose(arqSaida);//fecha a stream 'arqSaida'
}
msg()
{//mensagem do caixa eletr�nico, na primeira tela.
      printf ("|-------------------------------------------------|\n");
      printf ("|    CAIXA ELETR�NICO    |    ADS Bank \xA9          |\n");//\xa9 corresponde ao c�digo hexadecimal da tabela ASCII que � c de copyright.
      printf ("|                                                 |\n");
      printf ("|               DEUS SEJA LOUVADO!                |\n");
      printf ("|-------------------------------------------------|\n");
      printf ("\n");
}
saldoLimite(char conta[])
{//fun��o para ler saldo e limite dentro do arquivo.
    float saldoScan,limite;
    limite = 0.00;
    saldoScan = 0.00;
    system("CLS");//limpa a tela
    msg();
    saldoScan = leituraArquivo(conta,3);//3 � a linha que se encontra saldo dentro do arquivo.
    printf(" Saldo:R$%.2f  ||  ",saldoScan);//imprime o saldo na tela
    limite = leituraArquivo(conta,4);//4 � a linha que se encontra limite no arquivo.
    printf(" Limite de Cr�dito:R$%.2f\n",limite);//imprime o saldo na tela
    printf("\n Pressione algo para continuar.");//exibe mensagem na tela
    getch();
}
saque(char conta[])
{//fun��o para fazer a opera��o saque dentro do arquivo.
    int n;
    float saldo,saldoScan,sacar,limite;
    saldo = 0.00;
    sacar = 0.00;
    limite = 0.00;
    saldoScan = 0.00;
    inicioTrans://fun��o que volta aqui
    system("CLS");//limpa a tela
    msg();
    saldoScan = leituraArquivo(conta,3);//3 � a linha que se encontra saldo dentro do arquivo.
    printf(" Saldo:R$%.2f  ||  ",saldoScan);//imprime saldo na tela.
    limite = leituraArquivo(conta,4);//4 � a linha que se encontra limite dentro do arquivo.
    printf(" Limite de Cr�dito:R$%.2f || Limite de saque:R$1000\n",limite);//imprime o limite e limite de saque.
    printf("\n C�dulas dispon�veis\n notas de 100,50,20 e 10 Reais\n\n D�gite um valor a ser sacado\n 0 - SAIR\n ");//mensagem para o usu�rio.
    scanf("%f", &sacar);//fun��o pega o que foi digitado pelo usu�rio.
    n = sacar;//iguala as duas vari�veis
    if(n < 0)//verifica se o saque for negativo.
    {
        printf(" Por favor digite um valor positivo!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto inicioTrans;//volta para o inicio da opera��o
    }
    if(n == 0)//se n, que � a vari�vel que coleta o que foi digitado for igual a 0 fecha a opera��o saque
    {
       return 1;//retorna 1
    }else
    if(n > 1000)
        {//fun��o para ver se o que foi digitado de saque  for maior que MIL REAIS ele executa o c�digo abaixo
            printf(" Limite m�ximo de saque: R$1000");//imprime uma mensagem para o usu�rio
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            getch();//fun��o para parar a tela e esperar o usu�rio teclar algo para poder sair
            goto inicioTrans;//voltar para o inicio.
        }else
        {
            if(Rcedula(n) == 1)
            {//fun��o para ver se o que foi digitado de saque corresponde as c�dulas indispon�veis.
                printf(" Por favor digite um valor correspodente as c�dulas dispon�veis.");//imprime uma mensagem para o usuario
                printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
                getch();//fun��o para parar a tela e esperar o usu�rio teclar algo para poder sair
                goto inicioTrans;//voltar para o in�cio.
            }else
            {
                if(sacar > 0)
                    {//fun��o para ver se o que foi digitado de saque for maior que ZERO ele executa o c�digo.
                        if(sacar > (saldoScan + limite))
                        {
                            printf(" Saldo indispon�vel!\n");//mensagem para o usu�rio.
                        }else if(sacar > saldoScan)
                        {//fun��o para verificar se o saque for maior que o saldo dispon�vel, se for ele fara o c�lculo para subtrair do limite o que exceder o saldo dipon�vel
                            cedula(n);//fun��o que verifica quais c�dulas o caixa eletr�nico vai expelir
                            saldo = saldoScan - sacar;//c�lculo para subtrair o saque com o saldo  atual e salvar na vari�vel saldo.
                            gravarArquivo(conta,3,saldo);// 3 linha saldo, dentro do arquivo
                            printf("\n Valor sacado R$%.2f",sacar);//imprime valor sacado.
                            limite -= (sacar - saldoScan);//c�lculo para subtrair o que excedeu do saldo atual quando for sacar, e salvar na vari�vel limite.
                            gravarArquivo(conta,4,limite);// 3 linha saldo, dentro do arquivo
                        }else
                        {
                            cedula(n);//fun��o que verifica quais c�dulas o caixa eletr�nico vai expelir
                            saldo = saldoScan - sacar;//c�lculo para subtrair o saldo atual com o valor de saque e salvar na vari�vel saldo
                            gravarArquivo(conta,3,saldo);// 3 linha saldo, dentro do arquivo
                            printf("\n Valor sacado R$%.2f",sacar);//imprime o valor sacado
                        }
                    }
            }
        }
    printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
    getch();//fun��o para parar a tela e esperar o usu�rio teclar algo para poder sair
    system("CLS");//limpar tela
}
deposito(char conta[])
{//fun��o para opera��o deposito
    float saldoAtual,saldo,ResultsaldoPositivo,ResultsaldoNegativo,saldoNegativo,saldoScan,depositar,resultLimite,limite;
    saldoAtual = 0.00;
    saldo = 0.00;
    ResultsaldoPositivo = 0.00;
    ResultsaldoNegativo = 0.00;
    saldoNegativo = 0.00;
    saldoScan = 0.00;
    depositar = 0.00;
    resultLimite = 0.00;
    limite = 0.00;
    inicioDep://fun��o para voltar aqui.
    system("CLS");//fun��o para limpar a tela
    msg();
    printf(" Valor a ser depositado\n 0 - SAIR\n ");//mensagem para o usu�rio
    scanf("%f",&depositar);
    if(depositar < 0)//verifica se o saque for negativo
    {
        printf(" Por favor digite um valor positivo!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto inicioDep;//volta para o inic�o da opera��o
    }
    if(depositar ==0)
        {//se depositar for igual � 0 retorna 1 e para o processo do c�digo deposito.
            return 1;//retorna 1
        }
    saldoScan = leituraArquivo(conta,3);// 3 � a linha que se encontra saldo no arquivo.
    saldoAtual = saldoScan;
    saldoScan +=depositar;
    gravarArquivo(conta,3,saldoScan);// 3 linha saldo
    printf(" Saldo atual:R$%.2f",saldoScan);
    saldoNegativo = saldoScan;
    if(saldoNegativo <0)
    {//se o saldo atual for negativo ele executa.
        ResultsaldoNegativo = saldoNegativo + depositar;//somar o saldo negativo com o dep�sito
        saldoNegativo = saldoNegativo *-1;//modulo tornar o valor dentro de saldonegativo em um valor positivo.
        resultLimite = saldoNegativo + ResultsaldoNegativo;//salvar na vari�vel resultLimite a soma do saldoNegativo com ResultadoNegativo
        limite = leituraArquivo(conta,4);//4 � a linha que se encontra limite no arquivo.
        limite +=resultLimite;//soma da vari�vel lime com resultLimite
        gravarArquivo(conta,4,limite);// 4 � a linha limite, e grava dentro do arquivo o valor da vari�vel limite

    }else
        if(saldoNegativo > 0)
            {//fun��o para verificar se o valor da vari�vel saldoNegativo for positivo
                if(saldoAtual > 0)
                {//fun��o para verificar se o valor da vari�vel saldoAtual for positivo
                    gravarArquivo(conta,3,saldoScan);//gravar dentro do arquivo a vari�vel saldoScan
                }else
                {//fun��o que executa se o saldoAtual n�o for posito
                    ResultsaldoPositivo = saldoAtual + depositar;
                    resultLimite = depositar - ResultsaldoPositivo;
                    limite = leituraArquivo(conta,4);//4 � a linha que se encontra limite no arquivo.
                    limite +=resultLimite;//c�lculo
                    gravarArquivo(conta,4,limite);// 4 � a linha limite
                }
            }else
            if(saldoNegativo == 0)
            {//fun��o para ver se o saldo � igual a 0.
                resultLimite = saldoAtual * -1;
                limite = leituraArquivo(conta,4);//4 � a linha que se encontra limite no arquivo.
                limite +=resultLimite;//soma as variaveis limite + resultArquivo
                gravarArquivo(conta,4,limite);// 4 � a linha limite
            }
    printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
    getch();//fun��o para esperar o usu�rio teclar algo para proceuir com o processo
    system("CLS");//fun��o para limpar a tela
}
transferencia(char conta[])
{//fun��o para fazer a opera��o transfer�ncia dentro do arquivo
    char nconta[7];
    int sen;
    float valorTransSum,saldoSub,valorTrans,saldoAtual,saldoScan;
    valorTransSum = 0.00;
    saldoSub = 0.00;
    valorTrans = 0.00;
    saldoAtual = 0.00;
    saldoScan = 0.00;
    inicio:
    system("CLS");//fun��o para limpar a tela
    msg();
    saldoScan = leituraArquivo(conta,3);// 3 � a linha que se encontra saldo dentro do arquivo.
    printf(" Conta atual: %s || Saldo: %.2f\n",conta,saldoScan);
    printf("\n Digite o n�mero da conta com 6 d�gitos a ser transferido o dinheiro.\n 0 - SAIR\n Conta para transferir.: ");//mensagem para o usu�rio.
    fflush(stdin);//fun��o para limpar a streaming do teclado
    gets(nconta);//fun��o para pegar o que o usu�rio digitar
    sen = atoi(nconta);//fun��o para converter string para int
    if(sen == 0)
    {//sair da opera��o 4 transfer�ncia
        return 1;
    }
    if(strlen(nconta)<6)
    {//verifica se a string conta possui 6 digitos.
        printf(" por favor digite 6 n�meros!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto inicio;//volta para o in�cio se a conta n�o tiver 6 digitos.
    }
    if(verificarCont(nconta) == 2)
    {
        printf("\n Conta n�o existe! por favor digite um n�mero diferente.");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto inicio;//volta ao in�cio se a conta j� existir
    }
    inicioVtrans:
    printf(" Digite o valor a ser trasnferido.\n R$ ");//mensagem para o usu�rio.
    fflush(stdin);//fun��o para limpar a streaming do teclado
    scanf("%f",&valorTrans);
    if(valorTrans < 0)//verifica se o saque for negativo
    {
        printf(" Por favor digite um valor positivo!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        system("cls");//fun��o para limpar tela
        msg();
        printf(" Conta atual: %s || Saldo: %.2f\n",conta,saldoScan);
        printf("\n Digite n�mero da conta 6 digitos a ser transferido o dinheiro.\n 0 - SAIR\n");//mensagem para o usu�rio.
        printf(" Conta para transferir.: %s\n",nconta);
        goto inicioVtrans;//volta para o in�cio da opera��o
    }
    if(valorTrans > 0)
    {//se o valor da transfer�ncia for maior que 0, executa o c�digo abaixo
        saldoScan = leituraArquivo(conta,3);// 3 � a linha que se encontra saldo dentro do arquivo.
        saldoAtual = saldoScan;//iguala o valor de uma vari�vel na outra
        if(valorTrans > saldoAtual)
        {//fun��o para verificar se o valor de transfer�ncia � maior que o saldo do cliente.
            printf(" Saldo indispon�vel!\n");//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            getch();
        }
        else
        {//se caso contr�rio o valor da tranfer�ncia for menor ou igual o saldo do cliente o c�digo executa
            saldoSub =  saldoAtual - valorTrans;//valor do saldo subtraido com o valor da transfer�ncia
            gravarArquivo(conta,3,saldoSub);// 3 � a linha saldo
            valorTransSum = leituraArquivo(nconta,3);// 3 � a linha que se encontra saldo no arquivo.
            valorTransSum += valorTrans;
            gravarArquivo(nconta,3,valorTransSum);// 3 � a linha saldo
            printf(" Transfer�ncia feita com sucesso!");//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            getch();
        }
    }
}
contratarLimite(char conta[])
{//fun��o para contratar limite dentro do arquivo
    int limiteOPC;
    float limiteScan;
    limiteOPC = 0;
    limiteScan = 0.00;
    do
    {
        system("CLS");
        msg();
        printf(" Escolha um limite a ser contratado.\n 1 - R$500\n 2 - R$1,000\n 3 - R$1,500\n 0 - SAIR\n ");//mensagem para o usu�rio.
        scanf("%i",&limiteOPC);//fun��o para pegar o que o usu�rio digitar
        switch(limiteOPC)
        {//fun��o para contratar limite com valores pr�-definidos
        case 0:
        break;
        case 1:
            limiteScan = 500.00;
            gravarArquivo(conta,4,limiteScan);// 3 � a linha saldo
            printf(" Limite de Cr�dito:R$%.2f Contratado.",limiteScan);//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            limiteOPC =0;
            getch();
        break;
        case 2:
            limiteScan = 1000.00;
            gravarArquivo(conta,4,limiteScan);// 3 � a linha saldo
            printf(" Limite de Cr�dito:R$%.2f Contratado.",limiteScan);//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            limiteOPC =0;
            getch();
        break;
        case 3:
            limiteScan = 1500.00;
            gravarArquivo(conta,4,limiteScan);// 3 � a linha saldo
            printf(" Limite de Cr�dito:R$%.2f Contratado.",limiteScan);//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            limiteOPC =0;
            getch();
        break;
        default :
            system("CLS");
            msg();
            printf(" Por favor digite uma opera��o v�lida!");//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            getch();
        break;
        }
    }while(limiteOPC!=0);//fun��o que �um ciclo, s� para quando o usu�rio digitar 0.
    system("CLS");
}
cont(char conta[])
{//fun��o conta, opera��oes correspondentes a ela.
    FILE *arquivo;//ponteiro para apontar onde est� o arquivo, dentro da mem�ria ram, para modific�lo
    int opcao,limiteOPC,saq,dep,trans;
    arquivo = fopen(conta,"r+");//para verificar se o arquivo existe se existir ele abre.
    if(arquivo==NULL)//verifica se o arquivo � vazio caso for ele cria um arquivo novo. caso contrario ele apenas abre.
        {
            arquivo = fopen(conta,"w");//abrir arquivo com permiss�o de escrita.
        }else
            {
                arquivo = fopen(conta,"r+");//abrir arquivo com permiss�o de leitura e escrita
            }
    do
    {
        system("CLS");
        msg();
        arquivo = fopen(conta,"r+");//abre o arquivo com permiss�o de leitura e escrita
        printf("O que deseja fazer:\n 1 - Consultar Saldo/limite \n 2 - Saque\n 3 - Dep�sito\n 4 - Transfer�ncia\n 5 - Limite de cr�dito\n 0 - SAIR\n ");//mensagem para o usu�rio.
        scanf("%d",&opcao);//ele pega o que foi digitado pelo usu�rio na tela
        switch(opcao)
        {
            case 1:
                saldoLimite(conta);//executa a fun��o pr�-definida que exibe saldo e limite
            break;
            case 2:
                saq = saque(conta);//abre a fun��o saque e tamb�m a vari�vel saq recebe o valor retornado pela fun��o
                if(saq == 1)
                {
                    break;//para o ciclo
                }
            break;//parar opera��o 2 que � saque
            case 3:
                dep = deposito(conta);//abre a fun��o deposito e tamb�m a vari�vel dep�sito recebe o valor retornado pela fun��o
                if(dep == 1)
                {
                    break;//para o ciclo
                }
            break;
            case 4:
                trans = transferencia(conta);//abre a fun��o transfer�ncia e tamb�m a variavel trans recebe o valor retornado pela fun��o
                if(trans == 1)
                {
                    break;//para o ciclo
                }
            break;
            case 5:
                contratarLimite(conta);//abre a fun��o contratarLimite
            break;
            case 0:
                fclose(arquivo);//fecha o arquivo para n�o dar problemas futuros
                return 0;
            break;
            default :
                system("CLS");
                printf("Por favor digite uma opera��o v�lida!");//mensagem para o usu�rio
                printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
                getch();
            break;
        }
    }while(opcao!=0);
}
cedula(int n)
{//fun��o para contar c�dulas, e exibi-las
    int n100, n50, n20, n10;
    n100 = n/100;
    n50 = (n%100)/50;
    n20 = ((n%100)%50)/20;
    n10 = (((n%100)%50)%20)/10;
    if(n100 > 0)
    {//fun��o para verificar quantas c�dulas o caixa eletr�nico var expelir, as fun��es de baixo faz a mesma coisa.
        printf(" c�dulas(s) de R$100 : %i\n",n100);//mensagem para o usu�rio
    }
    if(n50 > 0)
    {
        printf(" c�dulas(s) de R$50 : %i\n",n50);//mensagem para o usu�rio
    }
    if(n20 > 0)
    {
        printf(" c�dulas(s) de R$20 : %i\n",n20);//mensagem para o usu�rio
    }
    if(n10 > 0)
    {
        printf(" c�dulas(s) de R$10 : %i\n",n10);//mensagem para o usu�rio
    }
}
Rcedula(int n)
{//fun��o que verifica se o usu�rio for sacar um valor diferente das c�dulas disponiveis 100,50,20 e 10 reais
    int n5, n4, n3, n2,n1;
    n5 = ((((n%100)%50)%20)%10)/5;
    n4 = (((((n%100)%50)%20)%10)%5)/4;
    n3 = ((((((n%100)%50)%20)%10)%5)%4)/3;
    n2 = (((((((n%100)%50)%20)%10)%5)%4)%3)/2;
    n1 = ((((((((n%100)%50)%20)%10)%5)%4)%3)%2)/1;
    if(n5 > 0)
        {//fun��o para verificar se o usu�rio escolheu um valor que n�o tem pode ser sacado porque n�o h� c�dulas no caixa eletr�nico, mesma coisa nos c�digo abaixo
            return 1;
        }else
        if(n4 > 0)
        {
            return 1;
        }else
            if(n3 > 0)
                {
                    return 1;
                }else
                    if(n2 > 0)
                        {
                            return 1;
                        }else
                            if(n1 > 0)
                                {
                                    return 1;
                                }
}
senha(char conta[])
{//fun��o para verificar a senha digitada pelo usu�rio, para poder acessar a conta
    char c,login[10], senha[10],lgn[15],shna[15];;
    int x=4, a=1, b=1,i,k,shna1;
    FILE *arq;
    arq = fopen(conta,"r");
    if (arq == NULL) // Se houve erro na abertura
    {
        printf(" Conta n�o existe\n");//mensagem para o usu�rio.
        getch();
        return 0;
    }
    shna1 = leituraArquivo(conta,2);//converter int para char
    itoa(shna1,shna,10);//converter int para char
for(k=0;k<4;k++)
    {       ini1:
            fflush(stdin);//limpa a streaming do teclado
            printf(" Senha.: ");
            i=0;
               do{
                   c=getch();
                   if(isprint(c))
                   {//Analisa se o valor de c e imprim�vel
                   senha[i]=c;
                   i++;
                   printf("*");//Imprimindo apenas o asterisco *
                   }
                   else if(c==8&&i)
                   {//8 e o caractere BackSpace na tabela ASCII, && a analisa se i e diferente de 0
                   senha[i]='\0';
                   i--;
                   printf("\b \b");//Apagando os caracteres digitados
                   }
                 }while(c!=13);//13 e o valor de ENTER na tabela ASCII
                  senha[i]='\0';
                  if(strlen(senha)<6)
                    {//verifica se a string conta possui 6 d�gitos.
                        printf("\n por favor digite 6 n�meros!");
                        getch();
                        system("CLS");
                        msg();
                        printf(" Por favor digite o n�mero da conta.\n 0 - Sair\n Conta: %s\n",conta);
                        goto ini1;//volta para o ini1, se a senha n�o possuir 6 d�gitos.
                    }
    b = strcmp(senha,shna);//compara se a avari�vel string login � igual a vari�vel string l. e se for iguais retorna 0
    if(b==0)
    {
        printf("\n        LOADING...");
        cont(conta);
        break;

    }else
        {
            system("CLS");
            msg();
            x--;
            printf("\a tente novamente chance(s) %i\n",x);
            printf(" Conta: %s\n",conta);
            if(x == 0)
            {
                printf("\n           CONTA BLOQUEADA!");
                printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
                getch();
            }
        }
    }
}
createCont(char conta[], char senha[])
{//fun��o para criar uma conta nova
 FILE *arq;
 arq = fopen(conta,"w");
 int senha1,conta1;
 conta1 = atoi(conta);//converter string para int
 gravarArquivo(conta,1,conta1);//linha 1 � a conta dentro do arquivo
 senha1 = atoi(senha);//converter string para int
 gravarArquivo(conta,2,senha1);//linha 2 � a senha dentro do arquivo
 gravarArquivo(conta,3,0);//linha � a 3 saldo
 gravarArquivo(conta,4,0);//linha � a 4 limite
}
verificarCont(char conta[])
{//fun��o para verificar a conta, se retornar 1 a conta existe, caso contr�rio n�o existe
 FILE *arq;
 arq = fopen(conta,"r");
 if(arq == NULL)
 {
    return 2;
 }else
    {
        return 1;
    }
}
/*****************EASTER EGG********************/
creditos()
{//fun��o para exibir creditos
printf("             v                                                            \n");
printf("         uBRBRB                                                           \n");
printf("        RBRBRBRBr                                                         \n");
printf("       rBRBRBRBRBR                                                        \n");
printf("        RBRBRBRBRBR                                                       \n");
printf("         RBRBRBRBF                                                        \n");
printf("       J7DRBRBRBRJ                                                        \n");
printf("   1BRBRBRBRB.   RBKBR3                                                   \n");
printf("  RBRBRBRBRBRBRB7  SZ2RE                  rB                              \n");
printf("HRBRBRBRBRBRBRBRBRE DR sBO              JRB                               \n");
printf("RBRBRBRBRBRBRBRBRBRBUBR: BR,           BRBR2                              \n");
printf(" PBRBRBRBRBRBRBRBRBRBRBRM ORB         BRBRBR                              \n");
printf("  KBRBRBRBRBRBRBRBRBRBRBRB  RB     E  RBRZ                                \n");
printf("   GBRBRBRBRBRBRBRBRBRBRBRB  RBKBRBRB                                     \n");
printf("    HBRBRBRBRBRBRBRBRBRBRBRB  rBRBRBR                                     \n");
printf("    .RBRBRBRBRBRBRBRBRBRBRBRBRORBRBi      ;uBRBRBRBR                      \n");
printf("    RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRB                    \n");
printf("    BRBRBRBRBRBRBRB ;RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBr                  \n");
printf("    RBRBRBRBRBRBRB1 RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBR                 \n");
printf("      JRBRBRBRBRBRB1BRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRJ               \n");
printf("          RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRB              \n");
printf("           RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBR            \n");
printf("            RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBRBi7RBRBRBRvsBRBRBRBRB       7RB\n");
printf("             RBRBRBRBRBRBRBRBRBRBRBRBRBJ      MRBRBRBP  BRBRBRBRBGi ,SBRBW\n");
printf("              RBRBRBRBRBRBRBRBRBRBRBRL        .BRBRBRB   xRBLPRBRBRBRBRB  \n");
printf("               RBRBRBRBRBRBRBRBRBRB            RBRBRBR2        RBRBRBR    \n");
printf("                             URJ               BRBRBRBR         RBRB      \n");
printf("                     RB       B      RB        xBRBRBRB          XH       \n");
printf("                     BRBR    LRL   BRBRK        RBRBRBRB                  \n");
printf("                    BR77BRBRBRBRBRBR0 BR        BRBRBRBR                  \n");
printf("                     u 7RBRBRBRBRBRBL      c    LBRBR                     \n");
printf("              :RBRBRBRBRBRBRBRBRBRBRBRBRBRBRBR   RBRD                     \n");
printf("              RBRBRBDR0DL    DR    73GSP201XRB.  BRBR                     \n");
printf("              BR             RB             RRB XRBRBR                    \n");
printf("              :;             BR                 RBRBRBRB                  \n");
printf("                             DB                 SRBRBRBRBRB               \n");
printf("                             BR                     .RRBRBR.              \n");
printf("                             :B                                           \n");
printf("//////////////////////////////////////////////////////////////////////////\n");
printf("*                                                                        *\n");
printf("*     #    ######   #####     ######     #    #     # #    #     #####   *\n");
printf("*    # #   #     # #     #    #     #   # #   ##    # #   #     #  #  #  *\n");
printf("*   #   #  #     # #          #     #  #   #  # #   # #  #      #  #     *\n");
printf("*  #     # #     #  #####     ######  #     # #  #  # ###        #####   *\n");
printf("*  ####### #     #       #    #     # ####### #   # # #  #         #  #  *\n");
printf("*  #     # #     # #     #    #     # #     # #    ## #   #     #  #  #  *\n");
printf("*  #     # ######   #####     ######  #     # #     # #    #     #####   *\n");
printf("*                                                                        *\n");
printf("*                                                        By Wesley Hjpr  *\n");
printf("//////////////////////////////////////////////////////////////////////////\n");
printf("\n");
}
/*****************EASTER EGG********************/
cadastro()
{//fun��o para fazer o cadastro do cliente
    int opcao,i,cont;
    char nconta[7],nsenha[7],c,d,s=1,senha1[7];
    inicio:
    system("CLS");
    msg();
    printf(" Por favor digite o n�mero da conta com 6 d�gitos.\n 0 - Sair\n Conta: ");//mensagem para o usu�rio.
    fflush(stdin);//fun��o para limpar a streaming do teclado.
    gets(nconta);//fun��o para pegar o que o usu�rio digitar
    cont = atoi(nconta);
    if(cont == 0)
    {//sair
        return 1;
    }
    if(strlen(nconta)<6)
    {//verifica se conta possui 6 d�gitos.
        printf(" por favor digite 6 n�meros!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto inicio;//volta para o inicio se a conta nao tiver 6 digitos.
    }
    if(verificarCont(nconta) == 1)
    {
        printf(" Conta j� existe! por favor digite um n�mero diferente.");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto inicio;//volta ao in�cio se a conta j� existir
    }
    inicio1:
    printf(" Por favor digite a senha da conta com 6 d�gitos. \n Senha: ");//mensagem para o usu�rio.
    fflush(stdin);//limpar streaming do teclado
    i=0;
    do
    {
        c=getch();
        if(isprint(c))
        {//Analisa se o valor de c e imprim�vel
            nsenha[i]=c;
            i++;
            printf("*");//Imprimindo apenas o asterisco *
        }
        else if(c==8&&i)
                {//8 e o caractere BackSpace na tabela ASCII, && a analisa se i e diferente de 0
                   nsenha[i]='\0';
                   i--;
                   printf("\b \b");//Apagando os caracteres digitados
                }
    }while(c!=13);//13 e o valor de ENTER na tabela ASCII
    nsenha[i]='\0';
    if(strlen(nsenha)<6)
    {//verifica se conta possui 6 d�gitos.
        printf("\n por favor digite 6 n�meros!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        system("CLS");
        msg();
        printf(" Por favor digite o n�mero da conta com 6 d�gitos.\n 0 - Sair\n Conta: %s\n",nconta);//mensagem para o usu�rio.
        goto inicio1;//volta para o inicio1 se a senha n�o tiver 6 d�gitos.
    }
    printf("\n digite a senha novamente.\n Senha: ");//mensagem para o usu�rio.
    i=0;
    do
    {
        d=getch();
        if(isprint(d))
        {//Analisa se o valor de c e imprim�vel
            senha1[i]=d;
            i++;//incrementa 1 a vari�vel
            printf("*");//Imprimindo apenas o asterisco * quando o usu�rio digitar
        }
        else if(d==8&&i)
                {//8 e o caractere BackSpace na tabela ASCII, && a analisa se i e diferente de 0
                    senha1[i]='\0';
                   i--;//decrementa 1 a vari�vel
                   printf("\b \b");//Apagando os caracteres digitados
                }
    }while(d!=13);//13 e o valor de ENTER na tabela ASCII
    senha1[i]='\0';
    s = strcmp(senha1,nsenha);//compara se a avari�vel string login � igual a vari�vel string l. e se for iguais retorna 0
    if(s==0)
    {
        createCont(nconta,nsenha);
        printf("\n Conta feita com sucesso!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
    }else
        {
            printf("\n senha n�o corresponde! digite novamente ");//mensagem para o usu�rio.
            printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
            getch();
            system("CLS");
            msg();
            printf(" Por favor digite o n�mero da conta com 6 d�gitos.\n 0 - Sair\n Conta: %s\n",nconta);//mensagem para o usu�rio.
            goto inicio1;
        }
}
entrarConta()
{//fun��o para entrar na conta
    int cont;
    char nconta[7];
    ini:
    system("CLS");
    msg();//fun��o para exibir a mensagem do caixa eletr�nico
    printf(" Por favor digite o n�mero da conta.\n 0 - Sair\n Conta: ");//mensagem para o usu�rio.
    fflush(stdin);//fun��o para limpar a streaming do teclado
    gets(nconta);//fun��o para pegar o que o usu�rio digitar
    cont = atoi(nconta);//fun��o para converter string em int
    if(cont == 0)
    {//sair
        return 1;// retorna 1
    }
    if(strlen(nconta)<6)
    {//verifica se conta possui 6 d�gitos.
        printf(" por favor digite 6 n�meros!");//mensagem para o usu�rio.
        printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
        getch();
        goto ini;//volta para o ini se a conta n�o tiver 6 d�gitos.
    }
    senha(nconta);//executa fun��o para verificar se o usu�rio digitou a senha corretamente
}
int main()
{//fun��o principal do programa
        int opcao,i,cont,cdtro,entrcnta;
        char nconta[7],nsenha[7],c,d,s=1,senha1[7];
        setlocale(LC_ALL,"portuguese");//fun��o para poder funcionar a acentua��o no software.
    do
    {//fun��o que faz um ciclo
        system("CLS");//fun��o para limpar a tela
        msg();//fun��o para exibir mensagem do caixa eletr�nico
        printf(" O que deseja fazer:\n 1 - Cadastrar Conta.\n 2 - Entrar Conta.\n 0 - Sair\n ");//mensagem para o usu�rio.
        scanf("%i",&opcao);//fun��o para pegar o que o usu�rio digitar
        switch(opcao)
        {//fun��o para verificar a op��o digitada pelo usu�rio
            case 0:
            break;//fun��o para parar o ciclo
            case 1:
                cdtro = cadastro();//abre a fun��o cadastro e tamb�m a  vari�vel cdtro recebe o valor retornado pela fun��o
                if(cdtro == 1)
                {//se cdtro retornar 1, vair parar o caso 1 das opera��es
                    break;//fun��o para parar o ciclo
                }
            break;//fun��o para parar o ciclo
            case 2:
                entrcnta = entrarConta();//abre a fun��o transfer�ncia e tamb�m a  vari�vel entrcnta recebe o valor retornado pela fun��o
                if(entrcnta == 1)
                {//se entrcnta retornar 1 para o caso 2
                    break;//fun��o para parar o ciclo
                }
            break;//fun��o para parar o ciclo
/*****************EASTER EGG********************/
            case 1337:
                system("CLS");//fun��o para limpar a tela
                creditos();//fun��o para exibir os creditos
                printf(" Pressione algo para continuar.");//exibe mensagem na tela
                getch();
            break;//fun��o para parar o ciclo
/*****************EASTER EGG********************/
            default :
                system("CLS");//fun��o para limpar a tela
                printf(" Por favor digite uma opera��o v�lida!");//mensagem para o usu�rio.
                printf("\n\n Pressione algo para continuar.");//exibe mensagem na tela
                getch();
            break;//fun��o para parar o ciclo
        }
    }while(opcao!=0);//termina o ciclo quando o usu�rio digitar 0
    return 0;//retorna 0 para finalizar o programa
}
