#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "imgui.h"
#include "imgui-SFML.h"   // ImGui-SFML integration

int main()
{
    // Window dimensions
    const int wWidth = 1200;
    const int wHeight = 720;

    // Create SFML RenderWindow
    sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML + ImGui Example");
    window.setFramerateLimit(60);

    // Initialize ImGui-SFML
    if (!ImGui::SFML::Init(window))
    {
        return -1;   // Return error if ImGui-SFML initialization fails
    }

    sf::Clock deltaClock;

    // ImGui style and scaling
    ImGui::GetStyle().ScaleAllSizes(2.0f);
    ImGui::GetIO().FontGlobalScale = 2.0f;

    // Circle properties
    float circleRadius = 50.0f;
    int circleSegments = 32;
    sf::Color circleColor = sf::Color::Cyan;
    bool drawCircle = true;

    sf::CircleShape circle(circleRadius, circleSegments);
    circle.setFillColor(circleColor);
    circle.setPosition(100.0f, 100.0f);

    // Movement properties
    float speedX = 1.0f, speedY = 1.0f;

    // Main loop
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            // Process ImGui events
            ImGui::SFML::ProcessEvent(window, event);
        }

        // ImGui Update
        ImGui::SFML::Update(window, deltaClock.restart());

        // ImGui window
        ImGui::Begin("Control Panel");
        ImGui::Checkbox("Draw Circle", &drawCircle);
        ImGui::SliderFloat("Radius", &circleRadius, 10.0f, 200.0f);
        ImGui::SliderInt("Segments", &circleSegments, 3, 64);
        ImGui::ColorEdit3("Circle Color", reinterpret_cast<float *>(&circleColor));
        ImGui::SliderFloat("Speed X", &speedX, -5.0f, 5.0f);
        ImGui::SliderFloat("Speed Y", &speedY, -5.0f, 5.0f);
        ImGui::End();

        // Update circle properties
        circle.setRadius(circleRadius);
        circle.setPointCount(circleSegments);
        circle.setFillColor(circleColor);

        // Move circle
        sf::Vector2f pos = circle.getPosition();
        pos.x += speedX;
        pos.y += speedY;

        // Screen boundaries
        if (pos.x <= 0 || pos.x + 2 * circleRadius >= wWidth)
        {
            speedX = -speedX;
        }
        if (pos.y <= 0 || pos.y + 2 * circleRadius >= wHeight)
        {
            speedY = -speedY;
        }

        circle.setPosition(pos);

        // Render
        window.clear();
        if (drawCircle)
        {
            window.draw(circle);
        }
        ImGui::SFML::Render(window);
        window.display();
    }

    // Shutdown ImGui-SFML
    ImGui::SFML::Shutdown();

    return 0;
}
