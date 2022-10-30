//librerias
#include <iostream>
#include <string>
#include<cstdlib> //para el system("cls");
#include<conio.h>//para el getch();
using namespace std;

//definicion de constantes
#define USER "admin"
#define PASS "12345"

bool login(){
	
	//declaracion de variables
	string user, password;
	bool ingresar = false;
	char caracter;
	
	do{
		system("cls");
		cout<<"\t\t\tINICIAR SESION"<<endl;
		cout<<"\t\t\t---------------"<<endl;
		cout<<"\n\tUsuario: ";
		getline(cin, user);
		cout<<"\n\tPassword: ";
		//getline(cin, password);
		
	
		caracter = getch();//catura un caracter sin mostrar en pantalla
		password = ""; //se borra lo que se introdujo en cada ciclo
		
		//13 codigo ASCII de la tecla enter
		while(caracter != 13){
			
			//8 codigo ASCII de la tecla borrar o backspace
			if(caracter != 8){
				password.push_back(caracter);//guarda el caracter en el string
				cout<<"*"; //ilusion de que se oculta la password con asteriscos
			}else{
				if(password.length() > 0){
					cout <<"\b \b";//para dar la isulucion de que el caracter(*) se va borrando
					password = password.substr(0, password.length() - 1 );//se toma los primeros caracteres y se deja el ultimo, en resumen practico lo que hace es borrar el ultimo caracter
				}
			}
			
			caracter = getch();//vuelve a tomar otro caracter
		}
		
		if(user == USER && password == PASS){
			
			cout<<"\n\n---------------------BIENVENIDO AL SISTEMA-----------------------"<<endl; 
			ingresar = true;
			getch();
			
		}else{
			
			cout<<"\n El usuario y/o la contraseña son incorrectos"<<endl;
			system("pause");
		}	
		
	}while(ingresar == false);
	
	system("cls");
	
	//retorna true siempre
	return ingresar;
	
}

