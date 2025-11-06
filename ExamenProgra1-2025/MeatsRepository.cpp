#include "MeatsRepository.h"
#include <fstream>
#include <iostream>

MeatsRepository::MeatsRepository(const std::string& dataFile)
    : dataFile_(dataFile) {
    LoadFromFile();
}

void MeatsRepository::LoadFromFile() {
    std::ifstream file(dataFile_);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo " << dataFile_ << std::endl;
        return;
    }

    std::string ingredient;
    int quantity;
    quantities_.clear();

    while (file >> ingredient >> quantity) {
        quantities_[ingredient] = quantity;
    }

    file.close();
}

void MeatsRepository::SaveToFile() const {
    std::ofstream file(dataFile_);
    if (!file.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo para guardar " << dataFile_ << std::endl;
        return;
    }

    for (const auto& pair : quantities_) {
        file << pair.first << " " << pair.second << std::endl;
    }

    file.close();
}

int MeatsRepository::GetAvailableQuantity(const std::string& ingredientType) const {
    auto it = quantities_.find(ingredientType);
    if (it != quantities_.end()) {
        return it->second;
    }
    return 0;
}

void MeatsRepository::UpdateQuantity(const std::string& ingredientType, int newQuantity) {
    auto it = quantities_.find(ingredientType);
    if (it != quantities_.end()) {
        quantities_[ingredientType] = newQuantity;
        SaveToFile();
    }
    else {
        std::cerr << "Error: ingrediente no encontrado: " << ingredientType << std::endl;
    }
}
