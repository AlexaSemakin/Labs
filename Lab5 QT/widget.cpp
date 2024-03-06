#include "widget.h"

#include <QDebug>

BinaryTreeWidget::BinaryTreeWidget()
{
    inputLineEdit = new QLineEdit(this);
    buildButton = new QPushButton("Построить дерево", this);

    connect(buildButton, &QPushButton::clicked, this, &BinaryTreeWidget::buildTree);

    layout = new QVBoxLayout(this);
    subLayout = new QHBoxLayout();
    layout->addWidget(inputLineEdit);
    layout->addWidget(buildButton);
    layout->addLayout(subLayout);

    scene = new QGraphicsScene(this);
    view = new QGraphicsView(scene, this);
    layout->addWidget(view);
}

void BinaryTreeWidget::buildTree()
{
    QString input_file = inputLineEdit->text();
    std::string encoded_file_name = "encoding";
    HafmanTree ht;
    ht.build(input_file.toStdString());
    // std::cout << ht.encode(input_file, encoded_file_name);
    ht.decode(encoded_file_name, "decoding");

    displayTree(ht.get_root(), scene, 300, 60, 800);
}

void BinaryTreeWidget::displayTree(HafmanTree::Node *root, QGraphicsScene *scene, qreal x, qreal y, qreal xOffset)
{
    if (root != nullptr) {
        // scene->addEllipse(x, y, 30, 30);
        QGraphicsTextItem *textItem = scene->addText(("<" + root->all_chr() + ">").c_str());

        textItem->setPos(x + 5, y + 5);

        if (root->left() != nullptr) {
            qreal leftX = x - xOffset;
            qreal leftY = y + 60;
            scene->addLine(x + 15, y + 30, leftX + 15, leftY, QPen(Qt::black));
            displayTree(root->left(), scene, leftX, leftY, xOffset / 2);
        }

        if (root->right() != nullptr) {
            qreal rightX = x + xOffset;
            qreal rightY = y + 60;
            scene->addLine(x + 15, y + 30, rightX + 15, rightY, QPen(Qt::black));
            displayTree(root->right(), scene, rightX, rightY, xOffset / 2);
        }
    }
}
