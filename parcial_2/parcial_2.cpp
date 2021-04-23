#include <iostream>
#include <string>
#include <mysql.h>

using namespace std;

int q_estado;
MYSQL* conectar;
MYSQL_ROW fila;
MYSQL_RES* resultado;

void menu();
void ver();
void ver1();
void ingresar_puesto();
void editar_puesto();
void eliminar_puesto();
void ver_puesto();
void agregar_Empleado();
void editar_empleado();
void eliminar_empleado();
void ver_empleado();

int main() {
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "root", "12345lux", "db_segundo_parcial", 3306, NULL, 0);

    if (conectar) {
        
        cout << "\n\n\t\t ESTE ES EL CRUD EN C++ NUMERO DE EMPLEADOS CARNET 1290-20-17901 (Impar) ...\n\n" << endl;
        system("pause");

        menu();


    }

    else {
      
        cout << "\n\n\t\tError de conexion ;( ..\n\n" << endl;
        system("pause");
    }


    system("pause");

    return 0;

}

void menu() {
    system("cls");
    system("cls");
    int opcion;

    do {

        cout << "\n\t\t\t.SELECCIONE LA OPCION QUE DESEE.\n\n" << endl;
        cout << "1. INGRESAR PUESTO. " << endl;
        cout << "2. INGRESAR EMPLEADO. " << endl;
        cout << "3. MODIFICAR PUESTO. " << endl;
        cout << "4. MODIFICAR EMPLEADO." << endl;
        cout << "5. ELIMINIAR PUESTO. " << endl;
        cout << "6. ELIMINAR EMPLEADO. " << endl;
        cout << "7. MOSTRAR PUESTO. " << endl;
        cout << "8. MOSTRAR EMPLEADOS. " << endl;
        cout << "9. SALIR. " << endl;
        cout << "\nDigite una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: system("cls");
            ingresar_puesto();
            break;
        case 2: system("cls");
            agregar_Empleado();
            break;
        case 3: system("cls");
            editar_puesto();
            break;
        case 4: system("cls");
            editar_empleado();
            break;
        case 5: system("cls");
            eliminar_puesto(); 
            break;
        case 6: system("cls");
            eliminar_empleado(); 
            break;
        case 7: system("cls");
            ver_puesto();
            break;
        case 8: system("cls");
            ver_empleado();
            break;
        case 9: system("cls");
            cout << "Saliendo del sistema..\n\n" << endl;
            system("pause");
            exit(1);
            break;

        default: system("cls");
            cout << "La opcion no es valida.." << endl; 
            system("pause");
            menu();
        }


    } while (opcion != 9);
}

void ver() {
    string consulta = "select *from Puestos";
    const char* consultar = consulta.c_str();
    q_estado = mysql_query(conectar, consultar);

    if (!q_estado) {
        resultado = mysql_store_result(conectar);
       

        while (fila = mysql_fetch_row(resultado)) {

            cout << fila[0] << " - " << fila[1] << endl;
        }
        cout << "\n\n\n";
    }
}
void ingresar_puesto() {

    system("cls");
    cout << "\n\t\t\t------INGRESE EL PUESTO---------- \n\n" << endl;
    string puesto;
    cin.ignore();
    cout << "INGRESE EL NOMBRE DEL PUESTO : ";
    getline(cin, puesto);

    string insert = "insert into Puestos (puesto) values('" + puesto + "')";
    const char* insertar = insert.c_str();
    q_estado = mysql_query(conectar, insertar);

    if (!q_estado) {

    
        cout << "\n\n\t\tDatos agregados :)...\n\n" << endl;
        system("pause");
        menu();
    }
    else {
        
        cout << "\n\n\t\tDatos no agregados :(..\n\n" << endl;
        cout << "\n\n\t\tIniciando conexion de nuevo..\n\n" << endl;
        cout << insert << "\n\n\n";
        system("pause");
        main();
    }

}

void editar_puesto() {
    string id_Puestos, puesto;
    system("cls");
    cout << "\n\t\t\t----------MODIFICAR PUESTO------- \n\n" << endl;

    ver();

    cin.ignore();
    cout << "\nIngrese el ID del Puesto a modificar: ";
    cin >> id_Puestos;

    cin.ignore();
    cout << "Ingrese el nuevo Nombre: ";
    getline(cin, puesto);

    string consulta = "update Puestos set puesto = '" + puesto + "' where id_Puestos = ('" + id_Puestos + "'); ";
    fflush(stdin);
    const char* insertar = consulta.c_str();
    q_estado = mysql_query(conectar, insertar);

    if (!q_estado) {

        system("color 02");
        cout << "\n\n\t\tDatos Modificados con exito...\n\n" << endl;
        system("pause");
        fflush(stdin);
        menu();
    }
    else {
        system("color 0c");
        cout << "\n\n\t\tError al agregar los datos :(..\n\n" << endl;
        cout << "Erro de conexion o el ID a modificar :( " << endl;
        cout << "\n\n\t\tIniciando conexion de nuevo..\n\n" << endl;
        system("pause");
        main();
    }
}

void eliminar_puesto() {
    string id_Puestos, puesto;
    system("cls");

    cout << "\n\t\t\t----------ELIMINAR PUESTOS----- \n\n" << endl;
    ver();
    cin.ignore();
    cout << "\nIngrese el ID de la marca a eliminar: ";
    cin >> id_Puestos;

    cout << "Esta seguro que desa eliminar el dato (s/n): "; cin >> puesto;

    if (puesto == "s" || puesto == "S") {
        string consulta = "delete from Puestos  where id_Puestos = '" + id_Puestos + "'";
        const char* insertar = consulta.c_str();
        q_estado = mysql_query(conectar, insertar);

    }

    else {
        cout << " \n\nDatos no eliminados ;(..\n\n\n" << endl;
        system("pause");
        menu();
    }


    if (!q_estado) {

        system("color 02");
        cout << "\n\n\t\tDatos eliminados con exito.:)..\n\n" << endl;
        system("pause");
        menu();
    }
    else {
        cout << "\n\n\t\tError al eliminar :(..\n\n" << endl;
        cout << "\n\n\t\tIniciando conexion de nuevo..\n\n" << endl;
        system("pause");
        main();
    }
}
void ver_puesto() {
    system("cls");

    cout << "\n\n\t\t\t--------Puestos Registradas------\n\n " << endl;

    string consulta = "select *from Puestos";
    const char* consultar = consulta.c_str();
    q_estado = mysql_query(conectar, consultar);

    if (!q_estado) {
        resultado = mysql_store_result(conectar);
        system("color 02");

        while (fila = mysql_fetch_row(resultado)) {

            cout << fila[0] << " - " << fila[1] << endl;
        }
        cout << "\n\n\n"; system("pause");
        menu();
    }
    else {
   
        cout << " Error al consulta  " << endl;
        main();
    }
}

void agregar_Empleado() {
    string nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_puestos, fecha_inicio_labores, fecha_ingreso;
    system("cls");
    cout << "\n\t\t\t------------Agregar Empleado------- \n\n" << endl;
    fflush(stdin);
    cin.ignore();

    cout << "Ingrese el  Nombres del Empleado: "; getline(cin, nombres);

    cout << "Ingrese los Apellidos del  Empleado: "; getline(cin, apellidos);
    fflush(stdin);
    cout << "Ingrese la Direccion del Empleado: "; getline(cin, direccion);

    cout << "Ingrese  el numero de telefono del empleado: "; getline(cin, telefono);

    fflush(stdin);
    cout << "Ingrese la numeracion del DPI: "; getline(cin, DPI);

    cout << "Ingrese el Genero del Empleado (0 = Femenino  1 = Masculino): "; getline(cin, genero);

    cout << "Ingrese  la Fecha de nacimiento (YYYY-MM-DD): "; getline(cin, fecha_nacimiento);

    fflush(stdin);
    cout << "\n\n\n\n";
    ver(); system("color 07");
    cout << "Ingrese el ID del puesto que estara el empleado: "; getline(cin, id_puestos);
    fflush(stdin);
    cout << "Ingrese la fecha de inicio de labores  es (YYYY-MM-DD): ";  getline(cin, fecha_inicio_labores);

    fflush(stdin);
    cout << "Ingrese la fecha de ingreso de labores (YYYY-MM-DD HH:MM:SS): "; getline(cin, fecha_ingreso);

    string insert = "insert into empleados(nombres,apellidos,direccion,telefono,DPI,genero,fecha_nacimiento,id_Puesto,fecha_inicio_labores,fecha_ingreso) values('" + nombres + "','" + apellidos + "','" + direccion + "','" + telefono + "',""'" + DPI + "'," + genero + ",'" + fecha_nacimiento + "','" + id_puestos + "','" + fecha_inicio_labores + "','" + fecha_ingreso + "');";
    const char* insertar = insert.c_str();
    q_estado = mysql_query(conectar, insertar);
    if (!q_estado) {

       
        cout << "\n\n\t\tDatos agregados con exito ;)...\n\n" << endl;
        system("pause");
        menu();
    }
    else {
      
        cout << "\n\n\t\tError al agregar los datos..\n\n" << endl;
        cout << insert;
        cout << "\n\n\t\tIniciando conexion de nuevo..\n\n" << endl;
        system("pause");
        main();
    }
}

void ver1() {
    string consulta = "select *from empleados";
    const char* consultar = consulta.c_str();
    q_estado = mysql_query(conectar, consultar);
    if (!q_estado) {
        resultado = mysql_store_result(conectar);

        while (fila = mysql_fetch_row(resultado)) {

            cout << fila[0] << " - " << fila[1] << " - " << fila[2] << endl;
        }

        cout << "\n\n";
    }
}

void editar_empleado() {
    system("cls");
    cout << "\n\t\t\t----------Editar Empleado Puesto------- \n\n" << endl;
    string id_empleado, respueta;
    ver1();
    cout << "Ingrese el ID del empleado a modificar: ";
    cin >> id_empleado;

    string nombres, apellidos, direccion, telefono, DPI, genero, fecha_nacimiento, id_puestos, fecha_inicio_labores, fecha_ingreso;
    fflush(stdin);
    cin.ignore();

    cout << "Ingrese los Nombres del Empleado: "; 
    getline(cin, nombres);

    cout << "Ingrese los Apellidos del  Empleado: ";
    getline(cin, apellidos);
    fflush(stdin);
    cout << "Ingrese la Direccion del Empleado: ";
    getline(cin, direccion);

    cout << "Ingrese el numero de telefono del empleado: "; 
    getline(cin, telefono);
    fflush(stdin);
    cout << "Ingrese la numeracion del DPI: ";
    getline(cin, DPI);

    cout << "Ingrese el Genero del Empleado (0 = Femenino  1 = Masculino): ";
    getline(cin, genero);

    cout << "Ingrese la Fecha de nacimiento (YYYY-MM-DD): ";
    getline(cin, fecha_nacimiento);

    fflush(stdin);
    cout << "\n\n\n\n";
    ver(); system("color 07");
    cout << "Ingrese el ID del puesto que estara el empleado: ";
    getline(cin, id_puestos);
    fflush(stdin);
    cout << "Ingrese la fecha de inicio de labores  es (YYYY-MM-DD): ";
    getline(cin, fecha_inicio_labores);

    fflush(stdin);
    cout << "Ingrese la fecha de ingreso de labores (YYYY-MM-DD HH:MM:SS): ";
    getline(cin, fecha_ingreso);

    string consulta = "UPDATE empleados set nombres = '" + nombres + "' , apellidos= '" + apellidos + "', direccion= '" + direccion + "', telefono= '" + telefono + "',DPI= '" + DPI + "',genero= " + genero + ",fecha_nacimiento= '" + fecha_nacimiento + "',id_Puesto= '" + id_puestos + "',fecha_inicio_labores= '" + fecha_inicio_labores + "',fecha_ingreso= '" + fecha_ingreso + "' where id_Empleado =('" + id_empleado + "');";
    const char* insertar = consulta.c_str();
    q_estado = mysql_query(conectar, insertar);

    if (!q_estado) {
        cout << "\n\n\t\tDatos modificados con exito...\n\n" << endl;

        system("pause");
    }
    else {
        cout << "\n\n\t\tError al agregar los datos..\n\n" << endl;
        cout << consulta << "\n\n\n";
        system("pause");
    }
}
void eliminar_empleado() {
    system("cls");
    cout << "\n\t\t\t-----------Eliminar Empleado-------- \n\n" << endl;
    ver1();
    string id_empleado, respueta;
    cout << "ID del empleado a eliminar: ";
    cin >> id_empleado;
    cin.ignore();
    cout << "Esta seguro que desa eliminar el dato (s/n): "; getline(cin, respueta);

    if (respueta == "s" || respueta == "S") {
        system("color 02");
        string consulta = "delete from empleados  where id_Empleado = '" + id_empleado + "'";
        const char* insertar = consulta.c_str();
        q_estado = mysql_query(conectar, insertar);

    }

    else {
        cout << " \n\nDatos no eliminados.." << endl;
    }


    if (!q_estado) {
        cout << "\n\n\t\tDatos eliminados con exito...\n\n" << endl;
        system("pause");
    }
    else {
        cout << "\n\n\t\tError al eliminar ..\n\n" << endl;
        system("pause");
    }

}
void ver_empleado() {
    system("cls");
    cout << "\n\t\t\t----------Agregar Puesto------ \n\n" << endl;

    string consulta = "select *from empleados";
    const char* consultar = consulta.c_str();
    q_estado = mysql_query(conectar, consultar);

    if (!q_estado) {
        resultado = mysql_store_result(conectar);

        while (fila = mysql_fetch_row(resultado)) {

            cout << fila[0] << " - " << fila[1] << " - " << fila[2] << " - " << fila[3] << " - " << fila[4] << " - " << fila[5] << " - " << fila[6] << " - " << fila[7] << " - " << fila[8] << " - " << fila[9] << " - " << fila[10] << " - " << fila[11] << endl;
        }
        cout << "\n" << endl; system("pause");
    }
    else {
        cout << "xxx Error al consulta xxx" << endl;
    }
}

