#include "album.h"

Album::Album(): composer{"Unknown"}, title{"Unknown"}, cost{0.0}, rating{0}
{
}

Album::Album(QString c, QString t, double p, int r): composer{c}, title{t}, cost{p}, rating{r}
{
}

QString Album::getComposer() const
{
    return composer;
}

QString Album::getTitle() const
{
    return title;
}

double Album::getCost() const
{
    return cost;
}

int Album::getRating() const
{
    return rating;
}

void Album::setComposer(QString c)
{
    composer = c;
}

void Album::setTitle(QString t)
{
    title = t;
}

void Album::setCost(double p)
{
    cost = p;
}

void Album::setRating(int r)
{
    rating = r;
}
