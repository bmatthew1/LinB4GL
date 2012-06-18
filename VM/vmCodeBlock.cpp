#include "vmCodeBlock.h"
#include "streaming.h"
using namespace std;

////////////////////////////////////////////////////////////////////////////////
//  vmCodeBlock

void vmCodeBlock::SetLengthAtLeast(int length) {
    if (runtimeFunctions.size() < (unsigned)length)
        runtimeFunctions.resize(length);
}

vmRuntimeFunction& vmCodeBlock::GetRuntimeFunction(int index) {
    assert(index >= 0);
    SetLengthAtLeast(index + 1);
    return runtimeFunctions[index];
}

#ifdef VM_STATE_STREAMING
void vmCodeBlock::StreamOut(ostream& stream) {
    WriteLong(stream, programOffset);
    WriteLong(stream, runtimeFunctions.size());
    for (vector<vmRuntimeFunction>::iterator i = runtimeFunctions.begin();
            i != runtimeFunctions.end();
            i++)
        i->StreamOut(stream);
}

void vmCodeBlock::StreamIn(istream& stream) {
    programOffset = ReadLong(stream);
    int count = ReadLong(stream);
    runtimeFunctions.resize(count);
    for (vector<vmRuntimeFunction>::iterator i = runtimeFunctions.begin();
            i != runtimeFunctions.end();
            i++)
        i->StreamIn(stream);
}
#endif

