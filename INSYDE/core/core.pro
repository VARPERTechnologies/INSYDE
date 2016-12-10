
QT += gui widgets opengl xml

CONFIG +=  qt shared

#CONFIG(release, debug|release):message("Staring RELEASE build for core sources") #will print
#CONFIG(debug, debug|release):message("Staring DEBUG build for core sources") #no print
#TODO: implement labeled color editor

TEMPLATE = lib

DEFINES +=\
WINDOW_HEIGH=31 \
WINDOW_WIDTH=13 \
WINDOW_STEP=1 \
EXPORT_CORE_LIB

MOC_DIR = moc
UI_DIR = ui
OBJECTS_DIR = obj
RCC_DIR = res
DESTDIR = ..

HEADERS += \
	imath.h\
	common.h \
	labeledcombobox.h \
	integersizewidget.h \
	dotmatrix.h \
	labeleddoublespinbox.h \
	labeledintegerspinbox.h \
	labeledwidget.h \
	datarepresentationbox.h \
	datarepresentationwidget.h \
	dotmatrixrepresentation.h \
	imagerepresentationwidget.h \
	rawrepresentationwidget.h \
	dotmatrixdetailedwindow.h \
	dotmatrixpropertydialog.h \
	imagedetailedwindow.h \
	imagepropertydialog.h \
	image.h \
	basicdialog.h \
	zoomcontrol.h \
	interfaces.h \
	graphicobject.h \
	basictable.h \
	datarepresentation.h \
	normalization.h \
	normalizationwidget.h \
	detailedwindow.h \
	basictree.h \
	doubleminmaxvaluewidget.h \
	effect.h \
	blackwhiteeffect.h \
	grayscaleeffect.h \
	graphiccursorelement.h \
	vector2d.h \
	share_core_lib.h \
	imageeffect.h \
	imageeffectpropertydialog.h \
	bnsubwidget.h \
	gssubwidget.h \
	selectimagesegmentdialog.h \
	graphicdetailedview.h \
	enviroment.h \
	graphicpointer.h \
	adddotmatrixdialog.h \
	connector.h \
	graphicobjectpropertydialog.h \
	fileeditline.h \
	definitions.h \
	simulation.h \
	restrictedlinef.h

SOURCES += \
	imath.cpp\
	common.cpp \
	labeledcombobox.cpp \
	integersizewidget.cpp \
	dotmatrix.cpp \
	labeleddoublespinbox.cpp \
	labeledintegerspinbox.cpp \
	labeledwidget.cpp \
	datarepresentationbox.cpp \
	datarepresentationwidget.cpp \
	dotmatrixrepresentation.cpp \
	imagerepresentationwidget.cpp \
	rawrepresentationwidget.cpp \
	dotmatrixdetailedwindow.cpp \
	dotmatrixpropertydialog.cpp \
	imagepropertydialog.cpp \
	imagedetailedwindow.cpp \
	basicdialog.cpp \
	zoomcontrol.cpp \
	graphicobject.cpp \
	basictable.cpp \
	image.cpp \
	datarepresentation.cpp \
	normalization.cpp \
	normalizationwidget.cpp \
	detailedwindow.cpp \
	basictree.cpp \
	doubleminmaxvaluewidget.cpp \
	effect.cpp \
	blackwhiteeffect.cpp \
	grayscaleeffect.cpp \
	graphiccursorelement.cpp \
	vector2d.cpp \
	imageeffect.cpp \
	imageeffectpropertydialog.cpp \
	bnsubwidget.cpp \
	gssubwidget.cpp \
	selectimagesegmentdialog.cpp \
	graphicdetailedview.cpp \
	enviroment.cpp \
	graphicpointer.cpp \
	adddotmatrixdialog.cpp \
	connector.cpp \
	graphicobjectpropertydialog.cpp \
	fileeditline.cpp \
	simulation.cpp \
	restrictedlinef.cpp

FORMS += \
	graphicimageeffectelementpropertydialog.ui \
	bnsubwidget.ui \
	gssubwidget.ui \
	selectimagesegmentdialog.ui

RESOURCES += \
	core_media.qrc

win32:{
	CONFIG += windows c++11
	CONFIG(release, debug|release):{

	TARGET = core

	LIBS += \
		"C:/Users/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/external/tbb44_20160128oss_win_0/lib/intel64/vc12/tbb.dll" \
#		-L$$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc12/ -ltbb \
		-L$$PWD/../external/kdchart-2.5.1-source-win/lib/ -lkdchart2 \

	lib.path = $$PWD/../../custom_libs/insyde/core/lib/win64/nodebug
	lib.files = $$OUT_PWD/../core.*

	includes.path = $$PWD/../../custom_libs/insyde/core/include
	includes.files = $$PWD/*.h

	tbb_lib.path = $$PWD/../../custom_libs/insyde/tbb/lib
	tbb_lib.files = $$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc12/tbb.*

	tbb_include.path = $$PWD/../../custom_libs/insyde/tbb
	tbb_include.files = $$PWD/../external/tbb44_20160128oss_win_0/include

	INSTALLS += lib includes tbb_lib tbb_include
	}else{
	TARGET = core_debug

	LIBS += \
#		-L"C:/Users/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/external/tbb44_20160128oss_win_0/bin/intel64/vc12/" -ltbb \
		"C:/Users/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/external/tbb44_20160128oss_win_0/bin/intel64/vc12/tbb_debug.dll" \
		"C:/Users/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/external/kdchart-2.5.1-source-win/lib/kdchartd2.lib"

#	lib.path = "C:/Users/Edixon/Google Drive/Programacion/C++/Qt/custom_libs/insyde/core/lib/win64/debug"
#	lib.files = $$OUT_PWD/../core_debug.*

#	includes.path = "C:/Users/Edixon/Google Drive/Programacion/C++/Qt/custom_libs/insyde/core/include"
#	includes.files = $$PWD/*.h

#	tbb_lib.path = "C:/Users/Edixon/Google Drive/Programacion/C++/Qt/custom_libs/insyde/tbb/lib"
#	tbb_lib.files = $$PWD/../external/tbb44_20160128oss_win_0/lib/intel64/vc12/tbb_debug.* \
#			$$PWD/../external/tbb44_20160128oss_win_0/bin/intel64/vc12/tbb_debug.*

#	tbb_include.path = "C:/Users/Edixon/Google Drive/Programacion/C++/Qt/custom_libs/insyde/tbb"
#	tbb_include.files = $$PWD/../external/tbb44_20160128oss_win_0/include

#	INSTALLS += lib includes tbb_lib tbb_include
	}
	INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-win/include
	DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-win/include

	INCLUDEPATH += "C:/Users/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/external/tbb44_20160128oss_win_0/include"
	DEPENDPATH += "C:/Users/Edixon/Google Drive/Programacion/C++/Qt/INSYDE/external/tbb44_20160128oss_win_0/include"
}

unix:{

	QMAKE_CXX += -std=c++11

	CONFIG(release, debug|release):{
	QMAKE_CXX += -O3

	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/release/ -lkdchart

	lib.path = $$PWD/../../custom_libs/insyde/$$APP_BASENAME/lib
	lib.files = $$OUT_PWD/../$$join(APP_BASENAME,,"lib").*

	includes.path = $$PWD/../../custom_libs/insyde/$$APP_BASENAME/include
	includes.files = $$PWD/*.h

	tbb_lib.path = $$PWD/../../custom_libs/insyde/tbb/lib
	tbb_lib.files = $$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/libtbb.*

	tbb_include.path = $$PWD/../../custom_libs/insyde/tbb
	tbb_include.files = $$PWD/../external/tbb42_20140416oss_lin/include

	INSTALLS += lib includes tbb_lib tbb_include
	}else{
	LIBS += -L$$PWD/../external/tbb42_20140416oss_lin/bin/intel64/gcc4.4/ -ltbb_debug \
		-L$$PWD/../external/tbb42_20140416oss_lin/lib/intel64/gcc4.4/ -ltbb_debug \
		-L$$PWD/../external/kdchart-2.5.1-source-linux/lib/debug/ -lkdchart
	}

	INCLUDEPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include
	DEPENDPATH += $$PWD/../external/kdchart-2.5.1-source-linux/include


	INCLUDEPATH += $$PWD/../external/tbb42_20140416oss_lin/include
	DEPENDPATH += $$PWD/../external/tbb42_20140416oss_lin/include
}