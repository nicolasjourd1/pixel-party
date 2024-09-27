#include <fstream>
#include <iostream>
#include <string>

#include "raylib.h"
#include "json/reader.h"
#include "json/value.h"

int main()
{
    const int screen_width = 800;
    const int screen_height = 450;

    InitWindow(screen_width, screen_height, "Pixel Party");
    SetTargetFPS(60);

    Json::Value root;
    Json::CharReaderBuilder builder;
    std::string errs;

    std::ifstream lang_file("./ressources/lang/fr-FR.json", std::ifstream::binary);
    if (!lang_file.is_open())
    {
        std::cerr << "Erreur lors de l'ouverture du fichier JSON" << std::endl;
        return 1;
    }

    if (!Json::parseFromStream(builder, lang_file, &root, &errs))
    {
        std::cerr << "Erreur de parsing: " << errs << std::endl;
        return 1;
    }

    std::string msg = root["WELCOME_MESSAGE"].asString();

    while (!WindowShouldClose())
    {
        BeginDrawing();

        ClearBackground(RAYWHITE);
        DrawText(msg.c_str(), 190, 200, 20, LIGHTGRAY);
        DrawText("Nouvelle branche", 190, 150, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
