
#include <string>

#include "element.h"

using namespace std;
using namespace ns_Engimon;

Element::CombineError::CombineError(const Element &f, const Element &s)
    : runtime_error(string("Can\'t combine element ")
        .append(f.getElementName())
        .append(" and ")
        .append(s.getElementName())
    ), first(f), second(s)
{
}

ExampleElement ExampleElement::element;

const char *ExampleElement::getElementName() const {
    return "test";
}

double ExampleElement::elementAdvantage(const Element &other) const {
    return 0;
}

bool ExampleElement::combineable(const Element &other) const {
    return false;
}

const Element &ExampleElement::combine(const Element &other) const {
    throw Element::CombineError(*this, other);
}

WaterElement WaterElement::element;

const char *WaterElement::getElementName() const {
    return "test";
}

double WaterElement::elementAdvantage(const Element &other) const {
    return 0;
}

bool WaterElement::combineable(const Element &other) const {
    return false;
}
const Element &WaterElement::combine(const Element &other) const {
    throw Element::CombineError(*this, other);
}

FireElement FireElement::element;

const char *FireElement::getElementName() const {
    return "test";
}

double FireElement::elementAdvantage(const Element &other) const {
    return 0;
}

bool FireElement::combineable(const Element &other) const {
    return false;
}
const Element &FireElement::combine(const Element &other) const {
    throw Element::CombineError(*this, other);
}

ElectricElement ElectricElement::element;

const char *ElectricElement::getElementName() const {
    return "test";
}

double ElectricElement::elementAdvantage(const Element &other) const {
    return 0;
}

bool ElectricElement::combineable(const Element &other) const {
    return false;
}
const Element &ElectricElement::combine(const Element &other) const {
    throw Element::CombineError(*this, other);
}

GroundElement GroundElement::element;

const char *GroundElement::getElementName() const {
    return "test";
}

double GroundElement::elementAdvantage(const Element &other) const {
    return 0;
}

bool GroundElement::combineable(const Element &other) const {
    return false;
}
const Element &GroundElement::combine(const Element &other) const {
    throw Element::CombineError(*this, other);
}

IceElement IceElement::element;

const char *IceElement::getElementName() const {
    return "test";
}

double IceElement::elementAdvantage(const Element &other) const {
    return 0;
}

bool IceElement::combineable(const Element &other) const {
    return false;
}
const Element &IceElement::combine(const Element &other) const {
    throw Element::CombineError(*this, other);
}
