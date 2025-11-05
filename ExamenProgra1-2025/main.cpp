#include "DataLoader.h"
#include "PizzaRepository.h"
#include <iostream>
#include <vector>

int main() {
    try {

        PizzaRepository repo;
        
        std::vector<std::string> test = {
            "Margherita", "San Remo", "Sublime", "Calabria", "Firenze", "Not a topping"
        };

        for (const auto& topping : test) {
            std::cout << "----------------\n";
            std::cout << "Topping: " << topping << "\n";
            try {
                for (const auto& ing : repo.GetRequiredIngredients(topping)) {
                    std::cout << "- " << ing << "\n";
                }
            } catch (const std::invalid_argument& ex) {
                std::cout << "Error: " << ex.what() << "\n";
            }
        }
    } catch (const std::exception& ex) {
        std::cerr << "Fatal error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}