//#define TRACE

class Solution {
public:

    enum class Available
    {
        Yes,
        No,
        Unknown
    };

    bool canMakeRecipe(int recipeIdx, vector<string>& recipes, vector<vector<string>>& ingredients, unordered_map<string, int>& supplies, vector<Available>& availableRecipes, unordered_map<string, int>& recipesMap)
    {
        if (availableRecipes[recipeIdx] != Available::Unknown)
            return availableRecipes[recipeIdx] == Available::Yes ? true : false;

        // Assume no, in case there is a loop
        availableRecipes[recipeIdx] = Available::No;

        #ifdef TRACE
            cout << "Testing " << recipeIdx << " (" << recipes[recipeIdx] << ")" << endl;
        #endif

        for (const string& ingredient : ingredients[recipeIdx])
        {
            if (supplies.find(ingredient) == supplies.end())
            {
                auto recipe = recipesMap.find(ingredient);
                if (recipe == recipesMap.end())
                {
                    availableRecipes[recipeIdx] = Available::No;
                    return false;
                }

                const int idx = recipe->second;
                #ifdef TRACE
                    cout << " - Needs " << idx << endl;
                #endif
                if (!canMakeRecipe(idx, recipes, ingredients, supplies, availableRecipes, recipesMap))
                {
                    availableRecipes[recipeIdx] = Available::No;
                    return false;
                }
            }
        }

        availableRecipes[recipeIdx] = Available::Yes;
        return true;
    }

    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies)
    {
        vector<string> available;

        unordered_map<string, int> suppliesMap;
        for (const string& supply : supplies)
        {
            suppliesMap[supply] = 1;
        }

        unordered_map<string, int> recipesMap;
        for (int i=0; i<recipes.size(); ++i)
        {
            recipesMap[recipes[i]] = i;
        }

        vector<Available> availableRecipes(recipes.size(), Available::Unknown);

        for (int i=0; i<recipes.size(); ++i)
        {
            if (canMakeRecipe(i, recipes, ingredients, suppliesMap, availableRecipes, recipesMap))
                available.push_back(recipes[i]);
        }

        return available;
    }
};
