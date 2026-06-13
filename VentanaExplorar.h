#pragma once
#include "botonera.h"
#include <SFML/Graphics.hpp>

class VentanaExplorar {
public:
    VentanaExplorar(const std::string& titulo, const std::string& mensaje);

    // Devuelve true si el usuario presiona "Sí", false si "No" o cierra
    bool mostrar(sf::RenderWindow& window);
    //void resaltarBoton(int i);
    void cargarRecursos();

private:
    sf::Texture fondoTexture;
    sf::Sprite  fondoSprite;
    sf::RectangleShape fondo;
    sf::Text textoTitulo;
    sf::Text textoMensaje;
    sf::Font font;
    Botonera botoneraExp;

    //sf::RectangleShape botonSi;
    //sf::RectangleShape botonNo;
    //sf::Text textoSi;
    //sf::Text textoNo;

    //void centrarTexto(sf::Text& texto, const sf::RectangleShape& rect);
};
