#include "menu/MenuManager.h"
#include "menu/MenuItem.h"
#include <iostream>
#include <fstream>
#include <string>
#include "linkedList/LinkedList.h"

using namespace std;

ofstream errorFile("/home/eisn/Desktop/bmstu/тисд/lr_1/error.txt");

void rearrangeList(LinkedList& list) {
    list.rearrange();
}

void logError(const string& errorMessage) {
    if (errorFile.is_open()) {
        errorFile << errorMessage << endl;
    }
}

void displayFirstElement(const LinkedList& list) {
    LinkedList::Node* current = list.getHead();
    if (current != nullptr) {
        cout << "Первый элемент списка: " << current->data << endl;
    } else {
        cout << "Список пуст." << endl;
        logError("Список пуст");
    }
}

void displayListSize(const LinkedList& list) {
    int size = list.getSize();
    cout << "Размер списка: " << size << endl;
}

void addElement(LinkedList& list) {
    int value;
    cout << "Введите элемент для добавления: ";
    cin >> value;
    list.append(value);
}

void removeElement(LinkedList& list) {
    int index;
    cout << "Введите индекс элемента для удаления: ";
    cin >> index;

    if (index < 0 || index >= list.getSize()) {
        cout << "Ошибка: Элемент с указанным индексом не существует." << endl;
        logError("Ошибка: Элемент с указанным индексом не существует.");
        return;
    }

    list.remove(index);
    cout << "Элемент успешно удален." << endl;
}

void displayList(const LinkedList& list) {
    list.display();
}

void loadSymbolsFromFile(const string& filename, LinkedList& list) {
    ifstream file("/home/eisn/Desktop/bmstu/тисд/lr_1/input.txt");
    if (!file.is_open()) {
        logError("Ошибка: Не удалось открыть файл.");
        cerr << "Не удалось открыть файл." << endl;
        return;
    }

    int value;
    while (file >> value) {
        list.append(value);
    }

    file.close();
}

void writeSymbolsToFile(const LinkedList& list) {
    ofstream myfile("/home/eisn/Desktop/bmstu/тисд/lr_1/output.txt");
    if (myfile.is_open()) {
        LinkedList::Node* current = list.getHead();
        while (current) {
            myfile << current->data << " ";
            current = current->next;
        }
        myfile.close();
    } else {
        logError("Ошибка: Не удалось открыть файл для записи.");
        cout << "Неверный путь к файлу" << endl;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    LinkedList list;
    MenuManager menuManager;

    menuManager.addMenuItem(MenuItem("Выполнить задание по варианту", [&]() { rearrangeList(list); }));
    menuManager.addMenuItem(MenuItem("Вывести первый элемент", [&]() { displayFirstElement(list); }));
    menuManager.addMenuItem(MenuItem("Вывести размер списка", [&]() { displayListSize(list); }));
    menuManager.addMenuItem(MenuItem("Добавить элемент в список", [&]() { addElement(list); }));
    menuManager.addMenuItem(MenuItem("Удалить элемент из списка", [&]() { removeElement(list); }));
    menuManager.addMenuItem(MenuItem("Вывести весь список", [&]() { displayList(list); }));
    menuManager.addMenuItem(MenuItem("Заполнение списка из файла", [&]() { loadSymbolsFromFile("input.txt", list); }));
    menuManager.addMenuItem(MenuItem("Запись списка в файл", [&]() { writeSymbolsToFile(list); }));
    menuManager.addMenuItem(MenuItem("Выход из программы", nullptr)); // Не указываем функцию для выхода

    menuManager.showMenu();

    return 0;
}