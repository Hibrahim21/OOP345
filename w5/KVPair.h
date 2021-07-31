#ifndef KVPair_H
#define KVPair_H
#include<string>
#include<iostream>
extern int behnam;
namespace sict {

	template<typename K,typename V>
	class KVPair {
		K key;
		V val;
	public:
		KVPair() { this->key = K(); this->val = V(); };
		KVPair(const K& i, const V& j) { key = i; val = j; };
		template<typename F>void display(std::ostream& os, F f)const {
			K temp1 = K();
			if (this->key != temp1)
			{
				os << std::left << std::setw(10) << key << " : "  <<std::right<<std::setw(10)<<val+5 << std::setw(10)<<f(val) << std::endl;
		
			}
		}
    };







}

#endif // !KVPair

