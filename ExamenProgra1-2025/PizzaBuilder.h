#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "IngredientSelector.h"
#include "HerbsRepository.h"


class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void SelectTomatoes();
    void SelectCheese();
    void SelectHerbs();
    void SelectMeat();

    TomatoesRepository tomatoRepo_;
    std::vector<std::string> selectedIngredients_;

    HerbsRepository herbRepo_;                 
    

    const std::vector<std::string> availableTomatoes_ = {"Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"};
    const std::vector<std::string> availableCheeses_ = {"Mozzarella", "Cheddar", "Parmesan", "Cream Cheese", "Gouda", "Blue Cheese", "Feta"};
    const std::vector<std::string> availableHerbs_ = { "Basil", "Parsley", "Oregano", "Thyme", "Rosemary", "Cilantro", "Sage", "Chives"};
};