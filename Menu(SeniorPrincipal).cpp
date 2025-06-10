#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>

int i = 0;
int c = 0;
typedef struct {
    int id_empleado;
    char nombre_empleado[50];
    char apellido_empleado[50];
    char puesto[50];
    char departamento[50];
    char fecha_trabajo[20];    // DD/MM/AAAA
    float horas_trabajadas;
} HorasTrabajadasEstructura;

typedef struct {
    char fecha_apertura[20];    // Formato: DD/MM/AAAA
    int dias_activos;
    char concepto[100];
    char fecha_registro[20];    // Fecha cuando se registró
} DiasActivosEstructura;

typedef struct {
    char nombre_dept[50];
    int numero_dept;
    char nombre_gerente[50];
    char nip_gerente[10];
} DepartamentoEstructura;

// Estructura para los empleos
typedef struct {
    char nombre_empleo[50];
    float jornada_diaria;
    float salario_por_hora;
    float horas_minimas;
    char departamento[50];
} EmpleoEstructura;

typedef struct {
    char nombre_empleado[50];
    char apellido_empleado[50];
    char puesto[50];
    char departamento[50];
    float salario_base;
    int id_empleado;
} EmpleadoEstructura;


typedef struct {
	
    char concepto[100];
    float cantidad;           // Positiva para ganancias, negativa para gastos
    char fecha_movimiento[20]; // Formato: DD/MM/AAAA
    int numero_factura;
    char departamento[50];    // Solo para gerente senior
    char tipo_movimiento[20]; // "Ingreso" o "Gasto"
} MovimientoFinanciero;


// Declarar solo las funciones de marcos que necesitamos (evitar incluir Marcos.h si causa conflictos)
void MarcoImpresiones();
void MarcoRegistrar();
void MarcoPrincipal();
void MarcoPassword();
void RegistrarDiasActivos();
void RegistrarGastosGananciasSenior();
void RegistrarGastosGananciasGerente();

// Variables globales externas (declaradas en Marcos.h)

// Variables globales propias del programa
char gerente_actual_local[50];
char departamento_actual_local[50];

// Declaración de funciones
void AnimacionInicio();
void RegistrarDepartamentos();
void RegistrarEmpleosSenior();
void RegistrarEmpleosGerente(char *departamento_gerente);
void RegistrarEmpleadosSenior();
void RegistrarEmpleadosGerente(char *departamento_gerente);
int VerificarCredenciales(char *nombre, char *nip, char *departamento);
void MenuPrincipal();
void MenuGerenteRegistrado(char *nombre_gerente, char *departamento);
void password();
void ImprimirEmpleos();
// Declaraciones para gastos y ganancias
int FechaADias(char *fecha);
int ValidarFechaEnRango(char *fecha_movimiento);
void RegistrarGastosGananciasSenior();
void RegistrarGastosGananciasGerente(char *departamento_gerente);
void RegistrarHorasDiarias(char *departamento_gerente);
void ImprimirEmpleosGerente(char *departamento_gerente);
void ImprimirDepartamentos();
void ImprimirEmpleados();


void MarcoPrincipal(){
	for( i=20;i<80;i++){
		gotoxy(i,2);printf("%c", 196);
		gotoxy(i,24);printf("%c", 196);
		gotoxy(i,4);printf("%c", 196);
	}
	
	for(c=3;c<24;c++){
		gotoxy(19,c);printf("%c", 179);
		gotoxy(80,c);printf("%c", 179);
	}
	gotoxy(40,3);printf("Control de salarios");
	gotoxy(19, 4);printf("%c",195);
	gotoxy(80,4);printf("%c", 180);	
	gotoxy(19,2);printf("%c", 201);
	gotoxy(19,24);printf("%c", 200);	
	gotoxy(80,2);printf("%c", 187);
	gotoxy(80,24);printf("%c", 188);
	
}

void MarcoPassword(){
	for( i=20;i<80;i++){
		gotoxy(i,6);printf("%c", 196);
		gotoxy(i,22);printf("%c", 196);
		gotoxy(i,10);printf("%c", 196);
	}
	
	for(c=6;c<22;c++){
		gotoxy(19,c);printf("%c", 179);
		gotoxy(80,c);printf("%c", 179);
	}	
	gotoxy(19,10);printf("%c",195); //Partidura izquierda
	gotoxy(80,10);printf("%c", 180);	//Partidura Derecha
	//Arriba estan las partiduras del medio
	gotoxy(19,6);printf("%c", 201);
	gotoxy(19,22);printf("%c", 200);	
	gotoxy(80,6);printf("%c", 187);
	gotoxy(80,22);printf("%c", 188);
	gotoxy(35,8);printf("Sistema Central Administradores");
}

void MarcoImpresiones(){
	
	gotoxy(1,2);printf("%c", 201);
	gotoxy(1,24);printf("%c", 200);
	gotoxy(80,2);printf("%c", 187);
	gotoxy(80,24);printf("%c", 188);
	for( i=2;i<80;i++){
		gotoxy(i,2);printf("%c", 196);
		gotoxy(i,24);printf("%c", 196);
		gotoxy(i,4);printf("%c", 196);
	}
	
	for(c=3;c<24;c++){
		gotoxy(1,c);printf("%c", 179);
		gotoxy(80,c);printf("%c", 179);
	}
	
	
	gotoxy(1, 4);printf("%c",195);
	gotoxy(80,4);printf("%c", 180);	
}

void MarcoRegistrar(){
	gotoxy(19,2);printf("%c", 201);
	gotoxy(19,24);printf("%c", 200);
	gotoxy(60,2);printf("%c", 187);
	gotoxy(60,24);printf("%c", 188);
	
	for( i=19;i<61;i++){
		gotoxy(i,2);printf("%c", 196);
		gotoxy(i,24);printf("%c", 196);
		gotoxy(i,4);printf("%c", 196);
	}
	
	for(c=3;c<24;c++){
		gotoxy(19,c);printf("%c", 179);
		gotoxy(60,c);printf("%c", 179);
	}
	
	//Marcos IzquierdaArriba, IzquierdaAbjo, DerechaArriba, DerechaAbajo
	gotoxy(19, 4);printf("%c",195);
	gotoxy(60,4);printf("%c", 180);	
	gotoxy(19,2);printf("%c", 201);
	gotoxy(19,24);printf("%c", 200);
	
	gotoxy(60,2);printf("%c", 187);
	gotoxy(60,24);printf("%c", 188);
	getch();
}


int FechaADias(char *fecha) {
    int dia, mes, anio;
    int dias_totales = 0;
    int dias_por_mes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    sscanf(fecha, "%d/%d/%d", &dia, &mes, &anio);
    
    // Sumar días de años completos
    for(int i = 1900; i < anio; i++) {
        if((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
            dias_totales += 366; // Año bisiesto
        } else {
            dias_totales += 365;
        }
    }
    
    // Ajustar febrero si es año bisiesto
    if((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
        dias_por_mes[1] = 29;
    }
    
    // Sumar días de meses completos del año actual
    for(int i = 0; i < mes - 1; i++) {
        dias_totales += dias_por_mes[i];
    }
    
    // Sumar días del mes actual
    dias_totales += dia;
    
    return dias_totales;
}

// Función para validar si la fecha está dentro del rango de días activos
int ValidarFechaEnRango(char *fecha_movimiento) {
    DiasActivosEstructura registro_activo;
    FILE *archivo;
    int fecha_mov_dias, fecha_apertura_dias, fecha_cierre_dias;
    int encontrado = 0;
    
    archivo = fopen("dias_activos.dat", "rb");
    if(archivo == NULL) {
        return 0; // No hay registros de días activos
    }
    
    fecha_mov_dias = FechaADias(fecha_movimiento);
    
    while(fread(&registro_activo, sizeof(DiasActivosEstructura), 1, archivo)) {
        fecha_apertura_dias = FechaADias(registro_activo.fecha_apertura);
        fecha_cierre_dias = fecha_apertura_dias + registro_activo.dias_activos - 1;
        
        if(fecha_mov_dias >= fecha_apertura_dias && fecha_mov_dias <= fecha_cierre_dias) {
            encontrado = 1;
            break;
        }
    }
    
    fclose(archivo);
    return encontrado;
}

// Estructura para los departamentos


// Función de animación de inicio
void AnimacionInicio(){
    clrscr();
    
    // Crear marco grande sin título
    gotoxy(1,2);printf("%c", 201);
    gotoxy(1,24);printf("%c", 200);
    gotoxy(80,2);printf("%c", 187);
    gotoxy(80,24);printf("%c", 188);
    
    // Líneas horizontales
    for(int anim_i=2; anim_i<80; anim_i++){
        gotoxy(anim_i,2);printf("%c", 196);
        gotoxy(anim_i,24);printf("%c", 196);
        Sleep(10);
    }
    
    // Líneas verticales
    for(int anim_c=3; anim_c<24; anim_c++){
        gotoxy(1,anim_c);printf("%c", 179);
        gotoxy(80,anim_c);printf("%c", 179);
        Sleep(30);
    }
    
    Sleep(500);
    
    // Animación de "CONSTELLIS"
    char constellis[] = "CONSTELLIS";
    int pos_x = 30;
    int pos_y = 10;
    
    gotoxy(pos_x, pos_y);
    for(int anim_i=0; anim_i<strlen(constellis); anim_i++){
        printf("%c", constellis[anim_i]);
        Sleep(150);
    }
    
    Sleep(300);
    
    // Animación de "CORP."
    char corp[] = "CORP.";
    pos_x = 35;
    pos_y = 12;
    
    gotoxy(pos_x, pos_y);
    for(int anim_i=0; anim_i<strlen(corp); anim_i++){
        printf("%c", corp[anim_i]);
        Sleep(150);
    }
    
    Sleep(500);
    
    // Efecto de parpadeo del título completo
    for(int parpadeo=0; parpadeo<3; parpadeo++){
        gotoxy(30, 10);printf("          ");
        gotoxy(35, 12);printf("     ");
        Sleep(200);
        
        gotoxy(30, 10);printf("CONSTELLIS");
        gotoxy(35, 12);printf("CORP.");
        Sleep(300);
    }
    
    Sleep(800);
    
    gotoxy(25, 16);printf("Inicializando sistema...");
    
    gotoxy(25, 18);printf("[");
    gotoxy(55, 18);printf("]");
    
    for(int anim_i=26; anim_i<55; anim_i++){
        gotoxy(anim_i, 18);printf("%c", 219);
        Sleep(80);
    }
    
    Sleep(500);
    gotoxy(28, 20);printf("Sistema listo!");
    Sleep(1000);
    
    for(int linea=24; linea>=2; linea--){
        for(int col=1; col<=80; col++){
            gotoxy(col, linea);printf(" ");
        }
        Sleep(20);
    }
}

// Función para registrar departamentos usando MarcoRegistrar
void RegistrarDepartamentos(){
    DepartamentoEstructura nuevo_dept;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(30,3);printf("Registrar Departamento");
    
    gotoxy(21,6);printf("Nombre del departamento:");
    gotoxy(21,8);gets(nuevo_dept.nombre_dept);
    
    gotoxy(21,10);printf("Numero del departamento:");
    gotoxy(21,12);scanf("%d", &nuevo_dept.numero_dept);
    fflush(stdin);
    
    gotoxy(21,14);printf("Nombre del gerente:");
    gotoxy(21,16);gets(nuevo_dept.nombre_gerente);
    
    gotoxy(21,18);printf("NIP del gerente:");
    gotoxy(21,20);gets(nuevo_dept.nip_gerente);
    
    archivo = fopen("departamentos.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_dept, sizeof(DepartamentoEstructura), 1, archivo);
        fclose(archivo);
        
        for(int line=6; line<=22; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Registrado exitosamente!");
        gotoxy(23,12);printf("Gerente: %s", nuevo_dept.nombre_gerente);
        gotoxy(23,14);printf("Depto: %s", nuevo_dept.nombre_dept);
    } else {
        gotoxy(23,10);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

// Función para registrar empleos (Gerente Senior) usando MarcoRegistrar
void RegistrarEmpleosSenior(){
    EmpleoEstructura nuevo_empleo;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(32,3);printf("Registrar Empleo");
    
    gotoxy(21,6);printf("Nombre del empleo:");
    gotoxy(21,7);gets(nuevo_empleo.nombre_empleo);
    
    do {
        gotoxy(21,9);printf("Jornada diaria (max 10 hrs): ");
        gotoxy(21,10);scanf("%f", &nuevo_empleo.jornada_diaria);
        fflush(stdin);
        
        if(nuevo_empleo.jornada_diaria > 10 || nuevo_empleo.jornada_diaria <= 0) {
            gotoxy(21,11);printf("Error: Entre 0.1 y 10 horas");
            gotoxy(21,12);printf("Presione tecla...");
            getch();
            gotoxy(21,11);printf("                          ");
            gotoxy(21,12);printf("                          ");
            gotoxy(21,10);printf("        ");
        }
    } while(nuevo_empleo.jornada_diaria > 10 || nuevo_empleo.jornada_diaria <= 0);
    
    gotoxy(21,12);printf("Salario por hora: $");
    gotoxy(21,13);scanf("%f", &nuevo_empleo.salario_por_hora);
    fflush(stdin);
    
    gotoxy(21,15);printf("Horas minimas:");
    gotoxy(21,16);scanf("%f", &nuevo_empleo.horas_minimas);
    fflush(stdin);
    
    gotoxy(21,18);printf("Departamento:");
    gotoxy(21,19);gets(nuevo_empleo.departamento);
    
    archivo = fopen("empleos.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_empleo, sizeof(EmpleoEstructura), 1, archivo);
        fclose(archivo);
        
        for(int line=6; line<=22; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Empleo registrado!");
        gotoxy(21,12);printf("Empleo: %s", nuevo_empleo.nombre_empleo);
        gotoxy(21,14);printf("Depto: %s", nuevo_empleo.departamento);
    } else {
        gotoxy(23,21);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

// Función para registrar empleos (Gerente de Departamento) usando MarcoRegistrar
void RegistrarEmpleosGerente(char *departamento_gerente){
    EmpleoEstructura nuevo_empleo;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(32,3);printf("Registrar Empleo");
    gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
    
    gotoxy(21,7);printf("Nombre del empleo:");
    gotoxy(21,8);gets(nuevo_empleo.nombre_empleo);
    
    do {
        gotoxy(21,10);printf("Jornada diaria (max 10 hrs): ");
        gotoxy(21,11);scanf("%f", &nuevo_empleo.jornada_diaria);
        fflush(stdin);
        
        if(nuevo_empleo.jornada_diaria > 10 || nuevo_empleo.jornada_diaria <= 0) {
            gotoxy(21,12);printf("Error: Entre 0.1 y 10 horas");
            gotoxy(21,13);printf("Presione tecla...");
            getch();
            gotoxy(21,12);printf("                          ");
            gotoxy(21,13);printf("                          ");
            gotoxy(21,11);printf("        ");
        }
    } while(nuevo_empleo.jornada_diaria > 10 || nuevo_empleo.jornada_diaria <= 0);
    
    gotoxy(21,13);printf("Salario por hora: $");
    gotoxy(21,14);scanf("%f", &nuevo_empleo.salario_por_hora);
    fflush(stdin);
    
    gotoxy(21,16);printf("Horas minimas:");
    gotoxy(21,17);scanf("%f", &nuevo_empleo.horas_minimas);
    fflush(stdin);
    
    strcpy(nuevo_empleo.departamento, departamento_gerente);
    
    archivo = fopen("empleos.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_empleo, sizeof(EmpleoEstructura), 1, archivo);
        fclose(archivo);
        
        for(int line=7; line<=21; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Empleo registrado!");
        gotoxy(21,12);printf("Empleo: %s", nuevo_empleo.nombre_empleo);
        gotoxy(21,14);printf("Depto: %s", nuevo_empleo.departamento);
    } else {
        gotoxy(23,19);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

// Función para registrar empleados (Gerente Senior) usando MarcoRegistrar
void RegistrarEmpleadosSenior(){
    EmpleadoEstructura nuevo_empleado;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(30,3);printf("Registrar Empleado");
    
    gotoxy(21,6);printf("Nombre del empleado:");
    gotoxy(21,7);gets(nuevo_empleado.nombre_empleado);
    
    gotoxy(21,9);printf("Apellido del empleado:");
    gotoxy(21,10);gets(nuevo_empleado.apellido_empleado);
    
    gotoxy(21,12);printf("Puesto:");
    gotoxy(21,13);gets(nuevo_empleado.puesto);
    
    gotoxy(21,15);printf("Departamento:");
    gotoxy(21,16);gets(nuevo_empleado.departamento);
    
    gotoxy(21,18);printf("Salario base: $");
    gotoxy(21,19);scanf("%f", &nuevo_empleado.salario_base);
    fflush(stdin);
    
    gotoxy(21,21);printf("ID del empleado:");
    gotoxy(21,22);scanf("%d", &nuevo_empleado.id_empleado);
    fflush(stdin);
    
    archivo = fopen("empleados.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_empleado, sizeof(EmpleadoEstructura), 1, archivo);
        fclose(archivo);
        
        for(int line=6; line<=22; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Empleado registrado!");
        gotoxy(21,12);printf("Nombre: %s %s", nuevo_empleado.nombre_empleado, nuevo_empleado.apellido_empleado);
        gotoxy(21,14);printf("Depto: %s", nuevo_empleado.departamento);
        gotoxy(21,16);printf("ID: %d", nuevo_empleado.id_empleado);
    } else {
        gotoxy(23,10);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

// Función para registrar empleados (Gerente de Departamento) usando MarcoRegistrar
void RegistrarEmpleadosGerente(char *departamento_gerente){
    EmpleadoEstructura nuevo_empleado;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(30,3);printf("Registrar Empleado");
    gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
    
    gotoxy(21,7);printf("Nombre del empleado:");
    gotoxy(21,8);gets(nuevo_empleado.nombre_empleado);
    
    gotoxy(21,10);printf("Apellido del empleado:");
    gotoxy(21,11);gets(nuevo_empleado.apellido_empleado);
    
    gotoxy(21,13);printf("Puesto:");
    gotoxy(21,14);gets(nuevo_empleado.puesto);
    
    // Asignar automáticamente el departamento del gerente
    strcpy(nuevo_empleado.departamento, departamento_gerente);
    
    gotoxy(21,16);printf("Salario base: $");
    gotoxy(21,17);scanf("%f", &nuevo_empleado.salario_base);
    fflush(stdin);
    
    gotoxy(21,19);printf("ID del empleado:");
    gotoxy(21,20);scanf("%d", &nuevo_empleado.id_empleado);
    fflush(stdin);
    
    archivo = fopen("empleados.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_empleado, sizeof(EmpleadoEstructura), 1, archivo);
        fclose(archivo);
        
        for(int line=7; line<=22; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Empleado registrado!");
        gotoxy(21,12);printf("Nombre: %s %s", nuevo_empleado.nombre_empleado, nuevo_empleado.apellido_empleado);
        gotoxy(21,14);printf("Depto: %s", nuevo_empleado.departamento);
        gotoxy(21,16);printf("ID: %d", nuevo_empleado.id_empleado);
    } else {
        gotoxy(23,10);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

// Función para verificar credenciales
int VerificarCredenciales(char *nombre, char *nip, char *departamento){
    DepartamentoEstructura dept_temp;
    FILE *archivo;
    
    if ( ((strcmp(nombre, "Angel")==0) || (strcmp(nombre,"Said")==0)) && ((strcmp(nip, "0805") == 0) || (strcmp(nip, "0725")==0 )) && strcmp(departamento, "Administracion") == 0) {
        return 1;
    }
    
    archivo = fopen("departamentos.dat", "rb");
    if(archivo != NULL){
        while(fread(&dept_temp, sizeof(DepartamentoEstructura), 1, archivo)){
            if(strcmp(nombre, dept_temp.nombre_gerente) == 0 && 
               strcmp(nip, dept_temp.nip_gerente) == 0 && 
               strcmp(departamento, dept_temp.nombre_dept) == 0){
                fclose(archivo);
                return 2;
            }
        }
        fclose(archivo);
    }
    
    return 0;
}

// Menú principal para gerente senior usando MarcoImpresiones
void MenuPrincipal(){
    int opcion;
    
    do{
        clrscr();
        MarcoImpresiones();
        
        gotoxy(27,3);printf("Sistema Principal Gerente Senior");
        
        gotoxy(3,6);printf("0.- Cerrar el sistema");
        gotoxy(3,7);printf("1.- Registrar empleos");
        gotoxy(3,8);printf("2.- Registrar departamentos");
        gotoxy(3,9);printf("3.- Registrar empleados");
        gotoxy(3,10);printf("4.- Registrar dias activos");
        gotoxy(3,11);printf("5.- Registrar gastos y ganancias");
        gotoxy(3,12);printf("6.- Imprimir empleos");
        gotoxy(3,13);printf("7.- Imprimir departamentos");
        gotoxy(3,14);printf("8.- Imprimir empleados");
        gotoxy(3,15);printf("9.- Imprimir Salarios");
        gotoxy(3,16);printf("10.- Imprimir movimientos");
        
        gotoxy(3,18);printf("Seleccione opcion (0-10): ");
        scanf("%d", &opcion);
        fflush(stdin);
        
        switch(opcion){
            case 0:
                gotoxy(3,20);printf("Cerrando sistema...");
                gotoxy(3,21);printf("Gracias!");
                break;
            case 1:
                RegistrarEmpleosSenior();
                break;
            case 2:
                RegistrarDepartamentos();
                break;
            case 3:
                RegistrarEmpleadosSenior();
                break;
            case 4:
                RegistrarDiasActivos();
                break;  
            case 5:
    			RegistrarGastosGananciasSenior();
    			break;
    		case 6:
    			ImprimirEmpleos();
    			break;
    		case 7:
    			ImprimirDepartamentos();
    			break;
    		case 8:
    			ImprimirEmpleados();
    			break;
            default:
                if(opcion >= 9 && opcion <= 10){
                    gotoxy(3,20);printf("Modulo en desarrollo...");
                } else {
                    gotoxy(3,20);printf("Opcion invalida.");
                }
                break;
        }
        
        if(opcion != 0 && opcion != 1 && opcion != 2 && opcion != 3){
            gotoxy(3,22);printf("Presione tecla para continuar...");
            getch();
        }
        
    }while(opcion != 0);
}

// Menú para gerente de departamento usando MarcoPrincipal
void MenuGerenteRegistrado(char *nombre_gerente, char *departamento){
    int opcion;
    
    strcpy(gerente_actual_local, nombre_gerente);
    strcpy(departamento_actual_local, departamento);
    
    do{
        clrscr();
        MarcoPrincipal();
        
        gotoxy(3,6);printf("0.- Cerrar sesion");
        gotoxy(3,7);printf("1.- Registrar empleos");
        gotoxy(3,8);printf("2.- Registrar empleados");
        gotoxy(3,9);printf("3.- Registrar ganancias o gastos");
        gotoxy(3,10);printf("4.- Gestionar horas de empleados");
        gotoxy(3,11);printf("5.- Imprimir empleos");
        gotoxy(3,12);printf("6.- Imprimir empleados");
        
        gotoxy(3,14);printf("Seleccione opcion (0-6): ");
        scanf("%d", &opcion);
        fflush(stdin);
        
        switch(opcion){
            case 0:
                gotoxy(3,16);printf("Cerrando sesion...");
                break;
            case 1:
                RegistrarEmpleosGerente(departamento_actual_local);
                break;
            case 2:
                RegistrarEmpleadosGerente(departamento_actual_local);
                break;
                
            case 3:
				RegistrarGastosGananciasGerente(departamento_actual_local);
    			break;
    		case 4:
    			RegistrarHorasDiarias(departamento_actual_local);
    			break;
    		case 5:
    			ImprimirEmpleosGerente(departamento_actual_local);
    			break;
            default:
                if(opcion >= 4 && opcion <= 6){
                    gotoxy(3,16);printf("Modulo en desarrollo...");
                } else {
                    gotoxy(3,16);printf("Opcion invalida.");
                }
                break;
        }
        
        if(opcion != 0){
            gotoxy(3,22);printf("Presione tecla para continuar...");
            getch();
        }
        
    }while(opcion != 0);
}

// Función principal de autenticación usando MarcoPassword
void password(){
    char nombre[50];
    char nip[10];
    char departamento[50];
    int resultado_auth;
    int intentos = 0;
    int max_intentos = 5;
    
    do {
        clrscr();
        MarcoPassword();
        
        gotoxy(21,11);printf("Intento %d de %d", intentos + 1, max_intentos);
        
        gotoxy(21,12);printf("Nombre del gerente: ");
        gotoxy(21,13);gets(nombre);
        
        gotoxy(21,15);printf("NIP: ");
        gotoxy(21,16);gets(nip);
        
        gotoxy(21,18);printf("Departamento: ");
        gotoxy(21,19);gets(departamento);
        
        resultado_auth = VerificarCredenciales(nombre, nip, departamento);
        
        if(resultado_auth > 0) {
            clrscr();
            MarcoPassword();
            
            gotoxy(38,8);printf("ACCESO AUTORIZADO");
            gotoxy(42,12);printf("BIENVENIDO");
            gotoxy(21,14);printf("Gerente: %s", nombre);
            gotoxy(21,16);printf("NIP: %s", nip);
            gotoxy(21,18);printf("Departamento: %s", departamento);
            
            gotoxy(28,21);printf("Presione tecla para continuar...");
            getch();
            
            if(resultado_auth == 1){
                MenuPrincipal();
            } else if(resultado_auth == 2){
                MenuGerenteRegistrado(nombre, departamento);
            }
            return;
            
        } else {
            intentos++;
            
            if(intentos < max_intentos) {
                gotoxy(38,12);printf("ACCESO DENEGADO");
                gotoxy(24,14);printf("Datos incorrectos.");
                gotoxy(26,16);printf("Verifique informacion.");
                gotoxy(21,18);printf("Intentos restantes: %d", max_intentos - intentos);
                
                gotoxy(28,21);printf("Presione tecla para continuar...");
                getch();
            } else {
                gotoxy(38,12);printf("ACCESO BLOQUEADO");
                gotoxy(24,14);printf("Demasiados intentos fallidos.");
                gotoxy(26,16);printf("El sistema se cerrara.");
                
                gotoxy(28,21);printf("Presione tecla para salir...");
                getch();
                
                clrscr();
                gotoxy(35,12);printf("SISTEMA CERRADO");
                gotoxy(28,14);printf("Por seguridad del sistema.");
                gotoxy(25,16);printf("Contacte al administrador.");
                
                gotoxy(28,21);printf("Presione tecla para terminar...");
                getch();
                return;
            }
        }
        
    } while(intentos < max_intentos);
}

void RegistrarDiasActivos(){
    DiasActivosEstructura nuevo_registro;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(30,3);printf("Registrar Dias Activos");
    
    gotoxy(21,6);printf("Fecha de apertura (DD/MM/AAAA):");
    gotoxy(21,7);gets(nuevo_registro.fecha_apertura);
    
    do {
        gotoxy(21,9);printf("Cantidad de dias activos: ");
        gotoxy(21,10);scanf("%d", &nuevo_registro.dias_activos);
        fflush(stdin);
        
        if(nuevo_registro.dias_activos <= 0 || nuevo_registro.dias_activos > 365) {
            gotoxy(21,11);printf("Error: Entre 1 y 365 dias");
            gotoxy(21,12);printf("Presione tecla...");
            getch();
            gotoxy(21,11);printf("                        ");
            gotoxy(21,12);printf("                        ");
            gotoxy(21,10);printf("    ");
        }
    } while(nuevo_registro.dias_activos <= 0 || nuevo_registro.dias_activos > 365);
    
    gotoxy(21,12);printf("Concepto (motivo apertura):");
    gotoxy(21,13);gets(nuevo_registro.concepto);
    
    // Registrar fecha actual (simulada)
    gotoxy(21,15);printf("Fecha de registro (DD/MM/AAAA):");
    gotoxy(21,16);gets(nuevo_registro.fecha_registro);
    
    archivo = fopen("dias_activos.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_registro, sizeof(DiasActivosEstructura), 1, archivo);
        fclose(archivo);
        
        // Limpiar área de entrada
        for(int line=6; line<=22; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,9);printf("Dias registrados!");
        gotoxy(21,11);printf("Apertura: %s", nuevo_registro.fecha_apertura);
        gotoxy(21,13);printf("Dias: %d", nuevo_registro.dias_activos);
        gotoxy(21,15);printf("Concepto: %.25s", nuevo_registro.concepto);
        if(strlen(nuevo_registro.concepto) > 25) {
            gotoxy(21,16);printf("%.25s", nuevo_registro.concepto + 25);
        }
        
    } else {
        gotoxy(23,18);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}
int main() {
    AnimacionInicio();
    password();
    return 0;
}


void RegistrarGastosGananciasSenior(){
    MovimientoFinanciero nuevo_movimiento;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(28,3);printf("Registrar Movimientos");
    
    gotoxy(21,6);printf("Concepto del movimiento:");
    gotoxy(21,7);gets(nuevo_movimiento.concepto);
    
    gotoxy(21,9);printf("Tipo (Ingreso/Gasto):");
    gotoxy(21,10);gets(nuevo_movimiento.tipo_movimiento);
    
    gotoxy(21,12);printf("Cantidad: $");
    gotoxy(21,13);scanf("%f", &nuevo_movimiento.cantidad);
    fflush(stdin);
    
    // Si es gasto, hacer la cantidad negativa
    if(strcmp(nuevo_movimiento.tipo_movimiento, "Gasto") == 0 || 
       strcmp(nuevo_movimiento.tipo_movimiento, "gasto") == 0) {
        nuevo_movimiento.cantidad = -abs(nuevo_movimiento.cantidad);
    }
    
    gotoxy(21,15);printf("Fecha (DD/MM/AAAA):");
    gotoxy(21,16);gets(nuevo_movimiento.fecha_movimiento);
    
    // Validar fecha en rango de días activos
    if(!ValidarFechaEnRango(nuevo_movimiento.fecha_movimiento)) {
        gotoxy(21,18);printf("Error: Fecha fuera de");
        gotoxy(21,19);printf("periodo activo");
        gotoxy(25,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    gotoxy(21,18);printf("Numero de factura:");
    gotoxy(21,19);scanf("%d", &nuevo_movimiento.numero_factura);
    fflush(stdin);
    
    gotoxy(21,21);printf("Departamento:");
    gotoxy(21,22);gets(nuevo_movimiento.departamento);
    
    archivo = fopen("movimientos.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_movimiento, sizeof(MovimientoFinanciero), 1, archivo);
        fclose(archivo);
        
        // Limpiar área
        for(int line=6; line<=22; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Movimiento registrado!");
        gotoxy(21,12);printf("Tipo: %s", nuevo_movimiento.tipo_movimiento);
        gotoxy(21,14);printf("Cantidad: $%.2f", nuevo_movimiento.cantidad);
        gotoxy(21,16);printf("Factura: %d", nuevo_movimiento.numero_factura);
    } else {
        gotoxy(23,18);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

void RegistrarGastosGananciasGerente(char *departamento_gerente){
    MovimientoFinanciero nuevo_movimiento;
    FILE *archivo;
    
    clrscr();
    MarcoRegistrar();
    
    gotoxy(28,3);printf("Registrar Movimientos");
    gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
    
    gotoxy(21,7);printf("Concepto del movimiento:");
    gotoxy(21,8);gets(nuevo_movimiento.concepto);
    
    gotoxy(21,10);printf("Tipo (Ingreso/Gasto):");
    gotoxy(21,11);gets(nuevo_movimiento.tipo_movimiento);
    
    gotoxy(21,13);printf("Cantidad: $");
    gotoxy(21,14);scanf("%f", &nuevo_movimiento.cantidad);
    fflush(stdin);
    
    // Si es gasto, hacer la cantidad negativa
    if(strcmp(nuevo_movimiento.tipo_movimiento, "Gasto") == 0 || 
       strcmp(nuevo_movimiento.tipo_movimiento, "gasto") == 0) {
        nuevo_movimiento.cantidad = -abs(nuevo_movimiento.cantidad);
    }
    
    gotoxy(21,16);printf("Fecha (DD/MM/AAAA):");
    gotoxy(21,17);gets(nuevo_movimiento.fecha_movimiento);
    
    // Validar fecha en rango de días activos
    if(!ValidarFechaEnRango(nuevo_movimiento.fecha_movimiento)) {
        gotoxy(21,19);printf("Error: Fecha fuera de");
        gotoxy(21,20);printf("periodo activo");
        gotoxy(25,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    gotoxy(21,19);printf("Numero de factura:");
    gotoxy(21,20);scanf("%d", &nuevo_movimiento.numero_factura);
    fflush(stdin);
    
    // Asignar automáticamente el departamento del gerente
    strcpy(nuevo_movimiento.departamento, departamento_gerente);
    
    archivo = fopen("movimientos.dat", "ab");
    if(archivo != NULL){
        fwrite(&nuevo_movimiento, sizeof(MovimientoFinanciero), 1, archivo);
        fclose(archivo);
        
        // Limpiar área
        for(int line=7; line<=21; line++){
            for(int col=21; col<59; col++){
                gotoxy(col,line);printf(" ");
            }
        }
        
        gotoxy(23,10);printf("Movimiento registrado!");
        gotoxy(21,12);printf("Tipo: %s", nuevo_movimiento.tipo_movimiento);
        gotoxy(21,14);printf("Cantidad: $%.2f", nuevo_movimiento.cantidad);
        gotoxy(21,16);printf("Factura: %d", nuevo_movimiento.numero_factura);
    } else {
        gotoxy(23,18);printf("Error al guardar.");
    }
    
    gotoxy(25,22);printf("Presione tecla para continuar...");
    getch();
}

void RegistrarHorasDiarias(char *departamento_gerente){
    EmpleadoEstructura empleado_temp;
    HorasTrabajadasEstructura registro_horas;
    DiasActivosEstructura dia_activo;
    FILE *archivo_empleados, *archivo_horas, *archivo_dias;
    char fecha_trabajo[20];
    int empleados_encontrados = 0;
    int linea_actual = 6;
    int hay_dias_activos = 0;
    
    clrscr();
    MarcoImpresiones();
    
    gotoxy(25,3);printf("Registro de Horas Diarias - %s", departamento_gerente);
    
    // Verificar si hay días activos registrados
    archivo_dias = fopen("dias_activos.dat", "rb");
    if(archivo_dias != NULL) {
        if(fread(&dia_activo, sizeof(DiasActivosEstructura), 1, archivo_dias)) {
            hay_dias_activos = 1;
        }
        fclose(archivo_dias);
    }
    
    if(!hay_dias_activos) {
        gotoxy(3,8);printf("Error: No hay dias activos registrados en el sistema.");
        gotoxy(3,10);printf("Contacte al gerente senior para configurar los dias activos.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    gotoxy(3,5);printf("Fecha de trabajo (DD/MM/AAAA): ");
    gets(fecha_trabajo);
    
    // Validar que la fecha esté en el rango de días activos
    if(!ValidarFechaEnRango(fecha_trabajo)) {
        gotoxy(3,7);printf("Error: La fecha ingresada no esta en el periodo activo.");
        gotoxy(3,8);printf("Verifique que la fecha este dentro del rango autorizado.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    gotoxy(3,7);printf("Empleados del departamento %s:", departamento_gerente);
    gotoxy(3,8);printf("----------------------------------------------------------------------------");
    
    // Leer empleados del departamento
    archivo_empleados = fopen("empleados.dat", "rb");
    if(archivo_empleados == NULL) {
        gotoxy(3,10);printf("Error: No se pudo abrir el archivo de empleados.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    while(fread(&empleado_temp, sizeof(EmpleadoEstructura), 1, archivo_empleados)) {
        if(strcmp(empleado_temp.departamento, departamento_gerente) == 0) {
            empleados_encontrados++;
            linea_actual++;
            
            if(linea_actual > 20) {
                gotoxy(3,21);printf("Demasiados empleados. Presione tecla para continuar...");
                getch();
                
                // Limpiar área de empleados
                for(int clear_line = 9; clear_line <= 20; clear_line++) {
                    for(int clear_col = 3; clear_col < 78; clear_col++) {
                        gotoxy(clear_col, clear_line);printf(" ");
                    }
                }
                linea_actual = 9;
            }
            
            // Mostrar información del empleado en una línea
            gotoxy(3, linea_actual);
            printf("%d. %-20s %-15s Horas [ ", 
                   empleado_temp.id_empleado, 
                   empleado_temp.nombre_empleado, 
                   empleado_temp.puesto);
            
            // Leer las horas trabajadas
            scanf("%f", &registro_horas.horas_trabajadas);
            fflush(stdin);
            
            // Validar horas (no pueden ser negativas ni exceder 24 horas)
            while(registro_horas.horas_trabajadas < 0 || registro_horas.horas_trabajadas > 24) {
                gotoxy(3, linea_actual + 1);
                printf("Error: Las horas deben estar entre 0 y 24. Reingrese: ");
                scanf("%f", &registro_horas.horas_trabajadas);
                fflush(stdin);
                
                // Limpiar línea de error
                for(int clear_col = 3; clear_col < 78; clear_col++) {
                    gotoxy(clear_col, linea_actual + 1);printf(" ");
                }
            }
            
            printf("] (%.2f hrs registradas)", registro_horas.horas_trabajadas);
            
            // Llenar la estructura de horas trabajadas
            registro_horas.id_empleado = empleado_temp.id_empleado;
            strcpy(registro_horas.nombre_empleado, empleado_temp.nombre_empleado);
            strcpy(registro_horas.apellido_empleado, empleado_temp.apellido_empleado);
            strcpy(registro_horas.puesto, empleado_temp.puesto);
            strcpy(registro_horas.departamento, empleado_temp.departamento);
            strcpy(registro_horas.fecha_trabajo, fecha_trabajo);
            
            // Guardar el registro de horas
            archivo_horas = fopen("horas_trabajadas.dat", "ab");
            if(archivo_horas != NULL) {
                fwrite(&registro_horas, sizeof(HorasTrabajadasEstructura), 1, archivo_horas);
                fclose(archivo_horas);
            }
        }
    }
    
    fclose(archivo_empleados);
    
    if(empleados_encontrados == 0) {
        gotoxy(3,10);printf("No se encontraron empleados en el departamento %s", departamento_gerente);
        gotoxy(3,12);printf("Verifique que haya empleados registrados en su departamento.");
    } else {
        linea_actual += 2;
        gotoxy(3, linea_actual);
        printf("----------------------------------------------------------------------------");
        linea_actual++;
        gotoxy(3, linea_actual);
        printf("Total de empleados procesados: %d", empleados_encontrados);
        linea_actual++;
        gotoxy(3, linea_actual);
        printf("Fecha registrada: %s", fecha_trabajo);
        linea_actual++;
        gotoxy(3, linea_actual);
        printf("Horas registradas exitosamente para el departamento %s", departamento_gerente);
    }
    
    gotoxy(3,22);printf("Presione tecla para continuar...");
    getch();
}


void ImprimirEmpleos(){
    EmpleoEstructura empleo_temp;
    FILE *archivo;
    int contador = 0;
    int linea_actual = 6;
    int pagina = 1;
    
    clrscr();
    MarcoImpresiones();
    
    gotoxy(30,3);printf("Listado de Empleos");
    
    archivo = fopen("empleos.dat", "rb");
    if(archivo == NULL) {
        gotoxy(3,8);printf("Error: No se pudo abrir el archivo de empleos.");
        gotoxy(3,10);printf("Verifique que existan empleos registrados en el sistema.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Verificar si hay empleos registrados
    fseek(archivo, 0, SEEK_END);
    if(ftell(archivo) == 0) {
        fclose(archivo);
        gotoxy(3,8);printf("No hay empleos registrados en el sistema.");
        gotoxy(3,10);printf("Registre empleos primero desde el menu principal.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Volver al inicio del archivo
    fseek(archivo, 0, SEEK_SET);
    
    gotoxy(3,5);printf("Pagina %d", pagina);
    gotoxy(3,6);printf("============================================================================");
    
    while(fread(&empleo_temp, sizeof(EmpleoEstructura), 1, archivo)) {
        contador++;
        
        // Control de paginación
        if(linea_actual > 20) {
            gotoxy(3,21);printf("============================================================================");
            gotoxy(3,22);printf("Presione tecla para continuar a la siguiente pagina...");
            getch();
            
            // Limpiar pantalla para nueva página
            clrscr();
            MarcoImpresiones();
            pagina++;
            gotoxy(30,3);printf("Listado de Empleos");
            gotoxy(3,5);printf("Pagina %d", pagina);
            gotoxy(3,6);printf("============================================================================");
            linea_actual = 7;
        }
        
        // Mostrar información del empleo
        gotoxy(3, linea_actual);
        printf("Empleo #%d: %-25s", contador, empleo_temp.nombre_empleo);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("  Departamento: %-20s", empleo_temp.departamento);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("  Jornada Diaria: %.2f hrs", empleo_temp.jornada_diaria);
        printf("      Horas Minimas: %.2f hrs", empleo_temp.horas_minimas);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("  Salario por Hora: $%.2f", empleo_temp.salario_por_hora);
        
        // Calcular salario base (horas mínimas * salario por hora)
        float salario_base = empleo_temp.horas_minimas * empleo_temp.salario_por_hora;
        printf("   Salario Base: $%.2f", salario_base);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("  ----------------------------------------------------------------------------");
        linea_actual++;
        
        // Espacio entre empleos
        linea_actual++;
    }
    
    fclose(archivo);
    
    if(contador == 0) {
        gotoxy(3,8);printf("No se encontraron empleos en el archivo.");
    } else {
        gotoxy(3,22);printf("Total de empleos mostrados: %d", contador);
    }
    
    gotoxy(3,23);printf("Presione tecla para regresar al menu...");
    getch();
}


void ImprimirEmpleosGerente(char*departamento_gerente){
    EmpleoEstructura empleo_temp;
    FILE *archivo;
    int contador = 0;
    int linea_actual = 7;
    int pagina = 1;
    
    clrscr();
    MarcoPrincipal();
    
    gotoxy(25,3);printf("Empleos del Departamento");
    gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
    gotoxy(21,6);printf("========================================================");
    
    archivo = fopen("empleos.dat", "rb");
    if(archivo == NULL) {
        gotoxy(21,8);printf("Error: No se pudo abrir el archivo de empleos.");
        gotoxy(21,10);printf("Verifique que existan empleos registrados.");
        gotoxy(21,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Verificar si hay empleos registrados
    fseek(archivo, 0, SEEK_END);
    if(ftell(archivo) == 0) {
        fclose(archivo);
        gotoxy(21,8);printf("No hay empleos registrados en el sistema.");
        gotoxy(21,10);printf("Registre empleos primero desde este menu.");
        gotoxy(21,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Volver al inicio del archivo
    fseek(archivo, 0, SEEK_SET);
    
    while(fread(&empleo_temp, sizeof(EmpleoEstructura), 1, archivo)) {
        // Solo mostrar empleos del departamento del gerente
        if(strcmp(empleo_temp.departamento, departamento_gerente) == 0) {
            contador++;
            
            // Control de paginación
            if(linea_actual > 20) {
                gotoxy(21,21);printf("========================================================");
                gotoxy(21,22);printf("Presione tecla para continuar...");
                getch();
                
                // Limpiar área de contenido
                for(int clear_line = 7; clear_line <= 20; clear_line++) {
                    for(int clear_col = 21; clear_col < 79; clear_col++) {
                        gotoxy(clear_col, clear_line);printf(" ");
                    }
                }
                pagina++;
                gotoxy(65,5);printf("(Pag. %d)", pagina);
                linea_actual = 7;
            }
            
            // Mostrar información del empleo (sin departamento)
            gotoxy(21, linea_actual);
            printf("Empleo #%d: %-25s", contador, empleo_temp.nombre_empleo);
            linea_actual++;
            
            gotoxy(21, linea_actual);
            printf("  Jornada Diaria: %.2f hrs", empleo_temp.jornada_diaria);
            linea_actual++;
            
            gotoxy(21, linea_actual);
            printf("  Horas Minimas: %.2f hrs", empleo_temp.horas_minimas);
            linea_actual++;
            
            gotoxy(21, linea_actual);
            printf("  Salario por Hora: $%.2f", empleo_temp.salario_por_hora);
            linea_actual++;
            
            // Calcular salario base (horas mínimas * salario por hora)
            float salario_base = empleo_temp.horas_minimas * empleo_temp.salario_por_hora;
            gotoxy(21, linea_actual);
            printf("  Salario Base: $%.2f", salario_base);
            linea_actual++;
            
            gotoxy(21, linea_actual);
            printf("  ------------------------------------------------");
            linea_actual++;
            
            // Espacio entre empleos
            linea_actual++;
        }
    }
    
    fclose(archivo);
    
    if(contador == 0) {
        gotoxy(21,8);printf("No hay empleos registrados en su departamento.");
        gotoxy(21,10);printf("Use la opcion 1 para registrar empleos.");
    } else {
        gotoxy(21,21);printf("Total de empleos en su departamento: %d", contador);
    }
    
    gotoxy(21,22);printf("Presione tecla para regresar al menu...");
    getch();
}

void ImprimirEmpleados(){
    EmpleadoEstructura empleado_temp;
    HorasTrabajadasEstructura horas_temp;
    EmpleoEstructura empleo_temp;
    FILE *archivo_empleados, *archivo_horas, *archivo_empleos;
    int mes_consulta, anio_consulta;
    int contador = 0;
    int linea_actual = 7;
    int pagina = 1;
    float total_horas_mes, salario_calculado;
    char mes_str[3], anio_str[5];
    int encontrado_empleo;
    
    clrscr();
    MarcoImpresiones();
    
    gotoxy(25,3);printf("Reporte de Empleados por Mes");
    
    // Solicitar mes y año
    gotoxy(3,5);printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes_consulta);
    fflush(stdin);
    
    while(mes_consulta < 1 || mes_consulta > 12) {
        gotoxy(3,6);printf("Error: Mes debe estar entre 1 y 12. Reingrese: ");
        scanf("%d", &mes_consulta);
        fflush(stdin);
        // Limpiar línea de error
        for(int clear_col = 3; clear_col < 78; clear_col++) {
            gotoxy(clear_col, 6);printf(" ");
        }
    }
    
    gotoxy(3,6);printf("Ingrese el año (ej: 2024): ");
    scanf("%d", &anio_consulta);
    fflush(stdin);
    
    // Convertir mes y año a strings para comparación
    sprintf(mes_str, "%02d", mes_consulta);
    sprintf(anio_str, "%d", anio_consulta);
    
    gotoxy(3,7);printf("Mes: %02d/%d", mes_consulta, anio_consulta);
    gotoxy(3,8);printf("============================================================================");
    
    // Abrir archivos
    archivo_empleados = fopen("empleados.dat", "rb");
    if(archivo_empleados == NULL) {
        gotoxy(3,10);printf("Error: No se pudo abrir el archivo de empleados.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    archivo_horas = fopen("horas_trabajadas.dat", "rb");
    if(archivo_horas == NULL) {
        gotoxy(3,10);printf("Error: No se pudo abrir el archivo de horas trabajadas.");
        fclose(archivo_empleados);
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    archivo_empleos = fopen("empleos.dat", "rb");
    if(archivo_empleos == NULL) {
        gotoxy(3,10);printf("Error: No se pudo abrir el archivo de empleos.");
        fclose(archivo_empleados);
        fclose(archivo_horas);
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Procesar cada empleado
    while(fread(&empleado_temp, sizeof(EmpleadoEstructura), 1, archivo_empleados)) {
        contador++;
        total_horas_mes = 0.0;
        salario_calculado = 0.0;
        encontrado_empleo = 0;
        
        // Control de paginación
        if(linea_actual > 20) {
            gotoxy(3,21);printf("============================================================================");
            gotoxy(3,22);printf("Presione tecla para continuar a la siguiente pagina...");
            getch();
            
            // Limpiar pantalla para nueva página
            clrscr();
            MarcoImpresiones();
            pagina++;
            gotoxy(25,3);printf("Reporte de Empleados por Mes");
            gotoxy(3,5);printf("Mes: %02d/%d (Pagina %d)", mes_consulta, anio_consulta, pagina);
            gotoxy(3,6);printf("============================================================================");
            linea_actual = 7;
        }
        
        // Calcular horas trabajadas en el mes específico
        fseek(archivo_horas, 0, SEEK_SET);
        while(fread(&horas_temp, sizeof(HorasTrabajadasEstructura), 1, archivo_horas)) {
            if(horas_temp.id_empleado == empleado_temp.id_empleado) {
                // Verificar si la fecha pertenece al mes consultado
                char fecha_mes[3], fecha_anio[5];
                sscanf(horas_temp.fecha_trabajo, "%*d/%2s/%4s", fecha_mes, fecha_anio);
                
                if(strcmp(fecha_mes, mes_str) == 0 && strcmp(fecha_anio, anio_str) == 0) {
                    total_horas_mes += horas_temp.horas_trabajadas;
                }
            }
        }
        
        // Buscar información del empleo para calcular salario
        fseek(archivo_empleos, 0, SEEK_SET);
        while(fread(&empleo_temp, sizeof(EmpleoEstructura), 1, archivo_empleos)) {
            if(strcmp(empleo_temp.nombre_empleo, empleado_temp.puesto) == 0 && 
               strcmp(empleo_temp.departamento, empleado_temp.departamento) == 0) {
                encontrado_empleo = 1;
                salario_calculado = total_horas_mes * empleo_temp.salario_por_hora;
                break;
            }
        }
        
        // Si no se encuentra el empleo, usar salario base
        if(!encontrado_empleo) {
            salario_calculado = empleado_temp.salario_base;
        }
        
        // Mostrar información del empleado
        gotoxy(3, linea_actual);
        printf("ID: %-4d %-20s %-15s", 
               empleado_temp.id_empleado,
               empleado_temp.nombre_empleado,
               empleado_temp.apellido_empleado);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("Empleo: %-25s Depto: %-20s", 
               empleado_temp.puesto,
               empleado_temp.departamento);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("Horas Mes: %6.2f hrs", total_horas_mes);
        printf("               Salario: $%8.2f", salario_calculado);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("----------------------------------------------------------------------------");
        linea_actual++;
        
        // Espacio entre empleados
        linea_actual++;
    }
    
    // Cerrar archivos
    fclose(archivo_empleados);
    fclose(archivo_horas);
    fclose(archivo_empleos);
    
    if(contador == 0) {
        gotoxy(3,10);printf("No se encontraron empleados en el sistema.");
    } else {
        gotoxy(3,22);printf("Total de empleados procesados: %d", contador);
    }
    
    gotoxy(3,23);printf("Presione tecla para regresar al menu...");
    getch();
}

void ImprimirDepartamentos(){
    DepartamentoEstructura dept_temp;
    EmpleadoEstructura empleado_temp;
    EmpleoEstructura empleo_temp;
    FILE *archivo_dept, *archivo_empleados, *archivo_empleos;
    int contador_dept = 0;
    int linea_actual = 6;
    int pagina = 1;
    
    clrscr();
    MarcoImpresiones();
    
    gotoxy(25,3);printf("Listado de Departamentos");
    
    // Abrir archivo de departamentos
    archivo_dept = fopen("departamentos.dat", "rb");
    if(archivo_dept == NULL) {
        gotoxy(3,8);printf("Error: No se pudo abrir el archivo de departamentos.");
        gotoxy(3,10);printf("Verifique que existan departamentos registrados en el sistema.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Verificar si hay departamentos registrados
    fseek(archivo_dept, 0, SEEK_END);
    if(ftell(archivo_dept) == 0) {
        fclose(archivo_dept);
        gotoxy(3,8);printf("No hay departamentos registrados en el sistema.");
        gotoxy(3,10);printf("Registre departamentos primero desde el menu principal.");
        gotoxy(3,22);printf("Presione tecla para continuar...");
        getch();
        return;
    }
    
    // Volver al inicio del archivo
    fseek(archivo_dept, 0, SEEK_SET);
    
    gotoxy(3,5);printf("Pagina %d", pagina);
    gotoxy(3,6);printf("============================================================================");
    
    while(fread(&dept_temp, sizeof(DepartamentoEstructura), 1, archivo_dept)) {
        contador_dept++;
        
        // Control de paginación
        if(linea_actual > 19) {
            gotoxy(3,21);printf("============================================================================");
            gotoxy(3,22);printf("Presione tecla para continuar a la siguiente pagina...");
            getch();
            
            // Limpiar pantalla para nueva página
            clrscr();
            MarcoImpresiones();
            pagina++;
            gotoxy(25,3);printf("Listado de Departamentos");
            gotoxy(3,5);printf("Pagina %d", pagina);
            gotoxy(3,6);printf("============================================================================");
            linea_actual = 7;
        }
        
        // Mostrar información básica del departamento
        gotoxy(3, linea_actual);
        printf("Departamento #%d: %-30s (Num: %d)", 
               contador_dept, dept_temp.nombre_dept, dept_temp.numero_dept);
        linea_actual++;
        
        gotoxy(3, linea_actual);
        printf("  Gerente: %-25s NIP: %s", 
               dept_temp.nombre_gerente, dept_temp.nip_gerente);
        linea_actual++;
        
        // Contar empleados y calcular salario total del departamento
        int cantidad_empleados = 0;
        float salario_total_dept = 0.0;
        
        archivo_empleados = fopen("empleados.dat", "rb");
        if(archivo_empleados != NULL) {
            while(fread(&empleado_temp, sizeof(EmpleadoEstructura), 1, archivo_empleados)) {
                if(strcmp(empleado_temp.departamento, dept_temp.nombre_dept) == 0) {
                    cantidad_empleados++;
                    
                    // Buscar el empleo correspondiente para obtener horas mínimas
                    archivo_empleos = fopen("empleos.dat", "rb");
                    if(archivo_empleos != NULL) {
                        float salario_empleado = empleado_temp.salario_base;
                        
                        while(fread(&empleo_temp, sizeof(EmpleoEstructura), 1, archivo_empleos)) {
                            if(strcmp(empleo_temp.nombre_empleo, empleado_temp.puesto) == 0 &&
                               strcmp(empleo_temp.departamento, dept_temp.nombre_dept) == 0) {
                                // Calcular salario basado en horas mínimas del empleo
                                float salario_por_horas = empleo_temp.horas_minimas * empleo_temp.salario_por_hora;
                                // Usar el mayor entre salario base y salario por horas
                                if(salario_por_horas > salario_empleado) {
                                    salario_empleado = salario_por_horas;
                                }
                                break;
                            }
                        }
                        fclose(archivo_empleos);
                        
                        salario_total_dept += salario_empleado;
                    }
                }
            }
            fclose(archivo_empleados);
        }
        
        gotoxy(3, linea_actual);
        printf("  Empleados: %-3d", cantidad_empleados);
        printf("          Salario Total Mensual: $%.2f", salario_total_dept);
        linea_actual++;
        
        // Mostrar algunos empleados del departamento (máximo 3)
        gotoxy(3, linea_actual);
        printf("  Empleados: ");
        linea_actual++;
        
        int empleados_mostrados = 0;
        archivo_empleados = fopen("empleados.dat", "rb");
        if(archivo_empleados != NULL) {
            while(fread(&empleado_temp, sizeof(EmpleadoEstructura), 1, archivo_empleados) && empleados_mostrados < 3) {
                if(strcmp(empleado_temp.departamento, dept_temp.nombre_dept) == 0) {
                    gotoxy(5, linea_actual);
                    printf("- %s %s (%s) - $%.2f", 
                           empleado_temp.nombre_empleado, 
                           empleado_temp.apellido_empleado,
                           empleado_temp.puesto,
                           empleado_temp.salario_base);
                    linea_actual++;
                    empleados_mostrados++;
                }
            }
            fclose(archivo_empleados);
            
            if(cantidad_empleados > 3) {
                gotoxy(5, linea_actual);
                printf("... y %d empleados mas", cantidad_empleados - 3);
                linea_actual++;
            }
        }
        
        if(empleados_mostrados == 0) {
            gotoxy(5, linea_actual);
            printf("- No hay empleados registrados en este departamento");
            linea_actual++;
        }
        
        gotoxy(3, linea_actual);
        printf("  ----------------------------------------------------------------------------");
        linea_actual++;
        
        // Espacio entre departamentos
        linea_actual++;
    }
    
    fclose(archivo_dept);
    
    if(contador_dept == 0) {
        gotoxy(3,8);printf("No se encontraron departamentos en el archivo.");
    } else {
        gotoxy(3,22);printf("Total de departamentos mostrados: %d", contador_dept);
    }
    
    gotoxy(3,23);printf("Presione tecla para regresar al menu...");
    getch();
}
void ImprimirEmpleadosGerente(char *departamento_gerente) {
    EmpleadoEstructura empleado_temp;
    HorasTrabajadasEstructura horas_temp;
    EmpleoEstructura empleo_temp;
    FILE *archivo_empleados, *archivo_horas, *archivo_empleos;
    int mes_consulta, anio_consulta;
    int contador = 0;
    int linea_actual = 7;
    int pagina = 1;
    float total_horas_mes, salario_calculado;
    char mes_str[3], anio_str[5];
    int encontrado_empleo;
    
    clrscr();
    MarcoPrincipal();
    
    gotoxy(25,3);printf("Reporte de Empleados por Mes");
    gotoxy(21,5);printf("Departamento: %s", departamento_gerente);

    // Solicitar mes y año
    gotoxy(21,7);printf("Ingrese el mes (1-12): ");
    scanf("%d", &mes_consulta); fflush(stdin);
    while(mes_consulta < 1 || mes_consulta > 12) {
        gotoxy(21,8);printf("Error: Mes debe estar entre 1 y 12. Reingrese: ");
        scanf("%d", &mes_consulta); fflush(stdin);
        for(int clear_col=21; clear_col<78; clear_col++) gotoxy(clear_col,8),printf(" ");
    }
    gotoxy(21,8);printf("Ingrese el año (ej: 2024): ");
    scanf("%d", &anio_consulta); fflush(stdin);
    sprintf(mes_str, "%02d", mes_consulta);
    sprintf(anio_str, "%d", anio_consulta);

    gotoxy(21,9);printf("Mes: %02d/%d", mes_consulta, anio_consulta);
    gotoxy(21,10);printf("========================================================");
    
    // Abrir archivos
    archivo_empleados = fopen("empleados.dat", "rb");
    if(!archivo_empleados) {
        gotoxy(21,12);printf("Error: No se pudo abrir el archivo de empleados.");
        gotoxy(21,22);printf("Presione tecla para continuar..."); getch(); return;
    }
    archivo_horas = fopen("horas_trabajadas.dat", "rb");
    if(!archivo_horas) {
        gotoxy(21,12);printf("Error: No se pudo abrir el archivo de horas trabajadas.");
        fclose(archivo_empleados);
        gotoxy(21,22);printf("Presione tecla para continuar..."); getch(); return;
    }
    archivo_empleos = fopen("empleos.dat", "rb");
    if(!archivo_empleos) {
        gotoxy(21,12);printf("Error: No se pudo abrir el archivo de empleos.");
        fclose(archivo_empleados); fclose(archivo_horas);
        gotoxy(21,22);printf("Presione tecla para continuar..."); getch(); return;
    }

    // Por cada empleado del departamento
    while(fread(&empleado_temp, sizeof(EmpleadoEstructura), 1, archivo_empleados)) {
        if(strcmp(empleado_temp.departamento, departamento_gerente) != 0) continue;
        contador++;
        total_horas_mes = 0.0;
        salario_calculado = 0.0;
        encontrado_empleo = 0;

        // Paginación
        if(linea_actual > 20) {
            gotoxy(21,21);printf("========================================================");
            gotoxy(21,22);printf("Presione tecla para continuar..."); getch();
            clrscr(); MarcoPrincipal();
            pagina++; gotoxy(25,3);printf("Reporte de Empleados por Mes");
            gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
            gotoxy(65,5);printf("(Pag. %d)", pagina);
            gotoxy(21,7);printf("Mes: %02d/%d", mes_consulta, anio_consulta);
            gotoxy(21,8);printf("========================================================");
            linea_actual = 9;
        }
        // Calcular horas trabajadas en el mes específico
        fseek(archivo_horas, 0, SEEK_SET);
        while(fread(&horas_temp, sizeof(HorasTrabajadasEstructura), 1, archivo_horas)) {
            if(horas_temp.id_empleado == empleado_temp.id_empleado) {
                char fecha_mes[3], fecha_anio[5];
                sscanf(horas_temp.fecha_trabajo, "%*d/%2s/%4s", fecha_mes, fecha_anio);
                if(strcmp(fecha_mes, mes_str) == 0 && strcmp(fecha_anio, anio_str) == 0) {
                    total_horas_mes += horas_temp.horas_trabajadas;
                }
            }
        }
        // Buscar información del empleo
        fseek(archivo_empleos, 0, SEEK_SET);
        while(fread(&empleo_temp, sizeof(EmpleoEstructura), 1, archivo_empleos)) {
            if(strcmp(empleo_temp.nombre_empleo, empleado_temp.puesto) == 0 &&
                strcmp(empleo_temp.departamento, empleado_temp.departamento) == 0) {
                encontrado_empleo = 1;
                salario_calculado = total_horas_mes * empleo_temp.salario_por_hora;
                break;
            }
        }
        if(!encontrado_empleo) salario_calculado = empleado_temp.salario_base;

        // Mostrar información
        gotoxy(21, linea_actual); printf("ID: %-4d %-20s %-15s", empleado_temp.id_empleado, empleado_temp.nombre_empleado, empleado_temp.apellido_empleado);
        linea_actual++;
        gotoxy(21, linea_actual); printf("Empleo: %-25s", empleado_temp.puesto);
        linea_actual++;
        gotoxy(21, linea_actual); printf("Horas Mes: %6.2f hrs   Salario: $%8.2f", total_horas_mes, salario_calculado);
        linea_actual++;
        gotoxy(21, linea_actual); printf("--------------------------------------------------------");
        linea_actual++;
        linea_actual++;
    }
    fclose(archivo_empleados); fclose(archivo_horas); fclose(archivo_empleos);
    if(contador == 0) {
        gotoxy(21,12);printf("No se encontraron empleados en su departamento.");
    } else {
        gotoxy(21,22);printf("Total de empleados procesados: %d", contador);
    }
    gotoxy(21,23);printf("Presione tecla para regresar al menu..."); getch();
}

// =============================
// 2. ImprimirMovimientos (SENIOR)
// =============================
void ImprimirMovimientos(){
    MovimientoFinanciero movimiento_temp;
    FILE *archivo;
    int contador = 0;
    int linea_actual = 6;
    int pagina = 1;
    
    clrscr();
    MarcoImpresiones();
    gotoxy(30,3);printf("Listado de Movimientos Financieros");

    archivo = fopen("movimientos.dat", "rb");
    if(archivo == NULL) {
        gotoxy(3,8);printf("Error: No se pudo abrir el archivo de movimientos.");
        gotoxy(3,22);printf("Presione tecla para continuar..."); getch(); return;
    }
    fseek(archivo, 0, SEEK_END);
    if(ftell(archivo) == 0) {
        fclose(archivo);
        gotoxy(3,8);printf("No hay movimientos registrados.");
        gotoxy(3,22);printf("Presione tecla para continuar..."); getch(); return;
    }
    fseek(archivo, 0, SEEK_SET);

    gotoxy(3,5);printf("Pagina %d", pagina);
    gotoxy(3,6);printf("============================================================================");
    while(fread(&movimiento_temp, sizeof(MovimientoFinanciero), 1, archivo)) {
        contador++;
        if(linea_actual > 20) {
            gotoxy(3,21);printf("============================================================================");
            gotoxy(3,22);printf("Presione tecla para continuar..."); getch();
            clrscr(); MarcoImpresiones();
            pagina++; gotoxy(30,3);printf("Listado de Movimientos Financieros");
            gotoxy(3,5);printf("Pagina %d", pagina);
            gotoxy(3,6);printf("============================================================================");
            linea_actual = 7;
        }
        gotoxy(3, linea_actual);
        printf("Movimiento #%d: %s (%s)", contador, movimiento_temp.concepto, movimiento_temp.tipo_movimiento);
        linea_actual++;
        gotoxy(3, linea_actual);
        printf("  Cantidad: $%.2f      Fecha: %s", movimiento_temp.cantidad, movimiento_temp.fecha_movimiento);
        linea_actual++;
        gotoxy(3, linea_actual);
        printf("  Factura: %d          Depto: %s", movimiento_temp.numero_factura, movimiento_temp.departamento);
        linea_actual++;
        gotoxy(3, linea_actual);
        printf("----------------------------------------------------------------------------");
        linea_actual++;
        linea_actual++;
    }
    fclose(archivo);
    if(contador == 0) {
        gotoxy(3,8);printf("No se encontraron movimientos en el archivo.");
    } else {
        gotoxy(3,22);printf("Total de movimientos mostrados: %d", contador);
    }
    gotoxy(3,23);printf("Presione tecla para regresar al menu..."); getch();
}

// =============================
// 3. ImprimirMovimientosGerente
// =============================
void ImprimirMovimientosGerente(char *departamento_gerente){
    MovimientoFinanciero movimiento_temp;
    FILE *archivo;
    int contador = 0;
    int linea_actual = 7;
    int pagina = 1;

    clrscr();
    MarcoPrincipal();
    gotoxy(25,3);printf("Movimientos del Departamento");
    gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
    gotoxy(21,6);printf("========================================================");

    archivo = fopen("movimientos.dat", "rb");
    if(archivo == NULL) {
        gotoxy(21,8);printf("Error: No se pudo abrir el archivo de movimientos.");
        gotoxy(21,22);printf("Presione tecla para continuar..."); getch(); return;
    }
    fseek(archivo, 0, SEEK_END);
    if(ftell(archivo) == 0) {
        fclose(archivo);
        gotoxy(21,8);printf("No hay movimientos registrados.");
        gotoxy(21,22);printf("Presione tecla para continuar..."); getch(); return;
    }
    fseek(archivo, 0, SEEK_SET);

    while(fread(&movimiento_temp, sizeof(MovimientoFinanciero), 1, archivo)) {
        // Solo movimientos del departamento
        if(strcmp(movimiento_temp.departamento, departamento_gerente) == 0) {
            contador++;
            if(linea_actual > 20) {
                gotoxy(21,21);printf("========================================================");
                gotoxy(21,22);printf("Presione tecla para continuar..."); getch();
                clrscr(); MarcoPrincipal();
                pagina++; gotoxy(25,3);printf("Movimientos del Departamento");
                gotoxy(21,5);printf("Departamento: %s", departamento_gerente);
                gotoxy(65,5);printf("(Pag. %d)", pagina);
                gotoxy(21,6);printf("========================================================");
                linea_actual = 7;
            }
            gotoxy(21, linea_actual);
            printf("Movimiento #%d: %s (%s)", contador, movimiento_temp.concepto, movimiento_temp.tipo_movimiento);
            linea_actual++;
            gotoxy(21, linea_actual);
            printf("  Cantidad: $%.2f      Fecha: %s", movimiento_temp.cantidad, movimiento_temp.fecha_movimiento);
            linea_actual++;
            gotoxy(21, linea_actual);
            printf("  Factura: %d", movimiento_temp.numero_factura);
            linea_actual++;
            gotoxy(21, linea_actual);
            printf("--------------------------------------------------------");
            linea_actual++;
            linea_actual++;
        }
    }
    fclose(archivo);
    if(contador == 0) {
        gotoxy(21,8);printf("No se encontraron movimientos en su departamento.");
    } else {
        gotoxy(21,22);printf("Total de movimientos procesados: %d", contador);
    }
    gotoxy(21,23);printf("Presione tecla para regresar al menu..."); getch();
}

// =============================
// 4. ImprimirSalarios (placeholder)
// =============================
void ImprimirSalarios() {
    clrscr();
    MarcoImpresiones();
    gotoxy(30,10);printf("Modulo de impresion de salarios en desarrollo");
    gotoxy(30,12);printf("Presione tecla para regresar al menu...");
    getch();
}
