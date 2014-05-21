/********************************************************************************
** Form generated from reading UI file 'mainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLayout>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QScrollArea>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "ObjWidget.h"
#include "ParametersToolBox.h"
#include "utilite/UPlot.h"

QT_BEGIN_NAMESPACE

class Ui_mainWindow
{
public:
    QAction *actionExit;
    QAction *actionAdd_object_from_scene;
    QAction *actionStart_camera;
    QAction *actionStop_camera;
    QAction *actionSave_objects;
    QAction *actionLoad_objects;
    QAction *actionAbout;
    QAction *actionRestore_all_default_settings;
    QAction *actionAdd_objects_from_files;
    QAction *actionLoad_scene_from_file;
    QAction *actionPause_camera;
    QAction *actionCamera_from_video_file;
    QAction *actionRemove_all_objects;
    QAction *actionCamera_from_directory_of_images;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLabel *label_timeRefreshRate;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_detectorDescriptorType;
    QSpacerItem *horizontalSpacer;
    QLabel *label_nfeatures;
    QLabel *label_15;
    ObjWidget *imageView_source;
    QHBoxLayout *horizontalLayout;
    QWidget *widget_controls;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_play;
    QPushButton *pushButton_pause;
    QPushButton *pushButton_stop;
    QSlider *horizontalSlider_frames;
    QLabel *label_frame;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuView;
    QMenu *menu;
    QDockWidget *dockWidget_parameters;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_timeMatching;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_12;
    QLabel *label_minMatchedDistance;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_maxMatchedDistance;
    QLabel *label_11;
    QLabel *label_timeGui;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_timeExtraction;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_timeDetection;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_timeIndexing;
    QLabel *label_6;
    QLabel *label_timeTotal;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_vocabularySize;
    ParametersToolBox *toolBox;
    QWidget *page_1;
    QVBoxLayout *verticalLayout_5;
    QPushButton *pushButton_restoreDefaults;
    QDockWidget *dockWidget_objects;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_6;
    QScrollArea *objects_area;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_objects;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_updateObjects;
    QSlider *horizontalSlider_objectsSize;
    QDockWidget *dockWidget_plot;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_7;
    UPlot *likelihoodPlot;

    void setupUi(QMainWindow *mainWindow)
    {
        if (mainWindow->objectName().isEmpty())
            mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
        mainWindow->resize(825, 441);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/resources/Find-Object.png"), QSize(), QIcon::Normal, QIcon::Off);
        mainWindow->setWindowIcon(icon);
        actionExit = new QAction(mainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAdd_object_from_scene = new QAction(mainWindow);
        actionAdd_object_from_scene->setObjectName(QString::fromUtf8("actionAdd_object_from_scene"));
        actionStart_camera = new QAction(mainWindow);
        actionStart_camera->setObjectName(QString::fromUtf8("actionStart_camera"));
        actionStop_camera = new QAction(mainWindow);
        actionStop_camera->setObjectName(QString::fromUtf8("actionStop_camera"));
        actionSave_objects = new QAction(mainWindow);
        actionSave_objects->setObjectName(QString::fromUtf8("actionSave_objects"));
        actionLoad_objects = new QAction(mainWindow);
        actionLoad_objects->setObjectName(QString::fromUtf8("actionLoad_objects"));
        actionAbout = new QAction(mainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionRestore_all_default_settings = new QAction(mainWindow);
        actionRestore_all_default_settings->setObjectName(QString::fromUtf8("actionRestore_all_default_settings"));
        actionAdd_objects_from_files = new QAction(mainWindow);
        actionAdd_objects_from_files->setObjectName(QString::fromUtf8("actionAdd_objects_from_files"));
        actionLoad_scene_from_file = new QAction(mainWindow);
        actionLoad_scene_from_file->setObjectName(QString::fromUtf8("actionLoad_scene_from_file"));
        actionPause_camera = new QAction(mainWindow);
        actionPause_camera->setObjectName(QString::fromUtf8("actionPause_camera"));
        actionCamera_from_video_file = new QAction(mainWindow);
        actionCamera_from_video_file->setObjectName(QString::fromUtf8("actionCamera_from_video_file"));
        actionCamera_from_video_file->setCheckable(true);
        actionRemove_all_objects = new QAction(mainWindow);
        actionRemove_all_objects->setObjectName(QString::fromUtf8("actionRemove_all_objects"));
        actionCamera_from_directory_of_images = new QAction(mainWindow);
        actionCamera_from_directory_of_images->setObjectName(QString::fromUtf8("actionCamera_from_directory_of_images"));
        actionCamera_from_directory_of_images->setCheckable(true);
        centralwidget = new QWidget(mainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        label_timeRefreshRate = new QLabel(centralwidget);
        label_timeRefreshRate->setObjectName(QString::fromUtf8("label_timeRefreshRate"));

        horizontalLayout_2->addWidget(label_timeRefreshRate);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label_detectorDescriptorType = new QLabel(centralwidget);
        label_detectorDescriptorType->setObjectName(QString::fromUtf8("label_detectorDescriptorType"));

        horizontalLayout_2->addWidget(label_detectorDescriptorType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        label_nfeatures = new QLabel(centralwidget);
        label_nfeatures->setObjectName(QString::fromUtf8("label_nfeatures"));
        label_nfeatures->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_nfeatures);

        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_2->addWidget(label_15);


        verticalLayout->addLayout(horizontalLayout_2);

        imageView_source = new ObjWidget(centralwidget);
        imageView_source->setObjectName(QString::fromUtf8("imageView_source"));

        verticalLayout->addWidget(imageView_source);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        widget_controls = new QWidget(centralwidget);
        widget_controls->setObjectName(QString::fromUtf8("widget_controls"));
        horizontalLayout_4 = new QHBoxLayout(widget_controls);
        horizontalLayout_4->setSpacing(-1);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_play = new QPushButton(widget_controls);
        pushButton_play->setObjectName(QString::fromUtf8("pushButton_play"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton_play->sizePolicy().hasHeightForWidth());
        pushButton_play->setSizePolicy(sizePolicy);
        pushButton_play->setMaximumSize(QSize(24, 24));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/resources/TheWorkingGroup_video_play.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_play->setIcon(icon1);

        horizontalLayout_4->addWidget(pushButton_play);

        pushButton_pause = new QPushButton(widget_controls);
        pushButton_pause->setObjectName(QString::fromUtf8("pushButton_pause"));
        pushButton_pause->setMaximumSize(QSize(24, 24));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/resources/TheWorkingGroup_video_pause.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_pause->setIcon(icon2);

        horizontalLayout_4->addWidget(pushButton_pause);

        pushButton_stop = new QPushButton(widget_controls);
        pushButton_stop->setObjectName(QString::fromUtf8("pushButton_stop"));
        pushButton_stop->setMaximumSize(QSize(24, 24));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/images/resources/TheWorkingGroup_video_stop.ico"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_stop->setIcon(icon3);

        horizontalLayout_4->addWidget(pushButton_stop);

        horizontalSlider_frames = new QSlider(widget_controls);
        horizontalSlider_frames->setObjectName(QString::fromUtf8("horizontalSlider_frames"));
        horizontalSlider_frames->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_frames->setMinimum(0);
        horizontalSlider_frames->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(horizontalSlider_frames);

        label_frame = new QLabel(widget_controls);
        label_frame->setObjectName(QString::fromUtf8("label_frame"));

        horizontalLayout_4->addWidget(label_frame);


        horizontalLayout->addWidget(widget_controls);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(1, 1);
        mainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 825, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuEdit = new QMenu(menubar);
        menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
        menuView = new QMenu(menubar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        mainWindow->setMenuBar(menubar);
        dockWidget_parameters = new QDockWidget(mainWindow);
        dockWidget_parameters->setObjectName(QString::fromUtf8("dockWidget_parameters"));
        dockWidget_parameters->setMinimumSize(QSize(360, 376));
        dockWidget_parameters->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_4 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(dockWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(6);
        gridLayout->setVerticalSpacing(0);
        label_timeMatching = new QLabel(groupBox);
        label_timeMatching->setObjectName(QString::fromUtf8("label_timeMatching"));

        gridLayout->addWidget(label_timeMatching, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 3, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 4, 2, 1, 1);

        label_12 = new QLabel(groupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 5, 2, 1, 1);

        label_minMatchedDistance = new QLabel(groupBox);
        label_minMatchedDistance->setObjectName(QString::fromUtf8("label_minMatchedDistance"));

        gridLayout->addWidget(label_minMatchedDistance, 6, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 6, 0, 1, 1);

        label_14 = new QLabel(groupBox);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout->addWidget(label_14, 7, 0, 1, 1);

        label_maxMatchedDistance = new QLabel(groupBox);
        label_maxMatchedDistance->setObjectName(QString::fromUtf8("label_maxMatchedDistance"));

        gridLayout->addWidget(label_maxMatchedDistance, 7, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout->addWidget(label_11, 5, 0, 1, 1);

        label_timeGui = new QLabel(groupBox);
        label_timeGui->setObjectName(QString::fromUtf8("label_timeGui"));

        gridLayout->addWidget(label_timeGui, 5, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        label_timeExtraction = new QLabel(groupBox);
        label_timeExtraction->setObjectName(QString::fromUtf8("label_timeExtraction"));

        gridLayout->addWidget(label_timeExtraction, 2, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 2, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        label_timeDetection = new QLabel(groupBox);
        label_timeDetection->setObjectName(QString::fromUtf8("label_timeDetection"));

        gridLayout->addWidget(label_timeDetection, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 4, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 3, 0, 1, 1);

        label_timeIndexing = new QLabel(groupBox);
        label_timeIndexing->setObjectName(QString::fromUtf8("label_timeIndexing"));

        gridLayout->addWidget(label_timeIndexing, 3, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 0, 0, 1, 1);

        label_timeTotal = new QLabel(groupBox);
        label_timeTotal->setObjectName(QString::fromUtf8("label_timeTotal"));

        gridLayout->addWidget(label_timeTotal, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 0, 2, 1, 1);

        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 8, 0, 1, 1);

        label_vocabularySize = new QLabel(groupBox);
        label_vocabularySize->setObjectName(QString::fromUtf8("label_vocabularySize"));

        gridLayout->addWidget(label_vocabularySize, 8, 1, 1, 1);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout_4->addWidget(groupBox);

        toolBox = new ParametersToolBox(dockWidgetContents);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        page_1->setGeometry(QRect(0, 0, 348, 114));
        verticalLayout_5 = new QVBoxLayout(page_1);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        toolBox->addItem(page_1, QString::fromUtf8("Dummy"));

        verticalLayout_4->addWidget(toolBox);

        pushButton_restoreDefaults = new QPushButton(dockWidgetContents);
        pushButton_restoreDefaults->setObjectName(QString::fromUtf8("pushButton_restoreDefaults"));

        verticalLayout_4->addWidget(pushButton_restoreDefaults);

        dockWidget_parameters->setWidget(dockWidgetContents);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidget_parameters);
        dockWidget_objects = new QDockWidget(mainWindow);
        dockWidget_objects->setObjectName(QString::fromUtf8("dockWidget_objects"));
        dockWidget_objects->setMinimumSize(QSize(200, 138));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_6 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        objects_area = new QScrollArea(dockWidgetContents_2);
        objects_area->setObjectName(QString::fromUtf8("objects_area"));
        objects_area->setMinimumSize(QSize(150, 0));
        objects_area->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 198, 314));
        verticalLayout_objects = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_objects->setSpacing(0);
        verticalLayout_objects->setContentsMargins(0, 0, 0, 0);
        verticalLayout_objects->setObjectName(QString::fromUtf8("verticalLayout_objects"));
        verticalSpacer = new QSpacerItem(20, 230, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_objects->addItem(verticalSpacer);

        objects_area->setWidget(scrollAreaWidgetContents);

        verticalLayout_6->addWidget(objects_area);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(12);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_updateObjects = new QPushButton(dockWidgetContents_2);
        pushButton_updateObjects->setObjectName(QString::fromUtf8("pushButton_updateObjects"));

        horizontalLayout_3->addWidget(pushButton_updateObjects);

        horizontalSlider_objectsSize = new QSlider(dockWidgetContents_2);
        horizontalSlider_objectsSize->setObjectName(QString::fromUtf8("horizontalSlider_objectsSize"));
        horizontalSlider_objectsSize->setMinimumSize(QSize(20, 0));
        horizontalSlider_objectsSize->setFocusPolicy(Qt::ClickFocus);
        horizontalSlider_objectsSize->setMaximum(100);
        horizontalSlider_objectsSize->setValue(100);
        horizontalSlider_objectsSize->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider_objectsSize);


        verticalLayout_6->addLayout(horizontalLayout_3);

        dockWidget_objects->setWidget(dockWidgetContents_2);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidget_objects);
        dockWidget_plot = new QDockWidget(mainWindow);
        dockWidget_plot->setObjectName(QString::fromUtf8("dockWidget_plot"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_7 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        likelihoodPlot = new UPlot(dockWidgetContents_3);
        likelihoodPlot->setObjectName(QString::fromUtf8("likelihoodPlot"));

        verticalLayout_7->addWidget(likelihoodPlot);

        dockWidget_plot->setWidget(dockWidgetContents_3);
        mainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(8), dockWidget_plot);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuEdit->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menu->menuAction());
        menuFile->addAction(actionLoad_objects);
        menuFile->addAction(actionSave_objects);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionAdd_object_from_scene);
        menuEdit->addAction(actionAdd_objects_from_files);
        menuEdit->addSeparator();
        menuEdit->addAction(actionLoad_scene_from_file);
        menuEdit->addAction(actionCamera_from_directory_of_images);
        menuEdit->addAction(actionCamera_from_video_file);
        menuEdit->addSeparator();
        menuEdit->addAction(actionStart_camera);
        menuEdit->addAction(actionPause_camera);
        menuEdit->addAction(actionStop_camera);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRestore_all_default_settings);
        menuEdit->addSeparator();
        menuEdit->addAction(actionRemove_all_objects);
        menu->addAction(actionAbout);

        retranslateUi(mainWindow);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
        mainWindow->setWindowTitle(QApplication::translate("mainWindow", "Find-Object", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("mainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionAdd_object_from_scene->setText(QApplication::translate("mainWindow", "Add object from scene...", 0, QApplication::UnicodeUTF8));
        actionStart_camera->setText(QApplication::translate("mainWindow", "Start camera", 0, QApplication::UnicodeUTF8));
        actionStop_camera->setText(QApplication::translate("mainWindow", "Stop camera", 0, QApplication::UnicodeUTF8));
        actionSave_objects->setText(QApplication::translate("mainWindow", "Save objects...", 0, QApplication::UnicodeUTF8));
        actionLoad_objects->setText(QApplication::translate("mainWindow", "Load objects...", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("mainWindow", "About...", 0, QApplication::UnicodeUTF8));
        actionRestore_all_default_settings->setText(QApplication::translate("mainWindow", "Restore all default settings", 0, QApplication::UnicodeUTF8));
        actionAdd_objects_from_files->setText(QApplication::translate("mainWindow", "Add objects from files...", 0, QApplication::UnicodeUTF8));
        actionLoad_scene_from_file->setText(QApplication::translate("mainWindow", "Camera from single file...", 0, QApplication::UnicodeUTF8));
        actionPause_camera->setText(QApplication::translate("mainWindow", "Pause camera", 0, QApplication::UnicodeUTF8));
        actionCamera_from_video_file->setText(QApplication::translate("mainWindow", "Camera from video file...", 0, QApplication::UnicodeUTF8));
        actionRemove_all_objects->setText(QApplication::translate("mainWindow", "Remove all objects", 0, QApplication::UnicodeUTF8));
        actionCamera_from_directory_of_images->setText(QApplication::translate("mainWindow", "Camera from directory of images...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("mainWindow", "Camera", 0, QApplication::UnicodeUTF8));
        label_timeRefreshRate->setText(QApplication::translate("mainWindow", " (0 Hz - 0 Hz)", 0, QApplication::UnicodeUTF8));
        label_detectorDescriptorType->setText(QString());
        label_nfeatures->setText(QApplication::translate("mainWindow", "0", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("mainWindow", " features", 0, QApplication::UnicodeUTF8));
        pushButton_play->setText(QString());
        pushButton_pause->setText(QString());
        pushButton_stop->setText(QString());
        label_frame->setText(QApplication::translate("mainWindow", "0", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("mainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuEdit->setTitle(QApplication::translate("mainWindow", "Edit", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("mainWindow", "View", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("mainWindow", "?", 0, QApplication::UnicodeUTF8));
        dockWidget_parameters->setWindowTitle(QApplication::translate("mainWindow", "Parameters", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("mainWindow", "Statistics", 0, QApplication::UnicodeUTF8));
        label_timeMatching->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("mainWindow", "ms", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("mainWindow", "ms", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("mainWindow", "ms", 0, QApplication::UnicodeUTF8));
        label_minMatchedDistance->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("mainWindow", "Min matched distance", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("mainWindow", "Max matched distance", 0, QApplication::UnicodeUTF8));
        label_maxMatchedDistance->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("mainWindow", "Detect outliers and GUI", 0, QApplication::UnicodeUTF8));
        label_timeGui->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("mainWindow", "Descriptors extraction", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("mainWindow", "ms", 0, QApplication::UnicodeUTF8));
        label_timeExtraction->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("mainWindow", "ms", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("mainWindow", "Features detection", 0, QApplication::UnicodeUTF8));
        label_timeDetection->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("mainWindow", "Descriptors matching", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("mainWindow", "Descriptors indexing", 0, QApplication::UnicodeUTF8));
        label_timeIndexing->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("mainWindow", "Total", 0, QApplication::UnicodeUTF8));
        label_timeTotal->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("mainWindow", "ms", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("mainWindow", "Vocabulary size", 0, QApplication::UnicodeUTF8));
        label_vocabularySize->setText(QApplication::translate("mainWindow", "000", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_1), QApplication::translate("mainWindow", "Dummy", 0, QApplication::UnicodeUTF8));
        pushButton_restoreDefaults->setText(QApplication::translate("mainWindow", "Restore defaults", 0, QApplication::UnicodeUTF8));
        dockWidget_objects->setWindowTitle(QApplication::translate("mainWindow", "Objects", 0, QApplication::UnicodeUTF8));
        pushButton_updateObjects->setText(QApplication::translate("mainWindow", "Update objects", 0, QApplication::UnicodeUTF8));
        dockWidget_plot->setWindowTitle(QApplication::translate("mainWindow", "Likelihood", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mainWindow: public Ui_mainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
