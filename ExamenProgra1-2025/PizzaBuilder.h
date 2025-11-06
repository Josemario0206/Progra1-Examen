#pragma once
#include <vector>
#include <string>
#include "TomatoesRepository.h"
#include "IngredientSelector.h"
#include "MeatsRepository.h"
#include "CheeseRepository.h"
#include "HerbsRepository.h"


class PizzaBuilder {
public:
    PizzaBuilder();

    void BuildPizza();
    void DisplayFinalPizza() const;

private:
    void SelectTomatoes();
    void SelectCheese();
    void SelectHerb();
    void SelectMeats();
    void SelectHerbs();
    void SelectMeat();

    TomatoesRepository tomatoRepo_;
    MeatsRepository meatsRepo_;

    std::vector<std::string> selectedIngredients_;

	CheeseRepository cheeseRepo_;

    HerbsRepository herbRepo_;                 
    

    const std::vector<std::string> availableTomatoes_ = {"Cherry", "Roma", "Beefsteak", "Heirloom", "Grape"};
    const std::vector<std::string> availableCheeses_ = {"Mozzarella", "Cheddar", "Parmesan", "Cream Cheese", "Gouda", "Blue Cheese", "Feta"};
};    const std::vector<std::string> availableMeats_ = {
        "Pepperoni", "Bacon", "Chicken", "Shrimp", "Mignon", "Ham", "Sausage", "Prosciutto"
};
    const std::vector<std::string> availableHerbs_ = { "Basil", "Parsley", "Oregano", "Thyme", "Rosemary", "Cilantro", "Sage", "Chives"};
};
