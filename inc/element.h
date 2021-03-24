/* Element.h
 * Element
 *
 * Author:
 * Hanif Arroisi Mukhlis (@Dheatly23)
 */

#ifndef ELEMENT_H
#define ELEMENT_H

#include <stdexcept>

namespace ns_Engimon {

    class Element {
    protected:
        constexpr Element() {
        }
        Element(const Element&) = delete;
        Element(const Element&&) = delete;

    public:
        class CombineError : public std::runtime_error {
        public:
            CombineError(const Element &first, const Element &second);

            const Element &first;
            const Element &second;
        };

        virtual const char *getElementName() const = 0;

        virtual double elementAdvantage(const Element &other) const = 0;

        virtual bool combineable(const Element &other) const = 0;
        virtual const Element &combine(const Element &other) const = 0;
    };

    // Example only
    class ExampleElement : public Element {
        constexpr ExampleElement() {
        }
        ExampleElement(const ExampleElement&) = delete;
        ExampleElement(const ExampleElement&&) = delete;

    public:
        virtual const char *getElementName() const;

        virtual double elementAdvantage(const Element &other) const;

        virtual bool combineable(const Element &other) const;
        virtual const Element &combine(const Element &other) const;

        static ExampleElement element;
    };

    class WaterElement : public Element {
        constexpr WaterElement() {
        }
        WaterElement(const WaterElement&) = delete;
        WaterElement(const WaterElement&&) = delete;

    public:
        virtual const char *getElementName() const;

        virtual double elementAdvantage(const Element &other) const;

        virtual bool combineable(const Element &other) const;
        virtual const Element &combine(const Element &other) const;

        static WaterElement element;
    };

    class FireElement : public Element {
        constexpr FireElement() {
        }
        FireElement(const FireElement&) = delete;
        FireElement(const FireElement&&) = delete;

    public:
        virtual const char *getElementName() const;

        virtual double elementAdvantage(const Element &other) const;

        virtual bool combineable(const Element &other) const;
        virtual const Element &combine(const Element &other) const;

        static FireElement element;
    };

    class ElectricElement : public Element {
        constexpr ElectricElement() {
        }
        ElectricElement(const ElectricElement&) = delete;
        ElectricElement(const ElectricElement&&) = delete;

    public:
        virtual const char *getElementName() const;

        virtual double elementAdvantage(const Element &other) const;

        virtual bool combineable(const Element &other) const;
        virtual const Element &combine(const Element &other) const;

        static ElectricElement element;
    };

    class GroundElement : public Element {
        constexpr GroundElement() {
        }
        GroundElement(const GroundElement&) = delete;
        GroundElement(const GroundElement&&) = delete;

    public:
        virtual const char *getElementName() const;

        virtual double elementAdvantage(const Element &other) const;

        virtual bool combineable(const Element &other) const;
        virtual const Element &combine(const Element &other) const;

        static GroundElement element;
    };

    class IceElement : public Element {
        constexpr IceElement() {
        }
        IceElement(const IceElement&) = delete;
        IceElement(const IceElement&&) = delete;

    public:
        virtual const char *getElementName() const;

        virtual double elementAdvantage(const Element &other) const;

        virtual bool combineable(const Element &other) const;
        virtual const Element &combine(const Element &other) const;

        static IceElement element;
    };

} /* ns_Engimon */

#endif /* !ELEMENT_H */
