#include "Forward_List.hpp"

int main () {
	Forward_list<char> lista;

	lista.push_front('k');
	lista.push_back('#');
	lista.print();

	std::cout << "A frente da lista:" << lista.front() << std::endl;
	std::cout << "O fim da lista:" << lista.back() << std::endl;

	lista.push_back('p');
	lista.push_front('@');
	lista.push_back('%');
	lista.pop_front();
	lista.print();

	std::cout << "A frente da lista:" << lista.front() << std::endl;
	std::cout << "O fim da lista:" << lista.back() << std::endl;
	std::cout << "O tamaho da lista:" << lista.length() << std::endl;

	lista.push_front('~');
	lista.pop_back();
	lista.print();
	std::cout << "O tamaho da lista:" << lista.length() << std::endl;

	lista.assign('s');

	lista.print();

	lista.clear();

	lista.print();
	// lista.find('~')
	std::cout << "O tamaho da lista:" << lista.length() << std::endl;

	return EXIT_SUCCESS;
}
