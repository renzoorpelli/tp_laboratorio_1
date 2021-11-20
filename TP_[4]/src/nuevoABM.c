









int menu()
{
    int opcion = 0;
    system("cls");
    printf("    ***ABM Personas***\n");
    printf("1- Cargar los datos de los empleados desde el archivo en modo csv \n");
    printf("2- Cargar los datos de los empleados desde el archivo en modo binario\n");
    printf("3- Alta de empleado\n");
    printf("4- Modificar datos de empleado\n");
    printf("5- Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7- Ordenar empleados\n");
    printf("8- Guardar los datos de los empleados desde el archivo en modo csv\n");
    printf("9- Guardar los datos de los empleados desde el archivo en modo binario\n");
    printf("10- SALIR\n");
    printf("Ingrese opcion: \n");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
