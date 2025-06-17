#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>

// Estructuras de datos
FILE* misropa;
struct ropa {
    int numero;
    char tipo[30];
    char talla[5];    
    char marca[30];   
    int cantidad;
    float precio;
} ropaarial;

FILE* misclientesVIP;
struct clientesVIP {
    int numero;
    char nombre[30];
    char direccion[50];
    char telefono[15]; 
    int puntos;       
} clientesVIParial;

FILE* misventas;
struct ventas {
    int numero;
    char concepto[30];
    char cliente[30];
    char articulo[30];
    char talla[5];    
    int cantidad;
    float total;
} ventasarial;

FILE* miscompras;
struct compras {      
    int numero;
    char proveedor[30];
    char articulo[30];
    char talla[5];
    int cantidad;
    float precio_unitario;
    float total;
} comprasarial;

// Variables globales
const int COLOR_ROPA = 14;      // Yellow (Amarillo)
const int COLOR_CLIENTES = 14;  // Yellow (Amarillo)
const int COLOR_VENTAS = 14;    // Yellow (Amarillo)
const int COLOR_COMPRAS = 14;   // Yellow (Amarillo)
const int COLOR_BASE = 0;       // Black (Negro
int acceso;
int intentos;

// Prototipos de funciones
void dibujarMarcoLogin();
void dibujarMarcoMenu();
void dibujarMarcoTitulo(const char* titulo);
void login();
void menu_principal();
void registrar_ropa();
void registrar_clientesVIP();
void registrar_ventas();
void registrar_compras();
void imprimir_ropa();
void imprimir_clientesVIP();
void imprimir_ventas();
void imprimir_compras();
void validar_texto(char *texto);
void convertir_mayusculas(char *cadena);
void mostrar_creditos();
void dibujarMarcoCompras();

// Función principal
int main() {
    textbackground(COLOR_BASE);
    textcolor(COLOR_ROPA);
    clrscr();
    login();
    return 0;
}



void login() {
    struct {
        char usuario[20];
        char clave[20];
    } user_input;
    int intentos = 0;
    int acceso = 0;
    char temp[20];
    
    while(intentos < 3 && acceso == 0) {
        clrscr();
        textbackground(COLOR_BASE);
        textcolor(COLOR_ROPA);
        dibujarMarcoTitulo("Sistema de Ropa");
        dibujarMarcoLogin();
        
        do {
            gotoxy(30, 12);
            printf("Usuario: ");
            gotoxy(38, 12);
            printf("                     ");
            gotoxy(38, 12);
            fflush(stdin);
            gets(temp);
            strcpy(user_input.usuario, temp);
            convertir_mayusculas(user_input.usuario);
        } while(strlen(user_input.usuario) == 0);
        
        do {
            gotoxy(30, 14);
            printf("Clave:   ");
            gotoxy(38, 14);
            printf("                     ");
            gotoxy(38, 14);
            fflush(stdin);
            textcolor(COLOR_ROPA);
            gets(temp);
            strcpy(user_input.clave, temp);
        } while(strlen(user_input.clave) == 0);
        
        textcolor(COLOR_BASE);
        if(strcmp(user_input.usuario, "ROPA") == 0 && 
           strcmp(user_input.clave, "123") == 0) {
            acceso = 1;
            gotoxy(32, 17);
            printf("Acceso concedido");
            Sleep(1000);
            menu_principal();
        } else {
            intentos++;
            gotoxy(27, 17);
            printf("                                        ");
            gotoxy(27, 17);
            printf("Datos incorrectos. Intento %i/3", intentos);
            getch();
        }
    }
    
    if(acceso == 0) {
        gotoxy(27, 17);
        printf("Sistema bloqueado. Contacte al admin");
        getch();
    }
}

void menu_principal() {
    int opcion;
    
    do {
        clrscr();
        textbackground(COLOR_BASE);
        textcolor(COLOR_ROPA);
        dibujarMarcoTitulo("Sistema de Ropa");
        dibujarMarcoMenu();
        
        gotoxy(15, 9); printf("1. Registrar Ropa");
        gotoxy(45, 9); printf("5. Imprimir Ropa");
        gotoxy(15, 11);printf("2. Registrar Clientes VIP");
        gotoxy(45, 11);printf("6. Imprimir Clientes VIP");
        gotoxy(15, 13);printf("3. Registrar Ventas");
        gotoxy(45, 13);printf("7. Imprimir Ventas");
        gotoxy(15, 15);printf("4. Registrar Compras");
        gotoxy(45, 15);printf("8. Imprimir Compras");
        gotoxy(30, 17);printf("0. Salir");
        
        gotoxy(20, 20);
        printf("Seleccione una opcion (0-8): ");
        gotoxy(48, 20);
        printf("                               ");
        gotoxy(48, 20);
        scanf("%i", &opcion);
        
        switch(opcion) {
            case 1: registrar_ropa(); break;
            case 2: registrar_clientesVIP(); break;
            case 3: registrar_ventas(); break;
            case 4: registrar_compras(); break;
            case 5: imprimir_ropa(); break;
            case 6: imprimir_clientesVIP(); break;
            case 7: imprimir_ventas(); break;
            case 8: imprimir_compras(); break;
            case 0:
                gotoxy(20, 21);
                printf("Hasta pronto");
                getch();
                break;
            default:
                gotoxy(20, 21);
                printf("Opcion invalida");
                getch();
        }
    } while(opcion != 0);
}


void registrar_ropa() {
    char continuar;
    
    do {
        clrscr();
        textbackground(COLOR_ROPA);
        textcolor(COLOR_BASE);
        dibujarMarcoTitulo("Sistema de Ropa");
        dibujarMarcoMenu();
        
        gotoxy(25, 8);
        printf("REGISTRO DE ROPA");
        
        misropa = fopen("ropa.dat", "ab");
        if(misropa == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(15, 10);
        printf("Numero: ");
        gotoxy(30, 10);
        printf("                               ");
        gotoxy(30, 10);
        scanf("%i", &ropaarial.numero);
        
        gotoxy(15, 11);
        printf("Tipo: ");
        fflush(stdin);
        gets(ropaarial.tipo);
        convertir_mayusculas(ropaarial.tipo);
        
        gotoxy(15, 12);
        printf("Marca: ");
        fflush(stdin);
        gets(ropaarial.marca);
        convertir_mayusculas(ropaarial.marca);
        
        gotoxy(15, 13);
        printf("Talla: ");
        fflush(stdin);
        gets(ropaarial.talla);
        convertir_mayusculas(ropaarial.talla);
        
        gotoxy(15, 14);
        printf("Cantidad: ");
        gotoxy(25, 14);
        printf("                               ");
        gotoxy(25, 14);
        scanf("%i", &ropaarial.cantidad);
        
        gotoxy(15, 15);
        printf("Precio: $");
        gotoxy(24, 15);
        printf("                               ");
        gotoxy(24, 15);
        scanf("%f", &ropaarial.precio);
        
        fwrite(&ropaarial, sizeof(ropaarial), 1, misropa);
        fclose(misropa);
        
        gotoxy(15, 17);
        printf("Ropa registrada exitosamente");
        gotoxy(15, 18);
        printf("Cantidad en inventario: %i", ropaarial.cantidad);
        gotoxy(15, 19);
        printf("Desea registrar otra prenda (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void registrar_clientesVIP() {
    char continuar;
    
    do {
        clrscr();
        textbackground(COLOR_CLIENTES);
        textcolor(COLOR_BASE);
        dibujarMarcoTitulo("Sistema de Ropa");
        dibujarMarcoMenu();
        
        gotoxy(25, 8);
        printf("REGISTRO DE CLIENTES VIP");
        
        misclientesVIP = fopen("clientesVIP.dat", "ab");
        if(misclientesVIP == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(15, 10);
        printf("Numero: ");
        gotoxy(30, 10);
        printf("                               ");
        gotoxy(30, 10);
        scanf("%i", &clientesVIParial.numero);
        
        gotoxy(15, 11);
        printf("Nombre: ");
        fflush(stdin);
        gets(clientesVIParial.nombre);
        convertir_mayusculas(clientesVIParial.nombre);
        
        gotoxy(15, 12);
        printf("Direccion: ");
        fflush(stdin);
        gets(clientesVIParial.direccion);
        convertir_mayusculas(clientesVIParial.direccion);
        
        gotoxy(15, 13);
        printf("Telefono: ");
        fflush(stdin);
        gets(clientesVIParial.telefono);
        
        gotoxy(15, 14);
        printf("Puntos iniciales: ");
        gotoxy(32, 14);
        printf("                               ");
        gotoxy(32, 14);
        scanf("%i", &clientesVIParial.puntos);
        
        fwrite(&clientesVIParial, sizeof(clientesVIParial), 1, misclientesVIP);
        fclose(misclientesVIP);
        
        gotoxy(15, 16);
        printf("Cliente VIP registrado exitosamente");
        gotoxy(15, 17);
        printf("Desea registrar otro cliente (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void registrar_ventas() {
    char continuar;
    float precio_unitario;
    int encontrado;
    int numero_ropa;
    struct ropa ropa_temp;
    
    do {
        clrscr();
        textbackground(COLOR_VENTAS);
        textcolor(COLOR_BASE);
        dibujarMarcoTitulo("Sistema de Ropa");
        dibujarMarcoMenu();
        
        gotoxy(25, 8);
        printf("REGISTRO DE VENTAS");
        
        misventas = fopen("ventas.dat", "ab");
        if(misventas == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(15, 10);
        printf("Numero de venta: ");
        gotoxy(31, 10);
        printf("                               ");
        gotoxy(31, 10);
        scanf("%i", &ventasarial.numero);
        
        gotoxy(15, 11);
        printf("Concepto: ");
        fflush(stdin);
        gets(ventasarial.concepto);
        convertir_mayusculas(ventasarial.concepto);
        
        gotoxy(15, 12);
        printf("Cliente: ");
        fflush(stdin);
        gets(ventasarial.cliente);
        convertir_mayusculas(ventasarial.cliente);
        
        gotoxy(15, 13);
        printf("Numero de prenda: ");
        gotoxy(32, 13);
        printf("                               ");
        gotoxy(32, 13);
        scanf("%i", &numero_ropa);
        
        // Buscar prenda y verificar inventario
        encontrado = 0;
        precio_unitario = 0;
        misropa = fopen("ropa.dat", "rb+");
        if(misropa != NULL) {
            while(fread(&ropa_temp, sizeof(ropa_temp), 1, misropa)) {
                if(ropa_temp.numero == numero_ropa) {
                    precio_unitario = ropa_temp.precio;
                    strcpy(ventasarial.articulo, ropa_temp.tipo);
                    strcpy(ventasarial.talla, ropa_temp.talla);
                    encontrado = 1;
                    
                    gotoxy(15, 14);
                    printf("Tipo de prenda: %s", ventasarial.articulo);
                    gotoxy(15, 15);
                    printf("Talla: %s", ventasarial.talla);
                    gotoxy(15, 16);
                    printf("Disponible: %d", ropa_temp.cantidad);
                    
                    gotoxy(15, 17);
                    printf("Cantidad a vender: ");
                    gotoxy(32, 17);
                    printf("                               ");
                    gotoxy(32, 17);
                    scanf("%i", &ventasarial.cantidad);
                    
                    if(ventasarial.cantidad <= ropa_temp.cantidad) {
                        ventasarial.total = ventasarial.cantidad * precio_unitario;
                        
                        // Actualizar inventario
                        ropa_temp.cantidad -= ventasarial.cantidad;
                        fseek(misropa, -sizeof(ropa_temp), SEEK_CUR);
                        fwrite(&ropa_temp, sizeof(ropa_temp), 1, misropa);
                        
                        fwrite(&ventasarial, sizeof(ventasarial), 1, misventas);
                        
                        gotoxy(15, 18);
                        printf("Precio unitario: $%8.2f", precio_unitario);
                        gotoxy(15, 19);
                        printf("Total: $%8.2f", ventasarial.total);
                    } else {
                        gotoxy(15, 19);
                        printf("Error: No hay suficiente inventario");
                        getch();
                    }
                    break;
                }
            }
            fclose(misropa);
        }
        
        fclose(misventas);
        
        if(!encontrado) {
            gotoxy(15, 15);
            printf("Error: Prenda no encontrada");
            getch();
            continue;
        }
        
        gotoxy(15, 21);
        printf("Desea registrar otra venta (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void registrar_compras() {
    char continuar;
    struct ropa ropa_temp;
    int encontrado;
    int numero_articulo;
    
    do {
        clrscr();
        textbackground(COLOR_BASE);
        textcolor(COLOR_COMPRAS);
        dibujarMarcoTitulo("Sistema de Ropa");
        dibujarMarcoCompras();
        
        gotoxy(25, 8);
        printf("REGISTRO DE COMPRAS");
        
        miscompras = fopen("compras.dat", "ab");
        if(miscompras == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo de compras");
            getch();
            return;
        }

        // Primero buscar si existe el artículo
        gotoxy(15, 10);
        printf("Numero de articulo: ");
        gotoxy(33, 10);
        printf("                               ");
        gotoxy(33, 10);
        scanf("%d", &numero_articulo);

        // Buscar el artículo en el archivo de ropa
        encontrado = 0;
        misropa = fopen("ropa.dat", "rb+");
        if(misropa != NULL) {
            while(fread(&ropa_temp, sizeof(ropa_temp), 1, misropa)) {
                if(ropa_temp.numero == numero_articulo) {
                    encontrado = 1;
                    
                    // Mostrar información del artículo encontrado
                    gotoxy(15, 11);
                    printf("Articulo encontrado:");
                    gotoxy(15, 12);
                    printf("Tipo: %s", ropa_temp.tipo);
                    gotoxy(15, 13);
                    printf("Marca: %s", ropa_temp.marca);
                    gotoxy(15, 14);
                    printf("Talla: %s", ropa_temp.talla);
                    gotoxy(15, 15);
                    printf("Cantidad actual: %d", ropa_temp.cantidad);
                    
                    // Registrar la compra
                    comprasarial.numero = numero_articulo;
                    strcpy(comprasarial.articulo, ropa_temp.tipo);
                    strcpy(comprasarial.talla, ropa_temp.talla);
                    
                    gotoxy(15, 16);
                    printf("Proveedor: ");
                    fflush(stdin);
                    gets(comprasarial.proveedor);
                    convertir_mayusculas(comprasarial.proveedor);
                    
                    gotoxy(15, 17);
                    printf("Cantidad a comprar: ");
                    gotoxy(33, 17);
                    printf("                               ");
                    gotoxy(33, 17);
                    scanf("%d", &comprasarial.cantidad);
                    
                    gotoxy(15, 18);
                    printf("Precio unitario: $");
                    gotoxy(31, 18);
                    printf("                               ");
                    gotoxy(31, 18);
                    scanf("%f", &comprasarial.precio_unitario);
                    
                    comprasarial.total = comprasarial.cantidad * comprasarial.precio_unitario;
                    
                    // Actualizar cantidad en inventario
                    ropa_temp.cantidad += comprasarial.cantidad;
                    fseek(misropa, -sizeof(ropa_temp), SEEK_CUR);
                    fwrite(&ropa_temp, sizeof(ropa_temp), 1, misropa);
                    
                    // Guardar la compra
                    fwrite(&comprasarial, sizeof(comprasarial), 1, miscompras);
                    
                    gotoxy(15, 20);
                    printf("Total de compra: $%.2f", comprasarial.total);
                    gotoxy(15, 21);
                    printf("Nueva cantidad en inventario: %d", ropa_temp.cantidad);
                    break;
                }
            }
            fclose(misropa);
        }
        
        if(!encontrado) {
            gotoxy(15, 12);
            printf("Articulo no encontrado. Debe registrarlo primero en");
            gotoxy(15, 13);
            printf("el menu de Registrar Ropa (opcion 1).");
            gotoxy(15, 14);
            printf("Presione una tecla para continuar...");
            getch();
        }
        
        fclose(miscompras);
        
        gotoxy(15, 22);
        printf("Desea registrar otra compra (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
    
    // Mostrar información del sistema al final
    gotoxy(5, 24);
    printf("Usuario: %s  -  Fecha: %s  -  Hora: %s UTC", 
           "German08052", "2025-06-13", "17:39:41");
}

void validar_texto(char *texto) {
    int i;
    char temp[50];
    
    strcpy(temp, texto);
    for(i = 0; temp[i]; i++) {
        if(temp[i] >= '0' && temp[i] <= '9') {
            gotoxy(15, 20);
            printf("Error: No se permiten numeros en este campo");
            gotoxy(15, 21);
            printf("Presione una tecla para continuar");
            getch();
            gotoxy(15, 20);
            printf("                                           ");
            gotoxy(15, 21);
            printf("                                           ");
            fflush(stdin);
            gets(texto);
            strcpy(temp, texto);
            i = -1;
        }
    }
}

void convertir_mayusculas(char *cadena) {
    int i;
    for(i = 0; cadena[i]; i++) {
        if(cadena[i] >= 'a' && cadena[i] <= 'z') {
            cadena[i] = cadena[i] - 32;
        }
    }
}

// Caracteres ASCII para marcos (Turbo C)
// + = 218  + = 192  + = 191  + = 217
// - = 196  ¦ = 179  + = 201  + = 187
// + = 200  + = 188  - = 205  ¦ = 186
// ¦ = 204  ¦ = 185  - = 203  - = 202

void dibujarMarcoLogin() {
    int i;
    
    // Marco estilo ondulado para login
    gotoxy(25, 8);
    printf("%c", 176);  // ¦
    for(i = 26; i <= 54; i++) {
        gotoxy(i, 8);
        printf("%c", 205);  // -
    }
    gotoxy(55, 8);
    printf("%c", 176);  // ¦
    
    for(i = 9; i <= 15; i++) {
        gotoxy(25, i);
        printf("%c", 177);  // ¦
        gotoxy(55, i);
        printf("%c", 177);  // ¦
    }
    
    gotoxy(25, 16);
    printf("%c", 176);  // ¦
    for(i = 26; i <= 54; i++) {
        gotoxy(i, 16);
        printf("%c", 205);  // -
    }
    gotoxy(55, 16);
    printf("%c", 176);  // ¦
    
    // Decoración adicional
    gotoxy(35, 9);
    printf("* BIENVENIDO *");
    gotoxy(32, 10);
    printf("%c%c%c%c%c%c%c%c%c%c%c", 196,196,196,196,196,196,196,196,196,196,196);
}

void dibujarMarcoTitulo(const char* titulo) {
    int i;
    int longitud = strlen(titulo);
    int inicio = 40 - (longitud / 2);
    
    // Marco estilo estrellado para título
    for(i = inicio - 3; i <= inicio + longitud + 2; i++) {
        gotoxy(i, 1);
        printf("%c", 42);  // *
    }
    
    gotoxy(inicio - 3, 2);
    printf("* %s *", titulo);
    
    for(i = inicio - 3; i <= inicio + longitud + 2; i++) {
        gotoxy(i, 3);
        printf("%c", 42);  // *
    }
}

void dibujarMarcoMenu() {
    int i, j;
    
    // Marco exterior con diseño de bloques
    for(i = 3; i <= 23; i++) {
        gotoxy(2, i);
        printf("%c", 178);  // ¦
        gotoxy(78, i);
        printf("%c", 178);  // ¦
    }
    
    for(i = 2; i <= 78; i++) {
        gotoxy(i, 3);
        printf("%c", 178);  // ¦
        gotoxy(i, 23);
        printf("%c", 178);  // ¦
    }
    
    // División del menú en cuatro secciones
    gotoxy(40, 6);
    printf("%c", 194);  // -
    for(i = 7; i <= 19; i++) {
        gotoxy(40, i);
        printf("%c", 179);  // ¦
    }
    gotoxy(40, 20);
    printf("%c", 193);  // -
}

void dibujarMarcoRopa() {
    int i;
    
    gotoxy(10, 7);
    printf("%c", 201);  // +
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 7);
        printf("%c", 205);  // -
    }
    gotoxy(70, 7);
    printf("%c", 187);  // +
    
    for(i = 8; i <= 18; i++) {
        gotoxy(10, i);
        printf("%c", 186);  // ¦
        gotoxy(70, i);
        printf("%c", 186);  // ¦
    }
    
    gotoxy(10, 19);
    printf("%c", 200);  // +
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 19);
        printf("%c", 205);  // -
    }
    gotoxy(70, 19);
    printf("%c", 188);  // +
}

void dibujarMarcoClientesVIP() {
    int i;
    
    gotoxy(10, 7);
    printf("%c", 213);  // -
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 7);
        printf("%c", 205);  // -
    }
    gotoxy(70, 7);
    printf("%c", 184);  // ¦
    
    for(i = 8; i <= 18; i++) {
        gotoxy(10, i);
        printf("%c", 179);  // ¦
        gotoxy(70, i);
        printf("%c", 179);  // ¦
    }
    
    gotoxy(10, 19);
    printf("%c", 212);  // -
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 19);
        printf("%c", 205);  // -
    }
    gotoxy(70, 19);
    printf("%c", 189);  // +
}

void dibujarMarcoVentas() {
    int i;
    
    gotoxy(10, 7);
    printf("%c", 214);  // +
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 7);
        printf("%c", 196);  // -
    }
    gotoxy(70, 7);
    printf("%c", 183);  // +
    
    for(i = 8; i <= 18; i++) {
        gotoxy(10, i);
        printf("%c", 186);  // ¦
        gotoxy(70, i);
        printf("%c", 186);  // ¦
    }
    
    gotoxy(10, 19);
    printf("%c", 211);  // +
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 19);
        printf("%c", 196);  // -
    }
    gotoxy(70, 19);
    printf("%c", 189);  // +
}

void dibujarMarcoCompras() {
    int i;
    
    gotoxy(10, 7);
    printf("%c", 201);  // +
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 7);
        printf("%c", 205);  // -
    }
    gotoxy(70, 7);
    printf("%c", 187);  // +
    
    for(i = 8; i <= 18; i++) {
        gotoxy(10, i);
        printf("%c", 186);  // ¦
        gotoxy(70, i);
        printf("%c", 186);  // ¦
        
        // Decoración adicional para el marco de compras
        if(i % 3 == 0) {
            gotoxy(9, i);
            printf("%c", 174);  // «
            gotoxy(71, i);
            printf("%c", 175);  // »
        }
    }
    
    gotoxy(10, 19);
    printf("%c", 200);  // +
    for(i = 11; i <= 69; i++) {
        gotoxy(i, 19);
        printf("%c", 205);  // -
    }
    gotoxy(70, 19);
    printf("%c", 188);  // +
}

void imprimir_ropa() {
    int linea;
    float total_inventario = 0;
    
    clrscr();
    textbackground(COLOR_ROPA);
    textcolor(COLOR_BASE);
    dibujarMarcoTitulo("Sistema de Ropa");
    dibujarMarcoMenu();
    
    gotoxy(25, 8);
    printf("LISTADO DE INVENTARIO DE ROPA");
    gotoxy(8, 10);
    printf("Num   Tipo                Marca               Talla    Cant    Precio");
    
    misropa = fopen("ropa.dat", "rb");
    if(misropa == NULL) {
        gotoxy(20, 12);
        printf("No hay prendas registradas");
        getch();
        return;
    }
    
    linea = 11;
    while(fread(&ropaarial, sizeof(ropaarial), 1, misropa)) {
        gotoxy(8, linea);
        printf("%-5d %-19s %-19s %-8s %-7d $%8.2f", 
               ropaarial.numero, 
               ropaarial.tipo,
               ropaarial.marca,
               ropaarial.talla,
               ropaarial.cantidad,
               ropaarial.precio);
        
        total_inventario += ropaarial.cantidad * ropaarial.precio;
        linea++;
        
        if(linea > 18) { // Control de paginación
            gotoxy(8, 20);
            getch();
            gotoxy(8, 11);
            for(int i = 11; i <= 18; i++) {
                gotoxy(8, i);
                printf("                                                                  ");
            }
            linea = 11;
        }
    }
    
    fclose(misropa);
    gotoxy(8, linea + 1);
    printf("Total Inventario: $%8.2f", total_inventario);
    gotoxy(8, linea + 2);
    getch();
}

void imprimir_clientesVIP() {
    int linea;
    
    clrscr();
    textbackground(COLOR_CLIENTES);
    textcolor(COLOR_BASE);
    dibujarMarcoTitulo("Sistema de Ropa");
    dibujarMarcoMenu();
    
    gotoxy(25, 8);
    printf("LISTADO DE CLIENTES VIP");
    gotoxy(8, 10);
    printf("Num   Nombre              Direccion                    Telefono      Puntos");
    
    misclientesVIP = fopen("clientesVIP.dat", "rb");
    if(misclientesVIP == NULL) {
        gotoxy(20, 12);
        printf("No hay clientes VIP registrados");
        getch();
        return;
    }
    
    linea = 11;
    while(fread(&clientesVIParial, sizeof(clientesVIParial), 1, misclientesVIP)) {
        gotoxy(8, linea);
        printf("%-5d %-19s %-27s %-12s %5d", 
               clientesVIParial.numero,
               clientesVIParial.nombre,
               clientesVIParial.direccion,
               clientesVIParial.telefono,
               clientesVIParial.puntos);
        linea++;
        
        if(linea > 18) { // Control de paginación
            gotoxy(8, 20);
            getch();
            gotoxy(8, 11);
            for(int i = 11; i <= 18; i++) {
                gotoxy(8, i);
                printf("                                                                  ");
            }
            linea = 11;
        }
    }
    
    fclose(misclientesVIP);
    gotoxy(8, linea + 1);
    getch();
}

void imprimir_ventas() {
    int linea;
    float total_ventas = 0;
    
    clrscr();
    textbackground(COLOR_VENTAS);
    textcolor(COLOR_BASE);
    dibujarMarcoTitulo("Sistema de Ropa");
    dibujarMarcoMenu();
    
    gotoxy(25, 8);
    printf("LISTADO DE VENTAS");
    gotoxy(8, 10);
    printf("Num   Concepto    Cliente     Articulo    Talla   Cant   Total");
    
    misventas = fopen("ventas.dat", "rb");
    if(misventas == NULL) {
        gotoxy(20, 12);
        printf("No hay ventas registradas");
        getch();
        return;
    }
    
    linea = 11;
    while(fread(&ventasarial, sizeof(ventasarial), 1, misventas)) {
        gotoxy(8, linea);
        printf("%-5d %-11s %-11s %-11s %-7s %-6d $%8.2f", 
               ventasarial.numero,
               ventasarial.concepto,
               ventasarial.cliente,
               ventasarial.articulo,
               ventasarial.talla,
               ventasarial.cantidad,
               ventasarial.total);
               
        total_ventas += ventasarial.total;
        linea++;
        
        if(linea > 18) { // Control de paginación
            gotoxy(8, 20);
            getch();
            gotoxy(8, 11);
            for(int i = 11; i <= 18; i++) {
                gotoxy(8, i);
                printf("                                                                  ");
            }
            linea = 11;
        }
    }
    
    fclose(misventas);
    gotoxy(8, linea + 1);
    printf("Total General de Ventas: $%8.2f", total_ventas);
    gotoxy(8, linea + 2);
    getch();
}

void imprimir_compras() {
    int linea;
    float total_compras = 0;
    
    clrscr();
    textbackground(COLOR_COMPRAS);
    textcolor(COLOR_BASE);
    dibujarMarcoTitulo("Sistema de Ropa");
    dibujarMarcoMenu();
    
    gotoxy(25, 8);
    printf("LISTADO DE COMPRAS");
    gotoxy(8, 10);
    printf("Num   Proveedor   Articulo    Talla   Cant   P.Unit    Total");
    
    miscompras = fopen("compras.dat", "rb");
    if(miscompras == NULL) {
        gotoxy(20, 12);
        printf("No hay compras registradas");
        getch();
        return;
    }
    
    linea = 11;
    while(fread(&comprasarial, sizeof(comprasarial), 1, miscompras)) {
        gotoxy(8, linea);
        printf("%-5d %-11s %-11s %-7s %-6d $%8.2f $%8.2f", 
               comprasarial.numero,
               comprasarial.proveedor,
               comprasarial.articulo,
               comprasarial.talla,
               comprasarial.cantidad,
               comprasarial.precio_unitario,
               comprasarial.total);
               
        total_compras += comprasarial.total;
        linea++;
        
        if(linea > 18) { // Control de paginación
            gotoxy(8, 20);
            getch();
            gotoxy(8, 11);
            for(int i = 11; i <= 18; i++) {
                gotoxy(8, i);
                printf("                                                                  ");
            }
            linea = 11;
        }
    }
    
    fclose(miscompras);
    gotoxy(8, linea + 1);
    printf("Total General de Compras: $%8.2f", total_compras);
    gotoxy(8, linea + 2);
    getch();
}







