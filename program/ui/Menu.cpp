#include "Menu.h"

void Menu::MainMenu()
{
	system("clear");
	std::cout << "Main menu: " << std::endl;
	std::cout << "1. Render" << std::endl;
	std::cout << "2. Add object" << std::endl;
	std::cout << "0. Exit" << std::endl;

	int choice = 0;

	std::cin >> choice;

	switch (choice) {
	case 1:
		Render();
		break;
	case 2:
		AddObject();
		break;
	case 0:
		return;
	default:
		std::cout << "Wrong option!\n";
		system("pause");
		break;
	}
	MainMenu();
}
void Menu::Render()
{
	system("clear");
	std::cout << "Render: " << std::endl;
	std::cout << "1. Render all" << std::endl;
	std::cout << "0. Back" << std::endl;

	auto choice = 0;
	std::cin >> choice;
	switch (choice)	{
	case 0:
		return;
	case 1:
		RenderObjects();
		break;
	default:
		std::cout << "Wrong option!" << std::endl;
		system("pause");
		break;
	}
	Render();
}

void Menu::RenderObjects() {
	system("clear");
    tracer.Render();
}


void Menu::AddObject() {
	system("clear");
	std::cout << "Main menu: " << std::endl;
	std::cout << "1. Add plane" << std::endl;
	std::cout << "2. Add triangle" << std::endl;
	std::cout << "3. Add sphere" << std::endl;
	std::cout << "4. Add light" << std::endl;
	std::cout << "5. Add default scene" << std::endl;
	std::cout << "0. Back" << std::endl;

	int choice = 0;
	std::cin >> choice;

	switch (choice) {
	case 1:
		AddPlane();
		break;
	case 2:
		AddTriangle();
		break;
	case 3:
		AddSphere();
		break;
    case 4:
        AddLight();
        break;
    case 5:
        AddDefault();
        break;
	case 0:
		return;
	default:
		std::cout << "Wrong option!\n";
		system("pause");
		break;
	}
	AddObject();
}

void Menu::AddSphere()
{
	system("clear");
	std::cout << "Set sphere center: " << std::endl;
	std::cout << "\n" << "Center X: ";
	std::cin >> center.x;
	std::cout << "\n" << "Center Y: ";
	std::cin >> center.y;
	std::cout << "\n" << "Center Z: ";
	std::cin >> center.z;
	std::cout << "Set sphere radius: " << std::endl;
	std::cout << "\n" << "Radius: ";
	std::cin >> radius;
	std::cout << "Set sphere color: " << std::endl;
	std::cout << "\n" << "Color.Red: ";
	std::cin >> color.x;
	std::cout << "\n" << "Color.Green: ";
	std::cin >> color.y;
	std::cout << "\n" << "Color.Blue: ";
	std::cin >> color.z;

    tracer.AddSphere(center, radius, color);
}


void Menu::AddTriangle()
{
	system("clear");
	std::cout << "Set triangle points: " << std::endl;
	std::cout << "\n" << "Point p0.x: ";
	std::cin >> p0.x;
	std::cout << "\n" << "Point p0.y: ";
	std::cin >> p0.y;
	std::cout << "\n" << "Point p0.z: ";
	std::cin >> p0.z;
	std::cout << "\n" << "Point p1.x: ";
	std::cin >> p1.x;
	std::cout << "\n" << "Point p1.y: ";
	std::cin >> p1.y;
	std::cout << "\n" << "Point p1.z: ";
	std::cin >> p1.z;
	std::cout << "\n" << "Point p2.x: ";
	std::cin >> p2.x;
	std::cout << "\n" << "Point p2.y: ";
	std::cin >> p2.y;
	std::cout << "\n" << "Point p2.z: ";
	std::cin >> p2.z;
	std::cout << "Set triangle color: " << std::endl;
	std::cout << "\n" << "Color.Red: ";
	std::cin >> color.x;
	std::cout << "\n" << "Color.Green: ";
	std::cin >> color.y;
	std::cout << "\n" << "Color.Blue: ";
	std::cin >> color.z;

    tracer.AddTriangle(p0, p1, p2, color);

}
void Menu::AddPlane()
{
	system("clear");
	std::cout << "Set plane center: " << std::endl;
	std::cout << "\n" << "Center X: ";
	std::cin >> center.x;
	std::cout << "\n" << "Center Y: ";
	std::cin >> center.y;
	std::cout << "\n" << "Center Z: ";
	std::cin >> center.z;
	std::cout << "Set plane normal: #default ex.(0, -1, 0)" << std::endl;
	std::cout << "\n" << "Normal X: ";
	std::cin >> normal.x;
	std::cout << "\n" << "Normal Y: ";
	std::cin >> normal.y;
	std::cout << "\n" << "Normal Z: ";
	std::cin >> normal.z;
	std::cout << "Set plane color: " << std::endl;
	std::cout << "\n" << "Color.Red:  ";
	std::cin >> color.x;
	std::cout << "\n" << "Color.Green: ";
	std::cin >> color.y;
	std::cout << "\n" << "Color.Blue: ";
	std::cin >> color.z;

    tracer.AddPlane(center, normal, color);
}
void Menu::AddLight() {
    system("clear");
    std::cout << "Set light center: " << std::endl;
    std::cout << "\n" << "Center X: ";
    std::cin >> center.x;
    std::cout << "\n" << "Center Y: ";
    std::cin >> center.y;
    std::cout << "\n" << "Center Z: ";
    std::cin >> center.z;
    std::cout << "Set light color: " << std::endl;
    std::cout << "\n" << "Color.Red: ";
    std::cin >> color.x;
    std::cout << "\n" << "Color.Green: ";
    std::cin >> color.y;
    std::cout << "\n" << "Color.Blue: ";
    std::cin >> color.z;

    tracer.AddLight(center, color);
}
void Menu::AddDefault() {
    system("clear");
    std::cout << "Objects added. " << std::endl;

    tracer.AddSphere(Vector(2, 2, 25), 10, Vector(10, 10, 255));
    tracer.AddTriangle(Vector(-3, 0, 4), Vector(-2, 5, 5), Vector(3, 3, 2), Vector(255, 50, 0));
    tracer.AddPlane(Vector(0, -25, 0), Vector(0, -1, 0), Vector(150, 150, 150));
    tracer.AddLight(Vector(8, 3, 5), Vector(200, 200, 200));
}