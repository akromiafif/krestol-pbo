/* map.cpp
 * Definisi map
 *
 * Authors:
 * Hanif Arroisi Mukhlis (@Dheatly23)
 */

#include "map.h"

using namespace ns_Engimon;

Map::Map(Coord::Index xsize, Coord::Index ysize)
    : entities(), sizex(xsize), sizey(ysize)
{
}

Map::~Map() {
}
