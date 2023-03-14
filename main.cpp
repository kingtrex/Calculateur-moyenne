#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(sf::Vector2u(200, 200)), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
//C:\\Users\\ttann\\OneDrive\\Documents\\GitHub\\Calculateur-moyenne\\test.txt
/*std::string nom = "Maths";
    int *a = new int;
    *a = 5;
    Matiere test(nom , 4.5);
    std::cout << test.getNom() << std::endl;
    delete a;*/