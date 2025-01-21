#include <stdio.h>
#include <string.h>

void calcularCambio(int cambio)
{
    int billetes50 = 0, billetes20 = 0, monedas10 = 0, monedas5 = 0, monedas2 = 0;

    billetes50 = cambio / 50;
    cambio %= 50;
    billetes20 = cambio / 20;
    cambio %= 20;
    monedas10 = cambio / 10;
    cambio %= 10;
    monedas5 = cambio / 5;
    cambio %= 5;
    monedas2 = cambio / 2;

    printf("Cambio desglosado:\n");
    if (billetes50 > 0)
        printf("%d billete(s) de $50\n", billetes50);
    if (billetes20 > 0)
        printf("%d billete(s) de $20\n", billetes20);
    if (monedas10 > 0)
        printf("%d moneda(s) de $10\n", monedas10);
    if (monedas5 > 0)
        printf("%d moneda(s) de $5\n", monedas5);
    if (monedas2 > 0)
        printf("%d moneda(s) de $2\n", monedas2);
}

void procesarVenta()
{
    char tipoCombustible[10];
    float precioExtra = 0.63;
    float precioSuper = 1.05;
    float precioDiesel = 0.46;
    float litros, costoTotal, montoPagado, cambio;

    printf("Ingrese el tipo de combustible (extra/super/diesel): ");
    while (1)
    {
        scanf("%s", tipoCombustible);
        if (strcmp(tipoCombustible, "extra") == 0 || strcmp(tipoCombustible, "super") == 0 || strcmp(tipoCombustible, "diesel") == 0)
        {
            break;
        }
        else
        {
            printf("Tipo de combustible invalido. Intente de nuevo: ");
        }
    }

    do
    {
        printf("Ingrese la cantidad de litros: ");
        scanf("%f", &litros);
        if (litros <= 0)
        {
            printf("La cantidad de litros debe ser mayor a cero.\n");
        }
    } while (litros <= 0);

    if (strcmp(tipoCombustible, "extra") == 0)
    {
        costoTotal = litros * precioExtra;
    }
    else if (strcmp(tipoCombustible, "super") == 0)
    {
        costoTotal = litros * precioSuper;
    }
    else
    {
        costoTotal = litros * precioDiesel;
    }
    printf("El costo total es: $%.2f\n", costoTotal);

    do
    {
        printf("Ingrese el monto pagado por el cliente: ");
        scanf("%f", &montoPagado);
        if (montoPagado < costoTotal)
        {
            printf("El monto pagado debe ser mayor o igual al costo total.\n");
        }
    } while (montoPagado < costoTotal);

    cambio = montoPagado - costoTotal;
    printf("El cambio a devolver es: $%.2f\n", cambio);

    calcularCambio((int)cambio);
}

int main()
{
    int opcion;

    printf("Bienvenido a la gasolinera\n");
    do
    {
        printf("\nMenu de opciones:\n");
        printf("1. Realizar una venta\n");
        printf("2. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            procesarVenta();
            break;
        case 2:
            printf("Gracias por usar el sistema. Hasta luego\n");
            break;
        default:
            printf("Opción no valida. Intente de nuevo.\n");
        }
    } while (opcion != 2);

    return 0;
}