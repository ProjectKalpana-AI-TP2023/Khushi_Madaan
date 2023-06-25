#include <iostream>
#include <string>

using namespace std;

class TextEditor {
private:
    string text;
    int curpos;

public:
    TextEditor() {
        text = "";
        curpos = 0;
    }

    void addtext(string text) {
        this->text.insert(curpos, text);
        curpos += text.length();
    }

    void deletetext(int n) {
        if (curpos > 0 && n > 0) {
            int delcnt = min(n, curpos);
            this->text.erase(curpos - delcnt, delcnt);
            curpos -= delcnt;
        }
    }

    void backspace() {
        deletetext(1);
    }

    int findcursor() {
        return curpos;
    }

    void cursorleft(int n) {
        int movecnt = min(n, curpos);
        curpos -= movecnt;
    }

    void cursorright(int n) {
        int movecnt = min(n,curpos);
        curpos += movecnt;
    }

    string fulltext() {
        return text;
    }

    string showtext(int n) {
        int remainingchars = text.length() - curpos;
        int showcount = min(n, remainingchars);
        return text.substr(curpos, showcount);
    }

    int findcur(){
        return curpos;
    }
};

int main() {
    TextEditor editor;
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;

    editor.addtext("Hello");
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;

    editor.backspace();
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;

    editor.cursorleft(2);
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;

    editor.deletetext(3);
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;

    editor.addtext("fa");
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;

    editor.cursorright(3);
    cout << editor.fulltext()<<"\t";
    cout <<"cursor position" <<editor.findcur()<<endl;


    return 0;
}

