#include "mycode.h"

void hello(std::istream &ist, std::ostream& ost) {
    std::string name;
    ist >> name;

    if (name.empty()) {
        ost << "Извините, имя не было введено.";
    } else {
        ost << "Привет, ";

        if (name == "Чудакин") {
            ost << "Здравствуйте, Игорь Андреевич!";
        } else {
            ost << name << "!";
        }
    }
}
