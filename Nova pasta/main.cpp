/* Programa bancario !
Algumas obs: O cliente precisa depositar um valor para abertura da conta, esse deposito caira na conta poupança do cliente
*/

#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
//#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
//#include <windows.h>
using namespace std;

// ***********variaveis de cadastro***************
struct cadastro{
char nome_correntista_cadastro [20];
char senha_cadastro[5];
int cpf_cadastro[20];
int rg_cadastro[20];
int idade_cadastro[5];
int agencia_cadastro[2];
int numero_conta_cadastro[2];
};

struct cadastro Cadastro;

//***************Variaveis de acesso****************

struct login{
char senha_acesso[5];
int agencia_acesso[2];
int numero_conta_acesso[2];
};
struct login Login;

//************** operaçoes *************************

float deposito_conta_corrente;
float deposito_conta_poupanca;
float transferencia;
float saldo_conta_corrente;
float saldo_conta_poupanca;

//selecao

int i;
static int op;
int selecao_inicial;



//TELAS
void menu_inicial(void);

void tela_transferencia();
void tela_deposito();

void tela_saldo();
void cadastro();
void tela_login();
/*
void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);
}
*/

int main(){
setlocale(LC_ALL, "Portuguese");
menu_inicial();  



return 0;
system("pause");
}



//INICIO

void menu_inicial(){
system("cls");
//system ("color 71");gotoxy(70,1); system("date/t");  gotoxy(72,2) ;system("time/t");

cout<<("\t########################################################\n");
       cout<<("\t#                 BANCO BWO @                          #\n");
       cout<<("\t#                SEJA BEM VINDO                        #\n");
       cout<<("\t########################################################\n\n\n");


cout<<("Informe uma das opções abaixo!\n");
cout<<("0- Acessar correntista\n");
cout<<("\n");
cout<<("1- Para cadastro de novo correntista!\n");
cout<<("\n");
cout<<("2- Deposito \n");
cout<<("\n");
cout<<("5- sair\n"); cout<<("\n");  
cout<<("seleção:");
cin>>selecao_inicial;
system("cls");
switch (selecao_inicial)
{

 		
		case 0:tela_login();
		break;
		
		case 1:cadastro();
		break;
		
		case 2:tela_deposito();
		break;
						
//		case 4: sair ();
		
		
		default:
			cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			system("pause");
			system("cls");
			return menu_inicial();			
}
}

//CADASTRO DO CORRENTISTA 
 void cadastro(){
int opc_cadastro;

do
{
//gotoxy(70,1); system("date/t");  gotoxy(72,2) ;system("time/t");
	cout<<("\t########################################################\n");
       cout<<("\t#                 TELA DE CADASTRO                     #\n");
       cout<<("\t#                                                      #\n");
       cout<<("\t########################################################\n\n\n");

cout<<("informe o nome do correntista!\n");gotoxy (31,9);

fflush(stdin);
gets(Cadastro.nome_correntista_cadastro);
cout<<("\n");
cout<<("informe o CPF\n");gotoxy (15,11);
cin>>Cadastro.cpf_cadastro[20];
cout<<("\n");
cout<<("informe o RG\n");gotoxy (14,13);
cin>> Cadastro.rg_cadastro[20];
cout<<("\n");
cout<<("informe Sua idade\n");gotoxy (19,15);
cin>>Cadastro.idade_cadastro[20];
cout<<("\n");
cout<<("informe um numero de agencia");gotoxy (30,17);cin>>Cadastro.agencia_cadastro[20];
cout<<("\n");
cout<<("informe um numero de conta	");gotoxy (28,19); cin>>Cadastro.numero_conta_cadastro[20];
cout<<("\n");
cout<<("informe uma senha de 5 digitos para cadastro"); cin>>Cadastro.senha_cadastro[5];

cout<<("INFORME UM VALOR A SER DEPOSITADO NA CONTA-POUPANÇA PARA PROSSEGUIR COM A ABERTURA DA CONTA !\n");
cin>>deposito_conta_poupanca;

saldo_conta_poupanca = (deposito_conta_poupanca) + (saldo_conta_poupanca);
//system("cls");
cout<<("CADASTRO REALIZADO COM SUCESSO!!!!!\n");
cout<<("informe 1 para começar e qualquer outro numero para encerrar\n");
cin>>opc_cadastro;
}while (opc_cadastro ==1);
system("cls");
	return menu_inicial();

}

//TELA DE LOGIN
void tela_login(){
int opc_tela_login1	;

cout<<("\t########################################################\n");
       cout<<("\t#                 TELA DE ACESSO                       #\n");
       cout<<("\t#                                                      #\n");
       cout<<("\t########################################################\n\n\n");

cout<<("informe sua agência:");cin>> Login.agencia_acesso[20];
cout<<("\n");
cout<<("Informe a conta:");cin>> Login.numero_conta_acesso[20];
cout<<("\n");
cout<<("informe a senha:\n");gotoxy (17,11);
cin>>Login.senha_acesso[5];
system("cls");
if (Login.agencia_acesso[2] == Cadastro.agencia_cadastro[2] &&  Login.numero_conta_acesso[2]== Cadastro.numero_conta_cadastro[2] && Login.senha_acesso[5]==Cadastro.senha_cadastro[5]){
	cout<<("\t########################################################\n");
       cout<<("\t#                   TELADE SALDO                       #\n");
       //cout<<"\t#       Ola     " <<Cadastro.nome_correntista_cadastro       <<"#\n";
       cout<<("\t########################################################\n\n\n");
	
	cout<<"Bem vindo \n" ,"\n";cout<<("\n");
	cout<<("\n Informe uma das opções abaixo\n");
	cout<<("1- Saldo\n");
	cout<<("2- Transferencia\n");
	
	cin>>opc_tela_login1;
	
	switch(opc_tela_login1){
		
	case 1:tela_saldo();
		break;
		
	case 2: tela_transferencia();
		break;
		
	
	}


}
else

cout<<("conta nao cadastrada\n");
system("pause");
system("cls");
return menu_inicial();

}


//DEPOSITO
void tela_deposito(){
	int op_deposito;
cout<<("******** BEM VINDO A TELA DE DEPOSITO!\n");
cout<<("Pressione 1 para deposito em conta corrente e 2 para deposito em poupança\n");
cin>>op_deposito;
switch (op_deposito){
		case 1:
		cout<< ("informe a agencia");
		cin>> Cadastro.agencia_cadastro[20];
		cout<< ("informe o numero da conta");
		cin>>Cadastro.numero_conta_cadastro[20];
		cout<<("Informe o valor a ser depositado!");
		cin>>deposito_conta_corrente;
		saldo_conta_corrente = ( deposito_conta_corrente ) + ( saldo_conta_corrente );
		cout<<("*********-------------------------------********* \n");
		cout<<("*********DEPOSITO REALIZADO COM SUCESSO********* \n");
		cout<<("*********-------------------------------********* \n");
		break;
			case 2:
			cout<< ("informe a agencia");
			cin>> Cadastro.agencia_cadastro[20];
			cout<< ("informe o numero da conta");
			cin>> Cadastro.numero_conta_cadastro[20];
			cout<<("Informe o valor a ser depositado!");
			cin>> deposito_conta_poupanca ;
			saldo_conta_poupanca= ( deposito_conta_poupanca) + (saldo_conta_poupanca);
			cout<<("*********-------------------------------********* \n");
			cout<<("*********DEPOSITO REALIZADO COM SUCESSO********* \n");
			cout<<("*********-------------------------------********* \n");
			break;
			
				default:
				cout<<("****************ERRO************\n");
				cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
				system("pause");
				system("cls");
				return tela_deposito();
				
}

system("pause");
	return menu_inicial();
	
	

}

void tela_saldo(){

cout<<("\t########################################################\n");
       cout<<("\t#                   TELA DE SALDO                       #\n");
       //cout<<"\t#       Ola     " <<Cadastro.nome_correntista_cadastro          <<"#\n";
       cout<<("\t########################################################\n\n\n");

cout<<"Voce possui R$:"<<saldo_conta_corrente <<" em sua conta corrente\n";

cout<<"Você possui R$:"<<saldo_conta_poupanca<<"Em sua puopança\n";
cout<<("\n O nome do correntista é\n");
//cout<<Login.nome_correntista[40];
system("pause");
system("cls");
return menu_inicial();

	
}

void tela_transferencia(){

int opc_transferencia;
system ("cls");
cout<<("*********-------------------------------************ \n");	
cout<<("**********BEM VINDO A TELA DE Transferencia ***********");
cout<<("*********-------------------------------************* \n");	
cout<<("Informe o numero da conta seguido da agência!\n");
cin>> Cadastro.numero_conta_cadastro[20];
cin>>Cadastro.agencia_cadastro[20];
cout<<("Informe o valor a ser depositado!\n");
cin>>transferencia;
if (transferencia > saldo_conta_corrente){

	cout<<("Saldo insuficiente\n");
	cout<<("pressione 1 para fazer a transferência de outro valor ou  2 se deseja voltar ao menu inicial \n");
    cin>>opc_transferencia;
    switch(opc_transferencia){
    	case 1:return tela_transferencia();
    	break;
    	case 2: return menu_inicial();
    	break;
    }
    

}
	
else {
saldo_conta_corrente=saldo_conta_corrente - transferencia;

cout<<("Operecao realizada com sucesso\n");
 return menu_inicial();

}

//ENCERRAR PROGRAMA


}




