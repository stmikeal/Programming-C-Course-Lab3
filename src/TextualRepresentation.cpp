#include <iostream>

#include "TextualRepresentation.hpp"

TextualRepresentation::TextualRepresentation(int val, const std::string &text)
    : value(val), textRepresentation(text) {}

TextualRepresentation::TextualRepresentation(const TextualRepresentation &other)
    : value(other.value), textRepresentation(other.textRepresentation) {}

TextualRepresentation::TextualRepresentation(
    TextualRepresentation &&other) noexcept
    : value(other.value),
      textRepresentation(std::move(other.textRepresentation)) {}

TextualRepresentation::~TextualRepresentation() {}

TextualRepresentation &
TextualRepresentation::operator=(const TextualRepresentation &other)
{
  if (this != &other)
  {
    value = other.value;
    textRepresentation = other.textRepresentation;
  }
  return *this;
}

TextualRepresentation &
TextualRepresentation::operator=(TextualRepresentation &&other) noexcept
{
  if (this != &other)
  {
    value = other.value;
    textRepresentation = std::move(other.textRepresentation);
  }
  return *this;
}

bool TextualRepresentation::operator<(TextualRepresentation &other)
{
  return this->getValue() < other.getValue();
}

bool TextualRepresentation::operator>(TextualRepresentation &other)
{
  return this->getValue() > other.getValue();
}
bool TextualRepresentation::operator==(TextualRepresentation &other)
{
  return this->getValue() == other.getValue();
}

void TextualRepresentation::print() const
{
  std::cout << value << " - " << textRepresentation << std::endl;
}
