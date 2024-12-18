#include <iostream>
#include <list>
#include <vector>
#include <random>
#include <algorithm>
#include <list>

#include "TextualRepresentation.hpp"

class TextualRandomizator
{
public:
	TextualRandomizator() : rd(), vector_size(500, 1000), list_size(20, 50), char_gen(32, 126), int_gen(-4242, 4242), str_len(1, 10) {}

	size_t getVectorSize()
	{
		return vector_size(rd);
	}

	size_t getListSize()
	{
		return list_size(rd);
	}

	TextualRepresentation getElem()
	{
		std::string s;
		s.resize(str_len(rd));
		std::generate(s.begin(), s.end(), [this]()
					  { return char_gen(rd); });
		return TextualRepresentation(int_gen(rd), s);
	}

private:
	std::random_device rd;
	std::uniform_int_distribution<size_t> vector_size;
	std::uniform_int_distribution<size_t> list_size;
	std::uniform_int_distribution<char> char_gen;
	std::uniform_int_distribution<size_t> str_len;
	std::uniform_int_distribution<int> int_gen;
};

constexpr size_t kStartCopyPos = 200;
constexpr size_t kEndCopyPos = 400;

int main()
{
	// task 1
	TextualRandomizator rand;
	std::vector<TextualRepresentation> v1(rand.getVectorSize());
	generate(v1.begin(), v1.end(), [&rand]()
			 { return rand.getElem(); });
	std::cout << "Сгенерирован вектор длиной " << v1.size() << std::endl;

	// task 2
	std::vector<TextualRepresentation> v2(v1.begin() + kStartCopyPos, v1.begin() + kEndCopyPos);
	v1.erase(v1.begin() + kStartCopyPos, v1.begin() + kEndCopyPos);
	std::cout << "Скопированы элементы с позиции " << kStartCopyPos << " до позиции " << kEndCopyPos << std::endl;

	// task 3
	size_t list1_size = rand.getListSize();
	std::partial_sort(v1.begin(), v1.begin() + list1_size, v1.end(), [](auto o1, auto o2)
					  { return o1 > o2; });
	std::list<TextualRepresentation> list1(v1.begin(), v1.begin() + list1_size);
	v1.erase(v1.begin(), v1.begin() + list1_size);
	std::cout << "В список добавлены " << list1_size << " старших элементов" << std::endl;

	// task 4
	size_t list2_size = rand.getListSize();
	std::partial_sort(v2.begin(), v2.begin() + list2_size, v2.end());
	std::list<TextualRepresentation> list2(v2.begin(), v2.begin() + list2_size);
	v2.erase(v2.begin(), v2.begin() + list2_size);
	std::cout << "В список добавлены " << list2_size << " младших элементов" << std::endl;

	// task 6
	double mean = std::accumulate(list1.begin(), list1.end(), 0.0, [](double sum, auto o)
								  { return sum + o.getValue(); }) /
				  list1.size();
	std::list<TextualRepresentation> temp_list1;
	std::copy_if(list1.begin(), list1.end(), std::back_inserter(temp_list1), [mean](auto o)
				 { return o.getValue() >= mean; });
	std::copy_if(list1.begin(), list1.end(), std::back_inserter(temp_list1), [mean](auto o)
				 { return o.getValue() < mean; });
	list1 = temp_list1;
	std::cout << "Список переупорядочен так, что первые элементы больше, чем " << mean << std::endl;

	// task 7
	list2.remove_if([](auto o)
					{ return o.getValue() % 2 != 0; });
	std::cout << "Удалены нечётные элементы" << std::endl;

	// task 8
	std::vector<TextualRepresentation> v3;
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());
	std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
	std::cout << "Сформирован вектор v3 из общих элементов v1 и v2, длиной " << v3.size() << std::endl;

	// task 9
	if (list1.size() > list2.size())
		list1.erase(list1.begin(), next(list1.begin(), list1.size() - list2.size()));
	else if (list2.size() > list1.size())
		list2.erase(list2.begin(), next(list2.begin(), -list1.size() + list2.size()));

	std::list<std::pair<TextualRepresentation, TextualRepresentation>> list3;
	transform(list1.begin(), list1.end(), list2.begin(), std::back_inserter(list3), [](auto o1, auto o2)
			  { return std::make_pair(o1, o2); });
	std::cout << "Сформирован список из пар списов длиной " << list3.size() << std::endl;
	
	// task 10
	std::list<std::pair<TextualRepresentation, TextualRepresentation>> list4;
	transform(v1.begin(), v1.begin() + std::min(v1.size(), v2.size()), v2.begin(), std::back_inserter(list4), [](auto o1, auto o2)
			  { return std::make_pair(o1, o2); });
	std::cout << "Сформирован список из пар векторов длиной " << list4.size() << std::endl;
	return 0;
}