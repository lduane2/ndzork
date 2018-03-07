#include "include/game/ndzork.hpp"
#include <iostream>

int main() {
    std::cout << "You are a Notre Dame student and it is the last week of April. The South Bend permacloud has stayed looming over the campus for months now, leaving a never-ending impression of winter. The sun hasn’t been seen since the fall semester and campus life is deteriorated. You start wondering if there’s a way to lift this curse before finals week where you think most students will lose their minds. You begin wandering around campus, looking for a hint, a sign, any sort of clue to help you fix your school. Going from building to building, you find nothing. Exhausted, stressed, and depressed from your lack of vitamin D, you sit down on the ring of stones surrounding Jesus and toss him a prayer. Unexpectedly, you slip from your seat as the stones are loose. You look at the stones and read.. " << std::endl << "il y a un moyen d\'éclairer le monde" << std::endl << "which oughly translates to: \"there is one way to light the world\"" << std::endl << "Luckily, that one semester of French you took to fulfill a college requirement hasn’t completely left you and you finally see the light at the end of the tunnel. " << std::endl << std::endl << "You can save the school." << std::endl << std::endl;
	NDZork ndzork;
	ndzork.loop();
	return 0;
}
