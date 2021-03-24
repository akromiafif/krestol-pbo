/* map.h
 * Deklarasi map
 *
 * Authors:
 * Hanif Arroisi Mukhlis (@Dheatly23)
 */

#ifndef MAP_H
#define MAP_H

#include <memory>
#include <vector>

namespace ns_Engimon {

    class Coord {
    public:
        typedef int Index;
        enum Direction { UP, DOWN, LEFT, RIGHT };

        constexpr Coord()
            : x(0), y(0)
        {
        }
        constexpr Coord(Index xpos, Index ypos)
            : x(xpos), y(ypos)
        {
        }

        inline constexpr Index getX() const {
            return x;
        }
        inline constexpr Index getY() const {
            return y;
        }

        inline void setX(Index x) {
            this->x = x;
        }
        inline void setY(Index y) {
            this->y = y;
        }

        void move(Direction dir);
        Coord moveDir(Direction dir) const;

        inline constexpr bool isBounded(Index xmax, Index ymax) const {
            return (x >= 0) && (x <= xmax) && (y >= 0) && (y <= ymax);
        }

    private:
        Index x, y;
    };

    class Map;

    class Entity {
    protected:
        Coord coord;
        Map &map;

    public:
        constexpr Entity(Coord c, Map &m)
            : coord(c)
            , map(m)
        {
        }
        virtual ~Entity() {
        }

        virtual Coord getPos();
        virtual void moveTo(Coord coord);

        // Interact and returns true if interaction valid, false otherwise.
        virtual bool interact(Entity &other);
    };

    class Map {
    private:
        std::vector<std::unique_ptr<Entity>> entities;

        Coord::Index sizex, sizey;

    public:
        Map(Coord::Index xsize, Coord::Index ysize);
        virtual ~Map();
    };

} /* Map */

#endif /* !MAP_H */
