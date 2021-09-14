/*
* @file: Untitled.cpp
* @date: September 14 2021
* @author: Thales Alves
* @Brief: AppFinanceiro
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>


using namespace std;

void flush();

fstream file;
char data[11];
char ref[51];
float valor, valorRead, valorWrite;
float reset = 0;
char a;

int main(){
	bool loop = 1;
	int escolha;
	//
	do {
		system("cls");
		cout << "O que deseja fazer?" << endl;
		cout << "[1] - Visualizar Balanço" << endl;
		cout << "[2] - Registrar Evento" << endl;
		cout << "[3] - Limpar valores" << endl;
		cin >> escolha;
		flush();
		system("cls");
		//
		switch(escolha){

			case 1:

			file.open("gastosgerais.txt", ios::in);
			file >> valorRead;
			file.close();

			cout << "Gastos Gerais: RS " << valorRead << endl;

			file.open("livre.txt", ios::in);
			file >> valorRead;
			file.close();

			cout << "Livre: RS " << valorRead << endl;

			file.open("metas.txt", ios::in);
			file >> valorRead;
			file.close();

			cout << "Metas: RS " << valorRead << endl;

			file.open("poupanca.txt", ios::in);
			file >> valorRead;
			file.close();

			cout << "Poupanca: RS " << valorRead << endl;

			break;

			case 2:

			do {
				loop = 0;
				cout << "Digite a data: (DD/MM/AAAA)" << endl;
				scanf("%[^\n]11s", data);
				flush();
				if(strlen(data) >= 11 || strlen(data) < 10){
					cout << "Formato invalido.." << endl;
					loop = 1;
				}//if loop
			} while(loop);

			do {
				loop = 0;
				cout << "Digite uma referencia:" << endl;
				scanf("%[^\n]51s", ref);
				flush();
				if(strlen(ref) > 50){
					cout << "Tamanho invalido.." << endl;
					loop = 1;
				}//if loop ref
			} while(loop);

			for(int i = 49; i >= strlen(ref); i--){
				ref[i]='-';
			}//for ----

			cout << "Digite o valor:" << endl;
			scanf("%f", &valor);
			flush();
			system("cls");

			do {
				loop = 0;
				cout << "A qual categoria deseja atribuir?" << endl;
				cout << "[1] - Gastos Gerais" << endl;
				cout << "[2] - Livre" << endl;
				cout << "[3] - Metas" << endl;
				cout << "[4] - Poupan�a" << endl;

				cin >> escolha;
				system("cls");

				switch(escolha){
					case 1:

					file.open("gastosgerais.txt", ios::in);
					file >> valorRead;
					file.close();
					valorWrite = valorRead + valor;
					file.open("gastosgerais.txt", ios::out);
					file << valorWrite;
					file.close();

					file.open("RELATORIO.txt", ios::out|ios::app);
					file << data << " " << ref << " R$ " << valor << " [Gastos Gerais]" << endl;
					file.close();

					break;

					case 2:

					file.open("livre.txt", ios::in);
					file >> valorRead;
					file.close();
					valorWrite = valorRead + valor;
					file.open("livre.txt", ios::out);
					file << valorWrite;
					file.close();

					file.open("RELATORIO.txt", ios::out|ios::app);
					file << data << " " << ref << " R$ " << valor << " [Livre]" << endl;
					file.close();

					break;

					case 3:

					file.open("metas.txt", ios::in);
					file >> valorRead;
					file.close();
					valorWrite = valorRead + valor;
					file.open("metas.txt", ios::out);
					file << valorWrite;
					file.close();

					file.open("RELATORIO.txt", ios::out|ios::app);
					file << data << " " << ref << " R$ " << valor << " [Metas]" << endl;
					file.close();

					break;

					case 4:

					file.open("poupanca.txt", ios::in);
					file >> valorRead;
					file.close();
					valorWrite = valorRead + valor;
					file.open("poupanca.txt", ios::out);
					file << valorWrite;
					file.close();

					file.open("RELATORIO.txt", ios::out|ios::app);
					file << data << " " << ref << " R$ " << valor << " [Poupanca]" << endl;
					file.close();

					break;

					default:

					cout << "Opçao Invalida!";
					loop = 1;
				}//switch categoria
			} while(loop);


			break;

			case 3:

			system("cls");
			cout << "Tem certeza que deseja limpar as variaveis? (s/n)";
			cin >> a;
			flush();

			if(a == 's' || a == 'S'){

				file.open("gastosgerais.txt", ios::out);
				file << reset;
				file.close();

				file.open("livre.txt", ios::out);
				file << reset;
				file.close();

				file.open("metas.txt", ios::out);
				file << reset;
				file.close();

				file.open("poupanca.txt", ios::out);
				file << reset;
				file.close();
			}

			break;

			default:

			cout << "Opçao inválida, tente novamente!";
		}//switch menu
		cout << "Deseja voltar ao inicio? (s/n)" << endl;
		cin >> a;
		flush();
		tolower(a) == 's' ? loop = 1 : loop = 0;
	} while(loop);
	return 0;
}//main

void flush(){
    /*Descarta todos os caracteres se houver algum at�
      encontrar o caractare nova linha �\n�, ent�o s�
      sobra o �\n� na entrada: */
    scanf("%*[^\n]");
    //E ent�o descarta o caractere nova linha �\n�:
    scanf("%*c");
}//flush
