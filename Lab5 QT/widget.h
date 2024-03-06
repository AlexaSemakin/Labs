#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <hafmantree.h>
#include <vector>
#include <iostream>

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr)
    {}
};

class BinaryTreeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BinaryTreeWidget();

private slots:
    void buildTree();

private:
    QLineEdit *inputLineEdit;
    QPushButton *buildButton;
    QVBoxLayout *layout;
    QHBoxLayout *subLayout;

    QGraphicsScene *scene;
    QGraphicsView *view;
    std::vector<int> numbers;

    void displayTree(HafmanTree::Node *root, QGraphicsScene *scene, qreal x, qreal y, qreal xOffset);
};

#endif // WIDGET_H
