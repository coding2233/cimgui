#include "cimgui_libs.h"

CIMGUI_API TextEditor* igNewTextEditor()
{
    auto text_editor =new TextEditor();
    return text_editor;
}


CIMGUI_API void igDeleteTextEditor(TextEditor* text_editor)
{
    delete text_editor;
}

CIMGUI_API void igRenderTextEditor(TextEditor* text_editor,const char* aTitle, const ImVec2 aSize, bool aBorder)
{
    text_editor->Render(aTitle,aSize,aBorder);
}

CIMGUI_API void igSetTextEditor(TextEditor* text_editor,const char* text)
{
    text_editor->SetText(text);
}