#ifndef KVList_H
#define KVList_H
#include<iostream>


namespace sict {
	


template<typename T>
class KVList {
		T* kvlist_;
		size_t len;
		size_t qty;
	public:
		KVList() { kvlist_ = nullptr; len = 0; qty = 0; };
		KVList(int i) {
			if (i<0) {
				kvlist_ =nullptr; len = 0; qty = 0;
				throw std::string("negative size");
				
			}
			else
			{
				kvlist_ = new T[i];
				len = i;
				qty = 0;
				
			}
		};
		~KVList() {		
			delete[]kvlist_;
			kvlist_ = nullptr;
		}

		KVList(KVList&& in)noexcept { 
			if (this != &in) {
				
				//delete[]kvlist_;
				len = in.len;
				qty = in.qty;
				
				kvlist_ = in.kvlist_;
				
				in.kvlist_ = nullptr;
				in.qty = 0;
				in.len = 0;
			}
		};

		const T& operator[](size_t i) const {
			if (i > qty) { throw  "out of bond"; }
			else
			{
				return kvlist_[i];

			}
		};

		template<typename F>void display(std::ostream& os, F f)const {
			
				for (size_t i = 0; i < qty; i++)
				{
					kvlist_[i].display(os, f);
				}				
			
		}
	void	push_back(const T& t){
			
		if (qty < len){
			kvlist_[qty] = t;
			qty++;
				}
			}

};







}

#endif // !KVList_H

