#include "cimgui_libs.h"

CIMGUI_API TextEditor* igNewTextEditor(const char* text)
{
    auto text_editor =new TextEditor();
    text_editor->SetText(text);
    return text_editor;
}


CIMGUI_API void igDeleteTextEditor(TextEditor* text_editor)
{
    delete text_editor;
}

CIMGUI_API void igTextEditorRender(TextEditor* text_editor,const char* aTitle, const ImVec2 aSize, bool aBorder)
{
    text_editor->Render(aTitle,aSize,aBorder);
}