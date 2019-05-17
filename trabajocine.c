//Antes de empezar se debe resetear (meterse en empleados usuario:Bartolo y contraseña:9876 y dar a resetear)

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
#define TMATRIZ 9//tamaño matriz de los asientos del cine
#define NUMUSUARIOS 25

int asientoslibres(char fichero[]);
void pantalla(char fichero[]);
char pedirletra();//pide el asiento del cine
int pedirnumero();
int Pediropcion();
char Pedirchar();
void comprarentrada(char fichero[]);
void pedirTarjeta();//pide un numero de tarjeta de 16 digitos
void pedirpin();//pide un pin de 4 digitos
void leyenda(int i);//Leyenda de la sala
void resetpantalla(char fichero[]);//resetea las salas
void resetusuarios();//resetea los usuarios
void tiempo();
void disponible(int horario);

struct TUsuario {
	char nombre[50];
	char contrasena[50];
	char ntarjeta[16];
	int nentradas;
};

struct TAux {
	char nombre[50];
	char contrasena[50];
	char cuentabancaria[25];
};

void main() {
	int opcion, comp1, k = 0, i, auxx = 0, nusu = 0, nentradas, pin;
	float precio = 7.75;//precio por entrada
	char cartelera, comentario[200];
	FILE * Comedia;
	FILE * Accion;
	FILE * Terror;
	FILE * Romance;
	FILE * Infantil;
	FILE*Usuarios;
	errno_t error;
	struct TUsuario usu[NUMUSUARIOS];
	struct TAux aux;

	while (1) {
		fopen_s(&Usuarios, "usuarios.txt", "r");
		fscanf_s(Usuarios, "%d", &nusu);//Lee del fichero el numero de usuarios
		if (nusu != 0) {//Si no es 0, lee el fichero completo
			for (i = 0; i < nusu; i++) {
				fscanf_s(Usuarios, "%s\t", usu[i].nombre, 50);
				fscanf_s(Usuarios, "%s\t", usu[i].contrasena, 50);
				fscanf_s(Usuarios, "%s\t", usu[i].ntarjeta, 25);
				fscanf_s(Usuarios, "%d\n", &usu[i].nentradas);
			}
		}
		fclose(Usuarios);
		error = fopen_s(&Comedia, "Comedia.txt", "r");
		fopen_s(&Accion, "Accion.txt", "r");
		fopen_s(&Terror, "Terror.txt", "r");
		fopen_s(&Romance, "Romance.txt", "r");
		fopen_s(&Infantil, "Infantil.txt", "r");

		printf("	BIENVENIDO A CINES BARTOLO S.L.	 \n\n");
		printf(" 1 - Cartelera\n");
		printf(" 2 - Registrarse\n");
		printf(" 3 - Atenci\242n al cliente\n");
		printf(" 4 - Contacto\n");
		printf(" 5 - Avisos legales\n");
		printf(" 6 - Empleados\n");
		printf(" 7 - Salir \n");



		opcion = Pediropcion();

		switch (opcion) {
		case 1:
			system("cls");
			printf("Seleccione g\202nero:\n 1-Comedia\n 2-Acci\242n\n 3-Terror\n 4-Romace\n 5-Infantil\n Si quieres salir pulsa cualquier otra letra\n");
			switch (Pediropcion()) {
			case 1:
				system("cls");
				tiempo();
				while ((cartelera = fgetc(Comedia)) != EOF) {//Imprimimos el fichero entero
					printf("%c", cartelera);
				}
				printf("\n");
				switch (Pediropcion()) {
				case 1:
					printf("Has elegido Ted   ");
					disponible(16);
					comprarentrada("PantallaTed.txt");
					break;
				case 2:
					printf("Has elegido Deadpool   ");
					disponible(18);
					comprarentrada("PantallaDeadpool.txt");
					break;
				case 3:
					printf("Has elegido Supersalidos   ");
					disponible(18);
					comprarentrada("PantallaSupersalidos.txt");
					break;
				case 4:
					printf("Has elegido El Dictador\n");
					disponible(19);
					comprarentrada("PantallaDictador.txt");
					break;
				case 5:
					printf("Has elegido Primos   ");
					disponible(19);
					comprarentrada("PantallaPrimos.txt");
					break;
				}
				break;
			case 2:
				system("cls");
				tiempo();
				while ((cartelera = fgetc(Accion)) != EOF) {
					printf("%c", cartelera);
				}
				printf("\n");
				switch (Pediropcion()) {
				case 1:
					printf("Has elegido Los Vengadores   ");
					disponible(18);
					comprarentrada("PantallaVengadores.txt");
					break;
				case 2:
					printf("Has elegido Star Wars   ");
					disponible(19);
					comprarentrada("PantallaStarWars.txt");
					break;
				case 3:
					printf("Has elegido Batman Begins   ");
					disponible(20);
					comprarentrada("PantallaBatman.txt");
					break;
				case 4:
					printf("Has elegido Indiana Jones   ");
					disponible(20);
					comprarentrada("PantallaIndianaJones.txt");
					break;
				case 5:
					printf("Has elegido X-Men   ");
					disponible(22);
					comprarentrada("PantallaXmen.txt");
					break;
				case 6:
					printf("Has elegido La Aparici\242n de Hambrona   ");
					disponible(23);
					comprarentrada("PantallaHambrona.txt");
					break;
				case 7:
					printf("Has elegido Gladiator   ");
					disponible(23);
					comprarentrada("PantallaGladiator.txt");
					break;
				}
				break;
			case 3:
				system("cls");
				tiempo();
				while ((cartelera = fgetc(Terror)) != EOF) {
					printf("%c", cartelera);
				}
				printf("\n");
				switch (Pediropcion()) {
				case 1:
					printf("Has elegido IT   ");
					disponible(12);
					comprarentrada("PantallaIt.txt");
					break;
				case 2:
					printf("Has elegido El Suspenso   ");
					disponible(15);
					comprarentrada("PantallaSuspenso.txt");
					break;
				case 3:
					printf("Has elegido Insidious   ");
					disponible(19);
					comprarentrada("PantallaInsidious.txt");
					break;
				case 4:
					printf("Has elegido La aparici\242n de Mr.Charles   ");
					disponible(20);
					comprarentrada("PantallaMrCharles.txt");
					break;
				case 5:
					printf("Has elegido El resplandor   ");
					disponible(23);
					comprarentrada("PantallaResplandor.txt");
					break;
				}
				break;
			case 4:
				system("cls");
				tiempo();
				while ((cartelera = fgetc(Romance)) != EOF) {
					printf("%c", cartelera);
				}
				printf("\n");
				switch (Pediropcion()) {
				case 1:
					printf("Has elegido El diario de Noah   ");
					disponible(10);
					comprarentrada("PantallaNoah.txt");
					break;
				case 2:
					printf("Has elegido Titanic   ");
					disponible(12);
					comprarentrada("PantallaTitanic.txt");
					break;
				case 3:
					printf("Has elegido Casablanca   ");
					disponible(22);
					comprarentrada("PantallaCasablanca.txt");
					break;
				case 4:
					printf("Has elegido Dirty Dancing   ");
					disponible(22);
					comprarentrada("PantallaDirtyDancing.txt");
					break;
				case 5:
					printf("Has elegido Una tarde de \"Qu\241mica\",   ");
					disponible(23);
					comprarentrada("PantallaQuimica.txt");
					break;
				}
				break;
			case 5:
				system("cls");
				tiempo();
				while ((cartelera = fgetc(Infantil)) != EOF) {
					printf("%c", cartelera);
				}
				printf("\n");
				switch (Pediropcion()) {
				case 1:
					printf("Has elegido El viaje de Bartolito   ");
					disponible(12);
					comprarentrada("PantallaBartolo.txt");
					break;
				case 2:
					printf("Has elegido Up   ");
					disponible(15);
					comprarentrada("PantallaUp.txt");
					break;
				case 3:
					printf("Has elegido Toy story    ");
					disponible(17);
					comprarentrada("PantallaToy.txt");
					break;
				case 4:
					printf("Has elegido Shrek   ");
					disponible(18);
					comprarentrada("PantallaShrek.txt");
					break;
				case 5:
					printf("Has elegido WALL.E   ");
					disponible(19);
					comprarentrada("PantallaWALLe.txt");
					break;
				case 6:
					printf("Has elegido Frozen");
					disponible(20);
					comprarentrada("PantallaFrozen.txt");
					break;
				}
				break;

			}
			break;
		case 2:
			system("cls");
			printf("Para registrarse introduzca los siguientes datos\n");
			do {
				printf("Introduzca su nombre de usuario\n");
				scanf_s("%s", &aux.nombre, 50);
				getchar();
				for (k = 0; k < nusu; k++) {
					comp1 = strcmp(aux.nombre, usu[k].nombre); //Compara entre todos los usuarios
					if (comp1 == 0) {
						break;
					}
				}
				if (comp1 != 0) {//Si no hay nadie registrado con ese nombre
					if (nusu == NUMUSUARIOS) {//Si el numero de usuarios es igual al numero maximo de ellos
						printf("NO SE PUEDEN REGISTRAR MAS USUARIOS\n");
					}
					else {
						strcpy_s(usu[nusu].nombre, 50, aux.nombre); //guarda el nombre nuevo en usuarios
						printf("Introduzca su contrase\244a\n");
						scanf_s("%s", &usu[nusu].contrasena, 50);
						printf("Introduzca su numero de tarjeta\n");
						scanf_s("%s", &usu[nusu].ntarjeta, 25);
						printf("ha sido registrado como %s con contrase\244a %s y n\243mero de cuenta %s\n", usu[nusu].nombre, usu[nusu].contrasena, usu[nusu].ntarjeta);
						nusu++;//Como se ha registrado un usuarios aumentamos uno el numero de usuarios
					}
				}
				else {
					printf("Ya existe un usuario con ese nombre, intente con otro\n");
				}
			} while (comp1 == 0);//Se repite mientras que se introduzcan nombres ya registrado
			error = fopen_s(&Usuarios, "usuarios.txt", "w");//Error para escribir en el fichero
			if (error == 0) {//Si no hay error
				printf("Guardando datos...\n");
			}
			else {//Si hay error
				printf("Ha habido un error %d para guardar los datos.\n", error);
				return; // return sale del programa
			}
			fprintf(Usuarios, "%d\n", nusu);//Imprime el numero de usuarios alcanzado
			usu[nusu - 1].nentradas = 0;
			for (i = 0; i < nusu; i++) {//En un bucle va escribiendo los usuarios que se han registrado antes de salir
				fprintf(Usuarios, "%s\t%s\t%s\t%d\n", usu[i].nombre, usu[i].contrasena, usu[i].ntarjeta, usu[i].nentradas);
			}
			fclose(Usuarios);
			break;
		case 3:

			system("cls");
			printf("Seleccione una opci\242n:\n 1-Contactar por un problema\n 2-Dar su opini\242n\n ");
			switch (Pediropcion()) {
			case 1:
				system("cls");
				printf("En caso de tener alg\243n problema contacte con el n\243mero de tel\202fono 658070970\n");
				break;
			case 2:
				system("cls");
				printf("D\202janos tu opinion\n");
				getchar();
				gets(comentario);
				FILE*Comentarios;
				fopen_s(&Comentarios, "comentarios.txt", "a");//guardamos los comentarios en un fichero para mejorar.
				fprintf(Comentarios, "%s\n", comentario);
				fclose(Comentarios);
				printf("Su comentario se ha enviado correctamente, gracias por ayudarnos a mejorar\n");
				break;
			}
			break;
		case 4:
			printf(" Ubicaci\242n:\n   -La Rotonda, Tres Cantos\n   -Avda. Doctor Garc\241a Tapia 220, Moratalaz\n   -C/ Anacleto Agente Secreto 22, Rivas Vaciamadrid\n");
			printf(" N\243mero de contacto: 605926055\n");
			break;
		case 5:
			printf("Cines Bartolo se compromete a adoptar una pol\241tica de confidencialidad, con el objeto de proteger la privacidad de la informaci\242n personal obtenida a trav\202s de los comentarios y sugerencias de los usuarios. A estos efectos, usted garantiza la autenticidad de todos aquellos datos que comunique como consecuencia de la cumplimentaci\242n de los formularios necesarios para el acceso a todos los contenidos del Portal. El usuario se compromete a actuar en forma responsable en este sitio y a tratar a otros visitantes con respeto. En caso contrario no ser\240n publicados los comentarios por alterar las normas del Portal.");
			break;

		case 6:
			printf("Introduzca su nombre de usuario\n");//reseteo de los ficheros
			scanf_s("%s", &aux.nombre, 50);
			if (strcmp(aux.nombre, "Bartolo") == 0) {//solo entra con ese usuario
				printf("Bienvenido %s\n", aux.nombre, 50);
				printf("Introduzca su contrase\244a\n");
				scanf_s("%d", &pin);
				getchar();
				if (pin == 9876) {
					printf("\250Desea resetear? S-si N-no\n");
					switch (Pedirchar()) {
					case 's':
					case 'S':
						resetusuarios();
						resetpantalla("PantallaTed.txt");
						resetpantalla("PantallaDeadpool.txt");
						resetpantalla("PantallaSupersalidos.txt");
						resetpantalla("PantallaDictador.txt");
						resetpantalla("PantallaPrimos.txt");
						resetpantalla("PantallaVengadores.txt");
						resetpantalla("PantallaStarWars.txt");
						resetpantalla("PantallaBatman.txt");
						resetpantalla("PantallaIndianaJones.txt");
						resetpantalla("PantallaXmen.txt");
						resetpantalla("PantallaHambrona.txt");
						resetpantalla("PantallaGladiator.txt");
						resetpantalla("PantallaIt.txt");
						resetpantalla("PantallaSuspenso.txt");
						resetpantalla("PantallaInsidious.txt");
						resetpantalla("PantallaMrCharles.txt");
						resetpantalla("PantallaResplandor.txt");
						resetpantalla("PantallaNoah.txt");
						resetpantalla("PantallaTitanic.txt");
						resetpantalla("PantallaCasablanca.txt");
						resetpantalla("PantallaDirtyDancing.txt");
						resetpantalla("PantallaQuimica.txt");
						resetpantalla("PantallaBartolo.txt");
						resetpantalla("PantallaUp.txt");
						resetpantalla("PantallaToy.txt");
						resetpantalla("PantallaShrek.txt");
						resetpantalla("PantallaWALLe.txt");
						resetpantalla("PantallaFrozen.txt");
						break;
					case'n':
					case'N':
						printf("Operaci\242n cancelada\n");
						break;
					default:
						printf("opci\242n no v\240lida\n");
						break;
					}
				}
				else {
					printf("Contrase\244a incorrecta\n");
				}
			}
			else {
				printf("No tienes acceso\n");
			}
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
				printf("Perfess\n");
				break;
			}
			break;
		default:
			printf("opci\242n no valida\n");
			break;

			fclose(Accion);
			fclose(Comedia);
			fclose(Romance);
			fclose(Terror);
			fclose(Infantil);

		}
		getchar();
		system("pause");
		system("cls");

	}
}

int asientoslibres(char fichero[]) {//cuenta el numero de asientos libres
	FILE*Pantalla;
	int sala[TMATRIZ][TMATRIZ], i, j, cont = 0;
	fopen_s(&Pantalla, fichero, "r");
	for (i = 0; i < TMATRIZ; i++) {
		for (j = 0; j < TMATRIZ - 1; j++) {
			fscanf_s(Pantalla, "%d    ", &sala[i][j]);
		}
		fscanf_s(Pantalla, "%d\n\n", &sala[i][j]);
	}
	fclose(Pantalla);
	for (i = 0; i < TMATRIZ; i++) {
		for (j = 0; j < TMATRIZ; j++) {
			if (sala[i][j] == 0) {
				cont++;
			}
		}
	}
	return cont;
}

void pantalla(char fichero[]) {//imprime por pantalla la sala de cine
	FILE*Pantalla;
	char letra = 'A';
	int sala[TMATRIZ][TMATRIZ], i, j;
	fopen_s(&Pantalla, fichero, "r");
	for (i = 0; i < TMATRIZ; i++) {//leemos el fichero
		for (j = 0; j < TMATRIZ - 1; j++) {
			fscanf_s(Pantalla, "%d    ", &sala[i][j]);
		}
		fscanf_s(Pantalla, "%d\n\n", &sala[i][j]);
	}
	fclose(Pantalla);
	printf("    ");
	for (i = 0; i < TMATRIZ; i++) {
		printf("     %d  ", i + 1);
	}
	printf("\n\n");
	for (i = 0; i < TMATRIZ; i++) {
		printf("  %c    ", letra + i);
		for (j = 0; j < TMATRIZ; j++) {
			if (sala[i][j] == 0) {
				printf("\263\332\277\263    ");
			}
			else {
				printf("\263\261\261\263    ");
			}
		}
		leyenda(i);
	}
	printf("\t\t\t\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\n");
	printf("\t\t\t\272          PANTALLA           \272\n\n");
	
}

char pedirletra() {
	char letra;
	getchar();
	do {
		printf("Introduce Asiento (primero letra luego n\243mero) o S-si quieres salir \n");
		scanf_s("%c", &letra);
		if (letra == 's' || letra == 'S') {
			return 's';
		}
		if (letra >= 'A'&&letra <= 'I' || letra >= 'a'&&letra <= 'i') {//solo hay 9 columnas y 9 filas 
			if (letra >= 'a' && letra <= 'i') {
				letra = letra - 32;//pasamos todo a mayusculas
			}
		}
		else {
			printf("Letra incorrecta, introduce una letra desde A hasta I\n");
			letra = 0;
			getchar();
			getchar();
		}
	} while (letra == 0);
	return letra;
}


int pedirnumero() {
	int num = 0;
	do {
		scanf_s("%d", &num);
		if (num<1 || num > TMATRIZ) {
			printf("n\243mero incorrecto\n");
			getchar();
			num = 0;
		}
	} while (num == 0);
	return num;
}

void leyenda(int i) {
	if (i == 3) {
		printf("\t\t\332\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\277");
	}
	if (i == 4) {
		printf("\t\t\263  \263\332\277\263  Asiento vac\241o    \263");
	}
	if (i == 5) {
		printf("\t\t\263  \263\261\261\263  Asiento ocupado  \263");
	}
	if (i == 6) {
		printf("\t\t\263  \263\250\077\263  Elecci\242n asiento \263");
	}
	if (i == 7) {
		printf("\t\t\300\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\304\331");
	}
	printf("\n\n");
	//return;
}

int Pediropcion() {
	int opc;
	printf("Introduce opci\242n\n");
	scanf_s("%d", &opc);
	return opc;
}

char Pedirchar() {
	char opc;
	printf("Introduce opci\242n\n");
	scanf_s("%c", &opc);
	return opc;
}

void comprarentrada(char nFichero[]) {
	FILE*Usuarios;
	FILE*Pantalla;
	errno_t error;
	struct TUsuario usu[NUMUSUARIOS];
	struct TAux aux;
	int opcion, comp1, k = 0, i, auxx = 0, nusu = 0, nasientos, nentradas, cont, ntarjeta, pin, n;
	char letra = 'A', salir, lasiento;
	int sala[TMATRIZ][TMATRIZ], j, casiento;//columna del aiento
	char opcion2;
	float precio = 7.75;
	fopen_s(&Pantalla, nFichero, "r");
	fopen_s(&Usuarios, "usuarios.txt", "r");
	fscanf_s(Usuarios, "%d", &nusu);//Lee del fichero el numero de usuarios
	if (nusu != 0) {//Si no es 0, lee el fichero completo
		for (i = 0; i < nusu; i++) {
			fscanf_s(Usuarios, "%s\t", usu[i].nombre, 50);
			fscanf_s(Usuarios, "%s\t", usu[i].contrasena, 50);
			fscanf_s(Usuarios, "%s\t", usu[i].ntarjeta, 25);
			fscanf_s(Usuarios, "%d\t", &usu[i].nentradas);
		}
	}
	fclose(Usuarios);
	printf("\250Cu\240ntas quieres comprar? Precio por entrada : %.2f$\n", precio);
	scanf_s("%d", &nentradas);
	precio = precio * nentradas;//calcula el precio
	cont = nentradas;
	printf("Tienes que pagar: %.2f $\n", precio);
	for (n = 0; n < cont; n++) {//se repite hasta que hayas elegido el mismo nº de asientos que entradas
		for (i = 0; i < TMATRIZ; i++) {//lee el fichero
			for (j = 0; j < TMATRIZ - 1; j++) {
				fscanf_s(Pantalla, "%d    ", &sala[i][j]);
			}
			fscanf_s(Pantalla, "%d\n\n", &sala[i][j]);
		}
		fclose(Pantalla);
		nasientos = asientoslibres(nFichero);//nº de asientos disponibles 
		if (n == 0) {//n=0 para que solo entre la primera vez
			if (nasientos < nentradas) {//si no hay asientos suficientes
				system("cls");
				printf("No hay asientos disponibles, solo quedan %d\n", nasientos);
				
			}
		}
		pantalla(nFichero);
		do {
			lasiento = pedirletra();//llamamos lasiento (letra del asiento) para poder utilizar mas tarde
			if (lasiento == 's') {// para salir
				
			}
			i = (int)lasiento - 65;//lo`pasamos a un entero
			casiento = pedirnumero();
			if (sala[i][casiento - 1] == 1) {//si es un 1 esta ocupado si es 0 esta libre
				system("cls");
				//getchar();
				pantalla(nFichero);
				printf("El asiento ya est\240 ocupado\n");
			}
			//getchar();
		} while (sala[i][casiento - 1] == 1);//se repite si esta ocupado
		sala[i][casiento - 1] = 2;//llamamos 2 al asiento que acabas de seleccionar
		system("cls");
		printf("    ");
		for (i = 0; i < TMATRIZ; i++) {//imprimimos la sala
			printf("     %d  ", i + 1);
		}
		printf("\n\n");
		for (i = 0; i < TMATRIZ; i++) {
			printf("  %c    ", letra + i);
			for (j = 0; j < TMATRIZ; j++) {
				if (sala[i][j] == 0) {
					printf("\263\332\277\263    ");//libre
				}
				else if (sala[i][j] == 2) {//el que quieres seleccionar lo pone en interrogaciones
					printf("\263\250\077\263    ");
				}
				else {
					printf("\263\261\261\263    ");//ocupado
				}
			}
			leyenda(i);
		}
		printf("\t\t\t\311\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\315\273\n");
		printf("\t\t\t\272          PANTALLA           \272\n\n");
		do {
			getchar();
			printf("\250Quieres este asiento? %c%d: S-si N-no\n", lasiento, casiento);
			opcion2 = Pedirchar();
			i = (int)lasiento - 65;
			if (opcion2 == 's' || opcion2 == 'S') {
				printf("Has elegido el asiento %c%d\n", lasiento, casiento);
				sala[i][casiento - 1] = 1;//pasa a estar ocupado 
			}
			else if (opcion2 == 'n' || opcion2 == 'N') {
				printf("Elige asiento de nuevo\n");
				sala[i][casiento - 1] = 0;//vuelve a estar libre
				cont++;//para que se repita hasta que cojas el numero de asientos que has elegido
					   //getchar();
			}
			else {
				printf("opci\242n incorrecta\n");
				opcion2 = 0;
				getchar();
			}
			//getchar();
		} while (opcion2 == 0);
		fopen_s(&Pantalla, nFichero, "w");
		for (i = 0; i < TMATRIZ; i++) {//guarda en el fichero los nuevos asientos cogidos
			for (j = 0; j < TMATRIZ; j++) {
				fprintf(Pantalla, "%d    ", sala[i][j]);
			}
			fprintf(Pantalla, "\n\n");
		}
		fclose(Pantalla);
		system("cls");
	}


	getchar();
	printf("\250Eres usuario? S-si  N-no\n");
	switch (Pedirchar()) {
	case 's':
	case 'S':
		printf("Introduzca su nombre de usuario\n");
		scanf_s("%s", &aux.nombre, 50);
		getchar();
		for (k = 0; k < nusu; k++) {
			comp1 = strcmp(aux.nombre, usu[k].nombre); //Compara entre todos los usuarios ya registrados
			if (comp1 == 0) {
				break;
			}
		}
		if (comp1 == 0) {//Si coincide con algun nombre
			system("cls");
			printf("Bienvenido %s\n", usu[k].nombre);
			if (usu[k].nentradas > 9) {//si ya has comprado 10 entradas o mas te regalamos 1
				printf("Por ser usuario tienes una entrada de regalo por cada 10 entradas compradas, tienes %d, \250quieres usar el descuento? S-Si N-No\n", usu[k].nentradas);
				switch (Pedirchar()) {
				case 's':
				case 'S':
					usu[k].nentradas = usu[k].nentradas - 10;
					printf("Tienes que pagar %.2f$\n", precio - 7.75);
					break;
				case 'n':
				case 'N':
					printf("Tienes que pagar %.2f$", precio);
					break;
				}
			}
			else {
				printf("Te quedan %d entradas para conseguir una entrada gratis\n", 10 - usu[k].nentradas);// si no llegas a 10  entradas compradas o ya has usado el cupon en otra ocasion
			}
			do {
				printf("Introduzca su contrase\244a para pagar\n");
				scanf_s("%s", &aux.contrasena, 50);
				getchar();
				comp1 = strcmp(aux.contrasena, usu[k].contrasena); //Compara  si es la contraseña
				if (comp1 == 0) {
					usu[k].nentradas = nentradas + usu[k].nentradas;//suma a las entradas ya existentes la nueva compra
					printf("Pago correcto\n");
					fopen_s(&Usuarios, "usuarios.txt", "w");
					fprintf(Usuarios, "%d\n", nusu);
					for (i = 0; i < nusu; i++) {//guardar en el fichero 
						fprintf(Usuarios, "%s\t%s\t%s\t%d\n", usu[i].nombre, usu[i].contrasena, usu[i].ntarjeta, usu[i].nentradas);
					}
					fclose(Usuarios);
				}
				else {
					printf("contrase\244a incorrecta, vuelva a intentarlo\n");
				}
			} while (comp1 != 0); //Hasta que la contraseña sea correcta se repite
		}
		else {
			printf("Lo sentimos, no se encuentra entre nuestros usuarios, reg\241strese como uno nuevo.\n");
		}
		break;
	case 'n':
	case 'N':// si no eres usuario
		system("cls");
		getchar();
		printf("\nSi quieres ser usuario registrate gratis en nuestra web, tendras cientos de descuentos\n\n");
		printf("\250Desea pagar con T-Tarjeta o C-Cash. En caso de error pulse cualquier otra tecla\n");
		switch (Pedirchar()) {
		case 'T':
		case 't':
			pedirTarjeta();
			pedirpin();
			printf("Pago aceptado\n");
			break;
		case 'C':
		case'c':
			printf("Recuerde pagar en taquilla son %.2f$\n", precio);
			break;
		default:
			
			break;
		}
	}
	return;
}

void pedirTarjeta() {
	getchar();
	char ntarjeta[50];
	do {
		printf("Introduce n\243mero tarjeta\n");
		gets(ntarjeta);
		if (strlen(ntarjeta) != 16) {
			printf("n\243mero tarjeta incorrecto (tienen que ser 16 digitos)\n ");
		}
	} while (strlen(ntarjeta) != 16);//si la longitud es diferente a 16 vuelve a repetir
	ntarjeta[17] = '\0';

}

void pedirpin() {
	char npin[10];
	do {
		printf("Introduce n\243mero secreto\n");
		gets(npin);
		if (strlen(npin) != 4) {
			printf("n\243mero pin incorrecto, tiene que tener 4 d\241gitos\n ");
		}
	} while (strlen(npin) != 4);//si la longitud es diferente a 4 vuelve a repetir
	npin[5] = '\0';

}

void resetpantalla(char fichero[]) {
	FILE*Pantalla;
	fopen_s(&Pantalla, fichero, "w");
	int i, j, sala[TMATRIZ][TMATRIZ];
	for (i = 0; i < TMATRIZ; i++) {
		for (j = 0; j < TMATRIZ; j++) {
			sala[i][j] = 0;
			fprintf(Pantalla, "%d    ", sala[i][j]);
		}
		fprintf(Pantalla, "\n\n");
	}
	fclose(Pantalla);
	return;
}

void resetusuarios() {
	FILE*Usuarios;
	fopen_s(&Usuarios, "usuarios.txt", "w");
	fprintf(Usuarios, "0");
	fclose(Usuarios);
	return;
}

void tiempo(){
	time_t tiempo;
	char cad[80];
	struct tm * pTiempo;

tiempo = time( NULL );
		pTiempo = localtime( &tiempo );
		strftime( cad, 80, "%x, %H:%M", pTiempo );
		printf( "\n Fecha y Hora: %s\n\n\n", cad );
}

void disponible(int horario){
	char cad[80];
	int hora;

	time_t tiempo;
   struct tm *ptiempo;

   time( &tiempo );
   ptiempo = localtime( &tiempo );
   strftime(cad,80,"%H", ptiempo);
   
  hora = cad[0]*10+cad[1] - (541-13);
   
  if(hora>horario){
 printf("Se ha pasado la hora de la sesi\242n. La entrada ser\240 para la sesi\242n de ma\244ana.\n");}
  else {
 printf("La entrada es para la sesi\242n de hoy.\n");
 	}
}
