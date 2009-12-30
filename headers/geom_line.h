#ifndef GEOM_LINE_INC
#define GEOM_LINE_INC

#include "point.h"


namespace libcan {
	struct geom_line {
		//pomocna trida, co reprezentuje "cistou" usecku
		//neni to u line, protoze puvodne bylo dost oddelene, co delaly
		//ted se to trochu smazalo, ale prijde mi prehlednejsi mit to takhle nez to vsechno cpat do line.h
		point a;
		point b;
		geom_line(const point& my_a, const point& my_b);
		geom_line();
		
			//proste jenom prehodi poradi .)
		geom_line reverted() const; 
		
			//vypocita uhel, pokud ale predpokladam, ze
			// b=another.a,
			// to znamena ze vlastne pocitam uhel od obracene orientovane usecky
		libcan_float count_rev_angle(const geom_line another) const;
		
			//uhel od horizontaly
		libcan_float angle_from_x() const;
		
			//zkrati/prodlouzi to velikost na length
		geom_line normalised(const libcan_float length) const;
		
			//udela pravy uhel
		point right_angle_a(const bool clockwise, const libcan_float length) const;
		point right_angle_b(const bool clockwise, const libcan_float length) const;
		
			//udela rovnobezku, vzdalenou distance ode mne
			//vlevo / vpravo
		geom_line parallel(const bool left, const libcan_float distance) const;
	
			//prusecik s jinou useckou (muze, a casto je mimo)
		point intersection(const geom_line& another) const;
		
			//vrati ty dva bodiky, co jsou potreba pri kresleni tluste cary
			//presneji - "obal" cary je vzdycky 4uhelnik, na kazde strane 
			//usecky jsou dva body. Ty dva body ale nezalezi jenom na 
			//usecce, ale i na te sousedni. Tahle je spocita a vrati.
			//second_hint je proto, ze pokud je uhel svirany temi useckami moc maly,
			//udela se ten obal trochu jinak, kde potrebuju v jednom pripade prehodit poradi bodu
		geom_line thick_cover(const geom_line& another, const libcan_float distance, bool second_hind) const;
	};
	
}






#endif