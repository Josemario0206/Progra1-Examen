#include "HerbsRepository.h"
#include <stdexcept>
#include <iostream>
HerbsRepository::HerbsRepository() {
    // Cargar datos de hierbas (puede venir de archivo si lo prefieres)
    auto data = DataLoader::LoadFromFile("herbs.txt");
    data_ = std::move(data);
    std::cout << "Cargando hierbas... cantidad de tipos: " << data_.size() << std::endl;

}

int HerbsRepository::GetAvailableQuantity(const std::string& herbType) const {
    auto it = data_.find(herbType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown herb type: " + herbType);
    }
    return std::stoi(it->second[0]);
}

void HerbsRepository::UpdateQuantity(const std::string& herbType, int newQuantity) {
    auto it = data_.find(herbType);
    if (it == data_.end()) {
        throw std::invalid_argument("Unknown herb type: " + herbType);
    }
    it->second[0] = std::to_string(newQuantity);
}
