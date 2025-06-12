#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>

// Estructuras de datos
FILE* deportesProductos;
struct productos {
    int codigo;
    char descripcion[30];
    int stock;
    float precio;
} productoDeporte;

FILE* deportesVentas;
struct ventas {
    int codigo;
    char fecha[11];
    int codProducto;
    int cantidad;
    float precio;
    float total;
} ventaDeporte;

FILE* deportesCompras;
struct compras {
    int codigo;
    char fecha[11];
    int codProducto;
    int cantidad;
    float precioProveedor;
    float total;
} compraDeporte;

FILE* deportesClientes;
struct clientes {
    int codigo;
    char nombre[30];
    char fechaRegistro[11];
} clienteDeporte;

// Prototipos de funciones
void dibujarLogo();
void dibujarMarco();
void iniciarSesion();
void menuPrincipal();
int buscarProducto(int codigo);
void registrarProducto();
void registrarVenta();
void registrarCompra();
void registrarCliente();
void mostrarProductos();
void mostrarVentas();
void mostrarCompras();
void mostrarClientes();
void convertirMayusculas(char *texto);
int validarNumero();
void mostrarCreditos();
void actualizarStock(int codigo, int cantidad, char tipo);

int main() {
    system("color 0E");
    clrscr();
    iniciarSesion();
    return 0;
}

void dibujarMarco() {
    int i;
    
    // Marco exterior doble
    gotoxy(3, 2);
    printf("%c", 201);
    for(i = 4; i <= 76; i++) {
        gotoxy(i, 2);
        printf("%c", 205);
    }
    gotoxy(77, 2);
    printf("%c", 187);
    
    // Marco interior
    gotoxy(5, 4);
    printf("%c", 218);
    for(i = 6; i <= 74; i++) {
        gotoxy(i, 4);
        printf("%c", 196);
    }
    gotoxy(75, 4);
    printf("%c", 191);
    
    // Laterales exteriores
    for(i = 3; i <= 22; i++) {
        gotoxy(3, i);
        printf("%c", 186);
        gotoxy(77, i);
        printf("%c", 186);
    }
    
    // Laterales interiores
    for(i = 5; i <= 21; i++) {
        gotoxy(5, i);
        printf("%c", 179);
        gotoxy(75, i);
        printf("%c", 179);
    }
    
    // Marco inferior
    gotoxy(5, 21);
    printf("%c", 192);
    for(i = 6; i <= 74; i++) {
        gotoxy(i, 21);
        printf("%c", 196);
    }
    gotoxy(75, 21);
    printf("%c", 217);
    
    gotoxy(3, 22);
    printf("%c", 200);
    for(i = 4; i <= 76; i++) {
        gotoxy(i, 22);
        printf("%c", 205);
    }
    gotoxy(77, 22);
    printf("%c", 188);
    
    gotoxy(25, 3);
    printf("DEPORTES OLYMPUS - Sistema de Gestion");
}


void iniciarSesion() {
    char usuario[20], clave[20];
    int intentos = 0, acceso = 0;
    
    // Credenciales del sistema
    const char USUARIO_SISTEMA[] = "Jose Angel";
    
    while(intentos < 3 && !acceso) {
        clrscr();
        system("color 0B");
        dibujarMarco();
        
        gotoxy(25, 10);
        printf("ACCESO AL SISTEMA DEPORTIVO");
        gotoxy(20, 12);
        printf("Usuario: ");
        gotoxy(20, 13);
        printf("Clave: ");
        
        gotoxy(29, 12);
        gets(usuario);
        convertirMayusculas(usuario);
        
        gotoxy(28, 13);
        gets(clave);
        
        // Verificar credenciales simplificada
        if(strcmp(usuario, "JOSE") == 0 && strcmp(clave, "1122") == 0) {
            acceso = 1;
        }
        
        if(acceso) {
            system("color 0A");
            gotoxy(25, 16);
            printf("Bienvenido al Sistema!");
            gotoxy(20, 18);
            printf("Usuario: %s", USUARIO_SISTEMA);
            getch();
            menuPrincipal();
        } else {
            system("color 0C");
            intentos++;
            gotoxy(20, 16);
            printf("Acceso denegado. Intento %d/3", intentos);
            gotoxy(20, 17);
            printf("Usuario o clave incorrectos");
            getch();
        }
    }
    
    if(!acceso) {
        system("color 04");
        gotoxy(20, 18);
        printf("Sistema bloqueado por seguridad");
        getch();
    }
}

void menuPrincipal() {
    int opcion;
    
    do {
        clrscr();
        system("color 0A");
        dibujarMarco();
        
        gotoxy(30, 7);printf("MENU PRINCIPAL");
        gotoxy(21, 9);printf("1. Registrar Productos Deportivos");
        gotoxy(21, 10);printf("2. Registrar Venta");
        gotoxy(21, 11);printf("3. Registrar Compra");
        gotoxy(21, 12);printf("4. Registrar Cliente");
        gotoxy(21, 13);printf("5. Inventario de Productos");
        gotoxy(21, 14);printf("6. Historial de Ventas");
        gotoxy(21, 15);printf("7. Historial de Compras");
        gotoxy(21, 16);printf("8. Lista de Clientes");
        gotoxy(21, 17);printf("9. Creditos");
        gotoxy(21, 8);printf("0. Salir");
        
        gotoxy(20, 20);printf("Seleccione una opcion (0-9): ");
        opcion = validarNumero();
        
        switch(opcion) {
            case 1: 
                system("color 0B");
                registrarProducto(); 
                break;
            case 2: 
                system("color 0C");
                registrarVenta(); 
                break;
            case 3: 
                system("color 0E");
                registrarCompra(); 
                break;
            case 4: 
                system("color 0D");
                registrarCliente(); 
                break;
            case 5: 
                system("color 0F");
                mostrarProductos(); 
                break;
            case 6: 
                system("color 0A");
                mostrarVentas(); 
                break;
            case 7: 
                system("color 09");
                mostrarCompras(); 
                break;
            case 8: 
                system("color 06");
                mostrarClientes(); 
                break;
            case 9: 
                system("color 07");
                mostrarCreditos(); 
                break;
            case 0: 
                system("color 0F");
                gotoxy(20, 20);
                printf("Gracias por usar el sistema!");
                getch();
                break;
            default:
                gotoxy(20, 20);
                printf("Opcion no valida");
                getch();
        }
    } while(opcion != 0);
}

void actualizarStock(int codigo, int cantidad, char tipo) {
    FILE* temp;
    int encontrado = 0;
    struct productos productoTemp;
    
    deportesProductos = fopen("productos.dat", "rb");
    temp = fopen("temp.dat", "wb");
    
    if(deportesProductos == NULL || temp == NULL) {
        if(temp) fclose(temp);
        if(deportesProductos) fclose(deportesProductos);
        return;
    }
    
    while(fread(&productoTemp, sizeof(productos), 1, deportesProductos)) {
        if(productoTemp.codigo == codigo) {
            if(tipo == 'V') {
                productoTemp.stock -= cantidad;
            } else if(tipo == 'C') {
                productoTemp.stock += cantidad;
            }
            encontrado = 1;
        }
        fwrite(&productoTemp, sizeof(productos), 1, temp);
    }
    
    fclose(deportesProductos);
    fclose(temp);
    
    remove("productos.dat");
    rename("temp.dat", "productos.dat");
}

void registrarProducto() {
    char continuar;
    
    do {
        clrscr();
        system("color 0B");
        dibujarMarco();
        
        gotoxy(28, 7);printf("REGISTRO DE PRODUCTOS DEPORTIVOS");
        
        deportesProductos = fopen("productos.dat", "ab");
        if(deportesProductos == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(20, 10);printf("Codigo: ");
        productoDeporte.codigo = validarNumero();
        
        gotoxy(20, 11);printf("Descripcion: ");
        fflush(stdin);
        gets(productoDeporte.descripcion);
        convertirMayusculas(productoDeporte.descripcion);
        
        gotoxy(20, 12);printf("Stock: ");
        productoDeporte.stock = validarNumero();
        
        gotoxy(20, 13);printf("Precio: ");
        scanf("%f", &productoDeporte.precio);
        
        fwrite(&productoDeporte, sizeof(productoDeporte), 1, deportesProductos);
        fclose(deportesProductos);
        
        gotoxy(20, 15);printf("Producto registrado exitosamente!");
        gotoxy(20, 16);printf("Desea agregar otro? (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void registrarVenta() {
    char continuar;
    
    do {
        clrscr();
        system("color 0C");
        dibujarMarco();
        
        gotoxy(30, 7);printf("REGISTRO DE VENTAS");
        
        deportesVentas = fopen("ventas.dat", "ab");
        if(deportesVentas == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(20, 9);printf("Codigo de venta: ");
        ventaDeporte.codigo = validarNumero();
        
        gotoxy(20, 10);printf("Fecha (DD/MM/AAAA): ");
        fflush(stdin);
        gets(ventaDeporte.fecha);
        
        gotoxy(20, 11);printf("Codigo de producto: ");
        ventaDeporte.codProducto = validarNumero();
        
        if(buscarProducto(ventaDeporte.codProducto)) {
            gotoxy(20, 12);printf("Producto: %s", productoDeporte.descripcion);
            gotoxy(20, 13);printf("Precio: %.2f", productoDeporte.precio);
            gotoxy(20, 14);printf("Stock actual: %d", productoDeporte.stock);
            
            gotoxy(20, 15);printf("Cantidad a vender: ");
            ventaDeporte.cantidad = validarNumero();
            
            if(ventaDeporte.cantidad > productoDeporte.stock) {
                gotoxy(20, 17);
                printf("Stock insuficiente!");
                getch();
                fclose(deportesVentas);
                continue;
            }
            
            ventaDeporte.precio = productoDeporte.precio;
            ventaDeporte.total = ventaDeporte.cantidad * ventaDeporte.precio;
            
            gotoxy(20, 16);printf("Total: %.2f", ventaDeporte.total);
            
            fwrite(&ventaDeporte, sizeof(ventaDeporte), 1, deportesVentas);
            fclose(deportesVentas);
            
            actualizarStock(ventaDeporte.codProducto, ventaDeporte.cantidad, 'V');
            
            gotoxy(20, 18);printf("Venta registrada y stock actualizado!");
        } else {
            gotoxy(20, 12);printf("Producto no encontrado!");
            fclose(deportesVentas);
        }
        
        gotoxy(20, 19);printf("Desea registrar otra venta? (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void registrarCompra() {
    char continuar;
    
    do {
        clrscr();
        system("color 0E");
        dibujarMarco();
        
        gotoxy(30, 7);printf("REGISTRO DE COMPRAS");
        
        deportesCompras = fopen("compras.dat", "ab");
        if(deportesCompras == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(20, 9);printf("Codigo de compra: ");
        compraDeporte.codigo = validarNumero();
        
        gotoxy(20, 10);printf("Fecha (DD/MM/AAAA): ");
        fflush(stdin);
        gets(compraDeporte.fecha);
        
        gotoxy(20, 11);printf("Codigo de producto: ");
        compraDeporte.codProducto = validarNumero();
        
        if(buscarProducto(compraDeporte.codProducto)) {
            gotoxy(20, 12);printf("Producto: %s", productoDeporte.descripcion);
            gotoxy(20, 13);printf("Stock actual: %d", productoDeporte.stock);
            
            gotoxy(20, 14);printf("Cantidad a comprar: ");
            compraDeporte.cantidad = validarNumero();
            
            gotoxy(20, 15);printf("Precio de compra: ");
            scanf("%f", &compraDeporte.precioProveedor);
            
            compraDeporte.total = compraDeporte.cantidad * compraDeporte.precioProveedor;
            
            gotoxy(20, 16);printf("Total: %.2f", compraDeporte.total);
            
            fwrite(&compraDeporte, sizeof(compraDeporte), 1, deportesCompras);
            fclose(deportesCompras);
            
            actualizarStock(compraDeporte.codProducto, compraDeporte.cantidad, 'C');
            
            gotoxy(20, 18);printf("Compra registrada y stock actualizado!");
        } else {
            gotoxy(20, 12);printf("Producto no encontrado!");
            fclose(deportesCompras);
        }
        
        gotoxy(20, 19);printf("Desea registrar otra compra? (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void registrarCliente() {
    char continuar;
    
    do {
        clrscr();
        system("color 0D");
        dibujarMarco();
        
        gotoxy(30, 7);printf("REGISTRO DE CLIENTES");
        
        deportesClientes = fopen("clientes.dat", "ab");
        if(deportesClientes == NULL) {
            gotoxy(20, 10);
            printf("Error al abrir archivo");
            getch();
            return;
        }
        
        gotoxy(20, 10);printf("Codigo: ");
        clienteDeporte.codigo = validarNumero();
        
        gotoxy(20, 11);printf("Nombre: ");
        fflush(stdin);
        gets(clienteDeporte.nombre);
        convertirMayusculas(clienteDeporte.nombre);
        
        gotoxy(20, 12);printf("Fecha de registro (DD/MM/AAAA): ");
        gets(clienteDeporte.fechaRegistro);
        
        fwrite(&clienteDeporte, sizeof(clienteDeporte), 1, deportesClientes);
        fclose(deportesClientes);
        
        gotoxy(20, 14);printf("Cliente registrado exitosamente!");
        gotoxy(20, 15);printf("Desea agregar otro? (S/N): ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
        
    } while(continuar == 'S');
}

void mostrarProductos() {
    float totalInventario = 0;
    int linea = 9;
    
    clrscr();
    system("color 0F");
    dibujarMarco();
    
    gotoxy(30, 7);printf("INVENTARIO DE PRODUCTOS");
    gotoxy(10, 8);printf("Cod  Descripcion         Stock  Precio   Total");
    
    deportesProductos = fopen("productos.dat", "rb");
    if(deportesProductos == NULL) {
        gotoxy(20, 10);
        printf("No hay productos registrados");
        getch();
        return;
    }
    
    while(fread(&productoDeporte, sizeof(productoDeporte), 1, deportesProductos)) {
        float totalProducto = productoDeporte.stock * productoDeporte.precio;
        gotoxy(10, linea);
        printf("%d   %-18s %d  %8.2f %8.2f", 
               productoDeporte.codigo, productoDeporte.descripcion, 
               productoDeporte.stock, productoDeporte.precio, totalProducto);
        totalInventario += totalProducto;
        linea++;
    }
    
    gotoxy(10, linea + 1);
    printf("VALOR TOTAL DEL INVENTARIO: $%.2f", totalInventario);
    
    fclose(deportesProductos);
    getch();
}

void mostrarVentas() {
    float totalVentas = 0;
    int linea = 9;
    
    clrscr();
    system("color 0A");
    dibujarMarco();
    
    gotoxy(30, 7);printf("HISTORIAL DE VENTAS");
    gotoxy(7, 8);printf("Cod  Fecha      Prod Cant  Precio   Total");
    
    deportesVentas = fopen("ventas.dat", "rb");
    if(deportesVentas == NULL) {
        gotoxy(20, 10);
        printf("No hay ventas registradas");
        getch();
        return;
    }
    
    while(fread(&ventaDeporte, sizeof(ventaDeporte), 1, deportesVentas)) {
        gotoxy(7, linea);
        printf("%d   %-10s %3d  %4d %8.2f %8.2f", 
               ventaDeporte.codigo, ventaDeporte.fecha, 
               ventaDeporte.codProducto, ventaDeporte.cantidad,
               ventaDeporte.precio, ventaDeporte.total);
        totalVentas += ventaDeporte.total;
        linea++;
    }
    
    gotoxy(7, linea + 1);
    printf("TOTAL VENTAS: $%.2f", totalVentas);
    
    fclose(deportesVentas);
    getch();
}

void mostrarCompras() {
    float totalCompras = 0;
    int linea = 9;
    
    clrscr();
    system("color 09");
    dibujarMarco();
    
    gotoxy(30, 7);printf("HISTORIAL DE COMPRAS");
    gotoxy(5, 8);printf("Cod  Fecha      Prod  Descripcion      Cant  Precio   Total");
    
    deportesCompras = fopen("compras.dat", "rb");
    if(deportesCompras == NULL) {
        gotoxy(20, 10);
        printf("No hay compras registradas");
        getch();
        return;
    }
    
    while(fread(&compraDeporte, sizeof(compraDeporte), 1, deportesCompras)) {
        char descripcionProd[30] = "NO ENCONTRADO";
        if(buscarProducto(compraDeporte.codProducto)) {
            strcpy(descripcionProd, productoDeporte.descripcion);
        }
        
        gotoxy(5, linea);
        printf("%d  %s  %d  %-15s %d %8.2f %8.2f", 
               compraDeporte.codigo, compraDeporte.fecha, 
               compraDeporte.codProducto, descripcionProd,
               compraDeporte.cantidad, compraDeporte.precioProveedor,
               compraDeporte.total);
        totalCompras += compraDeporte.total;
        linea++;
    }
    
    gotoxy(5, linea + 1);
    printf("TOTAL COMPRAS: $%.2f", totalCompras);
    
    fclose(deportesCompras);
    gotoxy(20, linea + 3);
    printf("Presione cualquier tecla para continuar...");
    getch(); 
}

void mostrarClientes() {
    int linea = 9;
    
    clrscr();
    system("color 06");
    dibujarMarco();
    
    gotoxy(30, 7);printf("LISTADO DE CLIENTES");
    gotoxy(15, 8);printf("Codigo  Nombre              Fecha Registro");
    
    deportesClientes = fopen("clientes.dat", "rb");
    if(deportesClientes == NULL) {
        gotoxy(20, 10);
        printf("No hay clientes registrados");
        getch();
        return;
    }
    
    while(fread(&clienteDeporte, sizeof(clienteDeporte), 1, deportesClientes)) {
        gotoxy(15, linea);
        printf("%d      %-20s %s", 
               clienteDeporte.codigo, clienteDeporte.nombre, 
               clienteDeporte.fechaRegistro);
        linea++;
    }
    
    fclose(deportesClientes);
    getch();
}

void mostrarCreditos() {
    clrscr();
    system("color 07");
    dibujarMarco();
    
    gotoxy(15,8);printf("Sistema de Gestion Deportiva");
    gotoxy(15,10);printf("Desarrollado por: German08052");
    gotoxy(15,12);printf("Fecha: 12/06/2025");
    gotoxy(15,14);printf("Version: 1.0");
    gotoxy(15,16);printf("Todos los derechos reservados");
    getch();
    clrscr();
}

int buscarProducto(int codigo) {
    deportesProductos = fopen("productos.dat", "rb");
    if(deportesProductos == NULL) return 0;
    
    while(fread(&productoDeporte, sizeof(productoDeporte), 1, deportesProductos)) {
        if(productoDeporte.codigo == codigo) {
            fclose(deportesProductos);
            return 1;
        }
    }
    fclose(deportesProductos);
    return 0;
}

void convertirMayusculas(char *texto) {
    int i;
    for(i = 0; texto[i]; i++) {
        texto[i] = toupper(texto[i]);
    }
}

int validarNumero() {
    int numero;
    while(scanf("%d", &numero) != 1) {
        printf("\nError: Ingrese solo numeros. Intente de nuevo: ");
        fflush(stdin);
    }
    return numero;
}
