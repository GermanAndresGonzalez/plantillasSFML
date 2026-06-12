#include "ventana.h"
#include "datosVentana.h"
#include <iostream>

// Constructor: Usa la lista de inicialización para crear la ventana de SFML
Ventana::Ventana(unsigned int ancho, unsigned int alto, const std::string& titulo)
    : m_ventana(sf::VideoMode(ancho, alto), titulo,sf::Style::Titlebar | sf::Style::Close)
{
    // Aquí puedes configurar límites de FPS si lo deseas:
    m_ventana.setFramerateLimit(60);
    cargarRecursos();

}
void Ventana::cargarRecursos() {
    if (!texturaFondo.loadFromFile(RUTA_FONDO))
    {
        std::cerr << ERROR_FONDO;
    }
    spriteFondo.setTexture(texturaFondo);
}
// El bucle principal extraído del main original
void Ventana::ejecutar() {
    while (m_ventana.isOpen()) {
        procesarEventos();
        renderizar();
    }
}

// Manejo exclusivo de eventos de entrada y cierre
void Ventana::procesarEventos() {
    sf::Event evento;
    while (m_ventana.pollEvent(evento)) {
        if (evento.type == sf::Event::Closed) {
            m_ventana.close();
        }
    }
}

// Lógica dedicada a limpiar y dibujar en la pantalla
void Ventana::renderizar() {
    m_ventana.clear(sf::Color::Black);
    m_ventana.draw(spriteFondo);
    // (Aquí irán tus llamadas a m_ventana.draw() en el futuro)

    m_ventana.display();
}
