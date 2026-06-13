#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Botonera {
private:

    int cantidad;

    sf::Text* textoBotones;     // array dinámico
    std::string* etiquetas;     // array dinámico
    sf::RectangleShape* botones;  // arreglo dinámico


    sf::Font fuente;
    unsigned int tamCar;
    sf::Color colorBotonera;
    sf::Color colorRecBot;
    sf::Color colorTexto;
    float anchoRect=0;
    float altoRect=0;

public:
    Botonera();
    Botonera(int n, sf::Font& f);
    ~Botonera();

    void inicializar(int n, sf::Font& f);

    void resaltarBoton(int n,sf::Color color,sf::Color color2);
    void igualarBotones(sf::Color color,sf::Color color2);


    void inicializarRectangulos(float ancho, float alto);
    const sf::FloatRect obtPosicion(int i) const;

    void inicializarEtiquetas(const std::string etiquetasExternas[], int cantidadEtiquetas);
    void setTamCar(unsigned int tamCaracter);  //setCharacterSize
    void seColoresBot(sf::Color color,sf::Color colorRec);  //setFillColor
    void setColorTexto(sf::Color color);  //setFillColor





    void setEtiqueta(int i, const std::string& texto);
    void inicializarBotones(float x, float y, bool horiz=false);
    void draw(sf::RenderWindow& ventana);
};

