#pragma once
#include "botonera.h"

#include <SFML/Graphics.hpp>
#include <string>


class Ventana {
public:
    // Constructor que inicializa el tamaño y el título
    Ventana(unsigned int ancho, unsigned int alto, const std::string& titulo);

    // Bucle principal que mantiene la ventana con vida
    void ejecutar();
    void ejecutarAccion(int eleccion);

private:
    // Métodos privados para organizar el flujo del juego/aplicación
    void procesarEventos();
    void renderizar();
    void cargarRecursos();
    sf::Font fuenteBotonera;

    sf::Texture texturaFondo;
    sf::Sprite spriteFondo;
    Botonera botonera;


    // Atributo principal de SFML
    sf::RenderWindow m_ventana;
};


