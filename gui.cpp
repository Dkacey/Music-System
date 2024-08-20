#include "gui.h"
#include "musicmodel.h"
#include "album.h"

#include <QLabel>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QSpinBox>
#include <QTableView>
#include <QPushButton>
#include <QGridLayout>
#include <QHeaderView>

Gui::Gui(QWidget *parent)
    : QWidget{parent},
       composerEdit{new QLineEdit},
       titleEdit{new QLineEdit},
       costSpinBox{new QDoubleSpinBox},
       ratingSpinBox{new QSpinBox},
       addButton{new QPushButton("Add")},
       tableView{new QTableView},
       model{new MusicModel(this)}
{
    setupGui();
    tableView->setModel(model);

    connect(addButton, &QPushButton::clicked, this, &Gui::addItem);
    //connect(composerEdit, &QLineEdit::textChanged, this &Gui::enableButton());
    connect(composerEdit, &QLineEdit::textChanged, this, &Gui::enableButton);
    connect(titleEdit, &QLineEdit::textChanged, this, &Gui::enableButton);
}

Gui::~Gui()
{
}

void Gui::addItem()
{
    // get values
    QString composer = composerEdit->text();
    QString title = titleEdit->text();
    double cost = costSpinBox->value();
    int rating = ratingSpinBox->value();

    // reset GUI
    composerEdit->clear();
    titleEdit->clear();
    costSpinBox->setValue(0.00);
    ratingSpinBox->setValue(0);
    composerEdit->setFocus();
    addButton->setEnabled(false);

    // add to model
    Album *album{new Album(composer, title, cost, rating)};
    model->addAlbum(album);
}

void Gui::enableButton()
{
    if (composerEdit->text().size()!=0 && titleEdit->text().size()!=0)
        addButton->setEnabled(true);
}

void Gui::setupGui()
{
    setWindowTitle("Music");

    QLabel* composerLabel{new QLabel("Composer")};
    QLabel* titleLabel{new QLabel("Album title")};
    QLabel* costLabel{new QLabel("Cost (R)")};
    QLabel* ratingLabel{new QLabel("Rating")};

    QGridLayout* layout{new QGridLayout(this)};
    layout->addWidget(composerLabel, 0, 0);
    layout->addWidget(titleLabel, 0, 1);
    layout->addWidget(costLabel, 0, 2);
    layout->addWidget(ratingLabel, 0, 3);
    layout->addWidget(composerEdit, 1, 0);
    layout->addWidget(titleEdit, 1, 1);
    layout->addWidget(costSpinBox, 1, 2);
    layout->addWidget(ratingSpinBox, 1, 3);
    layout->addWidget(addButton, 1, 4);
    layout->addWidget(tableView, 2, 0, 1, 5);

    costSpinBox->setMinimum(0.00);
    costSpinBox->setMaximum(99000.00);
    costSpinBox->setDecimals(2);
    ratingSpinBox->setMinimum(0);
    ratingSpinBox->setMaximum(100);

    tableView->horizontalHeader()->setStretchLastSection(true);

    addButton->setEnabled(false);

    this->setLayout(layout);
    this->adjustSize();
}

