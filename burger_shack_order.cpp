#include "util.h"
#include <iostream>
#include <map>
#include <string>

int main()
{
    /** assume desired menu prices:
     * Burgers cost $3.99
     * Fries cost $1.79
     * Soft drinks cost $0.99
     * Sales tax is 5%
     */ 
    
    
    double burger = 3.99, fries = 1.79, soda = 0.99, salesTax = 0.05, totalCost = 0;
    int totalItems = 0;
    
    cout << "Welcome to Chai's Burgers. What would you like to order?\n\n";
    
    map<string, map<double, int>> order;
    
    order["burger"][burger] = readInt("How many burgers would you like? \n");
    order["fries"][fries] = readInt("How many orders of fries? \n");
    order["soda"][soda] = readInt("And sodas? \n");
    
    // ITERATOR
    map<string, map<double, int>>::iterator it = order.begin();
 
    // ITERATE OUTER
    for (auto it = order.begin(); it != order.end(); ++it) {
        // std::cout << "Key: " << it->first << std::endl;

        // ITERATE INNER
        for (auto inner_it = it->second.begin(); inner_it != it->second.end(); ++inner_it) {
            // std::cout << "Inner Key: " << inner_it->first << ", Inner Value: " << inner_it->second << std::endl;
            totalItems += inner_it->second;
            totalCost += inner_it->first * inner_it->second;
        }
    }
    
    cout << "\nYour order for " << totalItems <<" items:\n";
    cout << "Subtotal: $" << totalCost << "\nTax: $" << salesTax*totalCost << "\nTotal: $" << (1+salesTax)*totalCost;
    
    return 0;
}
