// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VIDU.h for the primary calling header

#include "VIDU__pch.h"

void VIDU___024root___ctor_var_reset(VIDU___024root* vlSelf);

VIDU___024root::VIDU___024root(VIDU__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VIDU___024root___ctor_var_reset(this);
}

void VIDU___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VIDU___024root::~VIDU___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
