#include <limits>
#include<iostream>
using namespace std;
#include <cctype> 
#include <array>
using std::array;
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>


struct Recipe {
    string name;
    vector<string> ingredients;
    vector<string> steps;
};

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void addRecipe(vector<Recipe>& collection) {
    Recipe r;
    cout << "Enter recipe name: ";
    getline(cin, r.name);

    int numIngredients;
    cout << "How many ingredients? ";
    while (!(cin >> numIngredients) || numIngredients < 0) {
        cout << "Invalid input. Enter a non-negative number: ";
        clearInput();
    }
    clearInput();

    for (int i = 0; i < numIngredients; ++i) {
        string ingredient;
        cout << "Enter ingredient " << i + 1 << ": ";
        getline(cin, ingredient);
        r.ingredients.push_back(ingredient);
    }

    int numSteps;
    cout << "How many steps? ";
    while (!(cin >> numSteps) || numSteps < 0) {
        cout << "Invalid input. Enter a non-negative number: ";
        clearInput();
    }
    clearInput();

    for (int i = 0; i < numSteps; ++i) {
        string step;
        cout << "Enter step " << i + 1 << ": ";
        getline(cin, step);
        r.steps.push_back(step);
    }

    collection.push_back(r);
    cout << "Recipe added successfully!\n";
}

void displayRecipes(const vector<Recipe>& collection) {
    if (collection.empty()) {
        cout << "No recipes in the collection.\n";
        return;
    }

    for (size_t i = 0; i < collection.size(); ++i) {
        cout << "\nRecipe #" << i + 1 << ": " << collection[i].name << "\n";
        cout << "Ingredients:\n";
        for (const auto& ingredient : collection[i].ingredients) {
            cout << " - " << ingredient << "\n";
        }
        cout << "Steps:\n";
        for (size_t j = 0; j < collection[i].steps.size(); ++j) {
            cout << " " << j + 1 << ". " << collection[i].steps[j] << "\n";
        }
    }
}

void searchByName(const vector<Recipe>& collection) {
    string query;
    cout << "Enter recipe name to search: ";
    getline(cin, query);

    bool found = false;
    for (const auto& recipe : collection) {
        if (recipe.name == query) {
            cout << "Found recipe: " << recipe.name << "\n";
            cout << "Ingredients:\n";
            for (const auto& ing : recipe.ingredients)
                cout << " - " << ing << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "No recipe found with the name \"" << query << "\".\n";
    }
}

void searchByIngredient(const vector<Recipe>& collection) {
    string query;
    cout << "Enter ingredient to search for: ";
    getline(cin, query);

    bool found = false;
    for (const auto& recipe : collection) {
        if (find(recipe.ingredients.begin(), recipe.ingredients.end(), query) != recipe.ingredients.end()) {
            cout << "Found in recipe: " << recipe.name << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No recipes found with the ingredient \"" << query << "\".\n";
    }
}

void removeRecipe(vector<Recipe>& collection) {
    if (collection.empty()) {
        cout << "No recipes to remove.\n";
        return;
    }

    displayRecipes(collection);
    int index;
    cout << "Enter recipe number to remove (1 - " << collection.size() << "): ";
    while (!(cin >> index) || index < 1 || index > static_cast<int>(collection.size())) {
        cout << "Invalid index. Try again: ";
        clearInput();
    }
    clearInput();

    collection.erase(collection.begin() + index - 1);
    cout << "Recipe removed successfully!\n";
}

void showStats(const vector<Recipe>& collection) {
    cout << "\n--- Recipe Collection Statistics ---\n";
    cout << "Total Recipes: " << collection.size() << "\n";

    int totalIngredients = 0;
    int totalSteps = 0;
    for (const auto& r : collection) {
        totalIngredients += r.ingredients.size();
        totalSteps += r.steps.size();
    }

    cout << "Average Ingredients per Recipe: "
         << (collection.empty() ? 0 : static_cast<double>(totalIngredients) / collection.size()) << "\n";
    cout << "Average Steps per Recipe: "
         << (collection.empty() ? 0 : static_cast<double>(totalSteps) / collection.size()) << "\n";
}

void menu() {
    cout << "\n=== Recipe Manager ===\n";
    cout << "1. Add Recipe\n";
    cout << "2. Display All Recipes\n";
    cout << "3. Search Recipe by Name\n";
    cout << "4. Search Recipe by Ingredient\n";
    cout << "5. Remove a Recipe\n";
    cout << "6. View Collection Statistics\n";
    cout << "0. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    vector<Recipe> recipeCollection;
    int choice;

    do {
        menu();
        while (!(cin >> choice)) {
            cout << "Invalid input. Try again: ";
            clearInput();
        }
        clearInput();

        switch (choice) {
            case 1:
                addRecipe(recipeCollection);
                break;
            case 2:
                displayRecipes(recipeCollection);
                break;
            case 3:
                searchByName(recipeCollection);
                break;
            case 4:
                searchByIngredient(recipeCollection);
                break;
            case 5:
                removeRecipe(recipeCollection);
                break;
            case 6:
                showStats(recipeCollection);
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
