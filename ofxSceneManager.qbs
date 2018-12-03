import qbs
import qbs.Process
import qbs.File
import qbs.FileInfo
import qbs.TextFile
import "../../../libs/openFrameworksCompiled/project/qtcreator/ofApp.qbs" as ofApp

Project{
    property string of_root: "../../.."

    ofApp {
        name: { return FileInfo.baseName(path) }

        files: [
            "src/arena.cpp",
            "src/arena.h",
            "src/bullet.cpp",
            "src/bullet.h",
            "src/camera.cpp",
            "src/camera.h",
            "src/cameramanager.cpp",
            "src/cameramanager.h",
            "src/circle.cpp",
            "src/circle.h",
            "src/gameobject.cpp",
            "src/gameobject.h",
            "src/ofxobject.cpp",
            "src/ofxobject.h",
            "src/ofxscene.cpp",
            "src/ofxscene.h",
            "src/ofxscenemanager.cpp",
            "src/ofxscenemanager.h",
            "src/main.cpp",
            "src/ofApp.cpp",
            "src/ofApp.h",
            "src/shot.cpp",
            "src/shot.h",
            "src/skill.cpp",
            "src/skill.h",
            "src/tapeffect.cpp",
            "src/tapeffect.h",
            "src/testscene.cpp",
            "src/testscene.h",
            "src/testui.cpp",
            "src/testui.h",
            "src/unit.cpp",
            "src/unit.h",
            "src/unitmanager.cpp",
            "src/unitmanager.h",
        ]

        of.addons: [
            'ofxUI',
            'ofxXmlSettings',
        ]

        // additional flags for the project. the of module sets some
        // flags by default to add the core libraries, search paths...
        // this flags can be augmented through the following properties:
        of.pkgConfigs: []       // list of additional system pkgs to include
        of.includePaths: []     // include search paths
        of.cFlags: []           // flags passed to the c compiler
        of.cxxFlags: []         // flags passed to the c++ compiler
        of.linkerFlags: []      // flags passed to the linker
        of.defines: []          // defines are passed as -D to the compiler
                                // and can be checked with #ifdef or #if in the code

        // other flags can be set through the cpp module: http://doc.qt.io/qbs/cpp-module.html
        // eg: this will enable ccache when compiling
        //
        // cpp.compilerWrapper: 'ccache'

        Depends{
            name: "cpp"
        }

        // common rules that parse the include search paths, core libraries...
        Depends{
            name: "of"
        }

        // dependency with the OF library
        Depends{
            name: "openFrameworks"
        }
    }

    property bool makeOF: true  // use makfiles to compile the OF library
                                // will compile OF only once for all your projects
                                // otherwise compiled per project with qbs

    references: [FileInfo.joinPaths(of_root, "/libs/openFrameworksCompiled/project/qtcreator/openFrameworks.qbs")]
}
