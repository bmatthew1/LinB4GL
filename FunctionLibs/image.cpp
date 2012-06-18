#include <gl/corona.h>
#include "../VM/vmData.h"
#include <gl/gl.h>
#include <gl/glext.h>
#include <iostream>

//stores opengl texture handles
class TextureResourceStore : public vmIntHandleResources {
protected:
    virtual void DeleteHandle (int handle);
};

void TextureResourceStore::DeleteHandle (int handle) {
    GLuint texture = (GLuint) handle;
    glDeleteTextures (1, &texture);
}


//image resource Store
typedef vmPointerResourceStore<corona::Image> ImageResourceStore;


class DisplayListResourceStore : public vmIntHandleResources {
private:
    std::map<int,int> m_countMap;                               // Maps base to count
protected:
    virtual void DeleteHandle (int handle);
public:
    virtual void Clear ();
    void Store (int handle, int count)  {
        if (!Valid (handle) || m_countMap [handle] < count) {   // Not already stored, or new value covers a bigger range
            vmIntHandleResources::Store (handle);
            m_countMap [handle] = count;
        }
    }
    int GetCount (int base) {
        assert (Valid (base));
        return m_countMap [base];
    }
};

void DisplayListResourceStore::Clear () {
    vmIntHandleResources::Clear ();
    m_countMap.clear ();
}

void DisplayListResourceStore::DeleteHandle (int handle) {
    glDeleteLists (handle, m_countMap [handle]);
}

TextureResourceStore textures;
ImageResourceStore images;
DisplayListResourceStore displayLists;

static void Init (TomVM& vm) {
    textures.Clear ();
}

void WrapglGenTexture(TomVM& vm) {
    GLuint texture;
    glGenTextures (1, &texture);
    textures.Store (texture);
    vm.Reg ().IntVal () = texture;
}

void WrapglDeleteTexture(TomVM& vm) {
    textures.Free (vm.GetIntParam (1));
}

GLuint LoadTexture (std::string filename, bool mipmap) {

}




