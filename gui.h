#ifndef GUI_H
#define GUI_H

#include <QWidget>
class MusicModel;

class QLineEdit;
class QDoubleSpinBox;
class QSpinBox;
class QPushButton;
class QTableView;

class Gui : public QWidget
{
    Q_OBJECT

public:
    Gui(QWidget *parent = nullptr);
    ~Gui();

private slots:
    void addItem();
    void enableButton();

private:
    void setupGui();

    QLineEdit *composerEdit;
    QLineEdit *titleEdit;
    QDoubleSpinBox *costSpinBox;
    QSpinBox *ratingSpinBox;
    QPushButton *addButton;
    QTableView *tableView;
    MusicModel *model;
};
#endif // GUI_H
