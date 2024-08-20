#include "musicmodel.h"
#include "album.h"
#include <QString>

MusicModel::MusicModel(QObject *parent): QAbstractTableModel(parent)
{
}

MusicModel::~MusicModel()
{
    qDeleteAll(albumList);
}

int MusicModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return albumList.size();
}

int MusicModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return 4;
}

QVariant MusicModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::TextAlignmentRole)
    {
        return int(Qt::AlignRight | Qt::AlignVCenter);
    }

    if (role == Qt::DisplayRole)
    {
        int col = index.column();
        int row = index.row();
        if (col==0) return albumList.at(row)->getComposer();
        if (col==1) return albumList.at(row)->getTitle();
        if (col==2) return QString("%1").arg(albumList.at(row)->getCost(), 0, 'f', 2);
        else return albumList.at(row)->getRating();
    }

    return QVariant();
}

QVariant MusicModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Vertical)
        return QVariant();

    switch (section)
    {
    case 0: return QString("Composer/artist");  break;
    case 1: return QString("Album title");      break;
    case 2: return QString("Cost"); break;
    case 3: return QString("Rating");           break;
    default: return QVariant();
    }

    return QVariant();
}

bool MusicModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.isValid() && role==Qt::EditRole)
    {
        int col = index.column();
        int row = index.row();
        switch (col)
        {
        case 0: albumList.at(row)->setComposer(value.toString());   break;
        case 1: albumList.at(row)->setTitle(value.toString());      break;
        case 2: albumList.at(row)->setCost(value.toFloat());        break;
        case 3: albumList.at(row)->setRating(value.toInt());        break;
        default: return false;
        }
        emit dataChanged(index, index);
        return true;
    }
    return false;
}

Qt::ItemFlags MusicModel::flags(const QModelIndex &index) const
{
    if (index.isValid())
        return (Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable);
    else
        return Qt::NoItemFlags;
}

void MusicModel::addAlbum(Album *album)
{
    int row = albumList.size();
    beginInsertRows(QModelIndex(), row+1, row+1);
    albumList.append(album);
    endInsertRows();
}

