#include "MenuManager.h"
#include <iostream>
#include <cctype>

void MenuManager::addMenuItem(MenuItem item) {
    menuItems.push_back(item);
}

void MenuManager::showMenu() {
    int choice;
    do {
        std::cout << "Меню:\n";
        for (int i = 0; i < menuItems.size(); ++i) {
            std::cout << i + 1 << ". " << menuItems[i].getLabel() << "\n";
        }
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;

        if (choice > 0 && choice <= menuItems.size()) {
            menuItems[choice - 1].execute();
        }
        else if (choice != 0) {
            std::cout << "Введите существующий пункт меню.\n";
        }
    } while (choice != 0);
}




