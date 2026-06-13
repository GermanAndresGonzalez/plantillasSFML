#include "ventana.h"
#include "datosVentana.h"
#include "botonera.h"
#include "datosBotonera.h"
#include "VentanaExplorar.h"
#include "datosVentExplorar.h"

#include <iostream>

// Constructor: Usa la lista de inicialización para crear la ventana de SFML
Ventana::Ventana(unsigned int ancho, unsigned int alto, const std::string& titulo)
    : m_ventana(sf::VideoMode(ancho, alto), titulo,sf::Style::Titlebar | sf::Style::Close)
{
    // Aquí puedes configurar límites de FPS si lo deseas:
    m_ventana.setFramerateLimit(60);

    Botonera botonera;
    cargarRecursos();


}
/*
bool Ventana::botoneraVisible()
{
    return true; // o la lógica que corresponda
}
*/
void Ventana::cargarRecursos()
{
    if (!texturaFondo.loadFromFile(RUTA_FONDO))
    {
        std::cerr << ERROR_FONDO;
    }
    if (!fuenteBotonera.loadFromFile(FUENTE))
    {
        std::cerr << ERROR_FUENTE;
    }

    spriteFondo.setTexture(texturaFondo);

    botonera.inicializar(5, fuenteBotonera);
    botonera.seColoresBot(COLOR_FONDO,COLOR_RECUA);
    botonera.inicializarRectangulos(tamRectBotonX, tamRectBotonY);
    botonera.setTamCar(TAM_CARACTER);
    botonera.setColorTexto(COLOR_LETRA); //COLOR_FONDO
    botonera.inicializarEtiquetas(ETI_BOTONES,5);
    botonera.inicializarBotones(posBotonX,posBotonY);



}
// El bucle principal extraído del main original
void Ventana::ejecutar()
{
    while (m_ventana.isOpen())
    {
        procesarEventos();
        renderizar();
    }
}



// Manejo exclusivo de eventos de entrada y cierre
void Ventana::procesarEventos()
{
    sf::Event evento;
    while (m_ventana.pollEvent(evento))
    {
        if (evento.type==sf::Event::MouseMoved)
        {
            for (int i=0; i <CANT_BOTONES; i++)
            {
                if (!botonera.obtPosicion(i).contains(static_cast<float>(evento.mouseMove.x), static_cast<float>(evento.mouseMove.y)))
                {
                    botonera.igualarBotones(COLOR_FONDO,COLOR_LETRA);
                    break;
                }
            }

            for (int i=0; i <CANT_BOTONES; i++)
            {
                if (botonera.obtPosicion(i).contains(static_cast<float>(evento.mouseMove.x), static_cast<float>(evento.mouseMove.y)))
                {
                    botonera.resaltarBoton(i,COLOR_FONDO_RES,COLOR_LETRA_RES);
                    break;
                }
            }
        }
        if (evento.type == sf::Event::MouseButtonPressed && evento.mouseButton.button == sf::Mouse::Left)
        {
            sf::Vector2i mousePos = sf::Mouse::getPosition(m_ventana);
            for (int i=0; i<CANT_BOTONES; i++)
            {
                if (botonera.obtPosicion(i).contains(static_cast<float>(mousePos.x),static_cast<float>(mousePos.y)))
                {
                    ejecutarAccion(i);
                    break;
                }
            }
        }

        if (evento.type == sf::Event::Closed)
        {
            m_ventana.close();
        }
    }
}

// Lógica dedicada a limpiar y dibujar en la pantalla
void Ventana::renderizar()
{
    m_ventana.clear(sf::Color::Black);
    m_ventana.draw(spriteFondo);

    // (Aquí irán tus llamadas a m_ventana.draw() en el futuro)
    botonera.draw(m_ventana);
    m_ventana.display();
}
void Ventana::abrirExplorar()
{
    VentanaExplorar ventanaExplorar(TITULO,EXPLICACION);
    bool respuesta = ventanaExplorar.mostrar(m_ventana);
    if (respuesta)
    {
        m_ventana.close();
    }
}

void Ventana::ejecutarAccion(int eleccion)
{
    switch (eleccion)
    {
    case 0:
        std::cout << eleccion <<std::endl;
        break;
    case 1:
        abrirExplorar();
        break;
    case 2:
        std::cout << eleccion <<std::endl;
        break;
    case 3:
        std::cout << eleccion <<std::endl;
        break;
    case 4:
        std::cout << eleccion <<std::endl;
        break;
    }
}
