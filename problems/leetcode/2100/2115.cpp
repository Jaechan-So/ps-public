// 2115. Find All Possible Recipes from Given Supplies
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/

using namespace std;

#include <set>
#include <string>
#include <vector>

class Solution {
public:
  vector<string> findAllRecipes(vector<string> &recipes,
                                vector<vector<string>> &ingredients,
                                vector<string> &supplies) {
    vector<bool> recipePossibilities(recipes.size(), false);
    vector<vector<bool>> ingredientPossibilities;
    for (vector<string> &ingredient : ingredients) {
      ingredientPossibilities.push_back(vector<bool>(ingredient.size(), false));
    }

    set<string> possibleSupplies;
    for (string &supply : supplies) {
      possibleSupplies.insert(supply);
    }

    bool isNeedContinue = true;
    while (isNeedContinue) {
      isNeedContinue = false;

      for (int i = 0; i < recipes.size(); i++) {
        if (recipePossibilities[i]) {
          continue;
        }

        bool isRecipePossible = true;
        for (int j = 0; j < ingredientPossibilities[i].size(); j++) {
          bool isPreviousPossible = ingredientPossibilities[i][j];
          if (!isPreviousPossible) {
            bool isPossibleNow = possibleSupplies.find(ingredients[i][j]) !=
                                 possibleSupplies.end();
            ingredientPossibilities[i][j] = isPossibleNow;
            isRecipePossible &= isPossibleNow;
          }
        }

        if (isRecipePossible) {
          possibleSupplies.insert(recipes[i]);
          recipePossibilities[i] = true;
          isNeedContinue = true;
        }
      }
    }

    vector<string> possibleRecipes;
    for (int i = 0; i < recipes.size(); i++) {
      if (recipePossibilities[i]) {
        possibleRecipes.push_back(recipes[i]);
      }
    }

    return possibleRecipes;
  }
};
