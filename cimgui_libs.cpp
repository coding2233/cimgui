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

CIMGUI_API const char* igGetTextEditor(TextEditor* text_editor)
{
    return text_editor->GetText().c_str();
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

CIMGUI_API void igSetFlagLinesTextEditor(TextEditor* text_editor,int* lines,int size)
{
    std::vector<int> flagLines;

    for (size_t i = 0; i < size; i++)
    {
        flagLines.push_back(lines[i]);
    }

    text_editor->SetFlagLines(flagLines);
}

CIMGUI_API void igCustomPaletteTextEditor(TextEditor* text_editor,unsigned int* colors,int size)
{
    if(size<22)
        return;
    text_editor->SetPalette(text_editor->GetCustomPalette(colors));
}

CIMGUI_API void igIgnoreChildTextEditor(TextEditor* text_editor,bool ignore)
{
    text_editor->SetImGuiChildIgnored(ignore);
}

CIMGUI_API int* igGetCursorPositionTextEditor(TextEditor* text_editor)
{
    auto cursorPos = text_editor->GetCursorPosition();
    int position[2];
    position[0]=cursorPos.mLine;
    position[1]=cursorPos.mColumn;
    return position;
}
CIMGUI_API int igGetTotalLinesTextEditor(TextEditor* text_editor)
{
    return text_editor->GetTotalLines();
}
CIMGUI_API bool igIsOverwriteTextEditor(TextEditor* text_editor)
{
    return text_editor->IsOverwrite();
}
CIMGUI_API bool igCanUndoTextEditor(TextEditor* text_editor)
{
    return text_editor->CanUndo();
}
CIMGUI_API bool igIsTextChangedTextEditor(TextEditor* text_editor)
{
    return text_editor->IsTextChanged();
}

IMGUIFILEDIALOG_API char* IGFD_SelectionFilePath(ImGuiFileDialog* vContext)
{
    char* selectionPathName = "";
    auto selection =IGFD_GetSelection(vContext);
    if(selection.count>0)
    {
        selectionPathName=selection.table[0].filePathName;
    }
    return selectionPathName;
}