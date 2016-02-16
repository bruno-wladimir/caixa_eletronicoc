/*
============================================================================
                            Caixa eletrônico                  19/07/2014   =
Nome :Bruno wladimir de Oliveira 							   		       =
																		   =
Versão :1.0															       =
=============================================================================

*/


#include <unistd.h>
#include <iostream>   		#include <stdio.h>
#include <cstdlib>			#include <conio.h>
#include <locale.h>			#include <ctype.h>
#include <stdio.h>			#include <math.h>
#include <stdlib.h>			#include <stdlib.h>
#include <string.h>			#include <string>
#include <windows.h>

using namespace std;

// variaveis de cadastro
struct login{
char nome_correntista[50];
char senha_cadastro[20], senha_acesso[20];
char cpf[40];
char rg[40];
int idade , nconta_cadastro[10] , numero_conta_acesso[10] , telefone_cadastro[10];
double cpf_acesso[40];

};struct login Login;

int i;
double tmp=0;
int selecao;

// VARIAVEIS DE OPERAÇOES

struct operacoes{
double deposito_conta_corrente, deposito_conta_poupanca , transferencia , saldo_Ccorrente , saldo_Cpoupanca , saque_Ccorrente ,saque_Cpoupanca;

};struct operacoes Operacoes;

//TELAS
void menu_inicial(); void tela_transferencia(); void tela_deposito(); void tela_saldo(); void cadastro(); void tela_login();

void menu_correntista();void menu_saque_Ccorrente();void menu_saldo_insuficiente(); void informacoes(); void saque();
//POSICIONAMENTO DE CURSOR

void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);

}

int main(){
setlocale(LC_ALL, "Portugues");
menu_inicial();

  return 0;
system("pause");
}

//INICIO DO PROGRAMA

void menu_inicial(){

system("cls");
system ("color F5");gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );

cout<<("\t############################################################\n");
               cout<<("\t#                     BANCO BWO @                          #\n");
            cout<<("\t#                    SEJA BEM VINDO                        #\n");
              cout<<("\t############################################################\n\n\n");

					cout<<(" \1 \2\n");
					cout<<("Informe uma das opções abaixo!\n \n");
					cout<<("0- Acesso correntista\n \n");
					cout<<("1- Para cadastro de novo correntista!\n \n");
					cout<<("2- Deposito \n \n");
					cout<<("3- sair:\n");cout<<("\n \n");
					cout<<("Seleção:");
					cout<<Login.senha_acesso;
					cin>>selecao;
system("cls");
switch (selecao)
{

		case 0:tela_login();
		break;

		case 1:cadastro();
		break;

		case 2:tela_deposito();
		break;


    	case 3:
    		  exit(0);
	break;
		default:
			system("cls");
			gotoxy(25,2);


			cout<<("----------- ERRO ------------\n \n");
			cout<<("A opcão selecionada não corresponde a nenhum item do menu de opcões\n \n");
			system("pause");
			system("cls");
			  menu_inicial();
}
}

//CADASTRO DO CORRENTISTA
void cadastro(){
int opc_cadastro;

int tmp=0;
int num;
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
       cout<<("\t#                 TELA DE CADASTRO                     #\n");
       cout<<("\t#                                                      #\n");
       cout<<("\t########################################################\n\n\n");

				cout<<"informe o nome do correntista!\n";gotoxy (31,9);
				fflush(stdin);
				gets(Login.nome_correntista);
				cout<<("\n");
				cout<<("informe o CPF:\n");gotoxy (15,11);
				cin>>Login.cpf; cout<<("\n");
				cout<<("informe o RG:\n");gotoxy (14,13);
				cin>> Login.rg;		cout<<("\n");
				cout<<("informe Sua idade:\n");gotoxy (19,15);
				cin>>Login.idade;  cout<<("\n");
				cout<<("Informe um telefone de contato:\n");gotoxy (32,17);
				cin>>Login.telefone_cadastro[10];	cout<<("\n");
				cout<<("informe um numero para sua conta:\n");gotoxy (34,19);
				cin>>Login.nconta_cadastro[10]; cout<<("\n");
				cout<<("informe uma senha de 5 digitos: ");
				cin>>Login.senha_cadastro;	cout<<("\n");
				cout<<"INFORME UM VALOR A SER DEPOSITADO NA CONTA-POUPANÇA PARA PROSSEGUIR COM A ABERTURA DA CONTA !\n \n";
				cout<<"R$";
				cin>>tmp;
				Operacoes.saldo_Cpoupanca= (tmp) + (Operacoes.saldo_Cpoupanca);
				system("cls");
				gotoxy(15,2);
				cout<<("----------- CADASTRO REALIZADO COM SUCESSO ------------\n \n");

					system("pause");
					  menu_inicial();

}

//TELA DE LOGIN
void tela_login(){

int selecao=0;
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
	cout<<("\t########################################################\n");
       cout<<("\t#                 TELA DE ACESSO                       #\n");
       cout<<("\t#                                                      #\n");
       cout<<("\t########################################################\n\n\n");

				cout<<("como deseja acessar sua conta? \n");
				cout<<("\n");
				cout<<("1- A partir do numero do cpf: \n");
				cout<<("\n");
				cout<<("2- A partir do numero da conta:  \n");
				cout<<("\n");
				cout<<("Seleção:\n");
				cin>>selecao;
cout<<("\n");
switch (selecao){

	case 1:
	system("cls");
	gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
	cout<<("informe seu cpf:\n");gotoxy(17,3);
	cin>>Login.cpf_acesso[40];
	cout<<("\n");
	cout<<("Informe a senha: \n");gotoxy(17,5);
	cin>>Login.senha_acesso;

	//Login.senha_acesso [5]=toupper(Login.senha_acesso[5]);
	//Login.senha_acesso [5] = tolower( Login.senha_acesso[5]);
	cout<<("\n");

	  menu_correntista();
	   /*
		else
				system("cls");
				cout<<("conta não cadastrada\n");
				system("pause");
				system("cls");
				  menu_inicial();
*/
					case 2:
					system("cls");
					gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
					cout<<("Informe o numero da conta:  \n");
					cin>>Login.numero_conta_acesso[10];
					cout<<("Informe a senha:");
					cin>>Login.senha_acesso;

					//Login.senha_acesso [5]=toupper(Login.senha_acesso[5]);
					//Login.senha_acesso [5]=tolower(Login.senha_acesso[5]);

				//	if (Login.numero_conta_acesso==Login.nconta_cadastro && Login.senha_acesso[5]== Login.senha_cadastro[5]){
	}			 menu_correntista();

}


//DEPOSITO

void tela_deposito(){
int selecao=0;
int tmp=0;
system("cls");
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                 TELA DE DEPOSITO                     #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");

		cout<<("Pessione!\n\n");
		cout<<("1- Para deposito em conra corrente:\n \n");
		cout<<("2- Para deposito em poupança:\n \n");
		cout<<("3- Para voltar ao menu inicial:\n \n");
		cout<<("seleção:");
		cin>>selecao;

		switch (selecao){

		case 1:
		system("cls");gotoxy(11,2);
		cout<<("----------- DEPÓSITO EM CONTA CORRENTE ------------\n \n");
		cout<<("Informe o numero da conta:");
		cin>> tmp;
		if (tmp== Login.nconta_cadastro[10]){
			cout<<("Informe o valor a ser depositado:");
			cin>>tmp;
			Operacoes.saldo_Ccorrente= (tmp) + (Operacoes.saldo_Ccorrente);
			system("cls");
					gotoxy(15,2);
					cout<<("----------- DEPÓSITO REALIZADO COM SUCESSO ------------\n \n");
			system("pause");
			system("cls");

	    	cout<<("Para continuar depositando pressione '1' e para voltar pressione qualquer valor \n");
	    	cout<<"Seleção:";
	    	cin>>tmp;

		if (tmp==1){
			  tela_deposito()	;

  }
		else if(tmp !=1){

			   menu_correntista();
    }
}
			else
				system("cls");
				gotoxy(15,2);
				cout<<("---------CONTA NÃO CADASTRADA NO SISTEMA-----------\n");
				system("pause");
				  tela_deposito();

			case 2:
			system("cls");
			gotoxy(11,2);
			cout<<("----------- DEPÓSITO EM CONTA POUPANÇA ------------\n \n");
			cout<<("Informe o numero da conta:\n \n");gotoxy (27,4);
			cin>>tmp;
		if (tmp== Login.nconta_cadastro[10]){
			cout<<("Informe o valor a ser depositado!\n");
			cout<<"R$:";
		    cin>>tmp;
		    Operacoes.saldo_Cpoupanca= tmp + Operacoes.saldo_Cpoupanca;
		    system("cls");
					gotoxy(15,2);
					cout<<("----------- DEPÓSITO REALIZADO COM SUCESSO ------------\n\n");
			cout<<("Para continuar depositando pressione 1 e para voltar pressione qualquer valor\n \n");
			cout<<"Seleção:";
			cin>>tmp;
		if(tmp==1){
			  tela_deposito();

		}
		else if(tmp !=1){


			   menu_correntista();
	}

}	else
	  			gotoxy(15,2);
				cout<<("---------CONTA NÃO CADASTRADA NO SISTEMA-----------\n");
	 			system("pause");

			case 3:

			  menu_inicial();
			break;

				default:
					system("cls");
				gotoxy(25,2);
				cout<<("----------- ERRO ------------\n \n");
				cout<<("A opção selecionada não corresponde a nenhum item do menu de opcões\n \n");
				system("pause");
				system("cls");

  tela_deposito();

}

system("pause");
	  menu_inicial();

}
//TELA DE SALDO
void tela_saldo(){
system("cls");
		Operacoes.saldo_Ccorrente=(Operacoes.deposito_conta_corrente)+ (Operacoes.saldo_Ccorrente);
		gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
		cout<<("\t########################################################\n");
      	cout<<("\t#                     TELA DE SALDO                    #\n");
       	cout<<("\t#                                                      #\n");
       	cout<<("\t########################################################\n\n\n");
		cout<<"Voce possui:\n \n";
		cout<<"R$:"<<Operacoes.saldo_Ccorrente << ",00"<<" em sua conta corrente\n \n";
		cout<<"Você possui:\n \n";
		cout<<"R$:"<<Operacoes.saldo_Cpoupanca << ",00" <<"Em sua puopança\n \n";
				system("pause");
				system("cls");
  menu_correntista();

}
// TELA TRANSFERENCIA.

void tela_transferencia(){
int tmp=0;
int opc_transferencia;
int tmp_transferencia;

system ("cls");

gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                TELA DE TRANSFERÊNCIA                 #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");

		cout<<("informe o numero da conta de destino!: \n");
		cin>>tmp;
		cout<<("Informe o valor a ser depositado!\n");
		cin>>tmp_transferencia;
		if (tmp_transferencia > Operacoes.saldo_Ccorrente){
			system("cls");
			gotoxy(15,2);
			cout<<("XXXXXXXXXXXXX Saldo Insuficiente XXXXXXXXXXXXX \n \n");
			cout<<("pressione '1' para fazer a transferência de outro valor ou  '2' se deseja voltar ao menu:\n");
			cout<<("Seleção:");
    		cin>>opc_transferencia;

				switch(opc_transferencia){

    			case 1:  tela_transferencia();
    			break;

    			case 2:    menu_correntista();
    			break;
    		default:
				system("cls");
				gotoxy(25,2);
			cout<<("----------- ERRO ------------\n \n");
			cout<<("A opção selecionada não corresponde a nenhum item do menu de opcões\n \n");
			  tela_transferencia();

    }

}
		else
			Operacoes.saldo_Ccorrente= Operacoes.saldo_Ccorrente -tmp_transferencia ;
			cout<<("Operecao realizada com sucesso\n");
				system("pause");
 				  menu_correntista();
}

// INFORMAÇOES CORRENTISTA

void informacoes(){
int selecao=0;
system("cls");
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                 DADOS CADASTRAIS                    #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");

	cout<<"O nome do correntista é:"<<Login.nome_correntista << "\n \n";
	cout<<"Numero da conta:"<<Login.nconta_cadastro[10] << "\n \n";
	cout<<("Cliente desde:\n");
	cout<<system("date/t  \n \n");
	cout<<"Idade:"<<Login.idade <<"\n \n";
	cout<<("CPF de Numero:") ;
	cout<<Login.cpf ;
	cout<<("\n \n");
	cout<<"RG de Numero:"<<Login.rg <<"\n \n";
	cout<<"Deseja altera os dados cadastrais 1- para SIM e 2- Para NÃO\n \n";
	cout<<("Seleção:");
	cin>>selecao;

	switch(selecao){

		case 1:
		system("cls");
		cout<<("informe um novo nome de correntista:\n");
		cin>>Login.nome_correntista;
		cout<<("Informe uma nova senha de 5 digitos:\n ");
		cin>>Login.senha_cadastro;
		break;

		case 2:
			 menu_correntista();
			break;

	    default:
				system("cls");
			gotoxy(25,2);
			cout<<("----------- ERRO ------------\n \n");
			cout<<("A opção selecionada não corresponde a nenhum item do menu de opcões\n \n");
				informacoes();
				system("cls");
		 }
}

void saque(){
int selecao=0;
int tmp=0;
system("cls");
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                        SAQUE                         #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");

		cout<<("informe!\n\n");
		cout<<("1- Para saque em conta corrente:\n \n");
		cout<<("2- Para saque em conta poupança:\n \n");
		cout<<("Seleção:");
		cin>>selecao;
		switch(selecao) {

			case 1:

				system("cls");
				gotoxy(15,2);
				cout<<("-----------Retirada conta corrente ------------\n \n");
				cout<<("Informe o valor a ser sacado:\n\n");
				cout<<("R$" );
				cin>>tmp;

		if ( tmp> Operacoes.saldo_Ccorrente){
					system("cls");
						menu_saldo_insuficiente();
}
			else


			Operacoes.saldo_Ccorrente = (Operacoes.saldo_Ccorrente) -(tmp);
		system("cls");

		 menu_saque_Ccorrente	();

		default:
				system("cls");
		    	gotoxy(15,2);
			cout<<("----------- ERRO ------------\n \n");
			cout<<("A opção selecionada não corresponde a nenhum item do menu de opcões\n");
			system("pause");
			system("cls");
			 saque();

			case 2:
			system("cls");
		    gotoxy(15,2);
			cout<<("----------- Retirada conta poupança ------------\n \n");
			cout<<("Informe o valor a ser sacado:\n");
			cout<<("R$");
			cin>>tmp;

		if ( tmp> Operacoes.saldo_Cpoupanca){
					system("cls");
					menu_saldo_insuficiente();

}
			else

			Operacoes.saldo_Cpoupanca = (Operacoes.saldo_Cpoupanca)-(tmp);


		system("cls");
	 menu_saque_Ccorrente	();
}
}
// TELA MENU CORRENTISTA
void menu_correntista(){
int selecao=0;
int tmp=0;
 system("cls");
	        gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );

			cout<<("\t########################################################\n");
       cout<<("\t#                       BEM VINDO!                     #\n");
       cout<<("\t#                                                      #\n");
       cout<<("\t########################################################\n\n\n");
	cout<<("Informe:\n \n");
	cout<<("1- Para Saldo:\n \n");
	cout<<("2- Para Saque:\n \n");
	cout<<("3- Para Dados cadastrais:\n \n");
	cout<<("4- Para transferencias:\n \n");
	cout<<("5- Para Depósito:\n \n");
	cout<<("6- Sair da conta:\n \n");
	cout<<("7- Fechar Programa:\n \n");
	cout<<("Seleção:\n");
	cin>>selecao;

	switch(selecao) {

		case 1:
			tela_saldo();
			break;

		case 2:
			 saque();
			break;

		case 3:
			informacoes();
			break;

		case 4:
		tela_transferencia();
			break;

		case 5:
			tela_deposito();
			break;

		case 6:
			menu_inicial();
			break;

		case 7:
			exit(0);
	default:
			system("cls");
			gotoxy(25,2);
			cout<<("----------- ERRO ------------\n \n");
			cout<<("A opção selecionada não corresponde a nenhum item do menu de opcões\n");
			system("pause");
			system("cls");
			 menu_correntista();
	}
}
//MENU DA TELA DE SAQUE
void menu_saque_Ccorrente(){
int selecao=0;
			gotoxy(15,2);
			cout<<("----------- SAQUE REALIZADO COM SUCESSO ------------\n \n");
			cout<<("Deseja realizar outro saque ?\n \n");
			cout<<("1- Para SIM \n \n");
			cout<<("2- Para ver seu saldo\n \n");
			cout<<("3- Para encerrar\n \n");
			cout<<("Seleção:");
			cin>>selecao;
				switch(selecao) {

					case 1:
						 saque();
					break;

					case 2:
						 tela_saldo();
					break;
					case 3:

						menu_correntista();
					break;

		default:
			system("cls");
		    gotoxy(25,2);
			cout<<("----------- ERRO ------------\n \n");
			cout<<("A opção selecionada não corresponde a nenhum item do menu de opcões\n");
			system("pause");
			system("cls");
			menu_inicial();
        }
    }
// MENU SALDO INSUFICIENTE
void menu_saldo_insuficiente(){
int selecao=0;
					gotoxy(18,2);
					cout<<("XXXXXXXXXXXXX Saldo Insuficiente XXXXXXXXXXXXX \n \n");
					cout<<("Pressione!\n \n");
					cout<<("1- para fazer o saque de outro valor!\n \n");
					cout<<("2- para verificar seu saldo! \n \n");
					cout<<("3- Para voltar ao menu!\n \n");
					cout<<("Seleção:");
					cin>>selecao;
    			switch(selecao){

    		case 1: saque();
    		break;

    		case 2: tela_saldo();
    		break;

			case 3: menu_correntista();
    		break;
    }

system("pause");

}

