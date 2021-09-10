#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

void flush();

fstream file;
int i;
char data[11];
char ref[51];
float valor, valorRead, valorWrite;
float reset = 0;
char a;

int main(){
	
	inicio:
	
	system("cls");
	
	cout << "O que deseja fazer?" << endl;
	cout << "[1] - Visualizar Balanço" << endl;
	cout << "[2] - Registrar Evento" << endl;
	cout << "[3] - Limpar valores" << endl;
	
	cin >> i;
	flush();	
	system("cls");

	switch(i){
		
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
			
			data:
				
			cout << "Digite a data: (DD/MM/AAAA)" << endl;			
			scanf("%[^\n]11s", data);
			flush();
			if(strlen(data) >= 11 || strlen(data) < 10){
				cout << "Formato invalido.." << endl;
				goto data;
			}			
			
			ref:
				
			cout << "Digite uma referencia:" << endl;			
			scanf("%[^\n]51s", ref);
			flush();
			if(strlen(ref) > 50){
				cout << "Tamanho invalido.." << endl;
				goto ref;
			}			
			for(i = 49; i >= strlen(ref); i--){				
				ref[i]='-';
			}			
						
			cout << "Digite o valor:" << endl;
			scanf("%f", &valor);
			flush();			
			system("cls");
						
			categorias:
						
			cout << "A qual categoria deseja atribuir?" << endl;
			cout << "[1] - Gastos Gerais" << endl;
			cout << "[2] - Livre" << endl;
			cout << "[3] - Metas" << endl;
			cout << "[4] - Poupança" << endl;
			
			cin >> i;			
			system("cls");
			
			switch(i){
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
					goto categorias;	
			}			
			
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
				
				cout << "Opçao Invalida!";
				goto inicio;		
	}	
	cout << "Deseja voltar ao inicio? (s/n)" << endl;			
	cin >> a;
	flush();
	if(a == 's' || a == 'S')goto inicio;
	return 0;
}

void flush(){
    /*Descarta todos os caracteres se houver algum até 
      encontrar o caractare nova linha ´\n´, então só
      sobra o ´\n´ na entrada: */
    scanf("%*[^\n]"); 
    //E então descarta o caractere nova linha ´\n´:
    scanf("%*c"); 
}
