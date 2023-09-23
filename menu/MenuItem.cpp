// MenuItem.cpp
#include "MenuItem.h"

MenuItem::MenuItem(const std::string& label, std::function<void()> action)
        : label(label), action(action) {}

std::string MenuItem::getLabel() const {
    return label;
}

void MenuItem::execute() const {
    if (action) {
        action();
    }
}
