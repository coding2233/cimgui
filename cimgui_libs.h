#ifndef __CIMGUI_LIBS_H__
#define __CIMGUI_LIBS_H__

#include "libs/TextEditor.h"
#include "libs/ImGuiFileDialog/ImGuiFileDialog.h"

#include <stdio.h>
#include <stdint.h>
#if defined _WIN32 || defined __CYGWIN__
    #ifdef CIMGUI_NO_EXPORT
        #define API
    #else
        #define API __declspec(dllexport)
    #endif
#else
    #ifdef __GNUC__
        #define API  __attribute__((__visibility__("default")))
    #else
        #define API
    #endif
#endif

#if defined __cplusplus
    #define EXTERN extern "C"
#else
    #include <stdarg.h>
    #include <stdbool.h>
    #define EXTERN extern
#endif

#define CIMGUI_API EXTERN API
#define CONST const


#ifdef _MSC_VER
typedef unsigned __int64 ImU64;
#else
//typedef unsigned long long ImU64;
#endif

CIMGUI_API TextEditor* igNewTextEditor();
CIMGUI_API void igDeleteTextEditor(TextEditor* text_editor);
CIMGUI_API void igRenderTextEditor(TextEditor* text_editor,const char* aTitle, const ImVec2 aSize = ImVec2(), bool aBorder = false);
CIMGUI_API void igSetTextEditor(TextEditor* text_editor,const char* text);
CIMGUI_API const char* igGetTextEditor(TextEditor* text_editor);
CIMGUI_API void igSetPaletteTextEditor(TextEditor* text_editor,int style);
CIMGUI_API void igSetReadOnlyTextEditor(TextEditor* text_editor,bool readOnly);
CIMGUI_API void igSetShowWhitespacesTextEditor(TextEditor* text_editor,bool show);
CIMGUI_API void igSetFlagLinesTextEditor(TextEditor* text_editor,int* lines,int size);
CIMGUI_API void igSetFlagPointsTextEditor(TextEditor* text_editor,int* points,int size);
CIMGUI_API bool igGetFlagPointRectTextEditor(TextEditor* text_editor,int lineNo,ImVec4* rect);
CIMGUI_API void igCustomPaletteTextEditor(TextEditor* text_editor,unsigned int* colors,int size);
CIMGUI_API void igIgnoreChildTextEditor(TextEditor* text_editor,bool ignore);
CIMGUI_API TextEditor::Coordinates* igGetCursorPositionTextEditor(TextEditor* text_editor);
CIMGUI_API int igGetTotalLinesTextEditor(TextEditor* text_editor);
CIMGUI_API bool igIsOverwriteTextEditor(TextEditor* text_editor);
CIMGUI_API bool igCanUndoTextEditor(TextEditor* text_editor);
CIMGUI_API bool igIsTextChangedTextEditor(TextEditor* text_editor);


IMGUIFILEDIALOG_API char* IGFD_SelectionFilePath(ImGuiFileDialog* vContext);

#endif