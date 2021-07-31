#ifndef SICT_DATA_TABLE_H
#define SICT_DATA_TABLE_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <utility>
#include <fstream>
#include <numeric>
#include <algorithm>

extern int FW;
extern int ND;

namespace sict {
	template<typename T>
	class DataTable {
		std::vector<T> x_val;
		std::vector<T> y_val;

		T mean() const {
			T total = 0;
			total += std::accumulate(y_val.begin(), y_val.end(), 0.0000);
			return total / y_val.size();
		}

		T sigma() const {
			T sigma = 0;
			T avg = mean();
			std::vector<T> n(y_val.size());

			std::transform(y_val.begin(), y_val.end(), n.begin(), [&](auto i) {
				return pow(i - avg, 2);
			});

			sigma += std::accumulate(n.begin(), n.end(), 0.0000);

			return sqrt(sigma / (y_val.size() - 1));
		}

		T median() const {
			std::vector<T> y = y_val;
			std::sort(y.begin(), y.end());

			if (y.size() % 2 == 0) {
				return y[(y.size() / 2 + (y.size() / 2) + 1) / 2];
			}
			else {
				return y[(y.size() + 1) / 2];
			}
		}

		T slope() const {
			size_t n = x_val.size();
			std::vector<T> xy(n);
			T xy_total = 0;
			T x_sum = 0;
			T y_sum = mean() * y_val.size();    
			T x2_sum = 0;

			std::transform(x_val.begin(), x_val.end(), y_val.begin(), xy.begin(), [](auto x, auto y) {
				return x * y;
			});

			xy_total += std::accumulate(xy.begin(), xy.end(), 0.0000);

			x_sum += std::accumulate(x_val.begin(), x_val.end(), 0.0000);

			std::for_each(x_val.begin(), x_val.end(), [&](auto x) {
				x2_sum += pow(x, 2);
			});

			return (n * xy_total - x_sum * y_sum) / ((n * x2_sum) - pow(x_sum, 2));
		}

		T intercept() const {
			T x_sum = 0;
			x_sum += std::accumulate(x_val.begin(), x_val.end(), 0.0000);

			T y_sum = mean() * y_val.size(); 

			return (y_sum - slope() * x_sum) / x_val.size();
		}

	public:
		DataTable(std::ifstream & file) {
			if (file.is_open()) {
				T x_value, y_value;
				bool TF = true;

				do {
					if (file >> x_value >> y_value) {           
						x_val.push_back(x_value);
						y_val.push_back(y_value);
					}
					else TF = false;              
				} while (TF);
			}
		}

		void displayData(std::ostream & os) const {
			os << "Data Values\n------------\n";
			os << std::setw(FW) << "x" << std::setw(FW) << "y" << std::endl;

			for (int i = 0; i < x_val.size(); i++) {
				os << std::setw(FW) << std::fixed << std::setprecision(ND) << x_val[i]
					<< std::setw(FW) << std::fixed << std::setprecision(ND) << y_val[i] << std::endl;
			}
		}

		void displayStatistics(std::ostream & os) const {
			os << "\nStatistics\n----------\n";
			os << "  y mean    =  " << std::setw(FW) << mean() << std::endl;
			os << "  y sigma   =  " << std::setw(FW) << sigma() << std::endl;
			os << "  y median  =  " << std::setw(FW) << median() << std::endl;
			os << "  slope     =  " << std::setw(FW) << slope() << std::endl;
			os << "  intercept =  " << std::setw(FW) << intercept() << std::endl;
		}
	};
}
#endif //!SICT_DATA_TABLE_H