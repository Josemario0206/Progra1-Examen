#include "PizzaRepository.h"
#include <stdexcept>


PizzaRepository::PizzaRepository() {
    auto data = DataLoader::LoadFromFile("pizzas.txt");
    data_ = std::move(data);
}

std::vector<std::string> PizzaRepository::GetRequiredIngredients(const std::string& topping) const {
    auto it = data_.find(topping);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown topping: " + topping);
    }
    std::vector<std::string> out = it->second;
    out.push_back(BASE_1);
    out.push_back(BASE_2);
    return out;
}