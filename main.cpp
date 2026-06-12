#include "Ventana.h"
#include "datosVentana.h"

int main() {
    // Instanciamos el objeto Ventana con los parámetros deseados
    Ventana miAplicacion(xVent, yVent, TIT_VENTANA);

    // Arrancamos el bucle del programa
    miAplicacion.ejecutar();

    return 0;
}
