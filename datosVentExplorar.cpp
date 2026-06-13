#include "datosVentExplorar.h"

const char* TITULO="Eplora la cueva";
const char* EXPLICACION="Te encuentras en la cueva.\nNo tienes nada con que defenderte.\n";
const int CANT_BOTONES_EX=4;

const unsigned int TAM_CARACTER_EX=20;

const sf::Color COLOR_FONDO_EX = sf::Color(0, 0, 0, 180); //Semi transparente
const sf::Color COLOR_FONDO_RES_EX = sf::Color(90, 140, 210);
const sf::Color COLOR_LETRA_EX = sf::Color::White;
const sf::Color COLOR_LETRA_RES_EX = sf::Color(39,87,59);
const sf::Color COLOR_RECUA_EX = sf::Color::White;

const float posBotonX_EX=400;
const float posBotonY_EX=450;

const float tamRectBotonX_EX=150.f;
const float tamRectBotonY_EX=40.f;


const std::string ETI_BOTONES_EX[] = {
    "Explorar",
    "Craftear",
    "Pasar",
    "Atras"
};
