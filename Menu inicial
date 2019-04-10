#include<stdio.h>

int Pediropcion();
char Pedirchar();


void main(){
	int opcion;
	
while(1){
	
	printf("	BIENVENIDO A CINES BARTOLO S.L.	 \n\n");
		printf(" 1 - Cartelera\n");
		printf(" 2 - Registrarse\n");
		printf(" 3 - Atenci\242n al cliente\n");
		printf(" 4 - Contacto\n");
		printf(" 5 - Avisos legales\n");
		printf(" 6 - Empleados\n");
		printf(" 7 - Salir \n");
		
	opcion = Pediropcion();
	
	switch(opcion){
		case 1:
			system("cls");
			printf("Seleccione g\202nero:\n 1-Comedia\n 2-Acci\242n\n 3-Terror\n 4-Romace\n 5-Infantil\n Si quieres salir pulsa cualquier otra letra\n");
			getchar();
			break;
			
		case 2:
			system("cls");
			printf("Para registrarse introduzca los siguientes datos\n");
			getchar();
			break;
			
		case 3:
			system("cls");
			printf("Seleccione una opci\242n:\n 1-Contactar por un problema\n 2-Dar su opini\242n\n ");
			getchar();
			break;
			
		case 4:
			printf(" Ubicaci\242n:\n   -La Rotonda, Tres Cantos\n   -Avda. Doctor Garc\241a Tapia 220, Moratalaz\n   -C/ Anacleto Agente Secreto 22, Rivas Vaciamadrid\n");
			printf(" N\243mero de contacto: 605926055\n");
			getchar();
			break;
			
		case 5:
			printf("Cines Bartolo se compromete a adoptar una pol\241tica de confidencialidad, con el objeto de proteger la privacidad de la informaci\242n personal obtenida a trav\202s de los comentarios y sugerencias de los usuarios. A estos efectos, usted garantiza la autenticidad de todos aquellos datos que comunique como consecuencia de la cumplimentaci\242n de los formularios necesarios para el acceso a todos los contenidos del Portal. El usuario se compromete a actuar en forma responsable en este sitio y a tratar a otros visitantes con respeto. En caso contrario no ser\240n publicados los comentarios por alterar las normas del Portal.");
			getchar();
			break;
		
		case 6:
			system("cls");
			printf("Introduzca su nombre de usuario\n");
			getchar();
			break;
			
			case 7:
			getchar();
			printf("\250Est\240 seguro de querer salir?\n S-Si\t N-No\n");
			switch (Pedirchar()) {
			case 's':
			case 'S':
				printf("Don bartolo os desea un buen d\241a\n");
				system("pause");
				return;
			case 'n':
			case 'N':	
				break;
			}
			getchar();
			break;
			
		default:
			printf("opci\242n no valida\n");
			break;
	}
	getchar();
	system("cls");
}
}
