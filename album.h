#ifndef ALBUM_H
#define ALBUM_H

#include <QString>

class Album
{
public:
    Album();
    Album(QString c, QString t, double p, int r);
    QString getComposer() const;
    QString getTitle() const;
    double getCost() const;
    int getRating() const;
    void setComposer(QString c);
    void setTitle(QString t);
    void setCost(double p);
    void setRating(int r);
private:
    QString composer;
    QString title;
    double cost;
    int rating;
};

#endif // ALBUM_H
