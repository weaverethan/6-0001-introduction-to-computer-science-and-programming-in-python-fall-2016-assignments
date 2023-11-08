#include <iostream>
namespace Monster{
	enum MonsterType{
    		orc,
    		goblin,
    		troll,
    		orge,
    		skeleton,
	};
}

int main()
{
	Monster::MonsterType monster{ Monster::troll };

    if (monster == Monster::troll) // if the shirt is blue
        std::cout << "its a troll";
    else
        std::cout << "its not a troll";

    return 0;
}
