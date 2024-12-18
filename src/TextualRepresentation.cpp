#include <iostream>

#include "TextualRepresentation.hpp"

TextualRepresentation::TextualRepresentation(int val, const std::string &text) : value(val), textRepresentation(text)
{
    std::cout << "Basic Constructor" << std::endl;
}

TextualRepresentation::TextualRepresentation(const TextualRepresentation &other) : value(other.value), textRepresentation(other.textRepresentation)
{
    std::cout << "Copy Constructor" << std::endl;
}

TextualRepresentation::TextualRepresentation(TextualRepresentation &&other) noexcept : value(other.value), textRepresentation(std::move(other.textRepresentation))
{
    std::cout << "Move Constructor" << std::endl;
}

TextualRepresentation::~TextualRepresentation()
{
    std::cout << "Basic Destructor" << std::endl;
}

TextualRepresentation &TextualRepresentation::operator=(const TextualRepresentation &other)
{
    std::cout << "Copy assignment" << std::endl;
    if (this != &other)
    {
        value = other.value;
        textRepresentation = other.textRepresentation;
    }
    return *this;
}

TextualRepresentation &TextualRepresentation::operator=(TextualRepresentation &&other) noexcept
{
    std::cout << "Move assignment" << std::endl;
    if (this != &other)
    {
        value = other.value;
        textRepresentation = std::move(other.textRepresentation);
    }
    return *this;
}

void TextualRepresentation::print() const
{
    std::cout << value << " - " << textRepresentation << std::endl;
}
