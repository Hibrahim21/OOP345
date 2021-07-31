#ifndef Taxable_H
#define Taxable_H

namespace sict {

	class Taxable {
		float tax;
	public:
		Taxable(float in) { tax = in; };
		float operator()(float in) { return in * (1+tax); };
	};

	



}

#endif // !Taxable_H

