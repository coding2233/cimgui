#ifndef __CIMGUI_LIBS_H__
#define __CIMGUI_LIBS_H__

#include "libs/TextEditor.h"

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

CIMGUI_API TextEditor* igNewTextEditor(const char* text);
CIMGUI_API void igDeleteTextEditor(TextEditor* text_editor);
CIMGUI_API void igTextEditorRender(TextEditor* text_editor,const char* aTitle, const ImVec2 aSize = ImVec2(), bool aBorder = false);

#endif