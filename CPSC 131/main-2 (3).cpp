#include <cmath>                                                      // abs(), pow()
#include <compare>                                                    // weak_ordering
#include <cstddef>
#include <iomanip>                                                    // quoted()
#include <iostream>
#include <string>
#include <vector>
#include "GroceryItem.hpp"
#include <cctype>                                           // move()

#include <type_traits>                                                // is_floating_point_v, common_type_t
#include <utility> 

int main()
{
    std::cout << std::fixed << std::setprecision(2) << "Welcome to Kroger.  Place grocery items into your shopping cart by entering each item's information." << std::endl;
    std::cout << "  enclose string entries in quotes, separate fields with comas" << std::endl;
    std::cout <<"Enter CTL-Z (Windows) or CTL-D (Linux) to quit" << std::endl;
    std::cout << std::endl;
std::vector<GroceryItem *> items;
        
         GroceryItem item;


std::cout << "Enter UPC, Product Brand, Product Name, and Price(enclose string entries in quotes, separate fields with comas and entrie that have spaces with quotes)" << std::endl;
std::cout << "Item Added: ";

    while((std::cin >> item))
    {
        
      items.push_back(new GroceryItem(std::move(item)));
     
        std::cout << "Enter UPC, Product Brand, Product Name, and Price(enclose string entries in quotes, separate fields with comas and entrie that have spaces with quotes)" << std::endl;
        std::cout << "Item Added: ";

    }

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout <<"Here is an itemized list of the items in your shopping cart: " << std::endl;
    for(auto i = items.size(); i >= 1;)
    {
        --i;
        std::cout << *items[i] << std::endl;
    }

   /*for(std::size_t i = items.size(); i >= 1;)
    {
        --i;
        std::cout << *items[i] << std::endl;
    }*/

    std::cout << std::endl;
    std::cout << std::endl;

     std::cout << std::endl;
    std::cout << std::endl;


    

    



    return 0;
}




