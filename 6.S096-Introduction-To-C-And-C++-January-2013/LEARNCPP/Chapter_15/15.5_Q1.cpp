#include <iostream>
#include <string>


template <typename T1, typename T2, typename T3>
class Triad{

	private:

		T1 a{};
		T2 b{};
		T3 c{};

	public:
		
		Triad(const T1& a, const T2& b, const T3& c)
		       :a{a}, b{b}, c{c}
		{
		}	
		
		T1 geta(){ return a; }
		T2 getb(){ return b; }
		T3 getc(){ return c; }
		
		void print() const
		{
			std::cout << "[" << a << ", " << b << ", " << c << "]";
		}
};





int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}
