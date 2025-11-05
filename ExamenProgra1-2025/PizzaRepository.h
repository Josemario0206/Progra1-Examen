#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "DataLoader.h"

class PizzaRepository {
public:
    PizzaRepository();

    // Returns topping-specific + base ingredients.
    std::vector<std::string> GetRequiredIngredients(const std::string& topping) const;

private:
    std::unordered_map<std::string, std::vector<std::string>> data_;    
    static constexpr const char* BASE_1 = "Salsa de Tomate";
    static constexpr const char* BASE_2 = "Mozzarella";
};