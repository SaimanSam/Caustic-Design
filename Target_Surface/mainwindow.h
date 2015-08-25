#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global.h"
#include <QMainWindow>
#include "SurfaceModel.h"
#include "targetoptimization.h"
#include "rendering.h"
#include "ui_mainwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public Ui_MainWindow
{
    Q_OBJECT


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setModel();

private:
    //Ui::MainWindow *ui;
    //Renderer* render;
    TargetOptimization *optimizer;

protected slots:
    void on_actionSaveModel_triggered();
    void on_actionLoadModel_triggered();
    void on_actionExit_triggered();
    void on_actionSave_Vertices_triggered();
    void on_actionGenerateTriangles_triggered();
    void on_actionRunTargetOptimization_triggered();
    void on_actionLoadLightRayReceiverPosition_triggered();
    void on_actionNormals_toggled();
    void on_actionDesired_Normals_toggled();
    void on_actionDesired_Ray_Directions_toggled();
    void on_actionDesired_Rays_toggled();
    void on_actionShoot_Test_Ray_triggered();

    void on_actionAxis_toggled();
    /* line edit slots */
    void newMeshHeight();
    void newFocalLength();

    //void on_actionCreate_Object_triggered();
};

#endif // MAINWINDOW_H
