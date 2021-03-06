#ifndef __SFMLS_BEASTS_H__
#define __SFMLS_BEASTS_H__

#include <list>
#include "Beast.h"
#include "Object.h"

class Beasts : public Object
{
public:
    Beasts();
    Beasts(Game *g, Beast::Attributes attr);
    ~Beasts();
    std::list<Beast> beasts;
    Beast::Attributes getAttributes();
    void show();

    Beast::Attributes attributes;
private:
};

#endif
