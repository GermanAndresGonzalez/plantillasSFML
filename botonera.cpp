
#include "botonera.h"
#include <iostream>

Botonera::Botonera(int n, sf::Font& f) : cantidad(n), fuente(f)
{
    textoBotones = new sf::Text[cantidad];
    botones = new sf::RectangleShape[cantidad];
    etiquetas = new std::string[cantidad];
}

Botonera::~Botonera()
{
    delete[] textoBotones;
    delete[] botones;
    delete[] etiquetas;
    textoBotones = nullptr;
    botones = nullptr;
    etiquetas = nullptr;
}

void Botonera::inicializarEtiquetas(const std::string etiquetasExternas[], int cantidadEtiquetas)
{
    for (int i = 0; i < cantidad && i < cantidadEtiquetas; i++)
    {
        setEtiqueta(i, etiquetasExternas[i]);
    }
}

void Botonera::inicializarRectangulos(float ancho, float alto)
{
    anchoRect=ancho;
    altoRect=alto;
    for (int i = 0; i < cantidad; i++)
    {
        botones[i].setSize(sf::Vector2f(ancho, alto));
        //botones[i].setFillColor(sf::Color(colorBotonera));
        botones[i].setFillColor(colorBotonera);
        botones[i].setOutlineThickness(1.f);
        botones[i].setOutlineColor(colorRecBot);
    }
}

void Botonera::resaltarBoton(int n,sf::Color color,sf::Color color2)
{

    botones[n].setFillColor(sf::Color(color));
    textoBotones[n].setColor(sf::Color(color2));

}
void Botonera::igualarBotones(sf::Color color,sf::Color color2)
{
    for (int i=0; i<cantidad; i++)
    {
        botones[i].setFillColor(sf::Color(color));
        //textoBotones[i].setColor(sf::Color::Blue);
        textoBotones[i].setColor(sf::Color(color2));
    }
}

const sf::FloatRect Botonera::obtPosicion(int i) const
{
    if(i>=0 && i<cantidad)
    {
        return botones[i].getGlobalBounds();
    }
    return sf::FloatRect();

}
void Botonera::setTamCar(unsigned int tamCaracter)
{
    tamCar=tamCaracter;
}
void Botonera::seColoresBot(sf::Color color,sf::Color colorRec)
{
    colorBotonera=color;
    colorRecBot=colorRec;
}

void Botonera::setColorTexto(sf::Color color)
{
    colorTexto=color;
}

Botonera::Botonera()
    : cantidad(0), textoBotones(nullptr), etiquetas(nullptr), botones(nullptr), tamCar(30), colorBotonera(sf::Color::Transparent), colorTexto(sf::Color::White)
{
}

void Botonera::setEtiqueta(int i, const std::string& texto)
{
    if (i >= 0 && i < cantidad)
    {
        etiquetas[i] = texto;
        textoBotones[i].setFont(fuente);
        textoBotones[i].setString(texto);
        textoBotones[i].setCharacterSize(tamCar);
        textoBotones[i].setFillColor(colorTexto);
    }
}

void Botonera::inicializarBotones(float x, float y)
{

    for (int i = 0; i < cantidad; i++)
    {
        botones[i].setPosition(x, y + i * 60.f);
    }
    sf::FloatRect bounds =textoBotones->getLocalBounds();

    float xTexto = x+10 ;//+ (anchoRect - bounds.width) / 2.f - bounds.left;
    float yTexto = y + (altoRect - bounds.height) / 2.f - bounds.top;

    for (int i = 0; i < cantidad; i++)
    {
        //textoBotones[i].setPosition(x+5, y + i * 60.f);
        textoBotones[i].setPosition(xTexto, yTexto + i* 60.f);
    }

}

void Botonera::draw(sf::RenderWindow& ventana)
{
    for (int i = 0; i < cantidad; i++)
    {
        ventana.draw(botones[i]);
        ventana.draw(textoBotones[i]);

    }
}

void Botonera::inicializar(int n, sf::Font& f)
{
    cantidad = n;
    fuente = f;
    delete[] textoBotones;
    delete[] botones;
    delete[] etiquetas;
    textoBotones = new sf::Text[cantidad];
    etiquetas = new std::string[cantidad];
    botones = new sf::RectangleShape[cantidad];
}
