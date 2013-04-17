#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void Update();

private:
    Ui::MainWindow *ui;

    vtkColorTransferFunction * m_colorTransferFunction;
    vtkPiecewiseFunction * m_opacityFunction;
};

#endif // MAINWINDOW_H
