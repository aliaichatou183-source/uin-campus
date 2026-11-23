
#include <cstddef>
#include <print>
#include <vector>

int main() {
    std::vector<double> notes;

    for (int i{0}; i < 10; ++i) {
        notes.push_back(10.0 + i);

        std::println("taille {:>2}, capacité {:>2}", notes.size(), notes.capacity());
    }

    std::println("Première note : {}", notes.at(0));

    // Copie indépendante du tableau
    std::vector<double> copie = notes;

    std::println("Première note de la copie : {}", copie.at(0));
}
