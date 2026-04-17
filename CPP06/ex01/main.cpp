#include "Serializer.hpp"

int main()
{
	Data d;
	d.value = 1337;

	std::cout << "&d: "<< &d << std::endl;

	uintptr_t raw = Serializer::serialize(&d);
	std::cout << "raw: " << std::hex << raw << std::endl;

	Data* ptr = Serializer::deserialize(raw);
	std::cout << "ptr: " << ptr << std::endl;

	std::cout << "ptr->value: " << std::dec << ptr->value << std::endl;
}