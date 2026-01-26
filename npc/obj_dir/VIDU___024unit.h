// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VIDU.h for the primary calling header

#ifndef VERILATED_VIDU___024UNIT_H_
#define VERILATED_VIDU___024UNIT_H_  // guard

#include "verilated.h"


class VIDU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VIDU___024unit final {
  public:

    // INTERNAL VARIABLES
    VIDU__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VIDU___024unit() = default;
    ~VIDU___024unit() = default;
    void ctor(VIDU__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(VIDU___024unit);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
