#ifndef MEATSREPOSITORY_H
#define MEATSREPOSITORY_H

#include <string>
#include <map>

class MeatsRepository {
public:
    MeatsRepository(const std::string& dataFile = "meats.txt");

    int GetAvailableQuantity(const std::string& ingredientType) const;
    void UpdateQuantity(const std::string& ingredientType, int newQuantity);

private:
    void LoadFromFile();
    void SaveToFile() const;

private:
    std::string dataFile_;
    std::map<std::string, int> quantities_;
};

#endif // MEATSREPOSITORY_H
#pragma once
