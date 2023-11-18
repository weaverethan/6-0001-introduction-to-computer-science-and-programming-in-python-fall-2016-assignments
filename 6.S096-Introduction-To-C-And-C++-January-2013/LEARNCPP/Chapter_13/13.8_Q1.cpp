#include <iostream>




struct AdStat{
	int watched{};
	double clicked{};
	double earnings{};
};


double calcEarnings(AdStat stats){
	return stats.watched*stats.clicked*stats.earnings;
}



void printStats(AdStat stats){
	std::cout << stats.watched << " ads where watched\n";
	std::cout << stats.clicked << '%' << " of users clicked on an ad\n";
	std::cout << "you made $" << stats.earnings << " per click\n";
	std::cout << "in total you made $" << calcEarnings(stats) << "\n";
}




int main(){
	AdStat today{5793, 0.23, 0.05};
	printStats(today);
	return 0;
}
