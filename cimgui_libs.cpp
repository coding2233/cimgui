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

CIMGUI_API void igSetPaletteTextEditor(TextEditor* text_editor,int style)
{
    switch (style)
    {
    case 0:
        text_editor->SetPalette(TextEditor::GetLightPalette());
        break;
     case 1:
        text_editor->SetPalette(TextEditor::GetDarkPalette());
        break;
     case 2:
        text_editor->SetPalette(TextEditor::GetRetroBluePalette());
        break;
    default:
        text_editor->SetPalette(TextEditor::GetDarkPalette());
        break;
    }
}

CIMGUI_API void igSetReadOnlyTextEditor(TextEditor* text_editor,bool readOnly)
{
    text_editor->SetReadOnly(readOnly);
}

CIMGUI_API void igSetShowWhitespacesTextEditor(TextEditor* text_editor,bool show)
{
    text_editor->SetShowWhitespaces(show);
}