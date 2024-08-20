#ifndef MUSICMODEL_H
#define MUSICMODEL_H

#include <QAbstractTableModel>
#include <QList>

class Album;

class MusicModel : public QAbstractTableModel
{
public:
    MusicModel(QObject *parent=0);
    ~MusicModel();
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;

    void addAlbum(Album *album);

private:
    QList<Album*> albumList;
};

#endif // MUSICMODEL_H
