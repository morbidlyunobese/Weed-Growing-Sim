#include <iostream>

// preparing functions in global scope
void weedStock(float gs, float seedz);
float grow(float seedz, float gs);
float sell(float gs, float seedz);

float seeds = 1;

int main()
{
    int choice = 0;
    float grams = 30;

    std::cout << "WWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW\n";
    std::cout << "WWWWWWWWWWWWWWWWWWWW MARY JANE WWWWWWWWWWWWWWWWWWWW\n";

    do {
        std::cout << "(1) Inventory | (2) Grow | (3) Sell | (4) Exit\n";
        std::cin >> choice;

        switch (choice) {
        case 1:
            weedStock(grams, seeds);
            break;

        case 2:
            grams = grow(seeds, grams); // assign value to main
            break;

        case 4:
            grams -= sell(grams, seeds);
            weedStock(grams, seeds);
            break;

        default:
            std::cout << "Invalid Choice.\n";
        }

    } while (choice != 5);

    std::cout << "You have exited the game. Your data has been lost :(";

    return 0;
}

void weedStock(float gs, float seedz) {
    std::cout << "Your Stock: " << round(gs) << " gram(s).\n";
    std::cout << "Your Seeds: " << round(seedz) << " seed(s).\n";
}

float grow(float seedz, float gs) {
    srand(time(0));
    float yield = rand() % 56 + 16;
    int growSeeds;

    std::cout << "You have " << round(seedz) << " seeds. How many to grow: ";
    std::cin >> growSeeds;

    if (growSeeds > 0 && growSeeds <= seedz) {
        float harvest = growSeeds - seedz;
        float totalGs = yield + gs;
        seeds = harvest;
        std::cout << "You have " << harvest << " seeds remaining and " << totalGs << " g's left.\n";
        return totalGs; // return updated value of grams
        return harvest; // return updated value of seeds
    }
    else {
        std::cout << "You don't have that many seeds.\n";
        return gs; // return the original value of grams
        return seedz; // return the original value of seeds
    }
}

float sell(float gs, float seedz) {
    float gramz = 0;

    std::cout << "Enter how many grams to sell: ";
    std::cin >> gramz;
    std::cout << "\n";

    if (gramz > 0 && gramz <= gs) {
        gs -= gramz;
        return gramz;
    }
    else if (gs == 0) {
        std::cout << "You lost because you ran out of weed. \n";
    }
    else {
        std::cout << "Invalid amount :(. You don't have that much weed homie.\n";
    }
    return 0;
}

// make a buy function for 10 grams = 1 seed
