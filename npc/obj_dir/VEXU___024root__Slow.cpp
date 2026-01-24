// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VEXU.h for the primary calling header

#include "VEXU__pch.h"

void VEXU___024root___ctor_var_reset(VEXU___024root* vlSelf);

VEXU___024root::VEXU___024root(VEXU__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    VEXU___024root___ctor_var_reset(this);
}

void VEXU___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VEXU___024root::~VEXU___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
