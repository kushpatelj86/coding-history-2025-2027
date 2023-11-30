#include <exception>
#include <iostream>
#include <sstream>                                                                    // istringstream
#include <typeinfo>

#include "GroceryItem.hpp"
#include "GroceryList.hpp"




namespace
{
  void basicScenario()
  {
    // Let's start a grocery list
    GroceryList thingsToBuy = { { "milk"     },
                                { "hot dogs" },
                                { "eggs"     },
                                { "bread"    } };

    // Changed my mind, I want to make sure I can get eggs before running out of money so I'm going to move that to the top of my list
    thingsToBuy.moveToTop( { "eggs" } );

    // Let's see what's on the list so far
    std::cout << "My Grocery List" << thingsToBuy << "\n\n";



    // Hmm ..., no.  Need to add a few more things
    thingsToBuy += { { "bananas" },
                     { "apples"  } };




    // My roommate also has a grocery list
    GroceryList roommatesList = { { "potato chips", "Ruffles"    },
                                  { "potato chips", "Frito Lays" },
                                  { "beer",         "Bud Lite"   },
                                  { "eggs"                       },
                                  { "pretzels"                   } };

    std::cout << "My roommate's Grocery List" << roommatesList << "\n\n";

    // Let's combine the lists (if different) and go shopping
    if( thingsToBuy != roommatesList ) thingsToBuy += roommatesList;


    // Oops, forgot butter.  Let's add that right before bread.
    thingsToBuy.insert( { "butter", "Lakes 'Ole" }, thingsToBuy.find( { "bread" } ) );

    // And beer, really?  You should be studying!
    thingsToBuy.remove( { "beer", "Bud Lite" } );


    // Now let's see what's on the list
    std::cout << "Combined Grocery Lists" << thingsToBuy << "\n\n";



    // Did you get it right?
    //
    // I could construct "expectedResults" with the list of grocery items as above, but I want to exercise GroceryList's extraction
    // operator.  To do that, I could:
    //   1) read the list of grocery items from standard input and type the data at the keyboard, but that is time consuming and
    //      error prone.  That's easily handled by creating a text file with grocery item data then redirecting that text file to
    //      standard input at the command line when launching the program.  But then I would have to separately maintain that file
    //      and include it in the set of student files.  More importantly, that would prevent you from doing that in the TO-DO
    //      section below.
    //   2) open a text file directly using either command line arguments that supply the file's path and name, or hard coding the
    //      file's path and name.  But that would require using (and understanding) the standard's ifstream interface, which is easy
    //      enough given sufficient time, but I don't want to go down that rabbit hole in this course.
    //   3) create an in-memory text file (well, more accurately, an in-memory input stream) and read from there.  This allows me to
    //      exercise the extraction operator while avoiding the perils described in options 1) and 2) above.
    // So, as a design decision, let's chose option 3), create an in-memory input stream and read from there.
    //
    //                                            UPC | Brand Name   | Product Name   | Price
    //                                            ----+--------------+----------------+--------
    std::istringstream expectedResultsStream( R"( "",   "",            "eggs",          0.0
                                                  "",   "",            "milk",          0.0
                                                  "",   "",            "hot dogs",      0.0
                                                  "",   "Lakes 'Ole",  "butter",        0.0
                                                  "",   "",            "bread",         0.0
                                                  "",   "",            "bananas",       0.0
                                                  "",   "",            "apples",        0.0
                                                  "",   "Ruffles",     "potato chips",  0.0
                                                  "",   "Frito Lays",  "potato chips",  0.0
                                                  "",   "",            "pretzels",      0.0 )"   // multi-line raw string literal of grocery items
                                               );

    GroceryList expectedResults;
    expectedResultsStream >> expectedResults;

    std::cout << "\nExpected results:" << expectedResults << "\n\n"
              << "\nActual results:  " << thingsToBuy     << "\n\n"
              << "\nTest results:    " << ( thingsToBuy == expectedResults ? "PASS" : "FAIL" ) << '\n';
  }
}




int main()
{
  try
  {
    basicScenario();


    ///////////////////////// TO-DO (1) //////////////////////////////
     /// Create, manipulate, and display your own GroceryList object here.  Not looking for anything specific but don't just repeat
     /// what I've already done above.  Be imaginative and create your own story.  Maybe you're restocking a depleted food bank, or
     /// preparing for a holiday meal, or catering a banquette, or planning an all night study session, or ...  You *must* use all
     /// the functions of the GroceryList interface, including the insertion, extraction, and relational operators.  Try inserting
     /// grocery items from both the top and the bottom of the lists using the enumerated position values TOP and BOTTOM as well as
     /// indexed offsets.  Remove grocery items from the top, middle, and bottom.  Create, concatenate, rearrange, and compare
     /// several (more than two) lists. Have some fun with it!  The purpose is to show me you, as a GroceryList class consumer
     /// (i.e., the client) understand how to *use* the GroceryList.


     //I need to come up with a diet that only allows protein nothing else, I call it a gym diet
      GroceryList myProteinList = {{ "Chicken"     },{ "Cottage Cheese"     },{ "Turkey"     },{ "Fish"     },{ "Protein Powder"     }};
      std::cout << " We so far have " << myProteinList.size() << " protein items for my gym diet" << std::endl;

    //I have to get the protein powder first because I need it for pre-workout
    myProteinList.moveToTop({ "Protein Powder"     });

    //need to add few more meats
    myProteinList  += { { "Salmon" },
                     { "Bison Steak"  } };


    //all the meat proteins
    std::cout << "All the meat proteins I have so far " << myProteinList << "\n\n";

    //now we need to add plant based proteins
    GroceryList plantBasedProteinsList = { { "Lentils", "Great Value"    },
                                  { "Almonds", "Quakers" },
                                  { "Protein Cookie",         "Quest"},
                                  { "Chcikpeas"                       },
                                  { "Tofu"                   }} ;

      std::cout << "All the plant based proteins I have so far " << plantBasedProteinsList << "\n\n";

    
        
          std::cout << "All the proteins combined" << plantBasedProteinsList << "\n\n";

      // Oops, I forgot peanubutter.  Let's add that right before the almonds.
      myProteinList.insert({ "Peanut Butter", "Skippy" },myProteinList.find({ "Almonds", "Quakers" }));

      //protein cookies are you kidding me, they are unhealthy and high in added sugars
      myProteinList.remove({ "Protein Cookie",         "Quest"});

    


    //lets create a new protein list that has sugar free processed foods
    GroceryList combinedProteinList({{ "Protein Powder" },{"Trail Mix", "Nature Valley"},{"Protein Chips", "Quest"}});
    combinedProteinList.insert({ "Protein Bar" });
          std::cout << "Protein list: " << combinedProteinList << "\n\n";



    

  std::cout << "Where is Protein Powder? " << myProteinList.find({ "Protein Powder" }) << "\n\n";
      std::cout << "Now lets move everything into a copy list " << "\n\n";


    GroceryList copyProteinList;
    copyProteinList = myProteinList;
  



      std::cout << "Uh oh we have to much space, we must remove one thing " << "\n\n";
    copyProteinList.remove(copyProteinList.size() - 1);
          std::cout << "Copy list: " << copyProteinList << "\n\n";





    bool isTheSame = (copyProteinList == myProteinList);

    std::cout << "Now lets compare the copy list with the original list, Are the two lists the same? " << isTheSame << "\n\n";
    //myProteinList <=> plantBasedProteinsList;




    /////////////////////// END-TO-DO (1) ////////////////////////////
  }

  catch( const std::exception & ex )
  {
    std::cerr << "Fatal Error:  unhanded exception \"" << typeid( ex ).name() << "\"\n"
              << ex.what() << '\n';
  }
}
