//Computação Grafica
//João Henrique Lima Duarte
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>
#include <locale.h>

//Variaveis Globais
static int raio;
static int centrox;
static int centroy;
static int cor;
static int driver, mode;

//Funcoes
void PlotPoint(int xc, int yc, int r, int c){

	detectgraph(&driver, &mode); // Obtém o driver gráfico e o modo de acordo com o hardware
	initgraph(&driver, &mode, ""); // inicializa modo gráfico de acordo com os parâmetros obtidos

	setcolor(c);
    circle(xc, yc, r);
	system("pause");
    closegraph(); // fecha modo gráfico (OBS: Ta bugando no final)

}

void PlotMidPoint(int x, int r, int c){

	putpixel(x, r, c);
	putpixel(r, x, c);
	putpixel(r, -x, c);
	putpixel(x, -r, c);
	putpixel(-x, -r, c);
	putpixel(-r, -x, c);
	putpixel(-r, x, c);
	putpixel(-x, r, c);

}

void DDA(){

float X1,Y1,X2,Y2;
int step;

printf("Digite a coordenada de X1: ");
scanf("%f", &X1);
printf("Digite a coordenada de Y1: ");
scanf("%f", &Y1);
printf("Digite a coordenada de X2: ");
scanf("%f", &X2);
printf("Digite a coordenada de Y2: ");
scanf("%f", &Y2);

float X,Y,Xinc,Yinc;
step = fabs(X2 -X1);

if(fabs(Y2 -Y1)  > step)
	step =fabs(Y2 -Y1);

Xinc= (X2 -X1)/step;
Yinc= (Y2 -Y1)/step;
X = X1;
Y = Y1;

initwindow(640,480);

	for (int i = 0; i <= step; i++) {
        putpixel (X,Y,9);
        X += Xinc;
        Y += Yinc;
        delay(25);

    }

	system("pause");
	closegraph();
}

void bresenham() {

   int x1, y1,x2, y2;
   int m_new = 2 * (y2 - y1);
   int slope_error_new = m_new - (x2 - x1);

printf("Digite a coordenada de X1: ");
scanf("%d", &x1);
printf("Digite a coordenada de Y1: ");
scanf("%d", &y1);
printf("Digite a coordenada de X2: ");
scanf("%d", &x2);
printf("Digite a coordenada de Y2: ");
scanf("%d", &y2);

initwindow(640,480);

   for (int x = x1, y = y1; x <= x2; x++) {

      slope_error_new += m_new;

      setcolor (RED);
	  line (x, y, x1 ,y1);
	  delay(25);

      if (slope_error_new >= 0){
         y++;
         slope_error_new  -= 2 * (x2 - x1);
     }
   }
   system("pause");
   closegraph();
}

void CircleSimple(){

int r;
int xc;
int yc;
int c;

printf("Digite o Raio do circulo: ");
scanf("%d", &raio);

system("cls");
printf("\t A janela esta em 640 x 480 \nPara centralizar o circulo coloque X 320, Y 240\n\n\n");
printf("Digite a Coordenada X do circulo: ");
scanf("%d", &centrox);
printf("Digite a Coordenada Y do circulo: ");
scanf("%d", &centroy);

system("cls"); //Limpar a tela

do{

	printf("Selecione uma cor!!!\n\n");
	printf("Preto 0 \nAzul 1 \nVerde 2 \nCiano 3 \nVermelho 4 \nMagenta 5 \nMarrom 6 \nCinza 7 \nCinza 8 \nAzul claro 9");
	printf("\nVerde claro 10 \nCiano claro 11 \nVermelho claro 12 \nMagenta claro 13 \nAmarelo 14 \nBranco 15 \nVoltar 16 \n\nDigite a escolha: ");
	scanf("%d", &cor);

	system("cls");

		if(cor == 16){
			CircleSimple();
		}

	}while (cor > 16);


r=raio;
xc=centrox;
yc=centroy;
c=cor;

PlotPoint(xc, yc, r, c);

//return 0;
}

void CircleMidPoint(){

int r, xc, yc, c, p, x=0;

printf("Digite o Raio do circulo: ");
scanf("%d", &raio);

system("cls");
printf("\t A janela esta em 640 x 480 \nPara centralizar o circulo coloque X 320, Y 240\n\n\n");
printf("Digite a Coordenada X do circulo: ");
scanf("%d", &centrox);
printf("Digite a Coordenada Y do circulo: ");
scanf("%d", &centroy);

system("cls"); //Para Limpar a tela

do{

	printf("Selecione uma cor!!!\n\n");
	printf("Preto 0 \nAzul 1 \nVerde 2 \nCiano 3 \nVermelho 4 \nMagenta 5 \nMarrom 6 \nCinza 7 \nCinza 8 \nAzul claro 9");
	printf("\nVerde claro 10 \nCiano claro 11 \nVermelho claro 12 \nMagenta claro 13 \nAmarelo 14 \nBranco 15 \nVoltar 16 \n\nDigite a escolha: ");
	scanf("%d", &cor);

	system("cls");

	if(cor == 16){
		CircleMidPoint();
	}

	}while (cor > 16);


r=raio;
xc=centrox;
yc=centroy;
c=cor;
p=1-r;

	detectgraph(&driver, &mode); // Obtém o driver gráfico e o modo de acordo com o hardware
	initgraph(&driver, &mode, ""); // inicializa modo gráfico de acordo com os parâmetros obtidos
	PlotMidPoint(x, r, c);
	delay(25);

while (r > x){

	if(p < 0){
		p=p + 2*x + 1;
	}

	else{
		p=p + 2*x - 2*r + 1;
		r--;
	}
	x++;

	PlotMidPoint(x, r, c);
	delay(25);
}

	system("pause");
    closegraph(); // fecha modo gráfico (OBS: Ta bugando no final)

}

int main(){

	int escolha = 0;
	system("color 0E");
	setlocale(LC_ALL, "Portuguese"); //Para corrigir as acentuações

do{

	printf("Selecione a opção desejada:\n\n");
	printf("1-DDA\n");
	printf("2-Bresenham \n");
	printf("3-CircleSimples \n");
	printf("4-CircleMidPoint \n");
	printf("9-Sair\n\n");
	printf("Escolha: ");

	scanf("%d", &escolha);

	system("cls");

	switch(escolha){
		case 1: DDA();
		break;
		case 2: bresenham();
		break;
		case 3: CircleSimple();
		break;
		case 4: CircleMidPoint();
		break;
		default: printf("Escolha não encontrada\n");
		break;
	}

	system("cls");

	}while (escolha != 9);

	printf("Computação Gráfica - Univasf\n");
	printf("Atividades da disciplina\n");
	system("pause");
}
