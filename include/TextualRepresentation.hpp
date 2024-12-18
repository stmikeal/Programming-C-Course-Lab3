#ifndef _TEXTUAL_REPRESENTATION_
#define _TEXTUAL_REPRESENTATION_

#include <string>

class TextualRepresentation
{
private:
    int value;
    std::string textRepresentation;

public:
    TextualRepresentation(int val, const std::string &text);
    TextualRepresentation(const TextualRepresentation &other);
    TextualRepresentation(TextualRepresentation &&other) noexcept;
    ~TextualRepresentation();

    TextualRepresentation &operator=(const TextualRepresentation &other);
    TextualRepresentation &operator=(TextualRepresentation &&other) noexcept;

    void print() const;
};

#endif // _TEXTUAL_REPRESENTATION_
