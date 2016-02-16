/* 
============================================================================
                            Caixa eletrônico                               =
Nome :Bruno wladimir de Oliveira 							   		       =
																		   =
Versão :1.0															       =
=============================================================================

*/

#include <unistd.h>
#include <iostream>
#include <cstdlib>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

using namespace std;

// variaveis de cadastro
struct login{
char nome_correntista [128];
char senha_cadastro[100];
char senha_acesso[100];
double cpf;
double rg;
int idade;
int nconta_cadastro;
int numero_conta_acesso;
double cpf_acesso;
double telefone_cadastro;

};

struct login Login;

int i;
double tmp=0; // temporaria
int selecao_inicial;

// operaçoes
struct operacoes{
double deposito_conta_corrente;
double deposito_conta_poupanca; 
double transferencia;
double saldo_Ccorrente; 
double saldo_Cpoupanca;
double saque_Ccorrente;
double saque_Cpoupanca;
};
struct operacoes Operacoes;

//TELAS
void menu_inicial();
void tela_transferencia();
void tela_deposito();
void tela_saldo();
void cadastro();
void tela_login();
void informacoes();
void saque();
void menu_correntista();


//POSICIONAMENTO DE CURSOR

void gotoxy(int x, int y) {
  COORD c;
  c.X = x - 1;
  c.Y = y - 1;
  SetConsoleCursorPosition (GetStdHandle(STD_OUTPUT_HANDLE), c);

}

int main(){
setlocale(LC_ALL, "Portuguese");
menu_inicial();  

return 0;
system("pause");
}

//INICIO DO PROGRAMA

void menu_inicial(){
	int opc;
	
system("cls");
system ("color 1F");gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );

cout<<("\t############################################################\n");
               cout<<("\t#                     BANCO BWO @                          #\n");
            cout<<("\t#                    SEJA BEM VINDO                        #\n");
              cout<<("\t############################################################\n\n\n");

					cout<<("Informe uma das opções abaixo!\n");
					cout<<("\n");	
					cout<<("0- Acesso correntista\n");
					cout<<("\n");	
					cout<<("1- Para cadastro de novo correntista!\n");
					cout<<("\n");	
					cout<<("2- Deposito \n");
					cout<<("\n");
					cout<<("3- sair:\n");cout<<("\n");	   
					cout<<("Seleção:");   
					
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
						

    	case 3:
    		  exit(0);
	break;
		default:
			system("cls");
			cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			system("pause");
			system("cls");
			return menu_inicial();			
}}
//CADASTRO DO CORRENTISTA 
void cadastro(){
int opc_cadastro;
double count;
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
				cin>>Login.cpf;
				cout<<("\n");
				cout<<("informe o RG:\n");gotoxy (14,13);
				cin>> Login.rg;
				cout<<("\n");
				cout<<("informe Sua idade:\n");gotoxy (19,15);
				cin>>Login.idade;
				cout<<("\n");
				cout<<("Informe um telefone de contato!\n");gotoxy (32,17);
				cin>>Login.telefone_cadastro;
				cout<<("\n");
				cout<<("informe um numero para sua conta:\n");gotoxy (34,19); 
				cin>>Login.nconta_cadastro;			
				cout<<("\n");
				cout<<("informe uma senha de 5 digitos: ");
				cin>>Login.senha_cadastro;
				cout<<("\n");
				cout<<"INFORME UM VALOR A SER DEPOSITADO NA CONTA-POUPANÇA PARA PROSSEGUIR COM A ABERTURA DA CONTA !\n" <<"r$" ;
				cin>>Operacoes.deposito_conta_poupanca;
				Operacoes.saldo_Cpoupanca= (Operacoes.deposito_conta_poupanca) + (Operacoes.saldo_Cpoupanca);
				system("cls");
				cout<<("CADASTRO REALIZADO COM SUCESSO!!!!!\n");
system("pause");
					return menu_inicial();

}

//TELA DE LOGIN
void tela_login(){

int opc_tela_login	;
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
				cin>>opc_tela_login;cout<<("\n");
switch (opc_tela_login){
	
	case 1:
	system("cls");
	gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
	cout<<("informe seu cpf:\n");gotoxy(17,3);
	cin>>Login.cpf_acesso;
	cout<<("\n");
	cout<<("Informe a senha: \n");gotoxy(17,5);
	cin>>Login.senha_acesso;
	//Login.senha_acesso [6]=toupper(Login.senha_acesso[6]);
	//Login.senha_acesso [6]=tolower(Login.senha_acesso[6]);
	cout<<("\n");
	
	if (Login.cpf_acesso== Login.cpf && Login.senha_acesso == Login.senha_cadastro){
		
	 menu_correntista();
	   }
		else
				system("cls");
				cout<<("conta nao cadastrada\n");
				system("pause");
				system("cls");
				return menu_inicial();

					case 2:
					system("cls");
					gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
					cout<<("Informe o numero da conta:  \n");
					cin>>Login.numero_conta_acesso;
					cout<<("Informe a senha:");
					cin>>Login.senha_acesso;
				    //Login.senha_acesso [6]=toupper(Login.senha_acesso[6]);
					//Login.senha_acesso [6]=tolower(Login.senha_acesso[6]);
					if (Login.numero_conta_acesso==Login.nconta_cadastro && Login.senha_acesso== Login.senha_cadastro){
				return	menu_correntista();
 	  }
 	  else
				system("cls");
				cout<<("conta nao cadastrada\n");
				system("pause");
				system("cls");
				return menu_inicial();
}
}
//DEPOSITO
void tela_deposito(){
int op_deposito;
int tmp=0;	
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                 TELA DE DEPOSITO                     #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");

		cout<<("Pessione!\n");
		cout<<("\n");
		cout<<("1- Para deposito em conra corrente:\n");
		cout<<("\n");
		cout<<("2- Para deposito em poupança:\n");
		cout<<("\n");
		cout<<("3- Para voltar ao menu inicial:\n");
		cout<<("\n");
		cout<<("seleção:");
		cin>>op_deposito;
		
		switch (op_deposito){
			case 1:
			
		system("cls");gotoxy(11,2);
		cout<<("----------- DEPÓSITO EM CONTA CORRENTE ------------\n");
		cout<<("\n");
		cout<<("Informe o numero da conta:");
		cin>> tmp;
		if (tmp== Login.nconta_cadastro){
			cout<<("Informe o valor a ser depositado:");
			cin>>tmp;
			Operacoes.saldo_Ccorrente= (tmp) + (Operacoes.saldo_Ccorrente);
			system("cls");
			cout<<("*********-------------------------------********* \n");
			cout<<("*********DEPOSITO REALIZADO COM SUCESSO********* \n");
			cout<<("*********-------------------------------********* \n");
			system("pause");
			system("cls");
		
	    	cout<<("Para continuar depositando pressione 1 e para sair pressione qualquer valor");
	    	cin>>tmp;

		if (tmp==1){
			return tela_deposito()	;
	
  }
		else if(tmp !=1){
		 
			system("pause");
			return  menu_correntista();
    }

}

			else
				system("cls");
				gotoxy(14,2);
				cout<<("CONTA NÃO CADASTRADA NO SISTEMA!!!! \n");
				system("pause");
				return tela_deposito();
	
			case 2:
			system("cls");
			gotoxy(11,2);
			cout<<("----------- DEPÓSITO EM CONTA POUPANÇA ------------\n");
			cout<<("\n");
			cout<<("Informe o numero da conta:\n");gotoxy (27,4);
			cin>>tmp;
		if (tmp== Login.nconta_cadastro){
			cout<<("Informe o valor a ser depositado!");
		    cin>>tmp;
		    Operacoes.saldo_Cpoupanca= tmp + Operacoes.saldo_Cpoupanca;
		    system("cls");
			cout<<("*********-------------------------------********* \n");
			cout<<("*********DEPOSITO REALIZADO COM SUCESSO********* \n");
			cout<<("*********-------------------------------********* \n");
			cout<<("Para continuar depositando pressione 1 e para sair pressione qualquer valor");
			cin>>tmp;
		if(tmp==1){
			return tela_deposito();
			
		}
		else if(tmp !=1){
		 
			system("pause");
			return  menu_correntista();
	}
			
}
		else 
	  			cout<<("conta não cadastrada no sistema \n");
	 			system("pause");
	
			case 3:
			
			return menu_inicial();
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
//TELA DE SALDO
void tela_saldo(){
system("cls");
		Operacoes.saldo_Ccorrente=(Operacoes.deposito_conta_corrente)+ (Operacoes.saldo_Ccorrente);
		cout<<("*********-------------------------------************ \n");	
		cout<<("***********BEM VINDO A TELA DE saldo ***************  \n");
		cout<<("*********-------------------------------************* \n");
		cout<<"Voce possui R$:"<<Operacoes.saldo_Ccorrente <<" em sua conta corrente\n";cout<<("\n");

			cout<<"Você possui R$:"<<Operacoes.saldo_Cpoupanca<<"Em sua puopança\n";cout<<("\n");
				system("pause");
				system("cls");
return menu_correntista();

}
// TELA TRANSFERENCIA.

void tela_transferencia(){
int tmp=0;
int opc_transferencia;
int tmp_transferencia;

system ("cls");

cout<<("*********-------------------------------************ \n");	
cout<<("**********BEM VINDO A TELA DE Transferencia ***********");
cout<<("*********-------------------------------************* \n");	

		cout<<("informe o numero da conta de destino!: \n");
		cin>>tmp;
		cout<<("Informe o valor a ser depositado!\n");
		cin>>tmp_transferencia;
		if (tmp_transferencia > Operacoes.saldo_Ccorrente){
			cout<<("Saldo insuficiente\n");
			system("pause");
		
			cout<<("pressione '1' para fazer a transferência de outro valor ou  '2' se deseja voltar ao menu:\n");
    		cin>>opc_transferencia;
    			
				switch(opc_transferencia){
					
    			case 1:return tela_transferencia();
    			break;
    			
    			case 2: return  menu_correntista();
    			break;
    		default:
			cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			return tela_transferencia();
			
    }

}
		else
			Operacoes.saldo_Ccorrente= Operacoes.saldo_Ccorrente -tmp_transferencia ;
			cout<<("Operecao realizada com sucesso\n");
				system("pause");
 				return menu_correntista();
}
// INFORMAÇOES CORRENTISTA
void informacoes(){
int opc_informacoes;
system("cls");
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                 DADOS CADASTRAIS                    #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");

	cout<<"O nome do correntista é:"<<Login.nome_correntista << "\n";
	cout<<("\n");
	cout<<"Numero da conta:"<<Login.nconta_cadastro << "\n";
	cout<<("\n");
	cout<<"Cliente desde:\n" <<system("date/t\n");
	cout<<("\n");
	cout<<"Idade:"<<Login.idade <<"\n";
	cout<<("\n");
	cout<<"CPF de Numero:" <<Login.cpf <<"\n";
	cout<<("\n");
	cout<<"RG de Numero:"<<Login.rg <<"\n";
	cout<<("\n");
cout<<"Deseja altera os dados cadastrais 1- para SIM e 2- Para NÃO?\n"<<"\n";
cout<<("Seleção:");
cin>>opc_informacoes;

	switch(opc_informacoes){
		
		case 1:
		system("cls");
		cout<<("informe um novo nome de correntista:\n");
		cin>>Login.nome_correntista;
		cout<<("Informe uma nova senha de 5 digitos:\n ");
		cin>>Login.senha_cadastro[5];
		break;
		
		case 2:
			return menu_correntista();
			break;
	    
	    default:
				cout<<("****************ERRO************\n");
				cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
				return informacoes();
				system("cls");
		 
}
}
	
void saque(){
//int opc_saque;
int tmp=0;
system("cls");
gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
cout<<("\t########################################################\n");
cout<<("\t#                        SAQUE                         #\n");
cout<<("\t#                                                      #\n");
cout<<("\t########################################################\n\n\n");
		
		cout<<("informe!\n");
		cout<<("1- Para saque em conta corrente:\n");
		cout<<("\n");
		cout<<("2- Para saque em conta poupança:\n");
		cout<<("\n");
		cout<<("Seleção:");
		cin>>tmp;
		switch(tmp) {
			
			case 1:
				
				system("cls");
				cout<<("-----------Retirada conta corrente ------------\n");
				cout<<("Informe o valor a ser sacado:\n");
				cout<<("R$" );
				cin>>tmp;
				
		if ( tmp> Operacoes.saldo_Ccorrente){
					cout<<("Saldo insuficiente\n");
					system("pause");
					system("cls");
					cout<<("pressione '1' para fazer o saque de outro valor ou  '2' para verificar seu saldo \n");
    				cin>>tmp;
    			switch(tmp){
					
    		case 1:return saque();
    		break;
    			
    		case 2: return tela_saldo ();
    		break;
    		
			default:
				cout<<("****************ERRO************\n");
				cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
				return saque();
				system("cls");
    
}
}
			else
			
			
			Operacoes.saldo_Ccorrente = (tmp)- (Operacoes.saldo_Ccorrente); 
		system("cls");
			cout<<("*********----------------------------********* \n");
			cout<<("*********SAQUE REALIZADO COM SUCESSO********* \n");
			cout<<("*********----------------------------********* \n");
			cout<<("Deseja realizar outro saque ?\n");
			cout<<("1- Para SIM \n");
			cout<<("2- Para ver seu saldo\n");
			cout<<("3- Para Voltar ao Menu\n");
			cin>>tmp;
				switch(tmp) {
					
					case 1:
						return saque();
					break;
					
					case 2:
						
						return tela_saldo();
					break;
					
					case 3:
						return menu_correntista();
						break;
						
		default:
			system("cls");
		     cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			system("pause");
			system("cls");
			return menu_inicial();			
			
}	
												
			default:
				system("cls");
		    cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			system("pause");
			system("cls");
			return saque();
			
			case 2:
			system("cls");
		    cout<<("-----------Retirada conta poupança ------------\n");
			cout<<("Informe o valor a ser sacado:\n");
			cout<<("R$");
			cin>>tmp;
		
		if ( tmp> Operacoes.saldo_Cpoupanca){
					cout<<("Saldo insuficiente\n");
					system("pause");
					cout<<("pressione '1'para fazer o saque de outro valor ou  '2' se deseja voltar ao menu inicial \n");
    				cin>>tmp;
    			switch(tmp){
					
    		case 1:return tela_transferencia();
    		break;
    			
    		case 2: return menu_correntista();
    		break;
    }
			
}
			else
			
			Operacoes.saldo_Cpoupanca = (tmp)- (Operacoes.saldo_Cpoupanca); 
					
		system("cls");	
		cout<<("*********----------------------------********* \n");
		cout<<("*********SAQUE REALIZADO COM SUCESSO********* \n");
		cout<<("*********----------------------------********* \n");
		
		cout<<("Deseja realizar outro saque ?\n");
			cout<<("1- Para SIM \n");
			cout<<("\n");
			cout<<("2- Para ver seu saldo\n");
			cout<<("\n");
			cout<<("3- Para encerrar\n");
			cout<<("\n");
			cout<<("Seleção:");
			cin>>tmp;
				switch(tmp) {
					
					case 1:
						return saque();
					break;
					
					case 2:
						return tela_saldo();
					break;
					case 3:
						
						return menu_correntista();
					break;
					
						
		default:
		     cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			system("pause");
			system("cls");
			return menu_inicial();
			
			
        }	
}
}
void menu_correntista(){
int tmp=0;
 system("cls");
	        gotoxy(70,1); system ( "date /t" );gotoxy(73,2); system ( "time/t" );
			
			cout<<("\t########################################################\n");
       cout<<("\t#                       BEM VINDO!                     #\n");
       cout<<("\t#                                                      #\n");
       cout<<("\t########################################################\n\n\n");
	cout<<("Informe:\n");
	cout<<("\n");
	cout<<("1- Para Saldo:\n");
	cout<<("\n");
	cout<<("2- Para Saque:\n");
	cout<<("\n");
	cout<<("3- Para Dados cadastrais:\n");
	cout<<("\n");
	cout<<("4- Para transferencias:\n");
	cout<<("\n");
	cout<<("5- Para Deposito:\n");
	cout<<("\n");
	cout<<("6- Sair da conta:\n");
	cout<<("\n");
	cout<<("7- Fechar Programa:\n");
	cout<<("\n");
	cout<<("Seleção:\n");
	cin>>tmp;
	
	switch(tmp) {
		
		case 1:
			return tela_saldo();
			break;
		
		case 2:
			return saque();
			break;
		
		case 3:
			return informacoes();							
			break;
		
		case 4:
			return tela_transferencia();
			break;
		
		case 5:
			return tela_deposito();
			break;
		
		case 6:
			return menu_inicial();
			break;
		
		case 7:
			exit(0);
	default:cout<<("****************ERRO************\n");
			cout<<("A opcao selecionada nao corresponde a nenhum item do menu de opcoes\n");
			system("pause");
			system("cls");
			return menu_correntista();
}

system("pause");

}
		
