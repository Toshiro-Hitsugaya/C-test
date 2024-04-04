#include "SmartPointer.h"

SmartPointer::SmartPointer(const SmartPointer &sptr) {
    pointer = sptr.pointer;
    ref_cnt = sptr.ref_cnt;
    if (pointer != nullptr) {
        (*ref_cnt)++;
    }
}

void SmartPointer::assign(const SmartPointer &sptr)
{
    if(pointer!=sptr.pointer) {
        if (pointer == nullptr && ref_cnt == nullptr) {//new
            if (sptr.pointer != nullptr && sptr.ref_cnt != nullptr) {
                pointer = sptr.pointer;
                ref_cnt = sptr.ref_cnt;
                (*ref_cnt)++;
            } else if (sptr.pointer == nullptr) {
                pointer = sptr.pointer;
                ref_cnt = sptr.ref_cnt;
            }
        } else if (pointer != nullptr && ref_cnt != nullptr) {
            (*ref_cnt)--;
            if (*ref_cnt == 0) {
                delete pointer;
                pointer = nullptr;
                ref_cnt = nullptr;
            }
            if (sptr.pointer != nullptr && sptr.ref_cnt != nullptr) {
                pointer = sptr.pointer;
                ref_cnt = sptr.ref_cnt;
                (*ref_cnt)++;
            } else if (sptr.pointer == nullptr) {
                pointer = sptr.pointer;
                ref_cnt = sptr.ref_cnt;
            }
        }
    }
}

SmartPointer::~SmartPointer()
{
    if(pointer != nullptr&&ref_cnt != nullptr) {
        (*ref_cnt)--;
        if (*ref_cnt == 0) {
            delete pointer;
            pointer = nullptr;
            ref_cnt = nullptr;
        }
    } else if(pointer == nullptr){
        pointer = nullptr;
        ref_cnt = nullptr;
    }
}
