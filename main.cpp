#include "plane.h"
 
int main () {
	glib::plane<bool> kk(10,20,30,50,true);
	glib::plane<int> kl(kk,888);
	
	kl.set(15,40,777);
	std::cout<<kl.get(15,40)<<"\n";
	std::cout<<kl.first_non_zero()<<kl.last_non_zero()<<kl.most_left(40)<<kl.most_right(40)<<kl.most_top_left()<<kl.most_down_right()<<"\n";
	
	kl.get_row(40);
	
	glib::plane<int> klk;
	klk = kl;
	
	klk = klk.move(11,31);
	std::cout<<klk.get(15,40)<<"\n";
	std::cout<<klk.first_non_zero()<<klk.last_non_zero()<<klk.most_left(40)<<klk.most_right(40)<<kl.most_top_left()<<kl.most_down_right()<<"\n";
	
	kl.add(klk);
	
	std::cout<<kl.get(15,40)<<"\n";
	std::cout<<kl.first_non_zero()<<kl.last_non_zero()<<kl.most_left(40)<<kl.most_right(40)<<kl.most_top_left()<<kl.most_down_right()<<"\n";
	
	return 0;
}