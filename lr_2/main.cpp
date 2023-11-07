#include "MenuManager.h"
#include <iostream>
#include <fstream>
#include "Tree.h"
#include "Exceptions.h"

using namespace std;

Tree* tr = nullptr;
string expression = "";

void loadExpression() {
    int fileIter = 0;
    ifstream fin;
    fin.open("../input.txt");
    string *arr {new string[0]{}};
    string str;
    try {
        if(!fin.is_open()) {
            cout << "mistake file";
        } else {
            while (!fin.eof()) {
                fin >> str;
                expression += str;
            }
        }
    } catch (string error) {

    }
    fin.close();
    delete[] arr;

    tr = buildExpressionTree(expression);
    cout << "Success loading\n";
}



void PrintTree() {
    if (tr == nullptr) {
        EmptyException("Tree is empty, please load it\n");
    } else {
        PrintAllTree(tr);
    }
}

void prefics() {
    if (tr == nullptr) {
        EmptyException("Tree is empty, please load it\n");
    } else {
        std::ofstream fout;
        fout.open("../output.txt", std::ios_base::app);
        if (fout.is_open()) {
            fout << "\n";
            fout << PreficsTriversial(tr);
            fout << '\n';
        }
        fout.close();
    }
}

void infics() {
    if (tr == nullptr) {
        EmptyException("Tree is empty, please load it\n");
    } else {
        std::ofstream fout;
        fout.open("../output.txt", std::ios_base::app);
        if (fout.is_open()) {
            fout << "\n";
            fout << InficsTriversial(tr);
            fout << '\n';
        }
        fout.close();
    }
}

void postfics() {
    if (tr == nullptr) {
        EmptyException("Tree is empty, please load it\n");
    } else {
        std::ofstream fout;
        fout.open("../output.txt", std::ios_base::app);
        if (fout.is_open()) {
            fout << "\n";
            fout << PostficsTriversial(tr);
            fout << '\n';
        }
        fout.close();
    }
}

void deleteNode() {
    string data;
    cout << "Enter a node you want to delete: ";
    cin >> data;
    DeleteNode(tr, data);
}

int main() {
    MenuManager menuManager;
    menuManager.addMenuItem(MenuItem("Load expression from file", loadExpression));
    menuManager.addMenuItem(MenuItem("Print tree", PrintTree));
    menuManager.addMenuItem(MenuItem("Infics traversal", infics));
    menuManager.addMenuItem(MenuItem("Prefics traversal", prefics));
    menuManager.addMenuItem(MenuItem("Postfics traversal", postfics));
    menuManager.addMenuItem(MenuItem("Delete Node", deleteNode));

    menuManager.showMenu();

    return 0;
}