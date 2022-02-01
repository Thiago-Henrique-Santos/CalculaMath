#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void menu();
int VerificarConta(char sinal[]);
int delta(int a, int b, int c);
void x1(int b, int delta, int a);
void x2(int b, int delta, int a);
char coeficiente_b(int b);
char coeficiente_c(int c);
int fibonacci(int n);
float mmci(int numi[], int quant);
float mmcf(float numf[], int quant);
int mdc(int numi[], int quant);

main()
{
	//MDC
	//MMC manutenção
	
	setlocale(LC_ALL, "Portuguese");//habilita a acentuação para o português
	system("color 1f");
	int i, j, k, quant, ni, calci=0, expoentei;
	char sinal[50], T_Algarismo, lixo, T_Expoente, continuar[4]="Sim";
	float nf, calcf=0, expoentef, dividendo, divisor, FloatToInt;
	
	//Introdução
	while(!strcmp(continuar, "Sim") || !strcmp(continuar, "sim"))
	{
		system("cls");
		printf("Bem-vindo(a) ao Calcula Math!\n");
	
		printf("\nContas que você pode realizar na Calcula Math:\n");
		menu();
		
		printf("\nDigite a conta que você deseja realizar:");
		scanf("%[^\n]s", sinal);
		scanf("%c", &lixo);
		
		while(VerificarConta(sinal)==1)
		{
			system("cls");
			printf("Bem-vindo(a) ao Calcula Math!\n");
			
			printf("\nContas que você pode realizar na Calcula Math:\n");
			menu();
			
			printf("\nOps! Você digitou algo errado. Verifique se escreveu tudo corretamente, ou se for o caso, veja se a Calcula Math realiza a conta que deseja.\n");
			printf("Digite novamente a conta que você deseja realizar: ");
			scanf("%[^\n]s", sinal);
			scanf("%c", &lixo);
		}
		
		//==========Mensagem de manutenção==========
		while(strcmp(sinal, "mmc")==0 || strcmp(sinal, "mdc")==0)
		{
			printf("\nEsta conta está em manutenção!\n\n", '"', '"');
			printf("Por favor, escolha outra conta: ");
			scanf("%[^\n]s", sinal);
			scanf("%c", &lixo);
		}
		//===========================================
		
		
		//Fibonacci
		if(strcmp(sinal, "fibonacci")==0)
		{
			printf("Insira o número de que deseja saber o fibonacci: ");
			scanf("%d", &ni);
			calci=fibonacci(ni);
			while(ni<0)
			{
				printf("Fibonacci é feito apenas com números inteiros e positivos. Verifique seu número e insira um válido, por favor!\n");
				printf("Insira o número: ");
				scanf("%d", &ni);
			}
			printf("Fibonacci = %d\n", calci);
			break;
		}
		
		//raiz quadrada simples
		if(strcmp(sinal, "raiz quadrada simples")==0)
		{
			printf("Como esta calculadora está com base em números reais, para realizar uma raiz quadrada, é permitido apenas números inteiros.\n Sendo assim, caso o resultado do número não for inteiro, será emitido %cNúmero irracional!%c\n", '"', '"');
			printf("Insira o número em que deseja saber a raiz: ");
			scanf("%f", &nf);
			calcf=sqrt(nf);
			FloatToInt=calcf-(int)calcf;
			if(FloatToInt>0.0)
			{
				printf("Raiz = Número irracinal!");
			}
			else
			{
				printf("Raiz = %.0f\n", calcf);
			}
			break;
		}
		
		//equação do segundo grau
		if(strcmp(sinal, "equacao do segundo grau")==0)
		{
			int a, b, c, delta_resultado, resultado_x[2]; //resultado_x: [0]=x1, [1]=x2
			char sinais_coeficientes[2]; //sinais_coeficientes: [0]=b, [1]=c, a não precisa por ser o primeiro
			printf("Insira o valor do coeficiente a: ");
			scanf("%d", &a);
			printf("Insira o valor do coeficiente b: ");
			scanf("%d", &b);
			sinais_coeficientes[0]=coeficiente_b(b);
			printf("Insira o valor do coeficiente c: ");
			scanf("%d", &c);
			sinais_coeficientes[1]=coeficiente_c(c);
			printf("A fórmula da equação: %dx²%c%dx%c%d\n", a, sinais_coeficientes[0], b, sinais_coeficientes[1], c);
			delta_resultado=delta(a, b, c);
			printf("Delta = %d\n", delta_resultado);
			x1(b, delta_resultado, a);
			x2(b, delta_resultado, a);
			break;
		}
		
		//divisão simples
		if(strcmp(sinal, "divisao simples")==0)
		{
			printf("Insira o dividendo%cnúmero que será dividido%c: ", '(', ')');
			scanf("%f", &dividendo);
			printf("Insira o divisoro%cnúmero que irá dividir o dividendo%c: ", '(', ')');
			scanf("%f", &divisor);
			calcf=dividendo/divisor;
			FloatToInt=calcf-(int)calcf;
			if(FloatToInt>=0.1)
			{
				printf("O resultado é: %.2f.", calcf);
			}
			else
			{
				printf("O resultado é: %.0f.", calcf);
			}
			break;
		}
		
		//Fatorial
		if(strcmp(sinal, "fatorial")==0)
		{
			printf("Digite o número que você deseja ver o fatorial: ");
			scanf("%d", &ni);
			calci=1;
			for(i=1; i<=ni; i++)
			{
				calci=calci*i;
			}
			printf("O fatorial do seu número é: %d.", calci);
			break;
		}
		
		//continuação da introdução para as contas que precisam dessa parte
		printf("(f=decimal, e i=inteiro) Agora digite o tipo de algarismo que vai usar: ");
		scanf("%c", &T_Algarismo);
		scanf("%c", &lixo);
		
		//Potenciação
		if(strcmp(sinal, "potenciacao simples")==0)
		{
			printf("Digite o número que você quer saber a potência:");
			if(T_Algarismo=='i')
			{
				scanf("%d", &ni);
			}
			if(T_Algarismo=='f')
			{
				scanf("%f", &nf);
			}
			
			printf("(f=decimal, e i=inteiro) Escolha qual será o tipo de seu expoente: ");
			scanf("\n%c", &T_Expoente);
			printf("Digite o expoente: ");
			if(T_Expoente=='i')
			{
				scanf("%d", &expoentei);
			}
			else if(T_Expoente=='f')
			{
				scanf("%f", &expoentef);
			}
			
			if(T_Algarismo=='i')
			{
				if(T_Expoente=='i')
				{
					calci=pow(ni, expoentei);
					printf("Resultado: %d\n", calci);
				}
				if(T_Expoente=='f')
				{
					calcf=pow(ni, expoentef);
					printf("Resultado: %.2f\n", calcf);
				}
			}
			if(T_Algarismo=='f')
			{
				if(T_Expoente=='i')
				{
					calcf=pow(nf, expoentei);
					printf("Resultado: %.2f\n", calcf);
				}
				if(T_Expoente=='f')
				{
					calcf=pow(nf, expoentef);
					printf("Resultado: %.2f\n", calcf);
				}
			}
			break;
		}
		
		//fim introdução para algumas operações
		printf("Estamos quase no final. Agora digite quantos números você vai usar em sua conta: ");
		scanf("%d", &quant);
		printf("Por fim, digite os números de sua conta: ");
		
		//soma
		if(strcmp(sinal, "soma simples")==0)
		{
			if(T_Algarismo=='i')
	        {
		    	for(i=1; i<=quant; i++)
	    		{
	    			scanf("%d", &ni);
	    			calci=calci+ni;
		     	}
		     	printf("Resultado: %d\n", calci);
	    	}
			if(T_Algarismo=='f')
	    	{
	    	 	for(i=1; i<=quant; i++)
	     		{
				     scanf("%f", &nf);
			 	     calcf=calcf+nf;
	          	}
	          	printf("Resultado: %.2f\n", calcf);
	      	}
	      	break;
		}
		
		//subtração
		if(strcmp(sinal,"subtracao simples")==0)
		{
			if(T_Algarismo=='i')
	   	    {
		    	for(i=1; i<=quant; i++)
	    		{
	    			scanf("%d", &ni);
	    			if(i==1)
	    			{
	    				calci=ni;
	    			}
	    			else
	    			{
	    		    	calci=calci-ni;
	    			}
		     	}
		     	printf("Resultado: %d\n", calci);
	    	}
			if(T_Algarismo=='f')
	    	{
	    	 	for(i=1; i<=quant; i++)
	     		{
				     scanf("%f", &nf);
				     if(i==1)
				     {
				     	calcf=nf;
				     }
				     else
				     {
			 	        calcf=calcf-nf;
				      }
	          	}
	          	printf("Resultado: %.2f\n", calcf);
	      	}
	      	break;
		}
		
		//multiplicação
		if(strcmp(sinal, "multiplicacao simples")==0)
		{
			if(T_Algarismo=='i')
	        {
	        	calci=1;
		    	for(i=1; i<=quant; i++)
	    		{
	    			scanf("%d", &ni);
	    			calci=calci*ni;
		     	}
		     	printf("Resultado: %d\n", calci);
	    	}
			if(T_Algarismo=='f') //[!]No DevC++ não está rodando corretamente esta parte. Mas em outros compiladores está
	    	{
	    		calcf=1.0;
	    	 	for(i=1; i<=quant; i++)
	     		{
				    scanf("%f", &nf);
			 	    calcf=calcf*nf;
	          	}
	          	printf("Resultado: %.2f\n", calcf);
	      	}
	      	break;
		}
		
		/*==========Manutenção==========
		//MMC
		if(strcmp(sinal, "mmc")==0)
		{
			int numi[quant];
			float numf[quant];
			if(T_Algarismo=='i')
			{
				for(i=0; i<quant; i++)
				{
					scanf("%d", &numi[i]);
				}
				calcf=mmci(numi, quant);
			}
			else if(T_Algarismo=='f')
			{
				for(i=0; i<quant; i++)
				{
					scanf("%f", &numf[i]);
				}
				calcf=mmcf(numf, quant);
			}
			if(calcf-(int)calcf>0.0)
			{
				printf("MMC = %.2f\n", calcf);
			}
			else
			{
				printf("MMC = %.0f\n", calcf);
			}
			break;
		}
		================================*/
		
		/*==========Manutenção==========
		//MDC
		if(strcmp(sinal, "mdc")==0)
		{
			int numi[quant];
			if(T_Algarismo=='f')
			{
				printf("MDC é feito apenas com números inteiros.\n Insira números inteiros para ver o MDC\n");
				printf("Insira os números: ");
			}
			for(i=0; i<quant; i++)
			{
				scanf("%d", &numi[i]);
			}
			calcf=mdc(numi, quant);
			printf("MDC = %.0f\n", calcf);
			break;
		}
		================================*/
		
		printf("Deseja realizar mais uma conta?\n");
		printf("R: ");
		scanf("%s", continuar);
		//mensagem de erro, abaixo
		while(!strcmp(continuar, "Sim") && !strcmp(continuar, "sim") && !strcmp(continuar, "Não") && !strcmp(continuar, "não"))
		{
			printf("Digite %csim%c ou %cnão%c.\n", '"', '"');
			printf("R: ");
			scanf("%s", continuar);
		}
	}
	printf("\n•Obrigado por usar a Calcula Math!\n");
	printf("Não esqueça que possui o download dela no site criado para a sala de informática do IF Portas Abertas 2019.\n");
}

void menu()
{
	printf("=================================================================\n");
	printf("soma simples    |  subtracao simples       | multiplicacao simples\n");
	printf("divisao simples |  potenciacao simples     | raiz quadrada simples\n");
	printf("fatorial        |  fibonacci               | mdc\n");
	printf("mmc             |  equacao do segundo grau |\n");
	printf("=================================================================\n");
}

int VerificarConta(char sinal[])
{
	if(strcmp(sinal, "soma simples")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "subtracao simples")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "multiplicacao simples")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "divisao simples")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "potenciação simples")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "raiz quadrada simples")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "fatorial")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "fibonacci")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "mdc")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "mmc")==0)
	{
		return 0;
	}
	if(strcmp(sinal, "equacao do segundo grau")==0)
	{
		return 0;
	}
	return 1;
}

//funções equação do segundo grau
int delta(int a, int b, int c)
{
	int delta = pow(b, 2)-4*a*c;
	return delta;
}

//x1 e x2
void x1(int b, int delta, int a)
{
	float x1, raiz_delta;
	raiz_delta=sqrt(delta);
	if(delta<0 || (raiz_delta-(int)raiz_delta>0.0))
	{
		printf("x1 = Número irracional!\n");
	}
	else
	{
		x1=(-b+sqrt(delta))/(2*a);
		printf("x1 = %.2f\n", x1);
	}
}

void x2(int b, int delta, int a)
{
	float x2, raiz_delta;
	raiz_delta=sqrt(delta);
	if(delta<0 || (raiz_delta-(int)raiz_delta>0.0))
	{
		printf("x2 = Número irracional!\n");
	}
	else
	{
		x2=(-b-sqrt(delta))/(2*a);
		printf("x2 = %.2f\n", x2);
	}
}

//sinais dos coeficientes
char coeficiente_b(int b)
{
	char sinal_coeficiente;
	if(b>=0)
	{
		sinal_coeficiente='+';
	}
	else if(b<0)
	{
		sinal_coeficiente='-';
	}
	return sinal_coeficiente;
}

char coeficiente_c(int c)
{
	char sinal_coeficiente;
	if(c>=0)
	{
		sinal_coeficiente='+';
	}
	else if(c<0)
	{
		sinal_coeficiente='-';
	}
	return sinal_coeficiente;
}

//função para fibonacci - arrumar erro ainda
int fibonacci(int n)
{
	int i, resultado, n_anterior, fibonacci[n];
	fibonacci[0]=0;
	fibonacci[1]=1;
	if(n==0)
	{
		resultado=fibonacci[0];
	}
	else if(n==1)
	{
		resultado=fibonacci[1];
	}
	else if(n>1)
	{
		for(i=2;i<=n; i++)
		{
			fibonacci[i]=fibonacci[(i-1)]+fibonacci[(i-2)];
		}
		resultado=fibonacci[n];
	}
	return resultado;
}

//funções MMC
float mmci(int numi[], int quant)
{
	int i, j, k, num_divisor=2, guardador[200000], verif_repetir;
	float resultado, mmc=1;
	for(i=0; ; i++)
	{
		verif_repetir=0;
		for(j=0; j<quant; j++)
		{
			resultado=numi[j]/num_divisor;
			if(resultado-(int)resultado!=0.0)
			{
				resultado=numi[j]*num_divisor;
			}
			numi[j]=resultado;
			
			if(fmod(resultado, num_divisor)==0)
			{
				verif_repetir++;
			}
		}
		guardador[i]=num_divisor;
		if(verif_repetir==0)
		{
			num_divisor++;
		}
		else
		{
			num_divisor=num_divisor;
		}
	}
	for(k=0; k<i; k++)
	{
		mmc=mmc*guardador[k];
	}
	return mmc;
}

float mmcf(float numf[], int quant)
{
	
}

//função MDC
int mdc(int numi[], int quant)
{
	int i, j, k, num_divisor=2, guardador[200000], verif_repetir, verif_igual;
	float resultado, mdc=1;
	for(i=0; ; i++)
	{
		verif_repetir=0;
		verif_igual=0;
		for(j=0; j<quant; j++)
		{
			resultado=numi[j]/num_divisor;
			if(resultado-(int)resultado!=0.0)
			{
				resultado=numi[j]*num_divisor;
			}
			numi[j]=resultado;
			
			if(fmod(resultado, num_divisor)==0)
			{
				verif_repetir++;
			}
		}
		for(k=0; k<quant; k++)
		{
			if(k=0)
			{
				
			}
			else
			{
				if(numi[k]==numi[(k-1)])
				{
					verif_igual++;
				}
			}
		}
		if(verif_igual==2)
		{
			guardador[i]=num_divisor;
		}
		
		if(verif_repetir==0)
		{
			num_divisor++;
		}
		else
		{
			num_divisor=num_divisor;
		}
	}
	for(k=0; k<i; k++)
	{
		mdc=mdc*guardador[k];
	}
	return mdc;
}