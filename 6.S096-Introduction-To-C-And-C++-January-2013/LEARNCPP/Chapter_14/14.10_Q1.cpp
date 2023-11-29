#include <iostream>


class Ball
{
private:
	std::string m_color{};
	double m_radius{};
public:
	Ball(std::string color, double radius)
		: m_color{color}, m_radius{radius}
	{
	}	
	void print(){
		std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
	}

};




int main()
{
	Ball blue{ "blue", 10.0 };
	blue.print();

	Ball red{ "red", 12.0 };
	red.print();

	return 0;
}
