#include <SFML/Graphics.hpp>
#include "level.h"
using namespace sf;

float RectX = 500;
float RectY = 200;
float RectW = 400;
float RectH = 400;
float PosX = 500;
float PosY = 500;

View view;
class Player
{
public:
    std::vector<Object> obj; // Вектор объектов карты
    float dx, dy, x, y, speed;
    int w, h; // Ширина и высота тайла
    Texture texture;
    Sprite sprite;
public:
    Player(Image &image, std::vector<Object>& _obj, float X, float Y, int W, int H){
        x = X; y = Y; w = W; h = H;
        speed = 0.1; dx = speed; dy = speed;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
        obj = _obj;
    }

    int getX() {return x;}
    int getY() {return y;}

    // функция получения прямоугольника. координаты объекта, размер (ширина, высота).
    FloatRect getRect(){ return FloatRect(x, y, w, h); }// нужна для проверки столкновений

    // Проверяем Столкновения Нашего Игрока с Другими Тайлами Карты
    void checkCollisionWithMap(float Dx, float Dy)
    {
        for (size_t i = 0; i < obj.size(); i++) // Проходимся по всем элементам карты
            if (getRect().intersects(obj[i].rect)) // Если мы пересекаемся с каким-то тайликом
            {
                if (obj[i].name == "solid") // И этот тайлик помечен знаком "Стена"
                {
                    if (Dy>0)	{ y = obj[i].rect.top - h;  dy *= -1;; }
                    else if (Dy<0)	{ y = obj[i].rect.top + obj[i].rect.height;   dy *= -1; }
                    if (Dx>0)	{ x = obj[i].rect.left - w; dx *= -1;}
                    else if (Dx<0)	{ x = obj[i].rect.left + obj[i].rect.width; dx *= -1;}

                    sprite.setColor(Color(rand(),rand(),rand()));
                }
            }
    }

    void update(float time)
    {
        x += dx*time;
        checkCollisionWithMap(dx, 0);
        y += dy*time;
        checkCollisionWithMap(0, dy);
        sprite.setPosition(x + w / 2, y + h / 2);


        if((x) < PosX || (x+w) > PosX + RectW)
        {
            PosX = x + w / 2 - RectW / 2;
            PosY = y + h / 2 - RectH / 2;
        }

        else if((y) < PosY || (y+h) > PosY + RectH)
        {
            PosY = y + h / 2 - RectH / 2;
            PosX = x + w / 2 - RectW / 2;
        }
    }

    Sprite getSprite()  { return sprite;}
};


int main()
{
    //////////////////////////////СОЗДАЁМ ОКНО//////////////////////////////
    RenderWindow window(VideoMode(2000, 1250), "FlyingDVD");  // Создаём окно
    //////////////////////////////ЗАГРУЖАЕМ КАРТУ//////////////////////////////
    Level lvl; // Создаём объект типа "Карта"
    lvl.LoadFromFile("../../map.tmx");  // Загружаем нашу карту
    std::vector<Object> obj = lvl.GetAllObjects(); // Получаем вектор объектов карты
    //////////////////////////////СОЗДАЁМ ИГРОКА//////////////////////////////
    Image heroImage;
    heroImage.loadFromFile("../../images/sasha.jpg");
    heroImage.createMaskFromColor(Color(0,0,0,0));
    Object player = lvl.GetObject("player");
    Player object(heroImage, obj, player.rect.left, player.rect.top, 207, 207);//72 83 player

    // Рисуем прямоугольник
    RectangleShape rectangle(sf::Vector2f(RectW, RectH));
    PosX = object.x + object.w/2 - RectW;
    PosY = object.y + object.h/2 - RectH;
    rectangle.setPosition(PosX, PosY);


    // Создаём часики для работы со временем
    Clock clock;
    while (window.isOpen())
    {
        window.clear(Color::Black);
        window.setView(view);
        //////////////////////////////ВРЕМЯ//////////////////////////////
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time = time / 800; // Уменьшаем время, чтобы не так быстро всё летало
        //////////////////////////////ДАРИМ ИГРЕ ЖИЗНЬ//////////////////////////////
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //////////////////////////////РИСУЕМ КАРТУ//////////////////////////////
        lvl.Draw(window);
        rectangle.setPosition(PosX, PosY);
        view.reset(FloatRect(PosX - 200, PosY - 200, PosX + RectW + 200, PosY + RectH + 200));
        window.draw(rectangle);
        //////////////////////////////ДАРИМ ИГРОКУ ЖИЗНЬ//////////////////////////////
        object.update(time);
        window.draw(object.getSprite()); // Рисуем игрока

        window.display(); // Показываем наше игровое окно
    }
    return 0;
}

