#ifndef IMAGEHANDLER_H
#define IMAGEHANDLER_H

#include <QObject>
#include <QtWidgets>
#include <QtConcurrent/QtConcurrent>

class ImageHandler : public QObject
{
    Q_OBJECT
public:
    const int MAX_GRAY_COLOR = 255;
    const int MIN_GRAY_COLOR = 0;
    const QVector<int> plusDx = {-1, 1, 0, 0};
    const QVector<int> plusDy = {0, 0, 1, -1};
    const QVector<int> cornersDx = {-1, 1, 1, -1};
    const QVector<int> cornersDy = {-1, 1, -1, 1};

    explicit ImageHandler(QImage *image, int frameThreshold, int brightnessThreshold, int stressAmplitude, int stressCycles, QObject *parent = 0);
    void nextIteration();
    void setImage(QImage *image);
    QImage* getImage();

//    NOT WORKING
//    struct ThreadTask;
//    void useAlgorithmForWrapper(ThreadTask task);

private:
    QImage *sourceImage;
    QVector<QVector<int>> dataMatrix;
    QVector<QVector<char>> frame, activeMatrix;
    int frameThreshold;
    int brightnessThreshold;
    int stressAmplitude;
    int stressCycles;

    void useAlgorithmFor(QVector<QVector<int> > &newDataMatrix, QVector<QVector<char> > &newActiveMatrix);
//    void useAlgorithmFor(QVector<QVector<int> > *newDataMatrix, QVector<QVector<char> > *newActiveMatrix, QPair<int, int> pairX, QPair<int, int> pairY);

signals:

public slots:
};

#endif // IMAGEHANDLER_H
