#include <stdio.h>

int main(int argc, char *argv[])
{
    int opcion;
    float gasolina = 4, diesel = 2, precio, litros;
    int billetes50, billetes20, monedas10, monedas5, monedas2, monedas1, cambio;
    float montoPagado;
    while (opcion != 3)
    {
        printf("Seleccione una opcion escogiendo un numero del 1 al 3: \n");
        printf("1. Comprar Gasolina ($2.50 por litro)\n");
        printf("2. Comprar Diesel ($2.00 por litro)\n");
        printf("3. Salir\n");
        printf(">>> ");
        scanf("%d", &opcion);
        if (opcion == 3)
        {
            printf("Adios");
            return 0;
        }
        if (opcion == 1)
        {
            printf("Ingrese la cantidad de litros que desea: ");
            scanf("%f", &litros);
            precio = gasolina * litros;
            printf("Total a pagar: $%.2f\n", precio);
        }
        else
        {
            printf("Ingrese la cantidad de litros que desea: ");
            scanf("%f", &litros);
            precio = diesel * litros;
            printf("Total a pagar: $%.2f\n", precio);
        }
        do
        {
            printf("Ingrese la cantidad de dinero depositado: ");
            scanf("%f", &montoPagado);
            if (montoPagado < precio)
            {
                printf("Monto insuficiente. Ingrese un valor mayor.\n");
            }
        } while (montoPagado < precio);
        cambio = montoPagado - precio;
        billetes50 = cambio / 50;
        cambio = cambio % 50;
        billetes20 = cambio / 20;
        cambio = cambio % 20;
        monedas10 = cambio / 10;
        cambio = cambio % 10;
        monedas5 = cambio / 5;
        cambio = cambio % 5;
        monedas2 = cambio / 2;
        cambio = cambio % 2;
        monedas1 = cambio;
        printf("El cambio que se le que se le da es de: \n");
        if (billetes50 > 0)
        {
            printf("%d billete(s) de $50\n", billetes50);
        }
        if (billetes20 > 0)
        {
            printf("%d billete(s) de $20\n", billetes20);
        }
        if (monedas10 > 0)
        {
            printf("%d moneda(s) de $10\n", monedas10);
        }
        if (monedas5 > 0)
        {
            printf("%d moneda(s) de $5\n", monedas5);
        }
        if (monedas2 > 0)
        {
            printf("%d moneda(s) de $2\n", monedas2);
        }
        if (monedas1 > 0)
        {
            printf("%d moneda(s) de $1\n", monedas1);
        }
        precio = montoPagado - precio;
        printf("Dando un total de: ");
        printf("%.2f", precio);
        printf("\nGracias por su compra. \n");
    }
    printf("Adios");
    return 0;
}