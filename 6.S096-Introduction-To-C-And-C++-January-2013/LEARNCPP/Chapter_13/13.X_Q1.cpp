#include <iostream>



enum class MonsterType{
	orge,
	dragon,
	orc,
	giantspider,
	slime,
};

struct Monster{
	MonsterType monstertype{};
	int health{};
	std::string name{};	

};


std::string_view monsterTypeString(MonsterType monstertype){
	using enum MonsterType;
	switch(monstertype){
		case orge: return "Orge";
		case dragon: return "Dragon";
		case orc: return "Orc";
		case giantspider: return "Giant Spider";
		case slime: return "Slime";
		default: return "NA";
	}
}


void printMonster(Monster monster){

	std::cout << "this " << monsterTypeString(monster.monstertype) << " is named ";
       	std::cout << monster.name << " and has " << monster.health << " health\n";	


}


int main(){
	Monster Torg{MonsterType::orge, 145, "Torg"};
	Monster Blurp{MonsterType::slime, 23, "Blurp"};

	printMonster(Torg);
	printMonster(Blurp);
	return 0;
}
